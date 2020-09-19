#ifndef  PERFORMACTIONACCORDINGTOTYPE_CPP
#define  PERFORMACTIONACCORDINGTOTYPE_CPP


#include "PerformActionAccordingToType.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../Test/TestObject_1/TestObject_1.hpp"
#endif


namespace Universe 
{



	// Forward declarations :
	//
	//  NONE
	//




































//  ********************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ********************************************************************




































//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************




































// *********************************************************************************   TESTING   ********************************************************************************




































	DEBUG_TOOL(

		// Method Information :
		//
		//  Description :
		//
		//		This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
		//		the functionality
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the object passed the test
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. An assertion failed - class Exception or ErrnoException is thrown
		//		2. There is no more free memory space - class std::bad_alloc is thrown
		//		3. 
		//
		void PerformActionAccordingToType::Test()
		{
			// Create an instance of primitive type
			UnsignedInteger64bits testPrimitveType_1 = 89999UL;

			// Reset the instance of the primitive type
			Reset< UnsignedInteger64bits >( testPrimitveType_1 );

			// Check that the reset works correctly
			Assert_MACRO( ( testPrimitveType_1 == 0UL ), "Test failed - 1" );

			// Create an instance of primitive type
			Boolean testPrimitveType_2 = 89999UL;

			// Reset the instance of the primitive type
			Reset< Boolean >( testPrimitveType_2 );

			// Check that the reset works correctly
			Assert_MACRO( ( testPrimitveType_2 == false ), "Test failed - 2" );

			// Create an instance of primitive type
			Test::TestObject_1< UnsignedInteger64bits > testNonPrimitiveType_1( false, 456, 4444 );

			// Check that the reset works correctly
			Assert_MACRO( ( testNonPrimitiveType_1 != Test::TestObject_1< UnsignedInteger64bits >() ), "Test failed - 3" );

			// Reset the instance of the primitive type
			Reset< Test::TestObject_1< UnsignedInteger64bits > >( testNonPrimitiveType_1 );

			// Check that the reset works correctly
			Assert_MACRO( ( testNonPrimitiveType_1 == Test::TestObject_1< UnsignedInteger64bits >() ), "Test failed - 4" );

			// Create an instance of primitive type	
			UnsignedInteger64bits testPrimitveType_3 = GetDefaultInstance< UnsignedInteger64bits >();

			// Check that the reset works correctly
			Assert_MACRO( ( testPrimitveType_3 == 0UL ), "Test failed - 5" );

			// Create an instance of primitive type
			Boolean testPrimitveType_4 = GetDefaultInstance< Boolean >();

			// Check that the reset works correctly
			Assert_MACRO( ( testPrimitveType_4 == false ), "Test failed - 6" );

			// Create an instance of primitive type
			Test::TestObject_1< UnsignedInteger64bits > testNonPrimitiveType_2( GetDefaultInstance< Test::TestObject_1< UnsignedInteger64bits > >() );

			// Check that the reset works correctly
			Assert_MACRO( ( testNonPrimitiveType_2 == Test::TestObject_1< UnsignedInteger64bits >() ), "Test failed - 7" );
		}

	)  //  End of debug tool













}  //  Namespace Universe


#endif  //  PERFORMACTIONACCORDINGTOTYPE_CPP





