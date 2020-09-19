#include <iostream> 
#include <chrono>
#include <thread>


using namespace std;




int arrayee[1000000000] = {0};




void Set( int start, int size )
{
	for ( int i = start ; i < size ; ++i )
	{
		arrayee[i] = i;
	}
}


int main()  
{

	try
    {

		chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

		for ( int i = 0 ; i < 1000000000 ; ++i )
		{
			arrayee[i] = i;
		}

		chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();

		chrono::duration<double> elapsed = t2 - t1;

		cout << elapsed.count() << endl;


		chrono::high_resolution_clock::time_point t3 = chrono::high_resolution_clock::now();

		std::thread f1( &Set, 0, 180000000 );

		std::thread f2( &Set, 180000000, 180000000 );

		std::thread f3( &Set, 360000000, 180000000 );

		std::thread f4( &Set, 540000000, 180000000 );

		std::thread f5( &Set, 720000000, 180000000 );

		std::thread f6( &Set, 900000000, 100000000 );


		f1.join();
		f2.join();
		f3.join();
		f4.join();
		f5.join();
		f6.join();

		chrono::high_resolution_clock::time_point t4 = chrono::high_resolution_clock::now();

		chrono::duration<double> elapsed1 = t4 - t3;

		cout << elapsed1.count() << endl;


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}