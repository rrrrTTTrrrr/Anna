//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline Exception::Exception() :
   member_formattedErrorMessage{0}
{}


inline Exception::Exception( const char* fileName, const char* functionName, SignedInteger32bits lineNumber, const char* errorMessage ) :
   member_formattedErrorMessage{0}
{
    // Format the error message
    FormatErrorMessage__Private( fileName, functionName, lineNumber, errorMessage );
}


inline Exception::Exception( const SelfType& other ) :
   member_formattedErrorMessage{0}
{
    // Copy the formatted error message from the other instance into this, and check if the operation succeeded
    if ( CopyAsciiString__Private( other.member_formattedErrorMessage, member_formattedErrorMessage ) == false )
    {
        // Copying the ascii string failed
        return;
    }    
}


inline const AsciiCharacter* Exception::ErrorMessage() const
{
    // Return a pointer with the memory address of the error message
    return ( member_formattedErrorMessage );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean Exception::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



    }  //  Namespace Error

}  //  Namespace Universe