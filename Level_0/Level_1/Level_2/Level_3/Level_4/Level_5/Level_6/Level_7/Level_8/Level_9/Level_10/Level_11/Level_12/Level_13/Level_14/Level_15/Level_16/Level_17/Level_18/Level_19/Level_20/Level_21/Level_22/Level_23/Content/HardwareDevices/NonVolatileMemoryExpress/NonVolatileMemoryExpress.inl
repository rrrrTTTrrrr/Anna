// //	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



// 	inline NonVolatileMemoryExpress::NonVolatileMemoryExpress() :
// 	{}


// 	inline NonVolatileMemoryExpress::NonVolatileMemoryExpress() :
// 	{
// 	    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
// 	    // instance is ready to be used
// 		Assert( (), "" )
// 	}


// 	inline NonVolatileMemoryExpress::NonVolatileMemoryExpress( RandomInstance, const NumericRange< Type >& rangeFor = NumericRange< Type >() ) :
// 		SelfType( Random::Generator::Get< Type >() ),
// 	{}


// 	inline NonVolatileMemoryExpress::NonVolatileMemoryExpress( const SelfType& other ) :
// 	{}


// 	inline NonVolatileMemoryExpress::~NonVolatileMemoryExpress()
// 	{
// 	    // Check if the instance was constructed using the default constructor or the 'Reset' method was used, which usually signify that there
// 	    // are no resources used by the instance, and nothing needs to be done further in the destructor
// 	    ReturnIfExpressionIsTrue();
// 	}



// //  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



// 	inline Boolean NonVolatileMemoryExpress::operator==( const SelfType& other ) const
// 	{}


// 	inline Boolean NonVolatileMemoryExpress::operator!=( const SelfType& other ) const
// 	{
// 		// Return the negotiated value from the equal operator
// 		return ( !( *this == other ) );
// 	}



// //  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



// //  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************



// //	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



// // ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************



// // **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************



// 	}  //  Namespace HardwareDevices

// }  //  Namespace Universe



// #endif  // NONVOLATILEMEMORYEXPRESS