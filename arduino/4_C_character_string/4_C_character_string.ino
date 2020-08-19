
char StringA[8] = "Arduino";
char StringB[8] = "Arduino";
char StringC[16] = "Arduino";
char StringD[ ] = "Arduino";

void setup() {

  Serial.begin(9600);

  Serial.print(StringB);
  Serial.print(" is ");
  Serial.print(strlen(StringB));
  Serial.println(" characters long.");

  strncpy(StringA, "Hello", 6);
  Serial.println(StringA);

  strcat(StringC, "Hi");
  Serial.println(StringC);
  
  

}

void loop() {
  // put your main code here, to run repeatedly:

}
