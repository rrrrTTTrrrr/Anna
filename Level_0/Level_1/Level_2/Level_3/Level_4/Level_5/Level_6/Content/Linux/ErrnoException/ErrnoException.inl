//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline ErrnoException::ErrnoException() :
	Exception()
{}


ErrnoException::ErrnoException( const char* const fileName, const char* const functionName, const SignedInteger32bits lineNumber ) :
	Exception( fileName, functionName, lineNumber, strerror( errno ) )
{}


inline ErrnoException::ErrnoException( const SelfType& other ) :
	Exception( other )
{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



inline Boolean ErrnoException::operator==( const SelfType& other ) const
{
	// Call the base object exception equal operator, and return the result
	return ( Exception::operator==( other ) );
}


inline Boolean ErrnoException::operator!=( const SelfType& other ) const
{
	// Return the negotiated value from the equal operator
	return ( !( *this == other ) );
}



}  //  Namespace Linux


}  //  Namespace Universe