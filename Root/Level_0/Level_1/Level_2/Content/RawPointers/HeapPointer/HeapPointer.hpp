#ifndef HEAPPOINTER_HPP
#define HEAPPOINTER_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../Content/Metaprogramming/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../Content/Random/Generator/Generator.hpp"  //  Class Generator


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../TestBranch/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
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
	//			1. Type - any type
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
	class HeapPointer NotForInheritance
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
		inline HeapPointer();


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
		//			size - the size in the template type terms of elements to allocated on the heap memory segment
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
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		explicit inline HeapPointer( UnsignedInteger64bits size );


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
		//				1. size - the size in the template type terms of elements to allocated on the heap memory segment
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
		explicit inline HeapPointer( const Tuple< UnsignedInteger64bits >& arguments );


		// Method Information :
	    //
	    //  Description :
		//
		//		Constructor, use this version to initialize the instance with random generated data
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
		//			2. rangeForSize- this will be used to limit the possible values of the size in the random instance
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
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		explicit inline HeapPointer( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize );


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
		ObjectInfrastructure_ForInheritance_WithoutAssignmentOperator_MACRO( HeapPointer< Type > )


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
		inline void Swap( HeapPointer< Type >& other );


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
		//			size - the size in the template type terms of elements to allocated on the heap memory segment
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
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		inline void Initiate( UnsignedInteger64bits size );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
		//		This version is to accept all the required arguments for the constructor in a tuple instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
		//
		//				1. size - the size in the template type terms of elements to allocated on the heap memory segment
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
		inline void Initiate( const Tuple< UnsignedInteger64bits >& arguments );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance. This
		//		version is to initate an instance with random generated values
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
		//			2. rangeForSize- this will be used to limit the possible values of the size in the random instance
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
		inline void Initiate( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize );


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
		inline ~HeapPointer();


		// The following methods give access and manipulate the data inside this object :


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the size of instance
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
		//		The size of the instance
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		UnsignedInteger64bits Size() const;
		

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
		inline Boolean operator==( const HeapPointer< Type >& other ) const;


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
		inline Boolean operator!=( const HeapPointer< Type >& other ) const;


  	  	// Method Information :
	    //
	    //  Description :
	    //
	    //      Use this operator to get the pointer inside this instance
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
	    //      The pointer inside this instance
	    //
	    //  Expectations :
	    //
	    //      1. The instance should be ready
	    //      2. 
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    inline operator Type*() const;


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Override operator "->" so the use would be the same as with regular pointer, pointer->member = ( *pointer ).member
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
	    //      The resource inside the pointer object
	    //
	    //  Expectations :
	    //
	    //      1. The instance should be ready
	    //      2. 
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    inline Type* operator->();


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Override operator "[]" so the use would be the same as with regular pointer, pointer[n] = *( pointer + n ) = object number n
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          index - the index of the required entry
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      A reference to the required entry
	    //
	    //  Expectations :
	    //
	    //      1. The instance should be ready
	    //      2. The index should be in the range of this instance
	    //      3. 
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    inline Type& operator[]( UnsignedInteger64bits index );


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Override operator "[]" so the use would be the same as with regular pointer, pointer[n] = *( pointer + n ) = object number n
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          index - the index of the required entry
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      A reference to the required entry
	    //
	    //  Expectations :
	    //
	    //      1. The instance should be ready
	    //      2. The index should be in the range of this instance
	    //      3. 
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    inline const Type& operator[]( UnsignedInteger64bits index ) const;


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Override operator "+" so the use would be the same as with regular pointer, pointer + n = the address of object n
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          offset - the offset of the required entry in the resource
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The address of the required entry in the resource
	    //
	    //  Expectations :
	    //
	    //      1. The instance should not be in default state
	    //      2. 
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    inline Type* operator+( UnsignedInteger64bits offset ) const;


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Override operator "-" so the use would be the same as with regular pointer, pointer - n = the address of object n behind
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          offset - the offset of the required entry in the resource
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      The address of the required entry in the resource
	    //
	    //  Expectations :
	    //
	    //      1. The instance should not be in default state
	    //      2. 
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    inline Type* operator-( UnsignedInteger64bits offset ) const;


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Override operator ">" so the use would be the same as with regular pointer, pointer > otherPointer
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          other - a reference to other instance
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      1. true - if the pointer inside this instance has higher address then the pointer in the other instance
	    //      2. false - otherwise
	    //
	    //  Expectations :
	    //
	    //      1. The instance should not be in default state
	    //      2. 
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    inline Boolean operator>( HeapPointer< Type >& other ) const;


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Override operator "<" so the use would be the same as with regular pointer, pointer < otherPointer
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          other - a reference to other instance
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      1. true - if the pointer inside this instance has lower address then the pointer in the other instance
	    //      2. false - otherwise
	    //
	    //  Expectations :
	    //
	    //      1. The instance should not be in default state
	    //      2. 
	    //
	    //  Possible errors :
	    //
	    //      They will come 
	    //
	    inline Boolean operator<( HeapPointer< Type >& other ) const;


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Override operator ">=" so the use would be the same as with regular pointer, pointer >= otherPointer
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          other - a reference to other instance
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      1. true - if the pointer inside this instance has higher or equal address to the pointer in the other instance
	    //      2. false - otherwise
	    //
	    //  Expectations :
	    //
	    //      1. The instance should not be in default state
	    //      2. 
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    inline Boolean operator>=( HeapPointer< Type >& other ) const;


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Override operator "<=" so the use would be the same as with regular pointer, pointer <= otherPointer
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          other - a reference to other instance
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      1. true - if the pointer inside this instance has lower or equal address to the pointer in the other instance
	    //      2. false - otherwise
	    //
	    //  Expectations :
	    //
	    //      1. The instance should not be in default state
	    //      2. 
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    inline Boolean operator<=( HeapPointer< Type >& other ) const;


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
		//			rangeForSize - this will be used to limit the possible values of the size in the random instance
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
		static inline HeapPointer< Type > GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ) );


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


		// Disable all the abilites of the object to copy itself, this include the copy constructor and assignment operator
		DisableCopyConstructorAndAssignmentOperator_MACRO( HeapPointer )


		// This object will store the memory address of the allocated space in the heap memory segment
		Type* member_heapMemoryAddress;

		// This object will store the size in the template type terms of the memory space allocated on the heap memory segment
		UnsignedInteger64bits member_size;


		// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
		// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
		// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
		// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
		// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
		// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Create the operator "*" so the use would be the same as with regular pointer, *pointer = object
	    //
	    //  Required arguments :
	    //
	    //      User information needed :
	    //
	    //          pointer - a reference to a pointer instance
	    //
	    //      Information returned to the user :
	    //
	    //          NONE
	    //
	    //  Return value :
	    //
	    //      A reference to the resource pointed by the pointer
	    //
	    //  Expectations :
	    //
	    //      1. The pointer instance should be ready
	    //      2. 
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    template< typename TYPE >
	    friend inline TYPE& operator*( HeapPointer< TYPE >& heapPointer );


	};  //  Class HeapPointer




































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
	inline HeapPointer< Type >::HeapPointer() :
	member_state(),
	member_heapMemoryAddress( 0UL ),
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
	//			size - the size in the template type terms of elements to allocated on the heap memory segment
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
	//		1. The given size is larger then 0
	//		2. 
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename Type >
	inline HeapPointer< Type >::HeapPointer( UnsignedInteger64bits size ) :
	member_state( InstanceState::Ready ),
	member_heapMemoryAddress( 0UL ),
	member_size( size )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertSizeIsLargerThenZero_MACRO( size )

		// Allocate the memory space on the heap
		member_heapMemoryAddress = new Type[ size ];
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
	//				1. size - the size in the template type terms of elements to allocated on the heap memory segment
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
	inline HeapPointer< Type >::HeapPointer( const Tuple< UnsignedInteger64bits >& arguments ) :
	HeapPointer( arguments.template Entry< 0 >() )
	{}


	// Method Information :
    //
    //  Description :
	//
	//		Constructor, use this version to initialize the instance with random generated data
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
	//			2. rangeForSize- this will be used to limit the possible values of the size in the random instance
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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename Type >
	inline HeapPointer< Type >::HeapPointer( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize ) :
	member_state( InstanceState::Ready ),
	member_heapMemoryAddress( 0UL ),
	member_size( Random::Generator::Get< UnsignedInteger64bits >( rangeForSize ) )
	{
		// Allocate the required memory space
		member_heapMemoryAddress = new Type[ member_size ];
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
	inline void HeapPointer< Type >::Swap( HeapPointer< Type >& other )
	{
	    // Swap betwen the state instances
	    member_state.Swap( other.member_state );

	    // Swap between the memory addresses
	    Memory::Operations::Swap< Type* >( member_heapMemoryAddress, other.member_heapMemoryAddress );

	    // Swap between the sizes
	    Memory::Operations::Swap< UnsignedInteger64bits >( member_size, other.member_size );
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
	//			size - the size in the template type terms of elements to allocated on the heap memory segment
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
	inline void HeapPointer< Type >::Initiate( UnsignedInteger64bits size )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    HeapPointer< Type > temporary( size );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
	//		This version is to accept all the required arguments for the constructor in a tuple instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
	//
	//				1. size - the size in the template type terms of elements to allocated on the heap memory segment
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
	inline void HeapPointer< Type >::Initiate( const Tuple< UnsignedInteger64bits >& arguments )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    HeapPointer< Type > temporary( arguments );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance. This
	//		version is to initate an instance with random generated values
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. The first argument purpose is to ensure this constructor will be called by setting a special type
	//			2. rangeForSize- this will be used to limit the possible values of the size in the random instance
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
	inline void HeapPointer< Type >::Initiate( RandomInstance, NumericRange< UnsignedInteger64bits > rangeForSize )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    HeapPointer< Type > temporary( GenerateRandomInstance, rangeForSize );

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
	inline HeapPointer< Type >::~HeapPointer()
	{
	    // Check if the object is in default state, then noting needs to be done
	    ReturnIfExpressionIsTrue_MACRO( member_state.Get() == InstanceState::Default )

	    // Delete the memory space allocated for the instance
	    delete[] member_heapMemoryAddress;
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the size of instance
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
	//		The size of the instance
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
	UnsignedInteger64bits HeapPointer< Type >::Size() const
	{			
		// Return the size of the instance
		return ( member_size );
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
	inline Boolean HeapPointer< Type >::operator==( const HeapPointer< Type >& other ) const
	{
		// Check if both or only one of the instances is in default state
		CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO

		// Compare the pointers, and return the result
		return ( member_heapMemoryAddress == other.member_heapMemoryAddress );
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
	inline Boolean HeapPointer< Type >::operator!=( const HeapPointer< Type >& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}


    // Method Information :
    //
    //  Description :
    //
    //      Use this operator to get the pointer inside this instance
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
    //      The pointer inside this instance
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline HeapPointer< Type >::operator Type*() const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO

        // Return the pointer
        return ( member_heapMemoryAddress );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "->" so the use would be the same as with regular pointer, pointer->member = ( *pointer ).member
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
    //      The resource inside the pointer object
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Type* HeapPointer< Type >::operator->()
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO            

        // Return the pointer to the resource
        return ( member_heapMemoryAddress );
    }



    // Method Information :
    //
    //  Description :
    //
    //      Override operator "[]" so the use would be the same as with regular pointer, pointer[n] = *( pointer + n ) = object number n
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          index - the index of the required entry
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A reference to the required entry
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. The index should be in the range of this instance
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Type& HeapPointer< Type >::operator[]( UnsignedInteger64bits index )
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO            
        Assert_MACRO( ( index < member_size ), "The given index is not in the range" )

        // Return a reference to the required entry
        return ( member_heapMemoryAddress[ index ] );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "[]" so the use would be the same as with regular pointer, pointer[n] = *( pointer + n ) = object number n
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          index - the index of the required entry
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A reference to the required entry
    //
    //  Expectations :
    //
    //      1. The instance should be ready
    //      2. The index should be in the range of this instance
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline const Type& HeapPointer< Type >::operator[]( UnsignedInteger64bits index ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO            
        Assert_MACRO( ( index < member_size ), "The give index is not in the range" )
        
        // Return a constant reference to the required entry
        return ( member_heapMemoryAddress[ index ] );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "+" so the use would be the same as with regular pointer, pointer + n = the address of object n
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          offset - the offset of the required entry in the resource
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The address of the required entry in the resource
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Type* HeapPointer< Type >::operator+( UnsignedInteger64bits offset ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO

        // Return the required object in the resource
        return ( member_heapMemoryAddress + offset );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "-" so the use would be the same as with regular pointer, pointer - n = the address of object n behind
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          offset - the offset of the required entry in the resource
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The address of the required entry in the resource
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Type* HeapPointer< Type >::operator-( UnsignedInteger64bits offset ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO            

        // Return the required object in the resource
        return ( member_heapMemoryAddress - offset );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator ">" so the use would be the same as with regular pointer, pointer > otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has higher address then the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Boolean HeapPointer< Type >::operator>( HeapPointer< Type >& other ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO            

        // Return the required object in the resource
        return ( member_heapMemoryAddress > other.member_heapMemoryAddress );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "<" so the use would be the same as with regular pointer, pointer < otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has lower address then the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come 
    //
    template< typename Type >
    inline Boolean HeapPointer< Type >::operator<( HeapPointer< Type >& other ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO            

        // Return the required object in the resource
        return ( member_heapMemoryAddress < other.member_heapMemoryAddress );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator ">=" so the use would be the same as with regular pointer, pointer >= otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has higher or equal address to the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Boolean HeapPointer< Type >::operator>=( HeapPointer< Type >& other ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO            

        // Return the required object in the resource
        return ( member_heapMemoryAddress >= other.member_heapMemoryAddress );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "<=" so the use would be the same as with regular pointer, pointer <= otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has lower or equal address to the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Boolean HeapPointer< Type >::operator<=( HeapPointer< Type >& other ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady_MACRO           

        // Return the required object in the resource
        return ( member_heapMemoryAddress <= other.member_heapMemoryAddress );
    }
































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************

































    // Method Information :
    //
    //  Description :
    //
    //      Create the operator "*" so the use would be the same as with regular pointer, *pointer = object
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          pointer - a reference to a pointer instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A reference to the resource pointed by the pointer
    //
    //  Expectations :
    //
    //      1. The pointer instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename TYPE >
    inline TYPE& operator*( HeapPointer< TYPE >& heapPointer )
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
    	AssertInstanceIsReady_MACRO( heapPointer )
        
        // Return the object pointed
        return ( *heapPointer.member_heapMemoryAddress );
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
		//		1. An assertion failed - class Exception is thrown
		//		2. There is no more free memory space - class std::bad_alloc is thrown
		//		3. 
		//
		template< typename Type >
		void HeapPointer< Type >::Test()
		{
			// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
			// destructor, swap and more, seem to work correctly
			Testing::SanityCheck::Full< HeapPointer< Type > COMMA UnsignedInteger64bits >();
		}

	)  //  End of debug tool












}  //  Namespace Universe



#endif  // HEAPPOINTER_HPP