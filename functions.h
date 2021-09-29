const int PowerPin = 2;
int pres = 0;
int i = 0;
String lamp = "Off";

void pressRead() {
  for (int i = 0; i <= 14; i++) {
    pres = analogRead(A6);
    pres = map(pres, 100, 1024, 0, 100);
    Serial.print("Pressure: ");
    Serial.print(pres);
    Serial.println(" psi");
    Serial.print("UVC Lamp ");
    Serial.println(lamp);
    delay(500);
  }
}
void uvc() {
  if (pres <= 35) {
    Serial.print("Pressure: ");
    Serial.print(pres);
    Serial.println(" psi");
    lamp = "On";
    Serial.print("UVC Lamp ");
    Serial.println(lamp);
    digitalWrite(PowerPin, HIGH);
  }

  else {
    Serial.print("Pressure: ");
    Serial.print(pres);
    Serial.println(" psi");
    lamp = "Off";
    Serial.print("UVC Lamp ");
    Serial.println(lamp);
    digitalWrite(PowerPin, LOW);
  }
}
