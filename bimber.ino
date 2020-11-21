#include <OneWire.h> 
#include <DallasTemperature.h>
#include <LiquidCrystal.h> 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
#define thermometer 8
#define buzzer 12
boolean alreadyRun = false;
boolean changeStatus = false;
int temperature = 0;

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
  switch (temperature){
    case 1:
    if (sensors.getTempCByIndex(0) > 20) {
    activateBuzzer(50, true);
    break;
    
  }
  }
  }


void activateBuzzer(int delay_time, bool check_status){
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
  if (changeStatus == true) {
    alreadyRun = true;
  }
}
 
