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
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
//		   an interface which conatins only static methods, and does not need to never be instantied
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class ModelSpecificRegisters
{
public:


	// Create a type definition for the object itself
	using SelfType = ModelSpecificRegisters;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
	// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
	// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
	// does not involve the non static data members


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to read the content of a model specific register. This is doen in Intel central processing unit by the 'RDMSR' instruction.
	//
	//		RDMSR :
	//
	//		Reads the contents of a 64 bit model specific register ( MSR ) specified in the ECX part of the RCX register into registers EDX:EAX. The high
	//		order 32 bits of RCX are ignored.The EDX part of the RDX register is loaded with the high order 32 bits of the model specific register and the 
	//		EAX part of the RAX register with the 32 low order bits. The high order bits of RAX and RDX are cleared. If fewer then 64 bits are implemented
	//		in the model specific register being read, the values returned to EDX:EAX in the empty parts locations are undefined.
	//
	//		This instruction must be executed at privilege level 0 or in real address mode, otherwise a general protection exception #GP(0) will be 
	//		generated. Specifying a reserved or unimplemented model specific register address in ECX part of the RCX register will also cause a general 
	//		protection exception.
	//
	//		The model specific registers control functions for testability, execution tracing, performance monitoring, and machine check errors. The
	//		'CPUID' instruction should be used to determine whether model specific registers are supported before using this instruction
	//
    //      Flags affected :
    //
    //			NONE
    //
    //      Hardware Exceptions :
    //
    //          1. #GP(0) - if the current privilege level is not 0
    //          2. #UD - if the LOCK prefix is used
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			modelSpecificRegisterIndex - the index of the model specific register that its content is needed
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
	EnsureRetrunValueIsUsed static inline UnsignedInteger64bits Read( const UnsignedInteger32bits modelSpecificRegisterIndex );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to write the content of a model specific register. This is doen in Intel central processing unit by the 'WRMSR' instruction.
	//
	//		WRMSR :
	//
	//		Writes the contents of registers EDX:EAX into the 64 bit model specific register ( MSR ) specified in the ECX part of the RCX register.
	//		The high order 32 bits of RCX are ignored. The contents of the EDX part of the RDX register are copied to the high order 32 bits of the
	//		selected model specific register and the contents of the EAX part of the RAX register are copied to the low order 32 bits. The high
	//		order 32 bits of the RAX and RDX are ignored. Undefined or reserved bits in a model specific register should be set to the values
	//		previously read.
	//
	//		This instruction must be executed at privilege level 0 or in real address mode, otherwise a general protection exception #GP(0) will be 
	//		generated. Specifying a reserved or unimplemented model specific register address in ECX part of the RCX register will also cause a general 
	//		protection exception. The central processing unit will also generate a general protection exception if software attempts to write to 
	//		bits in a reserved model specific register.
	//
	//		When the 'WRMSR' instruction is used to write to a memory type range register ( MTRR ), the translation lookaside buffers are invalidated.
	//		This includes global entries.
	//
	//		The 'WRMSR' instruction is a serializing instruction, beside writes to IA32_TSC_DEADLINE ( index 0x6E0 ) and X2APIC model specific registers
	//		( index 0x802 to 0x83F ) which are not serializing
	//
	//		The model specific registers control functions for testability, execution tracing, performance monitoring, and machine check errors. The
	//		'CPUID' instruction should be used to determine whether model specific registers are supported before using this instruction
	//
    //      Flags affected :
    //
    //			NONE
    //
    //      Hardware Exceptions :
    //
    //          1. #GP(0) :
    //
    //				1. If the current privilege level is not 0
    //				2. If the value in ECX specifies a reserved or unimplemented model specific register address
    //				3. If the value in EDX:EAX sets bits that are reserved in the model specific register
    //				4. If the source register contains a non canonical address and ECX part of the RCX register specifies one of the following model
    //				   model specific registers - IA32_DS_AREA, IA32_FS_BASE, IA32_GS_BASE, IA32_KERNEL_GS_BASE, IA32_LSTAR, IA32_SYSENTER_EIP,
    //				   IA32_SYSENTER_ESP
    //			
    //          2. #UD - if the LOCK prefix is used
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. modelSpecificRegisterIndex - the index of the model specific register that its content needs to change
	//			2. contentToWrite - this will be written to the model specific register
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
	static inline void Write( const UnsignedInteger32bits modelSpecificRegisterIndex, const UnsignedInteger64bits contentToWrite );


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


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( ModelSpecificRegisters );


};  //  Class ModelSpecificRegisters