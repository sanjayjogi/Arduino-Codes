#include "ESP8266WiFi.h" 
#include "FirebaseArduino.h" 
#include "DHT.h" 

#define FIREBASE_HOST "todo-cf80c-default-rtdb.firebaseio.com" 
#define FIREBASE_AUTH "L5usVAyTvyr1xkwtDG2YKiFuXiokJUMroMDfAO1o" 

#define WIFI_SSID "Sanjay" 
#define WIFI_PASSWORD "UMXUPBTT"
#define DHTPIN D5 
#define DHTTYPE DHT11 
DHT dht (DHTPIN, DHTTYPE);

void setup () {
  Serial.begin (9600);
  delay (1000);
  WiFi.begin (WIFI_SSID, WIFI_PASSWORD); 
  Serial.print ("Connecting to");
  Serial.print (WIFI_SSID);
  while (WiFi.status()!= WL_CONNECTED) {
    Serial.print (".");
    delay (500);
  }
  Serial.println ();
  Serial.print ("Connected to");
  Serial.print (" ");
  Serial.println (WIFI_SSID);
  Serial.print ("IP Address is:");
  Serial.println (WiFi.localIP ()); 
  Firebase.begin (FIREBASE_HOST, FIREBASE_AUTH); 
  dht.begin (); 
}
void loop () 
{
  float h = dht.readHumidity (); 
  float t = dht.readTemperature (); 
    
  if (isnan (h) || isnan (t)) {
    Serial.println ("Failed to read from DHT sensor!");
    return;
  }  
  Serial.print ("Humidity: "); Serial.print (h);
  float firebaseHumid = float (h); 
  Serial.print ("% ; Temperature: "); Serial.print (t); Serial.println ("°C");
  float firebaseTemp = float (t); 
  delay (5000);
  
  Firebase.pushFloat ("Humidity", firebaseHumid); 
  Firebase.pushFloat ("Temperature", firebaseTemp);   
} 
