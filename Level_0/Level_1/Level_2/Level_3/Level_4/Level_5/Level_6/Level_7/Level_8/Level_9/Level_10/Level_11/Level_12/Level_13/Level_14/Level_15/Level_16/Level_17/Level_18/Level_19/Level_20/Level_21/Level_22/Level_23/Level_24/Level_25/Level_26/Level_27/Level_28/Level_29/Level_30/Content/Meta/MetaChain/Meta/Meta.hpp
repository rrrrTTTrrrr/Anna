#ifndef META_HPP
#define META_HPP


namespace Universe
{


	namespace SelfAwareness
    {


		// Class Information :
		//
		//  Purpose :
		//
		//		Artifical Inteligence
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
		template< typename Type >
        class Meta
        {
        public:


            // Create a type definition for this object
			using SelfType = Meta< Type >;


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
			inline Meta();


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
			explicit inline Meta();


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
			explicit inline Meta( const Tuple< Type >& arguments );


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
			explicit inline Meta( RandomInstance, NumericRange< Type > rangeFor = NumericRange< Type >() );


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
			inline Meta( const SelfType& other );


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
			ObjectInfrastructure_ForInheritance( Meta< Type > )


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
			inline void Swap( SelfType& other );


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
			//			NONE
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
			inline void Initiate();


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
			virtual ~Meta();


			// This part will contain all the get and set methods for the members of the object :


			// Member - 
			GetByValue_Creator( GetMethodName, MemberName, MemberType )
			GetOnlyIfInstanceIsReady( GetMethodName, MemberName, MemberType )
			SetByValue_Creator( SetMethodName, MemberName, MemberType )
			SetOnlyIfInstanceIsReady( SetMethodName, MemberName, MemberType )


			// The following methods give access and manipulate the data inside this object :











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
			inline Boolean operator==( const SelfType& other ) const;


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
			inline Boolean operator!=( const SelfType& other ) const;


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
			// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
			// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


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


		protected:


			// The protected part is used for inheritance. This means that only this object and the objects that will inherit from it can use the protected data
			// members or methods


		private:


			// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program
			// and only destroyed when the program ends. The access to the static member is bound to this object of course


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
			// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
			// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
			// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
			// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
			// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


			// Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
			// the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
			// thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
			// and the error message will be displayed. This method should not be used, because it does nothing during run time
			CompileTimeAssert(  );


		};  //  Class Meta




































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
		template< typename Type >
        inline Meta< Type >::Meta() :
		member_state(),
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
		template< typename Type >
        inline Meta< Type >::Meta() :
		State( InstanceState::Ready ),
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( (), "" )

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
		template< typename Type >
		inline Meta< Type >::Meta( const Tuple< Type >& arguments ) :
		Meta( arguments.template Entry< 0 >(), arguments.template Entry< 1 >() )
		{}


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
		template< typename Type >
		inline Meta< Type >::Meta( RandomInstance, NumericRange< Type > rangeFor = NumericRange< Type >() ) :
		member_state( InstanceState::Ready ),
		{
		    // Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert( (), "" )

		}


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
		template< typename Type >
        inline Meta< Type >::Meta( const SelfType& other ) :
		member_state( other.member_state ),
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
		template< typename Type >
		inline void Meta< Type >::Swap( SelfType& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );
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
		//			NONE
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
		template< typename Type >
		inline void Meta< Type >::Initiate()
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary;

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
    	}


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
		template< typename Type >
        Meta< Type >::~Meta()
		{
		    // Check if the object is in default state, then noting needs to be done
		    ReturnIfExpressionIsTrue( member_state.Get() == InstanceState::Default )
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
		template< typename Type >
        inline Boolean Meta< Type >::operator==( const SelfType& other ) const
		{
			// Check if both or only one of the instances is in default state
			CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue
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
		template< typename Type >
        inline Boolean Meta< Type >::operator!=( const SelfType& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************




































//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************




































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************




































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************




































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
			template< typename Type >
			void Meta< Type >::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::Full< SelfType,  >();
			}

		)  //  End of debug tool











    }  //  Namespace SelfAwareness

}  //  Namespace Universe


#endif  // META_HPP