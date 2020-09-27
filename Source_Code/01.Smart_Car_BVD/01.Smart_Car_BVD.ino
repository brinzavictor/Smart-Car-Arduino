/* Includes --------------------------------------------*/
/* Libraris */
#include <Arduino.h>
#include <PCF8574.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Headers */
//#include "index.h"

/* Define ----------------------------------------------*/
/* DC Motors */
#define M_LEFT_F D5
#define M_LEFT_B D6
#define M_RIGHT_F D7
#define M_RIGHT_B D8
#define CORRECTION_SPEED 20
#define TURN_COEFFICIENT 60

/* Setup -----------------------------------------------*/
/* Set i2c address */
PCF8574 pcf8574(0x39);

/* Set WiFi user & password */
const char* ssid = "iancu-wifi";
const char* password = "bglnpbcr1";

/* Set port 80 for server */
ESP8266WebServer server(80);

/*********************************************************/
/** Init ------------------------------------------------*/
/*********************************************************/
void setup() 
{
    Serial.begin(9600);
    setup_pins();
    connect_WiFi();
}

/*********************************************************/
/** Loop ------------------------------------------------*/
/*********************************************************/
void loop() 
{
    /* Ex I2C Pins
    pcf8574.digitalWrite(P0, HIGH);
    */
}

/*********************************************************/
/** Functions -------------------------------------------*/
/*********************************************************/
void go(byte direction, unsigned short speed)
{
    switch(direction)
    {
         case 0:
        {
            /* Standby */
            digitalWrite(M_LEFT_F, LOW);
            digitalWrite(M_LEFT_B, LOW);
            digitalWrite(M_RIGHT_F, LOW);
            digitalWrite(M_RIGHT_B, LOW);
        }
        break;
        case 1:
        {         
            /* STOP */
            digitalWrite(M_LEFT_F, HIGH);
            digitalWrite(M_LEFT_B, HIGH);
            digitalWrite(M_RIGHT_F, HIGH);
            digitalWrite(M_RIGHT_B, HIGH);           
        }
        break;
        case 2:
        {
            /* Ahead */
            analogWrite(M_LEFT_F, speed - CORRECTION_SPEED);
            digitalWrite(M_LEFT_B, LOW);
            analogWrite(M_RIGHT_F, speed);
            digitalWrite(M_RIGHT_B, LOW);      
        }
        break;
        case 3:
        {
            /* Back */
            digitalWrite(M_LEFT_F, LOW);
            analogWrite(M_LEFT_B, speed - CORRECTION_SPEED);
            digitalWrite(M_RIGHT_F, LOW);
            analogWrite(M_RIGHT_B, speed);         
        }
        break;
        case 4:
        {
            /* Spin Left */
            digitalWrite(M_LEFT_F, LOW);
            digitalWrite(M_LEFT_B, HIGH);
            digitalWrite(M_RIGHT_F, HIGH);
            digitalWrite(M_RIGHT_B, LOW);         
        }
        break;        
        case 5:
        {
            /* Spin Right */
            digitalWrite(M_LEFT_F, HIGH);
            digitalWrite(M_LEFT_B, LOW);
            digitalWrite(M_RIGHT_F, LOW);
            digitalWrite(M_RIGHT_B, HIGH);
        }
        break;
        case 6:
        {
            /* Turn Left */
            analogWrite(M_LEFT_F, speed - TURN_COEFFICIENT);
            digitalWrite(M_LEFT_B, LOW);
            analogWrite(M_RIGHT_F, speed);
            digitalWrite(M_RIGHT_B, LOW);
        }
        break;
        case 7:
        {
            /* Turn Right */
            analogWrite(M_LEFT_F, speed);
            digitalWrite(M_LEFT_B, LOW);
            analogWrite(M_RIGHT_F, speed - TURN_COEFFICIENT);
            digitalWrite(M_RIGHT_B, LOW);          
        }
        break;
        default:
        break;
    }
}

void setup_pins()
{
    /* Set DC Motors Pins */
    pinMode(M_LEFT_F, OUTPUT);
    pinMode(M_LEFT_B, OUTPUT);
    pinMode(M_RIGHT_F, OUTPUT);
    pinMode(M_RIGHT_B, OUTPUT);

    /* Set Pins I/O I2C */
    pcf8574.pinMode(P0, OUTPUT);
    pcf8574.pinMode(P1, INPUT);
    pcf8574.begin();
}

void connect_WiFi()
{
    WiFi.begin(ssid, password);
    Serial.println("");
    Serial.print("Connecting... ");
    while(WiFi.status() != WL_CONNECTED )
    {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");

    if( WiFi.status() == WL_CONNECTED)
    {
        Serial.println("WiFi Connected");
        Serial.print("IP Adress: ");
        Serial.println(WiFi.localIP());

        server.begin();
        Serial.println("Server is ON");
    }
    else
    {
        Serial.println("ERROR!");
    }
}
