#ifndef TESTFUNCTIONS_HPP
#define TESTFUNCTIONS_HPP


#include "../../../Root/Level_0/Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{

    namespace Testing
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
		class TestFunctions
		{
		public:


			// Create a type definition for the object itself
			using ObjectType = TestFunctions;


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
			// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
			// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
			// does not involve the non static data members


			static inline UnsignedInteger32bits TestFunction_1( UnsignedInteger32bits, UnsignedInteger64bits );

			static inline UnsignedInteger32bits TestFunction_2( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits );

			static inline void TestFunction_3();

			static inline UnsignedInteger32bits TestFunction_4();

	        static inline void TestFunction_5( UnsignedInteger32bits, UnsignedInteger64bits );

	        static inline void TestFunction_6( UnsignedInteger32bits*, UnsignedInteger64bits* );

            static inline void TestFunction_7( UnsignedInteger64bits* array, UnsignedInteger64bits arraySize );


		private:


			// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances_MACRO( TestFunctions )


		};  //  Class TestFunctions




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		inline UnsignedInteger32bits TestFunctions::TestFunction_1( UnsignedInteger32bits rr, UnsignedInteger64bits )
		{
			rr += 1;
			return ( 9 );
		}

		inline UnsignedInteger32bits TestFunctions::TestFunction_2( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits )
		{
			return ( 99 );
		}

		inline void TestFunctions::TestFunction_3()
		{}

		inline UnsignedInteger32bits TestFunctions::TestFunction_4()
		{
			return ( 999 );
		}

        inline void TestFunctions::TestFunction_5( UnsignedInteger32bits, UnsignedInteger64bits )
        {}

        inline void TestFunctions::TestFunction_6( UnsignedInteger32bits* pointer_1, UnsignedInteger64bits* pointer_2 )
        {
        	if ( pointer_1 != nullptr )
        	{
        		*pointer_1 = 888333;
        	}

        	if ( pointer_2 != nullptr )
        	{
        		*pointer_2 = 7777;
        	}
        }


        inline void TestFunctions::TestFunction_7( UnsignedInteger64bits* array, UnsignedInteger64bits arraySize )
        {
            
            for ( UnsignedInteger64bits index = 0 ; index < arraySize ; ++ index )
            {
                array[ index ] = index;
            }

        }





































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































    }  //  Namespace Testing

}  //  Namespace Universe


#endif  // TESTFUNCTIONS_HPP