#include <iostream> 

using namespace std;


class Test
{
public:

	Test() { cout << "Test constructor" << endl; }
	~Test() { cout << "Test Destructor" << endl; }

	void Print() { cout << "Print shit" << endl; }

protected:

	int m_s;

private:

	int m_d;

};  //  class Test


class Low : private Test
{
public:

	Low() { cout << "Low constructor" << endl; }
	~Low() { cout << "Low Destructor" << endl; }

	void PrintLow() { Print(); cout << endl << m_s << endl; }
};

int main() 
{
	Low l;

	l.PrintLow();


	return ( 0 );
}
