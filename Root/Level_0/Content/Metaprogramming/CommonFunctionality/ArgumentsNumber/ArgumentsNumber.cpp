#ifndef  ARGUMENTSNUMBER_CPP
#define  ARGUMENTSNUMBER_CPP


#include "ArgumentsNumber.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{

    namespace Types
    {


		// Forward declarations :
		//
		//  NONE
		//




































//  ********************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ********************************************************************




































//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************




































// *********************************************************************************   TESTING   ********************************************************************************




































		DEBUG_TOOL(


			UnsignedInteger32bits Foid( UnsignedInteger32bits, UnsignedInteger32bits, UnsignedInteger32bits )
			{
				return ( 897UL );
			}

			UnsignedInteger32bits Loyd( UnsignedInteger32bits, UnsignedInteger32bits, UnsignedInteger32bits, UnsignedInteger64bits )
			{
				return ( 443UL );
			}

			void Moyd()
			{}

			class Testy
			{
			public:

				void Loco( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits, UnsignedInteger64bits, UnsignedInteger64bits )
				{}

				void Moco( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits, UnsignedInteger64bits, UnsignedInteger64bits )
				{}

				void Socko( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits )
				{}

			};


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
			void ArgumentsNumber::Test()
			{
				// Check the number of arguments to the function
				ErrorHandling::Assert< ErrorHandling::Exception >::True( ( Function( Foid ).Value() == 3UL ), "Types::ArgumentsNumber::Test failed - 1" );

				// Check the number of arguments to the function
				ErrorHandling::Assert< ErrorHandling::Exception >::True( ( Function( Loyd ).Value() == 4UL ), "Types::ArgumentsNumber::Test failed - 2" );

				// Check the number of arguments to the function
				ErrorHandling::Assert< ErrorHandling::Exception >::True( ( Function( Moyd ).Value() == 0UL ), "Types::ArgumentsNumber::Test failed - 3" );
			}

		)  //  End of debug tool











    }  //  Namespace Types


}  //  Namespace Universe


#endif  //  ARGUMENTSNUMBER_CPP





