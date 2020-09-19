#include <iostream> 
#include <thread>
#include <signal.h>
#include <unistd.h>
// #include <asm/switch_to.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include "../../Infrastructure/Memory/MemoryAccessSynchronization/Intel_CPUandMemory_PrivateConversation/Intel_CPUandMemory_PrivateConversation.hpp"
#include "../../Infrastructure/Memory/MemorySegments/Stack/Integer_AllowAccessOnlyToOneCPU/Integer_AllowAccessOnlyToOneCPU.hpp"


using namespace std;
using namespace Universe;

// bool occupied = false;

int y = 0;


// Memory::Intel_CPUandMemory_PrivateConversation< bool > ggggg( &occupied );

Memory::Stack::Integer_AllowAccessToOnlyOneCPUeachTime< bool > ggggg1( false );

// int Do( int* ptr, int value )
// {


// 	int tmp = *ptr;

// 	// __asm volatile ("" : : : "memory");
// 	// __sync_synchronize();
// 	barrier();

// 	*ptr += value;

// 	return ( tmp );
// } 






void Lock()
{
	// static int number = 0;


	// cout << "Lock entered - " << number << endl;

    while ( ggggg1.ReadCurrentValueAndWriteOldValue( true ) == true )
    {

   //      if (  )
   //      {
			// // cout << "The object is free" << endl;

   //          break;
   //      }

        // sleep( 30 );

        // cout << "Still running" << endl;

    }

    // ++number;
}


void Unlock()
{
	// static int number = 0;
	// cout << "Unlock entered - " << number << endl;


    if ( ggggg1.ReadCurrentValueAndWriteOldValue( false ) == false )
    {
        std::cout << "Error" << std::endl;
    }

	// cout << "Unlock due" << endl;

	// raise( SIGINT );


	// ++number;
}



void Add()
{

	for ( int i = 0 ; i < 100000 ; ++i )
	{
	Lock();

	// cout << "Locked" << endl;

	// cout << y << endl;

	++y;

	cout << y << endl;

	Unlock();

	// cout << "Unlocked" << endl;
	}
}

void Add1()
{

	for ( int i = 0 ; i < 100000 ; ++i )
	{
	Lock();

	// cout << "Locked 1" << endl;

	++y;

	cout << y << endl;

	Unlock();

	// cout << "Unlocked 1" << endl;
	}
}

void Add2()
{

	for ( int i = 0 ; i < 100000 ; ++i )
	{
	Lock();

	// cout << "Locked 2" << endl;

	// cout << "BEFORE  " << y << "  2" << endl;

	++y;

	cout << y << endl;

	// cout << "AFTER   "  << y << "  2" << endl;

	Unlock();

	// cout << "Unlocked 2" << endl;
	}
}

void Add3()
{

	for ( int i = 0 ; i < 100000 ; ++i )
	{
	Lock();

	// cout << "Locked 3" << endl;

	// cout << "BEFORE    " << y << "  3" << endl;

	++y;

	cout << y << endl;

	// cout << "AFTER     "  << y << "  3" << endl;

	Unlock();

	// cout << "Unlocked 3" << endl;
	}
}

void Add4()
{

	for ( int i = 0 ; i < 100000 ; ++i )
	{
	Lock();

	// cout << "Locked 4" << endl;

	// cout << "BEFORE    " << y << "  4" << endl;

	++y;

	cout << y << endl;

	// cout << "AFTER     "  << y << "  4" << endl;

	Unlock();

	// cout << "Unlocked 4" << endl;
	}
}


int main()  
{

	try
    {

    	std::thread g( &Add );
    	std::thread e( &Add1 );
    	std::thread m( &Add2 );
    	std::thread g1( &Add3 );
    	std::thread g2( &Add4 );

    	g.join();
    	e.join();
    	m.join();
    	g1.join();
    	g2.join();


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }
    catch ( const ErrorHandling::Exception& exception )
    {
    	exception.TellMe();
    }

    return ( 0 );
}