#include <iostream>

#include "IntervalMap.hpp"


int main()
{


	interval_map< uu, uuuu > mmmm( 989 );

	// Check wrong using
	mmmm.assign( 45, 44, 44 );

	for(std::map<int,int>::iterator it = mmmm.m_map.begin(); it != mmmm.m_map.end(); ++it) 
	{
	  std::cout << it->first << "  " << it->second << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;

	// Check all range
	mmmm.assign( std::numeric_limits< int >::lowest(), std::numeric_limits< int >::max(), 2000 );
	mmmm.assign( std::numeric_limits< int >::lowest(), std::numeric_limits< int >::max(), 2345 );
	mmmm.assign( std::numeric_limits< int >::lowest(), std::numeric_limits< int >::max(), 23453 );
	mmmm.assign( std::numeric_limits< int >::lowest(), std::numeric_limits< int >::max(), 2222 );

	for(std::map<int,int>::iterator it = mmmm.m_map.begin(); it != mmmm.m_map.end(); ++it) 
	{
	  std::cout << it->first << "  " << it->second << std::endl;
	}
	std::cout << std::endl << std::endl << std::endl;


	// ///////////////////////////////////////////////////////////////////////////////////////////////


	// interval_map< int, int > mmmm1( 989 );	

	// // Check key begin bigger then all exisiting keys
	// mmmm1.assign( 45, 55, 2000 );
	// mmmm1.assign( 66, 77, 2345 );
	// mmmm1.assign( 88, 101, 23453 );

	// for(std::map<int,int>::iterator it = mmmm1.m_map.begin(); it != mmmm1.m_map.end(); ++it) 
	// {
	//   std::cout << it->first << "  " << it->second << std::endl;
	// }
	// std::cout << std::endl << std::endl << std::endl;

 //    std::map< int, int > m_map1 = mmmm1.m_map;

	// // Add elements
	// mmmm1.assign( 48, 51, 2000 );
	// mmmm1.assign( 66, 67, 2345 );
	// mmmm1.assign( 88, 101, 23453 );
	// mmmm1.assign( 48, 55, 2000 );
	// mmmm1.assign( 99, 100, 23453 );

	// if ( m_map1 != mmmm1.m_map )
	// {
	// 	std::cout << "BADDD" << std::endl;
	// 	return 1;
	// }

	// for(std::map<int,int>::iterator it = mmmm1.m_map.begin(); it != mmmm1.m_map.end(); ++it) 
	// {
	//   std::cout << it->first << "  " << it->second << std::endl;
	// }
	// std::cout << std::endl << std::endl << std::endl;


	// ///////////////////////////////////////////////////////////////////////////////////////////////



	// interval_map< int, int > mmmm2( 989 );

	// // Add elements
	// mmmm2.assign( 55, 56, 2000 );
	// mmmm2.assign( 59, 62, 2345 );
	// mmmm2.assign( 62, 63, 23453 );
	// mmmm2.assign( 63, 88, 2000 );
	// mmmm2.assign( 99, 100, 23453 );


	// for(std::map<int,int>::iterator it = mmmm2.m_map.begin(); it != mmmm2.m_map.end(); ++it) 
	// {
	//   std::cout << it->first << "  " << it->second << std::endl;
	// }
	// std::cout << std::endl << std::endl << std::endl;



	// ///////////////////////////////////////////////////////////////////////////////////////////////


	// interval_map< int, int > mmmm3( 989 );

	// // Add elements
	// mmmm3.assign( 55, 56, 2000 );
	// mmmm3.assign( 59, 62, 2345 );
	// mmmm3.assign( 62, 63, 23453 );
	// mmmm3.assign( 63, 88, 2000 );
	// mmmm3.assign( 99, 100, 23453 );


	// for(std::map<int,int>::iterator it = mmmm3.m_map.begin(); it != mmmm3.m_map.end(); ++it) 
	// {
	//   std::cout << it->first << "  " << it->second << std::endl;
	// }
	// std::cout << std::endl << std::endl << std::endl;

	// mmmm3.assign( 30, 134, 11 );


	// for(std::map<int,int>::iterator it = mmmm3.m_map.begin(); it != mmmm3.m_map.end(); ++it) 
	// {
	//   std::cout << it->first << "  " << it->second << std::endl;
	// }
	// std::cout << std::endl << std::endl << std::endl;


	// mmmm3.assign( 59, 62, 2345 );
	// mmmm3.assign( 62, 63, 23453 );
	// mmmm3.assign( 63, 88, 2000 );
	// mmmm3.assign( 99, 100, 23453 );


	// for(std::map<int,int>::iterator it = mmmm3.m_map.begin(); it != mmmm3.m_map.end(); ++it) 
	// {
	//   std::cout << it->first << "  " << it->second << std::endl;
	// }
	// std::cout << std::endl << std::endl << std::endl;


	// ///////////////////////////////////////////////////////////////////////////////////////////////


	// interval_map< int, int > mmmm4( 2 );

	// // Add elements
	// mmmm4.assign( 55, 56, 1 );
	// mmmm4.assign( 59, 62, 3 );
	// mmmm4.assign( 62, 63, 4 );
	// mmmm4.assign( 63, 88, 1 );
	// mmmm4.assign( 99, 100, 4 );
	// mmmm4.assign( 59, 62, 3 );
	// mmmm4.assign( 62, 63, 4 );
	// mmmm4.assign( 63, 88, 1 );
	// mmmm4.assign( 99, 100, 4 );
	// mmmm4.assign( 55, 56, 1 );
	// mmmm4.assign( 59, 62, 3 );
	// mmmm4.assign( 62, 63, 4 );
	// mmmm4.assign( 63, 88, 1 );
	// mmmm4.assign( 99, 100, 4 );
	// mmmm4.assign( 59, 62, 3 );
	// mmmm4.assign( 62, 63, 4 );
	// mmmm4.assign( 63, 88, 1 );
	// mmmm4.assign( 99, 100, 4 );


	// for(std::map<int,int>::iterator it = mmmm4.m_map.begin(); it != mmmm4.m_map.end(); ++it) 
	// {
	//   std::cout << it->first << "  " << it->second << std::endl;
	// }
	// std::cout << std::endl << std::endl << std::endl;


	// mmmm4.assign( 700, 5000, 5 );
	// mmmm4.assign( 700, 5000, 6 );
	// mmmm4.assign( 74, 5000, 6 );
	// mmmm4.assign( 88, 156, 11 );


	// for(std::map<int,int>::iterator it = mmmm4.m_map.begin(); it != mmmm4.m_map.end(); ++it) 
	// {
	//   std::cout << it->first << "  " << it->second << std::endl;
	// }
	// std::cout << std::endl << std::endl << std::endl;


	// mmmm4.assign( 88, 156, 12 );
	// mmmm4.assign( -200, 200, 44 );
	// mmmm4.assign( -300, 9000, 77 );
	// mmmm4.assign( -300, 9000, 88 );
	// mmmm4.assign( -300, 9000, 99 );
	// mmmm4.assign( -300, 9000, 2 );


	// for(std::map<int,int>::iterator it = mmmm4.m_map.begin(); it != mmmm4.m_map.end(); ++it) 
	// {
	//   std::cout << it->first << "  " << it->second << std::endl;
	// }
	// std::cout << std::endl << std::endl << std::endl;


	// ///////////////////////////////////////////////////////////////////////////////////////////////


	// interval_map< int, int > mmmm5( 1111 );

	// // Add elements
	// mmmm5.assign( 55, 56, 1 );
	// mmmm5.assign( 59, 62, 3 );
	// mmmm5.assign( 62, 63, 4 );
	// mmmm5.assign( 63, 88, 1 );
	// mmmm5.assign( 99, 100, 4 );
	// mmmm5.assign( 888, 999, 3 );
	// mmmm5.assign( 2345, 12111, 4 );

	// for(std::map<int,int>::iterator it = mmmm5.m_map.begin(); it != mmmm5.m_map.end(); ++it) 
	// {
	//   std::cout << it->first << "  " << it->second << std::endl;
	// }
	// std::cout << std::endl << std::endl << std::endl;


	// mmmm5.assign( 134, 25000, 7777 );
	// mmmm5.assign( 134, 25000, 8888 );
	// mmmm5.assign( 134, 25001, 9999 );

	// for(std::map<int,int>::iterator it = mmmm5.m_map.begin(); it != mmmm5.m_map.end(); ++it) 
	// {
	//   std::cout << it->first << "  " << it->second << std::endl;
	// }
	// std::cout << std::endl << std::endl << std::endl;
}