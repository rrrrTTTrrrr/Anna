 #ifndef __URI_H__
#define __URI_H__

#include <iostream>   //  std::bad_alloc

#include "../Utilities/Exception.h"  //  Class Exception
#include "../Utilities/AsciiStringOperations.h"  // Function DeleteString, Function StringDuplicateAndSetToZero, Function SetLettersOfStringToLowercase
#include "../Containers/AsciiString.h"  //  Class String


namespace Universe
{

    // Reserved characters :
    // main delimiters -> ":" / "/" / "?" / "#" / "[" / "]" / "@" ( used as part of the general uri syntax ) 
    // secondary delimiters -> "!" / "$" / "&" / "'" / "(" / ")" / "*" / "+" / "," / ";" / "=" ( used in specific schems )

    // In a uri the scheme and path must be presnet, although the path can be empty

    // The use of const at methods inside the class, is reserved for methods that basiclly
    // don't change the bits of the class. The problem starts when a method returning an 
    // handle to parts of the class, becuase now the method itself doesn't change anything
    // but using the handle changes can be made. The solution to this problem is to use 
    // the const qualifier when the method leaves the bits as they were, in order to be
    // able to use them with objects declared const, and return a const handle so that
    // no changes to the bits can happen. There is still the risk of course of changing 
    // the parts that pointers inside the object refer to, there is no way of preventing
    // this when giving an handle - we can fight with terrorists!!!

    // Use to to make the work easier with a string describing a resource in the world wide web in general uri syntax
    class Uri
    {
    public:

    	// Structure to contain the 3 pieces of the authority part, in a generic uri syntax - user information, host, port
    	typedef struct AuthorityPartOfUriInformation
    	{
    		    char* m_userInfo;
                char* m_host;
                char* m_port;

    	}AuthorityPartOfUriInformation;

        // Structure to contain the 5 pieces of the generic uri syntax - scheme, authority, path, query and fragment
        typedef struct UriInformation
        {
                char* m_scheme;
                AuthorityPartOfUriInformation* m_authority;
                char* m_path;
                char* m_query;
                char* m_fragment;

        }UriInformation;

        // Constructor, receives the uri parts without delimiters and create
        // the uri in normalized form
        explicit Uri( const char* scheme, const char* authority, const char* path, const char* query, const char* fragmentconst, int schemeDefaultPort = -1 ) throw( std::bad_alloc, Exception );

        // Constructor, upon construction parses the uri into it's components
        explicit Uri( const char* uri ) throw( std::bad_alloc, Exception );

        // Constructor, upon construction parses the uri into it's components
        explicit Uri( const AsciiString& uri ) throw( std::bad_alloc, Exception );

        // Destructor
        ~Uri() throw();

        // Copy constructor
        Uri( const Uri& other ) throw( std::bad_alloc, Exception );

        // Assignment operator
        Uri& operator=( const Uri& other ) throw( std::bad_alloc, Exception );

        // Use to get the UriInformation structure of the uri
        UriInformation& GetUriInformation() const throw();

        // Use to display the exsiting components of the given uri
        void DisplayUriInformation() const throw();

        // Use to display the exsiting components of the given authority part of uri
        void DisplayAuthorityPartOfUriInformation() const throw();

        // Comparison of two uri's is a very common operation and it requires that the two uri, will be
        // in a normalized form. Normalized form is obtain by three operation:
        // 1. Case Normalization - set all letters to their correct form ( lowercase or uppercase )
        // 2. Percent-Encoding Normalization - encode all unsafe and required characters to percent encoding
        // 3. Path Segment Normalization - remove all dot-segments from path ( "." and ".." ) 
        void NormalizeUri() throw( std::bad_alloc );

		// Use to check if two Uri objects point to the same internet resource
		// If the Uri objects still didn't perform the normalization the operation 
		// will jappen inside the function, returns true if they are the same
		// and false otherwise
        bool operator==( Uri& other ) throw( std::bad_alloc, Exception );

        // Use to check if the normalization process already happend, returns
        // true if it did, and false otherwise
        inline bool NormalizationHappendOrNot() const throw();

        // Use to get handle to the normalized uri
        inline const AsciiString& GetNormalizedUri() const throw();

        // Use to normalize the uri and get handle to the normalized uri
        inline const AsciiString& NormalizedAndGetNormalizedUri() throw();

        // Use to get handle to the uri
        inline const AsciiString& GetUri() const throw();

        // Use to get the default port
        inline unsigned int GetDefaultPort() const throw();

        // Use to change the default port
        inline void ChangeDefaultPort( unsigned int schemeDefaultPort ) throw();

    private:

        // Use to add a character to a location in a string, and add one to the index used for that string 
        inline void AddCharacterToCurrentWordAndAddOneToIndex( char& locationForCharacter, char currentCharacterToAdd, int& index ) throw();

