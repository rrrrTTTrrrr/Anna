#include <iostream> 

using namespace std;


class Test
{
public:



private:

};  //  class Test

inline int Ret( int a )
{
	if ( a == 2 )
	{
		return ( 20 );
	}

	return ( 100 );
}

void loss( int a )
{
	Ret( a );

	cout << "Fuccckkkkkk" << endl;
}

int main()  
{

	try
	{

		loss( 4 );



	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
