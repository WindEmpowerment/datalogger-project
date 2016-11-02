<?php
/*
     Released under the GNU Affero General Public License.
     See COPYRIGHT.txt and LICENSE.txt.
	See emoncms project
     mywindturbine module contributed by gilou
*/

// no direct access
defined('EMONCMS_EXEC') or die('Restricted access');

// mywindturbine Processlist Module
class mywindturbine_ProcessList
{
    private $log;
    private $parentProcessModel;
    private $feed;

    // Module required constructor, receives parent as reference
    public function __construct(&$parent)
    {
        $this->log = new EmonLogger(__FILE__);
        $this->parentProcessModel = &$parent;
       	$this->feed = &$parent->feed;
    }

    // Module required process configuration, $list array index position is not used, function name is used instead
    public function process_list()
    {
        // Note on engine selection

        // The engines listed against each process must be the supported engines for each process - and are only used in the input and node config GUI dropdown selectors
        // By using the create feed api and input set processlist its possible to create any feed type with any process list combination.
        // Only feeds capable of using a particular processor are displayed to the user and can be selected from the gui.
        // Daily datatype automaticaly adjust feed interval to 1d and user cant change it from gui.
        // If there is only one engine available for a processor, it is selected and user cant change it from gui.
        // The default selected engine is the first in the array of the supported engines for each processor.
        // Virtual feeds are feeds that are calculed in realtime when queried and use a processlist as post processor. 
        // Processors that write or update a feed are not supported and hidden from the gui on the context of virtual feeds.

        // 0=>Name | 1=>Arg type | 2=>function | 3=>No. of datafields if creating feed | 4=>Datatype | 5=>Group | 6=>Engines | 'desc'=>Description | 'requireredis'=>true/false
        $list[] = array(_("degree in column"),ProcessArg::VALUE,"degree_to_column",0,DataType::UNDEFINED,"My wind turbine", 'desc'=>"Convert a degree input to the right column. In value, put the number of column : 8, 16 or 32.");
	$list[] = array(_("Log wind speed frequency"),ProcessArg::FEEDID,"log_speed_frequency",2,DataType::REALTIME,"My wind turbine",array(Engine::PHPFINA,Engine::PHPFIWA,Engine::PHPTIMESERIES,Engine::MYSQL,Engine::MYSQLMEMORY), 'desc'=>"Convert the wind speed value to a column. (each column = 0,25 m/s)");    

        return $list;
    }


    // \/ Below are functions of this module processlist, same name must exist on process_list()
    
    
    
    public function degree_to_column($arg, $time, $value)
    {
	$value = floor(($value + (360/(2*$arg)))/(360/$arg));
	if ($value ==$arg) $value =0;
        return $value;
    }
    
    public function log_speed_frequency($id, $time, $value)
    {
	$value = floor($value *4);
	$this->feed->insert_data($id, $time, $time, $value);
        return $value;
    }

}
