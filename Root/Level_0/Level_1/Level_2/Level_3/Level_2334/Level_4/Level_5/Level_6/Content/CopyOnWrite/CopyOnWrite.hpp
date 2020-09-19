#ifndef COPYONWRITE_HPP
#define COPYONWRITE_HPP


#include "../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../Content/CentralProcessingUnit/Intel/x8086x64bits_Architecture/Synchronization/Intel_CPUandMemory_PrivateConversation/Intel_CPUandMemory_PrivateConversation.hpp"  //  Class Intel_CPUandMemory_PrivateConversation
#include "../../../Content/CentralProcessingUnit/Intel/x8086x64bits_Architecture/Synchronization/SpinWaitLoop/SpinWaitLoop.hpp"  //  Class SpinWaitLoop
#include "../../../../../../../../../Content/Metaprogramming/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
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



	// How to define a templated constructor of a template class outside the class declaration?
	//
	// Consider the following object :
	//
	//		template< typename Type >
	//		class X
	//		{
	//
	//			template< typename OtherType >
	//			X( OtherType foo );
	//
	//		};
	//
	// To define the constructor outside of the class declaration the following syntax is needed :
	//
	//		template< typename Type >
	//		template< typename OtherType >
	//		X< Type >::X( OtherType foo )
	//		{
	//			...
	//		}



	// In a template constructor, the template arguments can not be specified explicitly because the constructor has no name on its own, and so no
	// syntax for it. One of the ways is to use the template type as an argument to the constructor, and let the compiler deduce the type automatically!



	// Template Class Information :
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
	//		3. Template arguments :
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
	class CopyOnWrite NotForInheritance
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
		inline CopyOnWrite();


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
		//			constructorArguments - all the arguments required to construct the instance of the template type object
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
		template< typename... TemplateObjectConstrcutorArgumentsTypes >
		inline CopyOnWrite( TemplateObjectConstrcutorArgumentsTypes... constructorArguments );


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
		inline CopyOnWrite( const CopyOnWrite< Type >& other );


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
		ObjectInfrastructure_MACRO( CopyOnWrite< Type > )


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
		inline void Swap( CopyOnWrite< Type >& other );


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
		//			constructorArguments - all the arguments required to construct the instance of the template type object
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
		template< typename... TemplateObjectConstrcutorArgumentsTypes >
		inline void Initiate( TemplateObjectConstrcutorArgumentsTypes... constructorArguments );


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
		inline ~CopyOnWrite();


		// The following methods give access and manipulate the data inside this object :


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get a constant reference to the resource inside this isntance
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
		//		A constant reference to the resource inside this isntance
		//
		//  Expectations :
		//
		//		1. The instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		NONE 
		//
		inline const Type& Read() const;


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
		//			... - all the arguments required to construct the instance of the template type object
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
		//		1. The instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		inline Type& Write() const;


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
		inline Boolean operator==( const CopyOnWrite< Type >& other ) const;


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
		inline Boolean operator!=( const CopyOnWrite< Type >& other ) const;


		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
		// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
		// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


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


		// This pointer will store the memory address allocated on the heap for the template type object instance
		Type* member_pointerToInstance;

		// This pointer will store the memory address of an integer allocated on the heap, to count the number of references using this copy on write instance
		SignedInteger64bits* member_referenceCounter;

		// This object will be used to synchronize between different users of the instance to ensure that ceratin sections only one user enters at a time
		CentralProcessingUnit::SpinWaitLoop member_spinWaitLoop;


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


	};  //  Class CopyOnWrite




































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
	template< typename Type >
	inline CopyOnWrite< Type >::CopyOnWrite() :
	member_state(),
	member_pointerToInstance( 0UL ),
	member_referenceCounter( 0UL )
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
	//			constructorArguments - all the arguments required to construct the instance of the template type object
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
	template< typename Type >
	template< typename... TemplateObjectConstrcutorArgumentsTypes >
	inline CopyOnWrite< Type >::CopyOnWrite( TemplateObjectConstrcutorArgumentsTypes... constructorArguments ) :	
	member_state( InstanceState::Ready ),
	member_pointerToInstance( new Type( constructorArguments... ) ),
	member_referenceCounter( 0UL )
	{

		// Try catch block to ensure deleting the template type object instance allocated already, if the reference counter allocation will fail
		try
		{

			// Allocate the memory space for the reference counter
			member_referenceCounter = new SignedInteger64bits( 1 );

		}
		catch ( const std::bad_alloc& exception )
		{
			// The allocation of the reference counter failed

			// Delete the instance already allocated
			delete member_pointerToInstance;

			// Rethrow the exception to notify the caller that the operation failed
			throw;

		}

	}


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
	template< typename Type >
	inline CopyOnWrite< Type >::CopyOnWrite( const CopyOnWrite< Type >& other ) :
	member_state( other.member_state ),
	member_pointerToInstance( other.member_pointerToInstance ),
	member_referenceCounter( other.member_referenceCounter )
	{

		// Check if the other instance is ready
		if ( other.member_state.Get() == InstanceState::Ready )
		{
			// The other instance is ready

			// Increment the reference counter by 1, without allowing any other thread of execution or central processing unit to interrupt
			CentralProcessingUnit::Intel_CPUandMemory_PrivateConversation::Read_Add_Write< SignedInteger64bits >( member_referenceCounter, 1 );
		}

	}


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
	template< typename Type >
	inline void CopyOnWrite< Type >::Swap( CopyOnWrite< Type >& other )
	{
		// Wait until no other user uses this section of the code, and then lock the area for this thread of execution only
		member_spinWaitLoop.Lock();

		// Only one thread of execution can be at this section of code at a time

	    // Swap betwen the state instances
	    member_state.Swap( other.member_state );

	    // Swap between the pointers to the instances
	    Memory::Operations::Swap< Type* >( member_pointerToInstance, other.member_pointerToInstance );

    	// Swap between the reference counters
	    Memory::Operations::Swap< SignedInteger64bits* >( member_referenceCounter, other.member_referenceCounter );

	    // Unlock this section of code to allow the next thread of execution to use it
	    member_spinWaitLoop.Unlock();
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
	//			constructorArguments - all the arguments required to construct the instance of the template type object
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
	template< typename Type >
	template< typename... TemplateObjectConstrcutorArgumentsTypes >
	inline void CopyOnWrite< Type >::Initiate( TemplateObjectConstrcutorArgumentsTypes... constructorArguments )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    CopyOnWrite< Type > temporary( constructorArguments... );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}


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
	template< typename Type >
	inline CopyOnWrite< Type >::~CopyOnWrite()
	{
	    // Check if the object is in default state, then noting needs to be done
	    ReturnIfExpressionIsTrue_MACRO( member_state.Get() == InstanceState::Default )

	    // Decrement the reference counter by 1, and store the current value in the reference counter
	    SignedInteger64bits oldReferenceCounterValue = CentralProcessingUnit::Intel_CPUandMemory_PrivateConversation::Read_Add_Write_ReturnOldValue< SignedInteger64bits >( member_referenceCounter, -1 );

	    // Check if only this instance uses the resource
	    if ( oldReferenceCounterValue == 1 )
	    {
	    	// Only the instance used the resource

	    	// Delete the template type object instance
	    	delete member_pointerToInstance;

	    	// Delete the reference counter
	    	delete member_referenceCounter;
	    }

	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get a constant reference to the resource inside this isntance
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
	//		A constant reference to the resource inside this isntance
	//
	//  Expectations :
	//
	//		1. The instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		NONE 
	//
	template< typename Type >
	inline const Type& CopyOnWrite< Type >::Read() const
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO

		// Return a constant reference to the template type object instance
		return ( *member_pointerToInstance );
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
	//			... - all the arguments required to construct the instance of the template type object
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
	//		1. The instance is ready
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename Type >
	inline Type& CopyOnWrite< Type >::Write() const
	{
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO

    	// Make a new copy of the resource
    	Type* newCopyOfTheResource = new Type( *member_pointerToInstance );

	    // Decrement the reference counter by 1, and store the current value in the reference counter
	    SignedInteger64bits oldReferenceCounterValue = CentralProcessingUnit::Intel_CPUandMemory_PrivateConversation::Read_Add_Write_ReturnOldValue< SignedInteger64bits >( member_referenceCounter, 1UL );

		// Each method that interacts with the user directly needs to ensure that the given data is valid
		Assert_MACRO( ( oldReferenceCounterValue >= 0 ), "The reference counter value was smaller then 0, which indicates an error" )

	    // Check the old reference counter value
	    if ( oldReferenceCounterValue == 0 )
	    {
	    	// The old reference counter is 0, which means only this instance uses the resource

	    	// Delete the old template type object instance
	    	delete member_pointerToInstance;

	    	// Delete the old reference counter
	    	delete member_referenceCounter;

	    	// Set the new resource
	    	member_pointerToInstance = newCopyOfTheResource;

			// Try catch block to ensure deleting the template type object instance allocated already, if the reference counter allocation will fail
			try
			{

				// Allocate the memory space for the reference counter
				member_referenceCounter = new SignedInteger64bits( 1 );

			}
			catch ( const std::bad_alloc& exception )
			{
				// The allocation of the reference counter failed

				// Delete the instance already allocated
				delete member_pointerToInstance;

				// Rethrow the exception to notify the caller that the operation failed
				throw;

			}

	    }

		// Return a constant reference to the template type object instance
		return ( *member_pointerToInstance );
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
	template< typename Type >
	inline Boolean CopyOnWrite< Type >::operator==( const CopyOnWrite< Type >& other ) const
	{
		// Check if both or only one of the instances is in default state
		CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO

		// Compate between the two template type object instances, and return the result
		return ( *member_pointerToInstance == *other.member_pointerToInstance );
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
	template< typename Type >
	inline Boolean CopyOnWrite< Type >::operator!=( const CopyOnWrite< Type >& other ) const
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
		template< typename Type >
		void CopyOnWrite< Type >::Test()
		{
			// First of all ensure that the object works for one thread of execution!!

			// Create an instance
			CopyOnWrite< UnsignedInteger32bits > testCopyOnWrite_1( 3 );

			// Create an instance using the other instance
			CopyOnWrite< UnsignedInteger32bits > testCopyOnWrite_2( testCopyOnWrite_1 );

			
		}

	)  //  End of debug tool











}  //  Namespace Universe



#endif  // COPYONWRITE_HPP