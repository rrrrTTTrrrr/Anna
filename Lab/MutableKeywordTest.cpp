#include <iostream> 

#include  "../../Utilities/Exception/Exception.h"  //


using namespace std;
using namespace Universe;

class Test
{
public:

	Test( int y, int y1 ) : m_y( y ), m_y1( y1 ) {}

	void Te() const;

private:

	int m_y;

	mutable int m_y1;

};  //  class Test


void Test::Te() const
{
	m_y1 = 67;
}

int main()  
{

	try
	{

		Test tt( 6, 9 );

		tt.Te();



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