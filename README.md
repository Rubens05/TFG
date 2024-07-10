# REPOSITORIO DE PRUEBAS TFG

El repositorio de la librería RemoteLogLibrary: 
https://github.com/Rubens05/RemoteLogLibrary.git

El repositorio de la GUI: \
https://github.com/Rubens05/RemoteLogLibraryUI.git

Para implementar el flujo [ESP32 -> Broker Mosquitto -> Telegraf -> MongoDB] simplemente basta con ejecutar el **docker-compose.yml** que se encuentra en ``` bash codigo/docker-compose ```.

# 1. Configuración de Autenticación Mosquitto
El servicio Mosquitto está configurado para utilizar un usuario y una contraseña.

Para este ejemplo se debe añadir un usuario y una contraseña en un archivo llamado **mosquitto_passwords**, en el directorio ```codigo/docker-compose/config```.

### 1.1 Creación de usuario y contraseña

Dentro del directorio ``config`` ejecutar el comando  **sudo mosquitto_passwd -c mosquitto_passwords usuario**
tras el comando se solicitará ingresar una contraseña.

Se pueden crear tantos usuarios y contraseñas como se deseen. En este ejemplo se usan los valores usuario = "user" y contraseña = "user1"

# 2. Configuración de Mongo
Para el servicio Mongo es necesario crear un usuario root en la colección admin. Para ello se deben ejecutar los siguientes comandos

Primero entrar en el contenedor docker
```bash 
docker exec -it mongo-container bash
```

Una vez dentro conectar a la base de datos mongo con
```bash
mongosh
```

Cambiar a la colección admin con el comando
```bash
use admin
```

Y finalmente crear el usuario con

```bash
db.createUser({
  user: "mongoadmin",
  pwd: "mongopassword",
  roles: [{ role: "root", db: "admin" }]
})
```

# 3. Configuración de Telegraf

En el archivo de configuración de Telegraf hay que establecer los inputs y outputs, que en este caso son Mosquitto y MongoDB. Además de las configuraciones que se explican a continuación, se pueden observar más configuraciones comentadas que el usuario puede explorar y modificar.

### 3.1 Input Mosquitto

En esta configuración hay que definir el server y puerto donde se encuentra Mosquitto, que es el nombre del contenedor en el docker-compose.yml (mqtt5) y el puerto por defecto 1883.

También es necesario definir los topics a los que se subscribe Telegraf, el usuario y contraseña creado anteriormente en el archivo **mosquitto_passwords** y, el formato de los datos que va a recibir. En este caso el formato de datos es un JSON con 4 campos tipo string y uno timestamp.

### 3.2 Output MongoDB
En este caso hay que definir la cadena de conexión a la base de datos, puede ser una base de datos en local o en la nube con MongoDB Atlas. También hay que definir el usuario y contraseña creados anteriormente para mongo para poder almacenar la información en la base de datos. Y por último se debe establecer una base de datos en la que se almacenarán estos.


# 4. Despliegue 
Una vez esta todo configurado correctamente simplemente basta con ejecutar el comando

```bash
docker-compose up
```

Y ya estará el flujo listo para conectar la placa ESP32 al broker y enviar los datos a Mongo, a través de Telegraf.


![Flujo ESP32 -> MQTT -> Telegraf -> MongoDB](/utils/Flujomqtt.jpg)
