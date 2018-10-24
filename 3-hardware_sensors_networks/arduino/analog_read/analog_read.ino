int analogPin = 1;
int val = 0;

void setup()
{
  Serial.begin(115200);
}

void loop()
{
  val = analogRead(analogPin);
  Serial.println(val);
}
