#include <LiquidCrystal.h>
#include <DHT.h>
// Include required libraries

#define DHTPIN 17
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
// Initialize DHT pin, and DHT Type

const int rs = 50, e = 51, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, e , d4, d5, d6, d7);
// Create variables for each pin
// Initialize the pins

void setup() {
  lcd.begin(16, 2);
  //Initialize the rows and columns of the LCD Screen
  
  dht.begin();
  //Start reading temperature and humidity
}

void loop() {
  float temp = dht.readTemperature();
  float humi = dht.readHumidity();
  //Create variables for Temperature and Humidity

  delay(500);
  //Delay the code to allow for the DHT Sensor to read temperature. It is required due to the low kHz of the DHT11 Sensor

  if (isnan(temp) || isnan(humi)) {
    lcd.print("Failed to read");
    //Check whether the DHT11 Sensor is working or not
  } else {
    lcd.setCursor(0, 0);
    lcd.print("Temp: ");
    lcd.print(temp);
    lcd.print(" C");
    //Print temperature onto the LCD Screen

    lcd.setCursor(0, 1);
    lcd.print("Humidity: ");
    lcd.print(humi);
    lcd.print("%");
    //Print humidity onto the LCD Screen

  }
  delay(10000);
  //Delay the code to allow for the DHT Sensor to read temperature. It is required due to the low kHz of the DHT11 Sensor

}
