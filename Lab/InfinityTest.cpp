#include <iostream> 




double lol(double z)
{
  double lolo=0;
  for(double n=1 ; n<z ; ++n )
  {
  	lolo = lolo + ( 1 / (double)n );
  }

  return ( lolo );
}


int main()
{
	double result = lol( 100000000000 );
	std::cout << result << std::endl;
}


