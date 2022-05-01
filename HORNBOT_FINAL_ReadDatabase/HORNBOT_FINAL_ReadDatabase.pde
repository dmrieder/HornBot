import processing.serial.*;
import de.bezier.data.sql.*;

Timer timer;
MySQL dbconnection;
int[][] cars = new int[4][3];

String[] columns = { "carId", "active", "quadrant" };
Boolean[] change = { false, false, false, false };

int counter2;
int totalcount;
int sumup;

Boolean flag;

String user       = "rjlloyd";
String pass       = "lobsterman1";
String database   = "hornbot";
String table      = "hornData";

String serialSend;
Serial myPort;

Boolean flipflop = true;

int[][] quads = {
                        // Left to right, top to bottom; lat, long
                        {0,0}, // 0
                        {0,1}, // 1
                        {0,2}, // 2
                        {0,3}, // 3
                        {1,0}, // 4
                        {1,1}, // 5
                        {1,2}, // 6
                        {1,3}, // 7
                        {2,0}, // 8
                        {2,1}, // 9
                        {2,2}, // 10
                        {2,3}, // 11
                        {3,0}, // 12
                        {3,1}, // 13
                        {3,2}, // 14
                        {3,3}, // 15
                        {4,0}, // 16
                        {4,1}, // 17
                        {4,2}, // 18
                        {4,3}  // 19
                       };
                       
void setup()
{
  background(0);
  size(500, 500);

  myPort = new Serial(this, Serial.list()[0], 9600);
 
  counter2 = 0;
  totalcount = 0;
  
  flag = true;
  
  timer = new Timer(500);
  timer.start();

}

void draw()
{
  if (timer.isFinished()) {
    totalcount++;
  
  sumup = 0;
  
 println("------------------------------------------------" + totalcount + "/" + counter2);   
    
    for(int t = 0; t < 4; t++) {
   //   println("Car #" + t);
      sumup += cars[t][1];
      for(int tt = 1; tt < 3; tt++) {
        
   //     println(columns[tt] + ": " + cars[t][tt]);
      }
      
    }
     
    if(sumup == 0 && !flag) {
     flag = true;
     myPort.write("X");
     println("******TURNED ALL HORNS OFF******");
    }
    
    println("sumup: " + sumup);
    
    if(counter2 > 2) {
      queryDB();
      counter2 = 0;
    }
    else {
          updateArduino();
          counter2++;
    }
    
    timer.start();
    }
    
}
