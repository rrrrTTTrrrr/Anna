#include <iostream> 

using namespace std;


template< typename Y >
class Test
{
public:

	inline void Rec( Y that ) { if ( that == 0 ) { return; } Rec( that - 1 ); }

private:

};  //  class Test


inline void Ford( int f )
{
	if ( f == 0 )
		return;

	Ford( f - 1 );
}


int main()  
{

	try
    {

    	Test< int > oo;

    	oo.Rec( 89 );

    	int fdr = 890;

    	for ( int i = 0 ; i < 456 ; ++i )
    	{
    		if ( i % 2 == 0 )
    			--fdr;
    		else
    			fdr +=7;
    	}

    	Ford( fdr );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}