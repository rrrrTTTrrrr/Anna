#ifndef STACK_HPP
#define STACK_HPP


#include "../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../Content/Object/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../../../Content/Object/ObjectInfrastructure/GetAndSetForMembers/GetAndSetForMembers.hpp"  //  Macro Get_MACRO, Macro Set_MACRO
#include "../../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../Stack_Interface/Stack_Interface.hpp"  //  Class Stack_Interface
#include "../../../../../../Content/Memory/MemoryHandlers/Array/StackArray/StackArray.hpp"  //  Class Array
#include "../../../../../../../Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../../../../../../../Content/NumericRange/NumericRange.hpp"  //  Class NumericRange


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../../../Test/GeneralTests/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
#endif


namespace Universe
{

    namespace Memory
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



		// Why is the size of an empty class not zero?
		//
		// To ensure that the addresses of two different insances will be different. For the same reason, "new" always returns pointers to distinct instances.
		// Consider :
		//
		//		class Empty
		//		{}
		//
		//		void DoSomething()
		//		{
    	//			Empty a;
    	//			Empty b;
    	//
    	//			if ( &a == &b )
    	//			{
    	//				std::cout << "Impossible - report error to compiler supplier" << std::endl;
    	//			}
    	//		
    	//		}
    	//
    	// There is an interesting rule that says that an empty base class need not be represented by a separate byte :
    	//
    	//		class Derived : public Empty
    	//		{
    	//			int a;
    	//			...
    	//		}
    	//
    	//		void DoOtherThing( Derived* pointer )
    	//		{
    	//			void* p1 = pointer;
    	//			void* p2 = &p->a;
    	//
    	//			if ( p1 == p2 )
    	//			{
    	//				std::cout << "Nice - good optimizer" << std::endl;
    	//			}
    	//
    	//		}
    	//
    	// This optimization is safe and can be most useful. It allows a programmer to use empty classes to represent very simple concepts without overhead.
    	// Some current compilers provide this "empty base class optimization"



