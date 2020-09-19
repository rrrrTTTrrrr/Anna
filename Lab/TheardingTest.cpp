#include <iostream> 
#include <thread>
#include <unistd.h>

using namespace std;


class Test
{
public:

	Test() : m_t( 0 ) {}

	Test( int jj ) : m_t( new int( jj ) ) {}

	Test( const Test& other ) : m_t() { std::cout << *(other.m_t) << std::endl; 	std::cout << "Loker" << std::endl; sleep( 4 ); 	std::cout << "Dffffff" << std::endl; m_t = other.m_t; std::cout << *m_t << std::endl; }

	~Test() { delete m_t; }

	void gk() {}

private:

	int* m_t;

};  //  class Test


Test tt( 34 );



void Second( int uu )
{
	std::cout << uu << std::endl;

	Test jj( tt );

	std::cout << "Dfffffook" << std::endl;

	jj.gk();

}



void First()
{
	std::cout << "Dfffffookyyyyyyyyyyyyy" << std::endl;


	std::thread ff( Second, 34 );

	std::cout << "Sddddddddddddddddddd" << std::endl;


	sleep( 1 );

	std::cout << "Fdddddddddddddddddddddddd" << std::endl;


	tt.~Test();

	std::cout << "WWwWwWWwwwwwwwwwwwwwwwwwww" << std::endl;


	ff.join();
}





int main()  
{

	try
    {

    	First();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}