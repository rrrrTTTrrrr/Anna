#include <iostream> 

#include "../Containers/AsciiString.h"

using namespace std;
using namespace Universe;


class Test
{
public:



private:

};  //  class Test

int main() 
{
	char* le = new char[4];

	le[0] = 'h';
	le[1] = 'o';
	le[2] = 'm';
	le[3] = 'e';

	char* le1 = new char[4];

	le1[0] = 'h';
	le1[1] = 'o';
	le1[2] = 'm';
	le1[3] = 'e';

	cout << le << endl;

	AddCharacterToBeginingOfAsciiString( le, '/' );

	cout << AddCharacterToBeginingNewAllocatedOfAsciiString( le1, '/' ) << endl;

	cout << le << endl;

	AsciiString a( le );

	a.AddCharacterToTheBeginingOfAsciiString( '/' );

	cout << a.GetCstyleAsciiString() << endl;


	return ( 0 );
}
