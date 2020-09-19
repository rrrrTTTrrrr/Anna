#include <iostream> 

using namespace std;





int main()  
{

	try
    {

		int* ii = new int[23];

		std::cout << ii[2] << "    " << ii[4] << endl;

		ii[2] = 77777777;

		ii[4] = 711111117;

		ii = new int[23];

		std::cout << ii[2] << "    " << ii[4] << endl;

		delete[] ii;
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}