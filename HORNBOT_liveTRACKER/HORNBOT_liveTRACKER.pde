import de.bezier.data.sql.*;
import processing.serial.*;

//http://tools.chass.ncsu.edu/phpmyadmin/
//root
//NNhVhswUFFaMHdBu
MySQL msql;
String   performanceTitle;
int      performanceTitleID = 0;
Boolean  endrun = false;
int      counter = 0;
int      atcam, atwalmart;
int      lastpoint = 0;
color    bg = #ff0000;
float[]  corners = new float[4];

Serial port;
String data = "";
String[] splitData;

void setup() {
  size(500,500);
  
  performanceTitle = "LIVETEST1_DELETEME";
    corners[0] = 35.789725;      //top left lat
    corners[1] = -78.673789;     //top left long

    corners[2] = 35.777436;      //bottom right lat
    corners[3] = -78.66439;     //bottom right long
    
    atcam = 0;
    atwalmart = 0;
    
  pTitle();
  
  pTitleID();
  
  port = new Serial(this, Serial.list()[1], 9600);
  port.clear();
  
  port.bufferUntil(10);
  
}

void draw() {
  background(bg);
 
  if(counter > 1) {
 // drawGrid();
  }
  else if(endrun) {
    exit();
  }
  
 

}

void serialEvent(Serial port) {
 
 data = port.readString();
 parseData(data.trim());
 port.clear();

  
}

void mousePressed() {
  lastpoint = 1;
}

