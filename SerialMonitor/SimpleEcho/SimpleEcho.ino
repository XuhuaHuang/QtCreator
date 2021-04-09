void setup() {
  // initialize serial:
  Serial.begin(9600);
}

void loop() {
    while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    Serial.print("Received: ");
    Serial.println(inChar); 
  }
}
