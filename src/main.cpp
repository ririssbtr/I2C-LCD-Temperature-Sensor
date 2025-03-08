#include <Arduino.h>
//RUMIRIS BUTARRBUTAR
//233140707111130
//LCD I2C dengan sensor suhu

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHTesp.h"

LiquidCrystal_I2C lcd(0x27,16,2);

float temperature; //tipe data temperature
const int DHT_PIN = 13; //kaki DHT-22 pada ESP 32

DHTesp dhtSensor;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  dhtSensor.setup(DHT_PIN, DHTesp::DHT22);  
  lcd.init();
  lcd.backlight();
}

void loop() {
  TempAndHumidity  data = dhtSensor.getTempAndHumidity();
  lcd.clear();
  
  lcd.setCursor(0,0); //Menampilkan text di posisi kolom ke 0 baris ke 0
  lcd.println ("Tampilan Sensor Suhu");
    
  lcd.setCursor(3,2); //Menampilkan text di posisi kolom ke 3 baris ke 3
  lcd.println ("Suhu : " + String(data.temperature, 2) + " C");
  
  lcd.setCursor(1,3);
  lcd.print("Kelembapan: " + String(data.humidity, 2) + " %");

  
  delay (2000); //Delay selama 2s
}
