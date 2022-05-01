
void mysqlCall() {
  
    String user     = "rjlloyd";
    String pass     = "lobsterman1";
    String database = "hornbot";
 
    msql = new MySQL( this, "mysql.raymondrhythms.com:3306", database, user, pass );
    
    if ( msql.connect() )
    {
      msql.query( "INSERT INTO performance_data(perf_id, latitude, longitude, altitude, counter, lastPoint) VALUES (%s, %s, %s, %s, %s, %s)", performanceTitleID, splitData[0], splitData[1], splitData[3], counter, lastpoint);
       // msql.query( "SELECT COUNT(*) FROM performance_data" );
       // msql.next();
       // println( "number of rows: " + msql.getInt(1) );
       
    }
    else
    {
        // connection failed !
    }
    msql.close();
    counter++;
    println("Count: " + counter);
    println(splitData[0] + ", " + splitData[1] + ", " + splitData[3] + ", " + lastpoint);
   
    
}
