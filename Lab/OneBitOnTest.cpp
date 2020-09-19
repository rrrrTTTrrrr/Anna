#include <iostream> 

#include "../../Utilities/BasicUtilities/BasicOperations/Bits/BitsOperations.h"

using namespace std;
using namespace Universe;

	inline unsigned char GetByteWithOneBitOnInTheRequiredPlaceIMP( unsigned long bitNumber ) throw()
	{
		// Create an object to store only the first bit on ( 1 )
		unsigned char oneBitOn = 1;

		// Create an object to store the modulo 8 ( %8 ) operation on the sum of the given index and the number of unused
		// bits in the first byte
		unsigned char modulo8Result = ( ( bitNumber + 3 ) % 8 );

		// Check if the modulo operation on the sum of the given index and the number of unused bits in the first byte
		// is 0, then because of the circular nature of the values, it will never be 8, it will jump to 0 after 7,
		// Then no shiftig is required
		if ( 0 == modulo8Result )
		{
			// Nothing needs to be done, return to mama
			return ( oneBitOn );
		}

		// Shift the bit to the required index, and return a copy. The game here is to add one to the bit index
		// to make the number of bits and then add it to the number of unused bits in the first byte. And then
		// the sum should be decreased by 1 to get
		return ( oneBitOn << ( 8 - modulo8Result ) );
	}

class Test
{
public:



private:

};  //  class Test

int main()  
{

	try
	{

		for ( unsigned int bb = 0 ; bb < 16 ; ++bb )
		{
			cout << "bb value is -  " << bb << endl;

			unsigned char tt = GetByteWithOneBitOnInTheRequiredPlaceIMP( bb );

			DisplayObjectBits( &tt, 1 );

			cout << endl << endl;
		}


	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}