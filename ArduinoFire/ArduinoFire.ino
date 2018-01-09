const int analogInPin = A5;  
const int analogOutPin = 9; 
int sensorValue = 0;        
int outputValue = 0;        
int input='0';

const int Alarm  = 3;  // Pin 14 of L293


//L293D 1
//Motor A
const int motorAPin1  = 4;  // Pin 14 of L293
const int motorAPin2  = 5;  // Pin 10 of L293
//L293D 1
//Motor B
const int motorBPin1  = 6; // Pin  7 of L293
const int motorBPin2  = 7; // Pin  2 of L293
//L293D 2
//Motor C
const int motorCPin1  = 8; // Pin 14 of L293
const int motorCPin2  = 9; // Pin 10 of L293
//L293D 2
//Motor D
const int motorDPin1  = 10; // Pin  7 of L293
const int motorDPin2  = 11; // Pin  2 of L293
//L293D 3
//Motor E
const int motorEPin1  = 12; // Pin 14 of L293
const int motorEPin2  = 13; // Pin 10 of L293

//L298
//Motor F
const int motorWaterPin1  = 30; // Pin 30 of L293
const int motorWaterPin2  = 31; // Pin 31 of L293

//Flame sensor Front 5-chanels
const int FlamePinFrontL1 = A0;  // This is our input pin
const int FlamePinFrontL2 = A1;  // This is our input pin
const int FlamePinFrontC1 = A2;  // This is our input pin
const int FlamePinFrontR1 = A3;  // This is our input pin
const int FlamePinFrontR2 = A4;  // This is our input pin
//Fleme sensor Right 
const int FlamePinRight = A5;  // This is our input pin
//Flame sensor Left
const int FlamePinLeft = A6;  // This is our input pin
//Flame sensor Back
const int FlamePinBack = A7;  // This is our input pin

const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum

void motor_test();

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("HELLO");
  Serial.println(5);
  //Set pins as outputs
  pinMode(Alarm,OUTPUT);
  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  pinMode(motorBPin1, OUTPUT);
  pinMode(motorBPin2, OUTPUT);
  pinMode(motorCPin1, OUTPUT);
  pinMode(motorCPin2, OUTPUT);
  pinMode(motorDPin1, OUTPUT);
  pinMode(motorDPin2, OUTPUT);
  pinMode(motorWaterPin1, OUTPUT);
  pinMode(motorWaterPin2, OUTPUT);  
  //motor_test();
}

