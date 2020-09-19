#ifndef DISPLAY_HPP
#define DISPLAY_HPP


#include <iostream>  // Class std::cout, Class std::endl


#include "../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
//#include "../FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"  //  Class Assert


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{




	// When a type is forward declared, all the compiler knows is that this type exists. It does not know its size, members or methods. This is why its
	// called incomplete type. Therefore, it can not be used to declare a variable, member or base class since the compiler would need the layout of the
	// type. In other words, it can not be used for anything that requires information on the specific type. What can be done is declaring pointer and
	// reference to the incomplete type. The pointer and refernce can act as a variable, argument to a method or as the return type.
	//
	// Forward declarations :
	//
	//  NONE
	//



	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
	//
    //  Description :
    //
	//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
	//		   an interface which conatins only static methods, and does not need to never be instantied
	//
	//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	class Display
	{
	public:


		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
		// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
		// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
		// does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to display the bits of the given instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			instance - a constant refernce to an instance to display the bits of it
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< typename Type >
		static inline void Bits( const Type& instance );


		DEBUG_TOOL(

			// This part of the object is dedicated for testing :


			// Method Information :
			//
			//  Description :
			//
			//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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
			//			NONE
			//
			//  Expectations :
			//
			//		Please let the test pass lord!!
			//
			//  Possible errors :
			//
			//		It says there are no problems, which is even scarier, did I just wrote a working code??
			//
			static void Test() __attribute__ (( __unused__ ));

		)  //  End of debug tool


	private:


		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
		NoInstances_MACRO( Display )


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to move the monitor to display the next character in the next line if the given value is divided by the given number with no remainder
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. dividend - the value to divide by the divisor
        //			2. divisor - the value to check iof the dividend divids with no remainder by
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
		//  Expectations :
		//
		//		NONE
		//
        //  Possible errors :
        //
        //      They will come
        //
        static inline void MoveToNewLineIfTheGivenValueDividesByTheNumberWithNoRemainder__Private( UnsignedInteger64bits dividend, UnsignedInteger64bits divisor );


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to check if the bit state and print '1' or '0' accordingly
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          bitState - this will be used to determine the state of the bit, true for on, and false for off
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
		//  Expectations :
		//
		//		NONE
		//
        //  Possible errors :
        //
        //      They will come
        //
        static inline void DisplayOneOrZeroAccordingToTheBitState__Private( Boolean bitState );


	};  //  Class Display




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to display the bits of the given instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			instance - a constant refernce to an instance to display the bits of it
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< typename Type >
		inline void Display::Bits( const Type& instance )
		{
            // This object will be used to address the bytes of the instance
            const UnsignedInteger8bits* bytePointer = reinterpret_cast< const UnsignedInteger8bits* >( &instance );

            // Loop on all the bytes
            for ( UnsignedInteger64bits byteIndex = 0 ; byteIndex < sizeof( Type ) ; ++byteIndex )
            {

                // Loop on all the bits
                for ( SignedInteger8bits bitIndex = 7 ; bitIndex > -1 ; --bitIndex )
                {
                    // Check if the bit state is on or off, and display '1' or '0' accordingly
                    DisplayOneOrZeroAccordingToTheBitState__Private( ( bytePointer[ byteIndex ] & ( 1 << bitIndex ) ) );
                }

                // Create spaces between bytes
                std::cout << "  ";

                // Move to a new line if the byte index added 1 is divided by 8 with no remainder
                MoveToNewLineIfTheGivenValueDividesByTheNumberWithNoRemainder__Private( ( byteIndex + 1 ), 8 );
            }

            // Move the display one line down for better readability
            std::cout << std::endl << std::endl;
		}



































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































        // Method Information :
        //
        //  Description :
        //
        //      Use this method to move the monitor to display the next character in the next line if the given value is divided by the given number with no remainder
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. dividend - the value to divide by the divisor
        //			2. divisor - the value to check iof the dividend divids with no remainder by
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
		//  Expectations :
		//
		//		NONE
		//
        //  Possible errors :
        //
        //      They will come
        //
        inline void Display::MoveToNewLineIfTheGivenValueDividesByTheNumberWithNoRemainder__Private( UnsignedInteger64bits dividend, UnsignedInteger64bits divisor )
        {

            // Check if the dividend divided by the divisor has no remainder
            if ( ( dividend % divisor ) == 0 )
            {
                // The dividend divided by the divisor has no remainder

                // Move to the next line
                std::cout << std::endl;
            }
            
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to check if the bit state and print '1' or '0' accordingly
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          bitState - this will be used to determine the state of the bit, true for on, and false for off
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
		//  Expectations :
		//
		//		NONE
		//
        //  Possible errors :
        //
        //      They will come
        //
        inline void Display::DisplayOneOrZeroAccordingToTheBitState__Private( Boolean bitState )
        {

            // Check if the bit is on or not
            if ( bitState == true ) 
            {
                // The bit is on

                // Display - '1'
                std::cout << 1 << " ";
            }
            else
            {
                // The bit is off, everybody home

                // Display - '0'
                std::cout << 0 << " ";
            }

        }






}  //  Namespace Universe


#endif  // DISPLAY_HPP