/*
 * Tutorial 8: Using the LCD
 * 
 * Demonstrates the use a 16x2 LCD display.  The LiquidCrystal
 * library works with all LCD displays that are compatible with the 
 * Hitachi HD44780 driver. There are many of them out there, and you
 * can usually tell them by the 16-pin interface.
 *
 * Adjust the LCDs contrast with the Potentiometer until you
 * can see the characters on the LCD.
 *
 * The circuit:
 * - LCD RS pin to digital pin 12
 * - LCD Enable pin to digital pin 11
 * - LCD D4 pin to digital pin 5
 * - LCD D5 pin to digital pin 4
 * - LCD D6 pin to digital pin 3
 * - LCD D7 pin to digital pin 2
 * - LCD R/W pin to ground
 * - 10K potentiometer divider for LCD pin VO:
 * - 330ohm resistor betweenm LCD pin A and 5v
 * - LCD pin K to ground
 *
 * Library originally added 18 Apr 2008
 * by David A. Mellis
 * library modified 5 Jul 2009
 * by Limor Fried (http://www.ladyada.net)
 * example added 9 Jul 2009
 * by Tom Igoe
 * modified 22 Nov 2010
 * by Tom Igoe
 * modified 14 August 2013
 * by Blaise Jarrett
 *
 * This example code is in the public domain.
 *
 * Derivative work from:
 * http://www.arduino.cc/en/Tutorial/LiquidCrystal
 *
 */

// include the library
#include <LiquidCrystal.h>

// all of our LCD pins
int lcdRSPin = 12;
int lcdEPin = 11;

int lcdD0Pin = 5;
int lcdD1Pin = 4;
int lcdD2Pin = 3;
int lcdD3Pin = 2;

int clickerPin = 8;
int menuPin = 9;

//States
int count = 0;
int previousState = HIGH;

//Low == 0 == button down
//High == 1 == button up


// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(lcdRSPin, lcdEPin,
                  lcdD0Pin, lcdD1Pin, lcdD2Pin, lcdD3Pin);

void setup()
{
    Serial.begin(9600);
    // set up the LCD's number of columns and rows: 
    lcd.begin(16, 2);

    // Print a message to the LCD.
    lcd.print("Cookies");
    pinMode(clickerPin, INPUT_PULLUP);
}

void loop()
{
  int clickerValue = digitalRead(clickerPin);

  if(clickerValue == LOW && previousState == HIGH)
  {
    Serial.println(previousState);
    previousState = LOW;
    count++;
    Serial.println(previousState);
  }
  else if(clickerValue == HIGH && previousState == LOW) {
    previousState = HIGH;
  } 

  //Figure out a "print screen" function that lets me choose what text I want displayed based on the number I pass in. Make "menu" button cycle that number

  lcd.setCursor(0, 1);
  lcd.print(count);
}
