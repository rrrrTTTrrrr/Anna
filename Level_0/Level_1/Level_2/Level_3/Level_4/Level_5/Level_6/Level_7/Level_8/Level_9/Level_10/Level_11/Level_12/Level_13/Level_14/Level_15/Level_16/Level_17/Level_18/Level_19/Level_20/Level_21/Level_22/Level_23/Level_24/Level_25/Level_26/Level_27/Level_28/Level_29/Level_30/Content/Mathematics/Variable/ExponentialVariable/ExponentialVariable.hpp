#ifndef EXPONENTIALVARIABLE_HPP
#define EXPONENTIALVARIABLE_HPP


#include "../../../../../../../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../../../../../../../../Content/Object/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure
#include "../../../../../../../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../../../../../../Content/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../Variable_Interface/Variable_Interface.hpp"  //  Class Variable_Interface
#include "../../../../../../../../../../../../../../../Content/Arithmetic/Arithmetic.hpp"  // Class Arithmetic


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{


	namespace Mathematics
    {


		// Class Information :
		//
		//  Purpose :
		//
		//		Use this object to store an operation that will be performed on a given value, to output the result. This object will be used to take
		//		a base value, raise it by the power and finaly multiply it by a coefficient.
		//
		//			Value of variable = coefficient * ( base ^ power )
		//
		//		When the base is the value that needs to be supplied to the instance to perform the calculation
		//
		//  Description :
		//
		//		1. This object is used as a base object in inheritance. Therefore it must have a few methods virtual. When an object has a virtual method, the
		//		   C++ automatically creates a table with all the pointers to the virtual methods, where the pointer to the table is stored in the beginning of
		//		   the object. The problem arises when a new method needs to be created with the same signature as one in the base object, and the use of pointers.
		//		   Take a look at next example :
		//
		//				class Base
		//				{
		//				    void Display() { cout << "Lord" << endl; }
		//				};
		//
		//				class Derived : public Base
		//				{
		//				    void Display(); { cout << "Help Me" << endl; }    -> Derived inherits Display from Base but needs another behavior
		//				};
		//
		//         Now if a call is made :
		//
		//				Base* base = new Base;
		//				Derived* derived = new Derived;
		//
		//				base->Display( 5 );   -> Outputs "Lord"
		//				derived->Display();   -> Outputs "Help Me"
		//
		//         So far so good, a normal method is called by the static type of the pointer. This means no matter what the object the pointer is
		//		   pointing to it will call the method of the type he was declared as. This is a problematic behavior in inheritance, we need to point
		//		   to derived objects with base pointers and that the correct method will be called. But now :
		//
		//				void Do( Base* base ) { base->Display(); }
		//
		//				Base* base = new Base;
		//				Derived* derived = new Derived;
		//
		//				Do( base );        -> Outputs "Lord"
		//				Do( derived );     -> Outputs "Lord"
		//
		//         This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is picked
		//		   dynamically by the actual type of the object. This is done by the pointer in the beginning of the object that points to the virtual
		//		   table of the type. Of course it can be overloaded to the derived, but then if there is a deep inheritance a method will be needed to
		//		   be overloaded for each one
		//
		// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
		//		   providing 3 keywords :
		//
		//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
		//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
		//						member is public all the encapsulation is lost, so it should be avoided in most cases
		//
		//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
		//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
		//						   data members
		//
		//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
		//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
		//						 part will end with the suffix __Private
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class ExponentialVariable : public Variable_Interface
		{
		public:


			// Create a type definition for this object
			using SelfType = ExponentialVariable;


			// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
			// the compiler generates a basic behavior for them if possible :


			// Method Information :
			//
			//  Description :
			//
			//		Default Constructor,
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
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline ExponentialVariable();


			// Method Information :
			//
			//  Description :
			//
			//		Constructor,
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//          1. coefficient - the value for the variable coefficient
			//			2. power - the value that the base, which is the variable, should be raised by
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
			//		They will come
			//
			explicit inline ExponentialVariable( FloatingPoint64bits coefficient, FloatingPoint64bits power );


			// Method Information :
			//
			//  Description :
			//
			//		Constructor, to allow creating a random generated instance 
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
			//			2. rangeFor - this will be used to limit the possible values of the {} in the random instance
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
			//		They will come
			//
			explicit inline ExponentialVariable( RandomInstance, const Range< FloatingPoint64bits >& rangeForCoefficient = Range< FloatingPoint64bits >( 1, 100000 ), const Range< FloatingPoint64bits >& rangeForPower = Range< FloatingPoint64bits >( 1, 20 ) );


			// Method Information :
			//
			//  Description :
			//
			//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be copied
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
			//		They will come
			//
			inline ExponentialVariable( const SelfType& other );


			// Add the following infrastructure to the object :
			//
			//		1. Assigenment operator
			//		2. Move constructor
			//		3. Move assigenment operator
			//		4. Swap
			//		5. Reset
			//
			ObjectInfrastructure_ForInheritance( ExponentialVariable )


			// Method Information :
			//
			//  Description :
			//
			//		Destructor, does not throw
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
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual ~ExponentialVariable() = default;


			// This part will contain all the get and set methods for the members of the object :


			GetByValue_Creator( /* GetMethodName */ GetCoefficient, /* MemberName */ member_coefficient, /* MemberType */ FloatingPoint64bits )
			GetByValue_Creator( /* GetMethodName */ GetPower, /* MemberName */ member_power, /* MemberType */ FloatingPoint64bits )

			SetByValue_Creator( /* SetMethodName */ SetCoefficient, /* MemberName */ member_coefficient, /* MemberType */ FloatingPoint64bits )
			SetByValue_Creator( /* SetMethodName */ SetPower, /* MemberName */ member_power, /* MemberType */ FloatingPoint64bits )


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the "result" of the variable, when acted on the given value. In mathematics syntax :
			//
			//			result = coefficient * ( value ^ power )
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			value - this will be used as the value of the variable to perform the calculation
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The "result" of the variable, when acted on the given value		
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual FloatingPoint64bits Value( FloatingPoint64bits value ) const override;


			// The following methods declare the overloaded operators for the object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to check if the this instance match the other
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be compared with this object
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the 2 instances are the same
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			Boolean operator==( const SelfType& other ) const;


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to check if the this instance does not match the other
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be compared with this object
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		1. true - if the 2 instances are not the same
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean operator!=( const SelfType& other ) const;


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


			// This object will store the coefficient of the variable
			FloatingPoint64bits member_coefficient;

			// This object will store the power that the base, which is the provided value for the variable, needs to be raised by
			FloatingPoint64bits member_power;


		};  //  Class ExponentialVariable



#include "ExponentialVariable.inl"



    }  //  Namespace Mathematics

}  //  Namespace Universe



#endif  // EXPONENTIALVARIABLE_HPP