#include <iostream> 

using namespace std;


template< typename T >
class Test
{
public:

	Test() : mm( new T[88] ) {}

	~Test() { delete[] mm; }

	Test( const Test& ) : mm(0) {}

	Test& operator=( const Test& ) { return (*this ); }

	void Display() {}

private:

	T* mm;

};  //  class Test


class Test1
{
public:

	Test1() : mm( new int[88] ) {}

	~Test1() { delete[] mm; }

	Test1( const Test1& ) : mm(0) {}

	Test1& operator=( const Test1& ) { return (*this ); }

	void Display() {}

private:

	int* mm;

};  //  class Test



int main()  
{

	try
    {

    	Test< Test1 > arr[89];

    	arr[9].Display();



    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}