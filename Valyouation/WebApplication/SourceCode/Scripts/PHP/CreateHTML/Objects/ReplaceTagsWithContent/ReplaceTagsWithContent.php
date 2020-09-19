<?php


	/**
	*
	* HTML template engine, it takes an HTML template and change all the required data inside to match the current user. Every location in the HTML
	* template that needs to be changed must be marked as -> [@tag]
	*
	*/
	class ReplaceTagsWithContent
	{

		
		/////////////////////////////////////////////////////////      VARIABLE DECLERATIONS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


    	/**
    	 *
    	 * The filename of the HTML template to load
    	 *
    	 * @var string
    	 *
    	 */
		private $m_textWithTags = NULL;

        /**
         *
         * An array of values for replacing each tag on the HTML template ( the key for each value is its corresponding tag )
         *
         * @var array
         *
         */
		private $m_replaceToThisContent = array();

        /**
         *
         * A string containing the final HTML after all the tags were replaced with the required content, can be used only after
         * the first call to replace method
         *
         * @var array
         *
         */
        private $m_text = NULL;


		///////////////////////////////////////////////////////////       MAGIC METHODS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        /**
         *
         * Creates a new Template engine object and sets its associated file
         *
         * @param string $textWithTags - a javascript variable or the filename of the HTML template to load, if the given string matches an existing
         *        file then the file would be used otherwise it will be consdiered as a variable
         * @param array $replaceValues - an array with all the tags and corresponding values to change in the HTML template
         *
         */
        public function __construct( $textWithTags, $replaceToThisContent = NULL ) 
        {

            // Check that an HTML template was provided, and that it not empty string
            if ( ( isset( $textWithTags ) ) && ( $textWithTags !== "" ) )
            {
            	// Store the HTML template file in this object
                $this->m_textWithTags = $textWithTags;

                // Store the HTML template also to the final HTML data member
                $this->m_text = $textWithTags;

            	// Set the array inside the object
            	$this->m_replaceToThisContent = $replaceValues;
            }
            else
            {
                // Throw an exception to propagate that no HTML template was provided
                throw new Exception( "No HTML template was provided" );
            }

        }

        /**
         *
         * Ends the current template engine object
         *
         * @param NONE
         *
         */
        public function __destruct() 
        {
        	// Set the string variable inside this object to NULL
            $this->m_textWithTags = NULL;

            // Set the array of values to replace to NULL
            $this->m_replaceToThisContent = NULL;
        }

        /**
         *
         * This method will be triggered when invoking inaccessible or non exisiting methods of this object
         *
         * @param string $name - the name of the required method
         * @param string $arguments - a list of the given arguments to the method
         *
         */
		public function __call( $name, $arguments )
		{
			// Error handling - there is no method with the given name

			// Store the back trace
			$backTrace = debug_backtrace();

			// Display to the user the error message
			trigger_error( 'Undefined property via __call() : There is no method ' . $name . ' in ReplaceTagsWithContent object ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

            // Finish execution ofthe script
            Die();
		}

        /**
         *
         * This method will be triggered when invoking inaccessible or non exisiting static methods of this object
         *
         * @param string $name - the name of the required static method
         * @param string $arguments - a list of the given arguments to the static method
         *
         */
		public static function __callStatic( $name, $arguments )
		{
			// Error handling - there is no method with the given name

			// Store the back trace
			$backTrace = debug_backtrace();

			// Display to the user the error message
			trigger_error( 'Undefined property via __callStatic() : There is no static method ' . $name . ' in ReplaceTagsWithContent object ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

            // Finish execution ofthe script
            Die();
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
			
			// Check if an entry with the given name exist and return it's value
			if ( array_key_exists( $name, $this->m_replaceToThisContent ) === false )
			{
                // Error handling - there is no entry with the given name

                // Store the back trace
                $backTrace = debug_backtrace();

                // Display to the user the error message
                trigger_error( 'Undefined property via __get() : ' . $name . ' in ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

                // Return that nothing exist
                return ( NULL );
			}

            // An entry exist, return it's value
            return ( $this->m_replaceToThisContent[ $name ] );
		}


        ///////////////////////////////////////////////////////////       MAGIC METHODS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        public function Set( $arrayKey, $replaceValue )
        {
            // Add a new entry to the array
            $this->m_replaceToThisContent[ $arrayKey ] = $replaceValue;
        }

        public function Replace()
        {

            // Loop on all the template and change the tags into the required content
            foreach( $this->m_replaceToThisContent as $arrayKey => $replaceValue )
            {
                // Store the current array key
                $tagToReplace = '{{{' . $arrayKey . '}}}';

                // Replace the tag with the required value in the HTML
                $this->m_text = str_replace( $tagToReplace, $replaceValue, $this->m_text );
            }

        }

        public function GetHTML()
        {
            // Return the final HTML after all the tags were replaced with the required content
            return ( $this->m_text );
        }
        

	}


    







?>