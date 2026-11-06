// Page 13-15: Line Tracking (Arduino Uno)
int LEFT_WHEELS = 2;
int LEFT_WHEELS_SPEED = 5;
int RIGHT_WHEELS = 4;
int RIGHT_WHEELS_SPEED = 6; 

int LEFT_SENSOR = 7;
int MID_SENSOR = 8;
int RIGHT_SENSOR = 9;

void car_forward(int left_speed, int right_speed) {
  digitalWrite(LEFT_WHEELS, HIGH);
  analogWrite(LEFT_WHEELS_SPEED, left_speed);
  digitalWrite(RIGHT_WHEELS, LOW);
  analogWrite(RIGHT_WHEELS_SPEED, right_speed);
}

void setup() {
  pinMode(LEFT_WHEELS, OUTPUT);
  pinMode(LEFT_WHEELS_SPEED, OUTPUT);
  pinMode(RIGHT_WHEELS, OUTPUT);
  pinMode(RIGHT_WHEELS_SPEED, OUTPUT);

  pinMode(LEFT_SENSOR, INPUT_PULLUP);
  pinMode(MID_SENSOR, INPUT_PULLUP);
  pinMode(RIGHT_SENSOR, INPUT_PULLUP);
}

void loop() {
  int left_value(digitalRead(LEFT_SENSOR));
  int mid_value(digitalRead(MID_SENSOR));
  int right_value(digitalRead(RIGHT_SENSOR));

  if (left_value == 0 && mid_value == 1 && right_value == 0) { //OK
    car_forward(120, 120);
  } else if (left_value == 0 && mid_value == 0 && right_value == 1) { //slight left
    car_forward(10, 120);
  } else if (left_value == 1 && mid_value == 0 && right_value == 0) { //slight right
    car_forward(120, 10);
  } else { // error choose to stop
    car_forward(0, 0); //stop
  }
}
