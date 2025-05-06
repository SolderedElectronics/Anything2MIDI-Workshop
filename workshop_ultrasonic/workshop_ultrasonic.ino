
#include <RBD_Timer.h>  // https://github.com/alextaujenis/RBD_Timer
#include <RBD_Button.h> // https://github.com/alextaujenis/RBD_Button

#include "Ultrasonic-distance-sensor-easyC-SOLDERED.h"

// input pullup enabled by default
RBD::Button button(0);

Ultrasonic_Sensor hc; //Initializer for sensor with easyC

int oldMidiValue = 0;

void setup() {
  Serial.begin(115200);

  hc.begin();  //Initialize sensor
}

void loop() {
  if(button.onPressed()) {
    noteOn(0x90, 60, 100);
  }

  if(button.onReleased()) {
    noteOff(0x80, 60);

  }

  hc.takeMeasure();
  delay(37);
  int distance = hc.getDuration();
  int distanceConstrained = constrain(distance, 0, 1250);

  int distanceValue127 = map(distanceConstrained, 0, 1250, 0, 127);
  if(distanceValue127 != oldMidiValue)
  {
    controlChange(1, 1, distanceValue127);
    oldMidiValue = distanceValue127;
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

void controlChange(int channel, int controllerNumber, int controlValue)
{
  // Calculate the status byte based on the provided channel.
  int statusByte = 0xB0 | (channel - 1);

  // Send the control change message
  Serial.write(statusByte);
  Serial.write(controllerNumber);
  Serial.write(controlValue);
}
