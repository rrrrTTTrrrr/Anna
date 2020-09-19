#include <iostream> 

using namespace std;






int main()  
{

	try
    {

    	int arr[5] = {1,2,3,4,5};

    	for ( int i = 0 ; i < 3 ; ++i )
    	{
    		int cc = arr[i];
    		arr[i] = arr[i+1];
    		arr[i+1] = cc;
    	}

    	for ( int i = 0 ; i < 4 ; ++i )
    	{
    		std::cout << arr[i] << std::endl;
    	}


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}