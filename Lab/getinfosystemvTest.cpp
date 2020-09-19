#include <iostream> 
#include <sys/shm.h>


using namespace std;


int main()  
{

	try
	{
		struct shminfo info;

		shmctl( 0, IPC_INFO, ( struct shmid_ds* )&info );


		cout << info.shmmax << endl;
		cout << info.shmmni << endl;
	}
	catch ( const exception& exception )
	{
		cout << exception.what() << endl;
	}


	return ( 0 );
}
