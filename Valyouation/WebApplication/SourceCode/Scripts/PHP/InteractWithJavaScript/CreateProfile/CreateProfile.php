<?php


	// This php script will be used to store all the profile data for the user in the database


	///////////////////////////////////////////////      FIRST STAGE - include all the required php scripts      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	// Require the PHP global variables
	require_once '../../GlobalVariables/GlobalVariables.php';

	// Require the PHP object database
	require_once '../../PHPobjects/PHPdatabase/PHPdatabase.php';


	//////////////////////////////////////////      SECOND STAGE - store all the user's profile data in the database      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	// Create a new PHP database object
	$databaseConnection = new PHPdatabase( $global_URI, $global_serverType, $global_userName, $global_userPassword, $global_databaseName );

	// 
