#ifndef  INTEGERS_CPP
#define  INTEGERS_CPP



#include "Integers.hpp"




namespace Universe 
{

    namespace DataTypes
    {



    	// Forward declarations :
    	//
    	//  NONE
    	//















//	********************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ****************************************************





































//  ****************************************************************   OPERATORS IMPLEMENTATION   *************************************************************










//	**************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************








// ***************************************************   NESTED CLASS PRIVATE METHODS IMPLEMENTATION -    *****************************************************











// **************************************************************   FRIEND FUNCTIONS IMPLEMENTATION   *********************************************************












    	// This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
    	// within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
    	// to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
    	// this functions are needed to avoid just that








// ***********************************************************************   TESTING   ***********************************************************************












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
    	void Integers::Test() throw( std::bad_alloc, ErrorHandling::Exception )
        {
            // Get the number of digitis in the number 4567
            ThrowExceptionIfExpressionIsTrue( ( GetNumberOfDigitsInInteger( 4567 ) != 4 ), "Integers::Test failed - the method for determining the number of digits in an integer does not work correctly" );

            // Get the number of digitis in the number 4
            ThrowExceptionIfExpressionIsTrue( ( GetNumberOfDigitsInInteger( 4 ) != 1 ), "Integers::Test failed - the method for determining the number of digits in an integer does not work correctly" );

            // Get the number of digitis in the number 4
            ThrowExceptionIfExpressionIsTrue( ( GetNumberOfDigitsInInteger( 345666777432 ) != 12 ), "Integers::Test failed - the method for determining the number of digits in an integer does not work correctly" );

            // Create a long integer
            UnsignedInteger64bits longInteger = 345666777432678904;

            // Get the number of digitis in the number 4
            ThrowExceptionIfExpressionIsTrue( ( GetNumberOfDigitsInInteger( longInteger ) != 18 ), "Integers::Test failed - the method for determining the number of digits in an integer does not work correctly" );
        }











    }  //  Namespace DataTypes


}  //  Namespace Universe

#endif  //  INTEGERS_CPP





