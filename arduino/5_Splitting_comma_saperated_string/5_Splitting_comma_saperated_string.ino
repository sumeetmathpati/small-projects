
String message = "C,Python,Assembly";
int commaPosition;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  do {
    commaPosition = message.indexOf(',');
    if(commaPosition != -1) {
      Serial.println(message.substring(0, commaPosition));
      message = message.substring(commaPosition + 1, message.length());
    } else {
      if(message.length() > 0)
        Serial.println(message);
    }
  }while(commaPosition >= 0);

  delay(5000);

}
