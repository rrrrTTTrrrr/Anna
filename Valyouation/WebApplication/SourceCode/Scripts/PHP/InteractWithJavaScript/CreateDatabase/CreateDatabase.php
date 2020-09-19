<?php


	// This php script will be used to create the database for the webapplication


	///////////////////////////////////////////////      FIRST STAGE - include all the required php scripts      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	// Require the PHP global variables
	require_once '../../GlobalVariables/GlobalVariables.php';

	// Require the PHP object database
	require_once '../../PHPobjects/PHPdatabase/PHPdatabase.php';


	///////////////////////////////////////////////////      SECOND STAGE - create the database itself      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	// Create a new PHP database object
	$createDatabase = new PHPdatabase( $global_URI, $global_serverType, $global_userName, $global_userPassword );

	// Create the required database
	$createDatabase->CreateDatabase( $global_databaseName );

	// Use the new database
	$createDatabase->UseDatabase( $global_databaseName );

	// SECOND STAGE - create the tables in the database

	// Tables required for the webapplication to work

	// Table for the user's account information
	$createDatabase->ExecuteQuery( "CREATE TABLE UserAccountInformation (
		                            UserID BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
		                            Email NCHAR NOT NULL,
		                            Password CHAR NOT NULL,
		                            Hash CHAR NOT NULL,
		                            Active INT( 1 ) DEFAULT '0' )" );

	// Table for the user's profile
	$createDatabase->ExecuteQuery( "CREATE TABLE UserProfile (
					                UserID BIGINT UNSIGNED NOT NULL PRIMARY KEY,
					                FirstName NCHAR,
						            LastName NCHAR,
					                Title NCHAR,
					                Description NCHAR,
					                Photo LONGBLOB )" );

	// Table for the hash tags, these will be used at first to make the search for ceratin context of prices
	$createDatabase->ExecuteQuery( "CREATE TABLE HashTags (
	                 				HashTagID BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
		                 			HashTagName NCHAR NOT NULL,
			                 		HashTagDescription NCHAR NOT NULL )" );

	// Table for the hash tag price
	$createDatabase->ExecuteQuery( "CREATE TABLE HashTagsPrice (
				                 	HashTagPriceID BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
				                 	HashTagID BIGINT UNSIGNED NOT NULL,
				                 	UserID BIGINT UNSIGNED NOT NULL,
				                 	MaxPrice INT UNSIGNED NOT NULL,
				                 	MinPrice INT UNSIGNED NOT NULL,
				                 	Description NCHAR )" );

	// Table for the user's services
	$createDatabase->ExecuteQuery( "CREATE TABLE UserServices (
					                UserServiceID BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
					                UserID BIGINT UNSIGNED NOT NULL,
					                HashTagID BIGINT UNSIGNED NOT NULL,
					                ServiceName NCHAR NOT NULL,
					                Description NCHAR NOT NULL,
					                Photo LONGBLOB )" );

	// Table for the user's services pricing
	$createDatabase->ExecuteQuery( "CREATE TABLE UserServicesPrice (
					                UserServicePriceID BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
					                UserServiceID BIGINT UNSIGNED NOT NULL,
					                UserID BIGINT UNSIGNED NOT NULL,
					                Price INT UNSIGNED NOT NULL,
					                Description NCHAR NOT NULL )" );

	// Tables required for the cryptocurrency coin

	// Table to store all the cryptocurrency coin state of the user
	$createDatabase->ExecuteQuery( "CREATE TABLE UserCoins (
					                UserID BIGINT UNSIGNED NOT NULL PRIMARY KEY,
									Amount INT UNSIGNED DEFAULT '500' )" );


	// Tables required to analyse the user's usage

	// Table to store all the analytics of the user's
	$createDatabase->ExecuteQuery( "CREATE TABLE UserAnalytics (
					                UserID BIGINT UNSIGNED NOT NULL PRIMARY KEY,
						            JoinDate DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
					                ActiveDate DATETIME )" );

	// Table to store when ( date and time ) every user entred the webapplicaition and for how long
	$createDatabase->ExecuteQuery( "CREATE TABLE UserDateAndTimeUsage (
									UserDateAndTimeUsageID BIGINT UNSIGNED AUTO_INCREMENT PRIMARY KEY,
					                UserID BIGINT UNSIGNED NOT NULL,
						            InDateAndTime DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,
						            OutDateAndTime DATETIME )" );


?>