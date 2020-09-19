<?php

	
	// This class will be used to as a wrapper for the standard PDO class
	class Validate
	{

		/////////////////////////////////////////////////////////      VARIABLE DECLERATIONS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\



		///////////////////////////////////////////////////////////       MAGIC METHODS      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


        /**
         *
         * Creates a new validate object
         *
         * @param NONE
         *
         */
		public function __construct()
		{}

        /**
         *
         * Ends the current pdo object
         *
         * @param NONE
         *
         */
		public function __destruct()
		{}


		/////////////////////////////////////////////////////////////      OBJECT INTERFACE      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


	    /**
         *
         * This method will be used to validate an E-mail address
         *
         * @param string $email - the E-mail that needs to be validated
         *
         */
		public static function Email( $email )
		{

			// Validate the E-mail
			return ( filter_var( $email, FILTER_VALIDATE_EMAIL ) );
		}

	    /**
         *
         * This method will be used to validate that the text consists only of letters
         *
         * @param string $text - the text that needs to be validated
         *
         */
		public static function TextHasOnlyLetters( $text )
		{
			// Create a variable to store the length of text
			$textLength = strlen( $text );

			// Loop on all the text
			for ( $textIndex = 0 ; $textIndex < $textLength ; ++$textIndex )
			{
				// Create a variable to store the current character in the text
				$currentCharacter = $text[ $textIndex ];

				// Check if the current character in the text is not a letter
				if ( ( $currentCharacter === '0' ) || ( $currentCharacter === '1' ) || ( $currentCharacter === '2' ) || ( $currentCharacter === '3' ) || 
					 ( $currentCharacter === '4' ) || ( $currentCharacter === '5' ) || ( $currentCharacter === '6' ) || ( $currentCharacter === '7' ) || 
					 ( $currentCharacter === '8' ) || ( $currentCharacter === '9' ) || ( $currentCharacter === '!' ) || ( $currentCharacter === '@' ) ||
				     ( $currentCharacter === '#' ) || ( $currentCharacter === '^' ) || ( $currentCharacter === '(' ) || ( $currentCharacter === '$' ) || 
				     ( $currentCharacter === '&' ) || ( $currentCharacter === ')' ) || ( $currentCharacter === '%' ) || ( $currentCharacter === '*' ) || 
				     ( $currentCharacter === '_' ) || ( $currentCharacter === '.' ) || ( $currentCharacter === '+' ) || ( $currentCharacter === '-' ) ||
				     ( $currentCharacter === ',' ) || ( $currentCharacter === '?' ) || ( $currentCharacter === '=' ) || ( $currentCharacter === ':' ) || 
				     ( $currentCharacter === '~' ) || ( $currentCharacter === '`' ) || ( $currentCharacter === '}' ) || ( $currentCharacter === '{' ) || 
				     ( $currentCharacter === ';' ) || ( $currentCharacter === '|' ) || ( $currentCharacter === ']' ) || ( $currentCharacter === '[' ) ||
				     ( $currentCharacter === '\'' ) || ( $currentCharacter === '"' ) || ( $currentCharacter === '\\' ) || ( $currentCharacter === '/' ) )
				{
					// Return false to let the calling script know that the text is not valid
					return ( false );
				}

			}

			// If control reached here the text consist only letters, return true
			return ( true );
		}


	}
	

?>
