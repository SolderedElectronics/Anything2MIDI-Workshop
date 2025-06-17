const int buttonPin = 0;
const unsigned long debounceDelay = 50; // milliseconds

bool buttonState = HIGH;     // current stable state
bool lastButtonState = HIGH; // previous stable state
unsigned long lastDebounceTime = 0;

void setup()
{
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop()
{
  int reading = digitalRead(buttonPin);

  // If the reading changed, reset debounce timer
  if (reading != lastButtonState)
  {
    lastDebounceTime = millis();
  }

  // If the reading has been stable for long enough, accept it
  if ((millis() - lastDebounceTime) > debounceDelay)
  {
    if (reading != buttonState)
    {
      buttonState = reading;

      if (buttonState == LOW)
      { // Button pressed
        noteOn(0x90, 60, 100);
      }
      else
      { // Button released
        noteOff(0x80, 60);
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
