
 int val; // Data received from the serial port
 int ledPin = 13; // Set the pin to digital I/O 13
 int counter;
 int state;
 
 void count_me(){
   counter++;
 }
void setup() 
{
  pinMode(ledPin, OUTPUT);
 // pinMode(FLOWSENSORPIN, INPUT);
//  digitalWrite(FLOWSENSORPIN, HIGH);
  attachInterrupt(0, count_me, RISING);
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
   
  counter = 0;
  
 
  while(counter <5){
    digitalWrite(13,HIGH);
    //Serial.print(counter);
  }
  digitalWrite(13,LOW);
  //digitalRead(FLOWSENSORPIN);
  
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
  digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
 }
 }


