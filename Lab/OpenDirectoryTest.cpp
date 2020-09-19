#include <iostream> 
#include <dirent.h>


#include  "../../Utilities/Exception/Exception.h"
#include  "../../Utilities/Exception/ErrnoException.h"
#include "../../Utilities/BasicUtilities/cpp_BasicUtilities.h"



using namespace std;
using namespace Universe;


class Test
{
public:



private:

};  //  class Test



int main()  
{

	try
	{
		DIR* dd = opendir( "/home/david/Documents/Anna/" );

		ThrowExceptionWithErrnoIfPointerIsNULL( dd, "Loser" );

	}
	catch ( const Exception& exception )
	{
		exception.What();
	}
	catch ( const ErrnoException& errnoException )
	{
		errnoException.What();
	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}