#include "uri.h"  

#include "../Utilities/cpp_BasicUtilities.h"  //  Fucntion ThrowExceptionIfPointerIsNULL

namespace Universe
{

    // Constructor, receives the uri parts without delimiters and create
    // the uri in normalized form
    Uri::Uri( const char* scheme, const char* authority, const char* path, const char* query, const char* fragment, int schemeDefaultPort ) throw( std::bad_alloc, Exception )
    {
    	// In every uri the scheme and path must be present, Check that their
    	// pointers are not NULL pointer
        ThrowExceptionIfPointerIsNULL( scheme, "Uri constructor failed, becuase scheme is the NULL pointer" );
        ThrowExceptionIfPointerIsNULL( path, "Uri constructor failed, becuase path is the NULL pointer" );

        // Allocate new UriInformation structure
        m_uriInformation = new UriInformation;

        // Copy the uri parts into their location in the UriInformation structure
        m_uriInformation->m_scheme = AsciiStringDuplicateReturnNULLIfPointerIsNULL( scheme );

        // Check if authority is not NULL pointer
        if ( NULL != authority )
        {
        	m_uriInformation->m_authority = ParseAuthority( authority );
        }

        m_uriInformation->m_path = AsciiStringDuplicateReturnNULLIfPointerIsNULL( path );
        m_uriInformation->m_query = AsciiStringDuplicateReturnNULLIfPointerIsNULL( query );
        m_uriInformation->m_fragment = AsciiStringDuplicateReturnNULLIfPointerIsNULL( fragment );

        m_uri = ConstructUriFromUriInformationStructure( m_uriInformation );

        // Store the scheme default port if supplied
        m_schemeDefaultPort = schemeDefaultPort;
    }

	// Constructor, upon construction parses the uri into it's components
    Uri::Uri( const char* uri ) throw( std::bad_alloc, Exception ) :
    m_uri( uri )
    {
        // Check that uri is not NULL pointer
        ThrowExceptionIfPointerIsNULL( uri, "Uri constructor failed, becuase uri is the NULL pointer" );

        // Parse the uri
        ParseUri();
    }

    // Constructor, upon construction parses the uri into it's components
    Uri::Uri( const AsciiString& uri ) throw( std::bad_alloc, Exception ) :
    m_uri( uri )
    {
        // Parse the uri
        ParseUri();
    }

    // Copy constructor
    Uri::Uri( const Uri& other ) throw( std::bad_alloc, Exception ) :
    m_uri( other.GetUri() ), m_normalizedUri( other.GetNormalizedUri() ), m_uriInformation( other.CopyUriInforamtion() ), m_schemeDefaultPort( other.GetDefaultPort() )
    {}

    // Assignment operator
    Uri& Uri::operator=( const Uri& other ) throw( std::bad_alloc, Exception )
    {
    	// Check that the two objects are not the same one ( self assignment )
    	if ( this != &other )
    	{
    		m_uri = other.GetUri();
    		m_normalizedUri = other.GetNormalizedUri();
    		m_uriInformation = other.CopyUriInforamtion();
    		m_schemeDefaultPort = other.GetDefaultPort();
    	}

    	return ( *this );
    }

    // Destructor
    Uri::~Uri() throw()
    {
    	// Use the function DeleteUriInformationStructure to delete the structure 
    	// pointed by m_uriInformation
    	DeleteUriInformationStructure( m_uriInformation );
    }

    // Delete the given UriInformation structure
    void Uri::DeleteUriInformationStructure( UriInformation* uriInformationToDelete ) throw()
    {
    	delete[] uriInformationToDelete->m_scheme;

    	// Check if the authority part of uri exist
    	if ( NULL != uriInformationToDelete->m_authority )
    	{
	    	delete[] uriInformationToDelete->m_authority->m_userInfo;
	    	delete[] uriInformationToDelete->m_authority->m_host;
	    	delete[] uriInformationToDelete->m_authority->m_port;

	    	delete uriInformationToDelete->m_authority;
	    }

    	delete[] uriInformationToDelete->m_path;
    	delete[] uriInformationToDelete->m_query;
    	delete[] uriInformationToDelete->m_fragment;

    	delete uriInformationToDelete;
    }

