#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

#define NUM_SERVOS 5
#define PCA9685_ADDR 0x40

// Define minimum and maximum servo pulse widths (in microseconds)
const int servoMinPulse = 208;
const int servoMaxPulse = 588;

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(PCA9685_ADDR);

void setup() {
  Serial.begin(115200);
  pca9685.begin();
  pca9685.setPWMFreq(50);  // Set PWM frequency to 50 Hz
  delay(10);
}

void loop() {
  // Sweep servos from 0 to 180 degrees
  for (int angle = 0; angle <= 180; angle += 5) {
    moveServos(angle);
    delay(50);  // Adjust delay for speed control
  }
  
  // Sweep servos from 180 back to 0 degrees
  for (int angle = 180; angle >= 0; angle -= 5) {
    moveServos(angle);
    delay(50);
  }
}

void moveServos(int angle) {
  int pulseWidth = map(angle, 0, 180, servoMinPulse, servoMaxPulse);
  for (int i = 0; i < NUM_SERVOS; i++) {
    pca9685.setPWM(i, 0, pulseWidth);
  }
  Serial.print("Moving servos to angle: ");
  Serial.println(angle);
}
