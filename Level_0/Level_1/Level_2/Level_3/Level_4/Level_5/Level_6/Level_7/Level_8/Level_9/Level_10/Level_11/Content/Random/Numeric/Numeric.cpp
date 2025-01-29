namespace Universe 
{


namespace Random
{


namespace RunTimeGenerator
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void Numeric::UnitTest()
	{
		for ( UnsignedInteger64bits iterationNumber = 0UL ; iterationNumber < 1UL ; ++iterationNumber )
		{
			auto value_0 = Next< UnsignedInteger8bits >();
			auto value_1 = Next< UnsignedInteger16bits >();
			auto value_2 = Next< UnsignedInteger32bits >();
			auto value_3 = Next< UnsignedInteger64bits >();

			auto value_4 = Next< SignedInteger8bits >();
			auto value_5 = Next< SignedInteger16bits >();
			auto value_6 = Next< SignedInteger32bits >();
			auto value_7 = Next< SignedInteger64bits >();

			auto value_8 = Next< FloatingPoint32bits >();
			auto value_9 = Next< FloatingPoint64bits >();
			auto value_10 = Next< Boolean >();

			value_0++;
			value_1++;
			value_2++;
			value_3++;
			value_4++;
			value_5++;
			value_6++;
			value_7++;
			value_8++;
			value_9++;

			if ( value_10 == false )
			{
				++value_9;
			}
			
			UnsignedInteger8bits* const testPointer_0 = Memory::MainMemoryManager::template AllocateAndDefaultConstruct< UnsignedInteger8bits >( 4096 );

			SetMultipleNextRawPointer< UnsignedInteger8bits >( testPointer_0, 4096 / sizeof( UnsignedInteger8bits ) );
			SetMultipleNextRawPointer< UnsignedInteger16bits >( reinterpret_cast< UnsignedInteger16bits* >( testPointer_0 ), 4096 / sizeof( UnsignedInteger16bits ) );
			SetMultipleNextRawPointer< UnsignedInteger32bits >( reinterpret_cast< UnsignedInteger32bits* >( testPointer_0 ), 4096 / sizeof( UnsignedInteger32bits ) );
			SetMultipleNextRawPointer< UnsignedInteger64bits >( reinterpret_cast< UnsignedInteger64bits* >( testPointer_0 ), 4096 / sizeof( UnsignedInteger64bits ) );

			SetMultipleNextRawPointer< SignedInteger8bits >( reinterpret_cast< SignedInteger8bits* >( testPointer_0 ), 4096 / sizeof( SignedInteger8bits ) );
			SetMultipleNextRawPointer< SignedInteger16bits >( reinterpret_cast< SignedInteger16bits* >( testPointer_0 ), 4096 / sizeof( SignedInteger16bits ) );
			SetMultipleNextRawPointer< SignedInteger32bits >( reinterpret_cast< SignedInteger32bits* >( testPointer_0 ), 4096 / sizeof( SignedInteger32bits ) );
			SetMultipleNextRawPointer< SignedInteger64bits >( reinterpret_cast< SignedInteger64bits* >( testPointer_0 ), 4096 / sizeof( SignedInteger64bits ) );

			SetMultipleNextRawPointer< FloatingPoint32bits >( reinterpret_cast< FloatingPoint32bits* >( testPointer_0 ), 4096 / sizeof( FloatingPoint32bits ) );
			SetMultipleNextRawPointer< FloatingPoint64bits >( reinterpret_cast< FloatingPoint64bits* >( testPointer_0 ), 4096 / sizeof( FloatingPoint64bits ) );
			SetMultipleNextRawPointer< Boolean >( reinterpret_cast< Boolean* >( testPointer_0 ), 4096 / sizeof( Boolean ) );

			Memory::MainMemoryManager::template Done< UnsignedInteger8bits >( testPointer_0 );
		}
	}

)  //  End of debug tool



}  //  Namespace RunTimeGenerator


}  //  Namespace Random


}  //  Namespace Universe
