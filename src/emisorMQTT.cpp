#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Orange-E475";
const char* password = "3mcUAJZC";
const char* mqttServer = "192.168.1.117";
const char* username = "ruben";
const char* passwordMQ = "ruben";
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

void setup() {
  Serial.begin(9600);
  setup_wifi();
  client.setServer(mqttServer, mqttPort);
}

void loop() {
  if (!client.connected()) {
    if (client.connect("ESP32Client",username, passwordMQ)) {
      Serial.println("Conectado al broker MQTT");
    }
    else {
      Serial.println("Fallo al conectar al broker MQTT");
      delay(5000);
      return;
    }
  }

  client.loop();

  // Enviar mensaje MQTT
  client.publish(mqttTopic, "Hola desde ESP32");

  delay(5000);  // Enviar cada 5 segundos
}
