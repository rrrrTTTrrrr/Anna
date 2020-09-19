function ValidateLoginForm()
{
	// Validate the E-mail

	// Store the form object into this variable
	var loginForm = document.getElementById( "LoginForm" );

	// Check that the E-mail field is not empty
	if ( loginForm.elements[ "Email" ].value === "" ) 
	{
		// Send the user that an E-mail is required
		alert( "E-mail is needed" );

		// Return false this way the data form won't be sent
		return ( false );
	}

	// Check if the given E-mail is valid
	if ( ValidateEmail( loginForm.elements[ "Email" ].value ) === false )
	{
		// The E-mail is not correct

		// Display an error message for the user
		alert( "The given E-mail is not valid" );

		// Return false this way the data form won't be sent
		return ( false );
	}

	// Validate the password

	// Check that the password field is not empty
	if ( loginForm.elements[ "Password" ].value === "" ) 
	{
		// Display for the user that a password is required
		alert( "Password is needed" );

		// Return false this way the data form won't be sent
		return ( false );
	}

	// The data in the form is valid
	return ( true );
}

