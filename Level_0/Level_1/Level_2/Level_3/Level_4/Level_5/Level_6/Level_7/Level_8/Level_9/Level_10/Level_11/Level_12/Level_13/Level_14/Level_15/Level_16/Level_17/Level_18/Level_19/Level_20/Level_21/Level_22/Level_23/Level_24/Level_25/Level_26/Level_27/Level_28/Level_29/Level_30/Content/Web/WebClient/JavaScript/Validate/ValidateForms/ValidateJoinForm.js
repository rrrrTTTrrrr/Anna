function ValidateJoinForm()
{
	// Store the form object into this variable
	var joinForm = document.getElementById( 'JoinForm' );

	// Validate the E-mail

	// Check that the E-mail field is not empty
	if ( ( joinForm.elements[ "Email" ].value === "" ) || ( ValidateEmail( joinForm.elements[ "Email" ].value ) === false ) ) 
	{
		// Create a paragraph element
		var paragraph = document.createElement( "P" );

		// Set the inner text of the paragraph
		paragraph.innerText = 'A valid E-mail address is required';

		// Get the form E-mail input element
		var emailElement = document.getElementById( 'Email' );

		// Set the paragraph as a sibling of the E-mail input element
		emailElement.parentNode.insertBefore( paragraph, emailElement.nextSibling );

		// Return false this way the data won't be sent
		return ( false );
	}

	// Validate the password

	// Check that the password field is not empty
	if ( joinForm.elements[ "Password" ].value === "" ) 
	{
		// Create a paragraph element
		var paragraph = document.createElement( "P" );

		// Set the inner text of the paragraph
		paragraph.innerText = 'A password is needed';

		// Get the form Password input element
		var passwordElement = document.getElementById( 'Password' );

		// Set the paragraph as a sibling of the Password input element
		passwordElement.parentNode.insertBefore( paragraph, passwordElement.nextSibling );

		// Return false this way the data won't be sent
		return ( false );
	}

	// Check that the confirm password field is not empty
	if ( joinForm.elements[ "ConfirmPassword" ].value === "" ) 
	{
		// Create a paragraph element
		var paragraph = document.createElement( "P" );

		// Set the inner text of the paragraph
		paragraph.innerText = 'Please reconfirm the password<br>';

		// Get the form Password input element
		var confirmPasswordElement = document.getElementById( 'ConfirmPassword' );

		// Set the paragraph as a sibling of the Password input element
		confirmPasswordElement.parentNode.insertBefore( paragraph, confirmPasswordElement.nextSibling );

		// Return false this way the data form won't be sent
		return ( false );
	}

	// Check that the 2 passwords are equal
	if ( joinForm.elements[ "Password" ].value != joinForm.elements[ "ConfirmPassword" ].value ) 
	{
		// Send the user that the password don't match
		document.getElementById( 'JoinFormParagraph4' ).style.visibility = 'visible';

		// Return false this way the data form won't be sent
		return ( false );
	}

	// The data in the form is valid
	return ( true );
}

