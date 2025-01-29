#ifndef RATIONALNUMBER_HPP
#define RATIONALNUMBER_HPP


#include "../../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure
#include "../../../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../../../../../../Content/Metaprogramming/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../Numbers/Numbers.hpp"  //  Class Numbers


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
		//		Artifical Inteligence
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
		//
		// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class RationalNumber NotForInheritance
		{
		public:


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
			inline RationalNumber();


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
			//			1. numerator - the integer that will be above the fraction line, this number will be divided by the denominator
			//			2. denominator - the integer that will be below the fraction line, the numerator will be divided by this number
			//			3. sign - this boolean will be used only to store the sign of the rational number instance, true for positive and false for negative
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
			//		1. The denominator can not be 0
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			explicit inline RationalNumber( UnsignedInteger64bits numerator, UnsignedInteger64bits denominator, Boolean sign = true );


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
			//				1. numerator - the integer that will be above the fraction line, this number will be divided by the denominator
			//				2. denominator - the integer that will be below the fraction line, the numerator will be divided by this number
			//				3. sign - this boolean will be used only to store the sign of the rational number instance, true for positive and false for negative
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
			explicit inline RationalNumber( const Tuple< UnsignedInteger64bits, UnsignedInteger64bits, Boolean >& arguments );


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
			inline RationalNumber( const RationalNumber& other );


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
			ObjectInfrastructure_WithStateAlwaysReady( RationalNumber )


			// Method Information :
			//
			//  Description :
			//
			//		This method is used to swap the content between this instance and the other one
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be swapped
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
			inline void Swap( RationalNumber& other );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. numerator - the integer that will be above the fraction line, this number will be divided by the denominator
			//			2. denominator - the integer that will be below the fraction line, the numerator will be divided by this number
			//			3. sign - this boolean will be used only to store the sign of the rational number instance, true for positive and false for negative
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
			//		1. The denominator can not be 0
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void Initiate( UnsignedInteger64bits numerator, UnsignedInteger64bits denominator, Boolean sign );


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
			inline ~RationalNumber() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the numerator
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
			//		The numerator
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger64bits Numerator() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the denominator
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
			//		The denominator
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger64bits Denominator() const;


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
			//			other - a reference to the instance that should be compared with this object
			//
			//      Information returned to the user :
			//
			//			NONE
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
			inline Boolean operator==( const RationalNumber& other ) const;


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to check if the rational number inside this instance matches the right side operand  
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
			//      1. true - if the instance is equal to the right side operator integer
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
	        inline Boolean operator==( UnsignedInteger64bits rightSideOperand ) const;


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
			//			other - a reference to the instance that should be compared with this object
			//
			//      Information returned to the user :
			//
			//			NONE
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
			inline Boolean operator!=( const RationalNumber& other ) const;


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to check if the rational number inside this instance does not match the right side operand  
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
			//      1. true - if the instance is not equal to the right side operator integer
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
	        inline Boolean operator!=( UnsignedInteger64bits rightSideOperand ) const;


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to add the right side operand integer to the rational number in this instance, and return the result in a
	        // 		different instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		A copy of a rational number instance with the addition result
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //  
	        inline RationalNumber operator+( UnsignedInteger64bits rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to add the right side operand rational number to the rational number in this instance, and return the result in a
	        // 		different instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		A copy of a rational number instance with the addition result
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //  
	        inline RationalNumber operator+( const RationalNumber& rightSideOperand );


            // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to add the right side operand instance to this instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
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
	        RationalNumber& operator+=( const RationalNumber& rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to subtract the right side operand integer from the rational number in this instance, and return the result in a
	        // 		different instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		A copy of a rational number instance with the subtraction result
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //  
	        inline RationalNumber operator-( UnsignedInteger64bits rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to subtract the right side operand rational number from the rational number in this instance, and return the result in a
	        // 		different instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		A copy of a rational number instance with the subtraction result
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //  
	        inline RationalNumber operator-( const RationalNumber& rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to subtract from the rational number in this instance the data inside the right side operand object
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
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
	        RationalNumber& operator-=( const RationalNumber& rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to multiply the right side operand integer and the rational number in this instance, and return the result in a
	        // 		different instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		A copy of a rational number instance with the multiplication result
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //  
	        inline RationalNumber operator*( UnsignedInteger64bits rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to multiply the right side operand rational number and the rational number in this instance, and return the result in a
	        // 		different instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		A copy of a rational number instance with the multiplication result
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //  
	        inline RationalNumber operator*( const RationalNumber& rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to divide the the rational number in this instance by the right side operand integer, and return the result in a
	        // 		different instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		A copy of a rational number instance with the divison result
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //  
	        inline RationalNumber operator/( UnsignedInteger64bits rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to divide the the rational number in this instance by the right side operand rational number, and return the result in a
	        // 		different instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		A copy of a rational number instance with the divison result
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //  
	        inline RationalNumber operator/( const RationalNumber& rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to add the right side operand integer to this instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
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
	        inline RationalNumber& operator+=( UnsignedInteger64bits rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to subtract the right side operand instance from this instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
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
	        inline RationalNumber& operator-=( UnsignedInteger64bits rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to multiply the rational number inside this instance by the right side operand
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
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
	        inline RationalNumber& operator*=( UnsignedInteger64bits rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to multiply the rational number inside this instance by the data inside the right side operand instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
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
	        inline RationalNumber& operator*=( const RationalNumber& rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to divide the rational number inside this instance by the right side operand
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
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
	        inline RationalNumber& operator/=( UnsignedInteger64bits rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to divide the rational number inside this instance by the data inside the right side operand object
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
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
	        inline RationalNumber& operator/=( const RationalNumber& rightSideOperand );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to check if the rational number inside this instance is larger then the right side operand  
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		True if the rational number inside this instance is larger then the righe side operand, and false otherwise
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come 
	        //  
	        inline Boolean operator>( UnsignedInteger64bits rightSideOperand ) const;


            // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to check if the rational number in this instance is larger then the data inside the right side operand object
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		True if the rational number in this instance is larger then the righe side operand, and false otherwise
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come 
	        //  
	        Boolean operator>( const RationalNumber& rightSideOperand ) const;


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to check if the rational number inside this instance is smaller then the right side operand  
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		True if the rational number inside this instance is smaller then the righe side operand, and false otherwise
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come 
	        //  
	        inline Boolean operator <( UnsignedInteger64bits rightSideOperand ) const;


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to check if the rational number in this instance is smaller then the data inside the right side operand object
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		True if the rational number in this instance is smaller then the righe side operand, and false otherwise
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come 
	        //  
	        Boolean operator <( const RationalNumber& rightSideOperand ) const;


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to check if the rational number inside this instance is equal or larger then the right side operand  
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		True if the rational number inside this instance is larger or equal then the righe side operand, and false otherwise
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come 
	        //  
	        inline Boolean operator>=( UnsignedInteger64bits rightSideOperand ) const;


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to check if the rational number inside this instance is equal or larger then the data inside the right side operand object
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		True if the rational number inside this instance is larger or equal then the righe side operand, and false otherwise
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come 
	        //  
	        inline Boolean operator>=( const RationalNumber& rightSideOperand ) const;


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to check if the rational number inside this instance is equal or smaller then the right side operand  
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - an integer
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		True if the rational number inside this instance is smaller then the righe side operand, and false otherwise
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come 
	        //  
	        inline Boolean operator<=( UnsignedInteger64bits rightSideOperand ) const;


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to check if the rational number inside this instance is equal or smaller then the data inside the right side operand object
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          rightSideOperand - a reference to another rational number instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //		True if the rational number inside this instance is smaller then the righe side operand, and false otherwise
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come 
	        //  
	        inline Boolean operator<=( const RationalNumber& rightSideOperand ) const;


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


			// This object will store the numerator
			UnsignedInteger64bits member_numerator;

			// This object will store the denominator
			UnsignedInteger64bits member_denominator;

			// This integer will store the sign of the rational number, 1 for positive and -1 for negative
			SignedInteger8bits member_sign;


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to convert the rational number to simplified form. A rational number is written in its simplified form if the numerator
			//		and denominator have no common factor
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
			void SimplifiedForm__Private();


		};  //  Class RationalNumber



        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to add the left side operand integer to the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		A copy of a rational number instance with the addition result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber operator+( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand );


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to subtract the right side operand rational number instance from the left side operand integer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A copy of a rational number instance with the subtraction result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber operator-( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand );


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to multiply the left side operand integer and the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A copy of a rational number instance with the multiplication result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber operator*( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand );


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to divide the left side operand integer by the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A copy of a rational number instance with the divison result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber operator/( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand );


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the left side operand integer is larger then the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the integer is larger then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline Boolean operator>( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand );


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the left side operand integer is larger or equal to the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the integer is larger or equal to the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline Boolean operator>=( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand );


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the left side operand integer is smaller then the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the integer is smaller then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline Boolean operator <( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand );


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the left side operand integer is smaller or equal to the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the integer is smaller or equal to the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline Boolean operator<=( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand );






































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































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
		inline RationalNumber::RationalNumber() :
		member_numerator( 0UL ),
		member_denominator( 1UL ),
		member_sign( 1 )
		{}


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
		//			1. numerator - the integer that will be above the fraction line, this number will be divided by the denominator
		//			2. denominator - the integer that will be below the fraction line, the numerator will be divided by this number
		//			3. sign - this boolean will be used only to store the sign of the rational number instance, true for positive and false for negative
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
		//		1. The denominator can not be 0
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline RationalNumber::RationalNumber( UnsignedInteger64bits numerator, UnsignedInteger64bits denominator, Boolean sign ) :
		member_numerator( numerator ),
		member_denominator( denominator ),
		member_sign( ( sign == true ) ? 1 : -1 )
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( ( denominator != 0 ), "The denominator can not be 0" )

			// Set the simplified form of the rational number
			SimplifiedForm__Private();
		}


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
		//				1. numerator - the integer that will be above the fraction line, this number will be divided by the denominator
		//				2. denominator - the integer that will be below the fraction line, the numerator will be divided by this number
		//				3. sign - this boolean will be used only to store the sign of the rational number instance, true for positive and false for negative
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
		inline RationalNumber::RationalNumber( const Tuple< UnsignedInteger64bits, UnsignedInteger64bits, Boolean >& arguments ) :
		RationalNumber( arguments.template Entry< 0 >(), arguments.template Entry< 1 >(), arguments.template Entry< 2 >() )
		{}


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
		inline RationalNumber::RationalNumber( const RationalNumber& other ) :
		member_numerator( other.member_numerator ),
		member_denominator( other.member_denominator ),
		member_sign( other.member_sign )
		{}


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		other - a reference to the instance that should be swaped
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
		void RationalNumber::Swap( RationalNumber& other )
		{
			// Swap between the numerators
			Memory::Operations::Swap< UnsignedInteger64bits >( member_numerator, other.member_numerator );

			// Swap between the denominators
			Memory::Operations::Swap< UnsignedInteger64bits >( member_denominator, other.member_denominator );

			// Swap between the sign
			Memory::Operations::Swap< SignedInteger8bits >( member_sign, other.member_sign );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. numerator - the integer that will be above the fraction line, this number will be divided by the denominator
		//			2. denominator - the integer that will be below the fraction line, the numerator will be divided by this number
		//			3. sign - this boolean will be used only to store the sign of the rational number instance, true for positive and false for negative
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
		//		1. The denominator can not be 0
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline void RationalNumber::Initiate( UnsignedInteger64bits numerator, UnsignedInteger64bits denominator, Boolean sign )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    RationalNumber temporary( numerator, denominator, sign );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
    	}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the numerator
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
		//		The numerator
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger64bits RationalNumber::Numerator() const
		{
			// Return a copy of the numerator
			return ( member_numerator );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the denominator
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
		//		The denominator
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger64bits RationalNumber::Denominator() const
		{
			// Return a copy of the denominator
			return ( member_denominator );
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
		//			other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//			NONE
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
		inline Boolean RationalNumber::operator==( const RationalNumber& other ) const
		{
			// Compate the numerator and denominator, and return the result
			return ( ( member_numerator == other.member_numerator ) && ( member_denominator == other.member_denominator ) && ( member_sign == other.member_sign ) );
		}


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the rational number inside this instance matches the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
		//      1. true - if the instance is equal to the right side operator integer
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
        inline Boolean RationalNumber::operator==( UnsignedInteger64bits rightSideOperand ) const
        {            
            // Check if the sign of this instance is positive, and the right side operand integer multiplied by the denominator is equal to the
            // numerator, and retrun the result
            return ( ( member_sign == 1 ) && ( member_numerator == ( rightSideOperand * member_denominator ) ) );
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
		//			other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//			NONE
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
		inline Boolean RationalNumber::operator!=( const RationalNumber& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the rational number inside this instance does not match the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
		//      1. true - if the instance is not equal to the right side operator integer
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
        inline Boolean RationalNumber::operator!=( UnsignedInteger64bits rightSideOperand ) const
        {            
			// Return the negotiated value from the equal operator
			return ( !( *this == rightSideOperand ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to add the right side operand integer to the rational number in this instance, and return the result in a
        // 		different instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		A copy of a rational number instance with the addition result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber RationalNumber::operator+( UnsignedInteger64bits rightSideOperand )
        {
        	// This object will store the result of the addition. It will be initialized with a copy of the rational number instance
        	RationalNumber additionResult( *this );

        	// Perfrom the addition 
        	additionResult += rightSideOperand;

        	// Return a copy of the addition result
        	return ( MOVE( additionResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to add the right side operand rational number to the rational number in this instance, and return the result in a
        // 		different instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		A copy of a rational number instance with the addition result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber RationalNumber::operator+( const RationalNumber& rightSideOperand )
        {
        	// This object will store the result of the addition. It will be initialized with a copy of the rational number instance
        	RationalNumber additionResult( *this );

        	// Perfrom the addition 
        	additionResult += rightSideOperand;

        	// Return a copy of the addition result
        	return ( MOVE( additionResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to subtract the right side operand integer from the rational number in this instance, and return the result in a
        // 		different instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		A copy of a rational number instance with the subtraction result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber RationalNumber::operator-( UnsignedInteger64bits rightSideOperand )
        {
        	// This object will store the result of the subtraction. It will be initialized with a copy of the rational number instance
        	RationalNumber subtractionResult( *this );

        	// Perfrom the subtraction 
        	subtractionResult -= rightSideOperand;

        	// Return a copy of the subtraction result
        	return ( MOVE( subtractionResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to subtract the right side operand rational number from the rational number in this instance, and return the result in a
        // 		different instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		A copy of a rational number instance with the subtraction result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber RationalNumber::operator-( const RationalNumber& rightSideOperand )
        {
        	// This object will store the result of the subtraction. It will be initialized with a copy of the rational number instance
        	RationalNumber subtractionResult( *this );

        	// Perfrom the subtraction 
        	subtractionResult -= rightSideOperand;

        	// Return a copy of the subtraction result
        	return ( MOVE( subtractionResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to multiply the right side operand integer and the rational number in this instance, and return the result in a
        // 		different instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		A copy of a rational number instance with the multiplication result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber RationalNumber::operator*( UnsignedInteger64bits rightSideOperand )
        {
        	// This object will store the result of the multiplication. It will be initialized with a copy of the rational number instance
        	RationalNumber multiplicationResult( *this );

        	// Perfrom the multiplication 
        	multiplicationResult *= rightSideOperand;

        	// Return a copy of the multiplication result
        	return ( MOVE( multiplicationResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to multiply the right side operand rational number and the rational number in this instance, and return the result in a
        // 		different instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		A copy of a rational number instance with the multiplication result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber RationalNumber::operator*( const RationalNumber& rightSideOperand )
        {
        	// This object will store the result of the multiplication. It will be initialized with a copy of the rational number instance
        	RationalNumber multiplicationResult( *this );

        	// Perfrom the multiplication 
        	multiplicationResult *= rightSideOperand;

        	// Return a copy of the multiplication result
        	return ( MOVE( multiplicationResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to divide the the rational number in this instance by the right side operand integer, and return the result in a
        // 		different instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		A copy of a rational number instance with the divison result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber RationalNumber::operator/( UnsignedInteger64bits rightSideOperand )
        {
        	// This object will store the result of the divison. It will be initialized with a copy of the rational number instance
        	RationalNumber divisonResult( *this );

        	// Perfrom the divison 
        	divisonResult /= rightSideOperand;

        	// Return a copy of the divison result
        	return ( MOVE( divisonResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to divide the the rational number in this instance by the right side operand rational number, and return the result in a
        // 		different instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		A copy of a rational number instance with the divison result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber RationalNumber::operator/( const RationalNumber& rightSideOperand )
        {
        	// This object will store the result of the divison. It will be initialized with a copy of the rational number instance
        	RationalNumber divisonResult( *this );

        	// Perfrom the divison 
        	divisonResult /= rightSideOperand;

        	// Return a copy of the divison result
        	return ( MOVE( divisonResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to add the right side operand integer to this instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
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
        inline RationalNumber& RationalNumber::operator+=( UnsignedInteger64bits rightSideOperand )
        {
        	// Fraction subtraction :
        	//
        	//		a       a   c   a + c * b
        	//		- + c = - + - = ---------
        	// 		b       b   1       b

        	// An integer can be considered as a rational number with the numerator as the integer, and the denominator as 1. This means that
        	// the smallest common multiple, is the denominator of this instance. Then all there is to do in order to add the integer to the
        	// rational number, is to multiply it by the denominator of this instance, and add the result to the numerator
        	member_numerator += ( rightSideOperand * member_denominator );

			// Set the simplified form of the rational number
			SimplifiedForm__Private();

        	// Return a reference to this instance
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to subtract the right side operand instance from this instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
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
        inline RationalNumber& RationalNumber::operator-=( UnsignedInteger64bits rightSideOperand )
        {
        	// Fraction subtraction :
        	//
        	//		a       a   c   a - c * b
        	//		- - c = - - - = ---------
        	// 		b       b   1       b

        	// An integer can be considered as a rational number with the numerator as the integer, and the denominator as 1. This means that
        	// the smallest common multiple, is the denominator of this instance. Then all there is to do in order to subtract the integer from the
        	// rational number, is to multiply it by the denominator of this instance, and subtract the result from the numerator
        	member_numerator -= ( rightSideOperand * member_denominator );

			// Set the simplified form of the rational number
			SimplifiedForm__Private();

        	// Return a reference to this instance
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to multiply the rational number inside this instance by the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
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
        inline RationalNumber& RationalNumber::operator*=( UnsignedInteger64bits rightSideOperand )
        {
        	// Fraction multiplication :
        	//
        	//		a       a   c   a * c
        	//		- * c = - * - = -----
        	// 		b       b   1   b * 1

        	// To multiply a rational number with an integer all there is to do is multiply the numerator with the intger
        	member_numerator *= rightSideOperand;

			// Set the simplified form of the rational number
			SimplifiedForm__Private();

        	// Return a reference to this instance
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to multiply the rational number inside this instance by the data inside the right side operand instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
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
        inline RationalNumber& RationalNumber::operator*=( const RationalNumber& rightSideOperand )
        {
        	// Fraction multiplication :
        	//
        	//		a   c   a * c
        	//		- * - = -----
        	// 		b   d   b * d

        	// Multiply the numerators
        	member_numerator *= rightSideOperand.member_numerator;

        	// Multiply the denominators
        	member_denominator *= rightSideOperand.member_denominator;

        	// Multiply the signs to get the result sign
        	member_sign *= rightSideOperand.member_sign;

			// Set the simplified form of the rational number
			SimplifiedForm__Private();

        	// Return a reference to this instance
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to divide the rational number inside this instance by the right side operand
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
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
        inline RationalNumber& RationalNumber::operator/=( UnsignedInteger64bits rightSideOperand )
        {            
        	// Division of fractions and integer is performed by mutliplying the oposite fraction :
        	//
        	//		a       a   c   a   1   a * 1
        	//		- / c = - / - = - * - = -----
        	// 		b       b   1   b   c   b * c

        	// Multiply the denominator of this instance by the right side operand integer
        	member_denominator *= rightSideOperand;

			// Set the simplified form of the rational number
			SimplifiedForm__Private();

        	// Return a reference to this instance
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to divide the rational number inside this instance by the data inside the right side operand object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
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
        inline RationalNumber& RationalNumber::operator/=( const RationalNumber& rightSideOperand )
        {
        	// Division of fractions is performed by mutliplying the oposite fraction :
        	//
        	//		a   c   a   d   a * d
        	//		- / - = - * - = ----- 
        	// 		b   d   b   c   b * c

        	// Multiply the numerator of this instance and denominator of the right side operand instance
        	member_numerator *= rightSideOperand.member_denominator;

        	// Multiply the denominator of this instance and the numerator of the right side operand instance
        	member_denominator *= rightSideOperand.member_numerator;

        	// Multiply the signs to get the result sign
        	member_sign *= rightSideOperand.member_sign;

			// Set the simplified form of the rational number
			SimplifiedForm__Private();

        	// Return a reference to this instance
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the rational number inside this instance is larger then the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the rational number inside this instance is larger then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        inline Boolean RationalNumber::operator>( UnsignedInteger64bits rightSideOperand ) const
        {      
        	// Check if the rational number is positive and the right side operand is negative, which means the rational number in this instance
        	// is larger
        	ReturnValueIfExpressionIsTrue( ( member_sign == -1 ), false )

        	// Compare the right side operand multiplied by the denominator of this instance with the numerator of this instance, and retrun the
        	// result
        	return ( member_numerator > ( rightSideOperand * member_denominator ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the rational number inside this instance is smaller then the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the rational number inside this instance is smaller then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        inline Boolean RationalNumber::operator <( UnsignedInteger64bits rightSideOperand ) const
        {            
        	// Check if the rational number is positive and the right side operand is negative, which means the rational number in this instance
        	// is larger
        	ReturnValueIfExpressionIsTrue( ( member_sign == -1 ), false )

        	// Compare the right side operand multiplied by the denominator of this instance with the numerator of this instance, and retrun the
        	// result
        	return ( member_numerator < ( rightSideOperand * member_denominator ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the rational number inside this instance is equal or larger then the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the rational number inside this instance is larger or equal then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        inline Boolean RationalNumber::operator>=( UnsignedInteger64bits rightSideOperand ) const
        {            
        	// Check if the rational number is positive and the right side operand is negative, which means the rational number in this instance
        	// is larger
        	ReturnValueIfExpressionIsTrue( ( member_sign == -1 ), false )

        	// Compare the right side operand multiplied by the denominator of this instance with the numerator of this instance, and retrun the
        	// result
        	return ( member_numerator >= ( rightSideOperand * member_denominator ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the rational number inside this instance is equal or larger then the data inside the right side operand object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the rational number inside this instance is larger or equal then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        inline Boolean RationalNumber::operator>=( const RationalNumber& rightSideOperand ) const
        {            
        	// Return the negotiated result from using the smaller operator, which is the exact opposite of this operation
        	return ( !( *this < rightSideOperand ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the rational number inside this instance is equal or smaller then the right side operand  
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - an integer
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the rational number inside this instance is smaller then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        inline Boolean RationalNumber::operator<=( UnsignedInteger64bits rightSideOperand ) const
        {            
        	// Check if the rational number is positive and the right side operand is negative, which means the rational number in this instance
        	// is larger
        	ReturnValueIfExpressionIsTrue( ( member_sign == -1 ), false )

        	// Compare the right side operand multiplied by the denominator of this instance with the numerator of this instance, and retrun the
        	// result
        	return ( member_numerator <= ( rightSideOperand * member_denominator ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the rational number inside this instance is equal or smaller then the data inside the right side operand object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rightSideOperand - a reference to another rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the rational number inside this instance is smaller then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come 
        //  
        inline Boolean RationalNumber::operator<=( const RationalNumber& rightSideOperand ) const
        {            
        	// Return the negotiated result from using the larger operator, which is the exact opposite of this operation
        	return ( !( *this > rightSideOperand ) );
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
		//			1. rangeForNumerator - this will be used to limit the possible values of the numerator in the random instance
		//			2. rangeForDenominator - this will be used to limit the possible values of the denominator in the random instance
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
		inline RationalNumber RationalNumber::GenerateRandomInstance( Range< UnsignedInteger64bits > rangeForNumerator, Range< UnsignedInteger64bits > rangeForDenominator )
		{
			// This object will store the denominator
			UnsignedInteger64bits denominator = Random::Generator::Get< UnsignedInteger64bits >( rangeForDenominator );

			// The denominator can not be 0, therefore a loop will be used to pick numbers until a non zero number is picked
			while ( denominator == 0 )
			{
				// Pick another number 
				denominator = Random::Generator::Get( rangeForDenominator );
			}

			// Return a copy of the instance
			return ( MOVE( RationalNumber( Random::Generator::Get< UnsignedInteger64bits >( rangeForNumerator ), denominator, Random::Generator::Get< Boolean >() ) ) );
		}

































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************
































        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to add the left side operand integer to the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		A copy of a rational number instance with the addition result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber operator+( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand )
        {
        	// This object will store the result of the addition. It will be initialized with a copy of the rational number instance
        	RationalNumber additionResult( rightSideOperand );

        	// Perfrom the addition 
        	additionResult += leftSideOperand;

        	// Return a copy of the addition result
        	return ( MOVE( additionResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to subtract the right side operand rational number instance from the left side operand integer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A copy of a rational number instance with the subtraction result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber operator-( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand )
        {
        	// This object will store the result of the subtraction. It will be initialized with a copy of the rational number instance
        	RationalNumber subtractionResult( rightSideOperand );

        	// Perfrom the subtraction 
        	subtractionResult -= leftSideOperand;

        	// Return a copy of the subtraction result
        	return ( MOVE( subtractionResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to multiply the left side operand integer and the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A copy of a rational number instance with the multiplication result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber operator*( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand )
        {
        	// This object will store the result of the multiplication. It will be initialized with a copy of the rational number instance
        	RationalNumber multiplicationResult( rightSideOperand );

        	// Perfrom the multiplication 
        	multiplicationResult *= leftSideOperand;

        	// Return a copy of the multiplication result
        	return ( MOVE( multiplicationResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to divide the left side operand integer by the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //        A copy of a rational number instance with the divison result
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline RationalNumber operator/( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand )
        {
        	// This object will store the result of the divison. It will be initialized with a copy of the rational number instance
        	RationalNumber divisonResult( rightSideOperand );

        	// Perfrom the divison 
        	divisonResult /= leftSideOperand;

        	// Return a copy of the divison result
        	return ( MOVE( divisonResult ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the left side operand integer is larger then the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the integer is larger then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline Boolean operator>( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand )
        {
        	// Compare the operands and return the result
        	return ( rightSideOperand < leftSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the left side operand integer is larger or equal to the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the integer is larger or equal to the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline Boolean operator>=( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand )
        {
        	// Compare the operands and return the result
        	return ( rightSideOperand <= leftSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the left side operand integer is smaller then the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the integer is smaller then the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline Boolean operator <( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand )
        {
        	// Compare the operands and return the result
        	return ( rightSideOperand > leftSideOperand );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the left side operand integer is smaller or equal to the right side operand rational number instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. leftSideOperand - an integer
        //          2. rightSideOperand - a reference to a rational number instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //		True if the integer is smaller or equal to the righe side operand, and false otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //  
        inline Boolean operator<=( UnsignedInteger64bits leftSideOperand, const RationalNumber& rightSideOperand )
        {
        	// Compare the operands and return the result
        	return ( rightSideOperand >= leftSideOperand );
        }












	}  //  Namespace Mathematics

}  //  Namespace Universe



#endif  // RATIONALNUMBER_HPP