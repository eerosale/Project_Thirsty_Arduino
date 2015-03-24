 int val; // Data received from the serial port
 int ledPin = 13; // Set the pin to digital I/O 13
 int do_me;

void setup() 
{
  pinMode(ledPin, OUTPUT);
//initialize serial communications at a 9600 baud rate
Serial.begin(9600);
}

void loop()
{
 val = 0;  
  if (Serial.available()) 
   { // If data is available to read,
     val = Serial.read(); // read it and store it in val
   }
   if (val == '1') 
   { // If 1 was received
                
      do_me = Blink_me();           // wait for a second
      //digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
      //delay(500); // turn the LED on
   } else if (val == '0'){
      digitalWrite(13, LOW);//digitalWrite(ledPin, LOW); // otherwise turn it off
   }
   delay(500);
}
  int Blink_me(){
    int i;
  for (i = 0; i<5; i++)
 { 
   
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
 
 } 
 Serial.print(val);
 return i;
 }
   //delay(5000); // Wait 10 milliseconds for next reading

//}

