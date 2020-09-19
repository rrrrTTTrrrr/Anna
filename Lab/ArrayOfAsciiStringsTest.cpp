#include <iostream> 

#include "../../Utilities/Containers/Array.h"  //
#include "../../Utilities/BasicUtilities/BasicOperations/Ascii/AsciiString/AsciiString.h"
#include  "../../Utilities/Exception/Exception.h"  //


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

		Array< AsciiString* > tt;

		tt.PushHead( new AsciiString( "Loser" ) );



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