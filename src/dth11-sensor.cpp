/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/alvarosaburido/as/electronics/electronics-lab/Particle/dth11-sensor/src/dth11-sensor.ino"
/*
 * Project dth11-sensor
 * Description:
 * Author: Alvaro Saburido
 * Date: 13/04/2020
 */

void printSerial();
void setup();
void loop();
#line 8 "/Users/alvarosaburido/as/electronics/electronics-lab/Particle/dth11-sensor/src/dth11-sensor.ino"
#define BLYNK_PRINT Serial
#include <blynk.h>
#define ARDUINO 0
#include "DHT.h"

#define DHTPIN 4
#define DHTTYPE DHT11

#define BLYNK_TEMP_DISPLAY V1
#define BLYNK_HUMIDITY_DISPLAY V2

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "jUOUzcLpjsuVOaroXl2wsQQkRrGh-I8o";
float temp;
float humidity;
DHT dht(DHTPIN, DHTTYPE);

BLYNK_READ(BLYNK_TEMP_DISPLAY)
{
  // This command writes Arduino's uptime in seconds to Virtual Pin (5)
  Blynk.virtualWrite(BLYNK_TEMP_DISPLAY, temp);
}

BLYNK_READ(BLYNK_HUMIDITY_DISPLAY)
{
  // This command writes Arduino's uptime in seconds to Virtual Pin (5)
  Blynk.virtualWrite(BLYNK_HUMIDITY_DISPLAY, humidity);
}

void printSerial() {
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" *C ");
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  delay(5000); // Allow board to settle
  Blynk.begin(auth);
}

void loop()
{

  humidity = dht.readHumidity();
  temp = dht.readTemperature();
  printSerial();

  Blynk.run();
}
