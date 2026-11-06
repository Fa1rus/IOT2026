// Page 23 (Top): ESP32-CAM Send "Hello" to Arduino Uno via Serial1 (ESP32-CAM)
#define RX_PIN -1 
#define TX_PIN 13
void setup() {
  Serial1.begin(115200, SERIAL_8N1, RX_PIN, TX_PIN);
}
void loop() {
  Serial1.println("Hello");
  delay(500);
}
