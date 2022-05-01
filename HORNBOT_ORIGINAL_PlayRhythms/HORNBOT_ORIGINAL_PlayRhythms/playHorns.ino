

//car doubles as array index for hornsLongitude[]
void playLongitude(int car, int l) {

  //make sure that this horn is supposed to play (hval)
  if(hval[car] == 1) {
  //hornpins.h for the first parameter; 
  digitalWrite(hornsLongitude[car], onoff[carsLongitude[car][l][counter]]);
  }  
  else {
  digitalWrite(hornsLongitude[car], LOW);
  }
    
}


//car doubles as array index for hornsLattitude[]
void playLattitude(int car, int l) {
  
  if(hval[car] == 1) {
  digitalWrite(hornsLattitude[car], onoff[carsLattitude[car][l][counter]]);
  }
  else {
    digitalWrite(hornsLattitude[car], LOW);
  }
    
}