		// Template Class Information :
		//
		//  Purpose :
		//
		//		This object implements the concept of 'First In Last Out'. This means that this container has two operations, one to push into the
		//		stack and another to pop off the stack. Each pop takes off only the last element entered to the stack
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
		//		3. Template arguments :
		//
		//			1. AnyType - any type
		//
		//		4. The rational behind 
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		class Stack : public Stack_Interface< AnyType >
		{
		public:


			// Create a type definition for this object
			using SelfType = Stack< AnyType, StackCapacity >;


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
			inline Stack();


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
			//			data - a reference to the first data to push to the stack
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
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			explicit inline Stack( const AnyType& data );


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
			//				data - a reference to the first data to push to the stack
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
			explicit inline Stack( Tuple< const AnyType& > arguments );


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
			//			2. argumentsNeededToGenerateRandomInstanceOfType - any arguments needed to create a random instance of the data type
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
	        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfType >
			explicit inline Stack( RandomInstance, ArgumentsTypesNeededToGenerateRandomInstanceOfType... argumentsNeededToGenerateRandomInstanceOfType );


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
			//			other - a reference to the instance that should be copied
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
			inline Stack( const SelfType& other );


			// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
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
			ObjectInfrastructure_ForInheritance_MACRO( ConsiderAsOneArgument( Stack< AnyType, StackCapacity > ) )


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
			//			other - a reference to the instance that should be swaped
			//
			//      Information returned to the user :
			//
			//			NONE
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
			//		User information needed :
			//
			//			data - a reference to the first data to push to the stack
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
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void Initiate( const AnyType& data );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
			//		This version is to allow initiating an instance with the same arguments as the parameterized constructor, just that the arguments
			//		will be	wrapped in a tuple, to allow more automatic initialization of instances
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			arguments - the arguments needed to initiate an instance, only wrapped in a tuple. The arguments are :
			//
			//				data - a reference to the first data to push to the stack
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
			inline void Initiate( const Tuple< AnyType >& arguments );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
			//		This version is to allow initiating random instance
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
			//			2. argumentsNeededToGenerateRandomInstanceOfType - any arguments needed to create a random instance of the data type
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
	        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfType >
	        inline void Initiate( RandomInstance, ArgumentsTypesNeededToGenerateRandomInstanceOfType... argumentsNeededToGenerateRandomInstanceOfType );


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
			//      Information returned to the user :
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
			virtual ~Stack() = default;


			// This part will contain all the get and set methods for the members of the object :


			// Member - member_size
			GetByValue_DeclaredVirtualAndOverride_MACRO( Size, member_size, UnsignedInteger64bits )

			// Template integer - StackCapacity
			GetByValue_DeclaredVirtualAndOverride_MACRO( Capacity, StackCapacity, UnsignedInteger64bits )


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to push data into the dynamic stack
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			data - a constant reference to the data to push to the top of the dynamic stack
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
			//		1. The capacity still can contain more entries of the stack
			//		2.
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc will be thrown
			//		2. 
			//
			virtual void PushIn( const AnyType& data ) override;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to pop out the data that was last entered to the dynamic stack, and get a copy of it
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
			//		A copy of the data last entered to the dynamic stack
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. The instance size should be at least 1
			//		3. 
			//
			//  Possible errors :
			//
			//		NONE
			//
			virtual AnyType PopOut() override;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a reference to the data last entered to the dynamic stack. This means that using this method a reference will be
			//		returned to the data that will be removed if the pop out method will be used
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
			//		A reference to the data last entered to the dynamic stack
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. The instance size should be at least 1
			//		3. 
			//
			//  Possible errors :
			//
			//		NONE
			//
			virtual AnyType& PeakTop() override;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a constant reference to the data last entered to the dynamic stack. This means that using this method a reference will be
			//		returned to the data that will be removed if the pop out method will be used
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
			//		A constant reference to the data last entered to the dynamic stack
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. The instance size should be at least 1
			//		3. 
			//
			//  Possible errors :
			//
			//		NONE
			//
			virtual const AnyType& PeakTop() const override;


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
			inline Boolean operator==( const SelfType& other ) const;


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
			//			other - a reference to the instance that should be compared with this object
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


 			// This object will be used to store the stack
 			StackArray< AnyType, StackCapacity > member_stack;

 			// This object will store the current size used from the total capcaity, which is the size of the stack array
 			UnsignedInteger64bits member_size;


			// Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
			// the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
			// thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
			// and the error message will be displayed. This method should not be used, because it does nothing during run time
			CompileTimeAssert( ( StackCapacity > 0UL ), "Memory::Stack failed - the given capacity should be larger then 0" );


		};  //  Class Stack




































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
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		inline Stack< AnyType, StackCapacity >::Stack() :
		Stack_Interface< AnyType >(),
		member_state(),
		member_stack(),
		member_size( 0UL )
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
		//			data - a reference to the first data to push to the stack
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
		//		NONE
		//
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		inline Stack< AnyType, StackCapacity >::Stack( const AnyType& data ) :
		Stack_Interface< AnyType >(),
		member_state( InstanceState::Ready ),
		member_stack(),
		member_size( 1UL )
		{
			// Set the first entry with the data
			member_stack[0] = data;
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
		//				data - a reference to the first data to push to the stack
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
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		inline Stack< AnyType, StackCapacity >::Stack( Tuple< const AnyType& > arguments ) :
		SelfType( arguments.template Entry< 0 >() )
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
		//			2. argumentsNeededToGenerateRandomInstanceOfType - any arguments needed to create a random instance of the data type
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
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfType >
		inline Stack< AnyType, StackCapacity >::Stack( RandomInstance, ArgumentsTypesNeededToGenerateRandomInstanceOfType... argumentsNeededToGenerateRandomInstanceOfType ) :
		Stack_Interface< AnyType >(),
		member_state( InstanceState::Ready ),
		member_stack( GenerateRandomInstance, argumentsNeededToGenerateRandomInstanceOfType... ),
		member_size( member_stack.Size() )
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
		//			other - a reference to the instance that should be copied
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
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		inline Stack< AnyType, StackCapacity >::Stack( const SelfType& other ) :
		Stack_Interface< AnyType >(),
		member_state( other.member_state ),
		member_stack( other.member_stack ),
		member_size( other.member_size )
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
		//			other - a reference to the instance that should be swaped
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
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		inline void Stack< AnyType, StackCapacity >::Swap( SelfType& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );
		    
		    // Swap between the instances that store the stack
		    member_stack.Swap( other.member_stack );

		    // Swap between the instances that store the size
		    Operations::Swap< UnsignedInteger64bits >( member_size, other.member_size );
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
		//			data - a reference to the first data to push to the stack
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
		//		NONE
		//
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		inline void Stack< AnyType, StackCapacity >::Initiate( const AnyType& data )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( data );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
    	}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
		//		This version is to allow initiating an instance with the same arguments as the parameterized constructor, just that the arguments
		//		will be	wrapped in a tuple, to allow more automatic initialization of instances
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments needed to initiate an instance, only wrapped in a tuple. The arguments are :
		//
		//				data - a reference to the first data to push to the stack
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
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		inline void Stack< AnyType, StackCapacity >::Initiate( const Tuple< AnyType >& arguments )
		{
		    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
		    // leave this scope it delete the old data if exist
		    SelfType instanceCreatedUsingTheRequiredConstructor( arguments );

		    // Swap between this instance and the temporary instance
		    Swap( instanceCreatedUsingTheRequiredConstructor );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
		//		This version is to allow initiating random instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
		//			2. argumentsNeededToGenerateRandomInstanceOfType - any arguments needed to create a random instance of the data type
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
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfType >
        inline void Stack< AnyType, StackCapacity >::Initiate( RandomInstance, ArgumentsTypesNeededToGenerateRandomInstanceOfType... argumentsNeededToGenerateRandomInstanceOfType )
		{
		    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
		    // leave this scope it delete the old data if exist
		    SelfType randomGeneratedInstance( GenerateRandomInstance, argumentsNeededToGenerateRandomInstanceOfType... );

		    // Swap between this instance and the temporary instance
		    Swap( randomGeneratedInstance );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to push data into the stack
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			data - a constant reference to the data to push to the top of the stack
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
		//		NONE
		//
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		void Stack< AnyType, StackCapacity >::PushIn( const AnyType& data )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert_MACRO( ( member_size < StackCapacity ), "The stack can not contain any more entries" );

			// Push the data to the top of the stack
			member_stack[ member_size ] = data;

			// Increase the size of the stack by 1
			member_size += 1UL;
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to pop out the data that was last entered to the stack, and get a copy of it
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
		//		A copy of the data last entered to the stack
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. The instance size should be at least 1
		//		3. 
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		AnyType Stack< AnyType, StackCapacity >::PopOut()
		{
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThisInstanceSizeIsLargerThenZero_MACRO;

            // Decrement the size of the stack by one
            member_size -= 1UL;

			// Remove the data last entered to the stack, and return a copy of it
			return ( MOVE( member_stack[ member_size ] ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get a reference to the data last entered to the stack. This means that using this method a reference will be
		//		returned to the data that will be removed if the pop out method will be used
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
		//		A reference to the data last entered to the stack
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. The instance size should be at least 1
		//		3. 
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		AnyType& Stack< AnyType, StackCapacity >::PeakTop()
		{
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThisInstanceSizeIsLargerThenZero_MACRO;

			// Return a reference to the data at the top of the stack
			return ( member_stack[ member_size - 1UL ] );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get a constant reference to the data last entered to the stack. This means that using this method a reference will be
		//		returned to the data that will be removed if the pop out method will be used
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
		//		A constant reference to the data last entered to the stack
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. The instance size should be at least 1
		//		3. 
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		const AnyType& Stack< AnyType, StackCapacity >::PeakTop() const
		{
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThisInstanceSizeIsLargerThenZero_MACRO;

			// Return a constant reference to the data at the top of the stack
			return ( member_stack[ member_size - 1UL ] );
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
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		inline Boolean Stack< AnyType, StackCapacity >::operator==( const SelfType& other ) const
		{
			// Check if both or only one of the instances is in default state
			CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO
			
			// Compare the stacks of both instances, and return the result
			return ( ( member_size == other.member_size ) && ( member_stack.Compare( other.member_stack, member_size ) == true ) );
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
		template< typename AnyType, UnsignedInteger64bits StackCapacity >
		inline Boolean Stack< AnyType, StackCapacity >::operator!=( const SelfType& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
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
			//			NONE
			//
			//      Information returned to the user :
			//
			//			NONE
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
			//		1. An assertion failed - class Exception or ErrnoException is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			template< typename AnyType COMMA UnsignedInteger64bits StackCapacity >
			void Stack< AnyType COMMA StackCapacity >::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::Full< Stack< AnyType COMMA StackCapacity > COMMA const AnyType& >();
				
				// Create a test instance
				Stack< UnsignedInteger64bits COMMA 567UL > testStack_1;

				// Add elements to the stack
				for ( UnsignedInteger64bits index = 0UL ; index < 512UL ; ++index )
				{
					// Add an element to the top of the stack
					testStack_1.PushIn( 34UL );
				}

				// Pop all the elements from the stack
				for ( UnsignedInteger64bits index = 0UL ; index < 334UL ; ++index )
				{
					// Add an element to the top of the stack
					Assert_Test_MACRO( testStack_1.PopOut() == 34UL );
				}

				// Add elements to the stack
				for ( UnsignedInteger64bits index = 0UL ; index < 122UL ; ++index )
				{
					// Add an element to the top of the stack
					testStack_1.PushIn( 34UL );
				}

				// Store the current size of the test stack
				UnsignedInteger64bits size = testStack_1.Size();

				// Pop all the elements from the stack
				for ( UnsignedInteger64bits index = 0UL ; index < size ; ++index )
				{
					// Add an element to the top of the stack
					Assert_Test_MACRO( testStack_1.PopOut() == 34UL );
				}

				// Add elements to the stack
				for ( UnsignedInteger64bits index = 0UL ; index < 122UL ; ++index )
				{
					// Add an element to the top of the stack
					testStack_1.PushIn( 34UL );
				}

				// Create a test instance
				Stack< UnsignedInteger64bits COMMA 567UL > testStack_2( GenerateRandomInstance );

				// Check that the instances are different
				Assert_Test_MACRO( testStack_1 != testStack_2 );

				// Use the assignment operator
				testStack_1 = testStack_2;

				// Check that the instances match
				Assert_Test_MACRO( testStack_1 == testStack_2 );
			}

		)  //  End of debug tool











    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // STACK_HPP