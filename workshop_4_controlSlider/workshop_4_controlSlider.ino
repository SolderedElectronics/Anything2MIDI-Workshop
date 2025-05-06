
#include <RBD_Timer.h>  // https://github.com/alextaujenis/RBD_Timer
#include <RBD_Button.h> // https://github.com/alextaujenis/RBD_Button
#include "Slider-potentiometer-easyC-SOLDERED.h"

// Create button
RBD::Button button(0);

// Create the slider
sliderPot slider;

void setup()
{
  Serial.begin(115200);

  // Initialize the sensor
    slider.begin();
}

void loop() 
{
  if(button.onPressed()) 
  {
    noteOn(0x90, 60, 100);
    noteOn(0x90, 64, 100);
    noteOn(0x90, 67, 100);
  }

  if(button.onReleased()) 
  {
    noteOff(0x80, 60);
    noteOff(0x80, 64);
    noteOff(0x80, 67);
  }

  int sliderValue127 = map(slider.getPercentage(), 0, 100, 0, 127);
  controlChange(1, 1, sliderValue127);

  delay(10);
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
