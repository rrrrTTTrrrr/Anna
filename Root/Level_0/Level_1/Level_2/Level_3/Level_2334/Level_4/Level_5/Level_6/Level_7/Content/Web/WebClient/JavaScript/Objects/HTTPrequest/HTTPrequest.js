function HTTPrequest() 
{
	// Create a new XMLHttpRequest object to deal with server connection
	var m_XMLHttpRequest = new XMLHttpRequest();

	// This method will be called when the the state of the XMLHttpRequest is changed
	this.StateChange = function()
	{
		// Check the current state

		// The open method was not called yet
		if ( m_XMLHttpRequest.readyState === 0 )
		{
			console.log( "UNSET" );
		}
		// The open method was called
		else if ( m_XMLHttpRequest.readyState === 1 )
		{
			console.log( "OPENED" );
		}
		// The send method has been called
		else if ( m_XMLHttpRequest.readyState === 2 )
		{
			console.log( "HEADERS" );
		}
		// Downloading...
		else if ( m_XMLHttpRequest.readyState === 3 )
		{
			console.log( "LOADING" );
		}
		// The operation is complete
		else  //  this.XMLHttpRequest.readyState === DONE
		{
			console.log( m_XMLHttpRequest.responseText );
		}

	}

	// This method will be called when no replay has been recevied and the time given has past
	this.TimeoutReaced = function( callBack )
	{
		// Set the 
	}

	this.OpenConnection = function( GETorPOST, sourceFileURI, timeOut = 4000, asynchronos = true, stateChangeCallback = null, timeoutCallback = null, userName = null, password = null )
	{
		// Set the time out of the XMLHttpRequest object
		m_XMLHttpRequest.timeout = timeOut;

		this.StateChange();

		// Check if a callBack function has been giving to deal with the XMLHttpRequest object state changes
		if ( stateChangeCallback === null )
		{
			// A callback function was not given

			// Set the StateChange method as the callback inside the XMLHttpRequest object for when the state changes
			m_XMLHttpRequest.onreadystatechange = this.StateChange;
		}
		else
		{
			// A callback function was given

			// Set the callback function as the event handler inside the XMLHttpRequest object for when the state changes
			m_XMLHttpRequest.onreadystatechange = stateChangeCallback;
		}

		// Check if a callBack function has been giving to deal with the XMLHttpRequest object timeout request
		if ( timeoutCallback === null )
		{
			// A callback function was not given

			// Set the TimeoutReaced method as the callback inside the XMLHttpRequest object for when the state changes
			m_XMLHttpRequest.ontimeout = this.TimeoutReaced;
		}
		else
		{
			// A callback function was given

			// Set the callback function as the event handler inside the XMLHttpRequest object for when the state changes
			m_XMLHttpRequest.ontimeout = timeoutCallback;
		}

		// Use the opeN method of the XMLHttpRequest object to open the connection
		m_XMLHttpRequest.open( GETorPOST, sourceFileURI, asynchronos, userName, password );
	}

	// This method will be used to retrive the state of the XMLHttpRequest object, it can be
	// in of 5 states :
	//
	//	1. 0 - UNSET - client has been created. open method was not called yet
	//	2. 1 - OPENED - open method has been called
	//	3. 2 - HEADERS_RECEIVED - send method has been called, and headers and status are available
	//	4. 3 - LOADING - downloading, response text is only partial yet
	//	5. 4 - DONE - the operation is complete
	this.State = function()
	{
		// Return the ready state data member of the XMLHttpRequest object
		return ( m_XMLHttpRequest.readyState );
	}

	// This method will be used to send data to the server through the open channel.
	// The data can be  ->  string, blob, object, json and document. If the object
	// is not in the OPENED state the method will do nothing
	this.SendData = function( data )
	{
		// Set the header into XMLHttpRequest object 
		m_XMLHttpRequest.setRequestHeader( 'Content-type', 'application/x-www-form-urlencoded' );

		// Check that the open method was used
		if ( this.State() === 1 )
		{
			// Use the send method of the XMLHttpRequest object to send the data to the server
			m_XMLHttpRequest.send( data );
		}

	}

	// This method will be used to get the response if it is a text
	this.GetResponseText = function()
	{
		// Return the content of the responseText data member of the XMLHttpRequest object
		return ( m_XMLHttpRequest.responseText );
	}


}



