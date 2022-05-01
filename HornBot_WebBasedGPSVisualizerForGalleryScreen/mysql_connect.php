<?php 

$perfval = $_POST['perfval']; 
  
$dbc=mysqli_connect("localhost","root","arievi","hornbot");
// Check connection
if (mysqli_connect_errno())
  {
  echo "Failed to connect to MySQL: " . mysqli_connect_error();
  }
$q1 = "INSERT INTO performances (performance_title) VALUES ('$perfval')";
  
mysqli_query($dbc,$q1);

$q2 = "SELECT 'id' FROM 'performances' WHERE 'performance_title' = $perfval";

    $q2 = "SELECT id
            FROM performances
            WHERE performance_title = '{$perfval}'
            ";
    $run = mysqli_query($dbc, $q2);
    $result = mysqli_fetch_assoc($run);
    echo $result['id'];

?>  
