#ifndef  CONVERTBETWEENNUMERICSYSTEMS_CPP
#define  CONVERTBETWEENNUMERICSYSTEMS_CPP


#include "ConvertBetweenNumericSystems.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe 
{

    namespace DataTypes
    {


    	// Forward declarations :
    	//
    	//  NONE
    	//

























//  ***************************************************************   STATIC FUNCTIONS IMPLEMENTATION   *******************************************************
































            // Method Information :   
            //
            //  Description :
            //
            //      Use this method to convert hexadecimal to binary
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
            //      The number in binary system
            //
            //  Possible errors :
            //
            //      1. The given ascii string object is in default state
            //      2.
            //
            template< typename T >
            TYPE ConvertBetweenNumericSystems::HexadecimalToBinary( const Encoding::AsciiString& hexadecimal )
            {
                // Create an object to store the number in binary system
                TYPE binary = 0;

                // Loop on all the bytes ( starting from the fifth byte right after the "LE0x or BE0x" )
                for ( UnsignedInteger16bits hexadecimalIndex = 4 ; hexadecimal[ hexadecimalIndex ] != 0 ; ++hexadecimalIndex )
                {
                    // The hexadecimal represnt the state of the bits, therefore the bits of the binary must be identical.
                    // For that every hexadecimal entry is set into the lowest significant bits, and then the binary
                    // is left shifted 4 times to move the 4 lowest significant bits to higher significant bits, and to make
                    // space for the next 4 bits

                    // Check if the current hexadecimal is a digit 1 - 9 or a letter A - F
                    if ( ( hexadecimal[ hexadecimalIndex ] >= '0' ) && ( hexadecimal[ hexadecimalIndex ] <= '9' ) )
                    {
                        // The current hexadecimal is a digit, then 48 ( the value of '0' in ascii ) would be needed to 
                        // be subtracted from it in order to get the binary

                        // Multiply the current binary by 16, which is the same as left shifting 4 times, in order 
                        // to make room for the next lower significant bits, and add the new 4 bits
                        binary = ( binary * 16 ) + ( hexadecimal[ hexadecimalIndex ] - '0' );
                    }
                    else
                    {
                        // The current hexadecimal is a letter, then 65 ( the value of 'A' in ascii ) would be needed to 
                        // be subtracted from it in order to get the binary

                        // Multiply the current binary by 16, which is the same as left shifting 4 times, in order 
                        // to make room for the next lower significant bits, and add the new 4 bits
                        binary = ( binary * 16 ) + ( hexadecimal[ hexadecimalIndex ] - 'A' );
                    }

                }

                // Now all the bits were entered to the binary variable

                // The process is correct only if the current system and the system the hexadecimal given was created on
                // use the same endian encoding, otherwise the bits needs to be reversed
                if ( ( ( hexadecimal[0] == 'L' ) && ( false == LittleOrBigEndian() ) ) || ( ( hexadecimal[0] == 'B' ) && ( true == LittleOrBigEndian() ) ) ) 
                {
                    // The systems use different endian encodings 

                    // Reverse the order of the bits
                    Memory::BitsAndBytes::ReverseBytesOrder( &binary, sizeof( TYPE ) );
                }

            }



            // Method Information :   
            //
            //  Description :
            //
            //      Use this method to convert binary to hexadecimal
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
            //      The number in hexadecimal system
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. 
            //
            template< typename T >
            Encoding::AsciiString ConvertBetweenNumericSystems::BinaryToHexadecimal( TYPE binary )
            {
                // This object will store the transformation from the state of the 4 bits to the hexadecimal representation ( 0111 -> '7' )
                static const char convertBetween4BitsStateToHexadecimal[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};

                // Create an ascii string object to contain the number in hexadecimal system
                Encoding::AsciiString& hexadecimal( ( sizeof( TYPE ) * 2 ) + 4 );

                // The 2 first bytes are used to state the endian encoding of the system that created it

                // Set the second byte with the letter "E" to notify that this is the endian mark
                hexadecimal[1] = 'E';

                // Check if the system used little or big endian
                if ( true == LittleOrBigEndian() )
                {
                    // Little endian encoding

                    // Set the first byte to notify the system using little endian
                    hexadecimal[0] = 'L';
                }
                else
                {
                    // Big endian encoding

                    // Set the first byte to notify the system using big endian
                    hexadecimal[0] = 'B';

                }

                // Now the hexadecimal convention prefix "0x"

                // Set the third byte to "0"
                hexadecimal[2] = '0';

                // Set the fourt byte to "x"
                hexadecimal[3] = 'x';

                // Create an object to store the number of bytes used by the binary
                UnsignedInteger16bits binaryNumberOfBytes = sizeof( TYPE );

                // Create an object to point to the bytes of the binary
                UnsignedInteger8bits* binaryByte = reinterpret_cast< UnsignedInteger8bits* >( &binary );

                // Create an object to store the current byte to be set in hexadecimal
                UnsignedInteger16bits hexadecimalIndex = 4;

                // Loop on all the bytes of the given object
                for ( UnsignedInteger16bits binaryByteIndex = 0 ; binaryByteIndex < binaryNumberOfBytes ; ++binaryByteIndex )
                {
                    // First the 4 lower significant bits are handled. Set all the higher significant 4 bits to 0, and use the result as an index into
                    // the lookup array that transform between the 4 bits state and the hexadecimal representation
                    hexadecimal[ hexadecimalIndex + 1 ] = convertBetween4BitsStateToHexadecimal[ ( binaryByte[ binaryByteIndex ] & 0x0F ) ];

                    // Now the 4 higher significant bits. Right shift 4 times the byte, now the required bits are in the required location.
                    // Use the result as an index into the lookup array that transoform between the 4 bits state and the hexadecimal representation
                    hexadecimal[ hexadecimalIndex ] = convertBetween4BitsStateToHexadecimal[ ( binaryByte[ binaryByteIndex ] >> 4 ) ];

                    // Increase the hexadecimal index by 1
                    hexadecimalIndex += 2;
                }

            }



























// ***********************************************************************   TESTING   ***********************************************************************
































    	// All the following methods will be added only in test mode, they are not part of the implementation, their purpose is to
    	// help locate problems in the code


    	DEBUG_TOOL(


		    // Method Information :   
			//
			//  Description :
			//
			//      This method is used to test the object
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
			//      1. true - if the object passed the test
			//      2. false - otherwise
			//
			//  Possible errors :
			//
			//      1. A method does not work correctly - class Exception is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			void ConvertBetweenNumericSystems::Test() throw( std::bad_alloc, Exception )
			{
            }


        )  //  End of debug tool











    }  //  Namespace DataTypes


}  //  Namespace Universe

#endif  //  CONVERTBETWEENNUMERICSYSTEMS_CPP





