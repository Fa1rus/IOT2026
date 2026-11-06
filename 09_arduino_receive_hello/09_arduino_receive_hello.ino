// Page 23 (Bottom): Arduino Uno Receive "Hello" from ESP32-CAM (Arduino Uno)
String temp = "";
void setup() {
  Serial.begin(115200);
}
void loop() {
  temp = "";
  while (Serial.available() > 0) {
    temp = temp + ((char)(Serial.read()));
    delay(2); 
  }
  temp.trim();
  if (temp != "") {
    Serial.println(temp);
  }
}
