#include <Wire.h>
#include <LiquidCrystal.h>

// reciever

// DB4 to pin 9
// DB5 to pin 8
// DB6 to pin 7
// DB5 to pin 6

// Register select to pin 12
// Enable to pin 11

// RW to ground


LiquidCrystal lcd(12, 11, 9, 8, 7, 6);

void setup()
{
  lcd.begin(16, 2);
  
  lcd.print("Distance in cm: "); // Print a message to the LCD.
  
  Wire.begin(4);                 // join i2c bus with address #4
  Wire.onReceive(receiveEvent);  // register event
  Serial.begin(9600);            // start serial for outpu
}

void loop()
{
  lcd.setCursor(0, 1);
  
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany)
{
  while(1 < Wire.available()) // loop through all but the last
  {
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }
  int x = Wire.read();    // receive byte as an integer
  lcd.print(x);
  Serial.println(x);         // print the integer
}

