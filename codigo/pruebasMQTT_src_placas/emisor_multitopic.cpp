#include <Arduino.h>
#include <WiFi.h>
#include <PubSubClient.h>
#define BUILT_IN_LED 2

const char *ssid = "Orange-E475";
const char *password = "3mcUAJZC";
const char *mqttServer = "192.168.1.117";
// const char* ssid = "DIGIFIBRA-HdQF";
// const char* password = "4FXX5tAc37bA";
// const char* mqttServer = "192.168.1.131";
const char *username = "ruben";
const char *passwordMQ = "ruben";
const int mqttPort = 1883;

WiFiClient espClient;
PubSubClient client(espClient);

String direccionMAC;

void setup_wifi()
{
  delay(10);
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("Conectado a la red WiFi");
  Serial.println("Dirección IP: ");
  Serial.println(WiFi.localIP());
}

void setup()
{
  Serial.begin(9600);
  pinMode(BUILT_IN_LED, OUTPUT);

  setup_wifi();

  // Obtiene la dirección MAC
  uint8_t mac[6];
  WiFi.macAddress(mac);

  direccionMAC = "Dirección MAC: ";
  for (int i = 0; i < 6; i++)
  {
    char buf[3];                  // Buffer para convertir cada byte de la MAC a hexadecimal
    sprintf(buf, "%02X", mac[i]); // Convertir byte a hexadecimal
    direccionMAC += buf;          // Concatenar al string
    if (i < 5)
    {
      direccionMAC += ":"; // Agregar ":" excepto en el último byte
    }
  }

  client.setServer(mqttServer, mqttPort);
}

void loop()
{
  if (!client.connected())
  {
    if (client.connect("ESP32Client", username, passwordMQ))
    {
      Serial.println("Conectado al broker MQTT");
    }
    else
    {
      Serial.println("Fallo al conectar al broker MQTT");
      delay(5000);
      return;
    }
  }

  client.loop();

  // Enviar mensaje MQTT
  digitalWrite(BUILT_IN_LED, HIGH);
  client.publish("topic1", ("Hola desde ESP32, placa con " + direccionMAC).c_str());
  digitalWrite(BUILT_IN_LED, LOW);
  delay(500);
  digitalWrite(BUILT_IN_LED, HIGH);
  delay(500);
  client.publish("topic2", ("Hola desde ESP32, placa con " + direccionMAC).c_str());
  digitalWrite(BUILT_IN_LED, LOW);
  delay(500);
  digitalWrite(BUILT_IN_LED, HIGH);
  delay(500);
  digitalWrite(BUILT_IN_LED, LOW);
  delay(500);
  digitalWrite(BUILT_IN_LED, HIGH);
  client.publish("topic3", ("Hola desde ESP32, placa con " + direccionMAC).c_str());
  delay(20000); // Enviar cada 20 segundos
  digitalWrite(BUILT_IN_LED, LOW);
}
