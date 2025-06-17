const int buttonPin = 0;
const unsigned long debounceDelay = 50; // milliseconds

bool buttonState = HIGH;     // current stable state
bool lastButtonState = HIGH; // previous stable state
unsigned long lastDebounceTime = 0;

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(115200);
}

void loop()
{
  int reading = digitalRead(buttonPin);

  // Check for a change in input
  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
  }

  // Accept the new state if it has been stable long enough
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading != buttonState)
    {
      buttonState = reading;

      if (buttonState == LOW)
      { // Button pressed
        noteOn(0x90, 60, 100);
        noteOn(0x90, 64, 100);
        noteOn(0x90, 67, 100);
      }
      else
      { // Button released
        noteOff(0x80, 60);
        noteOff(0x80, 64);
        noteOff(0x80, 67);
      }
    }
  }

  lastButtonState = reading;
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
