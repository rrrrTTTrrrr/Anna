<?php

	
	// This class will be used to as a wrapper for the standard PDO class
	class ConnectDatabase
	{

		/////////////////////////////////////////////////////////      VARIABLE DECLERATIONS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


		// The following variables will be used to create the connection to the server that
		// the database is on :

    	/**
    	 *
    	 * This variable will store the address of the server ( IP address OR localhost )
    	 *
    	 * @var string
    	 *
    	 */
		private $m_serverIPaddress = NULL;

    	/**
    	 *
    	 * This variable will store the type of database on the server ( MySQL, MariaDB, etc... )
    	 *
    	 * @var string
    	 *
    	 */
		private $m_databaseType = NULL;

    	/**
    	 *
    	 * This variable will store the name of the required database on the server
    	 *
    	 * @var string
    	 *
    	 */
		private $m_databaseName = NULL;

    	/**
    	 *
    	 * This variable will store the user name to login to the server with
    	 *
    	 * @var string
    	 *
    	 */
		private $m_userName = NULL;

    	/**
    	 *
    	 * This variable will store the password for the specific user name
    	 *
    	 * @var string
    	 *
    	 */
		private $m_password = NULL;

    	/**
    	 *
    	 * This variable will store the PDO object that creates the connection
    	 *
    	 * @var PDO object
    	 *
    	 */
		private $m_pdo = NULL;


		///////////////////////////////////////////////////////////       MAGIC METHODS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        /**
         *
         * Creates a new PDO object, initializes all the required data members, open the connection to the server
         * and sets the error attribute for the object to throw exception on error
         *
         * @param string $serverIPaddress - the IP address of the required server
         * @param string $serverType - the type of the database on the server
         * @param string $userName - the name of the required user on the server
         * @param string $password - the password for the required user on the server
         * @param string $databaseName - the name of the required database on the server, if not provided will be NULL
         *
         */
		public function __construct( $serverIPaddress, $serverType, $userName, $password, $databaseName = NULL )
		{
			
			// Try catch structure to ensure that if an exception is thrown it will be caught, and the error
			// won't be shown on the client display
			try
			{

				// Initialize all the required variables
				$this->m_serverIPaddress = $serverIPaddress;
				$this->m_databaseType = $serverType;
				$this->m_userName = $userName;
				$this->m_password = $password;

				// This variable will store the string with the server information to pass to the PDO constrcutor
				$serverInformation = NULL;

				// Check if the a database name was given
				if ( $databaseName == NULL )
				{
					// No database name was given

					// Store the information to connect to the server without a specific database
 					$serverInformation = $this->m_databaseType . ":host=" . $this->m_serverIPaddress;
 				}
 				else
 				{
 					// A database name was given

 					// Store the database name
 					$this->m_databaseName = $databaseName;

					// Store the information to connect to the server without a specific database
 					$serverInformation = $this->m_databaseType . ":host=" . $this->m_serverIPaddress . ";dbname=" . $this->m_databaseName;
 				}
				
				// Try to connect to the MySQL server
				$this->m_pdo = new PDO( $serverInformation, $this->m_userName, $this->m_password );

				// Enable error mode, and make it throw a PDOException in case of an error
				$this->m_pdo->setAttribute( PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION );


			}
			// Check if an exception was thrown
			catch ( Exception $exception )
			{

				// Display the error that caused an exception to be thorwn and finish the script
				die( 'Error :  ' . $exception->getMessage() . '<br>' );

			}

		}

        /**
         *
         * Ends the current pdo object
         *
         * @param NONE
         *
         */
		public function __destruct()
		{
			// Set the PDO variable to NULL this will cause the connection to be closed
			$this->m_pdo = NULL;
		}

        /**
         *
         * This method will be triggered when invoking inaccessible or non exisiting methods of this class
         *
         * @param string $name - the name of the required method
         * @param string $arguments - a list of the given arguments to the method
         *
         */
		public function __call( $name, $arguments )
		{
			// Error handling - there is no static method with the given name

			// Store the back trace
			$backTrace = debug_backtrace();

			// Display to the user the error message
			trigger_error( 'Undefined property via __callStatic() : There is no method ' . $name . ' in ConnectDatabase object ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );
		}

        /**
         *
         * This method will be triggered when invoking inaccessible or non exisiting static methods of this class
         *
         * @param string $name - the name of the required static method
         * @param string $arguments - a list of the given arguments to the static method
         *
         */
		public static function __callStatic( $name, $arguments )
		{
			// Error handling - there is no static method with the given name

			// Store the back trace
			$backTrace = debug_backtrace();

			// Display to the user the error message
			trigger_error( 'Undefined property via __callStatic() : There is no static method ' . $name . ' in ConnectDatabase object ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );
		}

	    /**
         *
         * This method will be triggered when setting inaccessible data members of this object
         *
         * @param string $name - the name of the required inaccessible data member
         * @param mixed $value - the new value for the inaccessible data member
         *
         */
		public function __set( $name, $value )
		{

			// Check if a data member with the given name exist and it is not the PDO object and it is currently set
			if ( ( property_exists( 'ConnectDatabase', $name ) === true ) && ( $name !== 'm_pdo' ) && ( isset( $this->$name ) === true ) )
			{
				// An entry with the given name exist and it is not the PDO object and it is set, store the required value
				$this->$name = $value;

				// Return control to the calling metohd
				return;
			}

			// Error handling - there is no data member with the given name or the it is not set

			// Store the back trace
			$backTrace = debug_backtrace();

			// Display to the user the error message
			trigger_error( 'Undefined property via __set() : ' . $name . ' in ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );
		}

	    /**
         *
         * This method will be triggered when fetching inaccessible data members of this object
         *
         * @param string $name - the name of the required inaccessible data member
         *
         */
		public function __get( $name )
		{
			
			// Check if a data member with the given name exist and it is not the PDO object and it is currently set
			if ( ( property_exists( 'ConnectDatabase', $name ) === true ) && ( $name !== 'm_pdo' ) && ( isset( $this->$name ) === true ) )
			{
				// An entry with the given name exist and it is not the PDO object and it is set, return the required value
				return ( $this->$name );
			}

			// Error handling - there is no data member with the given name or the it is not set

			// Store the back trace
			$backTrace = debug_backtrace();

			// Display to the user the error message
			trigger_error( 'Undefined property via __get() : ' . $name . ' in ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

			// Return that nothing exist
			return ( NULL );
		}

	    /**
         *
         * This method will be triggered when testing the content of inaccessible data members of this object
         *
         * @param string $name - the name of the required inaccessible data member to test
         *
         */
		public function __isset( $name )
		{

			// Check if a data member with the given name exist and it is not the PDO object and it is currently set
			if ( ( property_exists( 'ConnectDatabase', $name ) === true ) && ( $name !== 'm_pdo' ) )
			{
				// An entry with the given name exist and it is not the PDO object return the if the data member is set
				return ( isset( $this->$name ) );
			}

			// Error handling - there is no data member with the given name or the it is not set

			// Store the back trace
			$backTrace = debug_backtrace();

			// Display to the user the error message
			trigger_error( 'Undefined property via __isset() : ' . $name . ' in ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );
		}

	    /**
         *
         * This method will be triggered when testing the content of inaccessible data members of this object
         *
         * @param string $name - the name of the required inaccessible data member to test
         *
         */
		public function __unset( $name )
		{

			// Check if a data member with the given name exist and it is not the PDO object and it is currently set
			if ( ( property_exists( 'ConnectDatabase', $name ) === true ) && ( $name !== 'm_pdo' ) )
			{
				// An entry with the given name exist and it is not the PDO object return the if the data member is set
				return ( isset( $this->$name ) );
			}

			// Error handling - there is no data member with the given name or the it is not set

			// Store the back trace
			$backTrace = debug_backtrace();

			// Display to the user the error message
			trigger_error( 'Undefined property via __isset() : ' . $name . ' in ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );
		}


		/////////////////////////////////////////////////////////////      OBJECT INTERFACE      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


		// This method will be used to check if a database exist on the server
		public function DatabaseExistOrNot( $databaseName )
		{
			
			// Try catch structure to ensure that if an exception is thrown it will be caught, and the error
			// won't be shown on the client display
			try
			{

				// Prepare the statment to query the server if the database exist
				$pdoStatment = $this->m_pdo->prepare( 'SELECT SCHEMA_NAME FROM INFORMATION_SCHEMA.SCHEMATA WHERE SCHEMA_NAME = :databaseName' );

				// Execute the SQL query
				$executeResult = $pdoStatment->execute( [ ':databaseName' => $databaseName ] );

				// Check if the query succeeded
				if ( $executeResult == false )
				{
					// The query failed, thrown an execption
					throw new Exception( "The query for checking if the database exist failed" );
				}

				// Check if the returned result is empty
				if ( $pdoStatment->fetch( PDO::FETCH_ASSOC ) == false )
				{
					// The database does not exist
					return ( false );
				}

				// The database exist, return true
				return ( true );

			}
			// Check if an exception was thrown
			catch ( Exception $exception )
			{

				// Display the error that caused an exception to be thorwn and finish the script
				die( 'Error :  ' . $exception->getMessage() . '<br>' );

			}

		}

		// This method will be used to use a specific database in the server
		public function UseDatabase( $databaseName )
		{
			
			// Try catch structure to ensure that if an exception is thrown it will be caught, and the error
			// won't be shown on the client display
			try
			{

				// Store the database name
				$this->m_databaseName = $databaseName;

				// Use the required database
				$this->m_pdo->exec( "USE $databaseName" );

			}
			// Check if an exception was thrown
			catch ( Exception $exception )
			{

				// Display the error that caused an exception to be thorwn and finish the script
				die( 'Error :  ' . $exception->getMessage() . '<br>' );

			}

		}

		// This method will be used to create databases
		public function CreateDatabase( $databaseName )
		{

			// Try catch structure to ensure that if an exception is thrown it will be caught, and the error
			// won't be shown on the client display
			try
			{

				// Begin a transaction, turning off autocommit
				$this->m_pdo->beginTransaction();

				// Create the database only if it doesn't exist already
				$this->m_pdo->exec( "CREATE DATABASE IF NOT EXISTS $databaseName" );

				// Commit the changes
				$this->m_pdo->commit();

			}
			// Check if an exception was thrown
			catch ( Exception $exception )
			{

				// Recognize mistake and roll back changes
				$this->m_pdo->rollBack();

				// Display the error that caused an exception to be thorwn and finish the script
				die( 'Error :  ' . $exception->getMessage() . '<br>' );

			}

		}

		// This method will be used to execute the given sql query
		public function ExecuteQuery( $query )
		{

			// Try catch structure to ensure that if an exception is thrown it will be caught, and the error
			// won't be shown on the client display
			try
			{

				// Begin a transaction, turning off autocommit
				$this->m_pdo->beginTransaction();	

				// Execute the required query
				$this->m_pdo->exec( $query );

				// Commit the changes
				$this->m_pdo->commit();

			}
			// Check if an exception was thrown
			catch ( Exception $exception )
			{

				// Recognize mistake and roll back changes
				$this->m_pdo->rollBack();

				// Display the error that caused an exception to be thorwn and finish the script
				die( 'Error :  ' . $exception->getMessage() . '<br>' );

			}

		}

		// This method will be used to execute the given sql query
		public function Prepare( $prepareQuery )
		{
			
			// Try catch structure to ensure that if an exception is thrown it will be caught, and the error
			// won't be shown on the client display
			try
			{

				// Prepare the the query
				$this->m_m_pdoStatement = $this->m_pdo->prepare( $prepareQuery );

			}
			// Check if an exception was thrown
			catch ( Exception $exception )
			{

				// Display the error that caused an exception to be thorwn and finish the script
				die( 'Error :  ' . $exception->getMessage() . '<br>' );

			}
	
		}


	}


?>
