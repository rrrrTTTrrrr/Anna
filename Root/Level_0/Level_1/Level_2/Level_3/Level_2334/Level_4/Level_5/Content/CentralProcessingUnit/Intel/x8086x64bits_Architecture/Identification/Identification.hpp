#ifndef IDENTIFICATION_HPP
#define IDENTIFICATION_HPP


#include "../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../Content/Memory/SequentialPlatforms/Array/Array.hpp"  //  Class Array
#include "../../../../../../Content/Memory/SequentialPlatforms/DynamicArray/DynamicArray.hpp"  //  Class DynamicArray
#include "TranslationLookasideBuffersIdentification/TranslationLookasideBuffersIdentification.hpp"  //  Class TranslationLookasideBuffersIdentification
#include "../../../../../../../../../../ObjectBranch/Level_0/Content/Abilities/InitializeStaticArrayUsingMethod/InitializeStaticArrayUsingMethod.hpp"  //  Class InitializeStaticArrayUsingMethod


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
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
		class Identification NotForInheritance
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
			inline Identification();


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
			inline Identification( const Identification& other );


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
			ObjectInfrastructure_MACRO( Identification )


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
			inline void Swap( Identification& other );


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
			inline void Initiate();


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
			inline ~Identification() = default;


			// The following methods give access and manipulate the data inside this object :


	        // The following methods provide the central processing unit version information :


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
            //      A pointer to the central processing unit vendor identification string
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            // inline const AsciiCharacter* VendorIdentificationString() const;


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
	        inline UnsignedInteger32bits SteppingIdentification() const;


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
	        inline UnsignedInteger32bits Model() const;


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
	        inline UnsignedInteger32bits Family() const;


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
	        inline UnsignedInteger32bits Type() const;


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
	        inline UnsignedInteger32bits ExtendedModelIdentification() const;


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
	        inline UnsignedInteger32bits ExtendedFamilyIdentification() const;


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
	        inline UnsignedInteger32bits BrandIndex() const;


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
	        inline UnsignedInteger32bits CacheLineSize() const;


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
	        inline UnsignedInteger32bits MaximumNumberOfAddressableIdentificationsForLogicalProcessorsInThisPackage() const;


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
	        inline UnsignedInteger32bits LocalAdvancePprogrammableInterruptControlleridentification() const;


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
	        inline Boolean StreamingSimdExtensions3() const;      


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
	        inline Boolean CarrylessMultiplication() const;      
	        

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
	        inline Boolean DebugStoreArea64bits() const;      


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
	        inline Boolean Monitor() const;      


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
	        inline Boolean CplQualifiedDebugStore() const;       


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
	        inline Boolean VirtualMachineExtensions() const;       


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
	        inline Boolean SaferModeExtensions() const;     


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
	        inline Boolean EnhancedSpeedStep() const;      


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
	        inline Boolean SecondThermalMonitor() const;      


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
	        inline Boolean SupplementalStreamingSimdExtensions3() const;      


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
	        inline Boolean Layer1ContextIdentification() const;      


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
	        inline Boolean SiliconDebug() const;     


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
	        inline Boolean FuseMultiplyAdd() const;     


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
	        inline Boolean CMPXCHG16B() const;      


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
	        inline Boolean xPtrUpdateControl() const;     


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
	        inline Boolean PerformanceDebugCapabilityMSR() const;     


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
	        inline Boolean ProcessContextIdentifiers() const;      


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
	        inline Boolean DirectCacheAccess() const;     


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
	        inline Boolean StreamingSimdExtensions4_1() const;      


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
	        inline Boolean StreamingSimdExtensions4_2() const;      


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
	        inline Boolean SecondAdvancedProgrammableInterruptController() const;      


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
	        inline Boolean MOVBE() const;       


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
	        inline Boolean POPCNT() const;      


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
	        inline Boolean TscDeadline() const;      


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
	        inline Boolean AES() const;      


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
	        inline Boolean XSAVE() const;        


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
	        inline Boolean OSXSAVE() const;       


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
	        inline Boolean AVX() const;       


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
	        inline Boolean FloatingPointConversion16bit() const;      


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
	        inline Boolean RDRAND() const;       


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
	        inline Boolean x87FloatingPointUnitOnChip() const;       


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
	        inline Boolean Virtual8086ModeEnhancement() const;        
	        

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
	        inline Boolean DebuggingExtensions() const;   


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
	        inline Boolean PageSizeExtensions() const;      


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
	        inline Boolean TimeStampCounter() const;    


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
	        inline Boolean RDMSRandWRMSR() const;       


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
	        inline Boolean PhysicalAddressExtensions() const;       


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
	        inline Boolean MachineCheckException() const;      


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
	        inline Boolean CMPXCHG8B() const;       


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
	        inline Boolean AdvancedProgrammableInterruptController() const;       


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
	        inline Boolean SYSENTERandSYSEXIT() const;      


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
	        inline Boolean MemoryTypeRangeRegisters() const;     


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
	        inline Boolean PteGlobalBit() const;       


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
	        inline Boolean MachineCheckArchitecture() const;      


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
	        inline Boolean ConditionalMoveAndCompareInstructions() const;     


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
	        inline Boolean PageAttributeTable() const;      


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
	        inline Boolean PageSizeExtension() const;       


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
	        inline Boolean ProcessorSerialNumber() const;      


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
	        inline Boolean CLFLUSH() const;      


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
	        inline Boolean DebugStore() const;       


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
	        inline Boolean ThermalMonitorAndClockControl() const;       


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
	        inline Boolean MMX() const;      


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
	        inline Boolean FXSAVEandFXRSTOR() const;       


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
	        inline Boolean StreamingSimdExtensions() const;      


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
	        inline Boolean StreamingSimdExtensions2() const;       


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
	        inline Boolean SelfSnoop() const;      


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
	        inline Boolean MultiThreading() const;      


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
	        inline Boolean ThermalMonitor() const;      


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
	        inline Boolean PBE() const;


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
	        inline const TranslationLookasideBuffersIdentification& TranslationLookasideBuffers() const;


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
			inline Boolean operator==( const Identification& other ) const;


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
			inline Boolean operator!=( const Identification& other ) const;


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
			// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
			// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


			// DEBUG_TOOL(

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

			// )  //  End of debug tool


		private:


			// This object will be used to monitor the state of each instance
			InstanceState member_state;

            // This constant expression will be used to determine the amount of values for EAX part of the RAX register the current central processing 
            // unit supports to obtain basic information
            UnsignedInteger64bits member_Basic_EAX_valuesMaximum;

            // This object will store all the information the 'CPUID' can return. Each activation of the 'CPUID' can at maximum return information in
            // 4 registers of 32 bits. This also only contain basic information where ECX part of the RCX register is always set to 0
            Memory::DynamicArray< Memory::Array< UnsignedInteger32bits, 4 > > member_centralProcessingUnitBasicInformation;

            // This will decode the information from the CPUID instruction regarding the translation lookaside buffer and store it
            TranslationLookasideBuffersIdentification member_translationLookasideBuffersIdentification;


			// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program
			// and only destroyed when the program ends. The access to the static member is bound to this object of course


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


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
	        inline UnsignedInteger64bits GetMaximumValueForBasicInformation__Private();


	        // Method Information :
	        //
	        //  Description :
	        //
	        //      Use this method to invoke the 'CPUID' assembly instruction for all the values that represent basic information on the cetnral processing
	        //		unit, store them into a dynamic array and return a copy of it
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
	        //      A dynamic array with the basic information on the central processing unit
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
	        inline Memory::DynamicArray< Memory::Array< UnsignedInteger32bits, 4 > > GetBasicInformation__Private();


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
            //          2. memoryAddressToStoreTheInformation - this memory address will be set with the information returned by the invoking the 'CPUID'
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
            inline void InvokeCPUIDandStoreTheResultToTheMemoryAddress__Private( UnsignedInteger32bits set_EAX_toThisValue, UnsignedInteger32bits* memoryAddressToStoreTheInformation, UnsignedInteger32bits set_ECX_toThisValue = 0 );


			// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
			// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
			// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
			// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
			// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
			// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


		};  //  Class Identification




































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
		inline Identification::Identification() :
		member_state( InstanceState::Ready ),
        member_Basic_EAX_valuesMaximum( GetMaximumValueForBasicInformation__Private() ),
        member_centralProcessingUnitBasicInformation( MOVE( GetBasicInformation__Private() ) ),
        member_translationLookasideBuffersIdentification( &member_centralProcessingUnitBasicInformation[2][0] )
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
		inline Identification::Identification( const Identification& other ) :
		member_state( other.member_state ),
		member_Basic_EAX_valuesMaximum( other.member_Basic_EAX_valuesMaximum ),
		member_centralProcessingUnitBasicInformation( other.member_centralProcessingUnitBasicInformation ),
		member_translationLookasideBuffersIdentification( other.member_translationLookasideBuffersIdentification )
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
		void Identification::Swap( Identification& other )
		{
		    // Swap betwen the state instances
		    member_state.Swap( other.member_state );

		    // Swap between the basic maximum value for the EAX part of the RAX register
		    Memory::Operations::Swap< UnsignedInteger64bits >( member_Basic_EAX_valuesMaximum, other.member_Basic_EAX_valuesMaximum );

		    // Swap between the dynamic arrays with the basic information
		    member_centralProcessingUnitBasicInformation.Swap( other.member_centralProcessingUnitBasicInformation );

		    // Swap between the translation lookaside buffers information
		    member_translationLookasideBuffersIdentification.Swap( other.member_translationLookasideBuffersIdentification );
		}



        // The following methods provide the central processing unit version information :


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
        //      A pointer to the central processing unit vendor identification string
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        // inline const AsciiCharacter* Identification::VendorIdentificationString() const
        // {
        //     // To acquire the central processing unit vendor identification string the 'CPUID' needs to be started with :
        //     //
        //     //      EAX = 0
        //     //      ECX - Non relevant
        //     //
        //     // And the result will be stored in the registers EBX, ECX and EDX

        //     // This object will be declared static to allow it to continue existing during the all process run. It will store the central processing
        //     // unit vendor identification string. The function that is required for intializing this array is provided as lambda expression 
        //     static const Abilities::InitializeStaticArrayUsingMethod< AsciiCharacter, 13 > vendorIdentificationString( [ this ]( AsciiCharacter* vendorIdentificationStringMemoryAddress, UnsignedInteger64bits ) -> void
        //     {

        //         // Set the four first ascii characters
        //         *( reinterpret_cast< UnsignedInteger32bits* >( vendorIdentificationStringMemoryAddress ) ) = member_centralProcessingUnitBasicInformation[0][1];

        //         // Set the four second ascii characters
        //         *( reinterpret_cast< UnsignedInteger32bits* >( vendorIdentificationStringMemoryAddress ) + 1 ) = member_centralProcessingUnitBasicInformation[0][3];

        //         // Set the four last ascii characters
        //         *( reinterpret_cast< UnsignedInteger32bits* >( vendorIdentificationStringMemoryAddress ) + 2 ) = member_centralProcessingUnitBasicInformation[0][2];                

        //     } );

        //     // Return the address of the central processing unit vendor identification string
        //     return ( vendorIdentificationString );
        // }


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
        inline UnsignedInteger32bits Identification::SteppingIdentification() const
        {
            // To obtain version information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EAX part of the RAX register, in bits with indexes 0-3 

            // Return the stepping identification by performing the and operation ( & ), between the entry that describes the required information
            // and a value that will set all the other bits, excpt of the stepping identification part, to 0
            return ( member_centralProcessingUnitBasicInformation[1][0] & 0x0000000F );
        }


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
        inline UnsignedInteger32bits Identification::Model() const
        {
            // To obtain version information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EAX part of the RAX register, in bits with indexes 4-7 

            // Return the model by performing the and operation ( & ), between the entry that describes the required information and a value that will 
            // set all the other bits, excpt of the model part, to 0. Finally right shift the bits to the beginning of the register so it could be read
            // as an integer
            return ( ( member_centralProcessingUnitBasicInformation[1][0] & 0x000000F0 ) >> 4 );
        }


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
        inline UnsignedInteger32bits Identification::Family() const
        {
            // To obtain version information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EAX part of the RAX register, in bits with indexes 8-11 

            // Return the family by performing the and operation ( & ), between the entry that describes the required information and a value that will 
            // set all the other bits, excpt of the family part, to 0. Finally right shift the bits to the beginning of the register so it could be read
            // as an integer
            return ( ( member_centralProcessingUnitBasicInformation[1][0] & 0x00000F00 ) >> 8 );
        }


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
        inline UnsignedInteger32bits Identification::Type() const
        {
            // To obtain version information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EAX part of the RAX register, in bits with indexes 12-13 

            // Return the type by performing the and operation ( & ), between the entry that describes the required information and a value that will 
            // set all the other bits, excpt of the type part, to 0. Finally right shift the bits to the beginning of the register so it could be read
            // as an integer
            return ( ( member_centralProcessingUnitBasicInformation[1][0] & 0x00003000 ) >> 12 );
        }


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
        inline UnsignedInteger32bits Identification::ExtendedModelIdentification() const
        {
            // To obtain version information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EAX part of the RAX register, in bits with indexes 16-19 

            // The extended family identification is only valid when the family identification is 0x0F
            Assert_MACRO( ( Family() == 0x0000000F ), "CentralProcessingUnit::Identification::ExtendedModelIdentification failed - the extended model identification is only valid for the family identification 0x0F - the Pentium 4 processir family" )

            // Return the type by performing the and operation ( & ), between the entry that describes the required information and a value that will 
            // set all the other bits, excpt of the type part, to 0. Finally right shift the bits to the beginning of the register so it could be read
            // as an integer
            return ( ( member_centralProcessingUnitBasicInformation[1][0] & 0x000F0000 ) >> 16 );
        }


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
        inline UnsignedInteger32bits Identification::ExtendedFamilyIdentification() const
        {
            // To obtain version information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EAX part of the RAX register, in bits with indexes 20-27 

            // The extended family identification is only valid when the family identification is 0x06 or 0x0F
            Assert_MACRO( ( ( Family() == 0x00000006 ) || ( Family() == 0x0000000F ) ), "CentralProcessingUnit::Identification::ExtendedFamilyIdentification failed - the extended model identification is only valid for the family identification 0x0F or 0x06 - the Pentium 4 processir family" )

            // Return the type by performing the and operation ( & ), between the entry that describes the required information and a value that will 
            // set all the other bits, excpt of the type part, to 0. Finally right shift the bits to the beginning of the register so it could be read
            // as an integer
            return ( ( member_centralProcessingUnitBasicInformation[1][0] & 0x0FF00000 ) >> 20 );
        }


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
        inline UnsignedInteger32bits Identification::BrandIndex() const
        {
            // To obtain version information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the low significant byte of the EBX part of the RBX register

            // Return the brand index by performing the and operation ( & ), between the entry that describes the required information and a value that will 
            // set all the other bits, excpt of the brand index part at the lowest significant byte, to 0
            return ( member_centralProcessingUnitBasicInformation[1][1] & 0x000000FF );
        }


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
        inline UnsignedInteger32bits Identification::CacheLineSize() const
        {
            // To obtain version information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the second low significant byte of the EBX part of the RBX register

            // Return the brand index by performing the and operation ( & ), between the entry that describes the required information and a value that will 
            // set all the other bits, excpt of the brand index part at the lowest significant byte, to 0. Finally right shift the bits to the beginning of 
            // the register so it could be read as an integer
            return ( ( member_centralProcessingUnitBasicInformation[1][1] & 0x0000FF00 ) >> 8 );
        }


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
        inline UnsignedInteger32bits Identification::MaximumNumberOfAddressableIdentificationsForLogicalProcessorsInThisPackage() const
        {
            // To obtain version information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the third low significant byte of the EBX part of the RBX register

            // Return the maximum number of addressable identifications for logical processors in this package by performing the and operation ( & ), between 
            // the entry that describes the required information and a value that will set all the other bits, excpt of the maximum number of addressable 
            // identifications for logical processors in this package part at the lowest significant byte, to 0. Finally right shift the bits to the beginning 
            // of the register so it could be read as an integer
            return ( ( member_centralProcessingUnitBasicInformation[1][1] & 0x00FF0000 ) >> 16 );
        }


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
        inline UnsignedInteger32bits Identification::LocalAdvancePprogrammableInterruptControlleridentification() const
        {
            // To obtain version information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the highest significant byte of the EBX part of the RBX register

            // Return the local advanced programmable interrupt controller identification by performing the and operation ( & ), between the entry that 
            // describes the required information and a value that will set all the other bits, except of the local advanced programmable interrupt 
            // controller part at the highest significant byte, to 0. Finally right shift the bits to the beginning of the register so it could be read 
            // as an integer
            return ( ( member_centralProcessingUnitBasicInformation[1][1] & 0xFF000000 ) >> 24 );
        }


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
        inline Boolean Identification::StreamingSimdExtensions3() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 0 

            // Return if the central processing unit supports the streaming SIMD extensions 3 feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 0
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000001 );
        }        


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
        inline Boolean Identification::CarrylessMultiplication() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 1

            // Return if the central processing unit supports carryless multiplication by performing the and operation ( & ), between the entry 
            // that describes the required information and a value with only one bit ON in the bit with index 1
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000002 );
        }        
        

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
        inline Boolean Identification::DebugStoreArea64bits() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 2

            // Return if the central processing unit supports the 64 bit debug store area feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 2
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000004 );
        }        


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
        inline Boolean Identification::Monitor() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 3 

            // Return if the central processing unit supports the monitor feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 3
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000008 );
        }        


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
        inline Boolean Identification::CplQualifiedDebugStore() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 4 

            // Return if the central processing unit supports the CPL qualified debug store feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 4
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000010 );
        }        


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
        inline Boolean Identification::VirtualMachineExtensions() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 5 

            // Return if the central processing unit supports the virtual machine extensions feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 5
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000020 );
        }        


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
        inline Boolean Identification::SaferModeExtensions() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 6

            // Return if the central processing unit supports the safer mode extensions feature by performing the and operation ( & ), between the 
            // entry that describes the required information and a value with only one bit ON in the bit with index 6
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000040 );
        }        


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
        inline Boolean Identification::EnhancedSpeedStep() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 7

            // Return if the central processing unit supports the enhanced speed step feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 7
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000080 );
        }        


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
        inline Boolean Identification::SecondThermalMonitor() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 8

            // Return if the central processing unit supports second thermal monitor feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 8
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000100 );
        }        


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
        inline Boolean Identification::SupplementalStreamingSimdExtensions3() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 9

            // Return if the central processing unit supports the supplemental streaming SIMD extensions 3 supplemental streaming SIMD extensions
            // 3 feature by performing the and operation ( & ), between the entry that describes the required information and a value with only 
            // one bit ON in the bit with index 9
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000200 );
        }        


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
        inline Boolean Identification::Layer1ContextIdentification() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 10

            // Return if the central processing unit supports the layer 1 context identification feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 10
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000400 );
        }        


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
        inline Boolean Identification::SiliconDebug() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 11 

            // Return if the central processing unit supports the IA32_DEBUG_INTERFACE MSR silicon debug feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 11
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00000800 );
        }        


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
        inline Boolean Identification::FuseMultiplyAdd() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 12 

            // Return if the central processing unit supports the fused multiply add feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 12
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00001000 );
        }        


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
        inline Boolean Identification::CMPXCHG16B() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 13 

            // Return if the central processing unit supports the CMPXCHG16B feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 13
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00002000 );
        }        


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
        inline Boolean Identification::xPtrUpdateControl() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 14 

            // Return if the central processing unit supports the xTPR update control feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 14
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00004000 );
        }        


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
        inline Boolean Identification::PerformanceDebugCapabilityMSR() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 15 

            // Return if the central processing unit supports the Performance/Debug capability MSR feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 15
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00008000 );
        }        


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
        inline Boolean Identification::ProcessContextIdentifiers() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 17

            // Return if the central processing unit supports the process context identifiers feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 17
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00020000 );
        }        


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
        inline Boolean Identification::DirectCacheAccess() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 18

            // Return if the central processing unit supports the direct cache access feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 18
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00040000 );
        }        


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
        inline Boolean Identification::StreamingSimdExtensions4_1() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 19

            // Return if the central processing unit supports the streaming SIMD extensions 4.1 feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 19
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00080000 );
        }        


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
        inline Boolean Identification::StreamingSimdExtensions4_2() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 20

            // Return if the central processing unit supports the streaming SIMD extensions 4.2 feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 20
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00100000 );
        }        


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
        inline Boolean Identification::SecondAdvancedProgrammableInterruptController() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 21

            // Return if the central processing unit supports a second advanced programmable interrupt controller feature by performing the and 
            // operation ( & ), between the entry that describes the required information and a value with only one bit ON in the bit with index 21
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00200000 );
        }        


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
        inline Boolean Identification::MOVBE() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 22

            // Return if the central processing unit supports the MOVBE feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 22
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00400000 );
        }        


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
        inline Boolean Identification::POPCNT() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 23

            // Return if the central processing unit supports the POPCNT feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 23
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x00800000 );
        }        


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
        inline Boolean Identification::TscDeadline() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 24

            // Return if the central processing unit supports the TSC deadline feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 24
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x01000000 );
        }        


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
        inline Boolean Identification::AES() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 25

            // Return if the central processing unit supports the AES feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 25
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x02000000 );
        }        


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
        inline Boolean Identification::XSAVE() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 26

            // Return if the central processing unit supports the XSAVE feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 26
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x04000000 );
        }        


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
        inline Boolean Identification::OSXSAVE() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 27

            // Return if the central processing unit supports the OSXSAVE feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 27
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x08000000 );
        }        


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
        inline Boolean Identification::AVX() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 28

            // Return if the central processing unit supports the AVX feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 28
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x10000000 );
        }        


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
        inline Boolean Identification::FloatingPointConversion16bit() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 29

            // Return if the central processing unit supports the 16 bit floating point conversion feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 29
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x20000000 );
        }        


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
        inline Boolean Identification::RDRAND() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the ECX part of the RCX register, in bit with index 30

            // Return if the central processing unit supports the RDRAND feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 30
            return ( member_centralProcessingUnitBasicInformation[1][2] & 0x40000000 );
        }        


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
        inline Boolean Identification::x87FloatingPointUnitOnChip() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 0 

            // Return if the central processing unit supports the floating point unit on chip feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 0
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00000001 );
        }        


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
        inline Boolean Identification::Virtual8086ModeEnhancement() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 1

            // Return if the central processing unit supports virtual 8086 mode enhancement by performing the and operation ( & ), between the entry 
            // that describes the required information and a value with only one bit ON in the bit with index 1
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00000002 );
        }        
        

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
        inline Boolean Identification::DebuggingExtensions() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 2

            // Return if the central processing unit supports the debugging extensions feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 2
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00000004 );
        }        


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
        inline Boolean Identification::PageSizeExtensions() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 3 

            // Return if the central processing unit supports the page size extensions feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 3
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00000008 );
        }        


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
        inline Boolean Identification::TimeStampCounter() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 4 

            // Return if the central processing unit supports the time stamp counter feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 4
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00000010 );
        }        


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
        inline Boolean Identification::RDMSRandWRMSR() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 5 

            // Return if the central processing unit supports the RDMSR and WRMSR feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 5
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00000020 );
        }        


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
        inline Boolean Identification::PhysicalAddressExtensions() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 6

            // Return if the central processing unit supports the physical address extensions feature by performing the and operation ( & ), between the 
            // entry that describes the required information and a value with only one bit ON in the bit with index 6
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00000040 );
        }        


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
        inline Boolean Identification::MachineCheckException() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 7

            // Return if the central processing unit supports the machine check exception feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 7
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00000080 );
        }        


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
        inline Boolean Identification::CMPXCHG8B() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 8

            // Return if the central processing unit supports CMPXCHG8B feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 8
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00000100 );
        }        


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
        inline Boolean Identification::AdvancedProgrammableInterruptController() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 9

            // Return if the central processing unit supports the advanced programmable interrupt controller on chip feature by performing the and 
            // operation ( & ), between the entry that describes the required information and a value with only one bit ON in the bit with index 9
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00000200 );
        }        


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
        inline Boolean Identification::SYSENTERandSYSEXIT() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 11

            // Return if the central processing unit supports the SYSENTER and SYSEXIT feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 11
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00000800 );
        }        


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
        inline Boolean Identification::MemoryTypeRangeRegisters() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 12

            // Return if the central processing unit supports the memory type range registers feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 12
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00001000 );
        }        


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
        inline Boolean Identification::PteGlobalBit() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 13

            // Return if the central processing unit supports the PTE global bit feature by performing the and operation ( & ), between the entry 
            // that describes the required information and a value with only one bit ON in the bit with index 13
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00002000 );
        }        


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
        inline Boolean Identification::MachineCheckArchitecture() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 14

            // Return if the central processing unit supports the machine check architecture feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 14
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00004000 );
        }        


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
        inline Boolean Identification::ConditionalMoveAndCompareInstructions() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 15

            // Return if the central processing unit supports the conditional move/compare instructions feature by performing the and operation 
            // ( & ), between the entry that describes the required information and a value with only one bit ON in the bit with index 15
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00008000 );
        }        


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
        inline Boolean Identification::PageAttributeTable() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 16

            // Return if the central processing unit supports the page attribute table feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 16
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00010000 );
        }        


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
        inline Boolean Identification::PageSizeExtension() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 17

            // Return if the central processing unit supports the page size extension feature by performing the and operation ( & ), between the 
            // entry that describes the required information and a value with only one bit ON in the bit with index 17
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00020000 );
        }        


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
        inline Boolean Identification::ProcessorSerialNumber() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 18

            // Return if the central processing unit supports the processor serial number feature by performing the and operation ( & ), between 
            // the entry that describes the required information and a value with only one bit ON in the bit with index 18
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00040000 );
        }        


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
        inline Boolean Identification::CLFLUSH() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 19

            // Return if the central processing unit supports the CLFLUSH feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 19
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00080000 );
        }        


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
        inline Boolean Identification::DebugStore() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 21

            // Return if the central processing unit supports the debug store feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 21
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00200000 );
        }        


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
        inline Boolean Identification::ThermalMonitorAndClockControl() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 22

            // Return if the central processing unit supports the thermal monitor and clock control feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 22
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00400000 );
        }        


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
        inline Boolean Identification::MMX() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 23

            // Return if the central processing unit supports a MMX feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 23
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x00800000 );
        }        


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
        inline Boolean Identification::FXSAVEandFXRSTOR() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 24

            // Return if the central processing unit supports the FXSAVE and FXRSTOR feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 24
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x01000000 );
        }        


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
        inline Boolean Identification::StreamingSimdExtensions() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 25

            // Return if the central processing unit supports the streaming SIMD extensions feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 25
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x02000000 );
        }        


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
        inline Boolean Identification::StreamingSimdExtensions2() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 26

            // Return if the central processing unit supports the streaming SIMD extensions 2 feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 26
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x04000000 );
        }        


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
        inline Boolean Identification::SelfSnoop() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 27

            // Return if the central processing unit supports the self snoop feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 27
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x08000000 );
        }        


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
        inline Boolean Identification::MultiThreading() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 28

            // Return if the central processing unit supports the multi threading feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 28
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x10000000 );
        }        


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
        inline Boolean Identification::ThermalMonitor() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 29

            // Return if the central processing unit supports the thermal monitor feature by performing the and operation ( & ), 
            // between the entry that describes the required information and a value with only one bit ON in the bit with index 29
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x20000000 );
        }        


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
        inline Boolean Identification::PBE() const
        {
            // To obtain feature information the 'CPUID' needs to be executed with the following values :
            //
            //      EAX = 1
            //      ECX - Non relevant
            //
            // And the specific information required for this method will be stored in the EDX part of the RDX register, in bit with index 31

            // Return if the central processing unit supports the PBE feature by performing the and operation ( & ), between the entry that describes 
            // the required information and a value with only one bit ON in the bit with index 31
            return ( member_centralProcessingUnitBasicInformation[1][3] & 0x80000000 );
        }


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
        inline const TranslationLookasideBuffersIdentification& Identification::TranslationLookasideBuffers() const
        {
        	// Return a constant reference to the member with the translation lookaside buffers identification information
            return ( member_translationLookasideBuffersIdentification );
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
		inline Boolean Identification::operator==( const Identification& other ) const
		{
			// Check if both or only one of the instances is in default state
			CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO

			// Compare between the instances, and retrun the result
			return ( ( member_Basic_EAX_valuesMaximum == other.member_Basic_EAX_valuesMaximum ) && ( member_centralProcessingUnitBasicInformation == other.member_centralProcessingUnitBasicInformation ) && ( member_translationLookasideBuffersIdentification == other.member_translationLookasideBuffersIdentification ) );
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
		inline Boolean Identification::operator!=( const Identification& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************




































//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************




































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



































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
        inline UnsignedInteger64bits Identification::GetMaximumValueForBasicInformation__Private()
        {
        	// This will store the return values from invoking the 'CPUID' instruction with EAX part of the RAX register set to 0
        	UnsignedInteger32bits result[4] = {0};

        	// Invoke the 'CPUID' instruction with EAX part of the RAX register set to 0. This will return in EAX part of the RAX register
        	// the number of leafs the current central proccessing unit supports
			InvokeCPUIDandStoreTheResultToTheMemoryAddress__Private( 0, result );

			// Return the first entry of the result, it contains the value in the EAX part of the RAX register
			return ( result[0] );        	
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to invoke the 'CPUID' assembly instruction for all the values that represent basic information on the cetnral processing
        //		unit, store them into a dynamic array and return a copy of it
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
        //      A dynamic array with the basic information on the central processing unit
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
        inline Memory::DynamicArray< Memory::Array< UnsignedInteger32bits, 4 > > Identification::GetBasicInformation__Private()
        {
            // This object will store the central processing unit basic information
            Memory::DynamicArray< Memory::Array< UnsignedInteger32bits, 4 > > centralProcessingUnitBasicInformation( member_Basic_EAX_valuesMaximum );

            // Invoke the 'CPUID' with all the possible central processing basic values for EAX ( ECX is always 0 ) and store the information
            for ( UnsignedInteger64bits current_EAX_value = 0 ; current_EAX_value < member_Basic_EAX_valuesMaximum ; ++current_EAX_value )
            {
                // Set the EAX part of the RAX register to the required value, invoke the 'CPUID' instruction and the store the information returned
                InvokeCPUIDandStoreTheResultToTheMemoryAddress__Private( current_EAX_value, centralProcessingUnitBasicInformation[ current_EAX_value ].FirstEntryMemoryAddress() );
            }

            // Return the dynamic array with the basic information on the central processing unit
            return ( MOVE( centralProcessingUnitBasicInformation ) );
        }


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
        //          2. memoryAddressToStoreTheInformation - this memory address will be set with the information returned by the invoking the 'CPUID'
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
        inline void Identification::InvokeCPUIDandStoreTheResultToTheMemoryAddress__Private( UnsignedInteger32bits set_EAX_toThisValue, UnsignedInteger32bits* memoryAddressToStoreTheInformation, UnsignedInteger32bits set_ECX_toThisValue )
        {
            // This will be added only in test mode, to ensure that the given data to the method is valid   
            Assert_MACRO( ( ( ( set_EAX_toThisValue >= 0x40000000 ) && ( set_EAX_toThisValue <= 0x4FFFFFFF ) ) == false ), "CentralProcessingUnit::Identification::InvokeCPUIDandStoreTheResultToTheMemoryAddress__Private failed - the given value for EAX is out of recognized range" )
            Assert_MACRO( ( memoryAddressToStoreTheInformation != 0 ), "CentralProcessingUnit::Identification::InvokeCPUIDandStoreTheResultToTheMemoryAddress__Private failed - the given pointer is NULL" )

            // The following is an extended inline assembly statement. It will be used to invoke the 'CPUID' instruction to obtain information on the
            // central processing unit, and store it to the given memory address. The first set of 4 bytes at the memory address will store the content of the
            // EAX part of the RAX register, the second set of 4 bytes at the memory address will store the content of the EBX part of the RBX register, The 
            // third set of 4 bytes at the memory address will store the content of the ECX part of the RCX register, and the last 4 bytes set at the memory 
            // address will store the content of the EDX part of the RDX register. This is not possible only using C++

            __asm__ volatile (  "MOV EAX, %[SetEAXtoThisValue];"
                                "MOV ECX, %[SetECXtoThisValue];"
                                "CPUID;"
                                "MOV %[StoreEAX], EAX;"
                                "MOV %[StoreEBX], EBX;"
                                "MOV %[StoreECX], ECX;"
                                "MOV %[StoreEDX], EDX;"

                                : [StoreEAX] "=m" ( *memoryAddressToStoreTheInformation ), [StoreEBX] "=m" ( *( memoryAddressToStoreTheInformation + 1 ) ), [StoreECX] "=m" ( *( memoryAddressToStoreTheInformation + 2 ) ), [StoreEDX] "=m" ( *( memoryAddressToStoreTheInformation + 3 ) )
                                : [SetEAXtoThisValue] "r" ( set_EAX_toThisValue ), [SetECXtoThisValue] "r" ( set_ECX_toThisValue )
                                : "memory", "%eax", "%ebx", "%ecx", "%edx" );

        }




































// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************




































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************




































	}  //  Namespace CentralProcessingUnit

}  //  Namespace Universe



#endif  // IDENTIFICATION_HPP