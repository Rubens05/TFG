#include <stdio.h>
#include "esp_log.h"

void app_main()
{
    // Configuración básica del sistema de registro
    esp_log_level_set("*", ESP_LOG_INFO); // Establece el nivel de registro a INFO para todas las etiquetas

    // Emisión de algunos mensajes de registro
    ESP_LOGI("MiApp", "Inicio de la aplicación");
    ESP_LOGW("MiApp", "Advertencia: algo podría estar mal");
    ESP_LOGE("MiApp", "Error: algo salió mal");
    ESP_LOGV("MiApp", "Mensaje de depuración");
    ESP_LOGD("MiApp", "Mensaje de depuración detallado");
}
