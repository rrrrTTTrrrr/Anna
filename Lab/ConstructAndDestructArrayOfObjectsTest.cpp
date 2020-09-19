#include <iostream> 


#include  "../../Utilities/ErrorHandling/Exception.h"  //  Class Exception


using namespace std;
using namespace Universe;



class Test
{
public:

	Test() { cout << "Constructor" << endl; }

	~Test() { cout << "Destructor" << endl; }


private:

};  //  class Test

int main()  
{

	try
	{


		Test* tt = new Test[ 3 ];

		delete[] tt;


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