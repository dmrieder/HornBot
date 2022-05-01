

void parseData(String s) {
 
 if(s.indexOf("*") == -1) {
   bg = #00ff00;
   splitData = split(s, ';');
  
 
   if(splitData.length == 4) {
     mysqlCall();
     
     if(endrun) {
       exit();
     }
   }
 }
 else {
   bg = #ff0000;
 }
 
}
