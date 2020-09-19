<?php


    // Include the validate object
    require_once 'SourceCode/Scripts/PHP/ErrorHandling/Validate/Validate.php';


  	class HTMLtagsInformation
  	{


		/////////////////////////////////////////////////////////      VARIABLE DECLERATIONS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        /**
         *
         * An array to store the HTML tags names
         *
         * @param array
         *
         */
        private $m_HTMLtagsNames = array();

        /**
         *
         * A string to store the content of the HTML tag
         *
         * @param string
         *
         */
        private $m_tagsNeedsCloserOrNot = array();


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
        public function __construct() 
        {
        	// Initialize the array with the information if the HTML tag needs closing tag or not
        	$this->InitializeTagsNeedsCloserOrNotArray();
        }


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
        private function InitializeHTMLtagsNamesArray()
        {
        	// head tag
        	$this->m_tagsNeedsCloserOrNot[0] = 'head';

        	// title tag
        	$this->m_tagsNeedsCloserOrNot[1] = 'title';

        	// button tag
        	$this->m_tagsNeedsCloserOrNot[2] = 'button';

        	// script tag
        	$this->m_tagsNeedsCloserOrNot[3] = 'script';
        	
        	// body tag
        	$this->m_tagsNeedsCloserOrNot[4] = 'body';

        	// div tag
        	$this->m_tagsNeedsCloserOrNot[5] = 'div';

        	// form tag
        	$this->m_tagsNeedsCloserOrNot[6] = 'form';

        	// p tag
        	$this->m_tagsNeedsCloserOrNot[7] = 'p';

        	// h1 tag
        	$this->m_tagsNeedsCloserOrNot[8] = 'h1';

        	// h2 tag
        	$this->m_tagsNeedsCloserOrNot[9] = 'h2';

        	// h3 tag
        	$this->m_tagsNeedsCloserOrNot[10] = 'h3';

        	// h4 tag
        	$this->m_tagsNeedsCloserOrNot[11] = 'h4';

        	// h5 tag
        	$this->m_tagsNeedsCloserOrNot[12] = 'h5';  

        	// h6 tag
        	$this->m_tagsNeedsCloserOrNot[13] = 'h6';       	

        	// DOCTYPE tag
        	$this->m_tagsNeedsCloserOrNot[14] = 'DOCTYPE';

        	// input tag
        	$this->m_tagsNeedsCloserOrNot[15] = 'input';

        	// meta tag
        	$this->m_tagsNeedsCloserOrNot[16] = 'meta';
        }


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
        private function InitializeTagsNeedsCloserOrNotArray()
        {
        	// Add each tag as the key to the array with a value of 1 of the tag needs closing tag, and 0 otherwise

        	// All the following tags needs closing tag :

        	// Add head tag
        	$this->m_tagsNeedsCloserOrNot[ 'head' ] = 1;

        	// Add title tag
        	$this->m_tagsNeedsCloserOrNot[ 'title' ] = 1;

        	// Add button tag
        	$this->m_tagsNeedsCloserOrNot[ 'button' ] = 1;

        	// Add script tag
        	$this->m_tagsNeedsCloserOrNot[ 'script' ] = 1;
        	
        	// Add body tag
        	$this->m_tagsNeedsCloserOrNot[ 'body' ] = 1;

        	// Add div tag
        	$this->m_tagsNeedsCloserOrNot[ 'div' ] = 1;

        	// Add form tag
        	$this->m_tagsNeedsCloserOrNot[ 'form' ] = 1;

        	// Add p tag
        	$this->m_tagsNeedsCloserOrNot[ 'p' ] = 1;

        	// Add h1 tag
        	$this->m_tagsNeedsCloserOrNot[ 'h1' ] = 1;

        	// Add h2 tag
        	$this->m_tagsNeedsCloserOrNot[ 'h2' ] = 1;

        	// Add h3 tag
        	$this->m_tagsNeedsCloserOrNot[ 'h3' ] = 1;

        	// Add h4 tag
        	$this->m_tagsNeedsCloserOrNot[ 'h4' ] = 1;

        	// Add h5 tag
        	$this->m_tagsNeedsCloserOrNot[ 'h5' ] = 1;  

        	// Add h6 tag
        	$this->m_tagsNeedsCloserOrNot[ 'h6' ] = 1;       	

        	// All the following tags don't need closing tag :

        	// Add DOCTYPE tag
        	$this->m_tagsNeedsCloserOrNot[ 'DOCTYPE' ] = 0;

        	// Add input tag
        	$this->m_tagsNeedsCloserOrNot[ 'input' ] = 0;

        	// Add meta tag
        	$this->m_tagsNeedsCloserOrNot[ 'meta' ] = 0;
        }



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
        public function DoesTagRequireClosingTag( $tag ) 
        {
        	// Return the value inside the array using the tag as the key
        	return ( $this->m_tagsNeedsCloserOrNot[ $tag ] );
        }


  	}






?>