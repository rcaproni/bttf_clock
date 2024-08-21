#pragma once
#include <Arduino.h>
#include "WiFiManager.h"
#include <FS.h>          
#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include "display.h"
#include "bttf_page.h"
#include "rtc.h"
#include "strip.h"


// for UDO time
#define GMT -3

class WebServer {
public:
    void init();
    void printWifiStatus();
    String getValueString();
    void send();
    void sendWebsite();
    void sendXML();
    void updateBrightness(String strip_br_s, String clk_br_s);
    void updateTimeToRtc();
    void getTimeFromRtc();
    void handleClient();
    void setBrightness();
    void printTime(disp_t dispTime);
    WebServer();

private:
    // page buffers
    char XML[2048]; // the XML array size needs to be bigger that your maximum expected size. 2048 is way too big for this example
    char buf[32]; // just some buffer holder for char operations
    ESP8266WebServer server;
    RTC rtc;    // rtc obj
    Strip strip; // strip obj
    Display display;

    // vars for reudes webserver.
    // TODO remove
    int bitsA0 = 0, bitsA1 = 0;
    float voltsA0 = 0, voltsA1 = 0;
    bool led0 = false, someOutput = false;
    uint32_t sensorUpdate = 0;

    // server address
    IPAddress actualIP;
    IPAddress ip;
};










