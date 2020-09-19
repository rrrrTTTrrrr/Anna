<?php

	// This script will be used to verify that the given E-mail is valid and that it is actually belongs to the new user

	// Require the global variables php script
	require_once '../GlobalVariables/GlobalVariables.php';

	// Require the connect to mysql server php script
	require_once '../ConnectToMySQLserver.php';

	// Check that the E-mail part of the form is not empty and that the E-mail address is valid
	if ( isset( $_POST['email'] ) == true )
	{
		// This variable will store the given E-mail address
		$email = $_POST['email'];

		// The E-mail part was given, check if the address is valid
		if ( filter_var( $email, FILTER_VALIDATE_EMAIL ) != false )
		{
			// The E-mail address is valid

			// Generate an hash string
			$hash = hash( "sha256", rand( 0, 1000 ) );

			// Generate a random password
			$password = rand( 1000, 10000 );

			// Try to add the new user information to the users information table
			try
			{

				// Start a transaction
				$mysql_pdo->beginTransaction();

				// Enable error mode, and make it throw an PDOException in case of an error
				$mysql_pdo->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );

				// Prepare the statment to be used to insert the new user account data
				$mysql_pdoStatment = $mysql_pdo->prepare( "INSERT INTO UsersAccountInformation ( Email, Password, Hash ) VALUES ( :Email, :Password, :Hash )" );

				// Execute the SQL query with the new user account information
				$mysql_pdoStatment->execute( [ 'Email' => $email, 'Password' => hash( "sha256", $password ), 'Hash' => $hash ] );

				// Commit the changes to the database
				$mysql_pdo->commit();
				
			}
			// Check if an exception was thrown
			catch ( Exception $exception )
			{

				// Make sure that no changes were made
				$mysql_pdo->rollBack();

				// Display the error that caused an exception to be thorwn and finish the script
				die( "Error :" . $exception->getMessage() . "<br>" );
				
			}

			// Create a variable to store the subject of the E-mail
			$subject = "$global_name - account activation";

			// Create a variable to store the message of the E-mail
			$message =  

				'Thanks for Joining!

				Your account has been created, you can login with the given E-mail and the following password after activation :

				_______________________

				password: '.$password.'
				_______________________


				Please click this link to activate your account :

				http://'.$global_URI.'/CheckEmailValidation.php?email='.$email.'&hash='.$hash.' ';

			// Send the activation E-mail to the new user
			mail( $email, $subject, $message, $headers );
		}

	}
	



?>