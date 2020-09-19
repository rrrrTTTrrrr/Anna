//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



	template< typename PointerType, UnsignedInteger64bits Alignment >
	inline PointerType* PreviousAlignedMemoryAddress< PointerType, Alignment >::Get( void* memoryAddress )
	{
		// The rational to get the previous aligned memory address is as follows. The first stage is to cast the pointer that contains the memory address
		// to an unsigned long integer, 8 bytes, to perform arithmetics on it. The next stage is to perfrom the AND operation between the value and the 
		// negotiated alignment minus 1. This will ensure that only the last bit currently on, which represents the next aligned memory address will be 
		// left on, and all the rest off. This works because the previous aligned memory address is the value where all the bits before the bit that
		// represents the alignment are off. For example :
		//
		//		The negotiated value of the alignment minus 1   ->   11111000
		//
		//		Peforming the AND operation results in 			->   00001100 & 11111000   ->   00001000
		//
		// Which is the aligned memroy address for alignment of 8. One important thing is that this process only works for alignment that is a power of 2,
		// because this values are represented as only 1 bit on

		// Perform the process and return the next aligned memory address
		return ( reinterpret_cast< PointerType* >( reinterpret_cast< UnsignedInteger64bits >( memoryAddress ) & ~( Alignment - 1UL ) ) );
	}



// *********************************************************************************   TESTING   ********************************************************************************



	DEBUG_TOOL(

		template< typename PointerType COMMA UnsignedInteger64bits Alignment >
		void PreviousAlignedMemoryAddress< PointerType COMMA Alignment >::Test()
		{}

	)  //  End of debug tool