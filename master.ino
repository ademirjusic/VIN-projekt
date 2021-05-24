#include <Wire.h>

// master sender

const int BLUE_LED = 13;
const int YELLOW_LED = 12;
const int ORANGE_LED = 11;
const int RED_LED = 10;
const int BUZZER = 7;

byte cm;
int cmInt;
int d;


void setup()
{
  Serial.begin(9600);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(YELLOW_LED , OUTPUT);
  pinMode(ORANGE_LED , OUTPUT);
  pinMode(RED_LED , OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop()
{
  d = 255;
  cmInt = 0.01723 * readDistance(9, 8);
  cm = 0.01723 * readDistance(9, 8);
  
  // Transfer data
  if (cmInt < 256)			// 'cm < 256' cause ... byte
  {
    Serial.print("distance: ");
    Serial.println(cm); 
  
    Wire.beginTransmission(4);         // transmit to device #4
    Wire.write("distance is ");        // sends 12 bytes
    Wire.write(cm);              	// sends one byte  
    Wire.endTransmission();    	// stop transmitting
  }
  
  // Shut every LED OFF
  if (cmInt > d)
  {
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(RED_LED, LOW);
  }
  
  // BLUE LED AND NO BEEP
  if (cmInt <= d  && cmInt > d / 2)
  {
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(RED_LED, LOW); 
  }
  
  // YELLOW LED AND FIRST BEEP
  if (cmInt <= d / 2 && cmInt > d / 4)
  {
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(RED_LED, LOW); 
    playTone(500);
  }
  
  // ORANGE LED AND SECOND BEEP
  if (cmInt <= d / 4 && cmInt > 25)
  {
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(ORANGE_LED, HIGH);
    digitalWrite(RED_LED, LOW); 
    playTone(150);
  }
  
  // RED LED AND FINAL BEEP
  if (cmInt <= 25 && cm != 0)             // 'cm != 0' because readDistance()
  {					   // returns 0, when there is no obstacle.
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    tone(BUZZER, 500);
  }
 
  delay(500);
}

long readDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

void playTone(int pause) 
{
  tone(BUZZER, 500, 100);
  delay(pause);
}
