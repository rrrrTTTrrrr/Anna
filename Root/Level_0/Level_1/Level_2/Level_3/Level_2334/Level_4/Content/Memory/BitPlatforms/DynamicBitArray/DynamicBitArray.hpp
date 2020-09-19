#ifndef DYNAMICBITARRAY_HPP
#define DYNAMICBITARRAY_HPP


#include "../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert, Macro MOVE
#include "../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../../Content/Metaprogramming/MetaprogrammingMacros/MetaprogrammingMacros.hpp"  //  Macro MOVE
#include "../../../../../Content/BuiltInTypesWrapper/Bit/Bit.hpp"  //  Class Bit
#include "../CommonFunctionality/SequentialPlatformsInterfaces/SequentialPlatform_Interface/SequentialPlatform_Interface.hpp"  //  Class SequentialPlatform_Interface
#include "../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../../../../../Content/NumericRange/NumericRange.hpp"  //  Class NumericRange


// This additional headers are only needed in test mode
#ifdef TEST_MODE
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



		// Class Information :
		//
		//  Purpose :
		//
		//		Use this object to store multiple bits. The size of the array is provided as an argument to the constructor which means that is allocated 
		//		during run time, and therefore it will be placed on the heap memory segment
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
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class DynamicBitArray : public SequentialPlatform_Interface< Bit< UnsignedInteger8bits > >
		{
		public:


            // Create a type definition for the sequential platform interface
            using SequentialPlatformInterfaceType = SequentialPlatform_Interface< Bit< UnsignedInteger8bits > >;


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
			inline DynamicBitArray();


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
			//			1. bitArraySize - the number of bits that the array will store
			//			2. state - the state that all the bits should be initialized to
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
			//		1. The given number of bits should be larger then 0
			//		2. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			explicit inline DynamicBitArray( UnsignedInteger64bits bitArraySize, Boolean state = 0 );


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
			//		    other - a reference to the instance that should be copied
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
			inline DynamicBitArray( const DynamicBitArray& other );


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
			ObjectForInheritanceInfrastructure_MACRO( DynamicBitArray )


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
			//		    other - a reference to the instance that should be swapped
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
			inline void Swap( DynamicBitArray& other );


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
			//			1. bitArraySize - the number of bits that the array will store
			//			2. state - the state that all the bits should be initialized to
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
			//		1. The given number of bits should be larger then 0
			//		2. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void Initiate( UnsignedInteger64bits bitArraySize, Boolean state = 0 );


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
			inline ~DynamicBitArray();


			// The following methods give access and manipulate the data inside this object :


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to get the dynamic bit array size inside this instance
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
	        //      The dynamic bit array size inside this instance
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        inline UnsignedInteger64bits Size() const;


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to get the memory address of the byte that contains the first bit inside this instance, all the other bytes with other
	        //		bits memory address can be obtained by indexing the returned memory address because all the entries are contigous
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
	        //      The memory address of the byte that contains the first bit inside this instance
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        inline UnsignedInteger8bits* ByteMemoryAddressOfFirstBit();


			// The following methods declare the overloaded operators for the object :


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to get a reference to the required entry
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
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        inline Bit< UnsignedInteger8bits > operator[]( UnsignedInteger64bits index );


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this operator to get a constant reference to the required entry
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
	        //      A constant reference to the instance inside the required entry
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        inline const Bit< UnsignedInteger8bits > operator[]( UnsignedInteger64bits index ) const;


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
			inline Boolean operator==( const DynamicBitArray& other ) const;


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
			inline Boolean operator!=( const DynamicBitArray& other ) const;


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
	        //      User information needed :
	        //
	        //          rangeForSize - this will be used to limit the possible size of the random instance
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      A random generated instance
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
	        //
	        static inline DynamicBitArray GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForSize );


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


			// This object will be used to monitor the state of each instance
			InstanceState member_state;

 			// This object will store the bits array
 			UnsignedInteger8bits* member_dynamicBitArray;

 			// This object will store the number of bits in the array
 			UnsignedInteger64bits member_size;


		};  //  Class DynamicBitArray




































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
		inline DynamicBitArray::DynamicBitArray() :
		SequentialPlatform_Interface< Bit< UnsignedInteger8bits > >(),
		member_state(),
		member_dynamicBitArray( 0UL ),
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
		//			1. bitArraySize - the number of bits that the array will store
		//			2. state - the state that all the bits should be initialized to
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
		//		1. The given number of bits should be larger then 0
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		inline DynamicBitArray::DynamicBitArray( UnsignedInteger64bits bitArraySize, Boolean state ) :
		SequentialPlatform_Interface< Bit< UnsignedInteger8bits > >(),
		member_state( InstanceState::Ready ),
		member_dynamicBitArray( new UnsignedInteger8bits[ ( ( bitArraySize / 8UL ) + 1UL ) ] ),
		member_size( bitArraySize )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert_MACRO( ( bitArraySize > 0UL ), "The given size should be larger then 0" )

			// This object will have all the bits ON if the given state is ON and all the bits OFF if the state is OFF
			UnsignedInteger8bits byteWithAllTheBitsInTheRequiredState = 0x00;

			// Check if the given state is ON or OFF
			if  ( state == 1 )
			{
				// The required state is ON

				// Set all the bits ON
				byteWithAllTheBitsInTheRequiredState = 0xFF;
			}

            // Set all the entries to the given instance
            Memory::Operations::Set< UnsignedInteger8bits >( member_dynamicBitArray, ( ( member_size / 8UL ) + 1UL ), byteWithAllTheBitsInTheRequiredState );			
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
		//		    other - a reference to the instance that should be copied
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
		inline DynamicBitArray::DynamicBitArray( const DynamicBitArray& other ) :
		SequentialPlatform_Interface< Bit< UnsignedInteger8bits > >(),
		member_state( other.member_state ),
		member_dynamicBitArray( new UnsignedInteger8bits[ ( ( other.member_size / 8UL ) + 1UL ) ] ),
		member_size( other.member_size )
		{
			// Copy the content of the other bit array to this bit array
			Memory::Operations::Copy< UnsignedInteger8bits >( other.member_dynamicBitArray, member_dynamicBitArray, ( ( other.member_size / 8UL ) + 1UL ) );
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
		//		other - a reference to the instance that should be swaped
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
		inline void DynamicBitArray::Swap( DynamicBitArray& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );

            // Swap between the dynamic bit arrays
            Memory::Operations::Swap< UnsignedInteger8bits* >( member_dynamicBitArray, other.member_dynamicBitArray );

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
		//			1. bitArraySize - the number of bits that the array will store
		//			2. state - the state that all the bits should be initialized to
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
		//		1. The given number of bits should be larger then 0
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		inline void DynamicBitArray::Initiate( UnsignedInteger64bits bitArraySize, Boolean state )
		{
		    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
		    // leave this scope it delete the old data if exist
		    DynamicBitArray instanceCreatedUsingTheRequiredConstructor( bitArraySize, state );

		    // Swap between this instance and the temporary instance
		    Swap( instanceCreatedUsingTheRequiredConstructor );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Destructor, does not throw any exceptions
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
		inline DynamicBitArray::~DynamicBitArray()
		{
       	    // Check if the object is in default state, then noting needs to be done
       	    ReturnIfExpressionIsTrue_MACRO( member_state.Get() == InstanceState::Default )

       	    // Delete the memory space allocated for the dynamic bit array
       	    delete[] member_dynamicBitArray;
		}


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the dynamic bit array size inside this instance
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
        //      The dynamic bit array size inside this instance
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline UnsignedInteger64bits DynamicBitArray::Size() const
        {
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO

            // Return the dynamic bit array size
            return ( member_size );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the memory address of the byte that contains the first bit inside this instance, all the other bytes with other
        //		bits memory address can be obtained by indexing the returned memory address because all the entries are contigous
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
        //      The memory address of the byte that contains the first bit inside this instance
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline UnsignedInteger8bits* DynamicBitArray::ByteMemoryAddressOfFirstBit()
        {
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO

            // Return the memory address of the byte that contains the first bit inside this instance
            return ( member_dynamicBitArray );
        }

































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************

































        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get a reference to the required entry
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
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Bit< UnsignedInteger8bits > DynamicBitArray::operator[]( UnsignedInteger64bits index )
        {
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO
			Assert_MACRO( ( index < member_size ), "The given index should by smaller then the array size" )
            
            // Return a reference to the required entry
            return ( MOVE( Bit< UnsignedInteger8bits >( ( member_dynamicBitArray + ( index / 8 ) ), ( index % 8 ) ) ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get a constant reference to the required entry
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
        //      A constant reference to the instance inside the required entry
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline const Bit< UnsignedInteger8bits > DynamicBitArray::operator[]( UnsignedInteger64bits index ) const
        {
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO
			Assert_MACRO( ( index < member_size ), "The given index should by smaller then the array size" )

            // Return a reference to the required entry
            return ( MOVE( Bit< UnsignedInteger8bits >( (UnsignedInteger8bits*)( member_dynamicBitArray + ( index / 8 ) ), ( index % 8 ) ) ) );
        }


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
		inline Boolean DynamicBitArray::operator==( const DynamicBitArray& other ) const
		{
			// Check if both or only one of the instances is in default state
			CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO

			// Check if both instances has the same number of bits
			if ( member_size != other.member_size )
			{
				// The two instances has a different number of bits

				// Return false
				return ( false );
			}

            // Compare between the bit arrays, and return the result
            return ( Memory::Operations::Compare< UnsignedInteger8bits >( member_dynamicBitArray, other.member_dynamicBitArray, ( ( member_size / 8UL ) + 1UL ) ) );
		}


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
		inline Boolean DynamicBitArray::operator!=( const DynamicBitArray& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































        // Method Information :
        //
        //  Description :
        //
        //      Use this method to generate a random instance of this object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          rangeForSize - this will be used to limit the possible size of the random instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A random generated instance
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
        //
        inline DynamicBitArray DynamicBitArray::GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForSize )
        {
            // Create an instance
            DynamicBitArray randomInstance( ( Random::Generator::Get< UnsignedInteger64bits >( rangeForSize ) ) );

            // Set the entries of the generated instance to random values
            for ( UnsignedInteger64bits bitArrayIndex = 0UL ; bitArrayIndex < randomInstance.Size() ; ++bitArrayIndex )
            {
                // Set the current entry to a random value
                randomInstance[ bitArrayIndex ] = Random::Generator::Get< Boolean >();
            }

            // Return a copy of the instance
            return ( MOVE( randomInstance ) );
        }










	}  //  Namespace Memory

}  //  Namespace Universe



#endif  // DYNAMICBITARRAY_HPP