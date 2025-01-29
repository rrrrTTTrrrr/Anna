#include <iostream>  //  Class std::cout, Class std::endl


int main( int argc, const char* argv[], char *env[] )
{
	// Notify the server that the content is plain text
	std::cout << "Content-type: text/plain\n";

	// Loop on the environment variables array and print the content
  	for ( int index = 0 ; env[ index ] ; index++ )
  	{
  		// Print the current environment variable 
		std::cout << env[ index ] << std::endl;
	  	std::cout << std::endl;
  	}

  	// Return success
	return ( 0 );
}