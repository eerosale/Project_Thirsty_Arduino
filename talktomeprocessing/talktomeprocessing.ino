
 int val; // Data received from the serial port
 int ledPin = 13; // Set the pin to digital I/O 13
 int counter;
 int ledPin2 = 11;
 int countertwo;
 int select_zero = 6; //this will be for the select wires of the MUX
 int select_one = 7; 

 void count_me(){
   counter++;
   
 }
 
 void count_me_two(){
   countertwo++;
 }
void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(select_zero, OUTPUT);
  pinMode(select_one, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  attachInterrupt(0, count_me, RISING); 
  attachInterrupt(1, count_me_two, RISING);//THIS IS WHERE THE OUTPUT OF THE MUX WILL GO, (or 1 flowmeter to digital pin #2)
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
          case '4':
          Calibration();
          break;
          case '5':
          Calibration_off();
          break;
     }
  
  }
}
  int Shot_one(){
  long dummy_count = 0;
  
  counter = 0;
  digitalWrite(6, LOW); //this is for select 0 and 1 from mux 
  digitalWrite(7, LOW); //see above comment
 

  while(counter <60 & countertwo < 60){
    digitalWrite(13,HIGH); //this will turn on the pump
    digitalWrite(11, HIGH);
    //dummy_count++;
    if(counter >= 13) digitalWrite(13,LOW);
    if(countertwo >= 13) digitalWrite(11, LOW);
    //if(dummy_count>1000000) break;
  }
    digitalWrite(13,LOW); //this turns off the pump;
    digitalWrite(11, LOW);
    Serial.print(counter);
  }
  
 
 //following two functions are for LEDS blinking to test functionality of GUI buttons. 
 int Shot_two(){
 
   int i;
  for (i = 0; i<2; i++)
  {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait for half a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);
 }
 }

 int Shot_three(){
  long dummy_count = 0;
  counter = 0;
  digitalWrite(6, LOW); //this is for select 0 and 1 from mux 
  digitalWrite(7, LOW); //see above comment
 
  while(counter <13){
    digitalWrite(11,HIGH); //this will turn on the pump
    dummy_count++;
    if(dummy_count>100000) break;
    //Serial.print(counter);
  }
  digitalWrite(11,LOW); //this turns off the pump;
 }
 
 
 int Calibration() {
  
    digitalWrite(13, HIGH);
    }
    
    int Calibration_off(){
      digitalWrite(13,LOW);
    }
  

