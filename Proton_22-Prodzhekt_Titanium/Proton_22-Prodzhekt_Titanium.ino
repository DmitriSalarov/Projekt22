//Протон 22
//Проджект Титаниум
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
#include <Wire.h>
#include <IRremote.h>
#define start 0xFFFFFFFF
#define stopp 0x20DF906F
#define reverse 0x20DF827D
#define ahead 0x20DF02FD
#define right 0x20DF609F
#define left 0x20DFE01F
#define SlowlyStop 0x20DF10EF
#define first 0x20DF8877
#define second 0x20DF48B7
#define third 0x20DFC837
#define fourth 0x20DF28D7
#define fifth 0x20DFA857
#define extreme 0x20DF6897
#define temp 0x20DF4EB1
#define TK19_PIN 11
IRrecv irrecv(TK19_PIN);
decode_results results;
float sicaklik;
float olculendeger;
const int read = A2; //Sensor AO pin to Arduino pin A0
int value;   
int sol = 9;
int sag = 10;
int LM35 = A3;
int ldr = A1;             // ldr mizi analog pine bağlıyoruz 
int ldr_deger ; 
int Flame = A0;
int Reset = 2;
int in1 = 6;
int in2 = 5;
int in3 = 4;
int in4 = 3;
const int sensorMin = 0;
const int sensorMax = 1024;
void setup() {
  // put your setup code here, to run once:
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ldr, INPUT);
  lcd.begin();
  lcd.setCursor(0,0);
  lcd.print("I am PRODZHEKT22");
  lcd.setCursor(0,1);
  lcd.print(":) :( :/ ;) ");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press START in");
  lcd.setCursor(0,1);
  lcd.print("RC Transmitter");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Powered By:");
  lcd.setCursor(0,1);
  lcd.print("Dmitri_Salarov");
  Serial.begin(9600);
   ldr_deger = analogRead(ldr);          // ldr değerimizi analog pinden okuyoruz
  Serial.println(ldr_deger); // Serial ekranımıza ( Arduino ide açıkken ctrl+shit+m tuş kombinasyonu ile yada üst taraftaki simgesi yada üsteki menüden açabilirsiniz) ldr değrini yazdırıyoruz
  if (ldr_deger > 550 || ldr_deger < 230){
    lcd.clear();
    lcd.print("INSERTION");
    lcd.setCursor(0,1);
    lcd.print("DETECTED!");
    digitalWrite(2, LOW);
    delay(100000000);
 }else{}
  irrecv.enableIRIn();
}

void loop() {

  if (irrecv.decode(&results))
 {

 Serial.println(results.value, HEX);
 irrecv.resume();
 delayMicroseconds(1);
 if (results.value == ahead){
   delay(1000);
     if (irrecv.decode(&results))
 {
 irrecv.resume();
 delayMicroseconds(1);
 if (results.value == first){
    lcd.clear();
    lcd.print("Going Ahead in");
    lcd.setCursor(0, 1);
    lcd.print("First Gear.");
   analogWrite(sol, 50);
    analogWrite(sag, 50);
digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    }else if (results.value == second){
      lcd.clear();
    lcd.print("Going Ahead in");
    lcd.setCursor(0, 1);
    lcd.print("Second Gear.");
    analogWrite(sol, 100);
    analogWrite(sag, 100);
digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    }else if (results.value == third){
      lcd.clear();
    lcd.print("Going Ahead in");
    lcd.setCursor(0, 1);
    lcd.print("Third Gear.");
      analogWrite(sol, 140);
    analogWrite(sag, 140);
digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
   }else if (results.value == fourth){
     lcd.clear();
    lcd.print("Going Ahead in");
    lcd.setCursor(0, 1);
    lcd.print("Fourth Gear.");
        analogWrite(sol, 175);
    analogWrite(sag, 175);
digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    }else if (results.value == fifth){
      lcd.clear();
    lcd.print("Going Ahead in");
    lcd.setCursor(0, 1);
    lcd.print("Fifth Gear.");
          analogWrite(sol, 200);
    analogWrite(sag, 200);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    }
  else if (results.value == extreme){
    lcd.clear();
    lcd.print("XtremeMode:Aktiv");
    analogWrite(sol, 255);
    analogWrite(sag, 255);
        digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    }}}
     else if (results.value == temp){
       olculendeger = (olculendeger/1023)*5000;
       sicaklik = olculendeger /10,0;
       olculendeger = analogRead(LM35);
      
       Serial.println(sicaklik);  
       lcd.clear();
       lcd.print("Temperature");
       lcd.setCursor(11, 0);
       lcd.print(sicaklik);
       }
     else if (results.value == reverse){
       lcd.clear();
    lcd.print("Going Back!");
      analogWrite(sol, 200);
    analogWrite(sag, 200);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
   }
  else if (results.value == stopp){
       lcd.clear();
    lcd.print("Stopped!");
      analogWrite(sol, 0);
    analogWrite(sag, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
   } else if (results.value == left){
     lcd.clear();
    lcd.print("Going Left!");
      analogWrite(sol, 200);
    analogWrite(sag, 200);
        digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
   } else if (results.value == right){
      lcd.clear();
    lcd.print("Going Right!");
     analogWrite(sol, 200);
    analogWrite(sag, 200);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
   } else if (results.value == SlowlyStop){
    lcd.clear();
    lcd.print("SlowlyStop(TM)");
    lcd.setCursor(0,1);
    lcd.print("Is in progress.");
    analogWrite(sol, 200);
    analogWrite(sag, 200);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    
    delay(500);
    analogWrite(sol, 175);
    analogWrite(sag, 175);
    delay(500);
    analogWrite(sol, 140);
    analogWrite(sag, 140);
    delay(500);
    analogWrite(sol, 100);
    analogWrite(sag, 100);
    delay(500);
    analogWrite(sol, 50);
    analogWrite(sag, 50);
    delay(500);
    analogWrite(sol, 0);
    analogWrite(sag, 0);
   } 

   }
  
   value = analogRead(read);
  if (value>480){ 
		Serial.println("Water level: 0mm to 5mm"); 
                lcd.clear();
                lcd.print("RAINING ALERT!");
}
  int sensorReading = analogRead(A0);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
  
 
   switch (range) {
 case 0: // A fire closer than 1.5 feet away.
 Serial.println("** Close Fire **");
 lcd.clear();
 lcd.print("Close Ranged");
 lcd.setCursor(0,1);
 lcd.print("FIRE ALARM!");
 break;
 case 1: // A fire between 1-3 feet away.
 Serial.println("** Distant Fire **");
 lcd.clear();
 lcd.print("FIRE ALARM!");
 break;
 case 2: // A fire between 1-3 feet away.
 break;
 }
   delay(1);
   
  }
