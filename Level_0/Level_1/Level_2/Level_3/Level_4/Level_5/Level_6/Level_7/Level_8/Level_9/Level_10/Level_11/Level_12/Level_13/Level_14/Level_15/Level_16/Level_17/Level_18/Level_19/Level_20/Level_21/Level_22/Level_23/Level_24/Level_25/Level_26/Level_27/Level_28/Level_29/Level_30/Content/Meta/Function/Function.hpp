#ifndef FUNCTION
#define FUNCTION


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
		class Function NotForInheritance
		{
		public:


			// Create a type definition for this object
			using SelfType = Function;


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
			inline Function();


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
			//			1. name - the name of the function
			//			2. containingFileName - the name of the file that contains the function
			//			3. namespaceName - the namespace that the function is part of ( Universe is the main namespace, this should be the subnamespace, if there isn't provide 'NONE' )
			//			4. isInline - a boolean to describe if the function is inline or not
			//			5. isConstantExpression - a boolean to describe if the function is a constant expression or not
			//			6. canThrowException - a boolean to describe if the function can throw an exception or not
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
			inline Function( const Language::String& name, const Language::String& containingFileName, const Language::String& namespaceName, Boolean isInline, Boolean isConstantExpression, Boolean canThrowException );


			// Add the following infrastructure to the object :
			//
			//		1. Move constructor
			//		2. Move assigenment operator
			//		3. Swap
			//		4. Reset
			//
			MoveConstructor_Creator( Function )
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
			inline ~Function() = default;


			// This part will contain all the get and set methods for the members of the object :


			GetByReference_Creator( /* GetMethodName */ Pointer, /* MemberName */ member_pointer, /* MemberType */ ConsiderAsOneArgument( FunctionPointer< ReturnValueType, FunctionArgumentTypes... > ) )
			GetByConstantReference_Creator( /* GetMethodName */ Name, /* MemberName */ member_name, /* MemberType */ Language::String )
			GetByConstantReference_Creator( /* GetMethodName */ ContainingFileAbsolutePath, /* MemberName */ member_containingFileAbsolutePath, /* MemberType */ Language::String )
			GetByConstantReference_Creator( /* GetMethodName */ Namespace, /* MemberName */ member_namespace, /* MemberType */ Language::String )
			GetByValue_Creator( /* GetMethodName */ IsInline, /* MemberName */ member_isInline, /* MemberType */ Boolean )
			GetByValue_Creator( /* GetMethodName */ IsConstantExpression, /* MemberName */ member_isConstantExpression, /* MemberType */ Boolean )
			GetByValue_Creator( /* GetMethodName */ CanThrowException, /* MemberName */ member_canThrowException, /* MemberType */ Boolean )


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
			DisableCopyConstructorAndAssignmentOperator( Function );


 			// This object will store the function name
 			Language::String member_name;

 			// This object will store the containing file absolute path of the function
 			Language::String member_containingFileAbsolutePath;

 			// This object will store the namespace the function is part of, if exist
 			Language::String member_namespace;

 			// This object will store if the function is marked as inline
 			Boolean member_isInline;

 			// This object will store if the function is marked as constant expression
 			Boolean member_isConstantExpression;

 			// This object will store if the function can throw an exception
 			Boolean member_canThrowException;


		};  //  Class Function