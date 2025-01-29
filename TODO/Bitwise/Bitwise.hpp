#ifndef  BITWISE_HPP
#define  BITWISE_HPP


#include "../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../DataTypes/Bit/Bit.hpp"  //  Class Bit


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../ErrorHandling/Exception/Exception.hpp"  //  Class Exception
#endif


// When a function name ends with the suffix IMP, the function is not part of the object interface ( capabilities ), it only used as aid to the function that
// it is, implementing only spsecific part


namespace Universe
{

    namespace Abilities
    {


    	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
    	// cpp source file that the object is nested within
    	//
    	// Forward declarations :
    	//
    	//  NONE
    	//


    	// Give proper treatment, by dealing with big and little endian encoding systems where it is required. The big or little endian encoding appear when dealing
    	// with byte order in memory. In the byte itself the bit the is closest to the address of the byte, is the high order bit
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
    	// Then in 1 byte this is always the case. But when dealing with more then 1 byte it is up to the system to decide whether the address of the first byte will
    	// contain the high order bits or the low order bits. For example for 2 bytes, store the value 1 in the 2 ways of endian encoding :
    	//
    	//    Big endian encoding :
    	//
    	//      First address of data type ->   00000000 00000001
    	//
    	//    Big endian encoding :
    	//
    	//      First address of data type ->   00000001 00000000


    	// To support move semantics every object must provide a default state. There are  how ever few exceptions, as objects that their members stay exactly the same along
    	// the run of the program, objects that don't have members at all, and objects with undefined state. This default state will be used to notify that the object should
    	// not be used


    	// Class Information :
    	//
    	//  Purpose :
    	//
    	//      This object should be inherted by objects that deal with basic types data. The addition makes the inherting object to appear as the data itself, while has much
        //      more functionality behind it
    	//
   	    //  Description :
   	    //
        //      1. This object is used as a base object in inheritance. Therefore it must have a few methods virtual. When an object has a virtual method, the C++ 
        //         automatically creates a table with all the pointers to the virtual methods, where the pointer to the table is stored in the beginning of the object. The 
        //         problem arises when a new method needs to be created with the same signature as one in the base object, and the use of pointers. Take a look at next 
        //         example :
        //
        //             class Base
        //             {
        //                 void Display() { cout << "Lord" << endl; }
        //             };
        //
        //             class Derived : public Base
        //             {
        //                 void Display(); { cout << "Help Me" << endl; }    -> Derived inherits Display from Base but needs another behavior
        //             };
        //
        //         Now if a call is made :
        //
        //             Base* base = new Base;
        //             Derived* derived = new Derived;
        //
        //             base->Display( 5 );   -> Outputs "Lord"
        //             derived->Display();   -> Outputs "Help Me"
        //
        //         So far so good, a normal method is called by the static type of the pointer. This means no matter what the object the pointer is pointing to it will call 
        //         the method of the type he was declared as. This is a problematic behavior in inheritance, we need to point to derived objects with base pointers and that 
        //         the correct method will be called. But now :
        //
        //             void Do( Base* base ) { base->Display(); }
        //
        //             Base* base = new Base;
        //             Derived* derived = new Derived;
        //
        //             Do( base );        -> Outputs "Lord"
        //             Do( derived );     -> Outputs "Lord"
        //
        //         This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is picked dynamically by the 
        //         actual type of the object. This is done by the pointer in the beginning of the object that points to the virtual table of the type. Of course it can be 
        //         overloaded to the derived, but then if there is a deep inheritance a method will be needed to be overloaded for each one
  	    //
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename DerivedObjectType >
        class Bitwise
        {
        public:


            // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
            // generates a basic behavior for them :


            // Method Information :
            //
            //  Description :
            //
            //      Default Constructor, used to support move semantics
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
            inline Bitwise() = default;


            // Method Information :
            //
            //  Description :
            //
            //      Copy constructor, will operate correctly even if the other object is in default state
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
            //      A reference to the new copy is returned
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Bitwise( const Bitwise< DerivedObjectType >& other ) = default;


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
            //      They will come
            //
            inline Bitwise< DerivedObjectType >& operator=( const Bitwise< DerivedObjectType >& other ) = default;


            // Method Information :
            //
            //  Description :
            //
            //      Move constructor, takes the resources from the other object ( rvalue reference ), and set it to
            //      the default state. Will operate correctly even if the other object is in default state
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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Bitwise( Bitwise< DerivedObjectType >&& other ) = default;


