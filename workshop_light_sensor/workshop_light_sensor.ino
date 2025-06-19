// Include needed libraries
#include "LTR-507-Light-And-Proximity-Sensor-SOLDERED.h"

// Create sensor object
LTR507 sensor;

int oldMidiValue = 0;

void setup()
{
    Serial.begin(115200);

    // Initialize the sensor!
    sensor.init();
}

void loop()
{
    // Make local variable for reading the light value
    uint16_t lightReading;

    // Make reading!
    lightReading = sensor.getLightIntensity();

    lightReading = constrain(lightReading, 0, 600); // Clamp input range

    // Map reading
    int lightValue127 = map(lightReading, 0, 600, 0, 127);
    if (lightValue127 != oldMidiValue)
    {
        controlChange(1, 1, lightValue127);
        oldMidiValue = lightValue127;
    }

    delay(100);
}

void controlChange(int channel, int controllerNumber, int controlValue)
{
  // Calculate the status byte based on the provided channel.
  int statusByte = 0xB0 | (channel - 1);

  // Send the control change message
  Serial.write(statusByte);
  Serial.write(controllerNumber);
  Serial.write(controlValue);
}