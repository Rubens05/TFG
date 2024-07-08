import libreria as libreria
import paho.mqtt.client as mqtt
import random

if __name__ == "__main__":
    # Configuración
    mqtt_server = "192.168.1.117"
    mqtt_port = 1883
    ssid = "ruben"
    password = "ruben"
    mqtt_topic = "logStatus"
    formatoinfo = '%(asctime)s ---- %(name)s - %(name)s - %(levelname)s - %(message)s - %(levelname)s - %(message)s - %(filename)s - %(lineno)d - %(process)d - %(thread)d'
    formatodebug = '%(asctime)s -- %(name)s - %(levelname)s - %(message)s - %(filename)s'
    formatoerror = '%(ascervefe)s ------ %(name)s - %(levelname)s - %(message)s - %(filename)s - %(process)d - %(thread)d'
    formatowarning = '%(asctime)s ---------- %(name)s - %(levelname)s - %(message)s - %(filename)s - %(lineno)d  - %(thread)d'
    formatocritical = '%(asctime)s -------- %(name)s - %(levelname)s - %(message)s - %(filename)s - %(lineno)d - %(process)d '
    numero_aleatorio = random.randint(1, 5)


    libreria.logger_id(str(numero_aleatorio))
    libreria.init(mqtt_server, mqtt_port)

    

    print(numero_aleatorio)
    if numero_aleatorio == 1:
        libreria.format_message(formatoinfo,mqtt_topic)
        libreria.log_info("Mensaje de información", numero_aleatorio)
    elif numero_aleatorio == 2:
        libreria.format_message(formatodebug,mqtt_topic)
        libreria.log_debug("Mensaje de depuración", numero_aleatorio)
    elif numero_aleatorio == 3:
        libreria.format_message(formatoerror,mqtt_topic)
        libreria.log_error("Mensaje de error", numero_aleatorio)
    elif numero_aleatorio == 4:
        libreria.format_message(formatowarning,mqtt_topic)
        libreria.log_warning("Mensaje de advertencia", numero_aleatorio)
    elif numero_aleatorio == 5:
        libreria.format_message(formatocritical,mqtt_topic)
        libreria.log_critical("Mensaje crítico", numero_aleatorio)

    
    libreria.close()