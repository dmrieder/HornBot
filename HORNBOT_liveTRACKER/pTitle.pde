
void pTitle() {
  
    String user     = "rjlloyd";
    String pass     = "lobsterman1";
    String database = "hornbot";
 
    msql = new MySQL( this, "mysql.raymondrhythms.com:3306", database, user, pass );
    
    if ( msql.connect() )
    {
      msql.query( "INSERT INTO performances(performance_title,tl_lat,tl_long,br_lat,br_long,atCAM,atWalmart) VALUES ('%s',%s,%s,%s,%s,%s,%s)", performanceTitle,corners[0],corners[1],corners[2],corners[3],atcam,atwalmart);
 
       
       performanceTitleID = 121;
       
    }
    else
    {
        // connection failed !
    }
}
