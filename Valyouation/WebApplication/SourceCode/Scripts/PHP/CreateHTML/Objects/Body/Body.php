<?php

    // Include the validate object
    require_once 'SourceCode/Scripts/PHP/ErrorHandling/Validate/Validate.php';


  	class Body
  	{


		/////////////////////////////////////////////////////////      VARIABLE DECLERATIONS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        /**
         *
         * A string to store all the java script files that needs to be added to the end of the body part of the HTML file using the <script> tag
         *
         * @param string object
         *
         */
		private $m_javaScriptSourceFilesToAdd = NULL;

        /**
         *
         * An array to store the 
         *
         * @param array object
         *
         */
        private $m_arrayOfRootTags = array();




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


        public function AddRootTag( $tag, $id, $name )
        {
            // Validate that the given strings
            Validtae::String( $id );
            Validtae::String( $name );

            // Create the parent div tag and set the required values
            $this->m_arrayOfRootTags[ '$id' ] = '<' . $tag . ' id="' . $id .'" name="' . $name . '">';

            // Store the required location for this parent tag be inserting tag into the body HTML
            $this->m_bodyHTML .= '{{{' . $id . '}}}';
        }

        public function AddContentToRootTag( $rootTagID, $tag, $id, $name, $content )
        {
            // Validate that the given strings
            Validtae::String( $rootTagID );
            Validtae::String( $tag );
            Validtae::String( $id );
            Validtae::String( $name );
            Validtae::String( $content );

            // Verify that the root tag id exist in the array of root tags inside the object
            Validate::ArrayKey( $rootTagID, $this->m_arrayOfRootTags );

            // Create the parent div tag and set the required values
            $this->m_arrayOfRootTags[ '$rootTagID' ] .= '<' . $tag . ' id="' . $id .'" name="' . $name . '">' . $content . '</' . $tag . '>';
        }

        public function AddDivTag( $id, $name, $content )
        {
            // Validate that the given strings
            Validtae::String( $id );
            Validtae::String( $name );
            Validtae::String( $content );

            // Create the div tag and set the required values
            $divTag = '<div id="' . $id .'" name="' . $name . '">' . $content . '</div>';

            // Add the div tag to the body part of the HTML file
            $this->m_bodyHTML .= $divTag;
        }

        public function AddScriptTagForJavaScriptFiles( $javaScriptFileURI )
        {
            // Validate that the given string
            Validtae::String( $javaScriptFileURI );

            // Create the div tag and set the required values
            $scriptTag = '<script src="' . $javaScriptFileURI .'"></script>';

            // Add another entry to the array with the <script> tag and the source javaScript file
            $this->m_javaScriptSourceFilesToAdd = $this->m_javaScriptSourceFilesToAdd . $scriptTag;
        }

        public function AddInputTag( $id, $name, $name, $placeHolder = NULL )
        {
            // Validate that the given strings
            Validtae::String( $id );
            Validtae::String( $name );
            Validtae::String( $name );
            Validtae::String( $placeHolder );

            // Create the input tag and set the required values
            $inputTag = '<input id="' . $id .'" name="' . $name . '" type="' . $type . '" placeHolder="' . $placeHolder . '">';

            // Add the input tag to the body part of the HTML file
            $this->m_bodyHTML .= $inputTag;
        }


        public function GetHTML()
        {
            // Create a new replace tags with content object
            $replaceTagsWithContentObject = new ReplaceTagsWithContent( $this->m_bodyHTML );

            foreach( $this->m_arrayOfRootTags as $IDofRootTag => $content )
            {
                // Set the root
                $replaceTagsWithContentObject->Set( $IDofRootTag, $content );
            }

            // Replace all the tags with the tag parents content
            $replaceTagsWithContentObject->Replace();

            // Set the body HTML data member with the result and add the the javaScript files also
            $this->m_bodyHTML = $replaceTagsWithContentObject->GetHTML() . $this->m_javaScriptSourceFilesToAdd;

            // Return the final HTML after all the tags were replaced with the required content
            return ( $this->m_bodyHTML . '</body>' );
        }

  	}


?>