void loop() {
  //char a,b;
  int a;
  int Flame1,Flame2,Flame3,Flame4,Flame5,Flame6,Flame7,Flame8;
  int range1=0,range2=0,range3=0,range4=0,range5=0,range6=0,range7=0,range8=0;
 /* a=Serial.read();
  b=Serial1.read();
  if(a=='A'||b=='A'){
      Serial.print(" ");
      Serial.println(1);
      Serial1.print(" ");
      Serial1.println(1);
      delay(500);
    }
 else if(a=='B'||b=='B'){
      Serial.print(" ");
      Serial.println(2);
      Serial1.print(" ");
      Serial1.println(2); 
    }*/
 
 Flame1 = analogRead(FlamePinFrontL1);
 Flame2 = analogRead(FlamePinFrontL2);
 Flame3 = analogRead(FlamePinFrontC1);
 Flame4 = analogRead(FlamePinFrontR1);
 Flame5 = analogRead(FlamePinFrontR2);
 Flame6 = analogRead(FlamePinRight);
 Flame7 = analogRead(FlamePinLeft);
 Flame8 = analogRead(FlamePinBack);

 range1 = map(Flame1, sensorMin, sensorMax, 0, 3);
 range2 = map(Flame2, sensorMin, sensorMax, 0, 3);
 range3 = map(Flame3, sensorMin, sensorMax, 0, 3);
 range4 = map(Flame4, sensorMin, sensorMax, 0, 3);
 range5 = map(Flame5, sensorMin, sensorMax, 0, 3);
 range6 = map(Flame6, sensorMin, sensorMax, 0, 3);
 range7 = map(Flame7, sensorMin, sensorMax, 0, 3);
 range8 = map(Flame8, sensorMin, sensorMax, 0, 3);

 Serial.print(range1);
 Serial.print(" - ");
 Serial.println(Flame1);
 Serial.print(range2);
 Serial.print(" - ");
 Serial.println(Flame2);
 Serial.print(range3);
 Serial.print(" - ");
 Serial.println(Flame3);
 Serial.print(range4);
 Serial.print(" - ");
 Serial.println(Flame4);
 Serial.print(range5);
 Serial.print(" - ");
 Serial.println(Flame5);
 Serial.print(range6);
 Serial.print(" - ");
 Serial.println(Flame6);
 Serial.print(range7);
 Serial.print(" - ");
 Serial.println(Flame7);
 Serial.print(range8);
 Serial.print(" - ");
 Serial.println(Flame8);
 Serial.println("******* AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA *******");
 if(range1==0||range2==0||range3==0||range4==0||range5==0||range6==0||range7==0||range8==0){
    Serial.println("** Close Fire **");    // A fire closer than 1.5 feet away.
    digitalWrite(Alarm, HIGH);
 }
 else if(range1==1||range2==1||range3==1||range4==1||range5==1||range6==1||range7==1||range8==1){
    Serial.println("** Distant Fire **");  // A fire between 1-3 feet away.
    digitalWrite(Alarm, HIGH);
 }
 else{
    Serial.println("No Fire");
    digitalWrite(Alarm, LOW);  
 }

  
    a = Serial1.read();
    if(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9'||a=='A'||a=='B'||a=='E'||a=='G'||a=='D'){
      input = a;
      if(input == '1')
      {
        Serial.println("Front 1");
        digitalWrite(motorAPin1, HIGH);      
      }
      else if(input == '2')
      {
        Serial.println("Back 2");
        digitalWrite(motorAPin2, HIGH);
      }
      else if(input == '3')
      {
        Serial.println("Left Front 3");
        //digitalWrite(motorAPin1, HIGH);              
        digitalWrite(motorBPin1, HIGH);
      }
      else if(input == '4')
      {
        Serial.println("Right Front 4");
        //digitalWrite(motorAPin1, HIGH);              
        digitalWrite(motorBPin2, HIGH);
      }
      else if(input == '5')
      {
        digitalWrite(motorDPin1, HIGH);              
        Serial.println("Up 5");
      }
      else if(input == '6')
      {
        digitalWrite(motorDPin2, HIGH);              
        Serial.println("Down 6");
      }
      else if(input == '7')
      {
        digitalWrite(motorCPin1, HIGH);             
        Serial.println("Left 7");
      }
      else if(input == '8')
      {
        digitalWrite(motorCPin2, HIGH);
        Serial.println("Right 8");
      }
      else if(input == '9')
      {
        digitalWrite(motorEPin1, HIGH);
        Serial.println("In 9");
      }
      else if(input == 'A')
      {
        digitalWrite(motorEPin2, HIGH);
        Serial.println("Out 10");
      }
      else if(input == 'B')
      {
        digitalWrite(motorWaterPin1, HIGH);
        Serial.println("Water 11");
      }
      else if(input == 'G')
      {
        //digitalWrite(motorAPin2, HIGH); 
        digitalWrite(motorBPin2, HIGH);        
        Serial.println("Right Down 12");
      }
      else if(input == 'D')
      {
        //digitalWrite(motorAPin2, HIGH);              
        digitalWrite(motorBPin1, HIGH);       
        Serial.println("Left Down 13");
      }
      else if(input == 'E')
      {
        Serial.println("End");
        digitalWrite(motorAPin1, LOW);
        digitalWrite(motorAPin2, LOW);
        digitalWrite(motorBPin1, LOW);
        digitalWrite(motorBPin2, LOW);
        digitalWrite(motorCPin1, LOW);
        digitalWrite(motorCPin2, LOW);
        digitalWrite(motorDPin1, LOW);
        digitalWrite(motorDPin2, LOW);
        digitalWrite(motorEPin1, LOW);
        digitalWrite(motorEPin2, LOW);
        digitalWrite(motorWaterPin1, LOW);
        digitalWrite(motorWaterPin2, LOW);
                 
      }
    }                
}

