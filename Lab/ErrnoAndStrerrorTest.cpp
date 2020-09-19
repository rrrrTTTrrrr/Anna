#include <iostream> 
#include <cerrno>  //  Macro errno
#include <cstring>  //  Function strerror

using namespace std;
class Test
{
public:



private:

};  //  class Test

int main()  
{

	std::cout << strerror( 5 ) << std::endl;

    return ( 0 );
}