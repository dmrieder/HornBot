
void updateArduino() {

  String commandline = "";
  
  if((sumup == 0) && (!flag)) {
//    flag = true;
//    myPort.write("X");
//    println("******TURNED ALL HORNS OFF******");

  }
  
  else if(change[counter2]) {
    flag = false;
    commandline = "B," + counter2 + "," + quads[cars[counter2][2]][0] + "," + quads[cars[counter2][2]][1] + "," + "H," + counter2 + "," + cars[counter2][1];

    myPort.write(commandline);
    
    println("******CHANGE WRITTEN TO ARDUINO******");
    println(commandline);
    println("");
    
    commandline = "";
  } 

}




