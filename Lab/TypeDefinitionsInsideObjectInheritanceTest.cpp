#include <iostream> 

using namespace std;


class Test
{
public:

	using tt = Test;

	void Display() { std::cout << "Air" << std::endl; }

private:

};  //  class Test

class Tedty : public Test
{
public:

	using tt = Tedty;
	using basett = Test;

	void Display() { std::cout << "AirsUpply" << std::endl; }

private:
};


int main()  
{

	try
    {

    	Tedty::basett kk;

    	kk.Display();


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}