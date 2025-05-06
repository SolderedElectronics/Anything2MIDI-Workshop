#include <LSM6DS3-SOLDERED.h>
#include <RBD_Timer.h>  // https://github.com/alextaujenis/RBD_Timer
#include <RBD_Button.h> // https://github.com/alextaujenis/RBD_Button


// Create button
RBD::Button button(0);

Soldered_LSM6DS3 gyro; // Default address is 0x6B

int oldMidiValue = 0;

void setup()
{
  Serial.begin(115200);
  gyro.begin();

}

void loop() 
{
  if(button.onPressed()) 
  {
    noteOn(0x90, 60, 100);
  }

  if(button.onReleased()) 
  {
    noteOff(0x80, 60);
  }

  //int midiValue127 = map(slider.getPercentage(), 0, 100, 0, 127);
  float accel = gyro.readFloatAccelZ() * 100;
  float accelConsrained = constrain(accel, -100, 100);
  int midiValue127 = map(accelConsrained, -100, 100, 0, 127);
  
  if(midiValue127 != oldMidiValue)
  {
    controlChange(1, 1, midiValue127);
    oldMidiValue = midiValue127;
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
