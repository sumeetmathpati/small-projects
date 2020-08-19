/*
Basic_Strings sketch
*/

String text1 = "Hello world!";
String text2 = "Sherlock Holmes and Doctor Watson";
String text3 = "Harry Potter";

void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);
  
  Serial.print( text1);
  Serial.print(" is ");
  Serial.print(text1.length());
  Serial.println(" characters long.");
  
  Serial.print("text2 is ");
  Serial.print(text2.length());
  Serial.println(" characters long.");
  
  text1.concat(text2);
  Serial.println("text1 now contains: ");
  Serial.println(text1);

}

void loop() {
  // put your main code here, to run repeatedly:

}
