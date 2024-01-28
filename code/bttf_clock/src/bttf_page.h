// This is the HTML code for the web page.
// See here for detailed information: https://github.com/KrisKasprzak/ESP32_WebPage

const char PAGE_MAIN[] PROGMEM = R"=====(

<!DOCTYPE html>
<html lang="en" class="js-focus-visible">
  <title>Web Page Update Demo</title>
  <style>
    table {
      position: relative;
      width: 100%;
      border-spacing: 0px;
    }

    tr {
      border: 1px solid white;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
    }

    th {
      height: 20px;
      padding: 3px 15px;
      background-color: #343a40;
      color: #FFFFFF !important;
    }

    td {
      height: 20px;
      padding: 3px 15px;
    }

    .tabledata {
      font-size: 24px;
      position: relative;
      padding-left: 5px;
      padding-top: 5px;
      height: 25px;
      border-radius: 5px;
      color: #FFFFFF;
      line-height: 20px;
      transition: all 200ms ease-in-out;
      background-color: #00AA00;
    }

    .fanrpmslider {
      width: 30%;
      height: 55px;
      outline: none;
      height: 25px;
    }

    .bodytext {
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 24px;
      text-align: left;
      font-weight: light;
      border-radius: 5px;
      display: inline;
    }

    .navbar {
      width: 100%;
      height: 50px;
      margin: 0;
      padding: 10px 0px;
      background-color: #FFF;
      color: #000000;
      border-bottom: 5px solid #293578;
    }

    .fixed-top {
      position: fixed;
      top: 0;
      right: 0;
      left: 0;
      z-index: 1030;
    }

    .navtitle {
      float: left;
      height: 50px;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 50px;
      font-weight: bold;
      line-height: 50px;
      padding-left: 20px;
    }

    .navheading {
      position: fixed;
      left: 60%;
      height: 50px;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
      font-weight: bold;
      line-height: 20px;
      padding-right: 20px;
    }

    .navdata {
      justify-content: flex-end;
      position: fixed;
      left: 70%;
      height: 50px;
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
      font-weight: bold;
      line-height: 20px;
      padding-right: 20px;
    }

    .category {
      font-family: "Verdana", "Arial", sans-serif;
      font-weight: bold;
      font-size: 32px;
      line-height: 50px;
      padding: 20px 10px 0px 10px;
      color: #000000;
    }

    .heading {
      font-family: "Verdana", "Arial", sans-serif;
      font-weight: normal;
      font-size: 28px;
      text-align: left;
    }

    .btn {
      background-color: #444444;
      border: none;
      color: white;
      padding: 10px 20px;
      text-align: center;
      text-decoration: none;
      display: inline-block;
      font-size: 16px;
      margin: 4px 2px;
      cursor: pointer;
    }

    .foot {
      font-family: "Verdana", "Arial", sans-serif;
      font-size: 20px;
      position: relative;
      height: 30px;
      text-align: center;
      color: #AAAAAA;
      line-height: 20px;
    }

    .container {
      max-width: 1800px;
      margin: 0 auto;
    }

    .bright-setup {
      margin-top: 20px;
    }

    table tr:first-child th:first-child {
      border-top-left-radius: 5px;
    }

    table tr:first-child th:last-child {
      border-top-right-radius: 5px;
    }

    table tr:last-child td:first-child {
      border-bottom-left-radius: 5px;
    }

    table tr:last-child td:last-child {
      border-bottom-right-radius: 5px;
    }
  </style>
  <body style="background-color: #efefef" onload="process()">
    <header>
      <!-- Header content -->
      <!-- ... -->
    </header>
    <main class="container" style="margin-top: 70px">
      <div class="category">Scene Setup</div>
      <div style="border-radius: 10px !important;">
        <table style="width:100%">
          <colgroup>
            <col span="1" style="background-color:rgb(230,230,230); width: 15%; color:#000000 ;" />
            <col span="1" style="background-color:rgb(200,200,200); width: 15%; color:#000000 ;" />
            <col span="1" style="background-color:rgb(180,180,180); width: 15%; color:#000000 ;" />
            <col span="1" style="background-color:rgb(160,160,160); width: 15%; color:#000000 ;" />
            <col span="1" style="background-color:rgb(140,140,140); width: 15%; color:#000000 ;" />
          </colgroup>
          <tr>
            <th colspan="1">
              <div class="heading">Name</div>
            </th>
            <th colspan="1">
              <div class="heading">Time (HH:MM)</div>
            </th>
            <th colspan="1">
              <div class="heading">Color</div>
            </th>
            <th colspan="1">
              <div class="heading">Bright</div>
            </th>
            <th colspan="1">
              <div class="heading">Clock</div>
            </th>
          </tr>
          <tr>
            <td>
              <div class="bodytext">Setup 0</div>
            </td>
            <td>
              <input type="time" id="time0">
            </td>
            <td>
              <input type="number" id="color0" min="0" max="255">
            </td>
            <td>
              <input type="number" id="bright0" min="0" max="55">
            </td>
            <td>
              <input type="number" id="clock0" min="0" max="255">
            </td>
          </tr>
          <tr>
            <td>
              <div class="bodytext">Setup 1</div>
            </td>
            <td>
              <input type="time" id="time1">
            </td>
            <td>
              <input type="number" id="color1" min="0" max="255">
            </td>
            <td>
              <input type="number" id="bright1" min="0" max="55">
            </td>
            <td>
              <input type="number" id="clock1" min="0" max="255">
            </td>
          </tr>
          <tr>
            <td>
              <div class="bodytext">Setup 2</div>
            </td>
            <td>
              <input type="time" id="time2">
            </td>
            <td>
              <input type="number" id="color2" min="0" max="255">
            </td>
            <td>
              <input type="number" id="bright2" min="0" max="55">
            </td>
            <td>
              <input type="number" id="clock2" min="0" max="255">
            </td>
          </tr>
        </table>
      </div>
      <br>
      <button type="button" class="btn" onclick="clock_setup_prog()">Prog Setup</button>
      <br>
      <div class="category">Time Setup</div>
      <div style="border-radius: 10px !important;">
        <table style="width:50%">
          <colgroup>
            <col span="1" style="background-color:rgb(230,230,230); width: 20%; color:#000000 ;" />
            <col span="1" style="background-color:rgb(200,200,200); width: 15%; color:#000000 ;" />
            <col span="1" style="background-color:rgb(180,180,180); width: 15%; color:#000000 ;" />
            <col span="1" style="background-color:rgb(160,160,160); width: 15%; color:#000000 ;" />
            <col span="1" style="background-color:rgb(140,140,140); width: 15%; color:#000000 ;" />
          </colgroup>
          <tr>
            <th colspan="1">
              <div class="heading">Time</div>
            </th>
            <th colspan="1">
              <div class="heading">Day</div>
            </th>
            <th colspan="1">
              <div class="heading">Month</div>
            </th>
            <th colspan="1">
              <div class="heading">Year</div>
            </th>
          </tr>
          <tr>
            <td>
              <input type="time" id="hour" step="3600">
            </td>
            <td>
              <input type="number" id="day" min="1" max="31" oninput="padZeros(this)">
            </td>
            <td>
              <input type="number" id="month" min="1" max="12" oninput="padZeros(this)">
            </td>
            <td>
              <input type="number" id="year" min="1950" max="2100">
            </td>
          </tr>
        </table>
      </div>
      <br>
      <button type="button" class="btn" onclick="prog_time()">Prog RTC Time</button>
      <button type="button" class="btn" onclick="read_time()">Get RTC Time</button>
      <button type="button" class="btn" onclick="fetchLocalTime()">Get Local Time</button>
      <div class="category">Bright Setup</div>
      <div class="bright-setup">
        <div>
          <div class="heading">Led Brightness</div>
          <input type="range" class="fanrpmslider" id="ledBrightness" min="0" max="255" value="0" oninput="updateSliderValue('ledBrightness', 'ledBrightnessValue')">
          <input type="number" id="ledBrightnessValue" min="0" max="255" oninput="updateSlider('ledBrightness', 'ledBrightnessValue')">
        </div>
        <div>
          <div class="heading">Clock Brightness</div>
          <input type="range" class="fanrpmslider" id="clockBrightness" min="0" max="15" value="0" oninput="updateSliderValue('clockBrightness', 'clockBrightnessValue')">
          <input type="number" id="clockBrightnessValue" min="0" max="15" oninput="updateSlider('clockBrightness', 'clockBrightnessValue')">
        </div>
      </div>
      <br>
      <button type="button" class="btn" onclick="prog_bright()">Prog Bright</button>
    </main>
    <footer div class="foot" id="temp">ESP32 Web Page Creation and Data Update Demo </div>
    </footer>
  </body>


  <script type="text/javascript">

    // global variable visible to all java functions
    var xmlHttp=createXmlHttpObject();

    function fetchLocalTime() {
            const currentTimestamp = new Date();

            // Fill the input fields with the date and time
            const formattedTime = formatTime(currentTimestamp.getHours(), currentTimestamp.getMinutes());
            document.getElementById("hour").value = formattedTime;
            document.getElementById("day").value = padZerosNTP(currentTimestamp.getDate());
            document.getElementById("month").value = padZerosNTP(currentTimestamp.getMonth() + 1); // Months are zero-based
            document.getElementById("year").value = currentTimestamp.getFullYear();

        }

        // Function to format time as "HH:mm"
        function formatTime(hours, minutes) {
          const formattedHours = padZerosNTP(hours);
            const formattedMinutes = padZerosNTP(minutes);
            const formattedTime = formattedHours + ":" + formattedMinutes;
            return formattedTime;
        }

    function padZerosNTP(value) {
      return value < 10 ? '0' + value : value.toString(); // Ensure it's a string
      }

    function padZeros(input) {
      // Get the input value and convert it to a number
      let value = parseInt(input.value, 10);

      // Ensure the value is within the specified range
      if (value < 1) {
        value = 1;
      } else if (value > 31) {
        value = 31;
      }

      // Pad the value with leading zeros and update the input field
      input.value = value.toString().padStart(2, '0');
    }



    // function to create XML object
    function createXmlHttpObject(){
      if(window.XMLHttpRequest){
        xmlHttp=new XMLHttpRequest();
      }
      else{
        xmlHttp=new ActiveXObject("Microsoft.XMLHTTP");
      }
      return xmlHttp;
    }

    
    function clock_setup_prog() {
      // Retrieve values from the input fields
      // ...
      // Send the data to the server for processing
      // ...
      // You can handle the response if needed
    }

    function prog_time() {
      var xhttp = new XMLHttpRequest();
      // Retrieve values from the input fields
      const hour = document.getElementById("hour").value;
      const day = document.getElementById("day").value;
      const month = document.getElementById("month").value;
      const year = document.getElementById("year").value;
      
      xhttp.open("PUT", "UPDATE_TIME?VALUE="+hour+day+month+year, true);
      xhttp.send();
    }


    function read_time() {
      var xhttp = new XMLHttpRequest();
      
      xhttp.open("PUT", "READ_TIME", false);
      xhttp.send();
    }

    function prog_bright() {
      var xhttp = new XMLHttpRequest();
      // Retrieve values from the input fields
      const value0 = document.getElementById("ledBrightness").value;
      const value1 = document.getElementById("clockBrightness").value;
      
      xhttp.open("PUT", "UPDATE_BRIGHT?VALUE="+value0+"@"+value1, true);
      xhttp.send();

    }

    // New functions for updating slider and number field
    function updateSliderValue(sliderId, numberFieldId) {
      const slider = document.getElementById(sliderId);
      const numberField = document.getElementById(numberFieldId);
      numberField.value = slider.value;
    }

    function updateSlider(sliderId, numberFieldId) {
      const slider = document.getElementById(sliderId);
      const numberField = document.getElementById(numberFieldId);
      slider.value = numberField.value;
    }
  </script>
</html>

)=====";