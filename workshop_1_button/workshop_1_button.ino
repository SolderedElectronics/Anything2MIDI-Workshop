void setup() 
{
  pinMode(0, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() 
{
  if(digitalRead(0) == 0)
  {
    Serial.println("button!");
  }
}
