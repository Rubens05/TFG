#define LOG_LOCAL_LEVEL ESP_LOG_VERBOSE
#include "esp_log.h"

static const char* TAG = "MyModule";

void app_main() {
    ESP_LOGE(TAG, "Esto es un mensaje de error");
    ESP_LOGW(TAG, "Esto es un mensaje de advertencia");
    ESP_LOGI(TAG, "Esto es un mensaje de información");
    ESP_LOGD(TAG, "Esto es un mensaje de depuración");
    ESP_LOGV(TAG, "Esto es un mensaje de traza");
}
