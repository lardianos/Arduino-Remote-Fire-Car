const int analogInPin = A5;  
const int analogOutPin = 9; 
int sensorValue = 0;        
int outputValue = 0;        
int input='0';
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);

  Serial.println("HELLO");
  Serial.println(5);

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

    if(Serial.available()>0){
        a = Serial1.read();
        if(a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9'||a=='A'||a=='B'||a=='E'){
            input = a;
          }
      }
    

 
    if(input == '1')
    {
      Serial.println("Front 1");
    }
    else if(input == '2')
    {
      Serial.println("Back 2");
    }
    else if(input == '3')
    {
      Serial.println("Left 3");
    }
    else if(input == '4')
    {
      Serial.println("Right 4");
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
    }
                      
}
