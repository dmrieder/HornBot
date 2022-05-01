
void serialRead() {
  
  if (Serial.available() > 0) {
    
    sdata = Serial.read();

    //B means beginning of message
    //THIS IS THE ONE THAT UPDATES EVERYTHING
    if(sdata == 66) {
 
      rtdata[0] = Serial.parseInt();    
      rtdata[1] = Serial.parseInt();
      rtdata[2] = Serial.parseInt();

      carsDriving[rtdata[0]] = quadrants[rtdata[1]][rtdata[2]];
      
      Serial.print("NEW QUAD: ");
      Serial.println(quadrants[rtdata[1]][rtdata[2]]);

      
      gpsWrite();
      
    }  
    
    //T means print out current settings    
    if(sdata == 84) {
  
      gpsWrite();
      
    }
    
    //H means turn on | off a specific pair of horns   
    if(sdata == 72) {

      rtdata[0] = Serial.parseInt();    
      rtdata[1] = Serial.parseInt();
      rtdata[2] = Serial.parseInt();
      
      hval[rtdata[0]] = rtdata[1];
  
      gpsWrite();      
      
    }   
 
    //X means turn OFF all horns   
    if(sdata == 88) {
      
      rtdata[0] = Serial.parseInt();    
      rtdata[1] = Serial.parseInt();
      rtdata[2] = Serial.parseInt();
      
      hval[0] = 0;
      hval[1] = 0;
      hval[2] = 0;
      hval[3] = 0;

      gpsWrite();
      
    }   
 
    //Y means turn ON all horns 
    if(sdata == 89) {

      rtdata[0] = Serial.parseInt();    
      rtdata[1] = Serial.parseInt();
      rtdata[2] = Serial.parseInt();
           
      hval[0] = 1;
      hval[1] = 1;
      hval[2] = 1;
      hval[3] = 1;
                        
      gpsWrite();
      
    }   

    //R means reset counter and ticktock  
    if(sdata == 82) {

      rtdata[0] = Serial.parseInt();    
      rtdata[1] = Serial.parseInt();
      rtdata[2] = Serial.parseInt();
            
      counter = 0;
      ticktock = 0;      
      gpsWrite();
      
    } 
 
 }

}
