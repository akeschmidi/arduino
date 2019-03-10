int soilMoisturePin1 = 4;
int soilMoisturePin2 = 3;
int soilMoisturePin3 = A3;
int baudrate = 9600;


const int motorPin1 = 9;
const int motorPin2 = 10;

int Speed; //Motorgeschwindigkeit 
int flag;

void setup() 
{
  pinMode(motorPin1, OUTPUT); 
  pinMode(motorPin2, OUTPUT);
  
  Serial.begin( baudrate );
  while(!Serial); 

}

int readSoilMoisture()

{
   int value; 
  
   pinMode(soilMoisturePin1, OUTPUT);
   pinMode(soilMoisturePin2, OUTPUT);

   digitalWrite(soilMoisturePin1, HIGH);
   digitalWrite(soilMoisturePin2, LOW);

   value = analogRead(soilMoisturePin3);

   digitalWrite(soilMoisturePin2, HIGH);
   digitalWrite(soilMoisturePin1, LOW);
   delay(500);

   digitalWrite(soilMoisturePin2, LOW);
   return value;
}

void loop() 
{
  int value_water = readSoilMoisture(); 
  //Werte von 0 zu 1023
  String water = String((int)((((double)value_water/1023.0)*100.0)));  
  Serial.print("Bodenfeuchtigkeit: ");
  Serial.print(water);
  Serial.print("% Rohwert: ");
  Serial.println(value_water);
  Serial.println(motorPin1);

//Warte auf Daten
    if (water.toInt() < 30)
    {
      Serial.println("Zu trocken, wir sollten es giessen...");
      Speed = 100;
      flag=0;
    }
    else 
    {
      Serial.println("Noch nass, keine Notwendigkeit, es zu giessen.");
      Speed = 0;
    }

 
  if (Speed>=50 && Speed<=255)
  {
   
    analogWrite(motorPin1, Speed);
      
      if (flag==0)
      { 
        Serial.print("Motor läuft mit: ");
        Serial.print(Speed);
        Serial.println(" PWM");
        flag=1;
      }
  }
  else if (Speed == 0) 
  {
    analogWrite(motorPin1, Speed);
  }

  delay(3000);
}
