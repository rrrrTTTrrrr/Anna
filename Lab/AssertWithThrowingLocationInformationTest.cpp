#include <iostream> 

#include "../Root/FunctionalityBranch/Content/ErrorHandling/Assert/Assert.hpp"

using namespace std;
using namespace Universe;


#define assss ErrorHandling::Assert< ErrorHandling::Exception >::True( ( 13 == 14 ), CreateStringBySurroundWithQuatationMarks_MACRO( #__FILE__ failed - the given pointer is null ) );


#define

class Test
{
public:



private:

};  //  class Test



int main()  
{

	try
    {

    	assss

    }
	catch ( const ErrorHandling::ErrnoException& errnoException )
    {
    	errnoException.TellMe();
    }
    catch ( const ErrorHandling::Exception& exception )
    {
    	exception.TellMe();
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}