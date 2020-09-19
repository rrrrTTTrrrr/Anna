#ifndef  ARITHMETICS_HPP
#define  ARITHMETICS_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../../../../Content/Metaprogramming/Types/TypeCheck/Numeric/TypeCheck_Numeric/TypeCheck_Numeric.hpp"  //  Macro TypeCheck_Numeric


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


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
    	template< typename DerivedObjectType, typename NumericType >
        class Arithmetics
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Arithmetics() = default;


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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Arithmetics( const Arithmetics< DerivedObjectType, NumericType >& other ) = default;


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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Arithmetics< DerivedObjectType, NumericType >& operator=( const Arithmetics< DerivedObjectType, NumericType >& other ) = default;


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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Arithmetics( Arithmetics< DerivedObjectType, NumericType >&& other ) = default;


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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline Arithmetics< DerivedObjectType, NumericType >& operator=( Arithmetics< DerivedObjectType, NumericType >&& other ) = default;


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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            virtual ~Arithmetics() = default;


    		// The following methods declare the overloaded operators for the object :


            // Method Information :
            //
            //  Description :
            //
            //      This method will be used to allow explicit ( through static cast ) or implicit conversion of the derived object to it's template type.
            //      It will allow a things :
            //
            //          1. expressions of the type ->  int + derivedObjectType< int >
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
            //      There is no written return type, but it will return an instance the derived object converted to it's template type
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline operator NumericType() const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the sum of the data inside the instance with the given right side operand
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
            //        The sum of the data inside the instance with the given right side operand
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator+( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the sum of the data inside the instance with the data inside right side operand object
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
            //      Sum of the data inside the instance with the data inside right side operand object 
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline NumericType operator+( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the difference between the data inside the instance and the data inside right side operand
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
            //      Difference between the data inside the instance and the data inside right side operand object
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator-( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the difference between the data inside the instance and the data inside right side operand object
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
            //      Difference between the data inside the instance and the data inside right side operand object 
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline NumericType operator-( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the sum of multiplying the data inside the instance by the data inside right side operand
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
            //      Sum of multiplying the data inside the instance by the data inside right side operand        
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator*( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the sum of multiplying the data inside the instance by the data inside right side operand object
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
            //      Sum of multiplying the data inside the instance by the data inside right side operand object
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline NumericType operator*( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the quotient of the data inside the instance by the data inside right side operand
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
            //        Quotient of the data inside the instance by the data inside right side operand
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator/( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the quotient of the data inside the instance by the data inside right side operand object
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
            //      Quotient of the data inside the instance by the data inside right side operand object 
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline NumericType operator/( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the data inside the instance modulo the data inside right side operand
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
            //        Result of the data inside the instance modulo the data inside right side operand
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator%( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the data inside the instance modulo the data inside right side operand object
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
            //        Result of the data inside the instance modulo the data inside right side operand object
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline NumericType operator%( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to left shift the data inside the instance the amount in the right side operand
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
            //        Result of left shifting the data inside the instance the required amount in the right side operand
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator<<( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to left shift the data inside the instance the amount in the right side operand object
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
            //        Result of left shifting the data inside the instance the required amount in the right side operand object
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator<<( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to right shift the data inside the instance the amount in the right side operand
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
            //        Result of right shifting the data inside the instance the required amount in the right side operand
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator>>( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to right shift the data inside the instance the amount in the right side operand object
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
            //        Result of right shifting the data inside the instance the required amount in the right side operand object
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator>>( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the AND operation ( & ) of the data inside the instance and the right side operand
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
            //        Result of the AND operation ( & ) of the data inside the instance and the right side operand
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator&( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the AND operation ( & ) of the data inside the instance and the right side operand object
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
            //        Result of the AND operation ( & ) of the data inside the instance and the right side operand object
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator&( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the OR operation ( | ) of the data inside the instance and the right side operand
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
            //        Result of the OR operation ( | ) of the data inside the instance and the right side operand
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator|( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the OR operation ( | ) of the data inside the instance and the right side operand object
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          rightSideOperand -a reference to another template type object
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        Result of the OR operation ( | ) of the data inside the instance and the right side operand object
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator|( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the XOR operation ( ^ ) of the data inside the instance and the right side operand
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
            //        Result of the XOR operation ( ^ ) of the data inside the instance and the right side operand
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator^( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to get the result of the XOR operation ( ^ ) of the data inside the instance and the right side operand object
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
            //        Result of the XOR operation ( ^ ) of the data inside the instance and the right side operand object
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline NumericType operator^( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to add the data inside this object the right side operand
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator+=( NumericType rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to add the data inside this object the data inside the right side operand object
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
            //        A reference to this object
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            // 
            inline DerivedObjectType& operator+=( const DerivedObjectType& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to subtract from the data inside this object the right side operand
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator-=( NumericType rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to subtract from the data inside this object the data inside the right side operand object
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator-=( const DerivedObjectType& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to multiply the data inside this object by the right side operand
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator*=( NumericType rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to multiply the data inside this object by the data inside the right side operand object
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator*=( const DerivedObjectType& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to divide the data inside this object by the right side operand
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator/=( NumericType rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to divide the data inside this object by the data inside the right side operand object
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator/=( const DerivedObjectType& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to modulo the data inside this object by the right side operand
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator%=( NumericType rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to modulo the data inside this object by the data inside the right side operand object
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator%=( const DerivedObjectType& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to left shift the required amount of times the data inside this object
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator<<=( NumericType rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to left shift the required amount of times the data inside this object
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
            //        A reference to this object
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator<<=( const DerivedObjectType& rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to right shift the required amount of times the data inside this object
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator>>=( NumericType rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to right shift the required amount of times the data inside this object
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
            //        A reference to this object
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator>>=( const DerivedObjectType& rightSideOperand );


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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator&=( NumericType rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the AND operation ( & ) on the data inside this object and the data inside the right side operand object
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
            //        A reference to this object
            //
            //  Expectations :
            //
            //      NONE
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator|=( NumericType rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the OR operation ( | ) on the data inside this object and the data inside the right side operand object
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
            //        A reference to this object
            //
            //  Expectations :
            //
            //      NONE
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //  
            inline DerivedObjectType& operator^=( NumericType rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to perform the XOR operation ( ^ ) on the data inside this object and the data inside the right side operand object
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
            //        A reference to this object
            //
            //  Expectations :
            //
            //      NONE
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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator==( NumericType rightSideOperand );


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object matches the data inside the right side operand object
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
            //      The result of the comparison :
            //      1. true - if the data insie this object matches the data inside the right side operand object
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator==( const DerivedObjectType& rightSideOperand ) const;


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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator!=( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object does not match the data inside the right side operand object
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
            //      The result of the comparison :
            //      1. true - if the data insie this object does not match the data inside the right side operand object
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator!=( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object is larger then the right side operand  
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
            //      1. true - if the data insie this object is larger then the right side operand
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator>( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object is larger then the data inside the right side operand object
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
            //      The result of the comparison :
            //      1. true - if the data insie this object is larger then the data inside the right side operand object
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator>( const DerivedObjectType& rightSideOperand ) const;

            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object is smaller then the right side operand  
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
            //      1. true - if the data insie this object is smaller then the right side operand
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator<( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object is smaller then the data inside the right side operand object
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
            //      The result of the comparison :
            //      1. true - if the data insie this object is smaller then the data inside the right side operand object
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator<( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object is equal or larger then the right side operand  
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
            //      1. true - if the data insie this object is equal or larger then the right side operand
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator>=( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object is equal or larger then the data inside the right side operand object
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
            //      The result of the comparison :
            //      1. true - if the data insie this object is equal or larger then the data inside the right side operand object
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator>=( const DerivedObjectType& rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object is equal or smaller then the right side operand  
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
            //      1. true - if the data insie this object is equal or smaller then the right side operand
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator<=( NumericType rightSideOperand ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use this operator to check if the data inside this object is equal or smaller then the data inside the right side operand object
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
            //      The result of the comparison :
            //      1. true - if the data insie this object is equal or smaller then the data inside the right side operand object
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come 
            //  
            inline bool operator<=( const DerivedObjectType& rightSideOperand ) const;


        protected:


            // The protected part is used for inheritance. This means that only this object and the objects that will inherit from it can use the protected data
            // members or methods


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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            virtual NumericType& GetData__Private() = 0;


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
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            virtual NumericType GetData__Private() const = 0;


    	private:


            // Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides 
            // the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
            // thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
            // and the error message will be displayed. This method should not be used, because it does nothing during run time
            CompileTimeAssert( ( TypeCheck_Numeric< NumericType >::Result() == true ), "Arithmetics::CompileTimeAssert - The given type should be numeric" );


    	};  //  Class Arithmetics






























//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************

































        // Method Information :
        //
        //  Description :
        //
        //      This method will be used to allow explicit ( through static cast ) or implicit conversion of the derived object to it's template type.
        //      It will allow a things :
        //
        //          1. expressions of the type ->  int + derivedObjectType< int >
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
        //      There is no written return type, but it will return an instance the derived object converted to it's template type
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename DerivedObjectType, typename NumericType >
        inline Arithmetics< DerivedObjectType, NumericType >::operator NumericType() const
        {
            // Return the data
            return ( GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to add the the given value from the value inside this instance, and return the result
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to a raw primitive type value
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A copy of the result of adding the 2 operands
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator+( NumericType rightSideOperand ) const
        {
            // Add the data inside the instance with the given right side operand, and return the result
            return ( GetData__Private() + rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to add the two operands and return a copy of the result
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to other instance of this object
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A copy of the result of adding the 2 operands
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator+( const DerivedObjectType& rightSideOperand ) const
        {
            // Add the data inside the instance with the data inside right side operand object, and return the result
            return ( GetData__Private() + rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to subtract the the given value from the value inside this instance, and return the result
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to a raw primitive type value
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A copy of the result of adding the 2 operands
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator-( NumericType rightSideOperand ) const
        {            
            // Subtract from the data inside the instance with the data inside right side operand object, and return the result 
            return ( GetData__Private() - rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the difference between the data inside the instance and the data inside right side operand object
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
        //      Difference between the data inside the instance and the data inside right side operand object 
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator-( const DerivedObjectType& rightSideOperand ) const
        {            
            // Subtract from the data inside the instance the data inside right side operand object, and return the result 
            return ( GetData__Private() - rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the sum of multiplying the data inside the instance by the data inside right side operand
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
        //      Sum of multiplying the data inside the instance by the data inside right side operand        
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator*( NumericType rightSideOperand ) const
        {            
            // Multiply the data inside the instance by the data inside right side operand, and return the result
            return ( GetData__Private() * rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the sum of multiplying the data inside the instance by the data inside right side operand object
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
        //      Sum of multiplying the data inside the instance by the data inside right side operand object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator*( const DerivedObjectType& rightSideOperand ) const
        {
            // Multiply the data inside the instance by the data inside right side operand object, and return the result
            return ( GetData__Private() * rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the quotient of the data inside the instance by the data inside right side operand
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
        //        Quotient of the data inside the instance by the data inside right side operand
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator/( NumericType rightSideOperand ) const
        {            
            // Divide the data inside the instance by the data inside right side operand, and return the result
            return ( GetData__Private() / rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the quotient of the data inside the instance by the data inside right side operand object
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
        //      Quotient of the data inside the instance by the data inside right side operand object 
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator/( const DerivedObjectType& rightSideOperand ) const
        {
            // Divide the data inside the instance by the data inside right side operand object, and return the result
            return ( GetData__Private() / rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the data inside the instance modulo the data inside right side operand
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
        //        Result of the data inside the instance modulo the data inside right side operand
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator%( NumericType rightSideOperand ) const
        {            
            // Modulo the data inside the instance by the data inside right side operand, and return the result
            return ( GetData__Private() % rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the data inside the instance modulo the data inside right side operand object
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
        //        Result of the data inside the instance modulo the data inside right side operand object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator%( const DerivedObjectType& rightSideOperand ) const
        {
            // Modulo the data inside the instance by the data inside right side operand object, and return the result
            return ( GetData__Private() % rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to left shift the data inside the instance the amount in the right side operand
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
        //        Result of left shifting the data inside the instance the required amount in the right side operand
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator<<( NumericType rightSideOperand ) const
        {            
            // Left shifting the data inside the instance the required amount in the right side operand, and return the result
            return ( GetData__Private() << rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to left shift the data inside the instance the amount in the right side operand object
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
        //        Result of left shifting the data inside the instance the required amount in the right side operand object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator<<( const DerivedObjectType& rightSideOperand ) const
        {
            // Left shifting the data inside the instance the required amount in the right side operand object, and return the result
            return ( GetData__Private() << rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to right shift the data inside the instance the amount in the right side operand
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
        //        Result of right shifting the data inside the instance the required amount in the right side operand
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator>>( NumericType rightSideOperand ) const
        {            
            // Right shifting the data inside the instance the required amount in the right side operand, and return the result
            return ( GetData__Private() >> rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to right shift the data inside the instance the amount in the right side operand object
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
        //        Result of right shifting the data inside the instance the required amount in the right side operand object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator>>( const DerivedObjectType& rightSideOperand ) const
        {
            // Right shifting the data inside the instance the required amount in the right side operand object, and return the result
            return ( GetData__Private() >> rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the AND operation ( & ) of the data inside the instance and the right side operand
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
        //        Result of the AND operation ( & ) of the data inside the instance and the right side operand
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator&( NumericType rightSideOperand ) const
        {            
            // Perform the bitwise AND operation ( & ) on the operands, and return the result
            return ( GetData__Private() & rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the AND operation ( & ) of the data inside the instance and the right side operand object
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
        //        Result of the AND operation ( & ) of the data inside the instance and the right side operand object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator&( const DerivedObjectType& rightSideOperand ) const
        {            
            // Perform the bitwise AND operation ( & ) on the operands, and return the result
            return ( GetData__Private() & rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the OR operation ( | ) of the data inside the instance and the right side operand
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
        //        Result of the OR operation ( | ) of the data inside the instance and the right side operand
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator|( NumericType rightSideOperand ) const
        {            
            // Perform the bitwise OR operation ( | ) on the operands, and return the result
            return ( GetData__Private() | rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the OR operation ( | ) of the data inside the instance and the right side operand object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand -a reference to another template type object
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        Result of the OR operation ( | ) of the data inside the instance and the right side operand object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator|( const DerivedObjectType& rightSideOperand ) const
        {            
            // Perform the bitwise OR operation ( | ) on the operands, and return the result
            return ( GetData__Private() | rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the XOR operation ( ^ ) of the data inside the instance and the right side operand
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
        //        Result of the XOR operation ( ^ ) of the data inside the instance and the right side operand
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator^( NumericType rightSideOperand ) const
        {            
            // Perform the bitwise XOR operation ( ^ ) on the operands, and return the result
            return ( GetData__Private() ^ rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get the result of the XOR operation ( ^ ) of the data inside the instance and the right side operand object
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
        //        Result of the XOR operation ( ^ ) of the data inside the instance and the right side operand object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline NumericType Arithmetics< DerivedObjectType, NumericType >::operator^( const DerivedObjectType& rightSideOperand ) const
        {            
            // Perform the bitwise XOR operation ( ^ ) on the operands, and return the result
            return ( GetData__Private() ^ rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to add the data inside this object the right side operand
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator+=( NumericType rightSideOperand )
        {
            // Set the sum of the data inside this object with the right side operand
            GetData__Private() += rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to add the data inside this object the data inside the right side operand object
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
        //        A reference to this object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        // 
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator+=( const DerivedObjectType& rightSideOperand )
        {
            // Set the sum of the data inside this object with the data inside right side operand object
            GetData__Private() += rightSideOperand.GetData__Private();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to subtract from the data inside this object the right side operand
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator-=( NumericType rightSideOperand )
        {
            // Set the difference between the data inside this object and the right side operand
            GetData__Private() -= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to subtract from the data inside this object the data inside the right side operand object
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator-=( const DerivedObjectType& rightSideOperand )
        {
            // Set the difference between the data inside this object and the data inside the right side operand object
            GetData__Private() -= rightSideOperand.GetData__Private();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to multiply the data inside this object by the right side operand
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator*=( NumericType rightSideOperand )
        {                        
            // Set the sum of multiplying the data inside this object and the right side operand
            GetData__Private() *= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to multiply the data inside this object by the data inside the right side operand object
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator*=( const DerivedObjectType& rightSideOperand )
        {            
            // Set the sum of multiplying the data inside this object and the data inside the right side operand object
            GetData__Private() *= rightSideOperand.GetData__Private();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to divide the data inside this object by the right side operand
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator/=( NumericType rightSideOperand )
        {            
            // Set the quotient of the data inside this object and the right side operand
            GetData__Private() /= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to divide the data inside this object by the data inside the right side operand object
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator/=( const DerivedObjectType& rightSideOperand )
        {
            // Set the quotient of the data inside this object by the data inside the right side operand object
            GetData__Private() /= rightSideOperand.GetData__Private();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to modulo the data inside this object by the right side operand
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator%=( NumericType rightSideOperand )
        {           
            // Set the sum of modulo the data inside this object and the right side operand
            GetData__Private() %= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to modulo the data inside this object by the data inside the right side operand object
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator%=( const DerivedObjectType& rightSideOperand )
        {
            // Set the modulo of the data inside this object by the data inside the right side operand object
            GetData__Private() %= rightSideOperand.GetData__Private();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to left shift the required amount of times the data inside this object
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator<<=( NumericType rightSideOperand )
        {           
            // Set the result of left shifting the required amount of times the data inside this object
            GetData__Private() <<= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to left shift the required amount of times the data inside this object
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
        //        A reference to this object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator<<=( const DerivedObjectType& rightSideOperand )
        {                        
            // Set the result of left shifting the required amount of times the data inside this object
            GetData__Private() <<= rightSideOperand.GetData__Private();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to right shift the required amount of times the data inside this object
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator>>=( NumericType rightSideOperand )
        {                        
            // Set the result of right shifting the required amount of times the data inside this object
            GetData__Private() >>= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to right shift the required amount of times the data inside this object
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
        //        A reference to this object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator>>=( const DerivedObjectType& rightSideOperand )
        {                        
            // Set the result of right shifting the required amount of times the data inside this object
            GetData__Private() >>= rightSideOperand.GetData__Private();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator&=( NumericType rightSideOperand )
        {                        
            // Set the result of the AND operation ( & ) on the data inside this object and the right side operand
            GetData__Private() &= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the AND operation ( & ) on the data inside this object and the data inside the right side operand object
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
        //        A reference to this object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator&=( const DerivedObjectType& rightSideOperand )
        {                        
            // Set the result of the AND operation ( & ) on the data inside this object and the data inside the right side operand object
            GetData__Private() &= rightSideOperand.GetData__Private();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator|=( NumericType rightSideOperand )
        {                        
            // Set the result of the OR operation ( | ) on the data inside this object and the right side operand
            GetData__Private() |= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the OR operation ( | ) on the data inside this object and the data inside the right side operand object
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
        //        A reference to this object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator|=( const DerivedObjectType& rightSideOperand )
        {                        
            // Set the result of the OR operation ( | ) on the data inside this object and the data inside the right side operand object
            GetData__Private() |= rightSideOperand.GetData__Private();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator^=( NumericType rightSideOperand )
        {                        
            // Set the result of the XOR operation ( ^ ) on the data inside this object and the right side operand
            GetData__Private() ^= rightSideOperand;

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to perform the XOR operation ( ^ ) on the data inside this object and the data inside the right side operand object
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
        //        A reference to this object
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline DerivedObjectType& Arithmetics< DerivedObjectType, NumericType >::operator^=( const DerivedObjectType& rightSideOperand )
        {            
            // Set the result of the XOR operation ( ^ ) on the data inside this object and the data inside the right side operand object
            GetData__Private() ^= rightSideOperand.GetData__Private();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator==( NumericType rightSideOperand )
        {            
            // Check if the data inside this object matches the right side operand, and return the result
            return ( GetData__Private() == rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object matches the data inside the right side operand object
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
        //      The result of the comparison :
        //      1. true - if the data insie this object matches the data inside the right side operand object
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator==( const DerivedObjectType& rightSideOperand ) const
        {            
            // Check if the data inside this object matches the data inside the right side operand object, and return the result
            return ( GetData__Private() == rightSideOperand.GetData__Private() );
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator!=( NumericType rightSideOperand ) const
        {            
            // Check if the data inside this object does not match the right side operand, and return the result
            return ( GetData__Private() != rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object does not match the data inside the right side operand object
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
        //      The result of the comparison :
        //      1. true - if the data insie this object does not match the data inside the right side operand object
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator!=( const DerivedObjectType& rightSideOperand ) const
        {            
            // Check if the data inside this object does not match the data inside the right side operand object, and return the result
            return ( GetData__Private() != rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object is larger then the right side operand  
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
        //      1. true - if the data insie this object is larger then the right side operand
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator>( NumericType rightSideOperand ) const
        {            
            // Check if the data inside this object is larger then the right side operand, and return the result
            return ( GetData__Private() > rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object is larger then the data inside the right side operand object
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
        //      The result of the comparison :
        //      1. true - if the data insie this object is larger then the data inside the right side operand object
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator>( const DerivedObjectType& rightSideOperand ) const
        {            
            // Check if the data inside this object is larger then the data inside the right side operand object, and return the result
            return ( GetData__Private() > rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object is smaller then the right side operand  
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
        //      1. true - if the data insie this object is smaller then the right side operand
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator <( NumericType rightSideOperand ) const
        {            
            // Check if the data inside this object is smaller then the right side operand, and return the result
            return ( GetData__Private() < rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object is smaller then the data inside the right side operand object
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
        //      The result of the comparison :
        //      1. true - if the data insie this object is smaller then the data inside the right side operand object
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator <( const DerivedObjectType& rightSideOperand ) const
        {            
            // Check if the data inside this object is smaller then the data inside the right side operand object, and return the result
            return ( GetData__Private() < rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object is equal or larger then the right side operand  
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
        //      1. true - if the data insie this object is equal or larger then the right side operand
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator>=( NumericType rightSideOperand ) const
        {            
            // Check if the data inside this object is equal or larger then the right side operand, and return the result
            return ( GetData__Private() >= rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object is equal or larger then the data inside the right side operand object
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
        //      The result of the comparison :
        //      1. true - if the data insie this object is equal or larger then the data inside the right side operand object
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator>=( const DerivedObjectType& rightSideOperand ) const
        {            
            // Check if the data inside this object is equal or larger then the data inside the right side operand object, and return the result
            return ( GetData__Private() >= rightSideOperand.GetData__Private() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object is equal or smaller then the right side operand  
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
        //      1. true - if the data insie this object is equal or smaller then the right side operand
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator<=( NumericType rightSideOperand ) const
        {            
            // Check if the data inside this object is equal or smaller then the right side operand, and return the result
            return ( GetData__Private() <= rightSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the data inside this object is equal or smaller then the data inside the right side operand object
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
        //      The result of the comparison :
        //      1. true - if the data insie this object is equal or smaller then the data inside the right side operand object
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        template< typename DerivedObjectType, typename NumericType >
        inline bool Arithmetics< DerivedObjectType, NumericType >::operator<=( const DerivedObjectType& rightSideOperand ) const
        {            
            // Check if the data inside this object is equal or smaller then the data inside the right side operand object, and return the result
            return ( GetData__Private() <= rightSideOperand.GetData__Private() );
        }








    }  //  Namespace Abilities

}  //  Namespace Universe


#endif  // ARITHMETICS_HPP