//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	inline Exception::Exception() :
	member_formattedErrorMessage{0}
	{}


	inline Exception::Exception( const char* fileName, const char* functionName, SignedInteger32bits lineNumber, const char* errorMessage ) :
	member_formattedErrorMessage{0}
	{
        // Format the error message
        FormatErrorMessage_Private( fileName, functionName, lineNumber, errorMessage );
	}


	inline Exception::Exception( const Exception& other ) :
	member_formattedErrorMessage{0}
	{
        // Copy the formatted error message from the other instance into this
        AsciiStringAndIntegers::CopyAsciiString( other.member_formattedErrorMessage, member_formattedErrorMessage );
	}


    inline Exception& Exception::operator=( const Exception& other )
    {
        // Create a copy of the other instance
        Exception copyOfOther( other );

        // Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted
        Swap( copyOfOther );

        // Return a reference to this instance
        return ( *this );
    }


    inline Exception::Exception( Exception&& other ) :
    Exception()
    {
        // Swap between this instance, which is in default state, and the other one
        Swap( other );
    }


    inline Exception& Exception::operator=( Exception&& other )
    {
        // Create a default constructed instance
        Exception defaultConstructedInstance;

        // Swap between the temporary instance, which is in default state, and the other instance, this will leave the other instance in default state
        defaultConstructedInstance.Swap( other );

        // Swap between this instance and the temporary one
        Swap( defaultConstructedInstance );

        // Return a reference to this instance
        return ( *this );
    }


    inline void Exception::Swap( Exception& other )
    {
        // This object will store a copy of the other instance formatted error message
        char copyOfOtherFormattedErrorMessage[256] = {0};

        // Copy the other instance formatted error message
        AsciiStringAndIntegers::CopyAsciiString( other.member_formattedErrorMessage, copyOfOtherFormattedErrorMessage );

        // Copy the formatted error message inside this instance to the other
        AsciiStringAndIntegers::CopyAsciiString( member_formattedErrorMessage, other.member_formattedErrorMessage );

        // Set the copy of the other instance formatted error message into this instance
        AsciiStringAndIntegers::CopyAsciiString( copyOfOtherFormattedErrorMessage, member_formattedErrorMessage );
    }


    inline void Exception::TellMe() const
    {            
        // Check if the instance contains an error message
        if ( member_formattedErrorMessage != 0UL )
        {
            // The instance contains valid erroe message

            // Display the error message
            std::cout << member_formattedErrorMessage << std::endl;          
        }
    }



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



	inline Boolean Exception::operator!=( const Exception& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}
