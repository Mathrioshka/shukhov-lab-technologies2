void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

  while (!Serial) ;
}

int i = 0;

void loop() {  
  Serial.println(i);

  i++;

  if (i > 100) {
    i = 0;
  }

  delay(1000);
}
