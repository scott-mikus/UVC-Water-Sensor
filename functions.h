const int PowerPin = 2;
const int setPoint = 35;
int pressure = 0;
int i = 0;
int readings = 20;
String lamp = "Off";

void pressRead() {
  for (int i = 0; i <= readings; i++) {
    pressure = analogRead(A6);
    pressure = map(pressure, 100, 1024, 0, 100);
    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" psi");
    Serial.print("UVC Lamp ");
    Serial.println(lamp);
    delay(500);
  }
}
void uvc() {
  if (pressure <= setPoint) {
    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" psi");
    lamp = "On";
    Serial.print("UVC Lamp ");
    Serial.println(lamp);
    digitalWrite(PowerPin, HIGH);
  }

  else {
    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" psi");
    lamp = "Off";
    Serial.print("UVC Lamp ");
    Serial.println(lamp);
    digitalWrite(PowerPin, LOW);
  }
}