    // Use to display the exsiting components of the given uri
    void Uri::DisplayUriInformation() const throw()
    {
    	std::cout << std::endl;

    	std::cout << "#################################################################"  << std::endl;

    	std::cout << "URI : " << m_uri.GetAsciiStyleString() << std::endl;

    	std::cout << "URI WITH ERROR HANDLING ->  " << ErrorHandler() << std::endl;

    	if ( false == m_normalizedUri.DoesAsciiStringEmptyOrNot() )
    	{
    		std::cout << "NORMALIZED URI ->  " << m_normalizedUri.GetAsciiStyleString() << std::endl << std::endl;
    	}
    	else
    	{
    		std::cout << "NORMALIZED URI ->  NORMALIZATION OPERATION DIDN'T TOOK PLACE" << std::endl;
    	}

    	std::cout << std::endl;

    	if ( !m_uriInformation->m_scheme )
    	{
    		std::cout << "	SCHEME  -  EMPTY" << std::endl;
    	}
    	else
    	{
    		std::cout << "	SCHEME  -  " << m_uriInformation->m_scheme << std::endl;	
    	}
    	
    	if ( !m_uriInformation->m_authority )
    	{
    		std::cout << "	AUTHORITY  -  EMPTY" << std::endl;
    	}
    	else
    	{
    		DisplayAuthorityPartOfUriInformation();	
    	}

		if ( !m_uriInformation->m_path )
    	{
    		std::cout << "	PATH  -  EMPTY" << std::endl;
    	}
    	else
    	{
    		std::cout << "	PATH  -  " << m_uriInformation->m_path << std::endl;	
    	}

		if ( !m_uriInformation->m_query )
       	{
    		std::cout << "	QUERY  -  EMPTY" << std::endl;
    	}
    	else
    	{
    		std::cout << "	QUERY  -  " << m_uriInformation->m_query << std::endl;	
    	}

		if ( !m_uriInformation->m_fragment )
       	{
    		std::cout << "	FRAGMENT  -  EMPTY" << std::endl;
    	}
    	else
    	{
    		std::cout << "	FRAGMENT  -  " << m_uriInformation->m_fragment << std::endl;	
    	}

    	if ( -1 == m_schemeDefaultPort )
    	{
    		std::cout << std::endl << "SCHEME DEFAULT PORT ->	" << m_schemeDefaultPort << std::endl;
    	}
    	else
    	{
    		std::cout << std::endl << "NO SCHEME DEFAULT PORT" << std::endl;
    	}

    	std::cout << "#################################################################"  << std::endl;
    }

    // Use to display the exsiting components of the given authority part of uri
    void Uri::DisplayAuthorityPartOfUriInformation() const throw()
    {
    	std::cout << "	AUTHORITY :  " << std::endl; 

    	if ( !m_uriInformation->m_authority->m_userInfo )
    	{
    		std::cout << "		USER INFORMATION  -  EMPTY" << std::endl;
    	}
    	else
    	{
    		std::cout << "		USER INFORMATION  -  " << m_uriInformation->m_authority->m_userInfo << std::endl;	
    	}
    	
    	if ( !m_uriInformation->m_authority->m_host )
    	{
    		std::cout << "		HOST  -  EMPTY" << std::endl;
    	}
    	else
    	{
    		std::cout << "		HOST  -  " << m_uriInformation->m_authority->m_host << std::endl;	
    	}

		if ( !m_uriInformation->m_authority->m_port )
    	{
    		std::cout << "		PORT -  EMPTY" << std::endl;
    	}
    	else
    	{
    		std::cout << "		PORT  -  " << m_uriInformation->m_authority->m_port << std::endl;	
    	}

    }

    // Use to get the UriInformation structure of the uri
    Uri::UriInformation& Uri::GetUriInformation() const throw()
    {
        return ( *m_uriInformation );
    }

