#include <iostream> 

#include "../Utilities/String/AsciiStringOperations.h"

using namespace std;
using namespace Universe;

#define IF_CURRENT_FILE_NAME_IS_DOT_OR_TWO_DOTS_CONTINUE( FILE_NAME ) if ( ( ( 0 == AsciiStringCompare( FILE_NAME, "." ) ) || ( 0 == AsciiStringCompare( FILE_NAME, ".." ) ) ) ) { continue; cout << "Yeah" << endl; }

int main() 
{

	IF_CURRENT_FILE_NAME_IS_DOT_OR_TWO_DOTS_CONTINUE( "Ludacris" )


	return ( 0 );
}
