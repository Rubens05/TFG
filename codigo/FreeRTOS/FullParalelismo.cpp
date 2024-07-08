// Codigo para hacer varias tareas en paralelo
// 1. Crear una tarea que imprima "Hola mundo" cada n segundos
// 2. Crear una tarea que inserte un mensaje en una cola
// 3. Crear una tarea que imprima el mensaje que le estoy pasando por cola de mensajes
// 4. Hacer una operacion matematica en una tarea cada n segundos

#include <Arduino.h>
#include <WiFi.h>

#define Task1Delay 400
#define Task2Delay 2000
#define Task3Delay 1000
#define Task4Delay 1700
#define BUILT_IN_LED 2

void Tarea1(void *parameter);
void Tarea2(void *parameter);
void Tarea3(void *parameter);
void Tarea4(void *parameter);

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
    xTaskCreate(Tarea3, "Tarea3", 10000, NULL, 1, NULL);
    xTaskCreate(Tarea4, "Tarea4", 10000, NULL, 1, NULL);
}

void loop()
{
    delay(1000);
}

void Tarea1(void *parameter)
{
    for (int i = 0; i < 5; i++)
    { // Escribe 5 veces
        Serial.println("[Task 1]: Hola Mundo");
        vTaskDelay(pdMS_TO_TICKS(Task1Delay));
    }
    printf("[Task 1] Finalizando tarea 1\n");
    vTaskDelete(NULL);
}

void Tarea2(void *parameter)
{
    for (int i = 0; i < 5; i++)
    {
        int a = i;
        int b = random(0, 10);
        int c = a + b;

        // Crear una cadena formateada con sprintf
        char buffer[50];
        sprintf(buffer, "[Task 2]: %d + %d = %d", a, b, c);
        printf("%s\n", buffer);

        vTaskDelay(pdMS_TO_TICKS(Task2Delay));
    }
    printf("[Task 2] Finalizando tarea 2\n");
    vTaskDelete(NULL);
}

void Tarea3(void *parameter)
{

    for (int i = 0; i < 5; i++)
    {
        vTaskDelay(pdMS_TO_TICKS(Task3Delay));
        ESP_LOGI("[Task 3]", "Enviando %i a la cola", i); // No se imprime
        printf("[Task 3] Enviando %i a la cola\n", i);
        if (!xQueueSend(GlobalQueue, &i, pdMS_TO_TICKS(1000)))
        {
            ESP_LOGE("[Task 3]", "Error al enviar %i a la cola está llena", i);
        }
        vTaskDelay(pdMS_TO_TICKS(Task3Delay));
    }
    printf("[Task 3] Finalizando tarea 3\n");
    vTaskDelete(NULL);
}

void Tarea4(void *parameter)
{
    int valorRecibido;
    int limite = 5;
    while (1)
    {
        if (!xQueueReceive(GlobalQueue, &valorRecibido, pdMS_TO_TICKS(100)))
        {
            ESP_LOGE("[Task 4]", "No hay datos en la cola");
            limite--;
            if (limite == 0)
            {
                break;
            }
        }
        else
        {
            limite = 5;
            vTaskDelay(pdMS_TO_TICKS(Task4Delay));
            digitalWrite(BUILT_IN_LED, HIGH);
            ESP_LOGI("[Task 4]", "Recibido %i de la cola", valorRecibido); // No se imprime
            printf("[Task 4] Recibido %i de la cola\n", valorRecibido);
            vTaskDelay(pdMS_TO_TICKS(Task4Delay));
            digitalWrite(BUILT_IN_LED, LOW);
        }
        vTaskDelay(pdMS_TO_TICKS(500));
    }
    printf("[Task 4] Finalizando tarea 4\n");
    vTaskDelete(NULL);
}