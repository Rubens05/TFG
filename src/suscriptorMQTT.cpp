#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Orange-E475";
const char* password = "3mcUAJZC";
const char* mqttServer = "192.168.1.117";
const int mqttPort = 1883;
const char* mqttTopic = "prueba";

WiFiClient espClient;
PubSubClient client(espClient);

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conectado a la red WiFi");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido en el tema: ");
  Serial.println(topic);
  Serial.print("Contenido del mensaje: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqttServer, mqttPort);
  client.setCallback(callback);

  if (!client.connected()) {
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado al broker MQTT");
      client.subscribe(mqttTopic);
    }
    else {
      Serial.println("Fallo al conectar al broker MQTT");
    }
  }
}

void loop() {
  if (!client.connected()) {
    if (client.connect("ESP32Client")) {
      Serial.println("Conectado al broker MQTT");
      client.subscribe(mqttTopic);
    }
    else {
      Serial.println("Fallo al conectar al broker MQTT");
    }
  }

  client.loop();
}
