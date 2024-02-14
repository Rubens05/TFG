import paho.mqtt.client as mqtt

# Definir el nombre del cliente
client_name = "Subscriber-Client"

# Definir el nombre del tema al que se suscribirá
topic = "test_topic"

# Definir el callback para cuando lleguen nuevos mensajes
def on_message(client, userdata, msg):
    print("[RECEPTOR] Nuevo mensaje recibido: " + msg.payload.decode())

# Crear una instancia del cliente MQTT
client = mqtt.Client(client_name)

# Establecer el callback de mensaje
client.on_message = on_message

# Conectar al broker MQTT (por defecto, localhost)
client.connect("localhost", 1883, 60)

# Suscribirse al tema
client.subscribe(topic)

# Mantener la conexión activa y esperar mensajes
client.loop_forever()
