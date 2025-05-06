#include "APDS9960-SOLDERED.h"
APDS_9960 APDS;

void setup()
{
  Serial.begin(115200);
  APDS.begin();
}

void loop()
{
  if (APDS.gestureAvailable())
  {
    int gesture = APDS.readGesture();

    //Determine which gesture was captured
    switch (gesture)
    {
      case GESTURE_UP:
        // C major (Cmaj) chord
        noteOn(0x90, 60, 100); // C4
        noteOn(0x90, 64, 100); // G4
        noteOn(0x90, 67, 100); // E4
        delay(500);
        noteOff(0x80, 60);
        noteOff(0x80, 64);
        noteOff(0x80, 67);
        break;

      case GESTURE_DOWN:
        // A minor (Am) chord
        noteOn(0x90, 57, 100);  // A3
        noteOn(0x90, 60, 100);  // C4
        noteOn(0x90, 64, 100);  // E4
        delay(500);
        noteOff(0x80, 57);
        noteOff(0x80, 60);
        noteOff(0x80, 64);
        break;

      case GESTURE_LEFT:
        // F major (F) chord
        noteOn(0x90, 53, 100);  // F3
        noteOn(0x90, 57, 100);  // A3
        noteOn(0x90, 60, 100);  // C4
        delay(500);
        noteOff(0x80, 53);
        noteOff(0x80, 57);
        noteOff(0x80, 60);
        break;

      case GESTURE_RIGHT:
        // G major (G) chord
        noteOn(0x90, 55, 100);  // G3
        noteOn(0x90, 59, 100);  // B3
        noteOn(0x90, 62, 100);  // D4
        delay(500);
        noteOff(0x80, 55);
        noteOff(0x80, 59);
        noteOff(0x80, 62);
        break;

      default:
        // ignore
        break;
    }
  }
}

void noteOn(int cmd, int pitch, int velocity)
{
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(velocity);
}

void noteOff(int cmd, int pitch)
{
  Serial.write(cmd);
  Serial.write(pitch);
  Serial.write(0);
}
