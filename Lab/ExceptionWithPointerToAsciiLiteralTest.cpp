#include <iostream> 

using namespace std;


class Exception
{
public:

	Exception( const char* message ) : m_message( message ) {}

	void Display() const { std::cout << m_message << std::endl; }

private:

	const char* m_message;

};  //  class Test


void Goo()
{
	const char* kk = "Fuckkkkkkk";

	throw( Exception( kk ) );
}

void Loo()
{
	const char kk[] = "Fuckkkkkkk";

	throw( Exception( kk ) );
}



int main()  
{

	try
    {

    	//throw( Exception( "Lorddddddddddddddddddddddddddddddd" ) );

    	//Goo();

    	Loo();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }
	catch ( const Exception& exception )
    {
    	exception.Display();
    }

    return ( 0 );
}