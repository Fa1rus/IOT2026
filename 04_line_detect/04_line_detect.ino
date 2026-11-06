// Page 9-10: Line Sensor Detection Test (Arduino Uno)
int LEFT_SENSOR = 7;
void setup() {
  pinMode(LEFT_SENSOR, INPUT_PULLUP);
  Serial.begin(57600);
}

void loop() {
  int left_value = digitalRead(LEFT_SENSOR);
  Serial.println(left_value);
  delay(200);
}
