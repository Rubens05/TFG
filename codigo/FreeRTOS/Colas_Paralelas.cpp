// HACER EJEMPLO CON FREERTOS QUE SEA
// 1 CREAR TAREA QUE IMPRIMA HOLA MUNDO
// 2 CREAR TAREA QUE IMPRIMA UN MENSAJE QUE LE ESTOY PASANDO POR COLA DE MENSAJES

#include <Arduino.h>

#define Task1Delay 400
#define Task2Delay 2000
#define BUILT_IN_LED 2

void Tarea1(void *parameter);
void Tarea2(void *parameter);

QueueHandle_t GlobalQueue = 0;

void setup()
{

  Serial.begin(9600);
  delay(1000);
  pinMode(BUILT_IN_LED, OUTPUT);
  esp_log_level_set("*", ESP_LOG_VERBOSE);
  GlobalQueue = xQueueCreate(10, sizeof(int));

  xTaskCreate(Tarea1, "Tarea1", 10000, NULL, 1, NULL);
  xTaskCreate(Tarea2, "Tarea2", 10000, NULL, 1, NULL);
}

void loop()
{
  delay(1000);
}

void Tarea1(void *parameter)
{

  for (int i = 0; i < 10; i++)
  {
    vTaskDelay(pdMS_TO_TICKS(Task1Delay));
    ESP_LOGI("Tarea1", "Enviando %i a la cola", i); // No se imprime
    printf("Enviando %i a la cola\n", i);
    if (!xQueueSend(GlobalQueue, &i, pdMS_TO_TICKS(1000)))
    {
      ESP_LOGE("Tarea1", "Error al enviar %i a la cola", i);
    }
    vTaskDelay(pdMS_TO_TICKS(Task1Delay));
  }
}

void Tarea2(void *parameter)
{
  int valorRecibido;

  while (1)
  {
    if (!xQueueReceive(GlobalQueue, &valorRecibido, pdMS_TO_TICKS(100)))
    {
      ESP_LOGE("Tarea2", "Error al recibir de la cola");
    }
    else
    {
      vTaskDelay(pdMS_TO_TICKS(Task2Delay));
      digitalWrite(BUILT_IN_LED, HIGH);
      ESP_LOGI("Tarea2", "Recibido %i de la cola", valorRecibido); // No se imprime
      printf("Recibido %i de la cola\n", valorRecibido);
      vTaskDelay(pdMS_TO_TICKS(Task2Delay));
      digitalWrite(BUILT_IN_LED, LOW);
    }
    vTaskDelay(pdMS_TO_TICKS(100));
  }
}
