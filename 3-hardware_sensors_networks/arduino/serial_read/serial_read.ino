const int MaxChars = 5;
char strValue[MaxChars + 1]; // must be big enough for digits and terminating null
int index = 0; // the index into the array storing the received digits
int sensorValue = 0;

void setup() {
  Serial.begin(57600);
}

void loop()
{
  if ( Serial.available())
  {
    char ch = Serial.read();
    
    if (index <  MaxChars && ch >= '0' && ch <= '9') {
      strValue[index++] = ch; // add the ASCII character to the string;
    }
    else
    {
      // here when buffer full or on the first non digit
      strValue[index] = 0;        // terminate the string with a 0
      sensorValue = atoi(strValue);  // use atoi to convert the string to an int
      index = 0;
    }
  }

  Serial.println(sensorValue);
}
