#ifndef BITARRAY_HPP
#define BITARRAY_HPP


#include "../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert, Macro MOVE
#include "../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../../Content/Metaprogramming/MetaprogrammingMacros/MetaprogrammingMacros.hpp"  //  Macro MOVE
#include "../../../../../Content/BuiltInTypesWrapper/Bit/Bit.hpp"  //  Class Bit
#include "../CommonFunctionality/SequentialPlatformsInterfaces/SequentialPlatform_Interface/SequentialPlatform_Interface.hpp"  //  Class SequentialPlatform_Interface
#include "../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator


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



        // The divide "/" operaotr yields the quotient, and the modulo % operator yields the remainder from the division of the first expression by the second. If the 
        // second operand of "/" or "%" is 0 the behavior is undefined. If both operands are nonnegative then the remainder is nonnegative, if not the sign of the remainder 
        // is implementation dependent



        // If the operand of the modulo is a power of 2, it used to be possible to compute it as :
        //
        //          n % b ( power of 2 )  =  n & ( b - 1 )
        //
        // The new standard requires that it be computed as :
        //
        //          n < 0 ? n | -b : n & ( b - 1 )
        //
        // Likewise, the divide operation can not be written as a simple shift, even on hardware that supports arithmetic shifts, instead, on such systems, an expression 
        // like ->  n / 16 must be written as :
        //
        //          n < 0 ? ( n + 15 ) >> 4 : n >> 4



        // The result of a subtraction generating a negative number in an unsigned type is well defined :
        //
        // A computation involving unsigned operands can never overflow, because a result that cannot be represented by the resulting unsigned integer type is reduced 
        // modulo the number that is one greater than the largest value that can be represented by the resulting type
        //
        // Example ->  (unsigned int)0 - (unsigned int)1  =  -1 % ( UNSIGNED_INT_MAX_VALUE + 1 )  =  UNSIGNED_INT_MAX_VALUE
        //
        // Explenation :
        //
        // When working with unsigned types, modular arithmetic ( also known as "wrap around" behavior ) is applied. To understand modular arithmetic, the clock can be 
        // used. If the hour is cuurently 9 am, adding 4 hours to it would bring us to the hour 1 pm, which is equal to the operation :
        //
        //          ( 9 + 4 ) % 12 = 1
        //
        // but the other way should give also a correct answer, if the current hour is 1 pm, going back 4 hours should give 9 am, which is equal to the operation :
        //
        //          ( 1 - 4 ) % 12 = 9



		// Template Class Information :
		//
		//  Purpose :
		//
		//		Use this object to store multiple bits. The size of the array is provided as a template argument, which means that it is known already 
		//		in compile time. The size then is determined and can not be changed. This is mandatory because the array will be placed in the stack 
		//		memory segment, and the compiler must know in advance how much memory space is needed to allocate it
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
		//			1. UnsignedInteger64bits - an integer to describe the required number of bits in the array
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< UnsignedInteger64bits BitArraySize >
		class BitArray : public SequentialPlatform_Interface< Bit< UnsignedInteger8bits > >
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
			//		Constructor,
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			state - the state that all the bits should be initialized to
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
			inline BitArray( Boolean state = 0 );


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
			inline BitArray( const BitArray< BitArraySize >& other );


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
			TemplateObjectForInheritanceInfrastructure_MACRO( BitArray, BitArraySize )


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
			inline void Swap( BitArray< BitArraySize >& other );


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
			//			state - the state that all the bits should be initialized to
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
			inline void Initiate( Boolean state = 0 );


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
			virtual ~BitArray() = default;


			// The following methods give access and manipulate the data inside this object :


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to get the bit array size inside this instance
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
	        //      The bit array size inside this instance
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
	        Bit< UnsignedInteger8bits > operator[]( UnsignedInteger64bits index );


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
	        const Bit< UnsignedInteger8bits > operator[]( UnsignedInteger64bits index ) const;


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
			inline Boolean operator==( const BitArray< BitArraySize >& other ) const;


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
			inline Boolean operator!=( const BitArray< BitArraySize >& other ) const;


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
            //          NONE
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
            //      They will come
            //
            static inline BitArray< BitArraySize > GenerateRandomInstance();


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
 			UnsignedInteger8bits member_bitArray[ ( BitArraySize / 8UL ) + 1UL ];


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Method Information :
			//
			//  Description :
			//
			//      This method will be used to assert all the requirements on the template arguments provided to the object. To perform a compile time assert
			//		the C++ language provides the keyword 'static_assert', which receives an expression and an error message to display if the expression
			//		result is false. The important thing is that the expression is evaluted during compile time, and therefore if the expression is false
			//		the compilation will be terminated and the error message will be displayed. This method should not be used, because it does nothing during
			//		run time
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
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void AssertTemplateArgumentsRequirementsDuringCompileTime__Private() const;


		};  //  Class BitArray





































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************






































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
		//			state - the state that all the bits should be initialized to
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
		template< UnsignedInteger64bits BitArraySize >
		inline BitArray< BitArraySize >::BitArray( Boolean state ) :
		SequentialPlatform_Interface< Bit< UnsignedInteger8bits > >(),
		member_state( InstanceState::Ready ),
		member_bitArray()
		{
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
            Memory::Operations::Set< UnsignedInteger8bits >( member_bitArray, ( ( BitArraySize / 8UL ) + 1UL ), byteWithAllTheBitsInTheRequiredState );
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
		template< UnsignedInteger64bits BitArraySize >
		inline BitArray< BitArraySize >::BitArray( const BitArray< BitArraySize >& other ) :
		SequentialPlatform_Interface< Bit< UnsignedInteger8bits > >(),
		member_state( other.member_state ),
		member_bitArray()
		{
			// Copy the content of the other bit array to this bit array
			Memory::Operations::Copy< UnsignedInteger8bits >( other.member_bitArray, member_bitArray, ( ( BitArraySize / 8UL ) + 1UL ) );
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
		template< UnsignedInteger64bits BitArraySize >
		inline void BitArray< BitArraySize >::Swap( BitArray< BitArraySize >& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );

            // Swap between the bit arrays
            Memory::Operations::Swap< UnsignedInteger8bits >( member_bitArray, other.member_bitArray, ( ( BitArraySize / 8UL ) + 1UL ) );
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
		//			state - the state that all the bits should be initialized to
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
		template< UnsignedInteger64bits BitArraySize >
		inline void BitArray< BitArraySize >::Initiate( Boolean state )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    BitArray< BitArraySize > temporary( state );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the bit array size inside this instance
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
        //      The bit array size inside this instance
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< UnsignedInteger64bits BitArraySize >
        UnsignedInteger64bits BitArray< BitArraySize >::Size() const
        {
            // Return the bit array size
            return ( BitArraySize );
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
        template< UnsignedInteger64bits BitArraySize >
        inline UnsignedInteger8bits* BitArray< BitArraySize >::ByteMemoryAddressOfFirstBit()
        {
            // Return the memory address of the byte that contains the first bit inside this instance
            return ( member_bitArray );
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
        template< UnsignedInteger64bits BitArraySize >
        Bit< UnsignedInteger8bits > BitArray< BitArraySize >::operator[]( UnsignedInteger64bits index )
        {
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert_MACRO( ( index < BitArraySize ), "Memory::BitArray::operator[] failed - the given index should by smaller then the array size" )
            
            // Return a reference to the required entry
            return ( MOVE( Bit< UnsignedInteger8bits >( ( member_bitArray + ( index / 8 ) ), ( index % 8 ) ) ) );
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
        template< UnsignedInteger64bits BitArraySize >
        const Bit< UnsignedInteger8bits > BitArray< BitArraySize >::operator[]( UnsignedInteger64bits index ) const
        {
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert_MACRO( ( index < BitArraySize ), "Memory::BitArray::operator[] constant failed - the given index should by smaller then the array size" )

            // Return a reference to the required entry
            return ( MOVE( Bit< UnsignedInteger8bits >( (UnsignedInteger8bits*)( member_bitArray + ( index / 8 ) ), ( index % 8 ) ) ) );
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
		template< UnsignedInteger64bits BitArraySize >
		inline Boolean BitArray< BitArraySize >::operator==( const BitArray< BitArraySize >& other ) const
		{            
            // Compare between the bit arrays, and return the result
            return ( Memory::Operations::Compare< UnsignedInteger8bits >( member_bitArray, other.member_bitArray, ( ( BitArraySize / 8UL ) + 1UL ) ) );
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
		template< UnsignedInteger64bits BitArraySize >
		inline Boolean BitArray< BitArraySize >::operator!=( const BitArray< BitArraySize >& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































		// Method Information :
		//
		//  Description :
		//
		//      This method will be used to assert all the requirements on the template arguments provided to the object. To perform a compile time assert
		//		the C++ language provides the keyword 'static_assert', which receives an expression and an error message to display if the expression
		//		result is false. The important thing is that the expression is evaluted during compile time, and therefore if the expression is false
		//		the compilation will be terminated and the error message will be displayed. This method should not be used, because it does nothing during
		//		run time
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
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< UnsignedInteger64bits BitArraySize >
		inline void BitArray< BitArraySize >::AssertTemplateArgumentsRequirementsDuringCompileTime__Private() const
		{
			// This method will contain as much as neccessary compile time assertions to check that the given template arguments pass the requirements
            CompileTimeAssert( ( BitArraySize > 0UL ), "Memory::BitArray failed - the given bit array size is 0" );
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
        //          NONE
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
        //      They will come
        //
		template< UnsignedInteger64bits BitArraySize >
        inline BitArray< BitArraySize > BitArray< BitArraySize >::GenerateRandomInstance()
        {
            // Create an instance
            BitArray< BitArraySize > randomInstance;

            // Set the entries of the generated instance to random values
            for ( UnsignedInteger64bits bitArrayIndex = 0UL ; bitArrayIndex < BitArraySize ; ++bitArrayIndex )
            {
                // Set the current entry to a random value
                randomInstance[ bitArrayIndex ] = Random::Generator::Get< Boolean >();
            }

            // Return a copy of the instance
            return ( MOVE( randomInstance ) );
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
			template< UnsignedInteger64bits BitArraySize >
			void BitArray< BitArraySize >::Test()
			{
                // Create an instance of the object using the default constructor
                BitArray< 89UL > testBitArray_1;

                // Loop and check that all the bits are ON
                for ( UnsignedInteger64bits bitIndex = 0UL ; bitIndex < 89UL ; ++bitIndex )
                {
	                // Check that the current bit is ON
	                Assert_MACRO( ( testBitArray_1[ bitIndex ].ONorOFF() == 0 ), "Test failed - 1" );
                }

                // Create an instnace of the object using the parameterized constructor
                BitArray< 873UL > testBitArray_2( 1 );

                // Loop and check that all the bits are ON
                for ( UnsignedInteger64bits bitIndex = 0UL ; bitIndex < 873UL ; ++bitIndex )
                {
	                // Check that the current bit is ON
	                Assert_MACRO( ( testBitArray_2[ bitIndex ].ONorOFF() == 1 ), "Test failed - 2" );
                }

                // Check the size of the array
                Assert_MACRO( ( testBitArray_2.Size() == 873UL ), "Test failed - 3" );

                // Create an instnace of the object using the parameterized constructor
                BitArray< 49UL > testBitArray_3;

                // Check the size of the array
                Assert_MACRO( ( testBitArray_3.Size() == 49UL ), "Test failed - 4" );              
                Assert_MACRO( ( testBitArray_3[13].ONorOFF() == 0 ), "Test failed - 5" );              

                // Create an instnace of the object using the parameterized constructor
                BitArray< 49UL > testBitArray_4( 1 );

                // Check that the 2 instnaces are different
                Assert_MACRO( ( testBitArray_3 != testBitArray_4 ), "Test failed - 6" );  

                // Set all the entries
                testBitArray_4.Initiate();

                // Check that the 2 instnaces are the same
                Assert_MACRO( ( testBitArray_3 == testBitArray_4 ), "Test failed - 7" );

                // A write operation is performed, to check that the object uses the copy on write method before
                testBitArray_4[5] = 1;

                // Check that the 2 instnaces point to the same address
                Assert_MACRO( ( testBitArray_3 != testBitArray_4 ), "Test failed - 8" );                                              

                // Check if the addition works
                Assert_MACRO( ( testBitArray_4[5] & 1 ), "Test failed - 9" );

                // Test the generate random instance method
                BitArray< 44 >::GenerateRandomInstance();
                GenerateRandomInstance();
                BitArray< 44 >::GenerateRandomInstance();
			}

		)  //  End of debug tool











    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // BITARRAY_HPP