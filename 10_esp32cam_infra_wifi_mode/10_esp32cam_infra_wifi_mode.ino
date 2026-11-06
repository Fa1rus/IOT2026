// Page 24-25: ESP32-CAM WiFi Infrastructure Mode (ESP32-CAM)
#include <WiFi.h>
const char* ssid = "IoTAP";
const char* password = "12345678";

void setup() {
  Serial.begin(57600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("ESP32-CAM IP Address: ");
  Serial.println(WiFi.localIP());
}
void loop() {
}
