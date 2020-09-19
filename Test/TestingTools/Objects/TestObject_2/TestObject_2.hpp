#ifndef TESTOBJECT_2_HPP
#define TESTOBJECT_2_HPP


#include <iostream>  //  Class std::cout, Class std::endl


#include "../../../../Root/Level_0/Content/Object/InstanceState/InstanceState.hpp"  //  Class InstanceState


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
		class TestObject_2 final
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
			inline TestObject_2( bool verbose = false );


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
			explicit inline TestObject_2( unsigned int size, int value, bool verbose = false );


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
			inline TestObject_2( const TestObject_2& other );


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
	    	//  Return object :
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
	    	inline TestObject_2& operator=( const TestObject_2& other );


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
	    	//  Return object :
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
	    	inline TestObject_2( TestObject_2&& other );


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
	    	//  Return object :
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
	    	inline TestObject_2& operator=( TestObject_2&& other );


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
	    	//  Return object :
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
			inline void Swap( TestObject_2& other );


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
			inline void Initiate( unsigned int size, int value, bool verbose = false );


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
	    	//  Return object :
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
			inline ~TestObject_2();


			// The following methods give access and manipulate the data inside this object :


			inline UnsignedInteger32bits TestMethod_1( UnsignedInteger32bits, UnsignedInteger64bits );

			inline UnsignedInteger32bits TestMethod_2( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits );

			inline void TestMethod_3();

			inline UnsignedInteger32bits TestMethod_4();

	        inline void TestMethod_5( UnsignedInteger32bits, UnsignedInteger64bits );

	        inline void TestMethod_6( UnsignedInteger32bits*, UnsignedInteger64bits* );

			inline UnsignedInteger32bits TestMethod_1_Constant( UnsignedInteger32bits, UnsignedInteger64bits ) const;

			inline UnsignedInteger32bits TestMethod_2_Constant( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits ) const;

			inline void TestMethod_3_Constant() const;

			inline UnsignedInteger32bits TestMethod_4_Constant() const;

	        inline void TestMethod_5_Constant( UnsignedInteger32bits, UnsignedInteger64bits ) const;

	        inline void TestMethod_6_Constant( UnsignedInteger32bits*, UnsignedInteger64bits* ) const;


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
	        //  Return object :
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
	        inline int& operator[]( unsigned int index ) const;


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
			inline bool operator==( const TestObject_2& other ) const;


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
			inline bool operator!=( const TestObject_2& other ) const;


		private:


 			// This object will be used to monitor the state of each instance
 			InstanceState member_state;

			// This object will store the verbosity level required
			bool member_verbose;

			// This object will store the memory address allocated on the heap memory segment
			int* member_memoryAddress;

			// This object will store the size
			unsigned int member_size;


		};  //  Class TestObject_2




































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
		inline TestObject_2::TestObject_2( bool verbose ) :
		member_state(),
		member_verbose( verbose ),
		member_memoryAddress( 0UL ),
		member_size( 0U )
		{

			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Default constructor :\n    this pointer = " << this << std::endl;
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
		inline TestObject_2::TestObject_2( unsigned int size, int value, bool verbose ) :
		member_state( InstanceState::Ready ),
		member_verbose( verbose ),
		member_memoryAddress( new int[ size ] ),
		member_size( size )
		{
			
			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Constructor :\n    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << size << std::endl;
			}

			// Set all the entries to the given value
			for ( unsigned int index = 0U ; index < size ; ++index )
			{
				member_memoryAddress[ index ] = value;
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
		inline TestObject_2::TestObject_2( const TestObject_2& other ) :
		member_state( other.member_state ),
		member_verbose( other.member_verbose ),
		member_memoryAddress( new int[ other.member_size ] ),
		member_size( other.member_size )
		{

			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Copy constructor :\n    other pointer = " << &other << "\n    Memory address = " << other.member_memoryAddress << "\n    Size = " << other.member_size << std::endl << std::endl;
				std::cout << "    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << member_size << std::endl;
			}

			// Set all the entries to the given value
			for ( unsigned int index = 0U ; index < member_size ; ++index )
			{
				member_memoryAddress[ index ] = other.member_memoryAddress[ index ];
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
    	//  Return object :
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
    	inline TestObject_2& TestObject_2::operator=( const TestObject_2& other )
    	{

			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Assignment operator :\n    other pointer = " << &other << "\n    Memory address = " << other.member_memoryAddress << "\n    Size = " << other.member_size << std::endl << std::endl;
				std::cout << "    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << member_size << std::endl;
			}

            // Create a copy of the other instance
            TestObject_2 temporary( other );

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
    	//  Return object :
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
    	inline TestObject_2::TestObject_2( TestObject_2&& other ) :
        TestObject_2( other.member_verbose )
        {
			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Move constructor :\n    other pointer = " << &other << "\n    Memory address = " << other.member_memoryAddress << "\n    Size = " << other.member_size << std::endl << std::endl;
				std::cout << "    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << member_size << std::endl;
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
    	//  Return object :
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
    	inline TestObject_2& TestObject_2::operator=( TestObject_2&& other )
    	{

			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Move Assignment operator :\n    other pointer = " << &other << "\n    Memory address = " << other.member_memoryAddress << "\n    Size = " << other.member_size << std::endl << std::endl;
				std::cout << "    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << member_size << std::endl;
			}

            // Create a default constructed instance
            TestObject_2 defaultConstructedInstance( other.member_verbose );

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
    	//  Return object :
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
		inline void TestObject_2::Reset()
		{    																																			
		    // Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it
			// will delete the old resources																					
		    TestObject_2 defaultConstructedInstance;																			
																																						
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
		inline void TestObject_2::Swap( TestObject_2& other )
		{
			// Swap the state
			member_state.Swap( other.member_state );

			// Swap the verbosity
			bool otherVerbosityCopy = other.member_verbose;
			other.member_verbose = member_verbose;
			member_verbose = otherVerbosityCopy;

			// Swap the memory address
			int* otherMemoryAddressCopy = other.member_memoryAddress;
			other.member_memoryAddress = member_memoryAddress;
			member_memoryAddress = otherMemoryAddressCopy; 

			// Swap the size
			unsigned int otherSizeCopy = other.member_size;
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
		inline void TestObject_2::Initiate( unsigned int size, int value, bool verbose )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    TestObject_2 temporary( verbose, size, value );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
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
    	//  Return object :
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
		inline const InstanceState& TestObject_2::State() const
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
		inline TestObject_2::~TestObject_2()
		{

			// Check if verbosity is true
			if ( member_verbose == true )
			{
				std::cout << "Destructor :\n    this pointer = " << this << "\n    Memory address = " << member_memoryAddress << "\n    Size = " << member_size << std::endl;
			}

			// Check if memory space was allocated
			if ( member_memoryAddress != 0UL )
			{
				delete[] member_memoryAddress;
			}

		}


		inline UnsignedInteger32bits TestObject_2::TestMethod_1( UnsignedInteger32bits rr, UnsignedInteger64bits )
		{
			rr += 1;
			return ( 9 );
		}

		inline UnsignedInteger32bits TestObject_2::TestMethod_2( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits )
		{
			return ( 99 );
		}

		inline void TestObject_2::TestMethod_3()
		{}

		inline UnsignedInteger32bits TestObject_2::TestMethod_4()
		{
			return ( 999 );
		}

        inline void TestObject_2::TestMethod_5( UnsignedInteger32bits, UnsignedInteger64bits )
        {}

        inline void TestObject_2::TestMethod_6( UnsignedInteger32bits* pointer_1, UnsignedInteger64bits* pointer_2 )
        {
        	*pointer_1 = 888333;
        	*pointer_2 = 7777;
        }

		inline UnsignedInteger32bits TestObject_2::TestMethod_1_Constant( UnsignedInteger32bits rr, UnsignedInteger64bits ) const 
		{
			rr += 1;
			return ( 9 );
		}

		inline UnsignedInteger32bits TestObject_2::TestMethod_2_Constant( UnsignedInteger32bits, UnsignedInteger64bits, UnsignedInteger64bits ) const
		{
			return ( 99 );
		}

		inline void TestObject_2::TestMethod_3_Constant() const
		{}

		inline UnsignedInteger32bits TestObject_2::TestMethod_4_Constant() const
		{
			return ( 999 );
		}

        inline void TestObject_2::TestMethod_5_Constant( UnsignedInteger32bits, UnsignedInteger64bits ) const
        {}

        inline void TestObject_2::TestMethod_6_Constant( UnsignedInteger32bits* pointer_1, UnsignedInteger64bits* pointer_2 ) const
        {
        	*pointer_1 = 888333;
        	*pointer_2 = 7777;
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
        //  Return object :
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
        inline int& TestObject_2::operator[]( unsigned int index ) const
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
		inline bool TestObject_2::operator==( const TestObject_2& other ) const
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
			for ( unsigned int index = 0U ; index < member_size ; ++index )
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
		inline bool TestObject_2::operator!=( const TestObject_2& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}














    }  //  Namespace Testing

}  //  Namespace Universe



#endif  // TESTOBJECT_2_HPP