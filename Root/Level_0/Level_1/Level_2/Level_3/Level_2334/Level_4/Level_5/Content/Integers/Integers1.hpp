#ifndef  INTEGERS_H
#define  INTEGERS_H


#include <new>  //  Class std::bad_alloc


#include "../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef UnsignedInteger64bits
#include "../../BasicUtilities/cpp_BasicUtilities.hpp"  //  Class AloneIstand



// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part



namespace Universe
{

    namespace DataTypes
    {


    	// This is used when only declaring the object in this source file will be enough to
    	// pass compilation. The implementation is given to the compiler through the cpp source
    	// file that the object is nested within
    	//
    	// Forward declarations :
    	//
    	//  NONE
    	//


    	// Give proper treatment, by dealing with big and little endian encoding systems
    	// where it is required. The big or little endian encoding appear when dealing
    	// with byte order in memory


    	// To support move semantics every class must provide a default state. This state
    	// will be used to notify that resources were taken from current instance by
    	// a move operation :
    	//
    	//
   		// When the object is in this state it should not be used ( the object is empty )


    	// Constructor of derived object, when called, all the base class constructors are executed
    	// first, according to the order they appear in the class declaration, and only then the
    	// user code is executed

    	// Destructor of derived object, when it is called, the user code existing in the destructor
    	// itself is executed first and then all the destructors of the base objects, in an opposite
    	// way from which they were constructed


        // In the C programming language, data types are declarations for memory locations or variables 
        // that determine the characteristics of the data that may be stored and the methods ( operations ) 
        // of processing that are permitted involving them.
        //
        // The C language provides basic arithmetic types, such as integer and real number types, and syntax 
        // to build array and compound types. Several headers in the C standard library contain definitions 
        // of support types, that have additional properties, such as providing storage with an exact size, 
        // independent of the implementation


		// Class Information :
    	//
    	//  Purpose :
    	//
    	//
    	//
   	    //  Description :
   	    //
  	    //
    	//
    	//  Possible errors :
    	//
    	//
    	//
    	class Integers : private AloneIstand
        {
        public:


            // The following methods are the basic methods for each object. How to create, destroy, copy
            // and move the object. This methods if not declared the compiler generates a basic behavior
            // for them :


            // Method Information :
    	    //
    	    //  Description :
            //
    		//   	Default Constructor, used to support move semantics
    		//
    		//  Required arguments :
    		//
    		//   	User information needed :
    		//
        	//          NONE
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
        	//
        	//  Return value :
    		//
    		//   	NONE
    		//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		explicit inline Integers() throw();


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Destructor,
    		//
    		//  Required arguments :
    		//
    		//   	User information needed :
    		//
    		//          NONE
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	NONE
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline ~Integers() throw();


    		// The following methods are the interface of the object. This methods implement the capabilities of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the number of digits of an integer
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          integer - the integer that the number of digits of it should be found
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The number of digits in the integer
            //
            //  Possible errors :
            //
            //      They will come
            //
            template< typename TYPE >
            static UnsignedInteger64bits GetNumberOfDigitsInInteger( TYPE integer );


            // Template Function Information :
            //
            //  Description :
            //
            //      Transform an array containing only the ascii values for digits into an integer
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          asciiString - the address of the ascii string
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      An integer 
            //
            //  Possible errors :
            //
            //      1. The given pointer to the ascii string is NULL - a segmentation fault is created 
            //      2. The given ascii string does not end with NULL
            //      3. 
            //
            template< typename TYPE >
            static TYPE ArrayOfDigitsToInteger( const char* asciiString );


            // Template function Information :
            //
            //  Description :
            //
            //      Transform an integer into a array containing the digits of the integer
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          integer - the integer that should be stored as an ascii string
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The address of the array containing the digits of the integer
            //
            //  Possible errors :
            //
            //      1. There is no more free space - class std::bad_alloc is thrown
            //      2.
            //
            template< typename TYPE >
            static char* IntegerToArrayOfDigits( T integer );


    		// The following methods declare the overloaded operators for the object :


    		// This part of the class is dedicated for testing :


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
    		void Test() throw( std::bad_alloc, ErrorHandling::Exception );


