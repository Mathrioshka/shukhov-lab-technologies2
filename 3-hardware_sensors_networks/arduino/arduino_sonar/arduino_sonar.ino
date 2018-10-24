const uint8_t echoPins[] = {2, 4, 8};
const uint8_t trigPins[] = {3, 5, 9};

uint32_t duration;
uint32_t cm;

void setup() {
  Serial.begin(115200);

  pinMode(echoPins[0], INPUT);
  pinMode(trigPins[0], OUTPUT);

  pinMode(echoPins[1], INPUT);
  pinMode(trigPins[1], OUTPUT);

  pinMode(echoPins[2], INPUT);
  pinMode(trigPins[2], OUTPUT);
}

uint8_t sensorNumber = 0;
void loop()
{
  digitalWrite(trigPins[sensorNumber], LOW);

  delayMicroseconds(3);

  digitalWrite(trigPins[sensorNumber], HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPins[sensorNumber], LOW);

  duration = pulseIn(echoPins[sensorNumber], HIGH, 10000);

  cm = (uint32_t)((duration<<4)+duration); // cm = 17 * duration/1000

  Serial.print(sensorNumber);
  Serial.print(" ");
  Serial.print(cm);

  Serial.println();

  sensorNumber += 1;
  if(sensorNumber > 2) {
    sensorNumber = 0;
  }

  delay(30);
}
