#include <iostream> 


using namespace std;


void Display() 
{
	cout << "PapA" << endl;
}


int Do()
{
	return ( 8 );
}


void Doo( void (*mf)() )
{
	(*mf)();
}

void Fuck( int, int )
{
	cout << "MamA" << endl;
}


class Test
{
public:

	void DisplayTest() 
	{
		cout << "PapA" << endl;
	}


	int DoTest()
	{
		return ( 8 );
	}

};


template< typename T >
struct is_void1
{
	static const bool m_t = false;

	operator bool() { return m_t; }
};

template<>
struct is_void1< void >
{
	static const bool m_t = true;

	operator bool() { return m_t; }

};


template< typename T >
T Add( T one )
{
	return ( one );
}

template< typename T, typename... Args >
T Add( T first, Args... args )
{
	std::cout << __PRETTY_FUNCTION__ << "\n";
	std::cout << __func__ << "\n";

	return ( first + Add( args... ) );
}



// void Display() 
// {
// 	cout << "PapA" << endl;
// }



// functionAddress = &Display;

// template< typename TYPE1, typename TYPE2, typename TYPE3 >

#define INVOKE(x) Fuck(x)
#define INVOKE1(x,y) Fuck( x, y )
#define INVOKE2(f,x,y) f( x, y )
#define INVOKE3(f,...) f( __VA_ARGS__ )
#define INVOKE4(f) (*f)()
#define INVOKE5(f,...) ((*f)( __VA_ARGS__ ))
#define COMMA ,


int main()  
{

	try
    {

    	void (*p)() = &Display;

    	INVOKE4( p );


    	(*p)();


		decltype( p ) p1 = p;

		(*p1)();

		int (*p2)() = &Do;

		cout << (*p2)() << endl;

		decltype( Do() ) integer = Do();

		++integer;

		decltype( declval< Test >().DoTest() ) y = Test().DoTest();

		cout << y << endl; 

		Doo( &Display );

		cout << is_void1< decltype( (*p)() ) >() << endl;

		int sum = Add(1,2,3,4,5,6,7);

		cout << sum << endl;

		sum += 1;

		INVOKE3( Fuck, 8,9 );

    	void (*p7)(int,int) = &Fuck;

    	INVOKE5( p7, 8, 9 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}