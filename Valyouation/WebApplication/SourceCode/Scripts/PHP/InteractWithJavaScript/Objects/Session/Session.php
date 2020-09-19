<?php


	/**
	*
    * This object will wrap the cookie functionality in PHP
	*
	*/
	class PHPsession
	{

		
		/////////////////////////////////////////////////////////      VARIABLE DECLERATIONS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


    	/**
    	 *
    	 * The cookie name
    	 *
    	 * @var string
    	 *
    	 */
		private $m_name = NULL;

        /**
         *
         * The value that should be stored inside the cookie
         *
         * @var string
         *
         */
		private $m_value = NULL;

        /**
         *
         * The time in seconds since the epoch that the cookie will expire
         *
         * @var int
         *
         */
        private $m_expirationTime = 0;

        /**
         *
         * The base directory which the cookie will be accessible only inside
         *
         * @var string
         *
         */
        private $m_accessOnlyPath = NULL;

        /**
         *
         * The domain or subdomain which the cookie will be accessible only inside
         *
         * @var string
         *
         */
        private $m_accessOnlyDomain = NULL;

        /**
         *
         * Indicates that the cookie should only be transmitted over a secure HTTPS connection from the client
         *
         * @var bool
         *
         */
        private $m_secure = false;

        /**
         *
         * When TRUE the cookie will be made accessible only through the HTTP protocol. This means that the cookie won't be accessible by scripting 
         * languages, such as JavaScript
         *
         * @var bool
         *
         */
        private $m_httpOnly = false;


		///////////////////////////////////////////////////////////       MAGIC METHODS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        /**
         *
         * Creates a new cookie object, inside the 
         *
         * @param string $name - the filename of the HTML template to load
         * @param string $value - an array with all the tags and corresponding values to change in the HTML template
         * @param int $expirationTime -
         * @param string $accessOnlyPath -
         * @param string $accessOnlyDomain -
         * @param bool $secure -
         * @param bool $httpOnly -
         *
         */
        public function __construct( $name, $value = NULL, $expirationTime = 0, $accessOnlyPath = NULL, $accessOnlyDomain = NULL, $secure = false, $httpOnly = false ) 
        {
        	// Initialize all the data members of the object
            $this->m_name = $name;
            $this->m_value = $value;
            $this->m_expirationTime = $expirationTime;
            $this->m_accessOnlyPath = $accessOnlyPath;
            $this->m_accessOnlyDomain = $accessOnlyDomain;
            $this->m_secure = $secure;
            $this->m_httpOnly = $httpOnly;            
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
            // Unset all the data members of the object
            $this->m_name = NULL;
            $this->m_value = NULL;
            $this->m_accessOnlyPath = NULL;
            $this->m_accessOnlyDomain = NULL;
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
			trigger_error( 'Undefined property via __call() : There is no method ' . $name . ' in PHPcookie object ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );
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
			trigger_error( 'Undefined property via __callStatic() : There is no static method ' . $name . ' in PHPcookie object ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );
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
			// Add a new entry to the array
			$this->m_replaceValues[ $name ] = $value;
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
			if ( array_key_exists( $name, $this->m_replaceValues ) === true )
			{
				// An entry exist, return it's value
				return ( $this->m_replaceValues[ $name ] );
			}

			// Error handling - there is no entry with the given name

			// Store the back trace
			$backTrace = debug_backtrace();

			// Display to the user the error message
			trigger_error( 'Undefined property via __get() : ' . $name . ' in ' . $backTrace[0][ 'file' ] . ' on line ' . $backTrace[0][ 'line' ], E_USER_NOTICE );

			// Return that nothing exist
			return ( NULL );
		}

	}










?>