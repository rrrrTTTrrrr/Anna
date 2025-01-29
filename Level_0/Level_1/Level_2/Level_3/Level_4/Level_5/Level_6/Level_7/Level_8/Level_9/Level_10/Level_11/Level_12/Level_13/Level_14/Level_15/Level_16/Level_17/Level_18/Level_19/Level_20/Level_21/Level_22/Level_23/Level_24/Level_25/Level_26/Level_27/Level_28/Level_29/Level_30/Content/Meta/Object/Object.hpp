#ifndef OBJECT
#define OBJECT


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
		template< typename ObjectType >
		class Object NotForInheritance
		{
		public:


			// Create a type definition for this object
			using SelfType = Object< ObjectType >;


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
			inline Object();


			// Add the following infrastructure to the object :
			//
			//		1. Move constructor
			//		2. Move assigenment operator
			//		3. Swap
			//		4. Reset
			//
			MoveConstructor_Creator( Object )
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
			inline ~Object() = default;


			// This part will contain all the get and set methods for the members of the object :


			// Member - 
			GetByValue_Creator( GetMethodName, MemberName, MemberType )
			GetOnlyIfInstanceIsReady( GetMethodName, MemberName, MemberType )
			SetByValue_Creator( SetMethodName, MemberName, MemberType )
			SetOnlyIfInstanceIsReady( SetMethodName, MemberName, MemberType )


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


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
			// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
			// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
			// or some functionality needed that does not involve the non static data members


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
			DisableCopyConstructorAndAssignmentOperator( Object );


            // Methods information :

			// This array will store the meta information on the methods of the object
			SequentialDataStructure< Method, Memory::HeapArray > member_methods;


            // Members information :

			// This array will store the meta information on the members of the object
			SequentialDataStructure< Member, Memory::HeapArray > member_members;


            // General information :

            // This object will store if the object has a default constructor
            Boolean m_doesDefaultConstructorExist;

            // This object will store if the object has a parameterized constructor
            Boolean m_doesParameterizedConstructorExist;

            // This object will store if the object has a destructor
            Boolean m_doesDestructorExist;

            // This object will store if the object has a copy constructor
            Boolean m_doesCopyConstructorExist;

             // This object will store if the object has an assignment operator
            Boolean m_doesAssignmentOperatorExist;

            // This object will store if the object has a move constructor
            Boolean m_doesMoveConstructorExist;

            // This object will store if the object has a move assignment operator
            Boolean m_doesMoveAssignmentOperatorExist;

            // This object will store if the object is templated
            Boolean m_isTemplated;

            // This object will store if the object inherits from another object
            Boolean m_doesInherit;


			// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the
			// start of the program and only destroyed when the program ends. The access to the static member is bound to this object of course


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
			// the interface, but rather help implement it :


			// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is
			// sometimes useful to allow a particular object to access private members of other object. The declration of such function is private,
			// because these functions are part of the implemntation, which the user should not be aware of. The use of this functions is not limited
			// to the object's scope. One of the problems that friend declaration solves is when the object needs to be as a right side operand in
			// expressions. Every method in the object is implicitly added a pointer to the location of the object data with the name "this", and
			// to enable this the method must be called from an existing instance. This means that the object can only be implemented as the left side
			// operand of an expression with methods, and friend functions and objects does not have this limitation


		};  //  Class Object