    // Takes a uri and parse it into the 5 generic components :
	// 1. Scheme - ends with ":"
    // 2. Authority - starts with "//"
    // 3. Path - start with "/"
    // 4. Query - start with "?"
    // 5. Fragment - start with "#"
    // And return the information in a uriInformation structure
    void Uri::ParseUri() throw( std::bad_alloc, Exception )
    {
        // Allocate the a new uriInformation structure
        Uri::UriInformation* uriInformation = new Uri::UriInformation;

        // Set all the uriInformation entries to NULL
        uriInformation->m_scheme = NULL;
        uriInformation->m_authority = NULL;
        uriInformation->m_path = NULL;
        uriInformation->m_query = NULL;
        uriInformation->m_fragment = NULL;

        // Create a buffer to save the current word
        char currentWordFromUri[512] = {0};
        // Index for currentWordFromUri
        int indexCurrentWordFromUri = 0;

        // Pointer to store the begining of uri copy, to be able to delete it later
        const char* const beginingOfUriCopy = ErrorHandler();
        // Pointer to pass on the characters of uri
        const char* currentLocationInUri = NULL;

        // Variable to indicate whether authority exist or not
        bool schemeExistOrNot = false;
        // Variable to indicate whether authority exist or not
        bool authorityExistOrNot = false;
        // Variable to indicate whether path exist or not
        bool pathExistOrNot = false;
        // Variable to indicate whether query exist or not
        bool queryExistOrNot = false;
        // Variable to indicate whether fragment exist or not
        bool fragmentExistOrNot = false;

        // Loop until the end of the uri is reached
        for ( currentLocationInUri = beginingOfUriCopy ; 0 != *currentLocationInUri ; ++currentLocationInUri )
        {

            switch ( *currentLocationInUri )
            {

                // Scheme is present - copy the string from currentWordFromUri to scheme entry in uriInformation
                // and set currentWordFromUri and indexCurrentWordFromUri back to zero
                case ':' :
                {
                    uriInformation->m_scheme = AsciiStringDuplicateAndSetStringAndIndexToZero( currentWordFromUri, indexCurrentWordFromUri );

                    schemeExistOrNot = true;

                    break;
                }

                // Authority or path exists, if there are two "/" in a row then it's authority else it's path
                case '/' :
                {
                	// Advance by one, in order to check the next character, if its two "/" in a row then it's authority
                	// else it's path
                    ++currentLocationInUri;

                    // Authority is present - set authorityExistOrNot to true
                    if ( '/' == *currentLocationInUri )
                    {
                        authorityExistOrNot = true;

                        break;
                    }
                    // Path is present - set pathExistOrNot to true 
                    else if ( false == pathExistOrNot )
                    {
                        pathExistOrNot = true;

                        // There is a possibility that the uri has an authority but it wasnt indicated by a double "/",
                        // if there is no scheme and the string containing the current word is not empty, then copy it 
                        // to the required entry in uriInformation and set currentWordFromUri and indexCurrentWordFromUri 
                        // back to zero
                        if ( ( false == schemeExistOrNot ) && ( 0 != indexCurrentWordFromUri ) )
                        {
	                    	// Store the new ascii string copy 
	                    	char* newcurrentWordFromUriCopy = AsciiStringDuplicateAndSetStringAndIndexToZero( currentWordFromUri, indexCurrentWordFromUri );

		                  	// Parse the authortiy part of uri before assigning it to m_authority
	                        uriInformation->m_authority = ParseAuthority( newcurrentWordFromUriCopy );

                        	authorityExistOrNot = false;
                        }

                    }

                    // This indicate the end of authority, check if authority exist and if it does copy
                    // it to the required entry in uriInformation and set currentWordFromUri and indexCurrentWordFromUri 
                    // back to zero, also change authorityExistOrNot back to false so this expression won't be 
                    // true anymore
                    if ( true == authorityExistOrNot )
                    {
                    	// Store the new ascii string copy 
                    	char* newcurrentWordFromUriCopy = AsciiStringDuplicateAndSetStringAndIndexToZero( currentWordFromUri, indexCurrentWordFromUri );

	                  	// Parse the authortiy part of uri before assigning it to m_authority
                        uriInformation->m_authority = ParseAuthority( newcurrentWordFromUriCopy );

                        authorityExistOrNot = false;
                    }
                    
                    // Then the "/" character is part of the path and not a delimiter or it ends the authority,
                    // anyway add it to currentWordFromUri and advance indexCurrentWordFromUri by one, and do the same
                    // to the current character currentLocationInUri is pointing to
                    AddCharacterToCurrentWordAndAddOneToIndex( currentWordFromUri[ indexCurrentWordFromUri ], '/', indexCurrentWordFromUri );
                    AddCharacterToCurrentWordAndAddOneToIndex( currentWordFromUri[ indexCurrentWordFromUri ], *currentLocationInUri, indexCurrentWordFromUri );

                    break;
                }

                // Query is present - this indicate the end of authority or path, check which one it is and copy
                // it to the required entry in uriInformation, and set currentWordFromUri and indexCurrentWordFromUri 
                // back to zero 
                case '?' :
                {
                    queryExistOrNot = true;

                    // If path exists then copy it to the required entry in uriInformation, and set currentWordFromUri 
                    // and indexCurrentWordFromUri back to zero 
                    if ( true == pathExistOrNot )
                    {
                        uriInformation->m_path = AsciiStringDuplicateAndSetStringAndIndexToZero( currentWordFromUri + 1, indexCurrentWordFromUri );
                    }
                    // Then it is authority copy it to the required entry in uriInformation, and set currentWordFromUri 
                    // and indexCurrentWordFromUri back to zero, also make the path entry not NULL but empty
                    else
                    {
        	            // Store the new ascii string copy 
                    	char* newcurrentWordFromUriCopy = AsciiStringDuplicateAndSetStringAndIndexToZero( currentWordFromUri, indexCurrentWordFromUri );

	                  	// Parse the authortiy part of uri before assigning it to m_authority
                        uriInformation->m_authority = ParseAuthority( newcurrentWordFromUriCopy );

                        uriInformation->m_path = new char;
                        *uriInformation->m_path = 0;
                    }

                    break;
                }

                // Fragment is present - this indicate the end of authority,path or query, check which one it is and copy
                // it to the required entry in uriInformation
                case '#' :
                {
                    fragmentExistOrNot = true;

                    // If query exists then copy it to the required entry in uriInformation, and set currentWordFromUri 
                    // and indexCurrentWordFromUri back to zero 
                    if ( true == queryExistOrNot )
                    {
                        uriInformation->m_query = AsciiStringDuplicateAndSetStringAndIndexToZero( currentWordFromUri, indexCurrentWordFromUri );
                    }
                    // If path exists then copy it to the required entry in uriInformation, and set currentWordFromUri 
                    // and indexCurrentWordFromUri back to zero 
                    else if ( true == pathExistOrNot )
                    {
                        uriInformation->m_path = AsciiStringDuplicateAndSetStringAndIndexToZero( currentWordFromUri + 1, indexCurrentWordFromUri );
                    }
                    // Then it is authority copy it to the required entry in uriInformation, and set currentWordFromUri 
                    // and indexCurrentWordFromUri back to zero, also make the path entry not NULL but empty
                    else
                    {
        	            // Store the new ascii string copy 
                    	char* newcurrentWordFromUriCopy = AsciiStringDuplicateAndSetStringAndIndexToZero( currentWordFromUri, indexCurrentWordFromUri );

	                  	// Parse the authortiy part of uri before assigning it to m_authority
                        uriInformation->m_authority = ParseAuthority( newcurrentWordFromUriCopy );                         
    
                        uriInformation->m_path = new char;
                        *uriInformation->m_path = 0;
                    }

                    break;
                }

                // Every character that is not part of the general uri syntax delimiters, add it to currentWordFromUri
                // and advance currentLocationInUri to the next character 
                default :
                {
                    AddCharacterToCurrentWordAndAddOneToIndex( currentWordFromUri[ indexCurrentWordFromUri ], *currentLocationInUri, indexCurrentWordFromUri );
                }

            }

        }

        // The uri has ended, the string in currentWordFromUri can represent authority, path, query or fragment, a check
        // must be done to know to which entry to assign the last piece of the uri

        // If fragment exists then copy it to the required entry in uriInformation, and set currentWordFromUri 
        // and indexCurrentWordFromUri back to zero
        if ( true == fragmentExistOrNot )
        {
            uriInformation->m_fragment = AsciiStringDuplicate( currentWordFromUri );
        }
        // If query exists then copy it to the required entry in uriInformation, and set currentWordFromUri 
        // and indexCurrentWordFromUri back to zero 
        else if ( true == queryExistOrNot )
        {      	
            	uriInformation->m_query = AsciiStringDuplicate( currentWordFromUri );
        }
        // If path exists then copy it to the required entry in uriInformation, and set currentWordFromUri 
        // and indexCurrentWordFromUri back to zero 
        else if ( true == pathExistOrNot )
        {
            	uriInformation->m_path = AsciiStringDuplicate( currentWordFromUri + 1 );
        }
        // Then it is authority copy it to the required entry in uriInformation, and set currentWordFromUri 
        // and indexCurrentWordFromUri back to zero, also make the path entry not NULL but empty
        else
        {
	        // Store the new ascii string copy 
        	char* newcurrentWordFromUriCopy = AsciiStringDuplicate( currentWordFromUri );

          	// Parse the authortiy part of uri before assigning it to m_authority
            uriInformation->m_authority = ParseAuthority( newcurrentWordFromUriCopy );                         

            uriInformation->m_path = new char;
            *uriInformation->m_path = 0;
        }

        m_uriInformation = uriInformation;

        // Delete the uri copy
        delete[] beginingOfUriCopy;
    }

