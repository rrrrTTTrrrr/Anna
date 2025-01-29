namespace Universe
{


namespace CentralProcessingUnit
{



// Central processing unit identification :
//
// The instruction used is 'CPUID'. It returns processor identification and feature information to the EAX, EBX, ECX and EDX registers, as
// determind by input entered in EAX ( in some cases, ECX as well ).
//
// The identification flag ( ID ), which is bit 21, in the RFLAGS register indicates support for the CPUID instruction. If a software procedure
// can set and clear this flag, the processor executing the procedure supports the 'CPUID' instruction. Two types of inforamtion are returned
// basic and extended function information. If a value entered in the EAX register is higher than the maximum input value for basic or extended
// function for that processor then the data for the highest basic information leaf is returned. If the value is less or equal to the maximum
// input value and the leaf is not supported on that processor then 0 is returned in all the registers. 'CPUID' can be executed at any privilege
// level to serialize instruction execution. Serializing instruction execution gurantees that any modifications to flags, registers and memory
// for previous instructions are completed before the next instruction is fetched and executed.
//
// Flags affected :
//
//  NONE
//
// Hardware Exceptions :
//
//  #UD - if the 'LOCK' prefix is used
//
// The possibilities are :        
//
// Register EAX value = 0h :
//
// The processor returns the highest value the 'CPUID' recognized for returning basic processor information. The value is returned in the EAX 
// register and is processor specific. A vendor identification string is also returned in EBX, EDX and ECX. For Intel the string is :
//
//          "GenuineIntel"
//
//          EBX  ->   756E6547h ( "Genu", with 'G' in the low eight bits of BL )
//          EDX  ->   49656E69h ( "ineI", with 'i' in the low eight bits of DL )
//          ECX  ->   6C65746Eh ( "ntel", with 'n' in the low eight bits of CL )
//
// Register EAX value = 80000000h :
//
// The processor returns the highest value the processor recognizes for returning extended processor information. The value is returned in the
// EAX register and is processor specific.
//
// Register EAX value = 01h :
//
// The processor returns the following information :
//
//  1. EAX - Model, Family and stepping information for the current central processing unit
//  2. EBX :
//
//      1. Brand index ( low byte of EBX ) - 
//
// Register EAX valus is 0x00000002 : 
//
//  The processor returns information about the processor internal translation lookaside buffers, cache and prefetch hardware. The least 
//  significant byte in the EAX part of the RAX register will always have the value 0x00000001. Software should ignore this value. The 
//  most significant bit of each register indicates whether the register contains valid information ( set to 0 ) or is reserved ( set to 1 ).
//  If a regsiter contains valid information, the information is contained in 1 byte descriptors. There are four types of encoding values for
//  the byte descriptor. The order of descriptors in the regsiters EAX, EBX, ECX and EDX is not defined. Also a processor may report a general 
//  descriptor type ( 0x000000FF ) and not report any byte descriptor of "cache type" 



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
class Identification NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Identification;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
	// or some functionality needed that does not involve the non static data members


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to obtain the central processing unit vendor identification string
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
    //      A constant reference to the central processing unit vendor identification string
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline const Language::String& VendorIdentificationString();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to obtain the central processing unit stepping identification
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
    //      The central processing unit steeping identification
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline UnsignedInteger32bits SteppingIdentification();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to obtain the central processing unit model
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
    //      The central processing unit model
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline UnsignedInteger32bits Model();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to obtain the central processing unit family 
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
    //      The central processing unit family
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline UnsignedInteger32bits Family();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to obtain the central processing unit type. The 4 possibilites are :
    //
    //          1. Original OEM Processor - 00
    //          2. Intel OverDrive Processor - 01
    //          3. Dual processor - 10
    //          4. Intel reserved - 11
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
    //      The central processing unit type
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline UnsignedInteger32bits Type();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to obtain the central processing unit extended model identification. This value is only valid when the family identification
    //      is 0x0F
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
    //      The central processing unit extended model identification
    //
    //  Expectations :
    //
    //      1. The family identification value is 0x0F
    //      2.
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline UnsignedInteger32bits ExtendedModelIdentification();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to obtain the central processing unit extended family identification. This value is only valid when the family identification
    //      is 0x06 or 0x0F
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
    //      The central processing unit extended family identification
    //
    //  Expectations :
    //
    //      1. The family identification value is 0x06 or 0x0F
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline UnsignedInteger32bits ExtendedFamilyIdentification();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to obtain the central processing unit brand index. This number provides an entry into a brand string table that
    //      contains brand strings for Intel processors
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
    //      The central processing unit brand index
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline UnsignedInteger32bits BrandIndex();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to obtain the central processing unit cache line size in bytes
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
    //      The central processing unit cache line size in bytes
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline UnsignedInteger32bits CacheLineSize();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to obtain the maximum number of addressable identifications for logical processors in this package
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
    //      The maximum number of addressable identifications for logical processors in this package
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline UnsignedInteger32bits MaximumNumberOfAddressableIdentificationsForLogicalProcessorsInThisPackage();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to obtain the central processing unit local advanced programmable interrupt controller ( APIC ) identification. This 8 bit identification
    //      is assigned to the local advanced programmable interrupt controller unit on the processor during power up
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
    //      The central processing unit local advanced programmable interrupt controller identification
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline UnsignedInteger32bits LocalAdvancePprogrammableInterruptControlleridentification();


    // The following methods provide the central processing unit feature information :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the streaming SIMD extensions 3 ( SSE3 ) feature.
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
    //      1. true - if the central processing unit supports the streaming SIMD extensions 3 feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean StreamingSimdExtensions3();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the carryless multiplication ( PCLMULQDQ ) feature
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
    //      1. true - if the central processing unit supports carryless multiplication
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean CarrylessMultiplication();      
    

    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the 64 bits debug store area ( DTES64 ) feature
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
    //      1. true - if the central processing unit supports the 64 bits debug store area feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean DebugStoreArea64bits();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the monitor ( MONITOR/MWAIT ) feature
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
    //      1. true - if the central processing unit supports the monitor feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean Monitor();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the CPL qualified debug store ( DS-CPL ) feature. This allows for
    //      branch message storage qualified by CPL
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
    //      1. true - if the central processing unit supports the CPL qualified debug store feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean CplQualifiedDebugStore();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the virtual machine extensions ( VMX ) feature
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
    //      1. true - if the central processing unit supports the virtual machine extensions feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean VirtualMachineExtensions();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the safer mode extensions ( SMX ) feature
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
    //      1. true - if the central processing unit supports the safer mode extensions feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean SaferModeExtensions();     


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the enhanced speed step ( EIST ) feature
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
    //      1. true - if the central processing unit supports the enhanced speed step feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean EnhancedSpeedStep();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support second thermal monitor ( TM2 ) feature
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
    //      1. true - if the central processing unit supports second thermal monitor feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean SecondThermalMonitor();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the supplemental streaming SIMD extensions 3 ( SSSE3 ) feature
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
    //      1. true - if the central processing unit supports the supplemental streaming SIMD extensions 3 feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean SupplementalStreamingSimdExtensions3();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the layer 1 context identification ( CNXT-ID ) feature. This allows
    //      to set the layer 1 data cache to either adaptive mode or shared mode
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
    //      1. true - if the central processing unit supports the layer 1 context identification feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean Layer1ContextIdentification();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the IA32_DEBUG_INTERFACE MSR silicon debug ( SDBG ) feature
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
    //      1. true - if the central processing unit supports the IA32_DEBUG_INTERFACE MSR silicon debug feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean SiliconDebug();     


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the fused multiply add ( FMA ) feature, using the YMM state
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
    //      1. true - if the central processing unit supports the fused multiply add feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean FuseMultiplyAdd();     


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the CMPXCHG16B feature
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
    //      1. true - if the central processing unit supports the CMPXCHG16B feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean CMPXCHG16B();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the xTPR update control feature. This allows to change in the processor
    //      the IA32_MISC_ENABLE[bit 23]
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
    //      1. true - if the central processing unit supports the xTPR update control feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean xPtrUpdateControl();     


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the Performance/Debug capability MSR ( PDCM ) feature. The indication
    //      is in MSR IA_32_PERF_CAPABILITIES
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
    //      1. true - if the central processing unit supports the Performance/Debug capability MSR feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean PerformanceDebugCapabilityMSR();     


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the process context identifiers ( PCID ) feature. This allows
    //      software to set the CR4.PCIDE to 1
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
    //      1. true - if the central processing unit supports the process context identifiers feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean ProcessContextIdentifiers();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the direct cache access ( DCA ) feature. This allows to prefetch data
    //      from a memory mapped device
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
    //      1. true - if the central processing unit supports the direct cache access feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean DirectCacheAccess();     


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the streaming SIMD extensions 4.1 ( SSE4.1 ) feature
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
    //      1. true - if the central processing unit supports the streaming SIMD extensions 4.1 feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean StreamingSimdExtensions4_1();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the streaming SIMD extensions 4.2 ( SSE4.2 ) feature
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
    //      1. true - if the central processing unit supports the streaming SIMD extensions 4.2 feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean StreamingSimdExtensions4_2();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support a second advanced programmable interrupt controller ( x2APIC ) feature
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
    //      1. true - if the central processing unit supports a second advanced programmable interrupt controller feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean SecondAdvancedProgrammableInterruptController();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the MOVBE feature
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
    //      1. true - if the central processing unit supports the MOVBE feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean MOVBE();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the POPCNT feature
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
    //      1. true - if the central processing unit supports the POPCNT feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean POPCNT();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the TSC deadline feature. This means that the local advanced programmable 
    //      interrupt controller timer supports one shot operations using a TSC deadline value
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
    //      1. true - if the central processing unit supports the TSC deadline feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean TscDeadline();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the AES feature
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
    //      1. true - if the central processing unit supports the AES feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean AES();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the XSAVE feature. This means that the processor supports the
    //      XSAVE/XRSTOR processor extended states featrue, the XSETBV/XGETBV instructions and  XCR0
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
    //      1. true - if the central processing unit supports the XSAVE feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean XSAVE();        


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the OSXSAVE feature. This means that the operating system has set
    //      CR4.OSXSAVE[bit 18 ] to enable XSWETBV/XGETBV instructions to access XCR0 and to support processor extended state managment using
    //      XSAVE/XRSTOR
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
    //      1. true - if the central processing unit supports the OSXSAVE feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean OSXSAVE();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the AVX feature
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
    //      1. true - if the central processing unit supports the AVX feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean AVX();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the 16 bit floating point conversion ( F16C ) feature
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
    //      1. true - if the central processing unit supports the 16 bit floating point conversion feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean FloatingPointConversion16bit();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the RDRAND feature
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
    //      1. true - if the central processing unit supports the RDRAND feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean RDRAND();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the floating point unit on chip ( x87 FPU ) feature
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
    //      1. true - if the central processing unit supports the floating point unit on chip feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean x87FloatingPointUnitOnChip();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the virtual 8086 mode enhancement ( VME ) feature. This include CR4.VME
    //      for controlling the feature, CR4.PVI for prot4ected mode virtual interrupts, software interrupt indirection, expansion of the TSS with
    //      the software indirection bitmap, and EFLAGS.VIF and EFLAGS.VIP flags
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
    //      1. true - if the central processing unit supports virtual 8086 mode enhancement feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean Virtual8086ModeEnhancement();        
    

    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the debugging extensions ( DE ) feature. This allows support
    //      for the input/output breakpoints, including CR4.DE for controlling the feature, and optional trapping of accesses to DR4 an DR5
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
    //      1. true - if the central processing unit supports the debugging extensions feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean DebuggingExtensions();   


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the page size extensions ( PSE ) feature. Large pages of size 4MB
    //      are supported, including CR4.PSE for controlling the feature, the defined dirty bit in the page directory entris ( PDE ), optional 
    //      reserved bit trapping in CR3, page directory entries and PTEs
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
    //      1. true - if the central processing unit supports the page size extensions feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean PageSizeExtensions();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the time stamp counter ( TSC ) feature. Ths RDTSC instruction
    //      is supported, including CR4.TSD for controlling privilege
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
    //      1. true - if the central processing unit supports the time stamp counter feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean TimeStampCounter();    


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the RDMSR and WRMSR ( MSR ) feature. This means that the model
    //      specific registers RDMSR and ERMSR instructions are supported. Some of the MSRs are implementataion dependent
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
    //      1. true - if the central processing unit supports the RDMSR and WRMSR feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean RDMSRandWRMSR();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the physical address extensions ( PAE ) feature. Physical addresses
    //      greater than 32 bits are supported. Extended page table entry formats, an extra level in the page translation tables is defined, 2MB 
    //      pages are supported instead of 4MB pages if PAE global bit is 1
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
    //      1. true - if the central processing unit supports the physical address extensions feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean PhysicalAddressExtensions();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the machine check exception ( MCE ) feature
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
    //      1. true - if the central processing unit supports the machine check exception feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean MachineCheckException();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support CMPXCHG8B ( CX8 ) feature
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
    //      1. true - if the central processing unit supports CMPXCHG8B feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean CMPXCHG8B();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the advanced programmable interrupt controller on chip ( APIC ) feature. 
    //      The processor contains an advanced programmable interrupt controller, responding to memory mapped commands in the physical address range 
    //      0xFFFE0000 to 0xFFFE0FFF ( by default - some processors permit this unit to be relocated )
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
    //      1. true - if the central processing unit supports the advanced programmable interrupt controller on chip feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean AdvancedProgrammableInterruptController();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the SYSENTER and SYSEXIT ( SEP ) feature
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
    //      1. true - if the central processing unit supports the SYSENTER and SYSEXIT feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean SYSENTERandSYSEXIT();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the memory type range registers ( MTRR ) feature. The MTRRcap MSR
    //      contains feature bits that describe what memory types are supported, how many variable MTRRs are supported, and whether fixed MTRRs
    //      are supported
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
    //      1. true - if the central processing unit supports the memory type range registers feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean MemoryTypeRangeRegisters();     


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the PTE global bit ( PGE ) feature. The global bit is supported 
    //      in paging structure entries that map a page, including TLB entries that are common to different processes and need not be flushed.
    //      The CR4.PGE bit controls this feature
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
    //      1. true - if the central processing unit supports the PTE global bit feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean PteGlobalBit();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the machine check architecture ( MCA ) feature. This is used to 
    //      report machine errors. The MCG_CAP_MSR contains feature bits describing how many banks of error reporting MSRs are supported
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
    //      1. true - if the central processing unit supports the machine check architecture feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean MachineCheckArchitecture();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the conditional move/compare instructions ( CMOV ) feature. In addition,
    //      if x87 floating point unit is present, then the FCOMI and FCMOV instructions are supported
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
    //      1. true - if the central processing unit supports the conditional move/compare instructions feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean ConditionalMoveAndCompareInstructions();     


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the page attribute table ( PAT ) feature This feature augments the
    //      memory type range registers, allowing an operating system to specifiy attributes of memory accessed through a linear address on a 
    //      4KB granularity
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
    //      1. true - if the central processing unit supports the page attribute table feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean PageAttributeTable();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the page size extension ( PSE-36 ) feature. 4MB pages addressing
    //      physical memory beyond 4GB are supportd with 32 bit paging. This feature indicates that upper bits of the physical address of a 
    //      4MB page are encoded in bits 13-20 of the page directory enttry. Such physical addresses are limited by MAXPHYADDR and may be up
    //      to 40 bits in size
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
    //      1. true - if the central processing unit supports the page size extension feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean PageSizeExtension();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the processor serial number ( PSN ) feature. The serial number
    //      is 96 bit long
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
    //      1. true - if the central processing unit supports the processor serial number feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean ProcessorSerialNumber();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the CLFLUSH ( CLFSH ) feature
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
    //      1. true - if the central processing unit supports the CLFLUSH feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean CLFLUSH();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the debug store ( DS ) feature. The processor supports the ability
    //      to write debug information into a memory resident buffer. This feature is used by the branch trace store ( BTS ) and precise event
    //      based sampling ( PEBS ) facilities
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
    //      1. true - if the central processing unit supports the debug store feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean DebugStore();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the thermal monitor and clock control ( ACPI ) feature. The processor
    //      implements internal MSRs that allow processor temperature to be monitored and processor performance to be modulated in predefined duty
    //      cycles under software control
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
    //      1. true - if the central processing unit supports the thermal monitor and clock control feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean ThermalMonitorAndClockControl();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support a MMX feature
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
    //      1. true - if the central processing unit supports a MMX feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean MMX();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the FXSAVE and FXRSTOR ( FXSR ) feature. This instructions are supported
    //      for fast save and restore of the floating point context. Presence of this bit also indicates that CR4.OSFXSR is available for an operating
    //      system to indicate that it supports the FXSAVE and FXRSTOR instructions
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
    //      1. true - if the central processing unit supports the FXSAVE and FXRSTOR feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean FXSAVEandFXRSTOR();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the streaming SIMD extensions ( SSE ) feature
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
    //      1. true - if the central processing unit supports the streaming SIMD extensions feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean StreamingSimdExtensions();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the streaming SIMD extensions 2 ( SSE2 ) feature
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
    //      1. true - if the central processing unit supports the streaming SIMD extensions 2 feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean StreamingSimdExtensions2();       


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the self snoop ( SS ) feature. The procssor supports the managment
    //      of conflicting memory types by performing a snoop of its own cache structure for transactions issued to the bus
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
    //      1. true - if the central processing unit supports the self snoop feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean SelfSnoop();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the multi threading ( HTT ) feature. A value of 0, indicates there is only a 
    //      single logical processor in the package and software should assume only a single advanced programmable interrupt controller identification is
    //      reserved. A value of 1 indicates the value in CPUID.1.EBX[23:16] ( the maximum number of addressable identifications for logical processors in
    //      this package ) is valid for the package
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
    //      1. true - if the central processing unit supports the multi threading feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean MultiThreading();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the thermal monitor ( TM ) feature. The processor implements the thermal
    //      monitor automatic thermal control circutry ( TCC )
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
    //      1. true - if the central processing unit supports the thermal monitor feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean ThermalMonitor();      


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to check if the central processing unit support the PBE ( Pend. Brk. En. ) feature. The processor supports the use
    //      of the FERR#/PBE# pin when the processor is in the stop clock state ( STPCLK# is asserted ) to signal processor that an interrupt is 
    //      pending and that the processor should return to normal operation to handle the interrupt. Bit 10 in the IA32_MISC_ENABLE MSR enables
    //      this capability
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
    //      1. true - if the central processing unit supports the PBE feature
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Boolean PBE();


    // The following methods provide the central processing unit information on processor internal translation lookaside buffers, cache and prefetch
    // in hardware :


    // Method Information :
    //
    //  Description :
    //
    //		Use this method to get a constant reference to an object that contains all the identification information on translation lookaside buffers
    //		of the central processing unit
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
    //		A constant reference to an object that contains all the identification information on translation lookaside buffers
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    // EnsureRetrunValueIsUsed static inline const TranslationLookasideBuffersIdentification& TranslationLookasideBuffers();


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
	NoInstances( Identification );


	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the
	// start of the program and only destroyed when the program ends. The access to the static member is bound to this object of course


    // This object will store the number of valid values the CPUID assembly function can be called with, for EAX register
    static LargestUnsignedInteger member_Basic_EAX_valuesMaximum;

    // This object will store all the information the 'CPUID' can return. Each activation of the 'CPUID' can at maximum return information in
    // 4 registers of 32 bits. This also only contain basic information where ECX part of the RCX register is always set to 0
    static Memory::Vector< Memory::Array< UnsignedInteger32bits, 4UL > > member_centralProcessingUnitBasicInformation;

    // This object will store the vendor identification string, it can contain at most 12 characters
    static Language::String member_vendorIdentificationString;

    // This will decode the information from the CPUID instruction regarding the translation lookaside buffer and store it
    //static TranslationLookasideBuffersIdentification member_translationLookasideBuffersIdentification;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to invoke the 'CPUID' assembly instruction and return the number of leafs the current central processing unit supports.
    //		In other words, this method will return the maximum value that the EAX register can be used to invoke the 'CPUID' instruction and it
    //		will return valid information describing the central processing unit
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
    //      The number of leafs the current central processing unit supports
    //
    //  Expectations :
    //
    //      1. The current central processing unit belongs to 'Intel'
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline LargestUnsignedInteger GetMaximumValueForBasicInformation__Private();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to invoke the 'CPUID' assembly instruction for all the values that represent basic information on the cetnral processing
    //		unit, store them into a heap array and return a copy of it
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
    //      A heap array with the basic information on the central processing unit
    //
    //  Expectations :
    //
    //      1. The current central processing unit belongs to 'Intel'
    //		2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline Memory::Vector< Memory::Array< UnsignedInteger32bits, 4UL > > GetBasicInformation__Private();


    // Method Information :
    //
    //  Description :
    //
    //      Use this method the set the EAX part of the register RAX, and when needed also the ECX part of the RCX register, and then invoke the
    //      'CPUID' assembly instruction to obtain the required information and set it into the required memory address
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. set_EAX_toThisValue - this value will be used to set the EAX part of the RAX register
    //          2. memoryAddressToStoreTheInformation - this memory address will store the information returned by invoking 'CPUID'
    //          3. set_ECX_toThisValue - this value will be used to set the ECX part of the RCX register
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
    //      1. The given value to set the EAX part of the RAX register is in the allowed value
    //      2. The given value to set the ECX part of the RCX register is in the allowed value
    //      3. ECX should be used only for the correct values of EAX that the 'CPUID' instruction requires more information
    //      4. The given pointer to the memory address is not NULL
    //      5. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    static inline void InvokeCpuidAssemblyInstructionAndStoreTheResultToTheMemoryAddress__Private( const UnsignedInteger32bits set_EAX_toThisValue, UnsignedInteger32bits* const memoryAddressToStoreTheInformation, const UnsignedInteger32bits set_ECX_toThisValue = 0 );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to extract the vendor identification string from the basic information
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
    //      A string instance with the vendor identification string
    //
    //  Expectations :
    //
    //		NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline const Language::String ExtractVendorIdentificationString__Private();


};  //  Class Identification