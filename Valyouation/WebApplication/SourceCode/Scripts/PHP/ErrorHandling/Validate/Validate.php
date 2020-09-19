<?php


  	class Validate
  	{


		/////////////////////////////////////////////////////////      VARIABLE DECLERATIONS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


		///////////////////////////////////////////////////////////       MAGIC METHODS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        /**
         *
         * Creates a new Template engine object and sets its associated file
         *
         * @param string $HTMLtemplateFile - the filename of the HTML template to load
         * @param array $replaceValues - an array with all the tags and corresponding values to change in the HTML template
         *
         */
        public function __construct() 
        {}

  //       /**
  //        *
  //        * Ends the current template engine object
  //        *
  //        * @param NONE
  //        *
  //        */
  //       public function __destruct() 
  //       {
  //       	// Set the string variable inside this object to NULL
  //           $this->m_HTMLtemplateFile = NULL;

  //           // Set the array of values to replace to NULL
  //           $this->m_replaceValues = NULL;
  //       }

  //       /**
  //        *
  //        * This method will be triggered when invoking inaccessible or non exisiting methods of this object
  //        *
  //        * @param string $name - the name of the required method
  //        * @param string $arguments - a list of the given arguments to the method
  //        *
  //        */
		// public function __call( $name, $arguments )
		// {
		// 	// Error handling - there is no method with the given name

		// 	// Store the back trace
		// 	$backTrace = debug_backtrace();

		// 	// Display to the user the error message
		// 	trigger_error( 'Undefined property via __call() : There is no method ' . $name . ' in PHPtemplateEngineForHTML object ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

  //           // Finish execution ofthe script
  //           Die();
		// }

  //       /**
  //        *
  //        * This method will be triggered when invoking inaccessible or non exisiting static methods of this object
  //        *
  //        * @param string $name - the name of the required static method
  //        * @param string $arguments - a list of the given arguments to the static method
  //        *
  //        */
		// public static function __callStatic( $name, $arguments )
		// {
		// 	// Error handling - there is no method with the given name

		// 	// Store the back trace
		// 	$backTrace = debug_backtrace();

		// 	// Display to the user the error message
		// 	trigger_error( 'Undefined property via __callStatic() : There is no static method ' . $name . ' in PHPtemplateEngineForHTML object ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

  //           // Finish execution ofthe script
  //           Die();
		// }

	 //    /**
  //        *
  //        * This method will be triggered when setting inaccessible data members of this object
  //        *
  //        * @param string $name - the name of the required inaccessible data member
  //        * @param mixed $value - the new value for the inaccessible data member
  //        *
  //        */
		// public function __set( $name, $value )
		// {

		// }

	 //    /**
  //        *
  //        * This method will be triggered when fetching inaccessible data members of this object
  //        *
  //        * @param string $name - the name of the required inaccessible data member
  //        *
  //        */
		// public function __get( $name )
		// {
			
		// 	// Check if an entry with the given name exist and return it's value
		// 	if ( array_key_exists( $name, $this->m_replaceValues ) === false )
		// 	{
  //               // Error handling - there is no entry with the given name

  //               // Store the back trace
  //               $backTrace = debug_backtrace();

  //               // Display to the user the error message
  //               trigger_error( 'Undefined property via __get() : ' . $name . ' in ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

  //               // Return that nothing exist
  //               return ( NULL );
		// 	}

  //           // An entry exist, return it's value
  //           return ( $this->m_replaceValues[ $name ] );
		// }


        ///////////////////////////////////////////////////////////       MAGIC METHODS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\

        public static function Set( $object )
        {

            // Check that the given string is set and has value other then an empty string
            if ( ( isset( $object ) === false ) )
            {
                // The string is not valid

                // Store the back trace
                $backTrace = debug_backtrace();

                // Display to the user the error message
                trigger_error( 'The given object is unset : ' . $name . ' in ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

                // Throw an exception with the unvalid string value
                throw new Exception( 'UnsetObject' );
            }

        }


        public static function String( $string )
        {

            // Check that the given string is set and has value other then an empty string
            if ( ( isset( $string ) === false ) || ( $string === "" ) )
            {
                // The string is not valid

                // Store the back trace
                $backTrace = debug_backtrace();

                // Display to the user the error message
                trigger_error( 'Undefined property via __get() : ' . $name . ' in ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

                // Throw an exception with the unvalid string value
                throw new Exception( 'UnvalidString' );
            }

        }

        public static function ArrayKey( $arrayKey, $array )
        {

            // Check that the given string is set and has value other then an empty string
            if ( ( isset( $array[ $arrayKey ] ) === false ) || ( array_key_exist( $arrayKey, $array ) === false ) )
            {
                // The string is not valid

                // Store the back trace
                $backTrace = debug_backtrace();

                // Display to the user the error message
                trigger_error( 'The given array key does not exist : ' . $name . ' in ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

                // Throw an exception with the unvalid string value
                throw new Exception( 'UnvalidArrayKey' );
            }

        }

        public static function True( $boolean )
        {

            // Check that the given string is set and has value other then an empty string
            if ( $boolean === false )
            {
                // The string is not valid

                // Store the back trace
                $backTrace = debug_backtrace();

                // Display to the user the error message
                trigger_error( 'Undefined property via __get() : ' . $name . ' in ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

                // Throw an exception with the unvalid string value
                throw new Exception( 'Boolean value is false' );
            }

        }

  	}


?>