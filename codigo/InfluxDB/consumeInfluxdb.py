from influxdb import InfluxDBClient

# Conexión con base de datos InfluxDB 
host = 'localhost'
port = 8086
database = 'prueba'

# Cliente InfluxDB y conexión a la base de datos
cliente = InfluxDBClient(host, port)

# Consulta para seleccionar datos de la base de datos
consulta = 'SELECT * FROM temperatura'

# Ejecutar la consulta y guardar en resultados
resultados = cliente.query(consulta,database=database)

# Imprime los resultados
for registro in resultados.get_points():
    print(f'Tiempo: {registro["time"]}, Sensor: {registro["sensor"]}, Ubicación: {registro["ubicacion"]}, Valor: {registro["valor"]}')

# Cierra la conexión con la base de datos
cliente.close()

#FUNCIONA