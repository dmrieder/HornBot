
void gpsWrite() {
  
  Serial.println("Updated readout");
    Serial.print("Car 0 > ");
    if(hval[0] == 0) {
      Serial.println("Car 0 OFF");
    }
    else {
      Serial.println(carsDriving[0]);
    }
    
    Serial.print("Car 1 > ");
    if(hval[1] == 0) {
      Serial.println("Car 1 OFF");
    }
    else {
      Serial.println(carsDriving[1]);
    }
    
    Serial.print("Car 2 > ");
    if(hval[2] == 0) {
      Serial.println("Car 2 OFF");
    }
    else {
      Serial.println(carsDriving[2]);
    }
    
    Serial.print("Car 3 > ");
    if(hval[3] == 0) {
      Serial.println("Car 3 OFF");
    }
    else {
      Serial.println(carsDriving[3]);
    }
    
}
