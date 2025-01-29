//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline const Language::String& Identification::VendorIdentificationString()
{
    // To acquire the central processing unit vendor identification string the 'CPUID' needs to be started with :
    //
    //      EAX = 0
    //      ECX - Non relevant
    //
    // And the result will be stored in the registers EBX, ECX and EDX

    // Return a constant reference to the central processing unit vendor identification string
    return ( member_vendorIdentificationString );
}


inline UnsignedInteger32bits Identification::SteppingIdentification()
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


inline UnsignedInteger32bits Identification::Model()
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


inline UnsignedInteger32bits Identification::Family()
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


inline UnsignedInteger32bits Identification::Type()
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


inline UnsignedInteger32bits Identification::ExtendedModelIdentification()
{
    // To obtain version information the 'CPUID' needs to be executed with the following values :
    //
    //      EAX = 1
    //      ECX - Non relevant
    //
    // And the specific information required for this method will be stored in the EAX part of the RAX register, in bits with indexes 16-19 

    // The extended family identification is only valid when the family identification is 0x0F
    Assert( ( Family() == 0x0000000F ), "CentralProcessingUnit::Identification::ExtendedModelIdentification failed - the extended model identification is only valid for the family identification 0x0F - the Pentium 4 processir family" );

    // Return the type by performing the and operation ( & ), between the entry that describes the required information and a value that will 
    // set all the other bits, excpt of the type part, to 0. Finally right shift the bits to the beginning of the register so it could be read
    // as an integer
    return ( ( member_centralProcessingUnitBasicInformation[1][0] & 0x000F0000 ) >> 16 );
}


inline UnsignedInteger32bits Identification::ExtendedFamilyIdentification()
{
    // To obtain version information the 'CPUID' needs to be executed with the following values :
    //
    //      EAX = 1
    //      ECX - Non relevant
    //
    // And the specific information required for this method will be stored in the EAX part of the RAX register, in bits with indexes 20-27 

    // The extended family identification is only valid when the family identification is 0x06 or 0x0F
    Assert( ( ( Family() == 0x00000006 ) || ( Family() == 0x0000000F ) ), "CentralProcessingUnit::Identification::ExtendedFamilyIdentification failed - the extended model identification is only valid for the family identification 0x0F or 0x06 - the Pentium 4 processir family" );

    // Return the type by performing the and operation ( & ), between the entry that describes the required information and a value that will 
    // set all the other bits, excpt of the type part, to 0. Finally right shift the bits to the beginning of the register so it could be read
    // as an integer
    return ( ( member_centralProcessingUnitBasicInformation[1][0] & 0x0FF00000 ) >> 20 );
}


inline UnsignedInteger32bits Identification::BrandIndex()
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


inline UnsignedInteger32bits Identification::CacheLineSize()
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


inline UnsignedInteger32bits Identification::MaximumNumberOfAddressableIdentificationsForLogicalProcessorsInThisPackage()
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


inline UnsignedInteger32bits Identification::LocalAdvancePprogrammableInterruptControlleridentification()
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


inline Boolean Identification::StreamingSimdExtensions3()
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


inline Boolean Identification::CarrylessMultiplication()
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


inline Boolean Identification::DebugStoreArea64bits()
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


inline Boolean Identification::Monitor()
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


inline Boolean Identification::CplQualifiedDebugStore()
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


inline Boolean Identification::VirtualMachineExtensions()
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


inline Boolean Identification::SaferModeExtensions()
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


inline Boolean Identification::EnhancedSpeedStep()
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


inline Boolean Identification::SecondThermalMonitor()
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


inline Boolean Identification::SupplementalStreamingSimdExtensions3()
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


inline Boolean Identification::Layer1ContextIdentification()
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


inline Boolean Identification::SiliconDebug()
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


inline Boolean Identification::FuseMultiplyAdd()
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


inline Boolean Identification::CMPXCHG16B()
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


inline Boolean Identification::xPtrUpdateControl()
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


inline Boolean Identification::PerformanceDebugCapabilityMSR()
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


inline Boolean Identification::ProcessContextIdentifiers()
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


inline Boolean Identification::DirectCacheAccess()
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


inline Boolean Identification::StreamingSimdExtensions4_1()
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


inline Boolean Identification::StreamingSimdExtensions4_2()
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


inline Boolean Identification::SecondAdvancedProgrammableInterruptController()
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


inline Boolean Identification::MOVBE()
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


inline Boolean Identification::POPCNT()
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


inline Boolean Identification::TscDeadline()
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


inline Boolean Identification::AES()
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


inline Boolean Identification::XSAVE()
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


inline Boolean Identification::OSXSAVE()
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


inline Boolean Identification::AVX()
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


inline Boolean Identification::FloatingPointConversion16bit()
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


inline Boolean Identification::RDRAND()
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


inline Boolean Identification::x87FloatingPointUnitOnChip()
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


inline Boolean Identification::Virtual8086ModeEnhancement()
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


inline Boolean Identification::DebuggingExtensions()
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


inline Boolean Identification::PageSizeExtensions()
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


inline Boolean Identification::TimeStampCounter()
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


inline Boolean Identification::RDMSRandWRMSR()
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


inline Boolean Identification::PhysicalAddressExtensions()
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


inline Boolean Identification::MachineCheckException()
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


inline Boolean Identification::CMPXCHG8B()
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


