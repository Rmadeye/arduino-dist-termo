#include <OneWire.h> 
#include <DallasTemperature.h>
#include <LiquidCrystal.h> 
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); 
#define thermometer 8
#define buzzer 12
int thresholds[6] = { 30, 50, 70, 90, 96, 98 };
String progresses[6] = {"Preheat/Opt. Dist", "Warm-up/Dist.Overheat", "Distillation (Opt.)",
"Distillation (Low)", "Post-dist", "The end"};
int highestThresholdALreadyWarnedAbout = 0;
int temperature = 0;
int signals = 0;

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
boolean warnAboutHighTemp = true;
boolean warnAboutLowTemp = true;
 
void loop() {
    //lcd.clear(); 
    sensors.requestTemperatures();

    lcd.setCursor(0,0);
  lcd.print("Current temp:");
  lcd.setCursor(0,1);
  lcd.print(sensors.getTempCByIndex(0));
  temperature = sensors.getTempCByIndex(0);
 
  int highestPassedThreshold;
 
  if (temperature < thresholds[0]) {        // < 30
    highestPassedThreshold = 0;
  } else if (temperature < thresholds[1]) { // 30-50
    highestPassedThreshold = 1;
  } else if (temperature < thresholds[2]) { // 50-70
    highestPassedThreshold = 2;
      } else if (temperature < thresholds[3]) { // 70-90
    highestPassedThreshold = 3;
          } else if (temperature < thresholds[4]) { // 90-96
    highestPassedThreshold = 4;
          } else if (temperature < thresholds[5]) { // 96-98
    highestPassedThreshold = 5;
  } else {                                  // > 98
    highestPassedThreshold = 6;
  }
 
  if (highestPassedThreshold > highestThresholdALreadyWarnedAbout) {
    highestThresholdALreadyWarnedAbout = highestPassedThreshold;
    signals = highestPassedThreshold*2;
    activateBuzzer(100, signals);
  }
  else if ( highestThresholdALreadyWarnedAbout > highestPassedThreshold ) {
    highestThresholdALreadyWarnedAbout = highestPassedThreshold;
       signals = highestPassedThreshold*2;

        activateBuzzer(100, signals);
  }
 
  delay(1000);
//  lcd.clear();
//  lcd.setCursor(0,0);
//  lcd.print("Progress: ");
//  lcd.setCursor(0,1);
//  lcd.print(progresses[highestPassedThreshold]);
//  delay(1000);
   
}
 
void activateBuzzer(int delay_time, int beeps){
  for (int i = 0; i < beeps; i++) {
    digitalWrite(buzzer, i % 2 == 0 ? HIGH : LOW);
    delay(delay_time);
  }
}
