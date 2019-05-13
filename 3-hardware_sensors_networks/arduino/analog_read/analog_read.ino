int analogPin = 1;
int val = 0;

void setup()
{
  Serial.begin(57600);
}

void loop()
{
  val = analogRead(analogPin);
  Serial.println(val);
}