void motor_test(){
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4
    //This code  will turn Motor A clockwise for 2 sec.
    digitalWrite(motorAPin1, HIGH);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);
    digitalWrite(motorCPin1, LOW);
    digitalWrite(motorCPin2, LOW);
    digitalWrite(motorDPin1, LOW);
    digitalWrite(motorDPin2, LOW);
    digitalWrite(motorEPin1, LOW);
    digitalWrite(motorEPin2, LOW);    
    
    delay(1000); 
    //This code will turn Motor A counter-clockwise for 1 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, HIGH);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);
    digitalWrite(motorCPin1, LOW);
    digitalWrite(motorCPin2, LOW);
    digitalWrite(motorDPin1, LOW);
    digitalWrite(motorDPin2, LOW);
    digitalWrite(motorEPin1, LOW);
    digitalWrite(motorEPin2, LOW);    
    delay(1000);
    
    //This code will turn Motor B clockwise for 1 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, HIGH);
    digitalWrite(motorBPin2, LOW);
    digitalWrite(motorCPin1, LOW);
    digitalWrite(motorCPin2, LOW);
    digitalWrite(motorDPin1, LOW);
    digitalWrite(motorDPin2, LOW);
    digitalWrite(motorEPin1, LOW);
    digitalWrite(motorEPin2, LOW);    
    delay(1000); 
    //This code will turn Motor B counter-clockwise for 1 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, HIGH);
    digitalWrite(motorCPin1, LOW);
    digitalWrite(motorCPin2, LOW);
    digitalWrite(motorDPin1, LOW);
    digitalWrite(motorDPin2, LOW);
    digitalWrite(motorEPin1, LOW);
    digitalWrite(motorEPin2, LOW);    
    delay(1000);
    //This code will turn Motor C clockwise for 1 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);
    digitalWrite(motorCPin1, HIGH);
    digitalWrite(motorCPin2, LOW);
    digitalWrite(motorDPin1, LOW);
    digitalWrite(motorDPin2, LOW);
    digitalWrite(motorEPin1, LOW);
    digitalWrite(motorEPin2, LOW);    
    delay(1000);
    //This code will turn Motor C counter-clockwise for 1 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);
    digitalWrite(motorCPin1, LOW);
    digitalWrite(motorCPin2, HIGH);
    digitalWrite(motorDPin1, LOW);
    digitalWrite(motorDPin2, LOW);
    digitalWrite(motorEPin1, LOW);
    digitalWrite(motorEPin2, LOW);    
    delay(1000);
    //This code will turn Motor D clockwise for 1 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);
    digitalWrite(motorCPin1, LOW);
    digitalWrite(motorCPin2, LOW);
    digitalWrite(motorDPin1, HIGH);
    digitalWrite(motorDPin2, LOW);
    digitalWrite(motorEPin1, LOW);
    digitalWrite(motorEPin2, LOW);    
    delay(1000);
    //This code will turn Motor D counter-clockwise for 1 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);
    digitalWrite(motorCPin1, LOW);
    digitalWrite(motorCPin2, LOW);
    digitalWrite(motorDPin1, LOW);
    digitalWrite(motorDPin2, HIGH);
    digitalWrite(motorEPin1, LOW);
    digitalWrite(motorEPin2, LOW);    
    delay(1000);
    //This code will turn Motor E clockwise for 1 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);
    digitalWrite(motorCPin1, LOW);
    digitalWrite(motorCPin2, LOW);
    digitalWrite(motorDPin1, LOW);
    digitalWrite(motorDPin2, LOW);
    digitalWrite(motorEPin1, HIGH);
    digitalWrite(motorEPin2, LOW);    
    delay(1000);
    //This code will turn Motor E counter-clockwise for 1 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);
    digitalWrite(motorCPin1, LOW);
    digitalWrite(motorCPin2, LOW);
    digitalWrite(motorDPin1, LOW);
    digitalWrite(motorDPin2, LOW);
    digitalWrite(motorEPin1, LOW);
    digitalWrite(motorEPin2, HIGH);    
    delay(1000);
    
    
    //And this code will stop motors
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);
    digitalWrite(motorCPin1, LOW);
    digitalWrite(motorCPin2, LOW);
    digitalWrite(motorDPin1, LOW);
    digitalWrite(motorDPin2, LOW);
    digitalWrite(motorEPin1, LOW);
    digitalWrite(motorEPin2, LOW);
  }
