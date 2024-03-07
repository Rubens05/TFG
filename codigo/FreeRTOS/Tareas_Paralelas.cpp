//HACER EJEMPLO CON FREERTOS QUE SEA 
//1 CREAR TAREA QUE IMPRIMA HOLA MUNDO
//2 CREAR TAREA QUE IMPRIMA UN MENSAJE QUE LE ESTOY PASANDO POR COLA DE MENSAJES

#include <Arduino.h>

void Tarea1( void * parameter );
void Tarea2( void * parameter );

void setup() {

  Serial.begin(9600);
  delay(1000);

  xTaskCreate(Tarea1,"Tarea1",10000,NULL,1,NULL);
  xTaskCreate(Tarea2,"Tarea2",10000,NULL,1,NULL);

}

void loop() {
  delay(1000);
}

void Tarea1( void * parameter )
{
    for( int i = 0;i<10;i++ ){ // Escribe 10 veces 
        Serial.println("Task 1: Operación hecha");
        delay(random(1000, 5000)); // Espera entre 1 y 5 segundos
    }
    Serial.println("Finalizando tarea 1");
    vTaskDelete( NULL );
}

void Tarea2(void * parameter) {
    for (int i = 0; i < 10; i++) {
        int a = i;
        int b = random(0, 10);
        int c = a + b;

        // Crear una cadena formateada con sprintf
        char buffer[50];
        sprintf(buffer, "Task 2: %d + %d = %d", a, b, c);
        
        Serial.println(buffer);

        delay(random(1000, 5000)); // Espera entre 1 y 5 segundos
    }
    Serial.println("Finalizando tarea 2");
    vTaskDelete(NULL);
}
