// Page 25-26: ESP32-CAM WiFi Access Point (AP) Mode (ESP32-CAM)
#include <WiFi.h>
const char* ssid = "ESP32-CAM_AP";
const char* password = "12345678";
void setup() {
  Serial.begin(57600);
  WiFi.softAP(ssid, password);
  Serial.println("");
  Serial.print("ESP32-CAM IP Address: ");
  Serial.println(WiFi.softAPIP());
}

void loop() {
}
