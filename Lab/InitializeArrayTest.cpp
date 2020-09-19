#include <iostream> 

using namespace std;


class Test
{
public:

	Test() { std::cout << "Lord" << std::endl; }
	Test( int ) { std::cout << "Lord Help me" << std::endl; }
	void Display() { std::cout << "Wow" << std::endl; }

private:

};  //  class Test


class Cock
{
public:

	Cock( const Test& oo ) : ll( new Test[4] ) { ll[1] = oo; }

    ~Cock() { delete[] ll; }

    Cock( const Cock&) : ll() {}
    Cock& operator=(const Cock&) {return ( *this );}

	Test* ll;

};  //  class Cock


template< typename T >
class Cocku
{
public:

    Cocku() : ll( new T[1000000] ) { ll[1].Display(); }

    ~Cocku() { delete[] ll; }

    Cocku( const Cocku&) {}
    Cocku& operator=(const Cocku&) {return ( *this );}

    T* ll;

};  //  class Cock


class Testy
{
public:

    inline Testy() : 
    member_array{ new long[3] }
    { 
        std::cout << "Before" << std::endl; 
        //Memory::Operations::Set< long >( member_array, 3, 0 ); 
        std::cout << "After" << std::endl; 
    }

    inline Testy( int o) : 
    member_array{ new long[3] } 
    { 
        member_array[0] = o;    
        member_array[1] = o;    
        member_array[2] = o;    

        //std::cout << member_array[0] << std::endl;

        std::cout << "Fuckkkkk" << std::endl; 
        //Memory::Operations::Set< long >( member_array, 3, u ); 
    }

    inline Testy( const Testy& ) : 
    member_array( new long[3] ) 
    { 
        //Memory::Operations::Copy< long >( member_array, other.member_array, 3 ); 
    }

    inline Testy& operator=( const Testy& ) 
    { 
        //Memory::Operations::Copy< long >( member_array, other.member_array, 3 ); 
        return ( *this ); 
    }

    inline ~Testy() { delete[] member_array; }


    long* member_array;

};



int main()  
{

	try
    {

    	// int uu[89] = {0};

    	// std::cout << uu[45] << std::endl;

    	// int uu1[45] = {int()};

    	// std::cout << uu1[45] << std::endl;

    	// Test tt[34];

    	// tt[32].Display();

    	// Cock gg;

        // Test* ii = new Test[ 2 ];

        // ii[1].Display();

        // Cock jj( Test( 88 ) );

        // jj.ll[2].Display();

        // Cocku< Test > jj1;

        // jj1.ll[2].Display();

        // delete[] ii;


        Testy* hh = new Testy[40];

        std::cout << hh[4].member_array[0] << std::endl;
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}