#include <iostream> 

using namespace std;


template< typename F, typename S, typename... args >
class Compare
{
public:

	static bool Result() { std::cout << "1" << std::endl; return ( Compare< F, S >::Result() && Compare< S, args... >::Result() ); }

private:

};  //  class Test

template< typename F, typename S >
class Compare< F, S >
{
public:

	static bool Result() { std::cout << "2" << std::endl;  return ( false ); }

private:

};  //  class Test

template< typename F >
class Compare< F, F >
{
public:

	static bool Result() { std::cout << "3" << std::endl; return ( true ); }

private:

};  //  class Test



int main()  
{

	try
    {

    	std::cout << Compare< double, int, int, int, int, int, int >::Result() << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}