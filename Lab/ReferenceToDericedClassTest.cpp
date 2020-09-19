#include <iostream> 

using namespace std;



class Test
{
public:

	void DIs() { std::cout << "Fuckkk" << std::endl; }

private:


};  //  class Test


class Test1
{
public:

	Test1( Test& kk ) : ff( kk ) {}

	void Foook() { ff.DIs(); }


private:

	Test& ff;

};  //  class Test


class Test2 : public Test, public Test1
{
public:

	Test2() : Test(), Test1( *reinterpret_cast< Test* >(this) ) {}

};  //  class Test



int main()  
{

	try
    {

    	Test2 kk;

    	kk.DIs();
    	kk.Foook();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}