// #include <Arduino.h>
// #include "LogLibrary.h"

// const char *ssid = "Orange-E475";
// const char *password = "3mcUAJZC";
// const char *mqttServer = "192.168.1.117";
// const int mqttPort = 1883;
// const char *mqttUser = "user";
// const char *mqttPassword = "user1";
// const char *mqttTopic = "mqttTopic";
// const char *idBoard = "idBoard";

// // Change TimeZone https://remotemonitoringsystems.ca/time-zone-abbreviations.php
// // Default timezone is Madrid
// // const char *timeZone = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";

// // Change ntpServer https://www.ntppool.org/es/zone/es
// // Default ntpServer is pool.ntp.org
// // const char *ntpServer = "pool.ntp.org";

// // Change log format optionally
// // Default format: "{level}-{message}-{idSender}-{topic}-{timestamp}"
// // const char *logFormat2 = "{message} - {timestamp} - {idSender}";
// // const char *logFormat1 = "{level} - {message}";
// // const char *logFormat3 = "{level} - {message} - {idSender}";

// Logger logger;

// void userFunctionality();

// void setup()
// {
//     Serial.begin(9600);

//     // Set log format
//     // logger.setLogFormat(logFormat2);
//     // logger.setLogFormat(logFormat3);
//     // logger.setLogFormat(logFormat4);

//     // Send logs to MQTT in order to be stored in a database
//     // logger.sendToMQTT(mqttUser, mqttPassword);

//     // Initialize logger with different configurations
//     logger.init(ssid, password, mqttServer, mqttPort);
//     // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic);
//     // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic, idBoard);
//     // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic, idBoard, timeZone);
//     // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic, idBoard, timeZone, ntpServer);
// }

// void loop()
// {
//     // Random number between 0 and 25
//     int number = random(0, 26);

//     // User functionality
//     userFunctionality();

//     if (number >= 0 && number <= 5)
//     {
//         logger.logDEBUG("Debug in the user's board");
//     }
//     else if (number >= 6 && number <= 10)
//     {
//         logger.logWARNING("Warning in the user's board");
//     }
//     else if (number >= 11 && number <= 15)
//     {
//         logger.logERROR("Error in the user's board");
//     }
//     else if (number >= 16 && number <= 20)
//     {
//         logger.logINFO("Information in the user's board");
//     }
//     else if (number >= 21 && number <= 25)
//     {
//         logger.logCRITICAL("Critical in the user's board");
//     }
// }

// void userFunctionality()
// {
//     // Functionality of the user's board
//     // Its operation should not be interrupted
//     Serial.println("User functionality running...");
//     delay(500);
// }

#include <Arduino.h>
#include "LogLibrary.h"

const char *ssid = "Orange-E475";
const char *password = "3mcUAJZC";
const char *mqttServer = "192.168.1.117";
const int mqttPort = 1883;
const char *mqttUser = "user";
const char *mqttPassword = "user1";

const char *mqttTopic = "logStatus";
const char *idBoard = "PlacaXD";

// Cambiar TimeZone https://remotemonitoringsystems.ca/time-zone-abbreviations.php
// Por defecto se usa la zona horaria de Madrid
const char *timeZone = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00";

// Cambiar ntpServer https://www.ntppool.org/es/zone/es
// Por defecto se usa el servidor NTP de pool.ntp.org
const char *ntpServer = "pool.ntp.org";

// Cambiar el formato del log opcionalmente
// Si no se cambia el formato, se usará el formato por defecto que es:
// "{level}-{message}-{timestamp}-{idSender}"
const char *logFormat1;
const char *logFormat2 = "{message} - {timestamp} - {idSender} -";
const char *logFormat3 = "{level} - {message} - {idSender} -";

Logger logger;

void funcionalidadUsuario();

