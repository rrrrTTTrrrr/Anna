<?php


	/**
	*
	* Every time you call session_start(), PHP adds another
	* identical session cookie to the response header. Do this
	* enough times, and your response header becomes big enough
	* to choke the web server
	*
	* This method clears out the duplicate session cookies. You can
	* call it after each time you've called session_start(), or call it
	* just before you send your headers
	*
	*/
	function ClearDuplicateCookies() 
	{
	    
	    // If headers have already been sent, there's nothing we can do
	    if ( headers_sent() == true ) 
	    {
	    	// Return control to the calling function
	        return;
	    }

	    // Create an array to store the cookie headers
	    $cookieHeaders = array();

	    foreach ( headers_list() as $header )  
	    {
	        
	        // Identify cookie headers, search on the header the first appearnce of the sub string
	        if ( strpos( $header, 'Set-Cookie:' ) === 0 ) 
	        {
	        	// Add the header as a cookie header
	            $cookieHeaders[] = $header;
	        }

	    }

	    // Removes all cookie headers, including duplicates
	    header_remove( 'Set-Cookie' );

	    // Restore one copy of each cookie
	    foreach( array_unique( $cookies ) as $cookie ) 
	    {
	    	// Add back all the required cookie headers
	        header( $cookie, false );
	    }

	}

	// Include the template engine for HTML functionality
	require_once '../PHPobjects/PHPtemplateEngineForHTML/PHPtemplateEngineForHTML.php';

	// Create a new session on resume existing one based on session ID supplied by cookie
	session_start();

	// Clear all duplicate cookie headers
	ClearDuplicateCookies();

	// Check if the session was created or resumed
	if ( isset( $_SESSION[ 'State' ] ) === true )
	{
		// A session was resumed

		// Check if the user name variable exist
		if ( isset( $_SESSION[ 'UserName' ] ) === true )
		{
			// The user is logged in

			// Use the HTML template engine to create the home page for logged in user
			TemplateEngine(  )

		}

		// Create the session state variable
		$_SESSION[ 'State' ] = 1;
	}


        	require 'SourceCode/HTML/Header/Header.inc';






?>