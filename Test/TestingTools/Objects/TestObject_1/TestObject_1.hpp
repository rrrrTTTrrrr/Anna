#ifndef TESTOBJECT_1_HPP
#define TESTOBJECT_1_HPP


#include <iostream>  //  Class std::cout, Class std::endl

#include "../../../../Root/Level_0/Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../../Root/Level_0/Content/Object/InstanceState/InstanceState.hpp"  //  Class InstanceState
#include "../../../../Root/Level_0/Level_1/Level_2/Level_3/Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../Root/Level_0/Level_1/Level_2/Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../../../Root/Level_0/Level_1/Level_2/Content/NumericRange/NumericRange.hpp"  //  Class NumericRange


namespace Universe
{

    namespace Testing
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
		template< typename AnyType >
		class TestObject_1 final
		{
		public:


			// Create a type definition for this object
			using SelfType = TestObject_1< AnyType >;


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
			//			verbose - this bool will be used to notify if the object should display debug information
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
			explicit inline TestObject_1( Boolean verbose = false );


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
			//			1. size - the size of the memory space to allocate
			//			2. value - the value to initiate all the entries
			//			3. verbose - this bool will be used to notify if the object should display debug information
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
			explicit inline TestObject_1( UnsignedInteger64bits size, AnyType value = AnyType(), Boolean verbose = false );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Constructor, to allow creating a random generated instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
	        //          2. rangeForSize - this will be used to limit the possible size of the random instance
	        //          3. rangeForValue - this will be used to limit the possible content of the value of the random instance
	        //          4. rangeForVerbose - this will be used to limit the possible verbosity of the random instance
	        //          5. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
	        //
	        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
	        explicit inline TestObject_1( RandomInstance, const NumericRange< UnsignedInteger64bits >& rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ), const  NumericRange< AnyType >& rangeForValue = NumericRange< AnyType >(), const NumericRange< Boolean >& rangeForVerbose = NumericRange< Boolean >(), ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


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
			inline TestObject_1( const SelfType& other );


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	        //      Assignment operator, can handle with self assignment and instances in default state
	    	//
	    	//  Required arguments :
	    	//
	    	//		User information needed :
	    	//
	    	//			other - a reference to the object that should be copied
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
	    	inline SelfType& operator=( const SelfType& other );


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	        //      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
	    	//
	    	//  Required arguments :
	    	//
	    	//   	User information needed :
	    	//
	    	//          other - a reference to the object that should be moved
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
	    	inline TestObject_1( TestObject_1&& other );


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	        //      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
	    	//
	    	//  Required arguments :
	    	//
	    	//   	User information needed :
	    	//
	    	//          other - a reference to the object that should be moved
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
	    	inline SelfType& operator=( SelfType&& other );


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
			//      Use this method to take an instance already initialized, delete the current resources and set it to default state
	    	//
	    	//  Required arguments :
	    	//
	    	//   	User information needed :
	    	//
			//			NONE
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
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
			inline void Reset();


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
			//			1. size - the size of the memory space to allocate
			//			2. value - the value to initiate all the entries
			//			3. verbose - this bool will be used to notify if the object should display debug information
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
			inline void Initiate( UnsignedInteger64bits size, AnyType value = AnyType(), Boolean verbose = false );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
	        //      This version is to allow initiating random instance
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
	        //          2. rangeForSize - this will be used to limit the possible size of the random instance
	        //          3. rangeForValue - this will be used to limit the possible content of the value of the random instance
	        //          4. rangeForVerbose - this will be used to limit the possible verbosity of the random instance
	        //          5. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
	        //
	        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
	        inline void Initiate( RandomInstance, const NumericRange< UnsignedInteger64bits >& rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 10000UL ), const NumericRange< AnyType >& rangeForValue = NumericRange< AnyType >(), const NumericRange< Boolean >& rangeForVerbose = NumericRange< Boolean >(), ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
			//      Use this method to get a handle that can be used to obtain information on the state of the instance
	    	//
	    	//  Required arguments :
	    	//
	    	//   	User information needed :
	    	//
			//			NONE
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
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
			inline const InstanceState& State() const;


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
			inline ~TestObject_1();


