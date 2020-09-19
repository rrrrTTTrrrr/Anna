#include <iostream> 


using namespace std;
class Test
{
public:

	virtual void Lol() { cout << "Yes" << endl; }

private:

};  //  class Test

class Testy : public Test
{
public:

	virtual void Lol() { cout << "No" << endl; }

private:

};  //  class Test

int main()  
{

	try
    {

    	Test rr;

    	rr.Lol();

    	Testy uu;

    	uu.Lol();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}