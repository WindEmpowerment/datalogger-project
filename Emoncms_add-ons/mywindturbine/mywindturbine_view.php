<!-- defenition of the style/look of the elements on our page (CSS stylesheet) -->
<style>

  body {
    background-color:#222;
  }

  .electric-title {
    font-weight:bold; 
    font-size:22px; 
    color:#aaa; 
    padding-top:50px
  }

  .power-value {
    font-weight:bold; 
    font-size:100px; 
    color:#0699fa; 
    padding-top:45px;
  }

  .kwh-value {
    font-weight:normal; 
    font-size:22px; 
    color:#0699fa; 
    padding-top:45px;
  }

</style>

<!-- The three elements: title, power value and kwhd value that makes up our page -->
<!-- margin: 0px auto; max-width:320px; aligns the elements to the middle of the page -->
<div style="margin: 0px auto; max-width:320px;">
    <div class="electric-title">POWER NOW:</div>
    <div class="power-value"><span id="power">250</span>W</div>
    <div class="kwh-value">USE TODAY: <b><span id="kwhd">3.2</span> kWh</b></div>
</div>

<!-- bring in the emoncms path variable which tells this script what the base URL of emoncms is -->
<?php global $path; ?>

<!-- feed.js is the feed api helper library, it gives us nice functions to use within our program that
calls the feed API on the server via AJAX. -->
<script language="javascript" type="text/javascript" src="<?php echo $path; ?>Modules/feed/feed.js"></script>

<script>

  // The feed api library requires the emoncms path
  var path = "<?php echo $path; ?>"

  update();

  // Set interval is a way of scheduling an periodic call to a function
  // which we can then use to fetch the latest power value and update the page.
  // update interval is set to 5 seconds (5000ms)
  setInterval(update,5000);

  function update()
  {
    // Get latest feed values from the server (this returns the equivalent of what you see on the feed/list page)
    var feeds = feed.list_by_id();    

    // Update the elements on the page with the latest power and energy values.
    $("#power").html(feeds[2]);
    $("#kwhd").html(feeds[3].toFixed(1));
  }
</script>