            // Method Information :
            //
            //  Description :
            //
            //      Move Assignment operator, can handle with self assignment. takes the resources from the
            //      other object ( rvalue reference ), and set it to the default state. will operate correctly
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
            inline Bitwise< DerivedObjectType >& operator=( Bitwise< DerivedObjectType >&& other ) = default;


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
            virtual inline ~Bitwise() = default;


    		// The following methods declare the overloaded operators for the object :


            // Method Information :
            //
            //  Description :
            //
            //      This method will be used to allow explicit ( through static cast ) or implicit conversion of the derived object to the bit inside.
            //      It will allow a things :
            //
            //          1. expressions of the type ->  bit & derivedObjectType< bit >
            //          2. it will be easier to get to the data
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
            //      There is no written return type, but it will return the derived object converted to it's template type
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline operator Boolean() const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the AND operation ( & ) of the data inside the object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        Result of the AND operation ( & ) of the data inside the object and the right side operand
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline Boolean operator&( Boolean rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the AND operation ( & ) of the data inside the object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        Result of the AND operation ( & ) of the data inside the object and the right side operand
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline Boolean operator&( const DataTypes::Bit& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the AND operation ( & ) of the data inside the object and the right side operand object
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - a reference to another template type object
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        Result of the AND operation ( & ) of the data inside the object and the right side operand object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline Boolean operator&( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the OR operation ( | ) of the data inside the object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        Result of the OR operation ( | ) of the data inside the object and the right side operand
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline Boolean operator|( Boolean rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the OR operation ( | ) of the data inside the object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        Result of the OR operation ( | ) of the data inside the object and the right side operand
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline Boolean operator|( const DataTypes::Bit& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the OR operation ( | ) of the data inside the object and the right side operand object
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - a reference to another template type object
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        Result of the OR operation ( | ) of the data inside the object and the right side operand object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline Boolean operator|( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the XOR operation ( ^ ) of the data inside the object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        Result of the XOR operation ( ^ ) of the data inside the object and the right side operand
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline Boolean operator^( Boolean rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the XOR operation ( ^ ) of the data inside the object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        Result of the XOR operation ( ^ ) of the data inside the object and the right side operand
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline Boolean operator^( const DataTypes::Bit& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the XOR operation ( ^ ) of the data inside the object and the right side operand object
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - a reference to another template type object
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        Result of the XOR operation ( ^ ) of the data inside the object and the right side operand object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline Boolean operator^( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the AND operation ( & ) on the data inside this object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        A reference to this object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator&=( Boolean rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the AND operation ( & ) on the data inside this object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        A reference to this object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator&=( const DataTypes::Bit& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the AND operation ( & ) on the data inside this object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        A reference to this object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator&=( const DerivedObjectType& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the OR operation ( | ) on the data inside this object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        A reference to this object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator|=( Boolean rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the OR operation ( | ) on the data inside this object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        A reference to this object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator|=( const DataTypes::Bit& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the OR operation ( | ) on the data inside this object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        A reference to this object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator|=( const DerivedObjectType& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the XOR operation ( ^ ) on the data inside this object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        A reference to this object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator^=( Boolean rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the XOR operation ( ^ ) on the data inside this object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        A reference to this object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator^=( const DataTypes::Bit& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the XOR operation ( ^ ) on the data inside this object and the right side operand
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        A reference to this object
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator^=( const DerivedObjectType& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object matches the right side operand  
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The result of the comparison :
            //      1. true - if the data insie this object matches the right side operand
            //      2. false - otherwise
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline Boolean operator==( Boolean rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object matches the right side operand  
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The result of the comparison :
            //      1. true - if the data insie this object matches the right side operand
            //      2. false - otherwise
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline Boolean operator==( const DataTypes::Bit& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object matches the right side operand  
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The result of the comparison :
            //      1. true - if the data insie this object matches the right side operand
            //      2. false - otherwise
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline Boolean operator==( const DerivedObjectType& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object does not match the right side operand  
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The result of the comparison :
            //      1. true - if the data insie this object does not match the right side operand
            //      2. false - otherwise
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline Boolean operator!=( Boolean rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object does not match the right side operand  
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The result of the comparison :
            //      1. true - if the data insie this object does not match the right side operand
            //      2. false - otherwise
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline Boolean operator!=( const DataTypes::Bit& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object does not match the right side operand  
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand - the right side operand of the operation
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The result of the comparison :
            //      1. true - if the data insie this object does not match the right side operand
            //      2. false - otherwise
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline Boolean operator!=( const DerivedObjectType& rightSideOperand ) const;


    		DEBUG_TOOL(

    			// This part of the class is dedicated for testing :


    			// Method Information :
    			//
    			//  Description :
    			//
    			//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
    			//		the functionality
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
    			static void Test();

    		)  //  End of debug tool


        private:


            // Friend class or friend function can access private and protected members of other class in which it is declared as friend. It is sometimes useful
            // to allow a particular class to access private members of other class. The declration of such function is private, because these functions are part
            // of the implemntation, which the user should not be aware of. The use of this functions is not limited to the class's scope. One of the problems that
            // friend addition to the object solves is when the object needs to be as a left side operand in expressions. Every method in the object is implicitly
            // added a pointer to the location of the object data with name the "this", and to enable this the method must be called from an existing instance.
            // This means that the object can only be implemented as the right side operand of an expression with methods, and friend functions and objects does
            // not have this limitation


            // Function Information :
            //
            //  Description :
            //
            //      Create the operator "~" so the use would be the same as with regular bits. This method is declared and defined outside of the bitwise object scope becuase this 
            //      operator comes before the object, which means it must receive the object
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          instance - a reference to the base pointer object
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A boolean containing the negotiated state of the bit
            //
            //  Possible errors :
            //
            //      1. The instance is in default state
            //      2. 
            //
            template< typename TYPE >
            friend inline Boolean operator~( const TYPE& instance );


            // The following methods decalre the pure virtual methods derived from arithmetics object, to ensure that every inherting object will need to implement 2 methods 
            // that returns the data to manipulate for constant and non constant instances, and antoher one if a task needs to be performed before changes takes place :


            // Method Information :
            //
            //  Description :
            //
            //      This method will be used for non constant objects
            //      
            //  Required arguments :
            //
            //      User information needed :
            //
            //          key - this will be used to identify the required data
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to the data
            //
            //  Possible errors :
            //
            //      They will come
            //
            virtual DataTypes::Bit GetData_IMP() = 0;


            // Method Information :
            //
            //  Description :
            //
            //      This method will be used for constant objects
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          key - this will be used to identify the required data
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
            virtual Boolean GetData_IMP() const = 0;


            // Method Information :
            //
            //  Description :
            //
            //      This method can be used when the default behavior for operators that change the state of the object is not good enough. It is very important for object 
            //      with shared main resource inside. When a write operation needs to take place, the number of instances using the resource must be checked. If only one
            //      instance uses the resource then there are no problems and the write operation can take place. If there is more then one instance using the resource then, 
            //      the resource must be copied first, to prevent changing it also for other instances. Only then the write operation can take place. This method then should 
            //      be used everytime before changes are made to the inherting object
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
            virtual void ExecuteTaskBeforeObjectChanges_IMP() = 0;


    	};  //  Class Bitwise









































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************










































        // Method Information :
        //
        //  Description :
        //
        //      This method will be used to allow explicit ( through static cast ) or implicit conversion of the derived object to the bit inside.
        //      It will allow a things :
        //
        //          1. expressions of the type ->  bit & derivedObjectType< bit >
        //          2. it will be easier to get to the data
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
        //      There is no written return type, but it will return the derived object converted to it's template type
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename DerivedObjectType >
        inline Bitwise< DerivedObjectType >::operator Boolean() const
        {
            // Return the data
            return ( GetData_IMP() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the AND operation ( & ) of the data inside the object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        Result of the AND operation ( & ) of the data inside the object and the right side operand
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator&( Boolean rightSideOperand ) const
        {            
            // Perform the bitwise AND operation ( & ) on the operands, and return the result
            return ( GetData_IMP() & rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the AND operation ( & ) of the data inside the object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        Result of the AND operation ( & ) of the data inside the object and the right side operand
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator&( const DataTypes::Bit& rightSideOperand ) const
        {            
            // Perform the bitwise AND operation ( & ) on the operands, and return the result
            return ( GetData_IMP() & rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the AND operation ( & ) of the data inside the object and the right side operand object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another template type object
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        Result of the AND operation ( & ) of the data inside the object and the right side operand object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator&( const DerivedObjectType& rightSideOperand ) const
        {            
            // Perform the bitwise AND operation ( & ) on the operands, and return the result
            return ( GetData_IMP() & rightSideOperand.GetData_IMP() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the OR operation ( | ) of the data inside the object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        Result of the OR operation ( | ) of the data inside the object and the right side operand
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator|( Boolean rightSideOperand ) const
        {            
            // Perform the bitwise OR operation ( | ) on the operands, and return the result
            return ( GetData_IMP() | rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the OR operation ( | ) of the data inside the object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        Result of the OR operation ( | ) of the data inside the object and the right side operand
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator|( const DataTypes::Bit& rightSideOperand ) const
        {            
            // Perform the bitwise OR operation ( | ) on the operands, and return the result
            return ( GetData_IMP() | rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the OR operation ( | ) of the data inside the object and the right side operand object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another template type object
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        Result of the OR operation ( | ) of the data inside the object and the right side operand object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator|( const DerivedObjectType& rightSideOperand ) const
        {            
            // Perform the bitwise OR operation ( | ) on the operands, and return the result
            return ( GetData_IMP() | rightSideOperand.GetData_IMP() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the XOR operation ( ^ ) of the data inside the object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        Result of the XOR operation ( ^ ) of the data inside the object and the right side operand
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator^( Boolean rightSideOperand ) const
        {            
            // Perform the bitwise XOR operation ( ^ ) on the operands, and return the result
            return ( GetData_IMP() ^ rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the XOR operation ( ^ ) of the data inside the object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        Result of the XOR operation ( ^ ) of the data inside the object and the right side operand
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator^( const DataTypes::Bit& rightSideOperand ) const
        {            
            // Perform the bitwise XOR operation ( ^ ) on the operands, and return the result
            return ( GetData_IMP() ^ rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the XOR operation ( ^ ) of the data inside the object and the right side operand object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another template type object
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        Result of the XOR operation ( ^ ) of the data inside the object and the right side operand object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator^( const DerivedObjectType& rightSideOperand ) const
        {            
            // Perform the bitwise XOR operation ( ^ ) on the operands, and return the result
            return ( GetData_IMP() ^ rightSideOperand.GetData_IMP() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the AND operation ( & ) on the data inside this object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline DerivedObjectType& Bitwise< DerivedObjectType >::operator&=( Boolean rightSideOperand )
        {            
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeObjectChanges_IMP();
            
            // Set the result of the AND operation ( & ) on the data inside this object and the right side operand
            GetData_IMP() &= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type because otherwise the this pointer has a static type 
            // of the bitwise object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the AND operation ( & ) on the data inside this object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline DerivedObjectType& Bitwise< DerivedObjectType >::operator&=( const DataTypes::Bit& rightSideOperand )
        {            
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeObjectChanges_IMP();
            
            // Set the result of the AND operation ( & ) on the data inside this object and the right side operand
            GetData_IMP() &= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type because otherwise the this pointer has a static type 
            // of the bitwise object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the AND operation ( & ) on the data inside this object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline DerivedObjectType& Bitwise< DerivedObjectType >::operator&=( const DerivedObjectType& rightSideOperand )
        {            
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeObjectChanges_IMP();
            
            // Set the result of the AND operation ( & ) on the data inside this object and the right side operand
            GetData_IMP() &= rightSideOperand.GetData_IMP();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type because otherwise the this pointer has a static type 
            // of the bitwise object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the OR operation ( | ) on the data inside this object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline DerivedObjectType& Bitwise< DerivedObjectType >::operator|=( Boolean rightSideOperand )
        {            
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeObjectChanges_IMP();
            
            // Set the result of the OR operation ( | ) on the data inside this object and the right side operand
            GetData_IMP() |= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type because otherwise the this pointer has a static type 
            // of the bitwise object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the OR operation ( | ) on the data inside this object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline DerivedObjectType& Bitwise< DerivedObjectType >::operator|=( const DataTypes::Bit& rightSideOperand )
        {            
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeObjectChanges_IMP();
            
            // Set the result of the OR operation ( | ) on the data inside this object and the right side operand
            GetData_IMP() |= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type because otherwise the this pointer has a static type 
            // of the bitwise object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the OR operation ( | ) on the data inside this object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline DerivedObjectType& Bitwise< DerivedObjectType >::operator|=( const DerivedObjectType& rightSideOperand )
        {            
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeObjectChanges_IMP();
            
            // Set the result of the OR operation ( | ) on the data inside this object and the right side operand
            GetData_IMP() |= rightSideOperand.GetData_IMP();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type because otherwise the this pointer has a static type 
            // of the bitwise object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the XOR operation ( ^ ) on the data inside this object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline DerivedObjectType& Bitwise< DerivedObjectType >::operator^=( Boolean rightSideOperand )
        {            
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeObjectChanges_IMP();
            
            // Set the result of the XOR operation ( ^ ) on the data inside this object and the right side operand
            GetData_IMP() ^= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type because otherwise the this pointer has a static type 
            // of the bitwise object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the XOR operation ( ^ ) on the data inside this object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline DerivedObjectType& Bitwise< DerivedObjectType >::operator^=( const DataTypes::Bit& rightSideOperand )
        {            
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeObjectChanges_IMP();
            
            // Set the result of the XOR operation ( ^ ) on the data inside this object and the right side operand
            GetData_IMP() ^= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type because otherwise the this pointer has a static type 
            // of the bitwise object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the XOR operation ( ^ ) on the data inside this object and the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType >
        inline DerivedObjectType& Bitwise< DerivedObjectType >::operator^=( const DerivedObjectType& rightSideOperand )
        {            
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeObjectChanges_IMP();
            
            // Set the result of the XOR operation ( ^ ) on the data inside this object and the right side operand
            GetData_IMP() ^= rightSideOperand.GetData_IMP();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type because otherwise the this pointer has a static type 
            // of the bitwise object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object matches the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The result of the comparison :
        //      1. true - if the data insie this object matches the right side operand
        //      2. false - otherwise
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator==( Boolean rightSideOperand )
        {            
            // Check if the data inside this object matches the right side operand, and return the result
            return ( GetData_IMP() == rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object matches the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The result of the comparison :
        //      1. true - if the data insie this object matches the right side operand
        //      2. false - otherwise
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator==( const DataTypes::Bit& rightSideOperand )
        {            
            // Check if the data inside this object matches the right side operand, and return the result
            return ( GetData_IMP() == rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object matches the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The result of the comparison :
        //      1. true - if the data insie this object matches the right side operand
        //      2. false - otherwise
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator==( const DerivedObjectType& rightSideOperand )
        {            
            // Check if the data inside this object matches the right side operand, and return the result
            return ( GetData_IMP() == rightSideOperand.GetData_IMP() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object does not match the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The result of the comparison :
        //      1. true - if the data insie this object does not match the right side operand
        //      2. false - otherwise
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator!=( Boolean rightSideOperand ) const
        {            
            // Check if the data inside this object does not match the right side operand, and return the result
            return ( !( *this == rightSideOperand ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object does not match the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The result of the comparison :
        //      1. true - if the data insie this object does not match the right side operand
        //      2. false - otherwise
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator!=( const DataTypes::Bit& rightSideOperand ) const
        {            
            // Check if the data inside this object does not match the right side operand, and return the result
            return ( !( *this == rightSideOperand ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object does not match the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - the right side operand of the operation
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The result of the comparison :
        //      1. true - if the data insie this object does not match the right side operand
        //      2. false - otherwise
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType >
        inline Boolean Bitwise< DerivedObjectType >::operator!=( const DerivedObjectType& rightSideOperand ) const
        {            
            // Check if the data inside this object does not match the right side operand, and return the result
            return ( !( *this == rightSideOperand ) );
        }














































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************











































        // Function Information :
        //
        //  Description :
        //
        //      Create the operator "~" so the use would be the same as with regular bits. This method is declared and defined outside of the bitwise object scope becuase this 
        //      operator comes before the object, which means it must receive the object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          instance - a reference to the base pointer object
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A boolean containing the negotiated state of the bit
        //
        //  Possible errors :
        //
        //      1. The instance is in default state
        //      2. 
        //
        template< typename TYPE >
        inline Boolean operator~( const TYPE& instance )
        {
            // Return the negotiated state of the bit
            return ( ~instance.GetData_IMP() );
        }














































// ********************************************************************************   TESTING   *********************************************************************************
















































    	DEBUG_TOOL(

    		// Method Information :
    		//
    		//  Description :
    		//
    		//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
    		//		the functionality
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
    		template< typename DerivedObjectType >
    		void Bitwise< DerivedObjectType >::Test()
    		{}

    	)  //  End of debug tool











    }  //  Namespace Abilities

}  //  Namespace Universe


#endif  // BITWISE_HPP