    // Takes the authority part of uri and parse it into the 3 generic components :
    // 1. Scheme - ends with ":"
    // 2. Authority - starts with "//"
    // 3. Path - start with "/"
    Uri::AuthorityPartOfUriInformation* Uri::ParseAuthority( const char* authorityPartOfUri ) throw()
    {
    	// In the authortiy part of uri the host part must be present

    	// The character ":" must appear percent encoded in order to prevent interpreting
    	// it as the end of scheme part of uri, the character "@" be represented as itself
    	// or as percent encoding 

    	// The user information part of authortiy, if exist, will be delimited by a "@"
    	// from the host part of authortiy, and the host part of authortiy will be delimited
    	// from the port part of authortiy by a ":"

    	// Check that uri is not NULL pointer
        ThrowExceptionIfPointerIsNULL( authorityPartOfUri, "ParseAuthority failed, becuase authorityPartOfUri is the NULL pointer" );

    	// Allocate a new AuthorityPartOfUriInformation structure
    	AuthorityPartOfUriInformation* newAuthorityPartOfUriInformation = new AuthorityPartOfUriInformation;

    	// Set all the pointers inside newAuthorityPartOfUriInformation to NULL
    	newAuthorityPartOfUriInformation->m_userInfo = NULL;
    	newAuthorityPartOfUriInformation->m_host = NULL;
    	newAuthorityPartOfUriInformation->m_port = NULL;

    	// Create a pointer to run on authortiy part of uri
    	const char* currentCharacterOfAuthorityPartOfUri = authorityPartOfUri;

    	// Create an object to hold the distance from begining of ascii string
    	// until the first delimiter if found
    	unsigned int indexFirstDelimiter = 0;

    	// Create an object to hold the distance from the the first delimiter
    	// to the second one if found
    	unsigned int indexSecondDelimiter = 0;

    	// Create an object to store if the character "@" was found as percent encoded
    	bool characterCommercialAtSignFoundOrNot = false;

    	// Loop until the ascii string is exhausted or one of the characters "@",":" is found   
    	while ( ( 0 != *currentCharacterOfAuthorityPartOfUri )  && ( '@' != *currentCharacterOfAuthorityPartOfUri ) )
    	{

    		// Check if the current character is "%"
    		if ( '%' == *currentCharacterOfAuthorityPartOfUri )
    		{

    			// Check if the percent encoded character is "@"
    			if ( '@' == HexadecimalAsciiStringUntilOffsetToInteger< char >( currentCharacterOfAuthorityPartOfUri + 1, 2 ) )
    			{
    				characterCommercialAtSignFoundOrNot = true;

    				break;
    			}
    			// Check if the percent encoded character is ":"
    			else if ( ':' == HexadecimalAsciiStringUntilOffsetToInteger< char >( currentCharacterOfAuthorityPartOfUri + 1, 2 ) )
    			{
    				break;
    			}

    		}

    		// Add one to the indexFirstDelimiter
    		indexFirstDelimiter += 1;

    		// Advance currentCharacterOfAuthorityPartOfUri by one
    		++currentCharacterOfAuthorityPartOfUri;
    	}

    	// Check currentCharacterOfAuthorityPartOfUri contents to choose which operation to take
    	if ( 0 == *currentCharacterOfAuthorityPartOfUri )
    	{
    		// The characters "@",":" are not found in the authority part of the uri, therefore the
    		// all authority part of the uri is the host
    		newAuthorityPartOfUriInformation->m_host = AsciiStringDuplicateUntilSpecifiedOffset( authorityPartOfUri, indexFirstDelimiter );
    	}
    	else if ( ( '@' == *currentCharacterOfAuthorityPartOfUri ) || ( true == characterCommercialAtSignFoundOrNot ) )
    	{
    		// User information part of authority is present - Copy the contetns of authorityPartOfUri until the required offset 
			// into his location in AuthorityPartOfUriInformation structure 
			newAuthorityPartOfUriInformation->m_userInfo = AsciiStringDuplicateUntilSpecifiedOffset( authorityPartOfUri, indexFirstDelimiter );

			// Loop until the ascii string is exhausted or the character :" is found
	    	while ( ( 0 != *currentCharacterOfAuthorityPartOfUri ) )
	    	{

	    		// Check if the current character is "%"
	    		if ( '%' == *currentCharacterOfAuthorityPartOfUri )
	    		{

	    			// Check if the percent encoded character is ":"
	    			if ( ':' == HexadecimalAsciiStringUntilOffsetToInteger< char >( currentCharacterOfAuthorityPartOfUri + 1, 2 ) )
	    			{
	    				break;
	    			}

	    		}

	    		// Add one to the indexSecondDelimiter
	    		indexSecondDelimiter += 1;

	    		// Advance currentCharacterOfAuthorityPartOfUri by one
	    		++currentCharacterOfAuthorityPartOfUri;
	    	}

	    	// Check currentCharacterOfAuthorityPartOfUri contents to choose which operation to take
    		if ( 0 == *currentCharacterOfAuthorityPartOfUri )
    		{

    			// The character ":" is not found meaning there is no port part at the current authority
    			// Check if the character "@" was found as ascii value or as percent encoding, and
    			// Copy the contents between the two delimiters which represent the host part of authority, starting
    			// from required offset from the begining of authorityPartOfUri until the required offset from that,
    			// into his location in AuthorityPartOfUriInformation structure
    			if ( true == characterCommercialAtSignFoundOrNot )
    			{
    				// The character "@" was found as percent encoding
    				newAuthorityPartOfUriInformation->m_host = AsciiStringDuplicate( authorityPartOfUri + indexFirstDelimiter + 3 );
    			}
    			else
    			{
    				// The character "@" was found in the ascii value
    				newAuthorityPartOfUriInformation->m_host = AsciiStringDuplicate( authorityPartOfUri + indexFirstDelimiter + 1 );
    			}

    		}
    		else  //  ':' == *currentCharacterOfAuthorityPartOfUri
    		{

    			// Check if the character "@" was found as ascii value or as percent encoding, and
    			// Copy the contents between the two delimiters which represent the host part of authority, starting
    			// from required offset from the begining of authorityPartOfUri until the required offset from that,
    			// into his location in AuthorityPartOfUriInformation structure
    			if ( true == characterCommercialAtSignFoundOrNot )
    			{
    				// The character "@" was found as percent encoding
    				newAuthorityPartOfUriInformation->m_host = AsciiStringDuplicateUntilSpecifiedOffset( authorityPartOfUri + indexFirstDelimiter + 3, indexSecondDelimiter - 3 );
    			}
    			else
    			{
    				// The character "@" was found in the ascii value
    				newAuthorityPartOfUriInformation->m_host = AsciiStringDuplicateUntilSpecifiedOffset( authorityPartOfUri + indexFirstDelimiter + 1, indexSecondDelimiter - 1 );
    			}

    			// Port part of authority is present - Copy the contetns of authorityPartOfUri into his location in 
    			// AuthorityPartOfUriInformation structure
    			newAuthorityPartOfUriInformation->m_port = AsciiStringDuplicate( authorityPartOfUri + indexFirstDelimiter + indexSecondDelimiter + 3 );
    		}

    	}
    	else  //  ':' == *currentCharacterOfAuthorityPartOfUri
		{
	    	// Host part of authortiy is present - Copy the contetns of authorityPartOfUri, starting
    		// from begining of authorityPartOfUri until the required offset, into his location in 
    		// AuthorityPartOfUriInformation structure
	    	newAuthorityPartOfUriInformation->m_host = AsciiStringDuplicateUntilSpecifiedOffset( authorityPartOfUri, indexFirstDelimiter );

			// Port part of authority is present - Copy the contetns of authorityPartOfUri, starting
    		// from required offset from the begining of authorityPartOfUri into his location in 
			// AuthorityPartOfUriInformation structure
			newAuthorityPartOfUriInformation->m_port = AsciiStringDuplicate( authorityPartOfUri + indexFirstDelimiter + 3 );
    	}

    	return ( newAuthorityPartOfUriInformation );
    }


