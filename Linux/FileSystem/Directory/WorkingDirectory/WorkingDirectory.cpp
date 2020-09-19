#ifndef WORKINGDIRECTORY_CPP
#define WORKINGDIRECTORY_CPP


#include "WorkingDirectory.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "TestBranch/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
#endif


namespace Universe 
{

	namespace Linux
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
			//		1. An assertion failed - class Exception is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			void WorkingDirectory::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::Full< SelfType,  >();
			}

		)  //  End of debug tool











	}  //  Namespace Linux


}  //  Namespace Universe


#endif  //  WORKINGDIRECTORY_CPP





