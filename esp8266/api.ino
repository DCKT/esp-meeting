unsigned long lastTime = 0;
unsigned long apiTimerDelay = 30000;
String jsonBuffer;
const String serverPath = "http://192.168.68.107:9887/state";

String httpGETRequest(const char *serverName)
{
  WiFiClient client;
  HTTPClient http;

  // Your IP address with path or Domain name with URL path
  http.begin(client, serverName);

  // Send HTTP POST request
  int httpResponseCode = http.GET();

  String payload = "{}";

  if (httpResponseCode > 0)
  {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    payload = http.getString();
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();

  return payload;
}

void getBusyState()
{
  if ((millis() - lastTime) > apiTimerDelay)
  {
    if (WiFi.status() == WL_CONNECTED)
    {
      jsonBuffer = httpGETRequest(serverPath.c_str());
      JSONVar myObject = JSON.parse(jsonBuffer);

      if (JSON.typeof(myObject) == "undefined")
      {
        writeScreen("API parsing failed!");
        return;
      }

      if (myObject["busy"])
      {
        u8g2.clearBuffer();
        u8g2.setFont(u8g2_font_fur20_tf);
        u8g2.drawStr(0, 24, "REUNION");
        u8g2.sendBuffer();
      }
      else
      {
        u8g2.clearDisplay();
      }
    }
    lastTime = millis();
  }
}