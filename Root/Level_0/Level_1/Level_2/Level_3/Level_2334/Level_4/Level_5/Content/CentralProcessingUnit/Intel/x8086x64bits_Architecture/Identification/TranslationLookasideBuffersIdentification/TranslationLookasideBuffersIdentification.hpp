#ifndef TRANSLATIONLOOKASIDEBUFFERSIDENTIFICATION_HPP
#define TRANSLATIONLOOKASIDEBUFFERSIDENTIFICATION_HPP


#include "../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../Content/Memory/SequentialPlatforms/Array/Array.hpp"  //  Class Array
#include "./TranslationLookasideBufferIdentification/TranslationLookasideBufferIdentification.hpp"  //  Class TranslationLookasideBufferIdentification


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe
{

	namespace CentralProcessingUnit
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
		//		Use this object to extract the information on the translation lookaside buffer existing in the system, from the output of the CPUID 
		//		instruction, and store them in an easily accessible way
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
		class TranslationLookasideBuffersIdentification NotForInheritance
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
			inline TranslationLookasideBuffersIdentification();


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
	        //          memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo - the memory address address where the result from invoking the CPUID with EAX set to 2
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
			//		1. The given pointer should not be NULL
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			explicit inline TranslationLookasideBuffersIdentification( const UnsignedInteger32bits* memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo );


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
			inline TranslationLookasideBuffersIdentification( const TranslationLookasideBuffersIdentification& other );


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
			ObjectInfrastructure_MACRO( TranslationLookasideBuffersIdentification )


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
			inline void Swap( TranslationLookasideBuffersIdentification& other );


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
	        //          memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo - the memory address address where the result from invoking the CPUID with EAX set to 2
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
			//		1. The given pointer should not be NULL
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void Initiate( const UnsignedInteger32bits* memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo );


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
			inline ~TranslationLookasideBuffersIdentification() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the number of translation lookaside buffers
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
			//		The number of translation lookaside buffers
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger8bits NumberOfTranslationLookasideBuffersIdentification() const;


			// The following methods declare the overloaded operators for the object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this operator to get a constant reference to the translation lookaside buffer identification instance in the required entry
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			index - the required index to the array
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A constant reference to the translation lookaside buffer identification instance in the required entry
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline const TranslationLookasideBufferIdentification& operator[]( UnsignedInteger64bits index ) const;


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
			inline Boolean operator==( const TranslationLookasideBuffersIdentification& other ) const;


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
			inline Boolean operator!=( const TranslationLookasideBuffersIdentification& other ) const;


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

            // This object will store the translation lookaside buffers identification. There should usually be at least 2, one for data and one for
            // instructions. There couls also be a shared translation lookaside buffer
            Memory::Array< TranslationLookasideBufferIdentification, 3 > member_translationLookasideBuffersIdentification;

            // This object will store the number of translation lookaside buffers this central processing unit actually contains
            UnsignedInteger8bits member_numberOfTranslationLookasideBuffers;


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to pass on the byte descriptors returned in the EAX, EBX, ECX and EDX after invoking the CPUID instruction with EAX
	        //      set to 2 
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo - the memory address address where the result from invoking the CPUID with EAX set to 2
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
	        //      1. The given pointer should not be NULL
	        //      2. 
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        void InitializeTranslationLookasideBuffersIdentificationArray__Private( const UnsignedInteger32bits* memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to check if the byte descriptor represent a translation lookaside buffer
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			byteDescriptor - a byte containing a value
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		true if the 2 byte descriptor represent a translation lookaside buffer, and false otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
	        inline Boolean DoesByteDescriptorValeRepresentTranslaionLookasideBuffer__Private( UnsignedInteger8bits byteDescriptor ) const;


		};  //  Class TranslationLookasideBuffersIdentification









































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
		inline TranslationLookasideBuffersIdentification::TranslationLookasideBuffersIdentification() :
		member_state(),
		member_translationLookasideBuffersIdentification(),
		member_numberOfTranslationLookasideBuffers( 0UL )
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
        //          memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo - the memory address address where the result from invoking the CPUID with EAX set to 2
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
		//		1. The given pointer should not be NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline TranslationLookasideBuffersIdentification::TranslationLookasideBuffersIdentification( const UnsignedInteger32bits* memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo ) :
		member_state( InstanceState::Ready ),
		member_translationLookasideBuffersIdentification{ TranslationLookasideBufferIdentification() },
		member_numberOfTranslationLookasideBuffers( 0UL )
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
            Assert_MACRO( ( memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo != 0 ), "CentralProcessingUnit::TranslationLookasideBuffersIdentificationIdentification::Constructor failed - the given pointer is NULL" )

            // Extract the information from the byte descriptors, and initialize the array entries with it
            InitializeTranslationLookasideBuffersIdentificationArray__Private( memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo );
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
		inline TranslationLookasideBuffersIdentification::TranslationLookasideBuffersIdentification( const TranslationLookasideBuffersIdentification& other ) :
		member_state( other.member_state ),
		member_translationLookasideBuffersIdentification( other.member_translationLookasideBuffersIdentification ),
		member_numberOfTranslationLookasideBuffers( other.member_numberOfTranslationLookasideBuffers )
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
		inline void TranslationLookasideBuffersIdentification::Swap( TranslationLookasideBuffersIdentification& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );

		    // Swap between the arrays
		    member_translationLookasideBuffersIdentification.Swap( other.member_translationLookasideBuffersIdentification );

		    // Swap between the number of translation lookaside buffers
		    Memory::Operations::Swap< UnsignedInteger8bits >( member_numberOfTranslationLookasideBuffers, other.member_numberOfTranslationLookasideBuffers );
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
        //          memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo - the memory address address where the result from invoking the CPUID with EAX set to 2
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
		//		1. The given pointer should not be NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline void TranslationLookasideBuffersIdentification::Initiate( const UnsignedInteger32bits* memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo )
		{
		    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
		    // leave this scope it delete the old data if exist
		    TranslationLookasideBuffersIdentification instanceCreatedUsingTheRequiredConstructor( memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo );

		    // Swap between this instance and the temporary instance
		    Swap( instanceCreatedUsingTheRequiredConstructor );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the number of translation lookaside buffers
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
		//		The number of translation lookaside buffers
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger8bits TranslationLookasideBuffersIdentification::NumberOfTranslationLookasideBuffersIdentification() const
		{
	        // This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.Get() == InstanceState::Ready ), "CentralProcessingUnit::NumberOfTranslationLookasideBuffersIdentification::NumberOfTranslationLookasideBuffersIdentification failed - the instance is not ready" )	
			
			// Return the number of translation lookaside buffers
			return ( member_numberOfTranslationLookasideBuffers );
		}



































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to get a constant reference to the translation lookaside buffer identification instance in the required entry
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			index - the required index to the array
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A constant reference to the translation lookaside buffer identification instance in the required entry
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline const TranslationLookasideBufferIdentification& TranslationLookasideBuffersIdentification::operator[]( UnsignedInteger64bits index ) const
		{
        	// This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.Get() == InstanceState::Ready ), "CentralProcessingUnit::TranslationLookasideBuffersIdentification::operator[] failed - the instance is not ready" )	
			
			// Return a constant reference to the requried entry
			return ( member_translationLookasideBuffersIdentification[ index ] );
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
		inline Boolean TranslationLookasideBuffersIdentification::operator==( const TranslationLookasideBuffersIdentification& other ) const
		{
			// Check if both or only one of the instances is in default state
			CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO
			
			// Compare the instances and retrun the result
			return ( member_translationLookasideBuffersIdentification == other.member_translationLookasideBuffersIdentification );
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
		inline Boolean TranslationLookasideBuffersIdentification::operator!=( const TranslationLookasideBuffersIdentification& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}





































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************


































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to check if the byte descriptor represent a translation lookaside buffer
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			byteDescriptor - a byte containing a value
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		true if the 2 byte descriptor represent a translation lookaside buffer, and false otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
        inline Boolean TranslationLookasideBuffersIdentification::DoesByteDescriptorValeRepresentTranslaionLookasideBuffer__Private( UnsignedInteger8bits byteDescriptor ) const
        {
            // This array will contain all the valid byte descriptors that describe translation lookaside buffers
			const Boolean byteDescriptorsThatRepresentTranslationLookasideBuffer[256] = { 	false, true, true, true, true, true, false, false, false, false, false, true, false, false, false, false, 
																							false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
																							false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
																							false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
																							false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, true, 
																							true, true, true, false, false, true, true, true, false, true, true, true, true, true, false, false, 
																							false, true, false, true, true, false, false, false, false, false, false, false, false, false, false, false, 
																							false, false, false, false, false, false, true, false, false, false, false, false, false, false, false, false, 
																							false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
																							false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
																							true, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
																							true, true, true, true, true, true, true, false, false, false, true, false, false, false, false, false, 
																							true, true, true, true, true, false, false, false, false, false, true, false, false, false, false, false, 
																							false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
																							false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, 
																							false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false };

			// Use the byte descriptor as index to the array, and return if it describes a translation lookaside buffer or not
			return ( byteDescriptorsThatRepresentTranslationLookasideBuffer[ byteDescriptor ] );
        } 













	}  //  Namespace CentralProcessingUnit

}  //  Namespace Universe



#endif  // TRANSLATIONLOOKASIDEBUFFERSIDENTIFICATION_HPP