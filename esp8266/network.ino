const char *ssid = "";
const char *password = "";
unsigned long previousMillis = 0;
unsigned long interval = 30000;

void initWiFi()
{
  writeScreen("Connecting to WiFi ..");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print('.');
    delay(1000);
  }
  writeScreen("Wifi connected !");
  Serial.println(WiFi.localIP());
  // The ESP8266 tries to reconnect automatically when the connection is lost
  WiFi.setAutoReconnect(true);
  WiFi.persistent(true);
}

void checkWifi()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval)
  {
    switch (WiFi.status())
    {
    case WL_NO_SSID_AVAIL:
      writeScreen("Configured SSID cannot be reached");
      break;
    case WL_CONNECT_FAILED:
      writeScreen("Connection failed");
      break;
    }
    Serial.printf("Connection status: %d\n", WiFi.status());
    Serial.print("RRSI: ");
    Serial.println(WiFi.RSSI());
    previousMillis = currentMillis;
  }
}
