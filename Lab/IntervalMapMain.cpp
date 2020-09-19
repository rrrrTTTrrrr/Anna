#include "IntervalMap.hpp"


// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a function IntervalMapTest() here that tests the
// functionality of the interval_map, for example using a map of unsigned int
// intervals to char.

int main(int argc, char* argv[]) {

    interval_map< int, char > imap( 'A' );

    imap.assign( 3, 6, 'E' );

    imap.assign( 3, 4, 'Z' );

    imap.assign( 4, 5, 'R' );

    imap.assign( 3, 56, 'S' );

    imap.assign( 7, 11, 'S' );

    imap.assign( 79, 110, 'A' );

    imap.assign( 45, 67, 'w' );  

    imap.assign( 72, 45, 'e' );  

    imap.assign( 72, 75, 'q' );

    imap.assign( 890, 1567, 'T' );

    imap.assign( -2147483648, -3, 'P' );

    imap.assign( 4000, 2147483647, 'Y' );

    imap.assign( 5000, 2147483647, 'O' );

    imap.assign( -2147483648, 2, 'P' );

    imap.display();

    return 0;
}



