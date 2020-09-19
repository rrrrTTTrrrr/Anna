  <?php


  	class Head
  	{


		/////////////////////////////////////////////////////////      VARIABLE DECLERATIONS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        /**
         *
         * A string to contain the head part of the HTML file
         *
         * @var string
         *
         */
		    private $m_headHTML = NULL;


		///////////////////////////////////////////////////////////       MAGIC METHODS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        /**
         *
         * Creates a new Head object
         *
         */
        public function __construct() 
        {
          // Initialize the head HTML with the <head> tag
          $this->m_headHTML = '<head>';
        }

          // // Initialize the head part of the HTML file
          // $this->m_headHTML = file_get_contents( 'SourceCode/HTML/HTMLhead/head.html' );
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


        public function AddTitleTag( $title )
        {
          // Create the title tag and set the value to given one
          $titleTag = '<title>' . $title . '</title>';

          // Add the title tag to the head part of the HTML file
          $this->m_headHTML = $this->m_headHTML . $titleTag;
        }

        public function AddLinkTag( $rel, $type, $href )
        {
          // Create the link tag and set the required values
          $linkTag = '<link rel="' . $rel . '" type="' . $type . '" href="' . $href . '">';

          // Add the link tag to the head part of the HTML file
          $this->m_headHTML = $this->m_headHTML . $linkTag;
        }

        public function AddLinkForCSSstyleSheetTag( $href )
        {
          // Create the link tag and set the required values
          $linkForCSSstyleSheetTag = '<link rel="stylesheet" type="text/css" href="' . $href . '">';

          // Add the link tag to the head part of the HTML file
          $this->m_headHTML = $this->m_headHTML . $linkForCSSstyleSheetTag;
        }

        public function AddMetaNameContentTag( $name, $content )
        {
          // Create the meta tag with attributes name and content and set the required values
          $metaNameContentTag = '<meta name="' . $name . '" content="' . $content . '">';

          // Add the meta tag to the head part of the HTML file
          $this->m_headHTML = $this->m_headHTML . $metaNameContentTag;
        }

        public function AddMetaFileTypeTag( $httpEquiv, $content )
        {
          // Create the meta tag with attributes http-equiv and content and set the required values
          $metaHttpEquivContentTag = '<meta http-equiv="' . $httpEquiv . '" content="' . $content . '">';

          // Add the meta tag to the head part of the HTML file
          $this->m_headHTML = $this->m_headHTML . $metaHttpEquivContentTag;
        }



        public function GetHTML()
        {
            // Return the final HTML after all the tags were replaced with the required content
            return ( $this->m_headHTML . '</head>' );
        }

  	}


?>