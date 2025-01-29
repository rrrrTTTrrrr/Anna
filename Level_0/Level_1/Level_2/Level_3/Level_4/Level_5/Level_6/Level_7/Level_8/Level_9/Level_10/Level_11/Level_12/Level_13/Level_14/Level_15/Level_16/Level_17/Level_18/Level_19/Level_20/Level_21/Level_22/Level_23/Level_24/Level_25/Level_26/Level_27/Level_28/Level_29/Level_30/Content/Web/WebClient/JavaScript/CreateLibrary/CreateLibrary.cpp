#ifndef  CREATELIBRARY_CPP
#define  CREATELIBRARY_CPP



#include "CREATELIBRARY.hpp"




// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe 
{

    namespace 
    {


    	// Forward declarations :
    	//
    	//  NONE
    	//





//	********************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ****************************************************






    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Assignment operator, can handle with self assignment. Will operate correctly even if the other object is in default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the object that should be copied
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	A reference to this object 
    	//
		//  Possible errors :
    	//
    	//	  They will come
    	//
    	CreateLibrary& CreateLibrary::operator=( const CreateLibrary& other ) throw( Exception )
    	{

        	// Check that this is not self assignment
        	if ( this != &other )
        	{
            	// This is not self assignment

            	// Release all the resources of this object and set the default state
            	DeleteResourcesAndSetToDefaultState();

            	// Check if the other object is in default state
            	if ( true == other.DefaultState() )
            	{
                	// The other object is in default state

                	// Nothing else needs to be done, return a reference to this object
                	return ( *this );
            	}

            	// Copy the other object resources

        	}

        	// Return a reference to this object
        	return ( *this );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Move Assignment operator, can handle with self assignment. Takes the resources from the
    	//      other object ( rvalue reference ), and set it to the default state. Will operate correctly
    	//      even if the other object is in default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the object that should be moved
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	A reference to this object
    	//
		//  Possible errors :
    	//
    	//      They will come
    	//
    	CreateLibrary& CreateLibrary::operator=( CreateLibrary&& other ) throw( Exception )
    	{

        	// Check that this is not self assignment
        	if ( this != &other )
        	{
            	// This is not self assignment

            	// Release all the resources of this object and set the default state
            	DeleteResourcesAndSetToDefaultState();

            	// Check if the other object is in default state
            	if ( true == other.DefaultState() )
            	{
                	// The other object is in default state

                	// Nothing else needs to be done, return a reference to this object
                	return ( *this );
            	}

            	// Take the other object resources

            	// Set the other object to default state
            	other.SetToDefaultState();
        	}

        	// Return a reference to this object
        	return ( *this );
    	}











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
    		void CreateLibrary::Test() throw( std::bad_alloc, Exception )
    		{
    		}


    	)  //  End of debug tool











    }  //  Namespace 


}  //  Namespace Universe

#endif  //  CREATELIBRARY_CPP





