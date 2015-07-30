
/*LCD Displays (Blue and YELLOW) with I2C/TWI Interface
YwRobotLCD-4x20-400.jpg
IMPORTANT LCD Software Library Info:
ALL the displays will now use the great Library written by F Malpartida . You should download that Library HERE (Click)
If you try to Verify and you see this:
error: 'LiquidCrystal_I2C' does not name a type
...this means you do not have the library installed correctly. See:
How-To-Install-Libraries
NOTE!! Move any other LCD libraries to another folder,or rename or delete them.


NOTE! THERE ARE THREE (or More??) VERSIONS OF THE 2 and 4 LINE DISPLAYS. Check the small "backpack" interface board on the back.

LCD Version 1 - Marked "YwRobot Arduino LCM1602 IIC V1"
LCD Version 2 - Marked "Arduino-IIC-LCD GY-LCD-V1"
LCD Version 3 - Marked "LCM1602 IIC A0 A1 A2"

These displays are Available HERE:
NOTE! These displays are very clear bright white on dark blue (or Black on Yellow) background: it is difficult to get a good digital photo due to polarization effects.

WHY THE I2C (IIC) TYPE LCD DISPLAY?
To use this type LCD directly with Arduino, you would need 6 pins: RS, EN, D7, D6, D5, and D4 to talk to the LCD. If you are doing more than a simple project, you may be out of pins using a normal LCD shield. With this I2C interface LCD module, you only need 2 lines (I2C) to display information. If you already have I2C devices in your project, this LCD module actually uses no more pins at all. More information about I2C/TWI (Wikipedia)
This unit connects with 4 wires including Vcc and Gnd. It is easiest with a 4-wire cable (supplied) that plugs into the Sensor Shield communications connector.

But you can wire it directly yourself if needed: There are 4 pins on the display.. (see photo below)
external image 4-pinCable-Pinout-500.jpg
YwRobotLCD-CU-450.jpg
Top to bottom:
GND - GND
VCC - 5V
SDA - ANALOG Pin 4
SCL - ANALOG pin 5
On most Arduino boards, SDA (data line) is on analog input pin 4, and SCL (clock line) is on analog input pin 5. On the Arduino Mega, SDA is digital pin 20 and SCL is 21.
NOTE: The Blue Potentiometer (Photo) adjusts Contrast. If you don't see any characters, adjust it. Start clockwise and back down to where the characters are bright and the background does not have boxes behind the characters.

See a LCD used in the Temperature-Humidity project.

LiquidCrystal_I2C Library Support Functions
See the "Docs" folder within the Library folder. There are many advanced functions.

Below are Example Software Sketches for different displays. They will display characters you type on the Serial Monitor screen on the LCD. NOTE: Line 1 only is correct when writing a long sequence of characters. The characters fill the first line and continue on the third, due to the way the LCD internal addressing works. So this is "normal" and has to do with the LCD hardware. Usually you will set the cursor position before writing characters. (Details in the document linked at the end of this page, if you want them.)
(Cut and paste these examples into a blank page on the Arduino IDE).


I2C LCD DISPLAY VERSION 1:
Example Software Sketch for 2 line 16 character Displays:
(NOTE: for displays with backpack interface labelled "YwRobot Arduino LCM1602 IIC V1")

/* YourDuino.com Example Software Sketch
 16 character 2 line I2C Display
 Backpack Interface labelled "YwRobot Arduino LCM1602 IIC V1"
 terry@yourduino.com */

/*-----( Import needed libraries )-----*/
#include <Wire.h>  // Comes with Arduino IDE
// Get the LCD I2C Library here: 
// https://bitbucket.org/fmalpartida/new-liquidcrystal/downloads
// Move any other LCD libraries to another folder or delete them
// See Library "Docs" folder for possible commands etc.
#include <LiquidCrystal_I2C.h>

/*-----( Declare Constants )-----*/
/*-----( Declare objects )-----*/
// set the LCD address to 0x27 for a 20 chars 4 line display
// Set the pins on the I2C chip used for LCD connections:
//                    addr, en,rw,rs,d4,d5,d6,d7,bl,blpol
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // Set the LCD I2C address

/*-----( Declare Variables )-----*/
//NONE

void setup()   /*----( SETUP: RUNS ONCE )----*/
{
  Serial.begin(9600);  // Used to type in characters

  lcd.begin(16,2);   // initialize the lcd for 16 chars 2 lines, turn on backlight

// ------- Quick 3 blinks of backlight  -------------
  for(int i = 0; i< 3; i++)
  {
    lcd.backlight();
    delay(250);
    lcd.noBacklight();
    delay(250);
  }
  lcd.backlight(); // finish with backlight on  

//-------- Write characters on the display ------------------
// NOTE: Cursor Position: (CHAR, LINE) start at 0  
  lcd.setCursor(0,0); //Start at character 4 on line 0
  lcd.print("Hello, world!");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("HI!YourDuino.com");
  delay(8000);  

// Wait and then tell user they can start the Serial Monitor and type in characters to
// Display. (Set Serial Monitor option to "No Line Ending")
  lcd.clear();
  lcd.setCursor(0,0); //Start at character 0 on line 0
  lcd.print("Use Serial Mon");
  lcd.setCursor(0,1);
  lcd.print("Type to display");  


}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  {
    // when characters arrive over the serial port...
    if (Serial.available()) {
      // wait a bit for the entire message to arrive
      delay(100);
      // clear the screen
      lcd.clear();
      // read all the available characters
      while (Serial.available() > 0) {
        // display each character to the LCD
        lcd.write(Serial.read());
      }
    }
  }

}/* --(end main loop )-- */


/* ( THE END ) */


