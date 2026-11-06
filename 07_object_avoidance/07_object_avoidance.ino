// Page 18-19: Obstacle Avoidance (Arduino Uno)
int LEFT_WHEELS = 2;
int LEFT_WHEELS_SPEED = 5;
int RIGHT_WHEELS = 4;
int RIGHT_WHEELS_SPEED = 6;
int ULTRASOUND_TRANSMITTER = 12;
int ULTRASOUND_RECEIVER = 13;

void car_forward(int left_speed, int right_speed) {
  digitalWrite(LEFT_WHEELS, HIGH);
  analogWrite(LEFT_WHEELS_SPEED, left_speed);
  digitalWrite(RIGHT_WHEELS, LOW);
  analogWrite(RIGHT_WHEELS_SPEED, right_speed);
}
void car_rotate_left(int speed) {
  digitalWrite(LEFT_WHEELS, LOW);
  analogWrite(LEFT_WHEELS_SPEED, speed);
  digitalWrite(RIGHT_WHEELS, LOW);
  analogWrite(RIGHT_WHEELS_SPEED, speed);
}
void car_rotate_right(int speed) {
  digitalWrite(LEFT_WHEELS, HIGH);
  analogWrite(LEFT_WHEELS_SPEED, speed);
  digitalWrite(RIGHT_WHEELS, HIGH);
  analogWrite(RIGHT_WHEELS_SPEED, speed);
}
void setup() {
  pinMode(LEFT_WHEELS, OUTPUT);
  pinMode(LEFT_WHEELS_SPEED, OUTPUT);
  pinMode(RIGHT_WHEELS, OUTPUT);
  pinMode(RIGHT_WHEELS_SPEED, OUTPUT);
  pinMode(ULTRASOUND_TRANSMITTER, OUTPUT);
  pinMode(ULTRASOUND_RECEIVER, INPUT);
  Serial.begin(57600);
}
void loop() {
  randomSeed(analogRead(0));
  digitalWrite(ULTRASOUND_TRANSMITTER, LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASOUND_TRANSMITTER, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASOUND_TRANSMITTER, LOW);
  float distance = pulseIn(ULTRASOUND_RECEIVER, HIGH) / 58.00;
  if (distance < 20.0) {
    int rand_value = random(1, 200);
    if (rand_value > 100) {
      car_rotate_right(100);
    } else {
      car_rotate_left(100);
    }
    delay(500);
  } else {
    car_forward(100, 100);
  }
  delay(100);
}
