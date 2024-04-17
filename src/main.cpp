// #include <Arduino.h>
// #include "LogLibrary.h"

// const char *ssid = "Orange-E475";
// const char *password = "3mcUAJZC";
// const char *mqttServer = "192.168.1.117";

// // const char *ssid = "DIGIFIBRA-HdQF";
// // const char *password = "4FXX5tAc37bA";
// // const char *mqttServer = "192.168.1.131";
// const int mqttPort = 1883;
// const char *mqttTopic = "logStatus";
// const char *idBoard = "PlacaXD";
// const char *timeZone = "CET-1CEST-2,M3.5.0/02:00:00,M10.5.0/03:00:00"; // https://remotemonitoringsystems.ca/time-zone-abbreviations.php
// const char *ntpServer = "pool.ntp.org";                                // https://www.ntppool.org/es/zone/es
// const char *logFormat = "{level}-{message}-{timestamp}-{idSender}";
// Logger logger;

// void funcionalidadUsuario();

// void setup()
// {
//     Serial.begin(9600);
//     logger.init(ssid, password, mqttServer, mqttPort);
//     // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic);
//     // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic, idBoard);
//     // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic, idBoard, timeZone);
//     // logger.init(ssid, password, mqttServer, mqttPort, mqttTopic, idBoard, timeZone, ntpServer);
// }

// void loop()
// {
//     // Generar un número aleatorio entre 0 y 8
//     int numeroAleatorio = random(0, 4);
//     // FUNCIONALIDAD DEL USUARIO
//     funcionalidadUsuario();

//     switch (numeroAleatorio)
//     {
//     // EL USUARIO DECIDE CUANDO LLAMAR AL METODO DE LOG
//     case 0:
//         Serial.print("INFO");

//         logger.logINFO("Mensaje de info!");
//         break;
//     case 1:
//         Serial.print("WARNING");

//         logger.logWARNING("Mensaje de warning!");
//         break;
//     case 2:
//         Serial.print("ERROR");

//         logger.logERROR("Mensaje de error!");
//         break;
//     case 3:
//         Serial.print("CRITICO");

//         logger.logCRITICO("Mensaje crítico!");
//         break;
//     default:
//         break;
//     }
// }

// void funcionalidadUsuario()
// {
//     // Funcion cualquiera de la placa del usuario
//     // No se debe interrumpir su funcionamiento
//     Serial.println(" ");
//     delay(500);
// }

#include <Arduino.h>
#include "LogLibrary.h"

const char *ssid = "Orange-E475";
const char *password = "3mcUAJZC";
const char *mqttServer = "192.168.1.117";
const int mqttPort = 1883;

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

    logger.init(ssid, password, mqttServer, mqttPort, mqttTopic, idBoard, timeZone, ntpServer);
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
