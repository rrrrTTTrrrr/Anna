//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< Concepts::Raw Type >
inline Type* AlignedMemoryAddress::Next( const void* const pointer, const LargestUnsignedInteger alignment )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( pointer );
	AssertValueIsPowerOfTwo( alignment );

	// The rational to get the next aligned memory address is as follows. The first stage is to cast the pointer that contains the memory address
	// to an unsigned long integer, 8 bytes, to perform arithmetics on it. The next stage is to add to the given memory address the required alignment
	// minus 1, this will ensure that the value will now have the next aligned memory address bit in state on. For example :
	//
	//		The memory address is    ->   00000101
	//		The required alignment   ->   8
	//
	//		Adding 7 to the memory address   ->   00001100
	//
	// As can be seen the required alignment is 8, and the memory address is 5, which means that the next aligned memory address is 8, and now the bit
	// that represents the value 8, the fourth bit, is on.
	//
	// The last stage is to perfrom the AND operation between the value and the negotiated alignment minus 1. This will ensure that only the last bit
	// currently on, which represents the next aligned memory address will be left on, and all the rest off. For example :
	//
	//		The negotiated value of the alignment minus 1   ->   11111000
	//
	//		Peforming the AND operation results in 			->   00001100 & 11111000   ->   00001000
	//
	// Which is the aligned memroy address for alignment of 8. One important thing is that this process only works for alignment that is a power of 2,
	// because this values are represented as only 1 bit on

	// Perform the process and return the next aligned memory address
	return ( reinterpret_cast< Type* >( ( reinterpret_cast< const LargestUnsignedInteger >( pointer ) + ( alignment - 1UL ) ) & ~( alignment - 1UL ) ) );
}


template< Concepts::Raw Type >
inline Type* AlignedMemoryAddress::Previous( const void* const pointer, const LargestUnsignedInteger alignment )
{
	// Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
	// instance is ready to be used
	AssertPointerIsNotNull( pointer );
	AssertValueIsPowerOfTwo( alignment );

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

	// Perform the process and return the previous aligned memory address
	return ( reinterpret_cast< Type* >( reinterpret_cast< const LargestUnsignedInteger >( pointer ) & ~( alignment - 1UL ) ) );
}



}  //  Namespace Memory


}  //  Namespace Universe