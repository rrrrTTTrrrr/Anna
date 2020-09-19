#include <iostream> 


using namespace std;

class Test
{
public:

	void Display() { cout << "Wippppppppi" << endl; }

private:

	unsigned long m_t;

	char m_r;

	char m_u;

};  //  class Test


int main()  
{
	cout << sizeof( Test ) << endl;


	return ( 0 );
}