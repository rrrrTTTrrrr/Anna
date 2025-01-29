function ValidateCreateProfileForm()
{
	// Store the form object into this variable
	var createProfileForm = document.getElementById( "CreateProfileForm" );

	// Validate that all the text entries of the form are not empty

	// Check that the first name field is not empty
	if ( createProfileForm.elements[ "FirstName" ].value === "" ) 
	{
		// Send the user that a first name is required
		alert( "First name is needed" );

		// Return false this way the data form won't be sent
		return ( false );
	}

	// Check that the last name field is not empty 
	if ( createProfileForm.elements[ "LastName" ].value === "" ) 
	{
		// Send the user that a last name is required
		alert( "Last name is needed" );

		// Return false this way the data form won't be sent
		return ( false );
	}

	// Check that the title field is not empty
	if ( createProfileForm.elements[ "Title" ].value === "" ) 
	{
		// Send the user that a title is required
		alert( "Title is needed" );

		// Return false this way the data form won't be sent
		return ( false );
	}

	// Check that the describing text field is not empty
	if ( createProfileForm.elements[ "DescribingText" ].value === "" ) 
	{
		// Send the user that a describing text is required
		alert( "Describing text is needed" );

		// Return false this way the data form won't be sent
		return ( false );
	}

	// Validate that all the text entries consist of letters only

	// Check if the given first name is valid
	if ( ValidateTextWithLettersOnly( createProfileForm.elements[ "FirstName" ].value ) === false )
	{
		// The first name is not valid

		// Display an error message for the user
		alert( "The given first name does not consist of letters only" );

		// Return false this way the data form won't be sent
		return ( false );
	}

	// Check if the given last name is valid
	if ( ValidateTextWithLettersOnly( createProfileForm.elements[ "LastName" ].value ) === false )
	{
		// The last name is not valid

		// Display an error message for the user
		alert( "The given last name does not consist of letters only" );

		// Return false this way the data form won't be sent
		return ( false );
	}

	// Check if the given title is valid
	if ( ValidateTextWithLettersOnly( createProfileForm.elements[ "Title" ].value ) === false )
	{
		// The title is not valid

		// Display an error message for the user
		alert( "The given title does not consist of letters only" );

		// Return false this way the data form won't be sent
		return ( false );
	}

	// Check if the given describing text is valid
	if ( ValidateTextWithLettersOnly( createProfileForm.elements[ "DescribingText" ].value ) === false )
	{
		// The describing text is not valid

		// Display an error message for the user
		alert( "The given describing text does not consist of letters only" );

		// Return false this way the data form won't be sent
		return ( false );
	}


	// The data in the form is valid
	return ( true );
}