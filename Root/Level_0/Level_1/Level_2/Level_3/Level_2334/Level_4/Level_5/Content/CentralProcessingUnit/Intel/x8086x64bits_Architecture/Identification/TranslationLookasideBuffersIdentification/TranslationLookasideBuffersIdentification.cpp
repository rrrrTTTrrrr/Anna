#ifndef TRANSLATIONLOOKASIDEBUFFERSIDENTIFICATION_CPP
#define TRANSLATIONLOOKASIDEBUFFERSIDENTIFICATION_CPP


#include "TranslationLookasideBuffersIdentification.hpp"


#include "../../../../../../../../Content/BuiltInTypesWrapper/Bit/Bit.hpp"  //  Class Bit


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe 
{

	namespace CentralProcessingUnit
    {


		// Forward declarations :
		//
		//  NONE
		//

















//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************


































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
        void TranslationLookasideBuffersIdentification::InitializeTranslationLookasideBuffersIdentificationArray__Private( const UnsignedInteger32bits* memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo )
        {
            // The information is in EAX, EBX, ECX and EDX when executing the CPUID with EAX set to 2, beside the lowest significant byte in
            // the EAX part of the RAX register. Each byte of this registers contains a descriptor. This descriptor is an index into a table,
            // in the Intel software developer manual part 2 in the CPUID instruction part ( table 3-12 - Encoding of CPUID Leaf 2 descriptors ),
            // that contains information on the translation lookaside buffers of the central processing unit

            // Loop on all the registers parts EAX, EBX, ECX and EDX
            for ( UnsignedInteger64bits registerIndex = 0 ; registerIndex < 4UL ; ++registerIndex )
            {
                // Create an instance that will point to the most significant bit of the current register
                const Bit< const UnsignedInteger32bits > registerMostSignificantBit( ( memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo + registerIndex ), 31 );

            	// Check if the most significant bit of the current register is set ON which means it is reserved, and does not contain valid information
            	if ( registerMostSignificantBit.ONorOFF() == 1 )
            	{
            		// The most significant bit of the current register is ON

            		// Continue to the next register
            		continue;
            	}

                // This object will store the current byte descriptor
                UnsignedInteger8bits byteDescriptor = 0;

                // Loop on the 4 byte of each part of the register
                for ( UnsignedInteger64bits registerByteIndex = 0 ; registerByteIndex < 4UL ; ++registerByteIndex )
                {
                    // Set the byte descriptor
                    byteDescriptor = *( reinterpret_cast< const UnsignedInteger8bits* >( memoryAddressOf_EAX_EBX_ECX_EDX_contentStoredAfterCPUIDexecutedWithEAXsetToTwo + registerIndex ) + registerByteIndex );

                    // The least significant byte of EAX does not contain information, check if it is the current byte
                    if ( ( registerIndex == 0 ) && ( registerByteIndex == 0 ) )
                    {
                        // This is the least significant byte of EAX

                        // Skip this byte
                        continue;
                    }

                    // Check if the current byte descriptor represents translation lookaside buffer
                    if ( DoesByteDescriptorValeRepresentTranslaionLookasideBuffer__Private( byteDescriptor ) == false )
                    {
                    	// The current byte descriptor does not represents translation lookaside buffer

                    	// Continue to the next byte descriptor
                    	continue;
                    }

                    // Provide the current byte descriptor to try initialize the translation lookaside buffer identification instance, it will
                    // only be initialized in case the descriptor match one of the values that describe a translation lookaside buffer
                    member_translationLookasideBuffersIdentification[ member_numberOfTranslationLookasideBuffers ] = TranslationLookasideBufferIdentification( byteDescriptor );

                    // Incremente the number of translation lookaside buffer this central processing unit contains by 1
                    member_numberOfTranslationLookasideBuffers += 1; 
                }
                
            }

        }





































// *********************************************************************************   TESTING   ********************************************************************************




































		DEBUG_TOOL(

			// Method Information :
			//
			//  Description :
			//
			//		This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
			//		the functionality
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
			//		1. true - if the object passed the test
			//		2. false - otherwise
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
			void TranslationLookasideBuffersIdentification::Test()
			{}

		)  //  End of debug tool











	}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe


#endif  //  TRANSLATIONLOOKASIDEBUFFERSIDENTIFICATION_CPP





