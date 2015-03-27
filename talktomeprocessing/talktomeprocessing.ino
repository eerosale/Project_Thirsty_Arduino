 int val; // Data received from the serial port
 int ledPin = 13; // Set the pin to digital I/O 13

void setup() 
{
  pinMode(ledPin, OUTPUT);
//initialize serial communications at a 9600 baud rate
Serial.begin(9600);
}

void loop()
{
  
  if (Serial.available()) 
   { // If data is available to read,
     val = Serial.read(); // read it and store it in val
   
   switch (val) 
   { // If 1 was received
      case '0':         
       Shot_one();
        break; 
      case '1':
      Shot_two();
      break;
      case '2':
      Shot_three();
      break;
      default:
      break;
   }
}
}
  int Shot_one(){
   
  digitalWrite(13, HIGH);
  delay(5000);
  digitalWrite(13, LOW);
    // turn the LED on (HIGH is the voltage level)
  
 }
 
 int Shot_two(){
   int i;
  for (i = 0; i<2; i++)
  {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
 }
 }//delay(5000); // Wait 10 milliseconds for next reading

 int Shot_three(){
   int i;
  for (i = 0; i<5; i++)
  {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
 }
 }


