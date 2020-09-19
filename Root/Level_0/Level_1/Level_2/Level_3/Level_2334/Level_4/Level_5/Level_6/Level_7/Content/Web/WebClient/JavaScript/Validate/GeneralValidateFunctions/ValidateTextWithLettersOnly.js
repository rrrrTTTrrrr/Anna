function ValidateTextWithLettersOnly( text )
{
	// This variable will store the length of the text
	var textLength = text.length;

	// This variable will store the current character of the text
	var currentCharacter;

	// Use the regular expression above to validate the text
	for ( var textIndex = 0 ; textIndex < textLength ; ++textIndex )
	{
		// Store the current character
		currentCharacter = text.charAt( textIndex );

		// Check if the current character in the text is not a letter
		if ( ( currentCharacter === '0' ) || ( currentCharacter === '1' ) || ( currentCharacter === '2' ) || ( currentCharacter === '3' ) || 
			 ( currentCharacter === '4' ) || ( currentCharacter === '5' ) || ( currentCharacter === '6' ) || ( currentCharacter === '7' ) || 
			 ( currentCharacter === '8' ) || ( currentCharacter === '9' ) || ( currentCharacter === '!' ) || ( currentCharacter === '@' ) ||
		     ( currentCharacter === '#' ) || ( currentCharacter === '^' ) || ( currentCharacter === '(' ) || ( currentCharacter === '$' ) || 
		     ( currentCharacter === '&' ) || ( currentCharacter === ')' ) || ( currentCharacter === '%' ) || ( currentCharacter === '*' ) || 
		     ( currentCharacter === '_' ) || ( currentCharacter === '.' ) || ( currentCharacter === '+' ) || ( currentCharacter === '-' ) ||
		     ( currentCharacter === ',' ) || ( currentCharacter === '?' ) || ( currentCharacter === '=' ) || ( currentCharacter === ':' ) || 
		     ( currentCharacter === '~' ) || ( currentCharacter === '`' ) || ( currentCharacter === '}' ) || ( currentCharacter === '{' ) || 
		     ( currentCharacter === ';' ) || ( currentCharacter === '|' ) || ( currentCharacter === ']' ) || ( currentCharacter === '[' ) ||
		     ( currentCharacter === '\'' ) || ( currentCharacter === '"' ) || ( currentCharacter === '\\' ) || ( currentCharacter === '/' ) )
		{
			// Return false to let the calling script know that the text is not valid
			return ( false );
		}

	}

	// The given text is valid
	return ( true );
}