<?php
    /*
    All Emoncms code is released under the GNU Affero General Public License.
    See COPYRIGHT.txt and LICENSE.txt.

    ---------------------------------------------------------------------
    Emoncms - open source energy visualisation
    Part of the OpenEnergyMonitor project:
    http://openenergymonitor.org
    */

    global $path, $embed;
?>

<script language="javascript" type="text/javascript" src="<?php echo $path;?>Lib/flot/jquery.flot.min.js"></script>
<script language="javascript" type="text/javascript" src="<?php echo $path;?>Lib/flot/jquery.flot.time.min.js"></script>
<script language="javascript" type="text/javascript" src="<?php echo $path; ?>Lib/flot/jquery.flot.selection.min.js"></script>
<script language="javascript" type="text/javascript" src="<?php echo $path; ?>./jquery.flot.rose.js"></script>
<script language="javascript" type="text/javascript" src="<?php echo $path; ?>./JUMFlot.min.js"></script>

<script language="javascript" type="text/javascript" src="<?php echo $path; ?>Modules/vis/visualisations/vis.helper.js"></script>
<script language="javascript" type="text/javascript" src="<?php echo $path; ?>Lib/flot/date.format.js"></script>

<div id="vis-title"></div>

<div id="placeholder_bound" style="width:100%; height:400px; position:relative; ">
    <div id="placeholder" style="position:absolute; top:0px;"></div>
    <div id="graph_buttons" style="position:absolute; top:18px; left:32px; opacity:0.5;">

        <div class='btn-group'>
            <button class='btn time' type='button' time='1'>D</button>
            <button class='btn time' type='button' time='7'>W</button>
            <button class='btn time' type='button' time='30'>M</button>
            <button class='btn time' type='button' time='365'>Y</button>
        </div>

        <div class='btn-group'>
            <button id='zoomin' class='btn' >+</button>
            <button id='zoomout' class='btn' >-</button>
            <button id='left' class='btn' ><</button>
            <button id='right' class='btn' >></button>
        </div>

        <div class='btn-group'>
            <button class='btn interval' type='button' interval='d'><span id="textunitD"></span>/D</button>
            <button class='btn interval' type='button' interval='m'><span id="textunitM"></span>/M</button>
            <button class='btn interval' type='button' interval='y'><span id="textunitY"></span>/Y</button>
        </div>

    </div>

    <h3 style="position:absolute; top:0px; right:25px;"><span id="stats"></span></h3>
</div>

<script id="source" language="javascript" type="text/javascript">


console.log(urlParams);

var wsfeedid = "<?php echo $wsfeedid; ?>";
var wdfeedid = "<?php echo $wdfeedid; ?>";
var path = "<?php echo $path; ?>";
var apikey = "<?php echo $apikey; ?>";
var embed = <?php echo $embed; ?>;
var valid = "<?php echo $valid; ?>";

var feedid = urlParams.feedid;

var barWidth = urlParams.barwidth;
if (barWidth==undefined || barWidth=='') barWidth = "5";

var interval = 3600*24;

var top_offset = 0;
var placeholder_bound = $('#placeholder_bound');
var placeholder = $('#placeholder');

var width = placeholder_bound.width();
var height = width * 0.5;

placeholder.width(width);
placeholder_bound.height(height);
placeholder.height(height-top_offset);

if (embed) placeholder.height($(window).height()-top_offset);
 
    
var intervalcode=interval;
if (intervalcode==0 || intervalcode=='y' || intervalcode=='m' || intervalcode=='d') interval = 3600*24;

var intervalms = interval * 1000;

var timeWindow;

if (intervalcode=='y')
   timeWindow = 3600000*24*365*5;
else if (intervalcode=='m')
   timeWindow = 3600000*24*365;
else if (intervalcode=='d')
   timeWindow = 3600000*24*10;
else
   timeWindow = 3600000*24*31;

view.start = +new Date - timeWindow;
view.end = +new Date;

var data = [];

$(function() {

    if (embed==false) $("#vis-title").html("<br><h2>Bar graph: "+feedname+"<h2>");
    draw();
    
    $("#zoomout").click(function () {view.zoomout(); draw();});
    $("#zoomin").click(function () {view.zoomin(); draw();});
    $('#right').click(function () {view.panright(); draw();});
    $('#left').click(function () {view.panleft(); draw();});
    $('.time').click(function () {view.timewindow($(this).attr("time")); draw();});
    $('.interval').click(function () {

		intervalcode=$(this).attr("interval");

		if (intervalcode==0 || intervalcode=='y' || intervalcode=='m' || intervalcode=='d') 
	        	interval = 3600*24;
	
		intervalms = interval * 1000;
	
		if (intervalcode=='y')
		   timeWindow = 3600000*24*365*5;
		else if (intervalcode=='m')
		   timeWindow = 3600000*24*365;
		else if (intervalcode=='d')
		   timeWindow = 3600000*24*10;
		else
		   timeWindow = 3600000*24*31;
	
		view.start = +new Date - timeWindow;
		view.end = +new Date;

		draw();
    });


    function draw()
    {
		var wsdata = [];
		var wddata = [];
		var datamax = 20;

		$.ajax({                                      
            url: path+'feed/average.json',                         
            data: "id="+wsfeedid+"&start="+view.start+"&end="+view.end+"&interval="+interval,
            dataType: 'json',
            async: false,                      
            success: function(data_in) { wsdata = data_in; } 
        });

		$.ajax({                                      
            url: path+'feed/average.json',                         
            data: "id="+wdfeedid+"&start="+view.start+"&end="+view.end+"&interval="+interval,
            dataType: 'json',
            async: false,                      
            success: function(data_in) { wddata = data_in; } 
        });

		var d1 = [ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
		var d2 = [ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
		var d3 = [ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0];
		var d4 = [[10,0-barWidth/2,0+barWidth/2]]

		for (var i = 0; i< wsdata.length; i++){
			var line = wddata[i];
			var line2 = wsdata[i];
			var index = parseInt(line[1]);

			if (line2[1]<3) d1[index]=d1[index]+1;
				else if (line2[1]>=3 && line2[1]<8)d2[index]=d2[index]+1;
					else d3[index]=d3[index]+1;
		}

		// create stacked bars
		for (var j = 0; j<d1.length; j++){
			d2[j]=d2[j]+d1[j];
			d3[j]=d3[j]+d2[j];
		}
		
		
		
		var options = {
        series:{ 
            rose: { 
                active:true,
//                drawGrid:{
//                    gridMode: "ticks",
//                    labelPos: 12,
//                    drawValue: false
//                },
				dataMin :0,
				dataMax : datamax
            } 
        },
        grid: {
            font: "14px Times New Roman",
            tickLabel:["N","NNE","NE","NEE","E","SEE","SE","SSE","S","SSW","SW","SWW","W","NWW","NW","NNW"]
        }
    };
		
		data = [
		    { label: "> 8 ms", color:"blue", data: d3, rose: {show: true } },
		    { label: "3-8 m/s", color:"yellow" , data: d2, rose: {show: true } },
		    { label: "< 3 m/s", color:"green", data: d1, rose: {show: true} },
			{ label: "test", color:"black", data: d4, rose: {show: true} }
		];

		p = $.plot($("#placeholder"), data , options);
	}

















});
</script>
