
//Initializes vars for the 8 pins for the horns
#include "hornpins.h"

//All of the various rhythm data in separate files
#include "carsData.h"

//Translates 0-20 quadrants to lat/long zones
#include "quadrants.h"

int limit, counter, pace, car, ticktock;

//FOR THE SERIAL COMM
  //read the next char of data from serial
  char sdata;
  
  //store data
  int rtdata[6];  

  boolean hval[4] = {1,1,1,1};
  String v[2] = {"off", "on" };
  
  int datacounter = 0;  
  
  char testString;
  
  //are you actively reading after & was received?
  boolean amper = false;

  //Sample quadrants for testing
  int carsDriving[4] = {0, 0, 0, 0};

//END OF SERIAL COMM

//translates 0s and 1s to pinMode
int onoff[2] = {LOW, HIGH};

void setup() {                
  
  initializePins();
  
  Serial.begin(9600);
  
  //96 / 8 = 12 seconds
  limit = 96;
  
  //begin counting from 0;
  counter = 0;
  
  //1000 / 8 = 125, which is a 1/8th second pause or note
  pace = 125;
  
}


void loop() {

  //Reset counter to 0 if limit is reached
  if(counter >= limit) {
    
    counter = 0;
    ticktock++;
    
    if(ticktock >= 10) {
      ticktock = 0;
    }
    
  }

 //Update rhythms the program plays
 serialRead();
   
  for(int i = 0; i < 4; i++) {
        
      //Send car# and lat-specific zone #
      playLongitude(i, quadrants2[carsDriving[i]][0]);
    
      //Send car# and long-specific zone #
      playLattitude(i, quadrants2[carsDriving[i]][1]);    
      }

  //count up by one
  counter++;  
  
  //Hold for 1/8th of a minute, or 125 milliseconds
  delay(pace);

 
}

