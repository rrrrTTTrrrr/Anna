#ifndef EXPONENTIALVARIABLE_HPP
#define EXPONENTIALVARIABLE_HPP


#include "../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../../../../../Content/Metaprogramming/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../Variable_Interface/Variable_Interface.hpp"  //  Class Variable_Interface
#include "../../../../../../../../Content/BaseRaisedByThePower/BaseRaisedByThePower.hpp"  //  Class BaseRaisedByThePower


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../../TestBranch/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
#endif


namespace Universe
{

    namespace Mathematics
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
		//		2. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
		//
		//		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
		//		   providing 3 keywords :
		//
		//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
		//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
		//						member is public all the encapsulation is lost, so it should be avoided in most cases
		//
		//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
		//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
		//						   data members
		//
		//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
		//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
		//						 part will end with the suffix __Private
		//
		//		4. Template arguments :
		//
		//			1. Type -
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename NumericType >
        class ExponentialVariable : public Variable_Interface< NumericType >
        {
        public:


            // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
			// the compiler generates a basic behavior for them if possible :


			// Method Information :
			//
			//  Description :
			//
			//   	Default Constructor
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
			//   	Constructor,
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//          1. coefficient - the value for the variable coefficient
			//			2. power - the value that the base, which is the variable, shoould be raised by
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			explicit inline ExponentialVariable( NumericType coefficient, NumericType power );


			// Method Information :
			//
			//  Description :
			//
			//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
			//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
			//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
			//
			//				1.
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
			explicit inline ExponentialVariable( const Tuple< NumericType, NumericType >& arguments );


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
			//          other - a reference to the instance that should be copied
			//
			//		Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline ExponentialVariable( const ExponentialVariable< NumericType >& other );


			// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
			//		1. Assigenment operator
			//		2. Move constructor
			//		3. Move assigenment operator
			//		4. Reset
			//		5. State
			//
			ObjectInfrastructure_ForInheritance_WithStateAlwaysReady_MACRO( ExponentialVariable< NumericType > )


			// Method Information :
			//
			//  Description :
			//
			//      This method is used to swap the content between this instance and the other one
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//          other - a reference to the instance that should be swaped
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
			inline void Swap( ExponentialVariable< NumericType >& other );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//          1. coefficient - the value for the variable coefficient
			//			2. power - the value that the base, which is the variable, shoould be raised by
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
			//		They will come
			//
			inline void Initiate( NumericType coefficient, NumericType power );


			// Method Information :
			//
			//  Description :
			//
			//   	Destructor, does not throw. Declared virtual to ensure correct deletion for derived objects
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
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual ~ExponentialVariable() = default;


			// The following methods are the interface of the object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the "result" of the variable, when acted on the given value
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
			virtual NumericType Value( NumericType value ) override;


			// The following methods declare the overloaded operators for the object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to check if the this instance match the other
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//          other - a reference to the instance that should be compared with this object
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//      1. true - if the 2 instances are the same
			//      2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean operator==( const ExponentialVariable< NumericType >& other ) const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to check if the this instance does not match the other
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//          other - a reference to the instance that should be compared with this object
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//      1. true - if the 2 instances are not the same
			//      2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean operator!=( const ExponentialVariable< NumericType >& other ) const;


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
			// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
			// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to generate a random instance of this object
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. rangeForCoefficient - this will be used to limit the possible values of the coefficient in the random instance
			//			2. rangeForPower - this will be used to limit the possible values of the power in the random instance
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A random generated instance
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			static inline ExponentialVariable< NumericType > GenerateRandomInstance( NumericRange< NumericType > rangeForCoefficient =NumericRange< NumericType >(), NumericRange< NumericType > rangeForPower = NumericRange< NumericType >() );


			DEBUG_TOOL(

				// This part of the object is dedicated for testing :


				// Method Information :
				//
				//  Description :
				//
				//      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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
			NumericType member_coefficient;

			// This object will store the power that the base, which is the provided value for the variable, needs to be raised by
			NumericType member_power;


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Method Information :
			//
			//  Description :
			//
			//      This method will be used to assert all the requirements on the template arguments provided to the object. To perform a compile time assert
			//		the C++ language provides the keyword 'static_assert', which receives an expression and an error message to display if the expression
			//		result is false. The important thing is that the expression is evaluted during compile time, and therefore if the expression is false
			//		the compilation will be terminated and the error message will be displayed. This method should not be used, because it does nothing during
			//		run time
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
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual void AssertTemplateArgumentsRequirementsDuringCompileTime__Private() const;


		};  //  Class ExponentialVariable




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































		// Method Information :
		//
		//  Description :
		//
		//   	Default Constructor
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
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NumericType >
        inline ExponentialVariable< NumericType >::ExponentialVariable() :
		Variable_Interface< NumericType >(),
		member_coefficient( 0UL ),
		member_power( 0UL )
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
		//          1. coefficient - the value for the variable coefficient
		//			2. power - the value that the base, which is the variable, shoould be raised by
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NumericType >
        ExponentialVariable< NumericType >::ExponentialVariable( NumericType coefficient, NumericType power ) :
		Variable_Interface< NumericType >(),
		member_coefficient( coefficient ),
		member_power( power )
		{}


		// Method Information :
		//
		//  Description :
		//
		//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
		//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
		//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
		//
		//				1.
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
		template< typename NumericType >
		inline ExponentialVariable< NumericType >::ExponentialVariable( const Tuple< NumericType, NumericType >& arguments ) :
		ExponentialVariable( arguments.template Entry< 0 >(), arguments.template Entry< 1 >() )
		{}


