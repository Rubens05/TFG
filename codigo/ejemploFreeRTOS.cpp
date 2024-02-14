#include "Arduino_FreeRTOS.h"

void TaskBlink(void *pvParameters)
{
  (void) pvParameters;

  pinMode(LED_BUILTIN, OUTPUT);

  while(true)
  {
    digitalWrite(LED_BUILTIN, HIGH);
    vTaskDelay( 500 / portTICK_PERIOD_MS );
    digitalWrite(LED_BUILTIN, LOW);    
    vTaskDelay( 500 / portTICK_PERIOD_MS );
  }
}

void setup()
{
  Serial.begin(9600);

  xTaskCreate(
    TaskBlink
    ,  "Blink"    // Nombre de la tarea
    ,  128      // Tamaño de la pila de la tarea
    ,  NULL
    ,  2        // Prioridad, siendo 0 la de menor prioridad, y 3 la de mayor
    ,  NULL );
}

void loop()
{
  Serial.println(millis());
  delay(1000);
}