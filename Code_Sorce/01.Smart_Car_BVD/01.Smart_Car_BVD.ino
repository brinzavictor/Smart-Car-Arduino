/* Includes --------------------------------------------*/
#include "Arduino.h"
#include "PCF8574.h"

/* Define ----------------------------------------------*/
/* DC Motors pins */
#define M_LEFT_F D5
#define M_LEFT_B D6
#define M_RIGHT_F D7
#define M_RIGHT_B D8
#define CORRECTION_SPEED 20
#define TURN_COEFFICIENT 60

/* Setup -----------------------------------------------*/
/* Set i2c address */
PCF8574 pcf8574(0x39);

/*********************************************************/
/** Init ------------------------------------------------*/
/*********************************************************/
void setup() 
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

/*********************************************************/
/** Loop ------------------------------------------------*/
/*********************************************************/
void loop() 
{
    /* Ex I2C Pins
    pcf8574.digitalWrite(P0, HIGH);
    */
}

void go(byte direction, unsigned short speed)
{
    switch(direction)
    {
         case 0:
        {
            // Standby
            digitalWrite(M_LEFT_F, LOW);
            digitalWrite(M_LEFT_B, LOW);
            digitalWrite(M_RIGHT_F, LOW);
            digitalWrite(M_RIGHT_B, LOW);
                     
        }
        break;
        
        case 1:
        {         
            // STOP
            digitalWrite(M_LEFT_F, HIGH);
            digitalWrite(M_LEFT_B, HIGH);
            digitalWrite(M_RIGHT_F, HIGH);
            digitalWrite(M_RIGHT_B, HIGH);           
        }
        break;

        case 2:
        {
            // In fata la viteza
            analogWrite(M_LEFT_F, speed - CORRECTION_SPEED);
            digitalWrite(M_LEFT_B, LOW);
            analogWrite(M_RIGHT_F, speed);
            digitalWrite(M_RIGHT_B, LOW);      
        }
        break;

        case 3:
        {
            // In spate la viteza
            digitalWrite(M_LEFT_F, LOW);
            analogWrite(M_LEFT_B, speed - CORRECTION_SPEED);
            digitalWrite(M_RIGHT_F, LOW);
            analogWrite(M_RIGHT_B, speed);         
        }
        break;

        case 4:
        {
              // Rotire Stanga
            digitalWrite(M_LEFT_F, LOW);
            digitalWrite(M_LEFT_B, HIGH);
            digitalWrite(M_RIGHT_F, HIGH);
            digitalWrite(M_RIGHT_B, LOW);         
        }
        break;
        
        case 5:
        {
            // Rotire Dreapta
            digitalWrite(M_LEFT_F, HIGH);
            digitalWrite(M_LEFT_B, LOW);
            digitalWrite(M_RIGHT_F, LOW);
            digitalWrite(M_RIGHT_B, HIGH);  
                       
        }
        break;

        case 6:
        {
            // Vireaza stanga
            analogWrite(M_LEFT_F, speed - TURN_COEFFICIENT);
            digitalWrite(M_LEFT_B, LOW);
            analogWrite(M_RIGHT_F, speed);
            digitalWrite(M_RIGHT_B, LOW);
        }
        break;

        case 7:
        {
            //Vireaza dreapta
            analogWrite(M_LEFT_F, speed);
            digitalWrite(M_LEFT_B, LOW);
            analogWrite(M_RIGHT_F, speed - TURN_COEFFICIENT);
            digitalWrite(M_RIGHT_B, LOW);          
        }
        break;
    }
}
