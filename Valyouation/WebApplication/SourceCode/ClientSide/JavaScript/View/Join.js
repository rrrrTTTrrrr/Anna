ModuleName=JOIN,DEPENDECIES=
function SubmitButtonHandler()
{
	// Create a variable to store the join form element
	var joinFormElement = document.getElementById( 'JoinForm' );

	// Validate the data
	if ( ValidateJoinForm() === true )
	{
		// The data is valid

		// Set the action to file name of the script to call on the server side
		joinFormElement.action = 'http://localhost/SourceCode/Scripts/PHP/Infrastructure/JoinForm/JoinForm.php';

		// Set method to post
		joinFormElement.method = 'POST';

		// Submit the form
		joinFormElement.submit();
	}
	else
	{
		// The data is not valid

		// Reset the form
		joinFormElement.reset();
	}

}


document.getElementById( 'SubmitButton' ).onclick = function() { 

	SubmitButtonHandler();

};

