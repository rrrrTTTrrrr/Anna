#include <iostream> 


using namespace std;

class Test
{
public:

	explicit inline Test( int t, int t1 ) : m_t1( t1 ), m_t( t ) {}

	static inline void Display() { cout << "Static Function" << endl; cout << m_t1 << endl; cout << m_t << endl; }

	int m_t1;


private:


	int m_t;

};  //  class Test



// The result is that the static function can not use any member neither public, protected or private

int main()  
{

	return ( 0 );
}