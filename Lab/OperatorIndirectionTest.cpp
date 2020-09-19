#include <iostream> 

using namespace std;

template< typename T >
class Test
{
public:

	Test() {}

	void Print() { cout << "Wooooowwwww" << endl; }

	int m = 8;

	void operator->( () )

private:

	T* mmm;

};  //  class Test

int main()  
{

	try
	{

		Test* t = new Test;

		t->Print();

		cout << t->m << endl;



	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
