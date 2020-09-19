function LoadJavaScript( URI, scriptID, callback )
{
	// Create a new script element
	var scriptElement = document.createElement( 'script' );

	// Set the script type
	scriptElement.type = 'text/javascript';

	// Set the script ID
	scriptElement.id= scriptID;

	// Set the URI in the script element
	scriptElement.src = URI;

	// Set the callback function to be called on load
	scriptElement.onload = function()
	{
		// Use the callback
		callback();
	}

	// Add the element to the DOM tree, this will cause to the script be downloaded
	document.getElementById( 'Body' )[0].appendChild( scriptElement );
}