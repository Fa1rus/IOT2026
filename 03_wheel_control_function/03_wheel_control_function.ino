// Page 9: Wheel Control with Function (Arduino Uno)
int LEFT_WHEELS = 2;
int LEFT_WHEELS_SPEED = 5;
int RIGHT_WHEELS = 4;
int RIGHT_WHEELS_SPEED = 6; 
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
    car_forward(127, 200);
}

void loop() {
}
