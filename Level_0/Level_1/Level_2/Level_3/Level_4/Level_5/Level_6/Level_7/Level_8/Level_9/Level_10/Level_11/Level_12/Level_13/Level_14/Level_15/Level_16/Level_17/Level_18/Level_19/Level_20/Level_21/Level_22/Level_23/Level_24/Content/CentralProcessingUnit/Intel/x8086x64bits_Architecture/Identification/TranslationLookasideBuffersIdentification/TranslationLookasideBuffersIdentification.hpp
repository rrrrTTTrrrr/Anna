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
class TranslationLookasideBuffersIdentification NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = TranslationLookasideBuffersIdentification;


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
    //          EAX_EBX_ECX_EDX_registersContentStoredAfterCpuidInstructionExecutedWithEAXsetToTwo - a constant reference to an array with the result from invoking the CPUID with EAX set to 2
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
	explicit inline TranslationLookasideBuffersIdentification( const Memory::Array< UnsignedInteger32bits, 4UL >& EAX_EBX_ECX_EDX_registersContentStoredAfterCpuidInstructionExecutedWithEAXsetToTwo );


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
	inline TranslationLookasideBuffersIdentification( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( TranslationLookasideBuffersIdentification )


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
	//      The number of translation lookaside buffers
	//
	//  Expectations :
	//
	//		NONE 
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed inline UnsignedInteger64bits NumberOfTranslationLookasideBuffers() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get a constant reference to the data translation lookaside buffer identification
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
	//      A constant reference to the data translation lookaside buffer identification
	//
	//  Expectations :
	//
	//		1. A data translation lookaside buffer identification exist
	//		2. 
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed inline const TranslationLookasideBufferIdentification& DataTranslationLookasideBufferIdentification() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get a constant reference to the instructions translation lookaside buffer identification
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
	//      A constant reference to the instructions translation lookaside buffer identification
	//
	//  Expectations :
	//
	//		1. A instructions translation lookaside buffer identification exist
	//		2. 
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed inline const TranslationLookasideBufferIdentification& InstructionsTranslationLookasideBufferIdentification() const;


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


    // This object will store the translation lookaside buffers identification. There should usually be at least 2, one for data and one for
    // instructions. There couls also be a shared translation lookaside buffer
    Memory::Vector< TranslationLookasideBufferIdentification > member_translationLookasideBuffersIdentification;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


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
    EnsureRetrunValueIsUsed static Boolean DoesByteDescriptorValueRepresentTranslaionLookasideBuffer__Private( const UnsignedInteger8bits byteDescriptor );


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
    //          EAX_EBX_ECX_EDX_registersContentStoredAfterCpuidInstructionExecutedWithEAXsetToTwo - a constant reference to an array with the result from invoking the CPUID with EAX set to 2
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
    void InitializeTranslationLookasideBuffersIdentificationArray__Private( const Memory::Array< UnsignedInteger32bits, 4UL >& EAX_EBX_ECX_EDX_registersContentStoredAfterCpuidInstructionExecutedWithEAXsetToTwo );


};  //  Class TranslationLookasideBuffersIdentification