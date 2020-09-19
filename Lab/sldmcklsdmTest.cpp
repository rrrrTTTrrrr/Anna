#include <iostream> 

using namespace std;


class Test
{
public:



private:

};  //  class Test


const unsigned char byteDescriptorsThatRepresentTranslationLookasideBuffer[37] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x0B, 0x4F, 0x50, 0x51, 0x52, 0x55, 0x56, 0x57, 0x59, 0x5A, 0x5B, 0x5C, 0x5D, 0x61, 0x63, 0x64, 0x76, 0xA0, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xBA, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xCA };


bool slmdkls( unsigned char uu )
{
	for ( int i = 0 ; i < 37 ; ++i )
	{
		if ( uu == byteDescriptorsThatRepresentTranslationLookasideBuffer[i] )
		{
			return true;
		}
	}

	return false;
}


int main()  
{

	try
    {


		for ( int i = 0 ; i < 256 ; ++i )
		{
			if ( slmdkls( i ) )
			{
				std::cout << i << ", ";
			}
			else
			{
				std::cout << "false, ";
			}
		}

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}