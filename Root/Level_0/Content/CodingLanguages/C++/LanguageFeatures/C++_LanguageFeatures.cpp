#ifndef  CPP_LANGUAGEFEATURES_CPP
#define  CPP_LANGUAGEFEATURES_CPP


#include "C++_LanguageFeatures.hpp"


namespace Universe 
{











//	***************************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ***************************************************************






























	// Use this function to verify if the current encoding is little ( true ) or big ( false ) endian
	bool LittleOrBigEndian()
	{
		// Create a variable with more then 1 octet and set it to 1
		UnsignedInteger16bits sample = 1U;

		// This object will point to the first byte of the sample
		UnsignedInteger8bits* sampleByteWithIndexZero = reinterpret_cast< UnsignedInteger8bits* >( &sample );

		// If the encoding is little endian the one bit set on in the variable will be in the first byte. The pointer then points to a location 
		// with value other then zero will be converted to the boolean value true. For the big endian the only bit on would at the part of the 
		// variable that the pointer is not reaching and therefore the value would be zero so be calm, and return the pointer dereferenced
		return ( *sampleByteWithIndexZero );
	}









}  //  Namespace Universe


#endif  //  CPP_LANGUAGEFEATURES_CPP