void setup()
{
    Serial.begin(9600);

    // Cambiar el formato del log opcionalmente
    logger.setLogFormat(logFormat1);
    // logger.setLogFormat(logFormat2);
    // logger.setLogFormat(logFormat3);

    // Para enviar los logs a MQTT y almacenarlos en una base de datos
    logger.sendToMQTT(mqttUser, mqttPassword);

    // Inicializar el logger con diferentes configuraciones
    logger.init(ssid, password, mqttServer, mqttPort);
    // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic);
    // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic, idBoard);
    // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic, idBoard, timeZone);
    // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic, idBoard, timeZone, ntpServer);
}

void loop()
{

    int numeroAleatorio = random(0, 21);

    // Hacer un switch para cambiar el valor de mqttTopic e idBoard
    // según el valor de numeroAleatorio

    switch (numeroAleatorio)
    {
    case 0:
        logger.setBoardId("FASH");
        break;
    case 1:
        logger.setBoardId("SPACE");
        break;
    case 2:
        logger.setBoardId("URBAN");
        break;
    case 3:
        logger.setBoardId("VRART");
        break;
    case 4:
        logger.setBoardId("AIED");
        break;
    case 5:
        logger.setBoardId("CRYPTO");
        break;
    case 6:
        logger.setBoardId("lowcase letters idBoard");
        break;
    case 7:
        logger.setBoardId("ETHERS");
        break;
    case 8:
        logger.setBoardId("HARDBOARD");
        break;
    case 9:
        logger.setBoardId("KRATOS");
        break;
    case 10:
        logger.setBoardId("APHELION");
        break;
    case 11:
        logger.setBoardId("MARS");
        break;
    case 12:
        logger.setBoardId("BITCOIN");
        break;
    case 13:
        logger.setBoardId("MINER");
        break;
    case 14:
        logger.setBoardId("UCLM");
        break;
    case 15:
        logger.setBoardId("GAME-OF-THRONES");
        break;
    case 16:
        logger.setBoardId("MARVEL");
        break;
    case 17:
        logger.setBoardId("ECR");
        break;
    case 18:
        logger.setBoardId("MERN");
        break;
    case 19:
        logger.setBoardId("SON-GOKU");
        break;
    case 20:
        logger.setBoardId("HUNGER-GAMES");
        break;
    }

    numeroAleatorio = random(0, 10);
    switch (numeroAleatorio)
    {
    case 0:
        logger.setMqttTopic("Temperature");
        break;
    case 1:
        logger.setMqttTopic("CAPITAL LETTERS TOPIC");
        break;
    case 2:
        logger.setMqttTopic("ANOTHER TOPIC");
        break;
    case 3:
        logger.setMqttTopic("logStatus");
        break;
    case 4:
        logger.setMqttTopic("Topic 4");
        break;
    case 5:
        logger.setMqttTopic("THIS TOPIC IS VERY LONG BUT IT IS OKAY");
        break;
    case 6:
        logger.setMqttTopic("T");
        break;
    case 7:
        logger.setMqttTopic("S");
        break;
    case 8:
        logger.setMqttTopic("KAMEHAMEHA");
        break;
    case 9:
        logger.setMqttTopic("RASENGAN");
        break;
    }

    // Generar un número aleatorio entre 0 y 25
    numeroAleatorio = random(0, 26);

    // FUNCIONALIDAD DEL USUARIO
    funcionalidadUsuario();

    if (numeroAleatorio >= 0 && numeroAleatorio <= 5)
    {
        logger.logDEBUG("Debug en la placa del usuario");
    }
    else if (numeroAleatorio >= 6 && numeroAleatorio <= 10)
    {
        logger.logWARNING("Advertencia en la placa del usuario");
    }
    else if (numeroAleatorio >= 11 && numeroAleatorio <= 15)
    {
        logger.logERROR("Error en la placa del usuario");
    }
    else if (numeroAleatorio >= 16 && numeroAleatorio <= 20)
    {
        logger.logINFO("Placa del usuario funcionando correctamente");
    }
    else if (numeroAleatorio >= 21 && numeroAleatorio <= 25)
    {
        logger.logCRITICAL("Placa del usuario en estado crítico");
    }
}

void funcionalidadUsuario()
{
    // Funcion cualquiera de la placa del usuario
    // No se debe interrumpir su funcionamiento
    Serial.println("Funcionalidad del usuario");
    delay(500);
}
