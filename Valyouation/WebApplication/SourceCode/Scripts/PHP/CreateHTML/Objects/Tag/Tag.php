<?php

    // Include the validate object
    require_once 'SourceCode/Scripts/PHP/ErrorHandling/Validate/Validate.php';

    // Include the HTML tags information object
    require_once 'SourceCode/Scripts/PHP/CreateHTML/Objects/HTMLtagsInformation/HTMLtagsInformation.php'


  	class Tag
  	{


		/////////////////////////////////////////////////////////      VARIABLE DECLERATIONS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        // This part will deal with the chain structure

        /**
         *
         * A string to store the next tag object in the HTML tags list
         *
         * @param Tag object
         *
         */
        private $m_nextTag = NULL;        

        /**
         *
         * A string to store the next tag object in the HTML tags list
         *
         * @param Tag object
         *
         */
        private $m_previousTag = NULL;  


        // This part will deal with tag data

        /**
         *
         * A string to store the name attribute of the HTML tag
         *
         * @param string
         *
         */
	    private $m_tag = NULL;

        /**
         *
         * A string to store the id attribute of the HTML tag
         *
         * @param string
         *
         */
        private $m_id = NULL;

        /**
         *
         * A string to store the name attribute of the HTML tag
         *
         * @param string
         *
         */
        private $m_name = NULL;

        /**
         *
         * A string to store the content of the HTML tag
         *
         * @param string
         *
         */
        private $m_content = NULL;


	    ///////////////////////////////////////////////////////////       MAGIC METHODS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        /**
         *
         * Creates a new Template engine object and sets its associated file
         *
         * The tag values can be :
         *
         *  1. 0 - DOCTYPE - no closing tag 
         *  2. 1 - html - require closing 
         *  3. 2 - head - require closing 
         *
         * @param string $HTMLtemplateFile - the filename of the HTML template to load
         * @param array $replaceValues - an array with all the tags and corresponding values to change in the HTML template
         *
         */
        public function __construct( $nextTagObjectInTheChain, $previousTagObjectInTheChain, $tagValue, $id, $name, $content ) 
        {
            // Validate that the next and previous objects in the chain were set
            Validate::Set( $nextTagObjectInTheChain );
            Validate::Set( $previousTagObjectInTheChain );

            // Validate the given strings
            Validtae::String( $tag );
            Validtae::String( $id );
            Validtae::String( $name );
            Validtae::String( $content );

            // Set the next tag object inside this instance
            $this->m_nextTag = $nextTagObjectInTheChain;

            // Set the previous tag object inside this instance
            $this->m_previousTag = $previousTagObjectInTheChain;

            // Set the data members
            $this->m_tag = $tag;
            $this->m_id = $id;
            $this->m_name = $name;
            $this->m_content = $content;
        }


        ///////////////////////////////////////////////////////////       MAGIC METHODS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\



        public function SetNewTag( $newTag )
        {
            // Change the tag id attribute
            $this->m_id = $newID;
        }

        public function SetNewID( $newID )
        {
            // Change the tag id attribute
            $this->m_id = $newID;
        }

        public function SetNewName( $newName )
        {
            // Change the tag name attribute
            $this->m_name = $newName;
        }

        public function SetNewContent( $newContent )
        {
            // Change the tag id attribute
            $this->m_content = $newContent;
        }


  	}


?>