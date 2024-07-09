# REPOSITORIO DE PRUEBAS TFG

El repositorio de la librería RemoteLogLibrary: 
https://github.com/Rubens05/RemoteLogLibrary.git

El repositorio de la GUI: \
https://github.com/Rubens05/RemoteLogLibraryUI.git

Para implementar el flujo [ESP32 -> Broker Mosquitto -> Telegraf -> MongoDB] simplemente basta con ejecutar el **docker-compose.yml** que se encuentra en ``` bash codigo/docker-compose ```.

## 1. Configuración de Autenticación Mosquitto
El servicio Mosquitto está configurado para utilizar un usuario y una contraseña.

Para este ejemplo se debe añadir un usuario y una constraseña en un archivo llamado **mosquitto_passwords**, en el directorio ```codigo/docker-compose/config```.

### 1.1 Creación de usuario y contraseña

Dentro del directorio ``config`` ejecutar el comando  **mosquitto_passwd -c mosquitto_passwords usuario**
tras el comando se solicitará ingresar una contraseña.

Se pueden crear tantos usuarios y contraseñas como se deseen. En este ejemplo se usan los valores usuario = "user" y contraseña = "user1"

## 2. Configuración de Telegraf

En el archivo de configuración de Telegraf hay que establecer los inputs y outputs, que en este caso son Mosquitto y MongoDB. Además de las configuraciones que se explican a continuación, se pueden observar más configuraciones comentadas que el usuario puede explorar y modificar.

### 2.1 Input Mosquitto

En esta configuración hay que definir el server donde se encuentra Mosquitto, que es el nombre del contenedor en el docker-compose.yml (mqtt5).

También es necesario definir los topics a los que se subscribe, el usuario y contraseña creado anteriormente. Y el formato de los datos que va a recibir.

### 2.2 Output MongoDB
En este caso hay que definir la cadena de conexión a la base de datos, puede ser una base de datos en local o en la nube. También hay que definir usuario y contraseña para poder almacenar la información en la base de datos. Y por último se debe establecer una base de datos en la que se almacenarán estos.



