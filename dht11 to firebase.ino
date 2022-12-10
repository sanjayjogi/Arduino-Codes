#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <ESP8266WiFi.h>
#include "DHT.h"       

#define DHTTYPE DHT11   
#define dht_dpin 0      //D3 pin of nodemcu
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""
#define WIFI_SSID ""
#define WIFI_PASSWORD ""

DHT dht(dht_dpin, DHTTYPE); 

void setup() {
  dht.begin();
  Serial.begin(9600);
  delay(10);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {

 float h = dht.readHumidity();  
 float t = dht.readTemperature(); 
 float f = (h * 1.8) + 32;;  
 
  Serial.print("Temperature in Celsius =");
  Serial.println(t);
  Serial.print("Temperature in Fahrenheit =");
  Serial.println(f);
  Serial.print("Humidity =");
  Serial.println(h);
  
  // set value
  Firebase.setFloat("Temperature",t);
  Firebase.setFloat("Humidity",h);
  
  // handle error
  if (Firebase.failed()) {
      Serial.print("couldnt push");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
  
  // update value
  Firebase.setFloat("Temperature",t);
  Firebase.setFloat("Humidity",h);
  
  // handle error
  if (Firebase.failed()) {
      Serial.print("couldnt push");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);

  // handle error
  if (Firebase.failed()) {
      Serial.print("setting /truth failed:");
      Serial.println(Firebase.error());  
      return;
  }
  delay(1000);
}
