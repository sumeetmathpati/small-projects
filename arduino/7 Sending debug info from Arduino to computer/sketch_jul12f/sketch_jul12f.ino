void setup() {
  Serial.begin(9600);
}

int number = 0;

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("The number is ");
  Serial.println(number);

  delay(500);
  number++;

}
