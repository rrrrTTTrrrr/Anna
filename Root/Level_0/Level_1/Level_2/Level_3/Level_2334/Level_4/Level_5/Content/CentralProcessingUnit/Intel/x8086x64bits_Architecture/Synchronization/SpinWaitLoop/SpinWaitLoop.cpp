#ifndef  SPINWAITLOOP_CPP
#define  SPINWAITLOOP_CPP


#include "SpinWaitLoop.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include <thread>  //  std::thread
#include <iostream>  //  std::std::cout, std::endl
#include <vector>
#include <unistd.h>  //  Function sleep
#endif


namespace Universe 
{

    namespace CentralProcessingUnit
    {


    	// Forward declarations :
    	//
    	//  NONE
    	//









// *********************************************************************************   TESTING   ********************************************************************************






















    	DEBUG_TOOL(

            // This definition will be used to determine the total number of additions to perfrom. Then each thread will execute this number divided by
            // the number of threads additons
            constexpr UnsignedInteger64bits NumberOfAdditionsToExecute = 10000000;
            constexpr UnsignedInteger64bits NumberOfThreadsToCreate = 5;


            void Add( SpinWaitLoop* testLoopLock, UnsignedInteger64bits* sharedMemory )
            {
                sleep( 1 );

                UnsignedInteger64bits StopLimitForTheLoop = NumberOfAdditionsToExecute;

                for ( UnsignedInteger64bits index = 0 ; index < StopLimitForTheLoop ; ++index )
                {
                    testLoopLock->Lock();

                    *sharedMemory += 1;

                    testLoopLock->Unlock();
                }

            }


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
    		//		the functionality
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//          NONE
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//      1. true - if the object passed the test
    		//      2. false - otherwise
    		//
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//      1. A method does not work correctly - class Exception is thrown
    		//		2. There is no more free memory space - class std::bad_alloc is thrown
    		//		3. 
    		//
    		void SpinWaitLoop::Test()
    		{
                // Create a loop lock instance
                SpinWaitLoop testLoopLock_1;

                // This will be the shared memory
                UnsignedInteger64bits sharedMemory = 0;

                // Try the basic funtionality
                testLoopLock_1.Lock();
                testLoopLock_1.Unlock();

                // Create multiple threads od execution that will try to share the same resource using the loop lock object
                std::vector< std::thread* > testThreads( NumberOfThreadsToCreate );

                for ( UnsignedInteger64bits index = 0 ; index < NumberOfThreadsToCreate ; ++index )
                {
                    testThreads[ index ] = new std::thread( Add, &testLoopLock_1, &sharedMemory );
                }

                // Wait for all the created threads of execution to finish
                for ( UnsignedInteger64bits index = 0 ; index < NumberOfThreadsToCreate ; ++index )
                {
                    testThreads[ index ]->join();
                }

                // Ensure that the value is 1000000
                Assert_Test_MACRO( ( sharedMemory == ( NumberOfAdditionsToExecute * NumberOfThreadsToCreate ) ) );
            }

    	)  //  End of debug tool











    }  //  Namespace CentralProcessingUnit


}  //  Namespace Universe


#endif  //  SPINWAITLOOP_CPP





