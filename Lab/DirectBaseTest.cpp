#include <iostream> 

using namespace std;


class Test
{
public:

	void Old() { std::cout << "Free me" << std::endl; }


private:

};  //  class Test

class Test1 : public Test
{
public:



private:

};  //  class Test

class Test2 : public Test1
{
public:


private:

};  //  class Test



int main()  
{

	try
    {

    	Test* jj = new Test2;

    	jj->Old();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}