#include <Servo.h>
#include <Adafruit_PWMServoDriver.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#define NUM_TOPIC 5

// Define the number of servos and PCA9685 address
#define NUM_SERVOS 5
#define PCA9685_ADDR 0x40

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(PCA9685_ADDR);

// Define potentiometer pins
const int potPins[NUM_SERVOS] = {A0};

// Define minimum and maximum servo pulse widths (in microseconds)
const int servoMinPulse = 150;
const int servoMaxPulse = 600;

Servo servos[NUM_SERVOS];

// WiFiClient espClient;
// PubSubClient client(espClient);

void setup() {
  // connect_mqtt();
  pca9685.begin();
  pca9685.setPWMFreq(50);  // Set PWM frequency to 50 Hz

  // Attach servos to PCA9685 channels
  for (int i = 0; i < NUM_SERVOS; i++) {
    servos[i].attach(i);
  }
}

void loop() {
  // // get_mqtt();
  // if (!client.connected()) {
  //   reconnect();
  // }
  // client.loop();

  // // Check for incoming messages
  // if (client.available()) {
  //   for (int i = 0; i < NUM_TOPIC; i++) {
  //   String message = client.readStringUntil('\n');
  //   Serial.print("Received message on topic ");
  //   Serial.print(topic[i]);
  //   Serial.print(": ");
  //   Serial.println(message);
  //   }
  // }
  for (int i = 0; i < NUM_SERVOS; i++) {
    // Read analog value from potentiometer
    int potValue = analogRead(potPins[i]);

    // Map potentiometer value to servo pulse width
    int pulseWidth = map(potValue, 0, 1023, servoMinPulse, servoMaxPulse);

    // Set servo position based on pulse width
    servos[i].writeMicroseconds(pulseWidth);
  }
  delay(15);  // Add a small delay to avoid overwhelming communication
}

