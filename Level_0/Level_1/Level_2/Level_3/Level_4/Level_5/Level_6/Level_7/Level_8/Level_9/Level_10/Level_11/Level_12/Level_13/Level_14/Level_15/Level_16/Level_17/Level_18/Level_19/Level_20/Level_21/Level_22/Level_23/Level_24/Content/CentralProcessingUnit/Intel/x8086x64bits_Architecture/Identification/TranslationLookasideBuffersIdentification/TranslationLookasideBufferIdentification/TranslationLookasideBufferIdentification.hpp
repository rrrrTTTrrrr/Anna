namespace Universe
{


namespace CentralProcessingUnit
{


// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
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


	// Create a type definition for this object
	using SelfType = TranslationLookasideBufferIdentification;


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
	//			translationLookasideBufferByteDescriptor - a byte containing a value that represents a specific translation lookaside buffer
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
	explicit inline TranslationLookasideBufferIdentification( const UnsignedInteger8bits translationLookasideBufferByteDescriptor );


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
	inline TranslationLookasideBufferIdentification( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( TranslationLookasideBufferIdentification )


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


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ ByteDescriptor, /* MemberName */ member_translationLookasideBufferByteDescriptor, /* MemberType */ UnsignedInteger8bits )
	GetByValue_Creator( /* GetMethodName */ IsSharedByMultipleCentralProcessingUnits, /* MemberName */ member_trueForShared_falseForExclusiveUse, /* MemberType */ Boolean )
	GetByValue_Creator( /* GetMethodName */ SizeInBytes, /* MemberName */ member_sizeInBytes, /* MemberType */ LargestUnsignedInteger )
	GetByValue_Creator( /* GetMethodName */ IsForInstructions, /* MemberName */ member_trueForInstructions_falseForData, /* MemberType */ Boolean )
	GetByValue_Creator( /* GetMethodName */ NumberOfPageSizesSupported, /* MemberName */ member_numberOfPageSizesSupported, /* MemberType */ UnsignedInteger8bits )
	GetByValue_Creator( /* GetMethodName */ IsAssociativityKnown, /* MemberName */ member_isAssociativityKnown, /* MemberType */ Boolean )
	GetByValue_Creator( /* GetMethodName */ IsFullAssociative, /* MemberName */ member_trueForFullAssociative_falseForSetAssociative, /* MemberType */ Boolean )


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
	EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


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
	EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


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
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// This will store the byte descriptor that represents the translational lookaside buffer in this instance
	UnsignedInteger8bits member_translationLookasideBufferByteDescriptor;

    // This will store the translational lookaside buffer memory size in bytes
    LargestUnsignedInteger member_sizeInBytes;

    // This boolean will store if the translational lookaside buffer belongs to one central processing unit or is shraed among multiple
    Boolean member_trueForShared_falseForExclusiveUse;

    // This boolean will store if the translational lookaside buffer stores instructions or data
    Boolean member_trueForInstructions_falseForData;

    // This number will store the number of supported page sizes
    UnsignedInteger8bits member_numberOfPageSizesSupported;

    // This boolean will store if associativity of the translational lookaside buffer is known or not
    Boolean member_isAssociativityKnown;

    // This boolean will store this translational lookaside buffer is fully associative or set associative ( god knows what that is )
    Boolean member_trueForFullAssociative_falseForSetAssociative;

    // This object will store the translational lookaside buffer pages supported sizes. It can support either one, or multiple. Furthermore, for each
    // page size two attributes will be associated, the number of entries and the number of way set associative 
    Memory::Array< Memory::Tuple< LargestUnsignedInteger, LargestUnsignedInteger, LargestUnsignedInteger >, 3UL > member_supportedPageSizesInBytesAssociatedWithNumberOfEntriesAndTheNumberOfWaySetAssociative;

    // Some page sizes can be used together while others don't. This array will contain for each supported page size, with which other from
    // the supported page sizes it can wotk together. The location for each page size is the same as in the supported page sizes array, if 
    // a page size appears in the first entry, then the first entry in this array will also be for it
    Memory::Array< Memory::Array< Boolean, 3UL >, 3UL > member_pageSizeCanWorkToghterWithThisOtherPageSizes;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


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
    //          translationLookasideBufferByteDescriptor - this will be used to determine if it contains translation lookaside buffer information, and also the specific type
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
    void InitializeInstanceWithTranslationLookasideBufferAttributesRepresentedByByteDescriptor__Private( const UnsignedInteger8bits translationLookasideBufferByteDescriptor );


};  //  Class TranslationLookasideBufferIdentification