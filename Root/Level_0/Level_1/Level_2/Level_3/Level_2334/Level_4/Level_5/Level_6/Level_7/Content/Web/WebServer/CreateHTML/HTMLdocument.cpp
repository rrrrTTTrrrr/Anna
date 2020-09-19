#ifndef  HTMLDOCUMENT_CPP
#define  HTMLDOCUMENT_CPP



#include "HTMLDOCUMENT.hpp"




// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe 
{

    namespace HTML
    {


    	// Forward declarations :
    	//
    	//  NONE
    	//





//	********************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ****************************************************


















//  ***************************************************************************   OPERATORS IMPLEMENTATION   ********************************************************************











//  ************************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ****************************************************************











//	*************************************************************************   PRIVATE METHODS IMPLEMENTATION   ****************************************************************








// **************************************************************   NESTED CLASS PRIVATE METHODS IMPLEMENTATION -    ************************************************************











// *************************************************************************   FRIEND FUNCTIONS IMPLEMENTATION   ****************************************************************












    	// This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
    	// within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
    	// to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
    	// this functions are needed to avoid just that








// **************************************************************************************   TESTING   ***************************************************************************






















    	// All the following methods will be added only in test mode, they are not part of the implementation, their purpose is to
    	// help locate problems in the code


    	DEBUG_TOOL(


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      This method is used to test the object
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//          NONE
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//      1. true - if the object passed the test
    		//      2. false - otherwise
    		//
    		//  Possible errors :
    		//
    		//      1. A method does not work correctly - class Exception is thrown
    		//		2. There is no more free memory space - class std::bad_alloc is thrown
    		//		3. 
    		//
    		void HTMLdocument::Test() throw( std::bad_alloc, Exception )
    		{
    		}


    	)  //  End of debug tool











    }  //  Namespace HTML


}  //  Namespace Universe

#endif  //  HTMLDOCUMENT_CPP





