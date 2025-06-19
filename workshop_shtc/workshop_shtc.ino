#include "SHTC3-SOLDERED.h"

// === USER-CONFIGURABLE TEMPERATURE RANGE ===
const float tempMin = 15.0;  // Minimum temperature expected
const float tempMax = 30.0;  // Maximum temperature expected
// ===========================================

SHTC3 shtcSensor;
int oldMidiValue = -1;

void setup()
{
    Serial.begin(115200); // Use 31250 for real MIDI hardware
    shtcSensor.begin();   // Initialize the sensor
}

void loop()
{
    shtcSensor.sample();  // Trigger a sample

    float temp = shtcSensor.readTempC();

    // Clamp temperature
    temp = constrain(temp, tempMin, tempMax);

    // Map temperature to MIDI range (0–127)
    int midiValue = map(temp * 100, tempMin * 100, tempMax * 100, 0, 127);

    // Send only if changed
    if (midiValue != oldMidiValue)
    {
        controlChange(1, 74, midiValue); // CC 74 (often used for filter cutoff)
        oldMidiValue = midiValue;
    }

    delay(100); // Debounce
}

void controlChange(int channel, int controllerNumber, int controlValue)
{
    int statusByte = 0xB0 | (channel - 1);
    Serial.write(statusByte);
    Serial.write(controllerNumber);
    Serial.write(controlValue);
}
