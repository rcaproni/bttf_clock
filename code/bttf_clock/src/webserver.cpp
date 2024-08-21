// webserver.
//based on code from here: https://github.com/KrisKasprzak/ESP32_WebPage


#include "WebServer.h"

WebServer::WebServer() : server(80),
                         rtc(),
                         strip(),
                         display() {
}


String WebServer::getValueString() {
    return server.arg("VALUE");
}

void WebServer::updateBrightness(String strip_br_s, String clk_br_s) {
  strip.setBrightness(strip_br_s.toInt());
  strip.update();

  // set clock bright
  display.setBrightness(clk_br_s.toInt());
}



void WebServer::setBrightness() {
  
  String webVal = getValueString();

  // split string in 2. @ is the divider
  uint8_t index = webVal.indexOf('@');
  String strip_br_s = webVal.substring(0, index);
  String clk_br_s = webVal.substring(index+1, webVal.length());
  
  Serial.println("WebServer::updateBrightness: VALUE=");
  Serial.println(webVal);

  updateBrightness(strip_br_s, clk_br_s);

  send();
}

// write date and time from webpage to RTC when button Prog RTC time is clicked
void WebServer::updateTimeToRtc() {
  disp_t dispTime;
  String webVal = getValueString();
  Serial.println("WebServer::updateTimeToRtc: VALUE=");
  Serial.println(webVal);
  String hh_s = webVal.substring(0, 2);
  String mm_s = webVal.substring(3, 5);
  String dd_s = webVal.substring(5, 7);
  String mo_s = webVal.substring(7, 9);
  String yy_s = webVal.substring(9, 11);
  Serial.println("WebServer::updateTimeToRtc: Subsrings:");
  Serial.printf("h %s m %s d %s m %s y %s\n", hh_s, mm_s, dd_s, mo_s, yy_s); // printf is used to print hh_s);
  
  dispTime.hour = webVal.substring(0, 2).toInt();
  dispTime.min = webVal.substring(3, 5).toInt();
  dispTime.day = webVal.substring(5, 7).toInt();
  dispTime.month = webVal.substring(7, 9).toInt();
  dispTime.year = webVal.substring(11, 13).toInt();

  Serial.println("WebServer::updateTimeToRtc: To RTC uint8_t:");
  Serial.printf("h %d m %d d %d m %d y %d\n", dispTime.hour, dispTime.min, dispTime.day, dispTime.month, dispTime.year);
  
  rtc.progRtcDate(dispTime);
  
  send(); // send page
}

// Read RTC time and send it to the webpage
// TODO
void WebServer::getTimeFromRtc() {
  disp_t dispTime;

  Serial.println("WebServer::getTimeFromRtc(): ");
  dispTime = rtc.readRtcDate();

  Serial.println("WebServer::getTimeFromRtc: date uint8_t:");
  Serial.printf("h %d m %d d %d m %d y %d\n", dispTime.hour, dispTime.min, dispTime.day, dispTime.month, dispTime.year);
  
  // now send it back
  send();
}

// send data to page
void WebServer::send() {
    server.send(200, "text/plain", buf);
}

// initialize webserver
void WebServer::init() {
    WiFiManager manager;

    manager.setConnectTimeout(60);
    bool res = manager.autoConnect("bttf", "bttf");
    if (!res) {
        Serial.println("failed to connect and timeout occurred");
        ESP.restart();
    } else {
        Serial.print("WIFI Connected!!!");
    }

    printWifiStatus();

    delay(3000);

    server.on("/", [this]() {
        this->sendWebsite();
    });
    server.on("/xml", [this]() {
        this->sendXML();
    });
    server.on("/UPDATE_BRIGHT", [this]() {
        this->setBrightness();
    });
    server.on("/UPDATE_TIME", [this]() {
        this->updateTimeToRtc();
    });
    server.on("/READ_TIME", [this]() {
        this->getTimeFromRtc();
    });

    server.begin();

    updateBrightness("50", "2");

}

void WebServer::printWifiStatus() {
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());

    ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);

    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");

    Serial.print("Open http://");
    Serial.println(ip);
}


void WebServer::handleClient() {
    server.handleClient();
}





void WebServer::sendWebsite() {
    Serial.println("WebServer::sendWebsite(): sending web page");
    server.send(200, "text/html", PAGE_MAIN);
}

// VML data to webserver
void WebServer::sendXML() {
    strcpy(XML, "<?xml version = '1.0'?>\n<Data>\n");

    sprintf(buf, "<B0>%d</B0>\n", bitsA0);
    strcat(XML, buf);

    sprintf(buf, "<V0>%d.%d</V0>\n", (int)(voltsA0), abs((int)(voltsA0 * 10) - ((int)(voltsA0) * 10)));
    strcat(XML, buf);

    sprintf(buf, "<B1>%d</B1>\n", bitsA1);
    strcat(XML, buf);

    sprintf(buf, "<V1>%d.%d</V1>\n", (int)(voltsA1), abs((int)(voltsA1 * 10) - ((int)(voltsA1) * 10)));
    strcat(XML, buf);

    strcat(XML, "</Data>\n");

    Serial.println(XML);
    server.send(200, "text/xml", XML);
}

void WebServer::printTime(disp_t dispTime) {
    display.printTime(dispTime);
}