inline Boolean Identification::AdvancedProgrammableInterruptController()
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


inline Boolean Identification::SYSENTERandSYSEXIT()
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


inline Boolean Identification::MemoryTypeRangeRegisters()
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


inline Boolean Identification::PteGlobalBit()
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


inline Boolean Identification::MachineCheckArchitecture()
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


inline Boolean Identification::ConditionalMoveAndCompareInstructions()
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


inline Boolean Identification::PageAttributeTable()
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


inline Boolean Identification::PageSizeExtension()
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


inline Boolean Identification::ProcessorSerialNumber()
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


inline Boolean Identification::CLFLUSH()
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


inline Boolean Identification::DebugStore()
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


inline Boolean Identification::ThermalMonitorAndClockControl()
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


inline Boolean Identification::MMX()
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


inline Boolean Identification::FXSAVEandFXRSTOR()
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


inline Boolean Identification::StreamingSimdExtensions()
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


inline Boolean Identification::StreamingSimdExtensions2()
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


inline Boolean Identification::SelfSnoop()
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


inline Boolean Identification::MultiThreading()
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


inline Boolean Identification::ThermalMonitor()
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


inline Boolean Identification::PBE()
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


// inline const TranslationLookasideBuffersIdentification& Identification::TranslationLookasideBuffers()
// {
// 	// Return a constant reference to the member with the translation lookaside buffers identification information
//     return ( member_translationLookasideBuffersIdentification );
// }



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



inline LargestUnsignedInteger Identification::GetMaximumValueForBasicInformation__Private()
{
	// This will store the return values from invoking the 'CPUID' instruction with EAX part of the RAX register set to 0
	UnsignedInteger32bits result[4] = {0};

	// Invoke the 'CPUID' instruction with EAX part of the RAX register set to 0. This will return in EAX part of the RAX register
	// the number of leafs the current central proccessing unit supports
	InvokeCpuidAssemblyInstructionAndStoreTheResultToTheMemoryAddress__Private( 0, result );

	// Return the first entry of the result, it contains the value in the EAX part of the RAX register
	return ( result[0] );        	
}


inline Memory::Vector< Memory::Array< UnsignedInteger32bits, 4UL > > Identification::GetBasicInformation__Private()
{
    // This object will store the central processing unit basic information
    Memory::Vector< Memory::Array< UnsignedInteger32bits, 4 > > centralProcessingUnitBasicInformation( member_Basic_EAX_valuesMaximum );

    // Invoke the 'CPUID' with all the possible central processing basic values for EAX ( ECX is always 0 ) and store the information
    for ( UnsignedInteger32bits current_EAX_value = 0 ; current_EAX_value < member_Basic_EAX_valuesMaximum ; ++current_EAX_value )
    {
        // Set the EAX part of the RAX register to the required value, invoke the 'CPUID' instruction and the store the information returned
        InvokeCpuidAssemblyInstructionAndStoreTheResultToTheMemoryAddress__Private( current_EAX_value, &centralProcessingUnitBasicInformation[ current_EAX_value ][0] );
    }

    // Return the dynamic array with the basic information on the central processing unit
    return ( centralProcessingUnitBasicInformation );
}


inline void Identification::InvokeCpuidAssemblyInstructionAndStoreTheResultToTheMemoryAddress__Private( UnsignedInteger32bits set_EAX_toThisValue, UnsignedInteger32bits* memoryAddressToStoreTheInformation, UnsignedInteger32bits set_ECX_toThisValue )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid   
    Assert( ( ( ( set_EAX_toThisValue >= 0x40000000 ) && ( set_EAX_toThisValue <= 0x4FFFFFFF ) ) == false ), "The given value for EAX is out of recognized range" );
    AssertPointerIsNotNull( memoryAddressToStoreTheInformation );

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


inline const Language::String Identification::ExtractVendorIdentificationString__Private()
{
    // To acquire the central processing unit vendor identification string the 'CPUID' needs to be started with :
    //
    //      EAX = 0
    //      ECX - Non relevant
    //
    // And the result will be stored in the registers EBX, ECX and EDX

	// This object will store the vendor identification string, it contains 12 characters
    Language::String vendorIdentificationString( MemoryHandlerName::Vector, 12UL );

    // Set the four first ascii characters
    vendorIdentificationString[0] = *reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][1] );
    vendorIdentificationString[1] = *( reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][1] ) + 1UL );
    vendorIdentificationString[2] = *( reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][1] ) + 2UL );
    vendorIdentificationString[3] = *( reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][1] ) + 3UL );

    // Set the four second ascii characters
    vendorIdentificationString[4] = *reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][3] );
    vendorIdentificationString[5] = *( reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][3] ) + 1UL );
    vendorIdentificationString[6] = *( reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][3] ) + 2UL );
    vendorIdentificationString[7] = *( reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][3] ) + 3UL );

    // Set the four last ascii characters
    vendorIdentificationString[8] = *reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][2] );
    vendorIdentificationString[9] = *( reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][2] ) + 1UL );
    vendorIdentificationString[10] = *( reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][2] ) + 2UL );
    vendorIdentificationString[11] = *( reinterpret_cast< const AsciiCharacter* >( &member_centralProcessingUnitBasicInformation[0][2] ) + 3UL );

    // Return the string with the central processing unit vendor identification string
    return ( vendorIdentificationString );
}



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe