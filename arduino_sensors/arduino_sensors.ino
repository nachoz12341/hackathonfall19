#include <OneWire.h>
#include <DallasTemperature.h>
// Data wire is plugged into port 2 on the Arduino
#define ONE_WIRE_BUS A0
// Setup a oneWire instance to communicate with any OneWire devices (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);

int trigPin = 11;    // Trigger
int echoPin = 12;    // Echo
long duration, cm, inches;

void setup(void)
{
// start serial port
Serial.begin(9600);
Serial.println("Dallas Temperature IC Control Library Demo");
// Start up the library
sensors.begin();

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}
void loop(void)
{
// The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  Serial.println("0");
  Serial.println(inches);


 delay(500);
  
// call sensors.requestTemperatures() to issue a global temperature
// request to all devices on the bus
//Serial.print("Requesting temperatures...");
sensors.requestTemperatures(); // Send the command to get temperatures
//Serial.println("DONE");
//Serial.print("Temperature for the device 1 (index 0) is: ");
Serial.println("1");
Serial.println(sensors.getTempFByIndex(0)); //print the temperature on serial monitor
delay(500);
}
