

var perfval; 
var data;
var performanceid = 99;
var perf_id;
var lati = 32.333;
var longi = 22.222;
var geoInter;
var counter = 0;
var accurate = 99;

var lati_array = new Array();
var longi_array = new Array();

function restartThings() {

	counter = 0;
	perf_id = 0;
	startUp();
}

function startUp() {

	document.getElementById("stepnum").innerHTML = "Step 0/4";
	document.getElementById("step0").style.display = "block"; 
	document.getElementById("todo0").style.display = "block"; 	
	
	document.getElementById("step1").style.display = "none"; 
	document.getElementById("todo1").style.display = "none"; 
	
	document.getElementById("step2a").style.display = "none";
	document.getElementById("step2b").style.display = "none";
	document.getElementById("latlon").style.display = "none";
	document.getElementById("gps-map").style.display = "none"; 
	document.getElementById("todo2").style.display = "none"; 
	
	document.getElementById("step3").style.display = "none"; 
	document.getElementById("latlon2").style.display = "none"; 
	document.getElementById("gps-map2").style.display = "none"; 
	document.getElementById("stopwatch").style.display = "none"; 
	document.getElementById("todo3").style.display = "none"; 

	document.getElementById("step4").style.display = "none"; 
	document.getElementById("todo4").style.display = "none"; 
}

//POSTS PERFORMANCE TITLE TO MYSQL_CONNECT		STEP 1
jQuery(function($)	{
					var field1 = $('#field1');
					$('#todo1').click(function(){
						if(!field1.val()){
							//alert("Please enter a value");
							field1.focus();
							return;
						}
					
					jQuery.ajax({
					url: 'mysql_connect.php',
					type: 'post',
					data: 'perfval=' + field1.val(),
					success: function(results){
						performanceid = results;
						perf_id = parseInt(performanceid);
						updateStep(2);
						beginTracking();
					}
				});
		});
	});

//POSTS LAT/LONG TO MYSQL_CONNECT_GEO			STEP 3
jQuery(function($)	{	
	$('#tracker').click(function(){	
		var callAjax = function(){
		
			testCounter();
			
			$.ajax({
				url: 'mysql_connect_geo.php',
				type: 'post',
				data: 'perf_id=' + perf_id + '&lati=' + lati + '&longi=' + longi + '&accurate=' + accurate,
				success: function(results){
					var id2 = results;
					}
				});
			};
		geoInter = setInterval(callAjax, 3000);
		});
	});
	
function updateStep(x) {

	if(x == 1) {
		document.getElementById("stepnum").innerHTML= "Step " + x + "/4";

		document.getElementById("step0").style.display = "none"; 
		document.getElementById("todo0").style.display = "none"; 	
		
		document.getElementById("step1").style.display = "block"; 
		document.getElementById("todo1").style.display = "block"; 
	}
	
	else if(x == 2) {
		document.getElementById("stepnum").innerHTML= "Step " + x + "/4";	
		
		document.getElementById("step1").style.display = "none"; 
		document.getElementById("todo1").style.display = "none"; 
		
		document.getElementById("step2a").style.display = "block"; 
		document.getElementById("step2b").style.display = "block"; 
		document.getElementById("latlon").style.display = "block"; 
		document.getElementById("todo2").style.display = "block"; 
		document.getElementById("gps-map").style.display = "block"; 
		
	}

	else if(x == 3) {
	
		document.getElementById("stepnum").innerHTML= "Step " + x + "/4";	
		
		document.getElementById("step2a").style.display = "none"; 
		document.getElementById("step2b").style.display = "none"; 
		document.getElementById("latlon").style.display = "none"; 
		document.getElementById("gps-map").style.display = "none"; 
		document.getElementById("todo2").style.display = "none"; 
		
		document.getElementById("step3").style.display = "block"; 
		document.getElementById("todo3").style.display = "block"; 
		document.getElementById("latlon2").style.display = "block"; 
		document.getElementById("gps-map2").style.display = "block"; 
		document.getElementById("stopwatch").style.display = "block"; 
		
		//startGPS();
		
		}

	else if(x == 4) {
		
		stopGPS();
		
		document.getElementById("stepnum").innerHTML= "Step " + x + "/4";	

		document.getElementById("step3").style.display = "none"; 
		document.getElementById("latlon2").style.display = "none"; 
		document.getElementById("gps-map2").style.display = "none"; 
		document.getElementById("stopwatch").style.display = "none"; 
		document.getElementById("todo3").style.display = "none"; 

		document.getElementById("step4").style.display = "block"; 		
		document.getElementById("todo4").style.display = "block"; 
		
		}
}

function beginTracking() {
	getuserLocation();
	}

function beginTracking2() {
	counter++;
	getuserLocation2();
	}
	
function showuserPosition(position) {
		latlon=position.coords.latitude.toFixed(4) + "," + position.coords.longitude.toFixed(4);
		lati = position.coords.latitude.toFixed(4);
		longi = position.coords.longitude.toFixed(4);
		accurate = Math.round(position.coords.accuracy);
		document.getElementById("latlon").innerHTML= latlon  + "<br>Accurate within " + accurate + " meters";
	 	
        var img_url="http://maps.googleapis.com/maps/api/staticmap?center="+latlon+"&zoom=17&size=150x150&sensor=false";
        document.getElementById("gps-map").innerHTML="<img src='"+img_url+"'>";
		//sendGeo();
    }

function getuserLocation(){         
	navigator.geolocation.getCurrentPosition(showuserPosition,showbrowserError);  
    }
	
function showbrowserError(error){
	alert("Error");
}

function showbrowserError2(error){
	alert("Error");
}

function beginTracking2() {
	getuserLocation2();
	}
	
function startGPS() {
	
	geoInter = setInterval("testCounter()", 1000);
}

function testCounter() {
counter++;
var timepassed = counter * 3;

document.getElementById("stopwatch").innerHTML = "<center>Time tracking: " + timepassed + " seconds</center>";
getuserLocationTwo();
}
function stopGPS() {	
	clearInterval(geoInter);
}

function getuserLocationTwo(){      
	navigator.geolocation.getCurrentPosition(showuserPositionTwo,showbrowserError2, {enableHighAccuracy: true});  
    }

function showuserPositionTwo(position) {
	latlon2=position.coords.latitude.toFixed(4) + "," + position.coords.longitude.toFixed(4);
	lati = position.coords.latitude.toFixed(4);
	longi = position.coords.longitude.toFixed(4);
	accurate = Math.round(position.coords.accuracy);
	document.getElementById("latlon2").innerHTML = "<center>" + latlon2 + "<br>Accurate within " + accurate + " meters</center>";
							
	lati_array.push(lati);
	longi_array.push(longi);
	
	var img_url="http://maps.googleapis.com/maps/api/staticmap?center="+latlon2+"&zoom=17&size=150x150&sensor=false";
	document.getElementById("gps-map2").innerHTML="<center><img src='"+img_url+"'></center>";
	//sendGeo(); 
}
				
