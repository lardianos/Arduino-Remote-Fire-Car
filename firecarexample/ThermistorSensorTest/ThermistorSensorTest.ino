// KY-028
int AnalogInput = A1;
int DigitalInput = 3;

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
  Analog = analogRead(DigitalInput);
  Digital= digitalRead(DigitalInput);
  Serial.print(Analog);
  Serial.print(" -- ");
  Serial.println(Digital);
  /* Current values will be read and converted to voltage
  Analog = analogRead (Analog_Eingang) * (5.0 / 1023.0); 
  Digital = digitalRead (Digital_Eingang);
  
  Serial.print ("Analog voltage value:"); Serial.print (Analog, 4);  Serial.print ("V, ");Serial.print (Digital);
  Serial.print ("Extreme value:");
  
  if(Digital==1)
  {
      Serial.println (" reached");
  }
  else
  {
      Serial.println (" not yet reached");
  }*/
  delay (200);
}
