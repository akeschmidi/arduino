
#include <Wire.h> 
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <OneWire.h>
#include <DallasTemperature.h>

// Data wire is conntec to the Arduino digital pin 2
#define ONE_WIRE_BUS 2
// Setup a oneWire instance to communicate with any OneWire devices
OneWire oneWire(ONE_WIRE_BUS);

// Pass our oneWire reference to Dallas Temperature sensor 
DallasTemperature sensors(&oneWire);
Adafruit_7segment matrix = Adafruit_7segment();

void setup(void)
{
  // Start serial communication for debugging purposes
  Serial.begin(9600);
  
  // Start up the library
  sensors.begin();

  #ifndef __AVR_ATtiny85__
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
  #endif
  matrix.begin(0x70);
  
}


void loop(void){ 


  sensors.requestTemperatures(); 
  
  //Serial.print("Sensor 1 Celsius-Temperatur: ");
  //Serial.println(sensors.getTempCByIndex(0)); 

  
  matrix.print(sensors.getTempCByIndex(0));
  matrix.writeDisplay();
  delay(5000);
 
}
