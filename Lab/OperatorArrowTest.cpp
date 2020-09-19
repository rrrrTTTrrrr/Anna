#include <iostream> 

#include  "../../Utilities/Exception/Exception.h"  //


using namespace std;
using namespace Universe;


typedef struct dumb
{
	int yy;
	int ss;
}dumb;


class Test
{
public:

	Test( int tt, int tt1 ) { m_p = new dumb; m_p->yy = tt; m_p->ss = tt1; }

	dumb* operator->() const { return ( m_p ); }

private:

	dumb* m_p;

};  //  class Test

int main()  
{

	try
	{


		Test rr( 67, 88 );

		cout << rr->yy << endl;


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