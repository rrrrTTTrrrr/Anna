#include <iostream> 


using namespace std;
class Test
{
public:



private:

};  //  class Test

int main()  
{

	try
    {


        int mm = 9;

        void* rr = &mm;

        __asm__ volatile ( "MOV RAX, %[MM]\n\t"
                           "MOV DWORD PTR [RAX], 10\n\t"
                           :
                           : [MM] "ir" ( rr )
                           : );

        std::cout << mm << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}