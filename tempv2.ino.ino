#include <LiquidCrystal_I2C.h>




#include <SimpleDHT.h>

//Declaring digital pin no 6 as the dht11 data pin

int pinDHT11 = 6; // change to a digital pin of your liking for added convenience
SimpleDHT11 dht11; // tells the arduino the sensor we are using is the dht 11

//Declaring the lcd pins

LiquidCrystal_I2C lcd(0x27,16,2); // change 0x27 to the value you get when you use the I2c scanner program. Once this is done the microcontroller we use will know how to interface with the lcd
void setup() {
  
  Serial.begin(9600);
 

  
  lcd.init(); //initializing lcd
  lcd.clear(); //clearing lcd
  lcd.backlight(); // turns the lcd backlight on
   
   
}

void loop() {

  //These serial codes are for getting readings on the Serial Monitor, plus the LCD display, Because the serial monitor provides a more detailed interface
  
  
  Serial.println("DHT11 Sensor Data");
  
 
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;

  //This bit will tell our Arduino what to do if there is some sort of an error at getting readings from our sensor
  if ((err = dht11.read(pinDHT11, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("No sensor found, Check wiring , err="); Serial.println(err);delay(1000); // When there is no data recived from the sensor this error will apear
    return;
  }
  
  Serial.print("Readings: ");
  Serial.print((int)temperature); Serial.print(" Celcius, "); // Writes the tempreature data into the serial monitor
  Serial.print((int)humidity); Serial.println(" %"); // Writes the humidity data into the serial monitor
 

  lcd.clear(); // this will clear everything on the lcd so we can print to it
 
  //Choosing the first line and row
  lcd.setCursor(0,0);
  //Typing Temp: to the first line starting from the first row
  lcd.print("Tempreature: ");
  //Typing the temperature readings after "Temp: " 
  lcd.print((int)temperature);
  lcd.print(" C");
  //Choosing the second line and first row
  lcd.setCursor(0,1);
  //Typing Humidity(%): to the second line starting from the first row
  lcd.print("Humidity: ");
  //Typing the humidity readings after "Humidity(%): "
  lcd.print((int)humidity);
  lcd.print(" %"); //prints the % symbol next to "Humidity"
 
  
  
  
  delay(850); // after 0.85 seconds the cycle will repeat can be adjusted accordingly to the sensor
}
