#include "Simple-Soil-Sensor-SOLDERED.h" // Include the required library

// Create the sensor object
simpleSoilSensor soilSensor;

// Keep track of last sent value to avoid spamming
int oldMidiValue = -1;

void setup()
{
    Serial.begin(115200); // For MIDI over serial, keep this at 31250 for real MIDI output

    soilSensor.begin(); // Initialize the Soil Humidity Sensor

    // Optional configuration
    soilSensor.setThreshold(35.5);
    //soilSensor.calibrate(67.5);
    //soilSensor.invertLED(true);
}

void loop()
{
    // Read the moistness percentage (0.0–100.0)
    float moisture = soilSensor.getValue();

    // Clamp and map to MIDI range (0–127)
    moisture = constrain(moisture, 0.0, 100.0);
    int midiValue = map(moisture, 0, 100, 0, 127);

    // Only send if value has changed
    if (midiValue != oldMidiValue)
    {
        controlChange(1, 2, midiValue); // Channel 1, Controller 2 = Humidity
        oldMidiValue = midiValue;
    }

    delay(100);
}

void controlChange(int channel, int controllerNumber, int controlValue)
{
    int statusByte = 0xB0 | (channel - 1); // Control Change message on channel
    Serial.write(statusByte);
    Serial.write(controllerNumber);
    Serial.write(controlValue);
}
