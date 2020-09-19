#include <iostream> 
#include <vector>

using namespace std;


class Test
{
public:

	Test() : mm( new int[45] ) {}

	Test( int i ) : mm( new int[45] ) { cout << "Lol" << endl; ++i; }

	Test( const Test& other ) : mm( new int[45] ) { cout << "Fuck" << endl; other.Display(); }

	void Display() const { cout << mm[8] << endl; }

	~Test() { cout << "Window" << endl; delete[] mm; }

private:

	int* mm;

};  //  class Test



int main()  
{

	try
    {

    	Test bb[10];

    	bb[8].Display();

    	vector< Test > oo( 10 );

    	oo.size();

    	Test ii = bb[9];

    	Test pp = std::move( ii );

    	pp.Display();

    	bb[8] = pp;

    	bb[4] = move( oo[5] );

    	vector< Test > llk = oo;

    	llk.size();

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}