<?php


	// This php script will be used to store all the profile data for the user in the database


	///////////////////////////////////////////////      FIRST STAGE - include all the required php scripts      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	// Require the PHP global variables
	require_once '../../GlobalVariables/GlobalVariables.php';

	// Require the PHP object database
	require_once '../../Objects/ConnectDatabase/ConnectDatabase.php';

	// Require the PHP validate
	require_once '../../Objects/Validate/Validate.php';


	//////////////////////////////////////////////////////////      SECOND STAGE - validate the data      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	// Check if the $_POST superglobal has an entrance for the E-mail the user provided
	if ( ( isset( $_POST[ 'Email' ] ) === false )
	{
		// 
	}

	// Check that all the required fields of the form were set
	if ( ( isset( $_POST[ 'Email' ] ) === false ) || ( isset( $_POST[ 'Password' ] ) === false ) || ( isset( $_POST[ 'ConfirmPassword' ] ) === false ) )
	{
		echo "1";
	}
	else
	{

		// Validate the E-mail address
		if ( Validate::Email( $_POST[ 'Email' ] ) === false )
		{
			echo "2";
		}
		else if ( $_POST[ 'Password' ] !== $_POST[ 'ConfirmPassword' ] )
		{
			echo "3";
		}

	}



	//////////////////////////////////////////      SECOND STAGE - store all the user's profile data in the database      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	// Create a new PHP database object
	$databaseConnection = new ConnectDatabase( $global_URI, $global_serverType, $global_userName, $global_userPassword, $global_databaseName );

	// 



?>