    // Comparison of two uri's is a very common operation and it requires that the two uri, will be
    // in a normalized form. Normalized form is obtain by three operation:
    // 1. Case Normalization - set all letters to their correct form ( lowercase or uppercase )
    // 2. Percent-Encoding Normalization - encode all unsafe and required characters to percent encoding
    // 3. Path Segment Normalization - remove all dot-segments from path ( "." and ".." ) 
    void Uri::NormalizeUri() throw( std::bad_alloc )
    {
    	// Check if normalization process already occuered
    	if ( false == m_normalizedUri.DoesAsciiStringEmptyOrNot() )
    	{
    		std::cout << "BEEEEEN HEREE TWICE" << std::endl;
    		// Normalization process occuered just return
    		return;
    	}

    	// Create a copy of current UriInformation structure to work on
    	UriInformation* uriInformationCopy = CopyUriInforamtion();

    	// Normalize the uri parts :

    	// Path segment normalization

    	// Remove the relative segments in path represented by "." and ".."
    	RemoveDotSegmentsFromPath( &uriInformationCopy->m_path );

    	// Case normalization

    	// Set the schme and host part of authority to lowercase
    	// Check that the authority part is present to prevent segmentation fault
    	if ( NULL != uriInformationCopy->m_authority )
    	{
			SetLettersOfSchemeAndHostPartOfAuthorityToLowercase( uriInformationCopy->m_scheme, uriInformationCopy->m_authority->m_host );
		}
		else
		{
			SetLettersOfSchemeAndHostPartOfAuthorityToLowercase( uriInformationCopy->m_scheme, NULL );
		}

		// The second part of case normalization will take part on all the normalized uri 
		// to pass one time on all the uri instead of on every part

		// Take all the part of current uriInformationCopy and construct a new uri ascii string
		m_normalizedUri = ConstructUriFromUriInformationStructure( uriInformationCopy );

		// In the normalized form the fragment part of uri doesn't appear, take that part off

		// Create a pointer to temporary hold the new ascii string without fragment
		char* normalizedUriWithoutFragment = AsciiStringDuplicateUntilDelimiter( m_normalizedUri.GetAsciiStyleString(), '#' );

		// Set inside m_normalizedUri the new ascii string without fragment
		m_normalizedUri = normalizedUriWithoutFragment;

		// Set the percent-encoding inside uri to uppercase letters
		SetLettersOfPercentEncoding();

		// Delete the copy uriInformationCopy
		DeleteUriInformationStructure( uriInformationCopy );
    }

