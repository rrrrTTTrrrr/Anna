#ifndef MEMBER
#define MEMBER


namespace Universe
{


	namespace Meta
    {


		// Class Information :
		//
		//  Purpose :
		//
		//		Artifical Inteligence
		//
		//  Description :
		//
		// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
		//		2. Template arguments :
		//
		//			1.
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class Member NotForInheritance
		{
		public:


			// Create a type definition for this object
			using SelfType = Member< MemberType >;


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
			inline Member();


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
			//			1. name - the name of the member
			//			2. encapsulationClassification - the encapsulation classification of the method, can be either public, protected or private
			//			3. isConstantExpression - a boolean to describe if the member is a constant expression or not
			//			4. isConstant - a boolean to describe if the member is declared as constant
			//			5. isVolatile - a boolean to describe if the member is declared as volatile
			//			6. isStatic - a boolean to describe if the member is declared as static
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
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline Member( const Language::String& name, const Language::String& encapsulationClassification, Boolean isConstantExpression, Boolean isConstant, Boolean isVolatile, Boolean isStatic );


			// Add the following infrastructure to the object :
			//
			//		1. Move constructor
			//		2. Move assigenment operator
			//		3. Swap
			//		4. Reset
			//
			MoveConstructor_Creator( Member )
			MoveAssignmentOperator_Creator()
			Swap_Creator()
			Reset_Creator( inline )


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
			inline ~Member() = default;


			// This part will contain all the get and set methods for the members of the object :


			GetByConstantReference_Creator( /* GetMethodName */ Name, /* MemberName */ member_name, /* MemberType */ Language::String )
			GetByConstantReference_Creator( /* GetMethodName */ EncapsulationClassification, /* MemberName */ member_encapsulationClassification, /* MemberType */ Language::String )
			GetByValue_Creator( /* GetMethodName */ IsInline, /* MemberName */ member_isInline, /* MemberType */ Boolean )
			GetByValue_Creator( /* GetMethodName */ IsConstantExpression, /* MemberName */ member_isConstantExpression, /* MemberType */ Boolean )
			GetByValue_Creator( /* GetMethodName */ IsVolatile, /* MemberName */ member_isVolatile, /* MemberType */ Boolean )
			GetByValue_Creator( /* GetMethodName */ IsStatic, /* MemberName */ member_isStatic, /* MemberType */ Boolean )


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
				static inline void UnitTest() __attribute__ (( __unused__ ));

			)  //  End of debug tool


		private:


			// Disable all the abilites of the object to copy itself, this include the copy constructor and assignment operator
			DisableCopyConstructorAndAssignmentOperator( Method );


			// This string will store the member name
			Language::String member_name;

 			// This object will store if the member is public, protected or private
 			Language::String member_encapsulationClassification;

			// This boolean will store if the member is a constant expression
			Boolean member_isConstantExpression;

			// This boolean will store if the member is constant
			Boolean member_isConstant;

			// This boolean will store if the member is volatile
			Boolean member_isVolatile;

			// This boolean will store if the member is static
			Boolean member_isStatic;


		};  //  Class Member