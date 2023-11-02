void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // tone(13, HIGH);
  // delay(1000);
  // digitalWrite(13, LOW);
  // delay(1000);
  tone(11, 262);
  delay(1000);
  noTone(11);
  delay(1000);
}
