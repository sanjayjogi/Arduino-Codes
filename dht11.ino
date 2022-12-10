#include <ESP8266WiFi.h>
#include "DHT.h"        
 
#define DHTTYPE DHT11   
#define dht_dpin 0      //D3 pin of nodemcu

const char* ssid = "Your SSID";
const char* password = "Your Wifi Password";


DHT dht(dht_dpin, DHTTYPE); 

void setup(void)
{ 
  dht.begin();
  Serial.begin(9600);
  delay(10);
  
  // Connect to WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);     //Begin WiFi
  Serial.println("");
  Serial.println("WiFi connected");
}



void loop() {

 float h = dht.readHumidity();  //Humidity level
 float t = dht.readTemperature();  //Temperature in celcius 
 float f = (h * 1.8) + 32;;  //Temperature in fahrenheit

  Serial.print("Temperature in Celsius =");
  Serial.println(t);
  Serial.print("Temperature in Fahrenheit =");
  Serial.println(f);
  Serial.print("Humidity =");
  Serial.println(h);
}
