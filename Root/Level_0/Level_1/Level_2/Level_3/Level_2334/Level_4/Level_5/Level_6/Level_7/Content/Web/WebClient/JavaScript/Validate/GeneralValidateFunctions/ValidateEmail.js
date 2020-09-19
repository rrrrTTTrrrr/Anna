function ValidateEmail( email )
{
	// This is the regular expression to validate an E-mail
	var validateFilter = /[a-z0-9!#$%&'*+/=?^_`{|}~-]+(?:\.[a-z0-9!#$%&'*+/=?^_`{|}~-]+)*@(?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?/;

	// Use the regular expression above to validate the E-mail
	if ( validateFilter.test( email ) == false )
	{
		// The E-mail is not correct

		// Return false to let the calling script know that the E-mail is not valid
		return ( false );
	}

	// The given E-mail is valid
	return ( true );
}

