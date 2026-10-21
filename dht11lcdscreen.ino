#include <LiquidCrystal.h>
#include <DHT.h>

#define DHTPIN 17
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

const int rs = 50, e = 51, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, e , d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  float temp = dht.readTemperature();
  float humi = dht.readTemperature();

  delay(500);

  if (isnan(temp) || isnan(humi)) {
    lcd.print("Failed to read");
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" C");

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(humi);
    lcd.print("%");

  }
  delay(10000);

}