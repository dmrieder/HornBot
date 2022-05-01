
void hornValWrite() {
  
  Serial.println("Updated readout (0 = off, 1 = on)");
    Serial.print("Horn 0 > ");
    Serial.println(hval[0]);
    Serial.print("Car 1 > ");
    Serial.println(hval[1]);
    Serial.print("Car 2 > ");
    Serial.println(hval[2]);
    Serial.print("Car 3 > ");
    Serial.println(hval[3]);

}
