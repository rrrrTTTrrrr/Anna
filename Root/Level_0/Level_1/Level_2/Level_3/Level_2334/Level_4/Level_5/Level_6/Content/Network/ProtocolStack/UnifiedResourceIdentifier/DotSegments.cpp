#include "../Utilities/AsciiStringOperations.h"

using namespace Universe;

// Removes the last segment, meaning that all the characters until the encounter of "/"
// are set back to zero
void RemoveLastSegmentFromPath( char* path )
{
    // Verify that path is not NULL pointer
    if ( !path )
    {
            /*throw( Exception( RemoveLastSegmentFromPath failed becuase path is NULL pointer ) );*/
    }

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

// Path segment normalization
// Removes relative references "." and ".." ( dot segments ) from path, used to normalize the uri
char* RemoveDotSegmentsFromPath( char* m_path )
{
    // Pointer to move on the path string
    char* currentCharacterInPath = m_path;

    // Allocate space for the path string without dot segments
    char* pathWithoutDotSegments = new char[ AsciiStringLength( m_path ) + 1 ];
    pathWithoutDotSegments[ AsciiStringLength( m_path ) + 1 ] = 0;

    // Allocate space for current segment
    char currentSegment[512] = {0};
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
                else if ( '.' == *( currentCharacterInPath + 1 ) )
                {
                    RemoveLastSegmentFromPath( pathWithoutDotSegments );
                }
                // For directories and files starting with a dot - check that the previous character is
                // "/" and the next one is not, meaning the dot doesn't represent a full segment but
                // it's part of the name, add the dot to currentSegment
                else if ( ( currentCharacterInPath != m_path ) && ( '/' == *( currentCharacterInPath - 1 ) ) && ( '/' != *( currentCharacterInPath + 1 ) ) )
                {
                    currentSegment[ indexCurrentSegment ] = '.';

                    ++indexCurrentSegment;
                }

                // Advance currentPathWithDotSegments by one position
                ++currentCharacterInPath;

                break;
            }
            case '/' :
            {

                // Check if the segment is "." or ".." then ignore it
                if (  ( currentCharacterInPath != m_path ) && ( '.' != *( currentCharacterInPath - 1 ) ) )
                {
                    AsciiStringConcatenate( pathWithoutDotSegments, currentSegment );
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

        ++currentCharacterInPath;
    }

    if ( 0 != currentSegment[1] )
    {
        AsciiStringConcatenate( pathWithoutDotSegments, currentSegment );
    }

    return ( pathWithoutDotSegments );
}

// Case normalization
// Change the uri parts from lowercase to uppercase letters, and the opposite, when required
/*char* SetLettersToTheCorrectFormUpperOrLower( char* uri )
{

}

// The percent-encoding ( e.g., "%3A" ) in a uri is case-insensitive and therefore should
// be all normalized to use uppercase leetters for the digits A-F
void SetLettersOfPercentEncoding( char* uri )
{
    // Pointer to advance on uri
    char* currentCharacterInUri = uri;

    // Index used to make sure the loop will only run twice when detecting "%" in the uri
    unsigned int indexToRunTwice = 0;

    // Loop until the uri is string is exhausted
    while ( 0 != *currentCharacterInUri )
    {

        // Check if the current character is "%", and if it does change the hexadecimal letters
        // A-F to uppercase
        if ( '%' == *currentCharacterInUri )
        {
            // Advance currentCharacterInUri by one
            ++currentCharacterInUri;

            // Loop twice to pass on the two hexadecimal characters that come after the
            // "%" character
            for ( indexToRunTwice = 0 ; indexToRunTwice < 2 ; ++indexToRunTwice )
            {

                // Check if the current character is a lower case letter a-z and change it
                // to uppercase
                if ( ( 'a' <= *currentCharacterInUri ) && ( 'z' >= *currentCharacterInUri ) )
                {
                    // Every lowercase letter is bigger by 32 then it's uppercase letter in then
                    // ascii numerical representation
                    *currentCharacterInUri -= 32;
                }

            }

        }

        ++currentCharacterInUri;
    }

}

// The scheme in a uri is case-insensitive and therefore should be normalized to lowercase letters
void SetLettersOfStringToLowercase( char* string )
{
    // Pointer to advance on scheme
    char* currentCharacterInString = string;

    // Loop Until the string is exhausted
    while ( 0 != *currentCharacterInString )
    {

        // Check if the current character is a uppercase letter A-Z and change it
        // to lowercase
        if ( ( 'A' <= *currentCharacterInString ) && ( 'Z' >= *currentCharacterInString ) )
        {
            // Every lowercase letter is bigger by 32 then it's uppercase letter in then
            // ascii numerical representation
            *currentCharacterInString += 32;
        }

        ++currentCharacterInString;
    }

}

typedef struct AuthorityInformation
{
        char* m_userInformation;
        char* m_host;
        char* m_port;

}AuthorityInformation;

// authority = [ userinfo "@" ] host [ ":" port ]
// If the port component is empty the character ":" should be ommited

void ParseAuthority( char* authority )
{
    // Pointer to move on the authority string
    char* currentCharacterInauthority = m_path;

    // Allocate space for the authority parts
    AuthorityInformation* authorityInformation = new AuthorityInformation;

    authorityInformation->m_userInformation = NULL;
    authorityInformation->m_host = NULL;
    authorityInformation->m_port = NULL;

    // Allocate space for current segment
    char currentWordFromAuthority[512] = {0};
    unsigned int indexcurrentWordFromAuthority = 0;

    // Loop Until the authority string is exhausted
    while ( 0 != *currentCharacterInauthority )
    {

}*/
