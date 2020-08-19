const int ledPin = 13;
int blinkRate = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    if(Serial.available()) {
    char ch = Serial.read();
    Serial.println(ch);
    if(ch >= '0' && ch <= '9') {
      blinkRate = (ch - '0');
      blinkRate = blinkRate * 100;
    }
  }
  blink();
}

void blink() {
  digitalWrite(ledPin, HIGH);
  delay(blinkRate);
  digitalWrite(ledPin, LOW);
  delay(blinkRate);
}
