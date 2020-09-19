#include <iostream> 
#include <map>
#include <vector>
#include <limits>

using namespace std;


template< typename K, typename V >
class interval_map {

public:
    
    // constructor associates whole range of K with val by inserting (K_min, val)
    // into the map
    interval_map( V const& val ) 
    {
        m_map.insert( m_map.end(), std::make_pair( std::numeric_limits< K >::lowest(), val ) );
    }

    std::map< K, V > m_map;

};



int main()  
{

	try
    {

    	interval_map< int, int > kk( 55 );

        kk.m_map.insert( kk.m_map.end(), std::make_pair( 56, 54 ) );
        kk.m_map.insert( kk.m_map.end(), std::make_pair( 4, 53 ) );
        kk.m_map.insert( kk.m_map.end(), std::make_pair( 45, 52 ) );
        kk.m_map.insert( kk.m_map.end(), std::make_pair( 3, 51 ) );





		vector<int> v;
		for(map<int,int>::iterator it = kk.m_map.begin(); it != kk.m_map.end(); ++it) {
		  v.push_back(it->first);
		  cout << it->first << "  ";
		}
		std::cout << std::endl;

		map<int,int>::iterator yy = --kk.m_map.end();
		map<int,int>::iterator yyff = --( --kk.m_map.end() );
		map<int,int>::iterator fff = --( --( --kk.m_map.end() ) );
		std::cout << yy->second << std::endl;
		std::cout << fff->second << std::endl;
		kk.m_map.erase( yyff );
		std::cout << yy->second << std::endl;
		std::cout << fff->second << std::endl;

		// map<int,int>::iterator zzz = kk.m_map.begin();
		// std::cout << zzz->second << std::endl;
  //       kk.m_map.insert( zzz, std::make_pair( 13, 888888 ) );
		// std::cout << zzz->second << std::endl;
		// std::cout << (++zzz)->second << std::endl;

		v.clear();
		for(map<int,int>::iterator it = kk.m_map.begin(); it != kk.m_map.end(); ++it) {
		  v.push_back(it->first);
		  cout << it->first << "  ";
		}
		std::cout << std::endl;


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}