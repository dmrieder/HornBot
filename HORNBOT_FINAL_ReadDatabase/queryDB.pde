
void queryDB() {

  background(255);
  
  int counter = 0;
  
  dbconnection = new MySQL( this, "mysql.raymondrhythms.com:3306", database, user, pass );
        
    if ( dbconnection.connect() )
    {
        dbconnection.query("SELECT * FROM %s", table);
        
        while (dbconnection.next())
        {
            for(int j = 0; j < 3; j++) {
              if(dbconnection.getInt(columns[j]) != cars[counter][j]) {
                change[counter] = true;
                }
                else {
                  change[counter] = false;
                }
            }
                
            cars[counter][0] = dbconnection.getInt(columns[0]); //carId
            cars[counter][1] = dbconnection.getInt(columns[1]); //active?              
            cars[counter][2] = dbconnection.getInt(columns[2]); //quadrant                
               
            counter++;
        }
        
    }
    else
    {
        println("Something went wrong?!");
    }
     updateArduino();
     dbconnection.close();
}

