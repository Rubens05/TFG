/*
 * ON Board LED GPIO 2
 */
#include <Arduino.h>
#include <esp_now.h>
#include <WiFi.h>
#define BUILT_IN_LED 2

void setup()
{
  // initialize serial port
  Serial.begin(9600);
  // Set pin mode
  pinMode(BUILT_IN_LED, OUTPUT);


  // Inicializa la conexión Wi-Fi
  WiFi.begin("Orange-E475", "3mcUAJZC");

  // Espera a que se establezca la conexión
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print("\nConectando a WiFi...");
  }

  // Obtiene la dirección MAC
  uint8_t mac[6];
  WiFi.macAddress(mac);

  Serial.print("Dirección MAC: ");
  for (int i = 0; i < 6; i++)
  {
    Serial.printf("%02X", mac[i]);
    if (i < 5)
    {
      Serial.print(":");
    }
  }
  //Inicializar ESP-NOW
  if (esp_now_init() == ESP_OK) {
    Serial.println("\nInicializado ESP-NOW");
    return;
}

  // Tu código adicional aquí
}
void loop()
{
  digitalWrite(BUILT_IN_LED, HIGH);
  delay(1000);
  digitalWrite(BUILT_IN_LED, LOW);
  delay(1000);
  
}
