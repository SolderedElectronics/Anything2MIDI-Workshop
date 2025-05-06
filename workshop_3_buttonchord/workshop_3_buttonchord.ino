
#include <RBD_Timer.h>  // https://github.com/alextaujenis/RBD_Timer
#include <RBD_Button.h> // https://github.com/alextaujenis/RBD_Button

// Create button
RBD::Button button(0);

void setup() 
{
  Serial.begin(115200);
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
