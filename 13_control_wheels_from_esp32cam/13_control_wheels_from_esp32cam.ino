// Page 42-44: Control Wheels from ESP32-CAM Commands (Arduino Uno)
int LEFT_WHEELS = 2;
int LEFT_WHEELS_SPEED = 5;
int RIGHT_WHEELS = 4;
int RIGHT_WHEELS_SPEED = 6; 

String come_msg;

void robot_direction(uint8_t left_dir, uint8_t left_speed, uint8_t right_dir, uint8_t right_speed) {
  digitalWrite(LEFT_WHEELS, left_dir);
  analogWrite(LEFT_WHEELS_SPEED, left_speed);
  digitalWrite(RIGHT_WHEELS, right_dir);
  analogWrite(RIGHT_WHEELS_SPEED, right_speed);
}
void setup() {
  pinMode(LEFT_WHEELS, OUTPUT);
  pinMode(LEFT_WHEELS_SPEED, OUTPUT);
  pinMode(RIGHT_WHEELS, OUTPUT);
  pinMode(RIGHT_WHEELS_SPEED, OUTPUT);

  robot_direction(LOW, 0, LOW, 0); //stop
  Serial.begin(115200);
}

void loop() {
  come_msg = "";
  while (Serial.available() > 0) {
    come_msg = come_msg + ((char)(Serial.read()));
    delay(2); 
  }
  come_msg.trim();
  if (come_msg != "") {
    Serial.println(come_msg);
    if (come_msg == "S") { //stop
      robot_direction(LOW, 0, LOW, 0);
    } else if (come_msg == "F") { //forward
      robot_direction(HIGH, 120, LOW, 120);
    } else if (come_msg == "B") { //backward
      robot_direction(LOW, 120, HIGH, 120);
    } else if (come_msg == "L") { //rotate left
      robot_direction(LOW, 120, LOW, 120);
    } else if (come_msg == "R") { //rotate right (Note: fixed '=' typo from PDF page 44 to '==')
      robot_direction(HIGH, 120, HIGH, 120);
    } 
  }
}
