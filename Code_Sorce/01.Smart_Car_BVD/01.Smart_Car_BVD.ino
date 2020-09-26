/* Includes --------------------------------------------*/
#include "Arduino.h"
#include "PCF8574.h"

/* Define ----------------------------------------------*/
/* DC Motors pins */
#define M_STANGA_F D5
#define M_STANGA_B D6
#define M_DREAPTA_F D7
#define M_DREAPTA_B D8

/* Setup -----------------------------------------------*/
/* Set i2c address */
PCF8574 pcf8574(0x39);

/*********************************************************/
/** Init ------------------------------------------------*/
/*********************************************************/
void setup() 
{
    /* Set DC Motors Pins */
    pinMode(M_STANGA_F, OUTPUT);
    pinMode(M_STANGA_B, OUTPUT);
    pinMode(M_DREAPTA_F, OUTPUT);
    pinMode(M_DREAPTA_B, OUTPUT);

    /* Set Pins I/O I2C */
    pcf8574.pinMode(P0, OUTPUT);
    pcf8574.pinMode(P1, INPUT);
    pcf8574.begin();
}

/*********************************************************/
/** Loop ------------------------------------------------*/
/*********************************************************/
void loop() 
{
    /* Ex I2C Pins
    pcf8574.digitalWrite(P0, HIGH);
    */
    analogWrite(M_DREAPTA_F, 1023);
    analogWrite(M_STANGA_F, 1023);
    delay(5000);
    analogWrite(M_DREAPTA_F, 0);
    analogWrite(M_STANGA_F, 0);
    delay(5000);
}
