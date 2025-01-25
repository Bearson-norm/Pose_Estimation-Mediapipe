#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
//#include "MQTT_site.h"

#define NUM_SERVOS 5
#define PCA9685_ADDR 0x40

const char* topics[NUM_SERVOS] = {"thumb", "index", "middle", "ring", "little"};

// Kredensial WiFi
const char* ssid = "Betapa Bahagianya Hatiku Saat?";
const char* password = "kududukberduadenganmu";

// Kredensial MQTT
const char* mqtt_server = "103.127.138.196";
const int mqtt_port = 1883;
const char* mqtt_user = "MQTT_USERNAME";
const char* mqtt_password = "MQTT_PASSWORD";

// Define minimum and maximum servo pulse widths (in microseconds)
const int servoMinPulse = 208;
const int servoMaxPulse = 588;

Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(PCA9685_ADDR);

WiFiClient espClient;
PubSubClient client(espClient);

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    if (client.connect("ESP8266Client", mqtt_user, mqtt_password)) {
      Serial.println("connected");
      for (int i = 0; i < NUM_SERVOS; i++) {
        client.subscribe(topics[i]);
      }
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, mqtt_port);
  client.setCallback(callback);

  pca9685.begin();
  pca9685.setPWMFreq(50);  // Set PWM frequency to 50 Hz

  delay(10);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  int attempt = 0;
  while (WiFi.status() != WL_CONNECTED && attempt < 20) {
    delay(500);
    Serial.print(".");
    attempt++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Failed to connect to WiFi");
  }
}

void callback(char* topic, byte* message, unsigned int length) {
  char messageTemp[256];
  if (length >= sizeof(messageTemp)) {
    Serial.println("Message too long");
    return;
  }

  memcpy(messageTemp, message, length);
  messageTemp[length] = '\0';

  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  Serial.println(messageTemp);

  int servoIndex = -1;
  for (int i = 0; i < NUM_SERVOS; i++) {
    if (strcmp(topic, topics[i]) == 0) {
      servoIndex = i;
      break;
    }
  }
  
  if (servoIndex != -1) {
    int angle = atoi(messageTemp);
    int pulseWidth = map(angle, 0, 180, servoMinPulse, servoMaxPulse);
    pca9685.setPWM(servoIndex, 0, pulseWidth);
  }
}
