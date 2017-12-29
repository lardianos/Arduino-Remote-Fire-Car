const int analogInPin = A5;  
const int analogOutPin = 9; 
int sensorValue = 0;        
int outputValue = 0;        
int input='0';
//L293D A
//Motor A
const int motorAPin1  = 5;  // Pin 14 of L293
const int motorAPin2  = 6;  // Pin 10 of L293
//Motor B
const int motorBPin1  = 10; // Pin  7 of L293
const int motorBPin2  = 9;  // Pin  2 of L293

void motor_test(){
    //Motor Control - Motor A: motorPin1,motorpin2 & Motor B: motorpin3,motorpin4
    //This code  will turn Motor A clockwise for 2 sec.
    digitalWrite(motorAPin1, HIGH);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);
    delay(2000); 
    //This code will turn Motor A counter-clockwise for 2 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, HIGH);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);
    delay(2000);
    
    //This code will turn Motor B clockwise for 2 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, HIGH);
    digitalWrite(motorBPin2, LOW);
    delay(2000); 
    //This code will turn Motor B counter-clockwise for 2 sec.
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, HIGH);
    delay(2000);    
    //And this code will stop motors
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin1, LOW);
    digitalWrite(motorBPin2, LOW);  
  }
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial.println("HELLO");
  Serial.println(5);
  //Set pins as outputs
  pinMode(motorAPin1, OUTPUT);
  pinMode(motorAPin2, OUTPUT);
  pinMode(motorBPin1, OUTPUT);
  pinMode(motorBPin2, OUTPUT);
  motor_test();
}

void loop() {
  //char a,b;
  int a;
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

    a = Serial1.read();
    if(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9'||a=='A'||a=='B'||a=='E'){
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
        Serial.println("Left 3");
        digitalWrite(motorBPin1, HIGH);
      }
      else if(input == '4')
      {
        Serial.println("Right 4");
        digitalWrite(motorBPin2, HIGH);
      }
      else if(input == '5')
      {
        Serial.println("Up 5");
      }
      else if(input == '6')
      {
        Serial.println("Down 6");
      }
      else if(input == '7')
      {
        Serial.println("Left 7");
      }
      else if(input == '8')
      {
        Serial.println("Right 8");
      }
      else if(input == '9')
      {
        Serial.println("In 9");
      }
      else if(input == 'A')
      {
        Serial.println("Out 10");
      }
      else if(input == 'B')
      {
        Serial.println("Water 11");
      }
      else if(input == 'E')
      {
        Serial.println("End");
        digitalWrite(motorAPin1, LOW);
        digitalWrite(motorAPin2, LOW);
        digitalWrite(motorBPin1, LOW);
        digitalWrite(motorBPin2, LOW); 
      }
    } 
    
                      
}
