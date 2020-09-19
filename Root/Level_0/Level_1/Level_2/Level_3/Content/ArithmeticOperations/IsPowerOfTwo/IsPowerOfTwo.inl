//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



	template< typename UnsignedIntegerType >
	inline Boolean IsPowerOfTwo< UnsignedIntegerType >::Check( UnsignedIntegerType value )
	{
		// The rational is that each integer value which is a power of 2, there will be only 1 bit on. Then in this case minus 1 of this value, will have
		// all the bits before ON, and then the AND operation between the given value and the value minus 1 will give 0. For example :
		//
		//		The value            ->    00001101
		//		The value minus 1    ->	   00001100
		//		The AND operation 	 ->    00001101 & 00001100 != 0
		//
		// In the first example the value is not a power of 2, and therefore the process does not give 0. But now :
		//
		//		The value            ->    00001000
		//		The value minus 1    ->	   00000111
		//		The AND operation 	 ->    00001000 & 00000111 == 0
		//
		// Note - the number 0 which is not a power of 2, will give also the same result and therefore will be excluded

		// Perform the process on the value and return the result
		return ( ( value != 0 ) && ( value != 1 ) && ( ( value & ( value - 1 ) ) == 0 ) );
	}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



	template< typename UnsignedIntegerType >
	inline void IsPowerOfTwo< UnsignedIntegerType >::AssertTemplateArgumentsRequirementsDuringCompileTime__Private() const
	{
		// This method will contain as much as neccessary compile time assertions to check that the given template arguments pass the requirements
		CompileTimeAssert( ( TypeCheck_UnsignedInteger< UnsignedIntegerType >::Value() == true ), "IsPowerOfTwo failed - the given template argument type should be unsigend integer" );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		template< typename UnsignedIntegerType >
		inline void IsPowerOfTwo< UnsignedIntegerType >::Test()
		{
			// This array will store all the values which are power of 2 that needs to be checked
			UnsignedInteger64bits powerOfTwoValues[] = {2UL COMMA 4UL COMMA 8UL COMMA 16UL COMMA 32UL COMMA 64UL COMMA 128UL COMMA 256UL COMMA 512UL COMMA 1024UL COMMA 2048UL COMMA 4096UL COMMA 8192UL COMMA 16384UL COMMA 32768UL COMMA 65536UL};

			// This variable will check the number of times the function returned true
			UnsignedInteger64bits numberOfTrue = 0UL;

			// Loop until the value 70000
			for ( UnsignedInteger64bits value = 0UL ; value < 70000UL ; ++value )
			{
				// Check if the current value is a power of 2
				Boolean result = IsPowerOfTwo< UnsignedInteger64bits >::Check( value );

				// Check if the result is true
				if ( result == true )
				{
					// Increase the number of true by 1
					numberOfTrue += 1UL;

					// Check if the current value appear in the array
					for ( UnsignedInteger64bits index = 0UL ; index < 17UL ; ++index )
					{

						// Check if the current value appear in the array
						if ( powerOfTwoValues[ index ] == value )
						{
							// The result seems correct
							break;
						}
						else if ( index == 16UL )
						{
							// The result does not appear in the array
							throw( Error::Exception( "IsPowerOfTwo::Test failed - 1" ) );
						}

					}

				}

			}

			// Check that only 16 times true was returned
			Assert_Test_MACRO( numberOfTrue == 16UL );
		}

	)  //  End of debug tool