#ifndef TRANSLATIONLOOKASIDEBUFFERIDENTIFICATION_HPP
#define TRANSLATIONLOOKASIDEBUFFERIDENTIFICATION_HPP


#include "../../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../Content/Memory/SequentialPlatforms/Array/Array.hpp"  //  Class Array
#include "../../../../../../../../../Content/BindObjects/Triplet/Triplet.hpp"  //  Class Triplet


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
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



        // There is 1 tlb with the seperate array, currently it is too much to add to each instance!!!!!!!

        // // This boolean will store if the translational lookaside buffer has an additional seperate array
        // Boolean member_seperateArray;

        // // This number will store the number of supported page sizes for the seperate array
        // UnsignedInteger64bits member_seperateArray_numberOfPageSizesSupported;

        // // This object will store the seperate array supported page size
        // UnsignedInteger64bits member_seperateArray_supportedPageSizeInBytes;

        // // This object will should be used only if the seperate array is set associatve. It will store the number of way set associative
        // UnsignedInteger64bits member_seperateArray_numberOfWaySetAssociative;

        // // This will store the number of entries the seperate array contains
        // UnsignedInteger64bits member_seperateArray_numbrOfEntries;



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
		class TranslationLookasideBufferIdentification NotForInheritance
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
			inline TranslationLookasideBufferIdentification();


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
			//			byteDescriptor - a byte containing a value that represents a specific translation lookaside buffer
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
	        //      1. The given byte descriptor value represents a translation lookaside buffer
	        //		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			explicit inline TranslationLookasideBufferIdentification( UnsignedInteger8bits byteDescriptor );


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
			inline TranslationLookasideBufferIdentification( const TranslationLookasideBufferIdentification& other );


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
			ObjectInfrastructure_MACRO( TranslationLookasideBufferIdentification )


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
			inline void Swap( TranslationLookasideBufferIdentification& other );


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
			//			byteDescriptor - a byte containing a value that represents a specific translation lookaside buffer
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
	        //      1. The given byte descriptor value represents a translation lookaside buffer
	        //		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void Initiate( UnsignedInteger8bits byteDescriptor );


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
			inline ~TranslationLookasideBufferIdentification() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the byte descriptor that represents the translation lookaside buffer
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
			//		The byte descriptor that represents the translation lookaside buffer
			//
			//  Expectations :
			//
	        //      1. The instance should be ready
	        //		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger8bits ByteDescriptor() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the translation lookaside buffer is shared
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
			//		True if the translation lookaside buffer is shared, and false otherwise
			//
			//  Expectations :
			//
	        //      1. The instance should be ready
	        //		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger8bits Shared() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the size in bytes of the translation lookaside buffer
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
			//		The size in bytes of the translation lookaside buffer
			//
			//  Expectations :
			//
	        //      1. The instance should be ready
	        //		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger64bits Size() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the translation lookaside buffer is for instructions
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
			//		True if the translation lookaside buffer is for instructions, and false otherwise
			//
			//  Expectations :
			//
	        //      1. The instance should be ready
	        //		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger64bits Instructions() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the translation lookaside buffer is for data
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
			//		True if the translation lookaside buffer is for data, and false otherwise
			//
			//  Expectations :
			//
	        //      1. The instance should be ready
	        //		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger64bits Data() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the number of page sizes the translation lookaside buffer supports
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
			//		The number of page sizes the translation lookaside buffer supports
			//
			//  Expectations :
			//
	        //      1. The instance should be ready
	        //		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger8bits NumberOfPageSizesSupported() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the associativity of the translation lookaside buffer is known
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
			//		True if the associativity of the translation lookaside buffer is known, and false otherwise
			//
			//  Expectations :
			//
	        //      1. The instance should be ready
	        //		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger8bits AssociativityKnown() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the translation lookaside buffer is full associative
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
			//		True if the translation lookaside buffer is full associative, and false otherwise
			//
			//  Expectations :
			//
	        //      1. The instance should be ready
	        //		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger8bits FullAssociative() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the translation lookaside buffer is set associative
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
			//		True if the translation lookaside buffer is set associative, and false otherwise
			//
			//  Expectations :
			//
	        //      1. The instance should be ready
	        //		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger8bits SetAssociative() const;


			// The following methods declare the overloaded operators for the object :


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
			inline Boolean operator==( const TranslationLookasideBufferIdentification& other ) const;


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
			inline Boolean operator!=( const TranslationLookasideBufferIdentification& other ) const;


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


			// This object will be used to monitor the state of each instance
			InstanceState member_state;

			// This will store the byte descriptor that represents the translational lookaside buffer in this instance
			UnsignedInteger8bits member_byteDescriptor;

            // This will store the translational lookaside buffer memory size in bytes
            UnsignedInteger64bits member_sizeInBytes;

            // This boolean will store if the translational lookaside buffer belongs to one central processing unit or is shraed among multiple
            Boolean member_trueForShared_falseForExclusiveUse;

            // This boolean will store if the translational lookaside buffer stores instructions or data
            Boolean member_trueForInstructions_falseForData;

            // This number will store the number of supported page sizes
            UnsignedInteger8bits member_numberOfPageSizesSupported;

            // This boolean will store if associativity of the translational lookaside buffer is known or not
            Boolean member_associativityKnown;

            // This boolean will store this translational lookaside buffer is fully associative or set associative ( god knows what that is )
            Boolean member_trueForFullAssociative_falseForSetAssociative;

            // This object will store the translational lookaside buffer pages supported sizes. It can support either one, or multiple. Furthermore, for each
            // page size two attributes will be associated, the number of entries and the number of way set associative 
            Memory::Array< Memory::Triplet< UnsignedInteger64bits, UnsignedInteger64bits, UnsignedInteger64bits >, 3 > member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative;

            // Some page sizes can be used together while others don't. This array will contain for each supported page size, with which other from
            // the supported page sizes it can wotk together. The location for each page size is the same as in the supported page sizes array, if 
            // a page size appears in the first entry, then the first entry in this array will also be for it
            Memory::Array< Memory::Array< Boolean, 3 >, 3 > member_pageSizeCanWorkToghterWithThisOtherPageSizes;


			// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program
			// and only destroyed when the program ends. The access to the static member is bound to this object of course


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to initialize the instance with the attributes of the translation lookaside buffer that the given byte descriptor
	        //		represents
	        //
	        //  Required arguments :
	        //
	        //      User information needed :
	        //
	        //          byteDescriptor - this will be used to determine if it contains translation lookaside buffer information, and also the specific type
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
	        //      1. The given byte descriptor value represents a translation lookaside buffer
	        //		2. 
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
	        void InitializeInstanceWithTranslationLookasideBufferAttributesRepresentedByByteDescriptor__Private( UnsignedInteger8bits byteDescriptor );


			// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
			// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
			// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
			// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
			// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
			// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


		};  //  Class TranslationLookasideBufferIdentification




































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
		inline TranslationLookasideBufferIdentification::TranslationLookasideBufferIdentification() :
		member_state(),
		member_byteDescriptor( 0UL ),
        member_sizeInBytes( 0UL ),
        member_trueForShared_falseForExclusiveUse( false ),
        member_trueForInstructions_falseForData( false ),
        member_numberOfPageSizesSupported( 0UL ),
        member_associativityKnown( false ),
        member_trueForFullAssociative_falseForSetAssociative( false ),
        member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative(),
        member_pageSizeCanWorkToghterWithThisOtherPageSizes()
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
		//			byteDescriptor - a byte containing a value that represents a specific translation lookaside buffer
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
        //      1. The given byte descriptor value represents a translation lookaside buffer
        //		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		TranslationLookasideBufferIdentification::TranslationLookasideBufferIdentification( UnsignedInteger8bits byteDescriptor ) :
		member_state( InstanceState::Ready ),
		member_byteDescriptor( byteDescriptor ),
	    member_sizeInBytes( 0UL ),
        member_trueForShared_falseForExclusiveUse( false ),
        member_trueForInstructions_falseForData( false ),
        member_numberOfPageSizesSupported( 0UL ),
        member_associativityKnown( false ),
        member_trueForFullAssociative_falseForSetAssociative( false ),
        member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative(),
        member_pageSizeCanWorkToghterWithThisOtherPageSizes()
		{
			// Initialize the instance using the given byte descriptor
			InitializeInstanceWithTranslationLookasideBufferAttributesRepresentedByByteDescriptor__Private( byteDescriptor );
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
		inline TranslationLookasideBufferIdentification::TranslationLookasideBufferIdentification( const TranslationLookasideBufferIdentification& other ) :
		member_state( other.member_state ),
		member_byteDescriptor( other.member_byteDescriptor ),
        member_sizeInBytes( other.member_sizeInBytes ),
        member_trueForShared_falseForExclusiveUse( other.member_trueForShared_falseForExclusiveUse ),
        member_trueForInstructions_falseForData( other.member_trueForInstructions_falseForData ),
        member_numberOfPageSizesSupported( other.member_numberOfPageSizesSupported ),
        member_associativityKnown( other.member_associativityKnown ),
        member_trueForFullAssociative_falseForSetAssociative( other.member_trueForFullAssociative_falseForSetAssociative ),
        member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative( other.member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative ),
        member_pageSizeCanWorkToghterWithThisOtherPageSizes( other.member_pageSizeCanWorkToghterWithThisOtherPageSizes )
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
		inline void TranslationLookasideBufferIdentification::Swap( TranslationLookasideBufferIdentification& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );

		    // Swap between the byte descriptors
		    Memory::Operations::Swap< UnsignedInteger8bits >( member_byteDescriptor, other.member_byteDescriptor );

		    // Swap between the size in bytes
		    Memory::Operations::Swap< UnsignedInteger64bits >( member_sizeInBytes, other.member_sizeInBytes );

		    // Swap between the booleans that describe if the translational lookaside buffer is shared or exclusive
		    Memory::Operations::Swap< Boolean >( member_trueForShared_falseForExclusiveUse, other.member_trueForShared_falseForExclusiveUse );

		    // Swap between the booleans that describe if the translational lookaside buffer is for instructions or data
		    Memory::Operations::Swap< Boolean >( member_trueForInstructions_falseForData, other.member_trueForInstructions_falseForData );

		    // Swap between the number of page sizes supported
		    Memory::Operations::Swap< UnsignedInteger8bits >( member_numberOfPageSizesSupported, other.member_numberOfPageSizesSupported );

		    // Swap between the booleans that describe if the translational lookaside buffer associativity is known or not
		    Memory::Operations::Swap< Boolean >( member_associativityKnown, other.member_associativityKnown );

		    // Swap between the booleans that describe if the translational lookaside buffer is full associative or set associative
		    Memory::Operations::Swap< Boolean >( member_trueForFullAssociative_falseForSetAssociative, other.member_trueForFullAssociative_falseForSetAssociative );

		    // Swap between the arrays conataining information on the supported page sizes and attributes
		    member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative.Swap( other.member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative );

		    // Swap between the array of arrays that contain information on which pages can coexist with other page sizes
		    member_pageSizeCanWorkToghterWithThisOtherPageSizes.Swap( other.member_pageSizeCanWorkToghterWithThisOtherPageSizes );
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
		//			byteDescriptor - a byte containing a value that represents a specific translation lookaside buffer
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
        //      1. The given byte descriptor value represents a translation lookaside buffer
        //		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline void TranslationLookasideBufferIdentification::Initiate( UnsignedInteger8bits byteDescriptor )
		{
		    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
		    // leave this scope it delete the old data if exist
		    TranslationLookasideBufferIdentification instanceCreatedUsingTheRequiredConstructor( byteDescriptor );

		    // Swap between this instance and the temporary instance
		    Swap( instanceCreatedUsingTheRequiredConstructor );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the byte descriptor that represents the translation lookaside buffer
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
		//		The byte descriptor that represents the translation lookaside buffer
		//
		//  Expectations :
		//
        //      1. The instance should be ready
        //		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger8bits TranslationLookasideBufferIdentification::ByteDescriptor() const
		{
	        // This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.Get() == InstanceState::Ready ), "CentralProcessingUnit::TranslationLookasideBufferIdentification::ByteDescriptor failed - the instance is not ready" )	
	
			// Return a copy of the byte descriptor
			return ( member_byteDescriptor );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the translation lookaside buffer is shared
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
		//		True if the translation lookaside buffer is shared, and false otherwise
		//
		//  Expectations :
		//
        //      1. The instance should be ready
        //		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger8bits TranslationLookasideBufferIdentification::Shared() const
		{
	        // This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.Get() == InstanceState::Ready ), "CentralProcessingUnit::TranslationLookasideBufferIdentification::Shared failed - the instance is not ready" )	
	
			// Return if the translation lookaside buffer is shared or not
			return ( member_trueForShared_falseForExclusiveUse );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the size in bytes of the translation lookaside buffer
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
		//		The size in bytes of the translation lookaside buffer
		//
		//  Expectations :
		//
        //      1. The instance should be ready
        //		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger64bits TranslationLookasideBufferIdentification::Size() const
		{
	        // This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.Get() == InstanceState::Ready ), "CentralProcessingUnit::TranslationLookasideBufferIdentification::Size failed - the instance is not ready" )	
	
			// Return the size in bytes of the translation lookaside buffer
			return ( member_sizeInBytes );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the translation lookaside buffer is for instructions
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
		//		True if the translation lookaside buffer is for instructions, and false otherwise
		//
		//  Expectations :
		//
        //      1. The instance should be ready
        //		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger64bits TranslationLookasideBufferIdentification::Instructions() const
		{
	        // This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.Get() == InstanceState::Ready ), "CentralProcessingUnit::TranslationLookasideBufferIdentification::Instructions failed - the instance is not ready" )	
	
			// Return if the translation lookaside buffer is for instructions
			return ( member_trueForInstructions_falseForData );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the translation lookaside buffer is for data
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
		//		True if the translation lookaside buffer is for data, and false otherwise
		//
		//  Expectations :
		//
        //      1. The instance should be ready
        //		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger64bits TranslationLookasideBufferIdentification::Data() const
		{
	        // This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.Get() == InstanceState::Ready ), "CentralProcessingUnit::TranslationLookasideBufferIdentification::Data failed - the instance is not ready" )	
	
			// Return if the translation lookaside buffer is for data
			return ( member_trueForInstructions_falseForData == false );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the number of page sizes the translation lookaside buffer supports
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
		//		The number of page sizes the translation lookaside buffer supports
		//
		//  Expectations :
		//
        //      1. The instance should be ready
        //		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger8bits TranslationLookasideBufferIdentification::NumberOfPageSizesSupported() const
		{
	        // This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.Get() == InstanceState::Ready ), "CentralProcessingUnit::TranslationLookasideBufferIdentification::NumberOfPageSizesSupported failed - the instance is not ready" )	
	
			// Return the number of page sizes the translation lookaside buffer supports
			return ( member_numberOfPageSizesSupported );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the associativity of the translation lookaside buffer is known
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
		//		True if the associativity of the translation lookaside buffer is known, and false otherwise
		//
		//  Expectations :
		//
        //      1. The instance should be ready
        //		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger8bits TranslationLookasideBufferIdentification::AssociativityKnown() const
		{
	        // This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.Get() == InstanceState::Ready ), "CentralProcessingUnit::TranslationLookasideBufferIdentification::AssociativityKnown failed - the instance is not ready" )	
	
			// Return if the associativity of the translation lookaside buffer is known
			return ( member_associativityKnown );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the translation lookaside buffer is full associative
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
		//		True if the translation lookaside buffer is full associative, and false otherwise
		//
		//  Expectations :
		//
        //      1. The instance should be ready
        //		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger8bits TranslationLookasideBufferIdentification::FullAssociative() const
		{
	        // This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.Get() == InstanceState::Ready ), "CentralProcessingUnit::TranslationLookasideBufferIdentification::FullAssociative failed - the instance is not ready" )	
	
			// Return if the translation lookaside buffer is full associative
			return ( member_trueForFullAssociative_falseForSetAssociative );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the translation lookaside buffer is set associative
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
		//		True if the translation lookaside buffer is set associative, and false otherwise
		//
		//  Expectations :
		//
        //      1. The instance should be ready
        //		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline UnsignedInteger8bits TranslationLookasideBufferIdentification::SetAssociative() const
		{
	        // This will be added only in test mode, to ensure that the given data to the method is valid
			Assert_MACRO( ( member_state.Get() == InstanceState::Ready ), "CentralProcessingUnit::TranslationLookasideBufferIdentification::SetAssociative failed - the instance is not ready" )	
	
			// Return if the translation lookaside buffer is set associative
			return ( member_trueForFullAssociative_falseForSetAssociative == false );
		}





































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































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
		inline Boolean TranslationLookasideBufferIdentification::operator==( const TranslationLookasideBufferIdentification& other ) const
		{
			// Check if both instances contain the same byte descriptor
			return ( member_byteDescriptor == other.member_byteDescriptor );
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
		inline Boolean TranslationLookasideBufferIdentification::operator!=( const TranslationLookasideBufferIdentification& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}










	}  //  Namespace CentralProcessingUnit

}  //  Namespace Universe



#endif  // TRANSLATIONLOOKASIDEBUFFERIDENTIFICATION_HPP