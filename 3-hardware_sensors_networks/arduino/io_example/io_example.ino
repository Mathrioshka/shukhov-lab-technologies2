int analogPin = 1;
int ledPin = 8;
int val = 0;

void setup()
{
  Serial.begin(57600);

  pinMode(ledPin, OUTPUT);
}

void loop()
{
  val = map(analogRead(analogPin), 0, 1023, 0, 255);
  analogWrite(ledPin, val);

  Serial.println(val);

  delay(100);
}
