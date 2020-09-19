#ifndef  CONVERTBETWEENNUMERICSYSTEMS_HPP
#define  CONVERTBETWEENNUMERICSYSTEMS_HPP



#include "../../BasicUtilities/cpp_BasicUtilities.hpp"  //  Class AloneIstand


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Exception/Exception.hpp"  //  Class Exception
#endif


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
    	// with byte order in memory. In the byte itself the bit the is closest to the
    	// address of the byte, is the high order bit
    	//
    	//    The closest bit to the    The farest bit from the
    	//     address of the byte        address of the byte
    	//                        |      |
    	//      Byte address ->   00000000
    	//                        |      |
    	//            High order bit    Low order bit
    	//
    	// Then the value 1 will be stored this way :
    	//
    	//      Byte address ->   00000001
    	//                        |      |
    	//            High order bit    Low order bit
    	//
    	// Then in 1 byte this is always the case. But when dealing with more then 1 byte
    	// it is up to the system to decide whether the address of the first byte will
    	// contain the high order bits or the low order bits. For example for 2 bytes,
    	// store the value 1 in the 2 ways of endian encoding :
    	//
    	//    Big endian encoding :
    	//
    	//      First address of data type ->   00000000 00000001
    	//
    	//    Big endian encoding :
    	//
    	//      First address of data type ->   00000001 00000000


    	// To support move semantics every object must provide a default state. There are
    	// how ever few exceptions, as objects that their members stay exactly the same along
    	// the run of the program, objects that don't have members at all, and objects with
    	// undefined state. This default state will be used to notify that the object should
    	// not be used


    	// Constructor of derived object, when called, all the base class constructors are executed
    	// first, according to the order they appear in the class declaration, and only then the
    	// user code is executed

    	// Destructor of derived object, when it is called, the user code existing in the destructor
    	// itself is executed first and then all the destructors of the base objects, in an opposite
    	// way from which they were constructed


        // Hexadecimal - In mathematics and computing, hexadecimal ( also base 16, or hex ) is a positional 
        // numeral system with a radix, or base, of 16. It uses sixteen distinct symbols, most often the 
        // symbols 0 – 9 to represent values zero to nine, and A, B, C, D, E, F ( or alternatively a, b, c, 
        // d, e, f ) to represent values ten to fifteen. Hexadecimal numerals are widely used by computer 
        // system designers and programmers. As each hexadecimal digit represents four binary digits 
        // ( bits ), it allows a more human-friendly representation of binary-coded values. One hexadecimal 
        // digit represents a nibble ( 4 bits ), which is half of an octet or byte ( 8 bits )


		// Class Information :
    	//
    	//  Purpose :
    	//
    	//      Use this object to convert between different numeric systems. The supported numeric systems
        //      are decimal, hexadecimal and binary. The object acts as a tunnel, it has no data members
        //      or defined state, it only get a number in one numeric system and convert it to the required 
        //      numeric system
    	//
   	    //  Description :
   	    //
        //      The constructor and destructor in this object are declared private, to ensure that the object
        //      won't be instantiated
        //
    	//  Possible errors :
    	//
    	//
    	//
    	class ConvertBetweenNumericSystems : private AloneIstand
        {
        public:


    		// The following functions are declared static. Static functions do not belong to any of
    		// the instances, but rather to the class. Satic functions only have access to static
    		// data members, which means all other data members can not be used. The only purpose
    		// then of declaring a static function is when a private static data member needs to be
    		// manipulated, or some functionality needed that does not involve the non static data members


    		// All the following methods will be added only in test mode, they are not part of the implementation, their purpose is to
    		// help locate problems in the code


    		DEBUG_TOOL(


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
    			static void Test() throw( std::bad_alloc, Exception );


    		)  //  End of debug tool


    	private:


            // The methods to create and destroy this object are private, because this object shold not be
            // instantiated. The object is just used to contain related functionality


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
    		explicit inline ConvertBetweenNumericSystems() throw();


            // Method Information :
            //
            //  Description :
            //
            //      Destructor,
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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ~ConvertBetweenNumericSystems() throw();


			// Static data members do not belong to any instnace, it belongs to the class. Like every global variable
    		// it is created with the start of the program and only destroyed when the program ends. This means that
    		// each member method can use the static data members, but not functions outside the object's scope. It
    		// restricts the access to this object use only, but rather then that acts as global variable


    	};  //  Class ConvertBetweenNumericSystems



























//  ****************************************************   TEMPLATE OR INLINE STATIC FUNCTIONS IMPLEMENTATION   ***********************************************





































//	*****************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************


































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
    	inline ConvertBetweenNumericSystems::ConvertBetweenNumericSystems() throw()
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Destructor,
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
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline ConvertBetweenNumericSystems::~ConvertBetweenNumericSystems() throw()
        {}













    }  //  Namespace DataTypes

}  //  Namespace Universe



#endif  // CONVERTBETWEENNUMERICSYSTEMS_HPP