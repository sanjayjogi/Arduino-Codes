void setup() {     
  pinMode(A0,INPUT);
  Serial.begin(9600);
}
 
 
void loop() {
  int moisture_raw = analogRead(A0);
  Serial.print(moisture_raw);
  float moisture= ( 100 - ( (moisture_raw/1023.00) * 100 ) );
  Serial.println("Moisture Sensor Value: ");
  Serial.print(moisture);
  delay(2000);
}
