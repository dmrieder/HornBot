

void pTitleID() {
  
    String user     = "rjlloyd";
    String pass     = "lobsterman1";
    String database = "hornbot";
 
    msql = new MySQL( this, "mysql.raymondrhythms.com:3306", database, user, pass );
    
    if ( msql.connect() )
    {
      msql.query( "SELECT id FROM performances WHERE performance_title = '%s'", performanceTitle);
      msql.next();
      performanceTitleID = msql.getInt("id");
       
    }
    else
    {
        // connection failed !
    }
}
