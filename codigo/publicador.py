import paho.mqtt.client as mqtt
import time

# Definir el nombre del cliente
client_name = "Publisher-Client"

# Definir el nombre del tema al que se publicará
topic = "test_topic"

# Definir el mensaje a publicar
message = "Enviando datos desde el publicador!"

# Definir el callback para cuando se conecte el cliente
def on_connect(client, userdata, flags, rc):
    print("Connected with result code " + str(rc))
    # Publicar el mensaje al conectarse
    client.publish(topic, message)

# Crear una instancia del cliente MQTT
client = mqtt.Client(client_name)

# Establecer el callback de conexión
client.on_connect = on_connect

# Conectar al broker MQTT (por defecto, localhost)
client.connect("localhost", 1883, 60)

# Mantener la conexión activa
client.loop_forever()
