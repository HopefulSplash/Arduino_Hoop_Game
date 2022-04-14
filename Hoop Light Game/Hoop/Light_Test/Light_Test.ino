  int Pin = 4;

  


void setup() {
  pinMode(Pin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(Pin, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(Pin, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
