#include <iostream> 

using namespace std;


class Test
{
public:



private:

};  //  class Test

template< typename LambdaSignatureType >
class Sig
{
public:

    Sig( LambdaSignatureType&& oo ) :
    kk( oo )
    {}


	using LambdaSignature = LambdaSignatureType;


    LambdaSignatureType kk;

};



int main()  
{

	try
    {

    	int hh = 890;

    	Sig ll = [hh]() {};

        Sig< decltype( ll )::LambdaSignature > kk = [hh]() {};

        ll.kk();
        kk.kk();

    	



    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}