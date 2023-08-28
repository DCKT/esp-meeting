
#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <Arduino_JSON.h>

U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, 14, 12, U8X8_PIN_NONE);

void setup(void) {
  Serial.begin(115200);
  u8g2.begin();
  initWiFi();
}

void loop(void) {
  checkWifi();
  getBusyState();
}


