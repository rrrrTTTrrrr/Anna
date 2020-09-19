#include <iostream> 


using namespace std;





class Test
{
private:

		class Test1;
public:

	Test( int m ) : m_t( m ) {} 

	Test1 Get() { return ( Test1( *this ) ); }

private:

	int m_t;



	class Test1
	{
	public:

		Test1( Test& test ) : m_test( test ) {}

	private:

		Test& m_test;


		friend inline void operator+=( int tt, Test1 tt1 );
	};

		friend inline void operator+=( int tt, Test& tt1 );

	friend inline void operator+=( int tt, Test1 tt1 );


};  //  class Test

inline void operator+=( int tt, Test& tt1 )
{
	tt += tt1.m_t;
}

inline void operator+=( int tt, Test::Test1 tt1 )
{
	tt += tt1.m_test.m_t;
}

int main()  
{

	Test tt( 56 );

	int r = 0;

	r += tt.Get();

	cout << r << endl;

	return ( 0 );
}