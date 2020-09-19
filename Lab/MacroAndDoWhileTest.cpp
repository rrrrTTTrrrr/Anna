#include <iostream> 


using namespace std;


#define ERROR_R( msg ) do { cout << msg << endl; } while( 0 )

class Test
{
public:



private:

};  //  class Test

int main()  
{

	int y = 8;

	if ( y == 7 )
	{
		ERROR_R( "wOW" );
	}
	else
	{
		cout << "Noooo" << endl;
	}


	return ( 0 );
}