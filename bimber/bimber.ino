#include <OneWire.h> 
#include <DallasTemperature.h>
#include <LiquidCrystal.h> 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
#define thermometer 8
#define buzzer 12
boolean stat = false;
boolean startTemp = false;
boolean lowTemp = false;
int temperature = 0;
int counter = 0;

OneWire oneWire(thermometer); 
DallasTemperature sensors(&oneWire);
void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  lcd.begin(16, 2); 
  lcd.setCursor(0, 0); 
  lcd.print("Buenas tardes"); 
  lcd.setCursor(0, 1); 
  lcd.print("Borracho amigo!");
  digitalWrite(buzzer, HIGH);
  delay(50);
  digitalWrite(buzzer, LOW);
  
  delay(2000);
  lcd.clear();  
}
void loop() {
  lcd.setCursor(0,0);
  lcd.print("Current temp:");
  lcd.setCursor(0,1);
  sensors.requestTemperatures();
  lcd.print(sensors.getTempCByIndex(0));
  temperature = sensors.getTempCByIndex(0);
    delay(1000);
//  if ((temperature > 20) && (temperature < 24)) {
//    activateBuzzer(100, startTemp);
//    startTemp = true;}
//   
//    
//  else  if ((temperature > 26) && (lowTemp = false)) {
//    Serial.println("Case 1");
//    activateBuzzer(100);
//    lowTemp = true;
//    Serial.println("1" + startTemp);
//    }
}



void activateBuzzer(int delay_time, bool stat){
  digitalWrite(buzzer, HIGH);
  delay(delay_time);
  digitalWrite(buzzer, LOW);
  delay(delay_time);
  digitalWrite(buzzer, HIGH);
  delay(delay_time);
  digitalWrite(buzzer, LOW);
  delay(delay_time);
  digitalWrite(buzzer, HIGH);
  delay(delay_time);
  digitalWrite(buzzer, LOW);
  delay(delay_time);
  digitalWrite(buzzer, HIGH);
  delay(delay_time);
  digitalWrite(buzzer, LOW);
}
 
