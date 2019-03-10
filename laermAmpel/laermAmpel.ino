const int mikrofon = A0;      //Analog-Eingang für das Mikrofon
const int grenze_rot = 700;   //Grenze für Rot-Anzeige
const int grenze_gelb = 500;  //Grenze für Gelb-Anzeige
const int led_rot = 8;        //Digital-Ausgang für rote LED
const int led_gelb = 7;       //Digital-Ausgang für gelbe LED
const int led_gruen = 6;     //Digital-Ausgang für grüne LED
const int dauer = 500;        //Anschaltdauer
 
void setup() {
Serial.begin(9600);          //Baudrate für serielle Schnittstelle
pinMode(led_rot, OUTPUT);    //LED als Ausgabe definieren
pinMode(led_gelb, OUTPUT);   //LED als Ausgabe definieren
pinMode(led_gruen, OUTPUT);  //LED als Ausgabe definieren
}
 
void loop() {
int lautstaerke = analogRead(mikrofon); // Lautstärke einlesen
float wert = lautstaerke;
Serial.println(wert); // Wert ausgeben
if (wert>grenze_rot) {           // Für hohe Lautstärke
  Serial.println("Rot!");               //Meldung ausgeben
  digitalWrite(led_gruen, LOW);         //Grün ausschalten
  digitalWrite(led_gelb, LOW);          //Gelb ausschalten
  digitalWrite(led_rot, HIGH);          //Rot anschalten
  delay(dauer);                         //Warten
}
else if (wert>grenze_gelb){      //Für mittlere Lautstärke ...
  Serial.println("Gelb!");
  digitalWrite(led_gruen, LOW);
  digitalWrite(led_rot, LOW);
  digitalWrite(led_gelb, HIGH);
  delay(dauer);
}
else {
  digitalWrite(led_rot, LOW);           //Rot ausschalten
  digitalWrite(led_gelb, LOW);          //Gelb ausschalten
  digitalWrite(led_gruen, HIGH);        //sonst Grün anschalten
}
}