		// Method Information :
		//
		//  Description :
		//
		//   	Copy constructor, will operate correctly even if the other instance is in default state or self assignment
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          other - a reference to the instance that should be copied
		//
		//		Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NumericType >
        inline ExponentialVariable< NumericType >::ExponentialVariable( const ExponentialVariable< NumericType >& other ) :
		Variable_Interface< NumericType >(),
		member_coefficient( other.member_coefficient ),
		member_power( other.member_power )
		{}


		// Method Information :
		//
		//  Description :
		//
		//      This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the instance that should be swaped
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
		template< typename NumericType >
		inline void ExponentialVariable< NumericType >::Swap( ExponentialVariable< NumericType >& other )
		{
			// Swap between the coefficients
			Memory::Operations::Swap< NumericType >( member_coefficient, other.member_coefficient );

			// Swap between the powers
			Memory::Operations::Swap< NumericType >( member_power, other.member_power );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          1. coefficient - the value for the variable coefficient
		//			2. power - the value that the base, which is the variable, shoould be raised by
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
		//		They will come
		//
		template< typename NumericType >
		inline void ExponentialVariable< NumericType >::Initiate( NumericType coefficient, NumericType power )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    ExponentialVariable< NumericType > temporary( coefficient, power );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
    	}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the "result" of the variable, when acted on the given value
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
		template< typename NumericType >
		NumericType ExponentialVariable< NumericType >::Value( NumericType value )
		{
			// Raise the value by the power, multiply by the coefficient, and return the result
			return ( member_coefficient * BaseRaisedByThePower::Calculate< NumericType >( value, member_power ) );
		}

































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 instances are the same
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NumericType >
        inline Boolean ExponentialVariable< NumericType >::operator==( const ExponentialVariable< NumericType >& other ) const
		{
			// Compare the coefficients and the powers, and return the result
			return ( ( member_coefficient == other.member_coefficient ) && ( member_power == other.member_power ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance does not match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 instances are not the same
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NumericType >
        inline Boolean ExponentialVariable< NumericType >::operator!=( const ExponentialVariable< NumericType >& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************




































		// Method Information :
		//
		//  Description :
		//
		//      Use this method to generate a random instance of this object
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. rangeForCoefficient - this will be used to limit the possible values of the coefficient in the random instance
		//			2. rangeForPower - this will be used to limit the possible values of the power in the random instance
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A random generated instance
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NumericType >
		inline ExponentialVariable< NumericType > ExponentialVariable< NumericType >::GenerateRandomInstance( NumericRange< NumericType > rangeForCoefficient, NumericRange< NumericType > rangeForPower )
		{
			// Choose a random value from the range
			static Random::PickNumber< NumericType > pickNumber;

			// Return a copy of the instance
			return ( MOVE( ExponentialVariable< NumericType >( pickNumber.Get( rangeForCoefficient ), pickNumber.Get( rangeForPower ) ) ) );
		}


































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































		// Method Information :
		//
		//  Description :
		//
		//      This method will be used to assert all the requirements on the template arguments provided to the object. To perform a compile time assert
		//		the C++ language provides the keyword 'static_assert', which receives an expression and an error message to display if the expression
		//		result is false. The important thing is that the expression is evaluted during compile time, and therefore if the expression is false
		//		the compilation will be terminated and the error message will be displayed. This method should not be used, because it does nothing during
		//		run time
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
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NumericType >
		void ExponentialVariable< NumericType >::AssertTemplateArgumentsRequirementsDuringCompileTime__Private() const
		{
			// This method will contain as much as neccessary compile time assertions to check that the given template arguments pass the requirements
			//CompileTimeAssert();
		}


































// *********************************************************************************   TESTING   ********************************************************************************




































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
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		1. An assertion failed - class Exception is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			template< typename NumericType >
			void ExponentialVariable< NumericType >::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::Full< ExponentialVariable< NumericType > COMMA NumericType COMMA NumericType >();

				// Create a test instance
				ExponentialVariable< UnsignedInteger32bits > testExponentialVariable_1( 45, 3 );

				// Check the results
				Assert_MACRO( ( testExponentialVariable_1.Value( 2 ) == 360 ), "Test failed - 1" )
				Assert_MACRO( ( testExponentialVariable_1.Value( 1 ) == 45 ), "Test failed - 2" )
				Assert_MACRO( ( testExponentialVariable_1.Value( 0 ) == 0 ), "Test failed - 3" )
				Assert_MACRO( ( testExponentialVariable_1.Value( 10 ) == 45000 ), "Test failed - 4" )

				// Create a test instance of signed nature
				ExponentialVariable< SignedInteger32bits > testExponentialVariable_2( 2, 3 );

				// Check the results
				Assert_MACRO( ( testExponentialVariable_2.Value( 2 ) == 16 ), "Test failed - 5" )
				Assert_MACRO( ( testExponentialVariable_2.Value( 1 ) == 2 ), "Test failed - 6" )
				Assert_MACRO( ( testExponentialVariable_2.Value( 0 ) == 0 ), "Test failed - 7" )
				Assert_MACRO( ( testExponentialVariable_2.Value( 10 ) == 2000 ), "Test failed - 8" )
				Assert_MACRO( ( testExponentialVariable_2.Value( -1 ) == -2 ), "Test failed - 9" )
				Assert_MACRO( ( testExponentialVariable_2.Value( -8 ) == -1024 ), "Test failed - 10" )
			}

		)  //  End of debug tool











    }  //  Namespace Mathematics

}  //  Namespace Universe


#endif  // EXPONENTIALVARIABLE_HPP