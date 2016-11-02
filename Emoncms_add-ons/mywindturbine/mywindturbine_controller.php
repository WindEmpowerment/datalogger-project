<?php

  // no direct access
  defined('EMONCMS_EXEC') or die('Restricted access');

  function mywindturbine_controller()
  {
    global $session,$route;
    $result = false;

    if ($route->action == "view" && $session['write']) $result = view("Modules/mywindturbine/mywindturbine_view.php",array());
    
    return array('content'=>$result);
  }