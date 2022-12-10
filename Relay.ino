int relayInput = 2; // the input to the relay pin

void setup() {
  pinMode(relayInput, OUTPUT); 
}

void loop() {
  digitalWrite(relayInput, HIGH); 
  delay(1000);
  digitalWrite(relayInput, LOW);
  delay(1000);
}
