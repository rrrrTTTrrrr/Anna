#include <iostream> 




using namespace std;

class Test
{
public:



private:

};  //  class Test

int main()  
{

	unsigned char tt = 0xef;

	switch ( tt )
	{
		case 0xef :
		{
			cout << "Local" << endl;
		}
	}


	return ( 0 );
}