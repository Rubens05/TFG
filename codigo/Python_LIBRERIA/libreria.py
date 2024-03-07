import logging
import paho.mqtt.client as mqtt
from time import sleep

client = None  # Definir el cliente MQTT fuera de la función init
logger = logging.getLogger("default") # Definir el logger fuera de la función init

def logger_id(id):
    global logger # Usar la instancia del logger global
    logger = logging.getLogger(id) # Definir id placa en el futuro

def format_message(formato,topic):
    # %(asctime)s: La marca de tiempo en formato de fecha y hora.
    # %(levelname)s: El nivel de registro del mensaje (por ejemplo, DEBUG, INFO, WARNING, ERROR, CRITICAL).
    # %(message)s: El mensaje de registro en sí.
    # %(name)s: El nombre del registrador que generó el registro.
    # %(filename)s: El nombre del archivo en el que se generó el registro.
    # %(lineno)d: El número de línea dentro del archivo donde se generó el registro.
    # %(process)d: El ID del proceso que generó el registro.
    # %(thread)d: El ID del hilo que generó el registro.

    # Configurar el formato de registro
        formatter = logging.Formatter(formato)

     # Configurar el manejador de registro para enviar los mensajes al broker MQTT
        class MQTTHandler(logging.Handler):
            def emit(self, record):
                message = self.format(record)
                client.publish(topic, message)

        # Configurar el logger
        logger.setLevel(logging.DEBUG)

    # Agregar el manejador de registro MQTT al logger
        mqtt_handler = MQTTHandler()
        mqtt_handler.setFormatter(formatter)
        logger.addHandler(mqtt_handler)

def init(mqtt_server, mqtt_port): 
    global client  # Usar la instancia del cliente global
    if client is None:  # Crear el cliente solo si no existe
        # Configurar el cliente MQTT
        client = mqtt.Client()
        connected = client.connect(mqtt_server, mqtt_port)
        if connected == 0:
            print("Conectado al broker")
        else:
            print("Fallo al conectar al broker")  # Avisar si hay un fallo en la conexión
        
    else:
        print("Ya existe una instancia del cliente MQTT")

    return client, logger

def close():
    if client is not None:
        client.disconnect()
        print("Desconectado del broker")
    else:
        print("No hay cliente MQTT para desconectar")




############################################ FUNCIONES DE LOG ############################################

def log_info( message, identifier):
    extra = {'identifier': identifier}
    logger.info(message, extra) #lineno imprime esta linea
    
def log_debug(message, identifier):
    """
    Emite un mensaje de depuración.
    """ 
    extra = {'identifier': identifier}
    logger.debug(message, extra) #lineno imprime esta linea

def log_error(message, identifier):
    """
    Emite un mensaje de error.
    """
    extra = {'identifier': identifier}
    logger.error(message, extra) #lineno imprime esta linea

def log_warning(message, identifier):
    """
    Emite un mensaje de advertencia.
    """
    extra = {'identifier': identifier}
    logger.warning(message, extra)  #lineno imprime esta linea

def log_critical(message, identifier):
    """
    Emite un mensaje crítico.
    """
    extra = {'identifier': identifier}
    logger.critical(message, extra) #lineno imprime esta linea
