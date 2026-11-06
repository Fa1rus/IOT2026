// Page 16-17: Ultrasonic Distance Sensor Test (Arduino Uno)
int ULTRASOUND_TRANSMITTER = 12;
int ULTRASOUND_RECEIVER = 13;
void setup() {
  pinMode(ULTRASOUND_TRANSMITTER, OUTPUT);
  pinMode(ULTRASOUND_RECEIVER, INPUT);
  Serial.begin(57600);
}
void loop() {
  digitalWrite(ULTRASOUND_TRANSMITTER, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASOUND_TRANSMITTER, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASOUND_TRANSMITTER, LOW);
  float distance = pulseIn(ULTRASOUND_RECEIVER, HIGH) / 58.00;
  delay(10);
  Serial.print(distance);
  Serial.print(" ");
  Serial.println("cm");
  delay(200);
}