    // Use to check if two Uri objects point to the same internet resource
    // If the Uri objects still didn't perform the normalization the operation 
    // will jappen inside the function, returns true if they are the same
    // and false otherwise
    bool Uri::operator==( Uri& other ) throw( std::bad_alloc, Exception )
    {

   		// Check if a normalized uri exist in this object
   		if ( true == m_normalizedUri.DoesAsciiStringEmptyOrNot() )
   		{
   			// Create a normalized uri
   			NormalizeUri();
   		}

   		// Check if a normalized uri exist in the other object
   		if ( true == other.GetNormalizedUri().DoesAsciiStringEmptyOrNot() )
   		{
   			// Create a normalized uri
   			other.NormalizeUri();
   		}

   		// Check if the two normalized uri's are identical
   		if ( 0 == AsciiStringCompare( m_normalizedUri.GetAsciiStyleString(), other.GetNormalizedUri().GetAsciiStyleString() ) )
   		{
   			// Normalized uri's are identical 
   			return ( true );
   		}

   		// Normalized uri's are not identical
   		return ( false );
    }

    // Create a new copy of the UriInformation structure inside the Uri class
    Uri::UriInformation* Uri::CopyUriInforamtion() const throw( std::bad_alloc )
    {
    	// No check if the pointer m_uriInformation is NULL or not, becuase
    	// at construction if the given uri is not NULL or empty there will 
    	// an uriInformation structure that m_uriInformation points to

    	// Allocate space for new uriInformation copy
    	UriInformation* newUriInformationCopy = new UriInformation;

    	// Duplicate the UriInformation parts into the new copy
    	newUriInformationCopy->m_scheme = AsciiStringDuplicateReturnNULLIfPointerIsNULL( m_uriInformation->m_scheme );

    	// Check if the authority part of uri exist
    	if ( NULL != m_uriInformation->m_authority )
    	{
    		newUriInformationCopy->m_authority = CopyAuthorityPartOfUriInformation();
    	}

    	newUriInformationCopy->m_path = AsciiStringDuplicateReturnNULLIfPointerIsNULL( m_uriInformation->m_path );
    	newUriInformationCopy->m_query = AsciiStringDuplicateReturnNULLIfPointerIsNULL( m_uriInformation->m_query );
    	newUriInformationCopy->m_fragment = AsciiStringDuplicateReturnNULLIfPointerIsNULL( m_uriInformation->m_fragment );

    	return ( newUriInformationCopy );
    }

    // Create a new copy of the AuthorityPartOfUriInformation structure insdie UriInformation
    Uri::AuthorityPartOfUriInformation* Uri::CopyAuthorityPartOfUriInformation() const throw( std::bad_alloc )
    {
    	// Allocate space for new AuthorityPartOfUriInformation copy
    	AuthorityPartOfUriInformation* newAuthorityPartOfUriInformationCopy = new AuthorityPartOfUriInformation;

    	// Duplicate the AuthorityPartOfUriInformation parts into the new copy
    	newAuthorityPartOfUriInformationCopy->m_userInfo = AsciiStringDuplicateReturnNULLIfPointerIsNULL( m_uriInformation->m_authority->m_userInfo );
    	newAuthorityPartOfUriInformationCopy->m_host = AsciiStringDuplicateReturnNULLIfPointerIsNULL( m_uriInformation->m_authority->m_host );
    	newAuthorityPartOfUriInformationCopy->m_port = AsciiStringDuplicateReturnNULLIfPointerIsNULL( m_uriInformation->m_authority->m_port );

    	return ( newAuthorityPartOfUriInformationCopy );
    }

