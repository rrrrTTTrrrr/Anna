#include <iostream> 


void Foo()
{
	std::cout << "Foo" << std::endl;
}

void Boo()
{
	return ( Foo() );

}


int main()  
{

	try
    {

    	Boo();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}