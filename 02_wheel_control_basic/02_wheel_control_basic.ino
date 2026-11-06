// Page 8: Wheel Control Basic (Arduino Uno)
int LEFT_WHEELS = 2;
int LEFT_WHEELS_SPEED = 5;
int RIGHT_WHEELS = 4;
int RIGHT_WHEELS_SPEED = 6; 
void setup() {
    pinMode(LEFT_WHEELS, OUTPUT);
    pinMode(LEFT_WHEELS_SPEED, OUTPUT);
    pinMode(RIGHT_WHEELS, OUTPUT);
    pinMode(RIGHT_WHEELS_SPEED, OUTPUT);

    digitalWrite(LEFT_WHEELS, HIGH);
    analogWrite(LEFT_WHEELS_SPEED, 127);
    digitalWrite(RIGHT_WHEELS, LOW);
    analogWrite(RIGHT_WHEELS_SPEED, 200);
}

void loop() {
}
