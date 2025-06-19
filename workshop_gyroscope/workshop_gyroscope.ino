#include <Arduino_LSM6DSOX.h>

int oldMidiValue = -1;

void setup() {
  Serial.begin(115200); // Use 31250 for real MIDI
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }
}

void loop() {
  float x, y, z;

  if (IMU.accelerationAvailable()) {
    IMU.readAcceleration(x, y, z);

    // Clamp X to -1.0 to 1.0
    x = constrain(x, -1.0, 1.0);

    // Map from -1.0 to 1.0 --> 0 to 127
    int midiValue = map(x * 100, -100, 100, 0, 127);

    // Only send MIDI if value has changed
    if (midiValue != oldMidiValue) {
      controlChange(1, 10, midiValue); // Channel 1, CC 10 (commonly pan)
      oldMidiValue = midiValue;
    }
  }

  delay(50);
}

void controlChange(int channel, int controllerNumber, int controlValue)
{
  int statusByte = 0xB0 | (channel - 1);
  Serial.write(statusByte);
  Serial.write(controllerNumber);
  Serial.write(controlValue);
}