        // Use to duplicate a string, set that string to zero, and return the location of the new copied string
        inline char* AsciiStringDuplicateAndSetStringAndIndexToZero( char* asciiString, int& index ) throw( std::bad_alloc, Exception );

        // Delete the given UriInformation structure
    	void DeleteUriInformationStructure( UriInformation* uriInformationToDelete ) throw();

        // Takes a uri and parse it into the five generic components :
        // 1. Scheme
        // 2. Authority
        // 3. Path
        // 4. Query
        // 5. Fragment
        // And return the information in a uriInformation structure
        void ParseUri() throw( std::bad_alloc, Exception );

	    // Takes the authority part of uri and parse it into the 3 generic components :
	    // 1. Scheme - ends with ":"
	    // 2. Authority - starts with "//"
	    // 3. Path - start with "/"
	    AuthorityPartOfUriInformation* ParseAuthority( const char* authorityPartOfUri ) throw();

   	    // Create a new copy of the UriInformation structure inside the Uri class
    	UriInformation* CopyUriInforamtion() const throw( std::bad_alloc );

        // Create a new copy of the AuthorityPartOfUriInformation structure insdie UriInformation
   		AuthorityPartOfUriInformation* CopyAuthorityPartOfUriInformation() const throw( std::bad_alloc );

        // Path segment normalization
        // Removes relative references "." and ".." ( dot segments ) from path, used to normalize the uri
        void RemoveDotSegmentsFromPath( char** path ) throw( std::bad_alloc );

        // Removes the last segment, meaning that all the characters until the encounter of "/"
        // are set back to zero
        void RemoveLastSegmentFromPath( char* m_path ) throw( Exception );

    	// The scheme and host part of authority in a uri are case-insensitive and therefore should be normalized
		// to lowercase letters
        void SetLettersOfSchemeAndHostPartOfAuthorityToLowercase( char* scheme, char* hostPartOfAuthority ) throw( Exception );

		// The percent-encoding ( e.g., "%3A" ) in a uri is case-insensitive and therefore should
		// be all normalized to use uppercase leetters for the digits A-F
		void SetLettersOfPercentEncoding() throw();

    	// Receive a UriInformation structure and constructe a new uri from
		// the parts, and return it as AsciiString
		AsciiString& ConstructUriFromUriInformationStructure( UriInformation* uriInformation ) throw( std::bad_alloc, Exception );

		// Change specific asspects of given uri, to match the generic uri syntax,
		// and returns it as a copy to avoid changing the given uri
		char* ErrorHandler() const throw( std::bad_alloc, Exception );

        // String to contain the origin uri given
        AsciiString m_uri;

        // String to contain the normalized uri 
        AsciiString m_normalizedUri;

        // UriInformation structure to contain the different ( not normalized ) uri components
        UriInformation* m_uriInformation;       
          
        // Object to store scheme default port if supplied
        int m_schemeDefaultPort;

    };  //  Class Uri

    // Use to add a character to a location in a string, and add one to the index used for that string
    inline void Uri::AddCharacterToCurrentWordAndAddOneToIndex( char& locationForCharacter, char currentCharacterToAdd, int& index ) throw()
    {
        locationForCharacter = currentCharacterToAdd;

        ++index;
    }

    // Use to duplicate a string, set that string to zero, and return the location of the new copied string
    inline char* Uri::AsciiStringDuplicateAndSetStringAndIndexToZero( char* asciiString, int& index ) throw( std::bad_alloc, Exception ) 
    {
        index = 0;

        return ( AsciiStringDuplicateAndSetToZero( asciiString ) );
    }

    // Use to get handle to the normalized uri
    inline const AsciiString& Uri::GetNormalizedUri() const throw()
    {
    	// Return the object m_normalizedUri
    	return ( m_normalizedUri );
    }

    // Use to normalize the uri and get handle to the normalized uri
    inline const AsciiString& Uri::NormalizedAndGetNormalizedUri() throw()
    {
    	// Normalize the uri
    	NormalizeUri();

    	// Return the object m_normalizedUri
    	return ( m_normalizedUri );
    }

    // Use to get handle to the uri
    inline const AsciiString& Uri::GetUri() const throw()
    {
    	// Return the object m_uri
    	return ( m_uri );
    }

    // Use to get the default port
    inline unsigned int Uri::GetDefaultPort() const throw()
    {
    	// Return the object m_schemeDefaultPort
    	return ( m_schemeDefaultPort );
    }

    // Use to change the default port
    inline void Uri::ChangeDefaultPort( unsigned int schemeDefaultPort ) throw()
    {
    	// Set m_schemeDefaultPort into schemeDefaultPort
    	m_schemeDefaultPort = schemeDefaultPort;
    }

    // Use to check if the normalization process already happend, returns
    // true if it did, and false otherwise
    inline bool Uri::NormalizationHappendOrNot() const throw()
    {
    	return ( m_normalizedUri.GetAsciiStringLength() );
    }


} //  namespace Universe

#endif //  __URI_H__
