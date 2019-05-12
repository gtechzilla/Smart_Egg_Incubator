//set up the lcd screen
#include <Wire.h> //Library for I2C communication
#include <LiquidCrystal_I2C.h> //Library for LCD
//Wiring: SDA pin is connected to A4 and SCL pin to A5.
//Connect to LCD via I2C, default address 0x27 
LiquidCrystal_I2C lcd(0x27,20,4); //Change to (0x27,16,2) for 16x2 LCD.


//set up the temperature sensor
#include <dht.h>
dht DHT;
#define DHT11_PIN 7

void setup()
{
//Initiate the LCD
lcd.init();
lcd.backlight();
}
void loop()
{
int chk = DHT.read11(DHT11_PIN);

lcd.setCursor(0,0); //Set the cursor on the first column and first row.
lcd.print("Temp: ");
lcd.print(DHT.temperature);
lcd.print((char)223);
lcd.print("C");
lcd.setCursor(0,1);//Set the cursor on the first column and 2nd row.
lcd.print("Humidity: ");
lcd.print(DHT.humidity);
lcd.print("%");
delay(1000);
}
