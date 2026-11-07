// Complete Movement Functions: Forward, Backward, Left, Right, Stop (Arduino Uno)
int LEFT_WHEELS = 2;
int LEFT_WHEELS_SPEED = 5;
int RIGHT_WHEELS = 4;
int RIGHT_WHEELS_SPEED = 6; 

// Move forward: Left = HIGH (forward), Right = LOW (forward)
void car_forward(int left_speed, int right_speed) {
    digitalWrite(LEFT_WHEELS, HIGH);
    analogWrite(LEFT_WHEELS_SPEED, left_speed);
    digitalWrite(RIGHT_WHEELS, LOW);
    analogWrite(RIGHT_WHEELS_SPEED, right_speed);
}

// Move backward: Left = LOW (backward), Right = HIGH (backward)
void car_backward(int left_speed, int right_speed) {
    digitalWrite(LEFT_WHEELS, LOW);
    analogWrite(LEFT_WHEELS_SPEED, left_speed);
    digitalWrite(RIGHT_WHEELS, HIGH);
    analogWrite(RIGHT_WHEELS_SPEED, right_speed);
}

// Rotate left in place: Left = LOW (backward), Right = LOW (forward)
void car_left(int speed) {
    digitalWrite(LEFT_WHEELS, LOW);
    analogWrite(LEFT_WHEELS_SPEED, speed);
    digitalWrite(RIGHT_WHEELS, LOW);
    analogWrite(RIGHT_WHEELS_SPEED, speed);
}

// Rotate right in place: Left = HIGH (forward), Right = HIGH (backward)
void car_right(int speed) {
    digitalWrite(LEFT_WHEELS, HIGH);
    analogWrite(LEFT_WHEELS_SPEED, speed);
    digitalWrite(RIGHT_WHEELS, HIGH);
    analogWrite(RIGHT_WHEELS_SPEED, speed);
}

// Stop all wheels
void car_stop() {
    analogWrite(LEFT_WHEELS_SPEED, 0);
    analogWrite(RIGHT_WHEELS_SPEED, 0);
}

void setup() {
    pinMode(LEFT_WHEELS, OUTPUT);
    pinMode(LEFT_WHEELS_SPEED, OUTPUT);
    pinMode(RIGHT_WHEELS, OUTPUT);
    pinMode(RIGHT_WHEELS_SPEED, OUTPUT);

    // Demo sequence: Forward -> Backward -> Left -> Right -> Stop
    car_forward(150, 150);
    delay(2000);
    car_stop();
    delay(500);

    car_backward(150, 150);
    delay(2000);
    car_stop();
    delay(500);

    car_left(150);
    delay(1000);
    car_stop();
    delay(500);

    car_right(150);
    delay(1000);
    car_stop();
}

void loop() {
}
