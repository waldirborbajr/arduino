/*
   Contol Speed of DC Motor with ESP8266 NodeMCU and D1 Mini with L298N module
   Motor is controlled using Robojax_L298N_DC_motor library

   Watch Video instrution for this code: https://youtu.be/gOMHU0Q8upA
   Full explanation of this code and wiring diagram is available at
   my Arduino Course at Udemy.com here: http://robojax.com/L/?id=62

   Written by Ahmad Shamshiri on Nov 02, 2019
   in Ajax, Ontario, Canada. www.robojax.com


   Get this code and other Arduino codes from Robojax.com
  Learn Arduino step by step in structured course with all material, wiring diagram and library
  all in once place. Purchase My course on Udemy.com http://robojax.com/L/?id=62

  If you found this tutorial helpful, please support me so I can continue creating
  content like this. You can support me on Patreon http://robojax.com/L/?id=63

  or make donation using PayPal http://robojax.com/L/?id=64

 *  * This code is "AS IS" without warranty or liability. Free to be used as long as you keep this note intact.*
   This code has been download from Robojax.com
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.


   Copyright (c) 2015, Majenko Technologies
   All rights reserved.

   Redistribution and use in source and binary forms, with or without modification,
   are permitted provided that the following conditions are met:

 * * Redistributions of source code must retain the above copyright notice, this
     list of conditions and the following disclaimer.

 * * Redistributions in binary form must reproduce the above copyright notice, this
     list of conditions and the following disclaimer in the documentation and/or
     other materials provided with the distribution.

 * * Neither the name of Majenko Technologies nor the names of its
     contributors may be used to endorse or promote products derived from
     this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
   ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
   WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
   DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
   ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
   (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
   LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
   ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

//static const uint8_t D0   = 16;
//static const uint8_t D1   = 5;
//static const uint8_t D2   = 4;
//static const uint8_t D3   = 0;
//static const uint8_t D4   = 2;
//static const uint8_t D5   = 14;
//static const uint8_t D6   = 12;
//static const uint8_t D7   = 13;
//static const uint8_t D8   = 15;
//static const uint8_t D9   = 3;
//static const uint8_t D10  = 1;
#include <Robojax_L298N_DC_motor.h>
// motor 1 settings
#define IN1 D6
#define IN2 D7
#define ENA D8 // this pin must be PWM enabled pin
const int CCW = 2; // do not change
const int CW  = 1; // do not change
int motorDirection = CW;
#define motor1 1 // do not change
// use the line below for single motor
Robojax_L298N_DC_motor motor(IN1, IN2, ENA, true);
String accessName = "robojaxESP8266";
const int changeStep = 5;// 10 is 10% every time button is pushed
int outPutValue = 40;// variable holding the light output vlaue (initial value) 40 means 40%
const int motorMinimumSpeed = 20;
#include "robojax_speed_control_page.h"

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>



#ifndef STASSID
#define STASSID "Oi_CD63"
#define STAPSK  "t4S7VEqp"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;

ESP8266WebServer server(80);

void handleRoot() {
  String HTML_page = speed_control_page_part1;

  HTML_page.concat(outPutValue);
  HTML_page.concat(speed_control_page_part2);
  HTML_page.concat(outPutValue);
  HTML_page.concat(speed_control_page_part3);


  server.send(200, "text/html", HTML_page);

}

void handleNotFound() {

  String message = "File Not Found                   ";
  message += "URI: ";
  message += server.uri();
  message += "             Method: ";
  message += (server.method() == HTTP_GET) ? "GET" : "POST";
  message += "             Arguments: ";
  message += server.args();
  message += "             ";

  for (uint8_t i = 0; i < server.args(); i++) {
    message += " " + server.argName(i) + ": " + server.arg(i) + "               ";
  }

  server.send(404, "text/plain", message);

}

void setup(void) {

  Serial.begin(115200);
  motor.begin();
  //L298N DC Motor by Robojax.com


  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin(accessName)) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/speed", HTTP_GET, handleMotorSpeed);
  server.onNotFound(handleNotFound);
  server.begin();
  Serial.println("HTTP server started");

}

void loop(void) {

  server.handleClient();
  MDNS.update();

  motor.rotate(motor1, outPutValue, motorDirection);//run motor1 at 60% speed in CW direction


  delay(100);
}

/*
   handleMotorSpeed()
   Slows down or speeds up the motor
   returns nothing
    Written by Ahmad Shamshiri on Nov 02, 2019
   www.Robojax.com
*/
void handleMotorSpeed() {
  if (server.arg("do") == "slower")
  {
    outPutValue -= changeStep;

    if (outPutValue < motorMinimumSpeed)
    {
      outPutValue = motorMinimumSpeed;
    }
  } else {
    outPutValue += changeStep;

    if (outPutValue > 100)
    {
      outPutValue = 100;
    }
  }

  handleRoot();
}
