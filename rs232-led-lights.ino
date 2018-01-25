/*
========================================================================================================================================
RS232 LED Lights
========================================================================================================================================
This project deals with LED Lights which is controlled by GPIO at pins 3, 4, and 5. It uses the RS232 to control the LEDs.
@package        RS232 LED Lights
@copyright      Copyright (C) 2018. Benjamin Lu
@license        GNU General Public License v2 or later (http://www.gnu.org/licenses/gpl-2.0.html)
@author         Benjamin Lu (https://www.benjlu.com/)
========================================================================================================================================
*/

/*
========================================================================================================================================
Table of Content
========================================================================================================================================
 1.0 - Required Files
 2.0 - Variables
 3.0 - Setup
 4.0 - Loop
 5.0 - redLED Checkbox
 6.0 - yellowLED Checkbox
 7.0 - greenLED Checkbox
========================================================================================================================================
*/

/*
========================================================================================================================================
 1.0 - Required Files
========================================================================================================================================
*/

/*
========================================================================================================================================
 2.0 - Variables
========================================================================================================================================
*/
int redLED = 3;
int yellowLED = 4;
int greenLED = 5;

int ledStatus;

int off_on;

/*
========================================================================================================================================
 3.0 - Setup
========================================================================================================================================
*/
void setup() {
  // put your setup code here, to run once:
  Serial232.begin(9600);

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
}

/*
========================================================================================================================================
 4.0 - Loop
========================================================================================================================================
*/
void loop() {
  delay(1000);
  Serial232.println("Enter 1 = Red LED, 2 = Yellow LED, 3 = Green LED");

  while (Serial232.available() == 0) {
    // Wait for Input
  }
  ledStatus = Serial232.parseInt();
  Serial232.print("You have selected: ");
  Serial232.println(ledStatus);
  Serial232.println();
  Serial232.println("Enter LED On = 1 or LED Off = 0");
  while (Serial232.available() == 0) {
    // Wait for Input
  }
  off_on = Serial232.parseInt();
  Serial232.println();
  
  switch (ledStatus) {
    case 1:
       if (off_on == 1) {
        digitalWrite(redLED, HIGH);
        Serial232.println("The Red LED has turn On.");
       } else if (off_on == 0) {
        digitalWrite(redLED, LOW);
        Serial232.println("The Red LED has turn Off.");      
       }
       break;

    case 2:
       if (off_on == 1) {
        digitalWrite(yellowLED, HIGH);
        Serial232.println("The Yellow LED has turn On.");
       } else if (off_on == 0) {
        digitalWrite(yellowLED, LOW);
        Serial232.println("The Yellow LED has turn Off.");      
       }
       break;

    case 3:
       if (off_on == 1) {
        digitalWrite(greenLED, HIGH);
        Serial232.println("The Green LED has turn On.");
       } else if (off_on == 0) {
        digitalWrite(greenLED, LOW);
        Serial232.println("The Green LED has turn Off.");      
       }
       break;
  }
  Serial232.println();
}
