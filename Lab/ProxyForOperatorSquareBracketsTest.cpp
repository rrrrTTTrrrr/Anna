#include <iostream> 


#include  "../../Utilities/Exception/Exception.h"  


using namespace std;
using namespace Universe;


class Test
{
public:

	Test( int yy ) : tt( new int[yy] ) {}

	int& operator[]( int index ) { return ( tt[ index ] ); }

	int operator[]( int index ) const { return ( tt[ index ] ); }



private:


	int* tt;

};  //  class Test



int main()  
{

	try
	{

		Test t( 8 );

		t[3] = 8;

		t[3] |= 33;

		if ( t[3] == 8 )
		{
			cout << "Yeahhhh" << endl;
		}

		const Test rr( 6 );

		cout << rr[3] << endl;


	}
	catch ( const Exception& exception )
	{
		exception.What();
	}
catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}