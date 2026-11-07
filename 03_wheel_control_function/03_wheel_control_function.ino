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

void car_backward(int left_speed, int right_speed) {
    digitalWrite(LEFT_WHEELS, LOW);
    analogWrite(LEFT_WHEELS_SPEED, left_speed);
    digitalWrite(RIGHT_WHEELS, HIGH);
    analogWrite(RIGHT_WHEELS_SPEED, right_speed);
}

void car_stop() {
    analogWrite(LEFT_WHEELS_SPEED, 0);
    analogWrite(RIGHT_WHEELS_SPEED, 0);
}

void setup() {
    pinMode(LEFT_WHEELS, OUTPUT);
    pinMode(LEFT_WHEELS_SPEED, OUTPUT);
    pinMode(RIGHT_WHEELS, OUTPUT);
    pinMode(RIGHT_WHEELS_SPEED, OUTPUT);

    // Test sequence:
    car_forward(150, 150);   // Move forward
    delay(2000);             // for 2 seconds

    car_stop();              // Pause briefly to protect motor gears
    delay(500);

    car_backward(150, 150);  // Move backward
    delay(2000);             // for 2 seconds

    car_stop();              // Stop
}

void loop() {
}
