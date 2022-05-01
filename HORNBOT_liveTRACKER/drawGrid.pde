
void drawGrid() {
//  float testlat = 40.826556;
//  float testlong = -73.693803;
 
  float testlat = float(splitData[0]);
  float testlong = float(splitData[1]);
  
  stroke(255);
  
  for(int x = 1; x < 6; x++) {          
     line(50,50 * x,250,50 * x);  
     if(x < 6) {
     line(50 * x,50,50 * x,250);
     }
  }
  float xx = map(float(splitData[0]), corners[2], corners[0], 0, 300);  
  float yy = map(float(splitData[1]), corners[3], corners[1], 0, 300);  
  
  //println(splitData[0] + ", " + splitData[1] + ", " + xx + ", " + yy);
  
  fill(0);
  stroke(0);
  ellipse(xx/2,yy/2, 10.0,10.0);

  
  
}
