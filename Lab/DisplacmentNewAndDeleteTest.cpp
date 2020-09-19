#include <iostream> 


#include  "../../Utilities/Exception/Exception.h"  //


using namespace std;
using namespace Universe;

class Test
{
public:

	Test( int y ) { m_t = new int[y]; cout << "Test constructor" << endl; }

	~Test() { delete[] m_t; cout << "Test destructor" << endl; }


private:

	int* m_t;

};  //  class Test

int main()  
{

	try
	{

		char* tt = new char[77];

		new ( tt + 3 ) Test(7);

		(*(Test*)(tt + 3 )).~Test();



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