    	private:


        	// Friend class or friend function can access private and protected members of other class in which it is declared as friend.
    		// It is sometimes useful to allow a particular class to access private members of other class. The declration of such function
    		// is private, because these functions are part of the implemntation, which the user should not be aware of. Furthermore the
    		// use of this functions is not limited to the class's scope. The following declarations are for all the function that should
    		// be friends with this class :




    	};  //  Class Integers





















//	****************************************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ************************************************************


















    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Default Constructor, used to support move semantics
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          NONE
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline Integers::Integers() throw()
        {}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Destructor,
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          NONE
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline Integers::~Integers() throw()
        {}
























//  ***********************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   *******************************************



































//  ****************************************************   TEMPLATE OR INLINE STATIC FUNCTIONS IMPLEMENTATION   ***********************************************






















        // Method Information :
        //
        //  Description :
        //
        //      Use to get the number of digits of an integer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          integer - the integer that the number of digits of it should be found
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The number of digits in the integer
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        UnsignedInteger64bits Integers::GetNumberOfDigitsInInteger( TYPE integer ) 
        {
            // Space for the number of digits
            UnsignedInteger64bits numberOfDigitsInTheInteger = 0;

            // Loop as long as the integer is not 0
            while ( 0 != integer )
            {
                // Divide the integer by 10 to strip the first digit
                integer /= 10;

                // Increase the number of digits by 1
                ++numberOfDigitsInTheInteger;
            }

            // Return the number of digits in the integer
            return ( numberOfDigitsInTheInteger );
        }


        // Template Function Information :
        //
        //  Description :
        //
        //      Transform an array containing only the ascii values for digits into an integer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          asciiString - the address of the ascii string
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      An integer 
        //
        //  Possible errors :
        //
        //      1. The given pointer to the ascii string is NULL - a segmentation fault is created 
        //      2. The given ascii string does not end with NULL
        //      3. 
        //
        template< typename T >
        T ArrayOfDigitsToInteger( const char* asciiString )
        {
            // Space to contain the integer
            T integer = 0;

            // Loop until the ascii string is exhausted
            while ( 0 != *asciiString )
            {
                // Every character in order to turn into decimal number needs to by
                // multiplied by 10 in the power of his distance from the last element.
                // And every character needs to be subtracted by 48 to get its real value
                // and not ascii value
                integer = integer * 10 + ( *asciiString - '0' );

                // Advance the pointer to the next entry
                ++asciiString;
            }

            // Return the integer 
            return ( integer );
        }


        // Template function Information :
        //
        //  Description :
        //
        //      Transform an integer into a array containing the digits of the integer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          integer - the integer that should be stored as an ascii string
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The address of the array containing the digits of the integer
        //
        //  Possible errors :
        //
        //      1. There is no more free space - class std::bad_alloc is thrown
        //      2.
        //
        template< typename T >
        char* IntegerToArrayOfDigits( T integer )
        {
            // Get the number of digits in the integer
            UnsignedInteger64bits numberOfDigitsInInteger = GetNumberOfDigitsInInteger( integer );

            // Allocate space to contain the ascii string
            char* asciiString = new char[ numberOfDigitsInInteger + 1 ];

            // Space for index to run on ascii string
            UnsignedInteger64bits asciiStringIndex = ( numberOfDigitsInInteger - 1 );

            // Loop on all the digits of the integer
            while ( 0 != integer )
            {
                // Set the string with the current digit by adding '0' to make it the ascii value
                asciiString[ asciiStringIndex ] = ( ( integer % 10 ) + '0' );

                // Subtract 1 from the string index
                --asciiStringIndex;
            }

            // Set the end of the ascii string to NULL
            asciiString[ numberOfDigitsInInteger ] = 0;

            // Return the integer as an ascii string
            return ( asciiString );
        }


























//	****************************************************************   PRIVATE METHODS IMPLEMENTATION   **************************************************************************

















// *********************************************************   INLINE OR TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   **************************************************************












        // This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
    	// within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
    	// to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
    	// this functions are needed to avoid just that








    }  //  Namespace DataTypes

}  //  Namespace Universe



#endif  // INTEGERS_H