    // Path segment normalization
    // Removes relative references "." and ".." ( dot segments ) from path, used to normalize the uri
    void Uri::RemoveDotSegmentsFromPath( char** path ) throw( std::bad_alloc )
    {
        // Pointer to move on the path string
        char* currentCharacterInPath = *path;

        // Store the length of path string
        unsigned int pathStringLength = AsciiStringLength( *path );

        // Allocate space for the path string without dot segments
        char* pathWithoutDotSegments = new char[ pathStringLength + 1 ];
        // Set the end of the ascii string pathWithoutDotSegments to 0
        pathWithoutDotSegments[ pathStringLength ] = 0;

        // Allocate space for current segment
        char currentSegment[1024] = {0};
        unsigned int indexCurrentSegment = 0;

        // Initialize the string pathWithoutDotSegments to zero
        SetAsciiStringToZero( pathWithoutDotSegments );

        // Loop until the path string is exhausted
        while ( 0 != *currentCharacterInPath )
        {

            switch ( *currentCharacterInPath )
            {

                case '.' :
                {

                    // If the only character existing is "." then break, nothing needs to be done
                    if ( 0 == *( currentCharacterInPath + 1 ) )
                    {
                        break;
                    }
                    // If the current segment is "..", the previous segment needs to be deleted
                    else if ( '.' == *( currentCharacterInPath + 1 ) && ( '/' == *( currentCharacterInPath + 2 ) ) )
                    {
                        RemoveLastSegmentFromPath( pathWithoutDotSegments );
                    }
                    // For directories and files starting with a dot - check that the previous character is
                    // "/" and the next one is not, meaning the dot doesn't represent a full segment but
                    // it's part of the name, add the dot to currentSegment
                    else if ( ( currentCharacterInPath != *path ) && ( '/' != *( currentCharacterInPath + 1 ) ) )
                    {
                        currentSegment[ indexCurrentSegment ] = '.';

                        ++indexCurrentSegment;

                        break;
                    }

                    // Advance currentCharacterInPath by one position
                    ++currentCharacterInPath;

                    break;
                }
                case '/' :
                {

                    // Check if the segment is "." or ".." then ignore it
                    if ( ( currentCharacterInPath != *path ) && ( '.' != *( currentCharacterInPath - 1 ) ) )
                    {
                        pathWithoutDotSegments = AsciiStringConcatenate( pathWithoutDotSegments, currentSegment );
                    }

                    SetAsciiStringToZero( currentSegment );

                    indexCurrentSegment = 1;

                    currentSegment[0] = '/';

                    break;
                }
                default :
                {
                    currentSegment[ indexCurrentSegment ] = *currentCharacterInPath;

                    ++indexCurrentSegment;
                }

            }

            // Advance currentCharacterInPath by one position
            ++currentCharacterInPath;
        }

        // Check that the first and second character at currentSegment are not zero then copy it
        if ( ( 0 != currentSegment[0] ) && ( 0 != currentSegment[1] ) )
        {
            pathWithoutDotSegments = AsciiStringConcatenate( pathWithoutDotSegments, currentSegment );
        }

        // Store current addres in path to delete after copy
        currentCharacterInPath = *path;

        // If the first character is "/", copy the string from the second character
        if ( '/' == *pathWithoutDotSegments )
        {
	        // Copy the new ascii string into path
	        *path = AsciiStringDuplicate( pathWithoutDotSegments + 1 );
	    }
	    // The first character is not "/"
	    else
	    {
	    	// Copy the new ascii string into path
	        *path = AsciiStringDuplicate( pathWithoutDotSegments );
	    }

        // Delete the two ascii strings not used anymore
        delete[] currentCharacterInPath;
        delete[] pathWithoutDotSegments;
    }

    // Removes the last segment, meaning that all the characters until the encounter of "/"
    // are set back to zero
    void Uri::RemoveLastSegmentFromPath( char* path ) throw( Exception )
    {
    	// Check that uri is not NULL pointer
        ThrowExceptionIfPointerIsNULL( path, "RemoveLastSegmentFromPath failed, becuase path is the NULL pointer" );

        // Check if path is an empty string, no deleting needs to be done, just return
        if ( 0 == *path )
        {
            return;
        }

        // Pointer to run on the string
        char* currentCharacterInPath = path;

        // Loop until the end of the string is found
        while ( 0 != *currentCharacterInPath )
        {
            ++currentCharacterInPath;
        }

        --currentCharacterInPath;

        // Loop until the character "/" is found or the begining of the string, and SetStringToZero
        // the characters to zero
        while ( ( '/' != *currentCharacterInPath ) && ( path != currentCharacterInPath ) )
        {
            *currentCharacterInPath = 0;

            --currentCharacterInPath;
        }

        // If the current character is "/" then set it to zero also
        if ( '/' == *currentCharacterInPath )
        {
            *currentCharacterInPath = 0;
        }

    }

