<?php 

$perf_id = (int)$_POST['perf_id']; 
$lati = (double)$_POST['lati']; 
$longi = (double)$_POST['longi']; 
$accurate = (int)$_POST['accurate']; 
  
$com=mysqli_connect("localhost","root","arievi","hornbot");
// Check connection
if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }
mysqli_query($com,"INSERT INTO performance_data (perf_id,latitude,longitude,accurate) VALUES ($perf_id,$lati,$longi,$accurate)");

echo "Working!!";

?>  
