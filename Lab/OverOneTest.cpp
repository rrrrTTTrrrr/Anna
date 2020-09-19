#include <iostream> 


using namespace std;
class Test
{
public:



private:

};  //  class Test


void Lol( long begin )
{
    long count = 0;

	double sum = 0;

	double current = 1 / (double)begin;

	long base = begin + 1;

	while ( sum <= 1 )
	{
		++count;

		sum += current;

		current = 1 / (double)base;

		++base;
	}

	cout << count << "    " << sum << endl;
}


void Summm()
{
	double sum = 0;

	for ( int i = 1 ; i < 10 ; ++i )
	{
		sum += 1 /(double)i;
	}

	cout << sum << endl;
}


int main()  
{

	try
    {

    	Summm();

    	cout << endl;

    	Lol( 10 );
    	Lol( 100 );
    	Lol( 1000 );
    	Lol( 10000 );
    	Lol( 100000 );
    	Lol( 1000000 );
    	Lol( 10000000 );
    	Lol( 100000000 );
    	Lol( 1000000000 );

    	cout << endl;

    	Lol( 10 );
    	Lol( 20 );
    	Lol( 30 );
    	Lol( 40 );
    	Lol( 50 );
    	Lol( 60 );
    	Lol( 70 );
    	Lol( 80 );
    	Lol( 90 );

    	cout << endl;

    	Lol( 10 );
    	Lol( 15 );
    	Lol( 20 );
    	Lol( 25 );
    	Lol( 30 );
    	Lol( 35 );
    	Lol( 40 );
    	Lol( 45 );
    	Lol( 50 );


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}