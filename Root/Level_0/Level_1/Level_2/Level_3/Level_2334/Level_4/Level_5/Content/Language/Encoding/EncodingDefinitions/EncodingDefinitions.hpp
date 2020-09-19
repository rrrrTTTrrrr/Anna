#ifndef  ENCODINGDEFINITIONS_HPP
#define  ENCODINGDEFINITIONS_HPP



// The purpose of this file is to unified all the definitions required in the namespace.
// This way every source file that is part of the namespace can add this file and use 
// it's contents



namespace Universe
{

    namespace Encoding
    {


		// The new name of using unicode scalar value, instead of unsigned int
		// Range :  0 until 1,114,111
		typedef unsigned int UnicodeScalarValue;

        // This enumeration will be used to determine the current encoding used in the text
        class enum EncodingType
        {

            Unknown = 0,
            Ascii = 1,
            UnicodeTransferFormat8 = 2,
            UnicodeTransferFormat16 = 3,
            UnicodeTransferFormat16_BigEndian = 4,
            UnicodeTransferFormat16_LittleEndian = 5,
            UnicodeTransferFormat32 = 6,
            UnicodeTransferFormat32_BigEndian = 7,
            UnicodeTransferFormat32_LittleEndian = 8

        };



    }  //   Namespace Encoding


}  //   Namespace Universe


#endif  // ENCODINGDEFINITIONS_HPP