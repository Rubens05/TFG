from influxdb import InfluxDBClient

# Configurar base de datos InfluxDB
host = 'localhost'
port = 8086
# usuario = 'usuario'
# contraseña = 'contraseña'
database = 'prueba'

# Cliente InfluxDB y conexión a la base de datos
cliente = InfluxDBClient(host, port)

# Definir datos a insertar
punto_de_datos = {
    "measurement": "temperatura",
    "tags": {
        "sensor": "sensor1",
        "ubicacion": "habitacion1"
    },
    "fields": {
        "valor": 25.5
    }
}

# Insertar los datos en la database 
cliente.write_points([punto_de_datos], time_precision='s',database=database)
# Cierra la conexión con la base de datos
cliente.close()


#FUNCIONA