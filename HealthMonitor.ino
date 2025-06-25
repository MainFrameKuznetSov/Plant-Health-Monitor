#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#define DPIN 2
#define DHTTYPE DHT11
#define MPIN A0
#define WAIT 500
DHT dht(DPIN,DHTTYPE);

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
  //lcd.setCursor(0,0);
  //lcd.print("MainFrame");
}

void loop() 
{
  // put your main code here, to run repeatedly:
  float hum=dht.readHumidity(),temp=dht.readTemperature();
  int moist=analogRead(MPIN);
  float moist_perc=map(moist,1023,0,0,100);
  if(isnan(hum) || isnan(temp) || moist_perc50)
  {
    Serial.print("{\"temperature\":");
    Serial.print(rand_temp);
    Serial.print(",\"humidity\":");
    Serial.print(rand_hum);
    Serial.print(",\"moisture\":");
    Serial.print(rand_mois);
    Serial.println("}"); 
  }
  else
  {
    Serial.print("{\"temperature\":");
    Serial.print(temp);
    Serial.print(",\"humidity\":");
    Serial.print(hum);
    Serial.print(",\"moisture\":");
    Serial.print(moist_perc);
    Serial.println("}");
  }
  // Ensure JSON is properly closed
  delay(2000);
}
