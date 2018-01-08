// KY-028
int AnalogInput = A10;
int DigitalInput = 22;

int bigNTCsensor = A8;

int val;
int tempPin = A10;

void setup ()
{
  Serial.begin (9600);
  pinMode (AnalogInput, INPUT);
  pinMode (DigitalInput, INPUT);
}  

void loop ()
{
  float Analog;
  int Digital;
//  Analog = analogRead(AnalogInput);
//  Digital= digitalRead(DigitalInput);
//  Serial.print(Analog);
//  Serial.print(" -- ");
//  Serial.println(Digital);
  /* Current values will be read and converted to voltage*/
  Analog = analogRead (AnalogInput) * (5.0 / 1023.0); 
  Digital = digitalRead (DigitalInput);
  
  Serial.print ("Analog voltage value:"); Serial.print (Analog, 4);  Serial.print ("V, ");Serial.print (Digital);
  Serial.print ("Extreme value:");
  
  if(Digital==1)
  {
      Serial.println (" reached");
  }
  else
  {
      Serial.println (" not yet reached");
  }
  delay (1000);
  
  float cel = analogRead(tempPin)/2;
  int readVal=analogRead(bigNTCsensor);
  double temp =  Thermistor(readVal);
  Serial.print("Temperature big sensor is = ");
  Serial.print(temp);
  Serial.println(" Celsius, ");

}

double Thermistor(int RawADC) {
  double Temp;
  Temp = log(10000.0*((1024.0/RawADC-1))); 
  Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
  Temp = Temp - 273.15;            // Convert Kelvin to Celcius
   //Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit
   return Temp;
}
