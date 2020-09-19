#include <iostream> 

using namespace std;


class Test
{
public:

	Test( int a, double b ) : m_a( a ), m_b( b ) { cout << "Constructor" << endl; }

	Test( const Test& other ) : m_a( other.m_a ), m_b( other.m_b ) { cout << "Copy Constructor" << endl; }

	Test& operator=( const Test& other ) { m_a = other.m_a; m_b = other.m_b; cout << "Assignment Operator" << endl; return ( *this ); }

	~Test() { cout << "Destructor" << endl; }

	// Move semantics part

	Test( Test&& other ) : m_a( other.m_a ), m_b( other.m_b ) { SetDefault1( other ); cout << "Move Constructor" << endl; }

	Test& operator=( Test&& other ) { m_a = other.m_a; m_b = other.m_b; SetDefault1( other ); cout << "Move Assignment Operator" << endl; return ( *this ); }

	void SetDefault( Test* t ) { t->m_a = ~0; t->m_b = ~0; cout << "SetDefault" << endl; }

	void SetDefault1( Test t ) { t.m_a = ~0; t.m_b = ~0; cout << "SetDefault1" << endl; }



private:


	int m_a;

	double m_b;

};  //  class Test



Test CopyTest( Test t )
{
	return ( t );
}

Test* CopyTest1( Test t )
{
	Test* newTest = new Test( t );

	return ( newTest );
}


int main()  
{

	try
	{

		Test t( 8, 97.44 );

		cout << "(((((((((((((((((((((((((((((((((((((((((((" << endl;

		Test t1 = t;

		cout << "(((((((((((((((((((((((((((((((((((((((((((" << endl;

		Test t2( t );

		cout << "(((((((((((((((((((((((((((((((((((((((((((" << endl;

		Test t3 = CopyTest( t );

		cout << "(((((((((((((((((((((((((((((((((((((((((((" << endl;

		t3 = CopyTest( t );		

		cout << "(((((((((((((((((((((((((((((((((((((((((((" << endl;

		Test* t4 = CopyTest1( t ); 

		cout << "(((((((((((((((((((((((((((((((((((((((((((" << endl;

		t4++;

	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
