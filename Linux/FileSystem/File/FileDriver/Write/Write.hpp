#ifndef  WRITE_HPP
#define  WRITE_HPP



// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Exception/Exception.hpp"  //  Class Exception
#endif


// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part



namespace Universe
{

    namespace FileSystem
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
    	class Write
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
    		inline Write() throw();


            // Method Information :
            //
            //  Description :
            //
            //      Constructor,
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          fileAbsolutePath - the absolute path to the file
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
            inline Write( const Encoding::UnicodeString& fileAbsolutePath ) throw( Exception );


			// Method Information :
    		//
    		//  Description :
    		//
    		//   	Copy constructor, will operate correctly even if the other object is in default state
    		//
    		//  Required arguments :
    		//
    	    //   	User information needed :
    		//
    		//          other - a reference to the object that should be copied
    		//
    		//		Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to the new copy is returned
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline Write( const Write& other ) throw( Exception );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Assignment operator, can handle with self assignment. Will operate correctly even if the other object is in default state
    		//
    		//  Required arguments :
    		//
    		//		User information needed :
    		//
    		//			other - a reference to the object that should be copied
    		//
    		//		Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to this object
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline Write& operator=( const Write& other ) throw( Exception );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move constructor, takes the resources from the other object ( rvalue reference ), and set it to
    		//		the default state. Will operate correctly even if the other object is in default state
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
    		//   	NONE
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline Write( Write&& other ) throw( Exception );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move Assignment operator, can handle with self assignment. takes the resources from the
    		//    	other object ( rvalue reference ), and set it to the default state. will operate correctly
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
    		//		They will come
    		//
    		inline Write& operator=( Write&& other ) throw( Exception );


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
    		inline ~Write() throw();


            // To support Move semantics, the following 3 methods are added to every object. One method to set
            // the object into the default state, another to check if the object is in the default state,
            // and the last method to delete all the object resources and set the object to default state, in
            // this case the object inherits the methods from the base class and their behavior is correct


    		// The following methods are the interface of the object. This methods implement the capabilities of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to write to the file
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. data - a pointer to the required data to write to disk
            //          2. startingOffset - this will be used to determine where to start reading
            //          3. dataSizeInBytes - the number of bytes to read from the file
            //
            //      Information returned to the user :
            //
            //          NONE        
            //
            //  Return value :
            //
            //          The number of bytes actually written to the file. There are  situations where the number of bytes written
            //          was smaller then the required but it is not consider as error. For example, the disk is full
            //
            //  Possible errors :
            //
            //      1. The file does not exist - class ErrnoException is thrown
            //      2. There is no more free memory space - class std::bad_alloc is thrown
            //      3. The object is in default state - class Exception is thrown
            //      4. 
            //
            UnsignedInteger64bits Set( const UnsignedInteger8bits* data, UnsignedInteger64bits startingOffset, UnsignedInteger64bits dataSizeInBytes ) throw();


    		// The following methods declare the overloaded operators for the object :


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


        	// Static data members do not belong to any instnace, it belongs to the class. Like every global variable
    		// it is created with the start of the program and only destroyed when the program ends. This means that
    		// each member method can use the static data members, but not functions outside the object's scope. It
    		// restricts the access to this object use only, but rather then that acts as global variable


    		// The following methods are private. This means that only public or protected methods can use them, in other
    		// words they not part of the interface, but rather help implement it :


    		// Friend class or friend function can access private and protected members of other class in which it is declared as friend.
    		// It is sometimes useful to allow a particular class to access private members of other class. The declration of such function
    		// is private, because these functions are part of the implemntation, which the user should not be aware of. Furthermore the
    		// use of this functions is not limited to the class's scope. The following declarations are for all the function that should
    		// be friends with this class :




    	};  //  Class Write
































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
    	inline Write::Write() throw() :
        BaseFileDriver()
        {}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Constructor,
    	//
    	//  Required arguments :
    	//
    	//		User information needed :
    	//
    	//          fileAbsolutePath - the absolute path to the file
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
    	inline Write::Write( const Encoding::UnicodeString& fileAbsolutePath ) throw( Exception ) :
        BaseFileDriver( fileAbsolutePath, O_WRONLY, S_IWUSR )
        {}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Copy constructor, will operate correctly even if the other object is in default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the object that should be copied
    	//
    	//		Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	A reference to the new copy is returned
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline Write::Write( const Write& other ) throw( Exception ) :
        BaseFileDriver( other )
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Assignment operator, can handle with self assignment. Will operate correctly even if the other object is in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be copied
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this object 
        //
        //  Possible errors :
        //
        //    They will come
        //
        inline Write& Write::operator=( const Write& other ) throw( Exception )
        {
            // Call the base class assignment operator
            BaseFileDriver::operator=( other );

            // Return a reference to this object
            return ( *this );
        }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Move constructor, takes the resources from the other object ( rvalue reference ), and set it to
    	//		the default state. Will operate correctly even if the other object is in default state
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
    	//   	NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline Write::Write( Write&& other ) throw( Exception ) :
        BaseFileDriver( other )
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Move Assignment operator, can handle with self assignment. Takes the resources from the
        //      other object ( rvalue reference ), and set it to the default state. Will operate correctly
        //      even if the other object is in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be moved
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Write& Write::operator=( Write&& other ) throw( Exception )
        {
            // Call the base class move assignment operator
            BaseFileDriver::operator=( other );

            // Return a reference to this object
            return ( *this );
        }


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
    	inline Write::~Write() throw()
        {}



















//  ***************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ************************************************


























//  ****************************************************   TEMPLATE OR INLINE STATIC FUNCTIONS IMPLEMENTATION   ***********************************************










//	*****************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************










// *********************************************************   INLINE OR TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   *******************************************












    	// This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
    	// within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
    	// to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
    	// this functions are needed to avoid just that








    }  //  Namespace FileSystem

}  //  Namespace Universe



#endif  // WRITE_HPP