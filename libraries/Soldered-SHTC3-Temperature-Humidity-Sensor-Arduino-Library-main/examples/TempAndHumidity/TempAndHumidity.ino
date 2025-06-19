/**
 **************************************************
 *
 * @file        TempAndHumidity.ino
 * @brief       Example file for using SHTC3 sensor with easyC/i2c
 *
 *
 *
 * @authors     @ soldered.com www.solde.red/333032
 ***************************************************/

#include "SHTC3-SOLDERED.h"

SHTC3 shtcSensor;

void setup()
{
    shtcSensor.begin(); //Initialize sensor
    Serial.begin(115200); //Start serial communication with PC using 115200 baudrate
}

void loop()
{
    shtcSensor.sample(); //Initialize sensor

    // For temperature use function readTempC
    Serial.print("Temp: ");
    Serial.println(shtcSensor.readTempC(), 2); //Get temperature and print

    // For geting humidity use function readHumidity
    Serial.print("Hum: ");
    Serial.println(shtcSensor.readHumidity(), 2); //Get humidity and print

    delay(5000);
}
