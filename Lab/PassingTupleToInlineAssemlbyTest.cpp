#include <iostream> 
// #include "../../Infrastructure/Abilities/Tuple/Tuple.hpp"

using namespace std;


const int yy = 9;

constexpr int LOl()
{
	return ( yy * 8 );
}

template< int yy, typename... tt >
class Philo
{
public:
	Philo() { std::cout << "Kaparaaaaaa" << std::endl; }
};

template< typename... tt >
class Philo< 0, tt... >
{
public:
	Philo() { std::cout << "Nesamaaaaaaaaaaaaa" << std::endl; }
};

template< typename... tt >
class Phil
{
public:
	Phil() { Philo< sizeof...( tt ), tt... >(); }
};

template< typename... tt >
class Phili
{
public:
	Phili() { Philo< LOl(), tt... >(); }
};




class Weirdo
{
public:
	int y;
};

template< typename... tt >
class Philow
{
public:
	Philow() { std::cout << "ROCKKKKKKKKKKKKKKKKKK" << std::endl; }
};

template< typename... tt >
class Philow< int, tt... >
{
public:
	Philow() { std::cout << "ROLLLLLLLLLLLLLLLLLLLLLLLL" << std::endl; }
};

template< typename... tt >
class PhiliP
{
public:
	PhiliP() { Philow< tt... >(); }
};

#define hh Realllll
constexpr const char* oo = "Realllll";
constexpr const char* Live()
{
	return ( "Realllll" );
}

class hh
{
public:
	hh() { std::cout << "Friend" << std::endl; }
};


#define lol( kk )  kk ## Karamel

int main()  
{

	try
    {

    	// Universe::Abilities::Tuple< int > mm( 9 );
    	// // int array[2] = {0,1};

    	// __asm__ volatile ( "MOV %0, 2\n\t"
    	// 				   : "=ir" ( mm.Entry< 0 >() ) 
    	// 				   : : "memory" );

    	// std::cout << mm.Entry< 0 >() << std::endl;

    	Phil< int, double > rr;
    	Phili< int, double > rr1;
    	PhiliP< int, double > rr2;
    	PhiliP< double > rr3;
    	Realllll mm;

    	// std::cout << lol( Gooooo ) << std::endl;

    	long jj = 0;

    	__asm__ volatile ( "MOVQ RAX, -77\n\t"
    					   "BT RAX, 63\n\t"
    					   "JC LOAD\n\t"
    					   "MOVQ %0, 10\n\t"
    					   "JMP END\n\t"
    					   "LOAD:\n\t"
    					   "MOVQ %0, 22\n\t"
    					   "END:\n\t"
    					   : "+ir" ( jj )
    					   : 
    					   : "memory", "cc" );

    	std::cout << jj << std::endl;


    	__asm__ volatile ( "MOVQ RAX, 77\n\t"
    					   "BT RAX, 63\n\t"
    					   "JC LOAD1\n\t"
    					   "MOVQ %0, 10\n\t"
    					   "JMP END1\n\t"
    					   "LOAD1:\n\t"
    					   "MOVQ %0, 22\n\t"
    					   "END1:\n\t"
    					   : "+ir" ( jj )
    					   : 
    					   : "memory", "cc" );

    	std::cout << jj << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}