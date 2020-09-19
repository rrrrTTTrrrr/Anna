#ifndef ASCIILITERAL_HPP
#define ASCIILITERAL_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../Memory/Operations/Aid/Aid.hpp"  //  Class Aid
#include "../AsciiCharacter/AsciiCharacter.hpp"  //  Class AsciiCharacter


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../Error/Assert/Assert.hpp"  //  Class Assert
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
		//		Artifical Inteligence
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
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
		class AsciiLiteral NotForInheritance
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
			inline AsciiLiteral();


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
			//			asciiLiteral - the memory address in the text memory segment of the ascii literal
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
			inline AsciiLiteral( const char* asciiLiteral );


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
			inline AsciiLiteral( const AsciiLiteral& other );


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
			ObjectInfrastructure_MACRO( AsciiLiteral )


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
			inline void Swap( AsciiLiteral& other );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			asciiLiteral - the memory address in the text memory segment of the ascii literal
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
			inline void Initiate( const char* asciiLiteral );


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
			inline ~AsciiLiteral() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the size of the ascii literal
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
			//		The size of the ascii literal
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
	        //      Use this operator to get a copy of the required ascii character
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          index - the index of the required ascii character
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      A copy of the ascii character in the required entry
	        //
	        //  Expectations :
	        //
	        //      1. The instance should be ready
	        //		2. The given index should be in the range of the ascii literal
	        //		3. 
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        inline AsciiCharacter operator[]( UnsignedInteger64bits index ) const;


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
			inline Boolean operator==( const AsciiLiteral& other ) const;


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
			inline Boolean operator!=( const AsciiLiteral& other ) const;


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

			// This object will store the memory address in the text memory segment of the ascii literal
			const char* member_asciiLiteral;

			// This object will store the size of the ascii literal
			UnsignedInteger64bits member_size;


		};  //  Class AsciiLiteral




































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
		inline AsciiLiteral::AsciiLiteral() :
		member_state(),
		member_asciiLiteral( 0UL ),
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
		//			asciiLiteral - the memory address in the text memory segment of the ascii literal
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
		AsciiLiteral::AsciiLiteral( const char* asciiLiteral ) :
		member_state( InstanceState::Ready ),
		member_asciiLiteral( asciiLiteral ),
		member_size( Aid::AsciiStringSize( member_asciiLiteral ) )
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
		inline AsciiLiteral::AsciiLiteral( const AsciiLiteral& other ) :
		member_state( other.member_state ),
		member_asciiLiteral( other.member_asciiLiteral ),
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
		void AsciiLiteral::Swap( AsciiLiteral& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );

		    // Swap between the ascii literals pointers
		    Operations::Swap< const char* >( member_asciiLiteral, other.member_asciiLiteral );

		    // Swap between the sizes
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
		//			asciiLiteral - the memory address in the text memory segment of the ascii literal
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
		inline void AsciiLiteral::Initiate( const char* asciiLiteral )
		{
		    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
		    // leave this scope it delete the old data if exist
		    AsciiLiteral instanceCreatedUsingTheRequiredConstructor( asciiLiteral );

		    // Swap between this instance and the temporary instance
		    Swap( instanceCreatedUsingTheRequiredConstructor );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the size of the ascii literal
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
		//		The size of the ascii literal
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger64bits AsciiLiteral::Size() const
		{
			// Return the ascii literal size
			return ( member_size );
		}


































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************

































        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to get a copy of the required ascii character
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          index - the index of the required ascii character
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A copy of the ascii character in the required entry
        //
        //  Expectations :
        //
        //      1. The instance should be ready
        //		2. The given index should be in the range of the ascii literal
        //		3. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline AsciiCharacter AsciiLiteral::operator[]( UnsignedInteger64bits index ) const
        {
			// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( index < member_size ), "The instance should be ready" )
			Assert_MACRO( ( index < member_size ), "The given index should by smaller then the ascii literal size" )

            // Return a copy of the required ascii character
            return ( AsciiCharacter( member_asciiLiteral[ index ] ) );
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
		inline Boolean AsciiLiteral::operator==( const AsciiLiteral& other ) const
		{

			// Check if the size of both ascii literals is the same
			if ( member_size != other.member_size )
			{
				// The sizes are different

				// The instances don't match, return fals
				return ( false );
			}

			// Check if both instances match, and return the result
			return ( Operations::Compare< const char >( member_asciiLiteral, other.member_asciiLiteral, member_size ) );
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
		inline Boolean AsciiLiteral::operator!=( const AsciiLiteral& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}














	}  //  Namespace Memory

}  //  Namespace Universe



#endif  // ASCIILITERAL_HPP