	// The percent-encoding ( e.g., "%3A" ) in a uri is case-insensitive and therefore should
	// be all normalized to use uppercase leetters for the digits A-F
	void Uri::SetLettersOfPercentEncoding() throw()
	{
	    // Pointer to advance on uri
	    char* currentCharacterInNormalizaedUri = m_normalizedUri.GetAsciiStyleString();

	    // Index used to make sure the loop will only run twice when detecting "%" in the uri
	    unsigned int indexToRunTwice = 0;

	    // Loop until the uri is string is exhausted
	    while ( 0 != *currentCharacterInNormalizaedUri )
	    {

	        // Check if the current character is "%", and if it does change the hexadecimal letters
	        // A-F to uppercase
	        if ( '%' == *currentCharacterInNormalizaedUri )
	        {
	            // Advance currentCharacterInNormalizaedUri by one
	            ++currentCharacterInNormalizaedUri;

	            // Loop twice to pass on the two hexadecimal characters that come after the
	            // "%" character
	            for ( indexToRunTwice = 0 ; indexToRunTwice < 2 ; ++indexToRunTwice )
	            {

	                // Check if the current character is a lower case letter a-z and change it
	                // to uppercase
	                if ( ( 'a' <= *currentCharacterInNormalizaedUri ) && ( 'z' >= *currentCharacterInNormalizaedUri ) )
	                {
	                    // Every lowercase letter is bigger by 32 then it's uppercase letter in then
	                    // ascii numerical representation
	                    *currentCharacterInNormalizaedUri -= 32;
	                }

	            }

	        }

	        ++currentCharacterInNormalizaedUri;
	    }

	}

	// The scheme and host part of authority in a uri are case-insensitive and therefore should be normalized
	// to lowercase letters
	void Uri::SetLettersOfSchemeAndHostPartOfAuthorityToLowercase( char* scheme, char* hostPartOfAuthority ) throw( Exception )
	{

		// Use try catch clause to check if the functions throw exception,
		// if an Exception object was thrown nothing needs to be done
		// becuase one of the pointers or both were NULL 
		try
		{
			// Set the scheme part of uri into lowercase
		    SetLettersOfAsciiStringToLowercase( scheme );

		    // Set the host part in authority of uri into lowercase
		    SetLettersOfAsciiStringToLowercase( hostPartOfAuthority );
		}
		catch ( Exception& exception )
		{}	

	}

	// Receive a UriInformation structure and constructe a new uri from
	// the parts, and return it as AsciiString
	AsciiString& Uri::ConstructUriFromUriInformationStructure( Uri::UriInformation* uriInformation ) throw( std::bad_alloc, Exception )
	{
		// Check every part of UriInformation structure and, if it is not NULL 
		// concatenate it to the new uri

		// Allocate space to contain normalized uri
		AsciiString* uri = new AsciiString;

		// Scheme part
		if ( NULL != uriInformation->m_scheme )
		{
			*uri += uriInformation->m_scheme;
			*uri += ":";
		}

		// Authortiy part
		if ( NULL != uriInformation->m_authority )
		{
			*uri += "//";

			// User information part of authority
			if ( NULL != uriInformation->m_authority->m_userInfo )
			{
				*uri += uriInformation->m_authority->m_userInfo;
				*uri += "@";
			}

			// Host part of authority
			if ( NULL != uriInformation->m_authority->m_host )
			{
				*uri += uriInformation->m_authority->m_host;
			}

			// Port part of authority
			if ( NULL != uriInformation->m_authority->m_port )
			{
				// In the general uri syntax a normalized uri, would not have the port
				// part, if it is equal to the scheme default port

				// Check if the scheme default port was supplied, and if the current port 
				// and default port are equal, or that the sting representing port is empty
				if ( ( ( -1 != m_schemeDefaultPort ) && ( m_schemeDefaultPort == (int)AsciiStringToInteger( uriInformation->m_authority->m_port ) ) ) || ( 0 == uriInformation->m_authority->m_port[0] ) )
				{
					// Scheme default port exist and current port is equal to it, nothing needs to be add to uri 
				}
				// Scheme default port not supplied or current port is not equal to scheme default port
				// add the port part to uri
				else
				{
					*uri += "%3A";
					*uri += uriInformation->m_authority->m_port;
				}

			}

		}

		// Path part
		if ( NULL !=uriInformation->m_path )
		{
			*uri += "/";
			*uri += uriInformation->m_path;
		}

		// Query part
		if ( NULL != uriInformation->m_query )
		{
			*uri += "?";
			*uri += uriInformation->m_query;
		}

		// Fragment part
		if ( NULL != uriInformation->m_fragment )
		{
			*uri += "#";
			*uri += uriInformation->m_fragment;
		}

		return( *uri );
	}

	// Change specific asspects of given uri, to match the generic uri syntax,
	// and returns it as a copy to avoid changing the given uri
	char* Uri::ErrorHandler() const throw( std::bad_alloc, Exception )
	{
		// Allocate new memory space to store the uri after error handling
		char* beginingOfuriWithErrorHandling = AsciiStringDuplicate( m_uri.GetAsciiStyleString() );

		// Create pointer to run on uri copy
		char* currentCharacterInUriWithErrorHandling = beginingOfuriWithErrorHandling;

		// First error handle : 
		// Removes the character "?" or "#", if they appear in uri right before the end of
		// Example - "http://www.walla.co.il/index.html?", "http://www.walla.co.il/index.html?dlcsmcl#"

		// Loop until the ascii string is exhausted
		while ( 0 != *currentCharacterInUriWithErrorHandling )
		{
			// Advance currentCharacterInUriWithErrorHandling by one
			++currentCharacterInUriWithErrorHandling;
		}

		// Check the last character and see if it is "?" or "#" 
		if ( ( '?' == *( currentCharacterInUriWithErrorHandling - 1 ) ) || ( '#' == *( currentCharacterInUriWithErrorHandling - 1 ) ) )
		{
			// Set the NULL terminator instead of it
			*( currentCharacterInUriWithErrorHandling - 1 ) = 0;
		}

		// Return the uri after error handling
		return ( beginingOfuriWithErrorHandling );
	}

}  //  namespace Universe