			// The following methods give access and manipulate the data inside this object :


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
			//      Use this method to get the size of the instance
	    	//
	    	//  Required arguments :
	    	//
	    	//   	User information needed :
	    	//
			//			NONE
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
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
			inline UnsignedInteger64bits Size() const;


			// The following methods declare the overloaded operators for the object :


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use to get reference to an entry
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          index - the index of the entry required
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      A reference to the required object
	        //
			//  Expectations :
			//
			//		NONE
			//
	        //  Possible errors :
	        //
	        //		They will come
	        //
	        inline AnyType& operator[]( UnsignedInteger64bits index ) const;


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
			inline bool operator==( const SelfType& other ) const;


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
			inline bool operator!=( const SelfType& other ) const;


		private:


 			// This object will be used to monitor the state of each instance
 			InstanceState member_state;

			// This object will store the memory address allocated on the heap memory segment
			AnyType* member_memoryAddress;

			// This object will store the size
			UnsignedInteger64bits member_size;

			// This object will store the verbosity level required
			bool member_verbose;


		};  //  Class TestObject_1




































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
		//			verbose - this bool will be used to notify if the object should display debug information
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
		template< typename AnyType >
		inline TestObject_1< AnyType >::TestObject_1( Boolean verbose ) :
		member_state(),
		member_memoryAddress( 0UL ),
		member_size( 0U ),
		member_verbose( verbose )
		{

			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Default constructor :\n    this pointer = " << this << std::endl << std::endl;
			}

		}


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
		//			1. size - the size of the memory space to allocate
		//			2. value - the value to initiate all the entries
		//			3. verbose - this bool will be used to notify if the object should display debug information
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
		template< typename AnyType >
		inline TestObject_1< AnyType >::TestObject_1( UnsignedInteger64bits size, AnyType value, Boolean verbose ) :
		member_state( InstanceState::Ready ),
		member_memoryAddress( new AnyType[ size ] ),
		member_size( size ),
		member_verbose( verbose )
		{

			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Constructor :\n    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << size << std::endl << std::endl;
			}

			// Set all the entries to the given value
			for ( UnsignedInteger64bits index = 0U ; index < size ; ++index )
			{
				member_memoryAddress[ index ] = value;
			}

		}


        // Method Information :
        //
        //  Description :
        //
        //      Constructor, to allow creating a random generated instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
        //          2. rangeForSize - this will be used to limit the possible size of the random instance
        //          3. rangeForValue - this will be used to limit the possible content of the value of the random instance
        //          4. rangeForVerbose - this will be used to limit the possible verbosity of the random instance
        //          5. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
        //
		template< typename AnyType >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline TestObject_1< AnyType >::TestObject_1( RandomInstance, const NumericRange< UnsignedInteger64bits >& rangeForSize, const NumericRange< AnyType >& rangeForValue, const NumericRange< Boolean >& rangeForVerbose, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType ) :
        SelfType( Random::Generator::Get< UnsignedInteger64bits >( rangeForSize ), Random::Generator::Get< AnyType >( rangeForValue ), Random::Generator::Get< Boolean >( rangeForVerbose ) )
        {

            // Set the entries of the generated instance to random values
            for ( UnsignedInteger64bits arrayIndex = 0UL ; arrayIndex < member_size ; ++arrayIndex )
            {
            	// Add another node to the random instance
            	member_memoryAddress[ arrayIndex ] = Random::Generator::Get< AnyType >( argumentsNeededToGenerateRandomInstanceOfDataType... );
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
		template< typename AnyType >
		inline TestObject_1< AnyType >::TestObject_1( const SelfType& other ) :
		member_state( other.member_state ),
		member_memoryAddress( 0UL ),
		member_size( other.member_size ),
		member_verbose( other.member_verbose )
		{

			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Copy constructor :\n    other pointer = " << &other << "\n    Memory address = " << other.member_memoryAddress << "\n    Size = " << other.member_size << std::endl << std::endl;
				std::cout << "    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << member_size << std::endl << std::endl;
			}

			// Check if the size of the other instance is not 0
			if ( ( other.State().Get() == InstanceState::Ready ) && ( other.member_size > 0UL ) )
			{
				// Allocate space 
				member_memoryAddress = new AnyType[ other.member_size ];

				// Set all the entries to the given value
				for ( UnsignedInteger64bits index = 0UL ; index < member_size ; ++index )
				{
					member_memoryAddress[ index ] = other.member_memoryAddress[ index ];
				}

			}

		}


    	// Method Information :
    	//
    	//  Description :
    	//
        //      Assignment operator, can handle with self assignment and instances in default state
    	//
    	//  Required arguments :
    	//
    	//		User information needed :
    	//
    	//			other - a reference to the object that should be copied
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
    	template< typename AnyType >
    	inline TestObject_1< AnyType >& TestObject_1< AnyType >::operator=( const SelfType& other )
    	{

			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Assignment operator :\n    other pointer = " << &other << "\n    Memory address = " << other.member_memoryAddress << "\n    Size = " << other.member_size << std::endl << std::endl;
				std::cout << "    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << member_size << std::endl << std::endl;
			}

            // Create a copy of the other instance
            SelfType temporary( other );

            // Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
            Swap( temporary );

            // Return a reference to this object
            return ( *this );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
        //      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the object that should be moved
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
    	template< typename AnyType >
    	inline TestObject_1< AnyType >::TestObject_1( TestObject_1&& other ) :
        SelfType()
        {
			
			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Move constructor :\n    other pointer = " << &other << "\n    Memory address = " << other.member_memoryAddress << "\n    Size = " << other.member_size << std::endl << std::endl;
				std::cout << "    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << member_size << std::endl << std::endl;
			}

            // Swap between this instance and the other one
            Swap( other );
        }


    	// Method Information :
    	//
    	//  Description :
    	//
        //      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the object that should be moved
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
    	template< typename AnyType >
    	inline TestObject_1< AnyType >& TestObject_1< AnyType >::operator=( SelfType&& other )
    	{

			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Move Assignment operator :\n    other pointer = " << &other << "\n    Memory address = " << other.member_memoryAddress << "\n    Size = " << other.member_size << std::endl << std::endl;
				std::cout << "    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << member_size << std::endl << std::endl;
			}

            // Create a default constructed instance
            SelfType defaultConstructedInstance;

            // Swap between the default constructed instance, which is in default state, and the other instance
            defaultConstructedInstance.Swap( other );

            // Swap between this instance and the default constructed instance one
            Swap( defaultConstructedInstance );

            // Return a reference to this object
            return ( *this );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
		//      Use this method to take an instance already initialized, delete the current resources and set it to default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
		//			NONE
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
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
		template< typename AnyType >
		inline void TestObject_1< AnyType >::Reset()
		{    																																			
		    // Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it
			// will delete the old resources																					
		    SelfType defaultConstructedInstance;																			
																																						
		    // Swap between this instance and the default constructed instance
		    Swap( defaultConstructedInstance );    																										
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
		template< typename AnyType >
		inline void TestObject_1< AnyType >::Swap( SelfType& other )
		{
			// Swap the state
			member_state.Swap( other.member_state );

			// Swap the verbosity
			bool otherVerbosityCopy = other.member_verbose;
			other.member_verbose = member_verbose;
			member_verbose = otherVerbosityCopy;

			// Swap the memory address
			AnyType* otherMemoryAddressCopy = other.member_memoryAddress;
			other.member_memoryAddress = member_memoryAddress;
			member_memoryAddress = otherMemoryAddressCopy; 

			// Swap the size
			UnsignedInteger64bits otherSizeCopy = other.member_size;
			other.member_size = member_size;
			member_size = otherSizeCopy; 
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
		//			1. size - the size of the memory space to allocate
		//			2. value - the value to initiate all the entries
		//			3. verbose - this bool will be used to notify if the object should display debug information
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
		template< typename AnyType >
		inline void TestObject_1< AnyType >::Initiate( UnsignedInteger64bits size, AnyType value, Boolean verbose )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( size, value, verbose );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
        //      This version is to allow initiating random instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. The first argument purpose is to ensure this constructor will be called by setting a special type
        //          2. rangeForSize - this will be used to limit the possible size of the random instance
        //          3. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
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
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
        //
        template< typename AnyType >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline void TestObject_1< AnyType >::Initiate( RandomInstance, const NumericRange< UnsignedInteger64bits >& rangeForSize, const NumericRange< AnyType >& rangeForValue, const NumericRange< Boolean >& rangeForVerbose, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType )
        {
            // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
            // leave this scope it delete the old data if exist
            SelfType randomGeneratedInstance( GenerateRandomInstance, rangeForSize, rangeForValue, rangeForVerbose, argumentsNeededToGenerateRandomInstanceOfDataType... );

            // Swap between this instance and the temporary instance
            Swap( randomGeneratedInstance );
        }


    	// Method Information :
    	//
    	//  Description :
    	//
		//      Use this method to get a handle that can be used to obtain information on the state of the instance
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
		//			NONE
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
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
		template< typename AnyType >
		inline const InstanceState& TestObject_1< AnyType >::State() const
		{
		    // Return a reference to the state member
		    return ( member_state );
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
		template< typename AnyType >
		inline TestObject_1< AnyType >::~TestObject_1()
		{

			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Destructor :\n    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << member_size << std::endl << std::endl;
			}

			// Check if memory space was allocated
			if ( member_memoryAddress != 0UL )
			{
				delete[] member_memoryAddress;
			}

		}


    	// Method Information :
    	//
    	//  Description :
    	//
		//      Use this method to get the size of the instance
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
		//			NONE
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
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
		template< typename AnyType >
		inline UnsignedInteger64bits TestObject_1< AnyType >::Size() const
		{
		    // Return the size of the instance
		    return ( member_size );
		}
































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************






























        // Method Information :
        //
        //  Description :
        //
        //      Use to get reference to an entry
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          index - the index of the entry required
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to the required object
        //
		//  Expectations :
		//
		//		NONE
		//
        //  Possible errors :
        //
        //		They will come
        //
		template< typename AnyType >
        inline AnyType& TestObject_1< AnyType >::operator[]( UnsignedInteger64bits index ) const
        {
        	// Return a reference to the entry
        	return ( member_memoryAddress[ index ] );
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
		template< typename AnyType >
		inline bool TestObject_1< AnyType >::operator==( const SelfType& other ) const
		{

			// Check if both instances are in default state
			if ( ( member_state.Get() == InstanceState::Default ) && ( other.member_state.Get() == InstanceState::Default ) )
			{
				return ( true );
			}
			// Check if only one isntance is in default state
			else if ( ( member_state.Get() == InstanceState::Default ) || ( other.member_state.Get() == InstanceState::Default ) )
			{
				return ( false );
			}

			// Compare the size
			if ( member_size != other.member_size )
			{
				return ( false );
			}

			// Compare the entries
			for ( UnsignedInteger64bits index = 0U ; index < member_size ; ++index )
			{

				if ( member_memoryAddress[ index ] != other.member_memoryAddress[ index ] )
				{
					return ( false );
				}

			}

			return ( true );
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
		template< typename AnyType >
		inline bool TestObject_1< AnyType >::operator!=( const SelfType& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}











    }  //  Namespace Testing

}  //  Namespace Universe



#endif  // TESTOBJECT_1_HPP