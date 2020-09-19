#ifndef AID_HPP
#define AID_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../Content/Metaprogramming/CommonFunctionality/SubstitutionFailureIsNotAnError/ProvideTypeOnlyIfAssertionIsTrue/ProvideTypeOnlyIfAssertionIsTrue.hpp"  //  Class ProvideTypeOnlyIfAssertionIsTrue
#include "../../../../../../Content/Metaprogramming/Types/TypeCheck/Integers/TypeCheck_Integer/TypeCheck_Integer.hpp"  //  Class TypeCheck_Integer
#include "../../../../../../Content/Metaprogramming/Types/TypeCheck/Integers/TypeCheck_UnsignedInteger/TypeCheck_UnsignedInteger.hpp"  //  Class TypeCheck_UnsignedInteger


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{

    namespace Memory
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
		class Aid
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
			//		Use this method to duplicate the given value as much as times as needed to fit into 8 bytes. The given template type must be smaller
			//		or equal to 8 bytes in size, and the size also must divide by 2 with no remainder. For example :
			//
	        //         		00001111             ->    00001111 00001111 00001111 00001111 00001111 00001111 00001111 00001111
	        //
	        //          	00000000 11111111    ->    00000000 11111111 00000000 11111111 00000000 11111111 00000000 11111111
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			value - the value that needs to be duplicate to spread across 8 bytes
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//			The 8 bytes representation of the given value
			//
			//  Expectations :
			//
			//
			//		1. The given template type should be integer type
			//		2. The given template type size is should be 1,2,4 or 8 bytes
			//		3. 
			//
			//  Possible errors :
			//
			//		They will come
			//
	    	template < typename IntegerType >
	    	static typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_Integer< IntegerType >::Result() == true && sizeof( IntegerType ) != 8, UnsignedInteger64bits >::Type DuplicateValueToFillEightBytes( IntegerType value );


	        // Method Information :
	        //
	        //  Description :
	        //  
	        //      Use to get the an unsigned integer with all the bits on ( 1 ) above the given index. for example :
	        //
	        //           00011111
	        //
	        //           00000111 11111111
	        //
	        //           00000000 01111111 11111111    
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //      
	        //          bitIndex - this will be used to determine the first bit to set on
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      An unsigned integer with all the bits on ( 1 ) above the given index
	        //
			//  Expectations :
			//
			//		1. The given template type should be unsigned integer
			//		2. The given template type size is should be 1,2,4 or 8 bytes
			//		3. 
			//
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        template< typename UnsignedIntegerType >
	        static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_UnsignedInteger< UnsignedIntegerType >::Result() == true, UnsignedIntegerType >::Type AllBitsOnAboveIndex( UnsignedInteger8bits bitIndex );
 

	        // Method Information :
	        //
	        //  Description :
	        //  
	        //      Use to get the an unsigned integer with all the bits off ( 0 ) above the given index. for example :
	        //
	        //           11100000
	        //
	        //           11111000 00000000
	        //
	        //           11111111 10000000 00000000     
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //      
	        //          bitIndex - this will be used to determine the first bit to set off
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      An unsigned integer with all the bits off ( 0 ) above the given index
	        //
			//  Expectations :
			//
			//		1. The given template type should be unsigned integer
			//		2. The given template type size is should be 1,2,4 or 8 bytes
			//		3. 
			//
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        template< typename UnsignedIntegerType >
	        static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_UnsignedInteger< UnsignedIntegerType >::Result() == true, UnsignedIntegerType >::Type AllBitsOffAboveIndex( UnsignedInteger8bits bitIndex );
 

	        // Method Information :
	        //
	        //  Description :
	        //  
	        //      Use to get the an unsigned integer with all the bits on ( 1 ) above and including the given index. for example :
	        //
	        //           00011111
	        //
	        //           00000111 11111111
	        //
	        //           00000000 01111111 11111111    
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //      
	        //          bitIndex - this will be used to determine the first bit to set on
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      An unsigned integer with all the bits on ( 1 ) above and including the given index
	        //
			//  Expectations :
			//
			//		1. The given template type should be unsigned integer
			//		2. The given template type size is should be 1,2,4 or 8 bytes
			//		3. 
			//
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        template< typename UnsignedIntegerType >
	        static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_UnsignedInteger< UnsignedIntegerType >::Result() == true, UnsignedIntegerType >::Type AllBitsOnAboveAndIncludingIndex( UnsignedInteger8bits bitIndex );
 

	        // Method Information :
	        //
	        //  Description :
	        //  
	        //      Use to get the an unsigned integer with all the bits off ( 0 ) above and including the given index. for example :
	        //
	        //           11100000
	        //
	        //           11111000 00000000
	        //
	        //           11111111 10000000 00000000      
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //      
	        //          bitIndex - this will be used to determine the first bit to set off
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      An unsigned integer with all the bits off ( 0 ) above and including the given index
	        //
			//  Expectations :
			//
			//		1. The given template type should be unsigned integer
			//		2. The given template type size is should be 1,2,4 or 8 bytes
			//		3. 
			//
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        template< typename UnsignedIntegerType >
	        static inline typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheck_UnsignedInteger< UnsignedIntegerType >::Result() == true, UnsignedIntegerType >::Type AllBitsOffAboveAndIncludingIndex( UnsignedInteger8bits bitIndex );
 

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
			NoInstances_MACRO( Aid )
			

		};  //  Class Aid



#include "Aid.inl"

		

    }  //  Namespace Memory

}  //  Namespace Universe


#endif  // AID_HPP