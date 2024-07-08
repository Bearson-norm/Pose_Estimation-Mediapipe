// #include <ESP8266WiFi.h>
// #include <PubSubClient.h>
// #define NUM_TOPIC 5

// // Kredensial WiFi
// const char* ssid = "AHA";
// const char* password = "legaenak";

// // Kredensial MQTT
// const char* mqtt_server = "dimasalifta.tech";
// const int mqtt_port = 1883;
// const char* mqtt_user = "MQTT_USERNAME";
// const char* mqtt_password = "MQTT_PASSWORD";

// // Assigning topic
// // const char* topic = "thumb";
// // const char* topic1 = "point";
// // const char* topic2 = "middle";
// // const char* topic3 = "index";
// // const char* topic4 = "little";
// const char* topic[NUM_TOPIC] = {"thumb", "point", "middle", "index", "little"};
// // 0 = thumb, 1 = point, 2 = middle, 3 = index, 4 = little

// WiFiClient espClient;
// PubSubClient client(espClient);

// void callback(char* topic, byte* payload, unsigned int length) {
//   // Serial.print("Pesan diterima pada topik: ");
//   // Serial.println(topic[i]);
  
//   for (int i = 0; i < length; i++) {
//     Serial.print((char)payload[i]);
//   }
//   Serial.println();
// }

// // Koneksi ke mqtt
// void connect_mqtt() {
//   WiFi.begin(ssid, password);

//   while (WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }

//   Serial.println("");
//   Serial.println("WiFi terhubung!");

//   client.setServer(mqtt_server, mqtt_port);
//   client.setCallback(callback);
//   // client.subscribe(topic);
//   // client.subscribe(topic1);
//   // client.subscribe(topic2);
//   // client.subscribe(topic3);
//   // client.subscribe(topic4);
//   for (int i = 0; i < NUM_TOPIC; i++) {
//     client.subscribe(topic[i]);
//   }
// }

// // void get_mqtt(){
//   // if (!client.connected()) {
//   //   reconnect();
//   // }
//   // client.loop();

//   // // Check for incoming messages
//   // if (client.available()) {
//   //   for (int i = 0; i < NUM_TOPIC; i++) {
//   //   String message = client.readStringUntil('\n');
//   //   Serial.print("Received message on topic ");
//   //   Serial.print(topic[i]);
//   //   Serial.print(": ");
//   //   Serial.println(message);
//   // }
//     // String message = client.readStringUntil('\n');
//     // Serial.print("Received message on topic ");
//     // Serial.print(topic);
//     // Serial.print(": ");
//     // Serial.println(message);
// //   }
// // }

// // Menyambungkan kembali koneksi
// boolean reconnect() {
//   if (client.connect("WEMOS_D1_R1")) {
//     Serial.println("Terhubung ke broker MQTT!");
//     return true;
//   } else {
//     Serial.print("Koneksi MQTT gagal: ");
//     Serial.println(client.state());
//     return false;
//   }
// }
