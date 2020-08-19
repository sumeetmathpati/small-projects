const int tiltSensorPin = 2;
const int firstLEDPin = 11;
const int secondLEDPin = 12;

void setup() {
  // put your setup code here, to run once:
  pinMode (tiltSensorPin, INPUT);
  digitalWrite (tiltSensorPin, HIGH); //the code will read this pin
  // and use a pull-up resistor
  pinMode (firstLEDPin, OUTPUT);
  pinMode (secondLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(tiltSensorPin)){
    digitalWrite(firstLEDPin, HIGH);
    digitalWrite(secondLEDPin, LOW);
  }
  else{
    digitalWrite(firstLEDPin, LOW);
    digitalWrite(secondLEDPin, HIGH);
  }
}
