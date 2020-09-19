#ifndef IDENTIFICATION_CPP
#define IDENTIFICATION_CPP


#include "Identification.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{

	namespace CentralProcessingUnit
    {


		// Forward declarations :
		//
		//  NONE
		//










//	***************************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ***************************************************************




































//  ************************************************************************   OPERATORS IMPLEMENTATION   ***********************************************************************




































//  ********************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ********************************************************************




































//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************




































// *****************************************************************   NESTED CLASS METHODS IMPLEMENTATION -    *****************************************************************




































// **********************************************************************   FRIEND FUNCTIONS IMPLEMENTATION   *******************************************************************




































// *********************************************************************************   TESTING   ********************************************************************************




































		// DEBUG_TOOL(

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
			void Identification::Test()
			{
				Identification testIdentification_1;

				std::cout << testIdentification_1.Model() << std::endl;

				const TranslationLookasideBuffersIdentification& mm = testIdentification_1.TranslationLookasideBuffers();

				std::cout << mm.NumberOfTranslationLookasideBuffersIdentification() << std::endl;
			}

		// )  //  End of debug tool











	}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe


#endif  //  IDENTIFICATION_CPP





