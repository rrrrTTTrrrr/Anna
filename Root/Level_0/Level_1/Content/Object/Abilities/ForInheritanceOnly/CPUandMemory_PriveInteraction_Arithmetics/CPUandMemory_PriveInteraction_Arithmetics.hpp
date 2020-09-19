#ifndef  CPUANDMEMORY_PRIVEINTERACTION_ARITHMETICS_HPP
#define  CPUANDMEMORY_PRIVEINTERACTION_ARITHMETICS_HPP


#include "../Definitions/VariableTypesDefinitions.hpp"  //  Typedef
#include "../BasicUtilities/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../Memory/MemoryOperations/Swap/Swap.hpp"  //  Class Swap
#include "../Abilities/State/State.hpp"  //  Class State


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
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
    	//		Artifical Inteligence
    	//
   	    //  Description :
   	    //
    	//      1. This object is used as a base object in inheritance. Therefore it must have a few methods virtual. When an object has a virtual method, the C++ automatically
    	//		   creates a table with all the pointers to the virtual methods, where the pointer to the table is stored in the beginning of the object. The problem arises
    	//		   when a new method needs to be created with the same signature as one in the base object, and the use of pointers. Take a look at next example :
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
    	//		   the method of the type he was declared as. This is a problematic behavior in inheritance, we need to point to derived objects with base pointers and that
    	//		   the correct method will be called. But now :
    	//
    	//             void Do( Base* base ) { base->Display(); }
    	//
    	//             Base* base = new Base;
    	//             Derived* derived = new Derived;
    	//
    	//             Do( base );        -> Outputs "Lord"
    	//             Do( derived );     -> Outputs "Lord"
    	//
    	//         This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is picked dynamically by the actual
    	//		   type of the object. This is done by the pointer in the beginning of the object that points to the virtual table of the type. Of course it can be overloaded
    	//		   to the derived, but then if there is a deep inheritance a method will be needed to be overloaded for each one
    	//
    	//		2. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
    	//
    	// 		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
    	//
    	//				1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
    	//							presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
    	//							lost, so it should be avoided in most cases
    	//
    	//				2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
    	//							   all the data and methods inside this part. This part will usually containt some methods and few data members
    	//
    	//				3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
    	//							 methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
    	//							 suffix __Private
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		Too many to count
    	//
    	template< typename DerivedObjectType, typename PrimitiveType >
        class CPUandMemory_PriveInteraction_Arithmetics : public CentralProcessingUnit::Intel_CPUandMemory_PrivateConversation< PrimitiveType >
        {
        public:


            // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
            // generates a basic behavior for them :


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
    		inline CPUandMemory_PriveInteraction_Arithmetics();


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
    		explicit inline CPUandMemory_PriveInteraction_Arithmetics();


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
    		inline CPUandMemory_PriveInteraction_Arithmetics( const CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& other );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Assignment operator, can handle with self assignment and instances in default state
    		//
    		//  Required arguments :
    		//
    		//		User information needed :
    		//
    		//			other - a reference to the instance that should be copied
    		//
    		//		Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to this object
    		//
    		//  Expectations :
    		//
    		//		NONE
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& operator=( const CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& other );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
    		//
    		//  Required arguments :
    		//
    		//   	User information needed :
    		//
    		//          other - a reference to the instance that should be moved
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
    		inline CPUandMemory_PriveInteraction_Arithmetics( CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >&& other );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
    		//
    		//  Required arguments :
    		//
    		//   	User information needed :
    		//
    		//          other - a reference to the instance that should be moved
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to this object
    		//
    		//  Expectations :
    		//
    		//		NONE
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& operator=( CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >&& other );


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
    		inline void Swap( CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& other );


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
    		inline void Reset();


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
    		//      Use this method to get a handle that can be used to obtain information on the state of the instance
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
    		inline const Abilities::State& State() const;
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
    		virtual inline ~CPUandMemory_PriveInteraction_Arithmetics();


    		// The following methods are the interface of the object :











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
    		inline Boolean operator==( const CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& other ) const;


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
    		inline Boolean operator!=( const CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& other ) const;


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
    			static void Test();

    		)  //  End of debug tool


    	protected:


    		// The protected part is used for inheritance. This means that only this object and the objects that will inherit from it can use the protected data
    		// members or methods


    	private:


        	// This object will be used to monitor the state of each instance
        	Abilities::State member_state;


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


    	};  //  Class CPUandMemory_PriveInteraction_Arithmetics










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
    	template< typename DerivedObjectType, typename PrimitiveType >
        inline CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::CPUandMemory_PriveInteraction_Arithmetics() :
        Intel_CPUandMemory_PrivateConversation< PrimitiveType >()
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
        //          memoryAddress - the memory address on which the operations nedds to act
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
    	template< typename DerivedObjectType, typename PrimitiveType >
        inline CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::CPUandMemory_PriveInteraction_Arithmetics( PrimitiveType* memoryAddress ) :
        Intel_CPUandMemory_PrivateConversation< PrimitiveType >( memoryAddress )
    	{
    		// This will be added only in test mode, to ensure that the given data to the method is valid
    		ASSERT( ( memoryAddress != 0 ), "Abilities::CPUandMemory_PriveInteraction_Arithmetics::Constructor failed - the given pointer is NULL" )
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
    	template< typename DerivedObjectType, typename PrimitiveType >
        inline CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::CPUandMemory_PriveInteraction_Arithmetics( const CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& other ) :
        Intel_CPUandMemory_PrivateConversation< PrimitiveType >( other )
    	{}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Assignment operator, can handle with self assignment and instances in default state
    	//
    	//  Required arguments :
    	//
    	//		User information needed :
    	//
    	//			other - a reference to the instance that should be copied
    	//
    	//		Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	A reference to this object
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename DerivedObjectType, typename PrimitiveType >
        inline CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::operator=( const CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& other )
    	{
    		// Create a copy of the other instance
    		CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType > temporary( other );

    		// Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
    		Swap( temporary );

    		// Return a reference to this object
    		return ( *this );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the instance that should be moved
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
    	template< typename DerivedObjectType, typename PrimitiveType >
        inline CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::CPUandMemory_PriveInteraction_Arithmetics( CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >&& other ) :
    	CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >()
    	{
    		// Swap between this instance, which is in default state, and the other one
    		Swap( other );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the instance that should be moved
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	A reference to this object
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename DerivedObjectType, typename PrimitiveType >
        inline CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::operator=( CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >&& other )
    	{
    	    // Create a default constructed instance
    	    CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType > defaultConstructedInstance;

    	    // Swap between the temporary instance, which is in default state, and the other instance
    	    defaultConstructedInstance.Swap( other );

    	    // Swap between this instance and the temporary one
    	    Swap( defaultConstructedInstance );

    	    // Return a reference to this object
    	    return ( *this );
    	}


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
    	template< typename DerivedObjectType, typename PrimitiveType >
    	inline void CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::Swap( CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& other )
    	{
            // Use the base object swap method 
            CentralProcessingUnit::Intel_CPUandMemory_PrivateConversation< PrimitiveType >::Swap( other );
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
    	template< typename DerivedObjectType, typename PrimitiveType >
    	inline void CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::Reset()
    	{
    	    // Create a default constructed instance, it will be used to swap with this instance, leaving this instance in default state, and delete the old data
    	    CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType > defaultConstructedInstance;

    	    // Swap between this instance and the default constructed instance
    	    Swap( defaultConstructedInstance );
    }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this method to take an instance and prepare it for work. The method will have the same effect on instances already initialized. Each
    	//		constructor except for the default constructor, should have a corresponding "Initiate" method
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//			memoryAddress - the memory address on which the operations nedds to act
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
    	template< typename DerivedObjectType, typename PrimitiveType >
    	inline void CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::Initiate( PrimitiveType* memoryAddress )
    	{
    	    // This will be added only in test mode, to ensure that the given data to the method is valid
    	    ASSERT( ( memoryAddress != 0  ), "Abilities::CPUandMemory_PriveInteraction_Arithmetics::Initiate failed - the given pointer is NULL" )

    	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
    	    // leave this scope it will delete the old data
    	    CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType > temporary;

    	    // Swap between this instance and the temporary instance
    	    Swap( temporary );
        }






























//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************

































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
        template< typename DerivedObjectType, typename PrimitiveType >
        inline DerivedObjectType& CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::operator+=( const PrimitiveType& rightSideOperand )
        {
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeInstanceChanges_Private();

            // Read the current value in the memory address, add to it the right side operand and store it back to the memory address
            Intel_CPUandMemory_PrivateConversation< PrimitiveType >::Read_Add_Write( rightSideOperand );

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
        template< typename DerivedObjectType, typename PrimitiveType >
        inline DerivedObjectType& CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::operator+=( const DerivedObjectType& rightSideOperand )
        {
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeInstanceChanges_Private();

            // Set the sum of the data inside this object with the data inside right side operand object
            GetData_Private() += rightSideOperand.GetData_Private();

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
        template< typename DerivedObjectType, typename PrimitiveType >
        inline DerivedObjectType& CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::operator-=( const PrimitiveType& rightSideOperand )
        {
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeInstanceChanges_Private();

            // Set the difference between the data inside this object and the right side operand
            GetData_Private() -= rightSideOperand;

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
        template< typename DerivedObjectType, typename PrimitiveType >
        inline DerivedObjectType& CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::operator-=( const DerivedObjectType& rightSideOperand )
        {
            // The object is about to change, execute the required task if supplied by user
            ExecuteTaskBeforeInstanceChanges_Private();

            // Set the difference between the data inside this object and the data inside the right side operand object
            GetData_Private() -= rightSideOperand.GetData_Private();

            // Every time a reference to this object is returned the pointer needs to be casted to the template type
            // because otherwise the this pointer has a static type of this object
            return ( *( reinterpret_cast< DerivedObjectType* >( this ) ) );
        }


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
    	template< typename DerivedObjectType, typename PrimitiveType >
        inline Boolean CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::operator==( const CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& other ) const
    	{
            // Return the result from calling the base object equal operator
            return (  )
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
    	template< typename DerivedObjectType, typename PrimitiveType >
        inline Boolean CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::operator!=( const CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >& other ) const
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
    		//      1. A method does not work correctly - class Exception is thrown
    		//		2. There is no more free memory space - class std::bad_alloc is thrown
    		//		3. 
    		//
    		template< typename DerivedObjectType, typename PrimitiveType >
    		void CPUandMemory_PriveInteraction_Arithmetics< DerivedObjectType, PrimitiveType >::Test()
    		{}

    	)  //  End of debug tool











    }  //  Namespace Abilities

}  //  Namespace Universe


#endif  // CPUANDMEMORY_PRIVEINTERACTION_ARITHMETICS_HPP