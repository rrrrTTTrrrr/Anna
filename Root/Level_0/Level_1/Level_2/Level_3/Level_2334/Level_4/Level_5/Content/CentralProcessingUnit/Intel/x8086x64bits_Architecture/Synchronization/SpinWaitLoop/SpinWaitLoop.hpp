#ifndef  SPINWAITLOOP_HPP
#define  SPINWAITLOOP_HPP


#include "../../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../../../../../Content/CodingLanguages/Assembly/LanguageFeatures/Assembly_LanguageFeatures.hpp"  //  Function CentralPrcessingUnit_Pause
#include "../../../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../MemoryBarrier/MemoryBarrier.hpp"  //  Macro MemoryBarrier_EnsureAllDataWasReadAndWrittenToRAM
#include "../Intel_CPUandMemory_PrivateConversation/Intel_CPUandMemory_PrivateConversation.hpp"  //  Class Intel_CPUandMemory_PrivateConversation
#include "./SpinWaitLoopQueue/SpinWaitLoopQueue.hpp"  //  Class SpinWaitLoopQueue
#include "./SpinWaitLoopQueueRequestHandle/SpinWaitLoopQueueRequestHandle.hpp"  //  Class SpinWaitLoopQueueRequestHandle


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{

    namespace CentralProcessingUnit
    {



    	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
    	// cpp source file that the object is nested within
    	//
    	// Forward declarations :
    	//
    	//  NONE
    	//



    	// Class Information :
    	//
    	//  Purpose :
    	//
    	//		Use this object to create a lock for some purpose. This lock will be placed in the stack, this means that in order to share this lock across threads or
        //      processes, there should be one instance and a reference to it must be passed to each other process or thread of execution. Therefore, this object has no
        //      copy or move operations
    	//
   	    //  Description :
   	    //
    	//      1. This object is used as a base object in inheritance. Therefore it must have a few methods virtual. When an object has a virtual method, the C++ automatically
    	//		   creates a table with all the pointers to the virtual methods, where the pointer to the table is stored in the beginning of the object. The problem arises
    	//		   when a new method needs to be created with the same signature as one in the base object, and the use of pointers. Take a look at next example :
    	//
    	//             class Base
    	//             {
    	//                 void Display() { cout << "Lord" << endl; }
    	//             };
    	//
    	//             class Derived : public Base
    	//             {
    	//                 void Display(); { cout << "Help Me" << endl; }    -> Derived inherits Display from Base but needs another behavior
    	//             };
    	//
    	//         Now if a call is made :
    	//
    	//             Base* base = new Base;
    	//             Derived* derived = new Derived;
    	//
    	//             base->Display( 5 );   -> Outputs "Lord"
    	//             derived->Display();   -> Outputs "Help Me"
    	//
    	//         So far so good, a normal method is called by the static type of the pointer. This means no matter what the object the pointer is pointing to it will call
    	//		   the method of the type he was declared as. This is a problematic behavior in inheritance, we need to point to derived objects with base pointers and that
    	//		   the correct method will be called. But now :
    	//
    	//             void Do( Base* base ) { base->Display(); }
    	//
    	//             Base* base = new Base;
    	//             Derived* derived = new Derived;
    	//
    	//             Do( base );        -> Outputs "Lord"
    	//             Do( derived );     -> Outputs "Lord"
    	//
    	//         This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is picked dynamically by the actual
    	//		   type of the object. This is done by the pointer in the beginning of the object that points to the virtual table of the type. Of course it can be overloaded
    	//		   to the derived, but then if there is a deep inheritance a method will be needed to be overloaded for each one
    	//
        //      2. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
    	//
    	// 		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
    	//
    	//				1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
    	//							presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
    	//							lost, so it should be avoided in most cases
    	//
    	//				2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
    	//							   all the data and methods inside this part. This part will usually containt some methods and few data members
    	//
    	//				3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
    	//							 methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
    	//							 suffix _IMP
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		Too many to count
    	//
    	class SpinWaitLoop NotForInheritance
        {
        public:


            // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
            // generates a basic behavior for them :


            // Method Information :
    	    //
    	    //  Description :
            //
    		//   	Default Constructor,
    		//
    		//  Required arguments :
    		//
    		//   	User information needed :
    		//
        	//          NONE
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
        	//
        	//  Return value :
    		//
    		//   	NONE
    		//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline SpinWaitLoop();


            // This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
            // simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
            // any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
            // be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
            // macro will be used to add the following methods to each object :
            //
            //      1. State
            //
            ObjectInfrastructure_WithStateAlwaysReadyOnly_MACRO( SpinWaitLoop )


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Destructor, does not throw. Declared virtual to ensure correct deletion for derived objects
    		//
    		//  Required arguments :
    		//
    		//   	User information needed :
    		//
    		//          NONE
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	NONE
    		//
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline ~SpinWaitLoop() = default;


    		// The following methods are the interface of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to add this instance into the spin wait loop queue and wait until it is allowed to proceed
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
            //      NONE
            //
            //  Expectations :
            //
            //      1. The intel documentation is correct
            //      2. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline void Lock();


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to notify that this instance has done using and the next one can stop waiting
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
            //      NONE
            //
            //  Expectations :
            //
            //      1. A call to the method 'Lock' needs to happen before this method
            //      2. 
            //
            //  Possible errors :
            //
            //      NONE
            //
            inline void Unlock();


    		DEBUG_TOOL(

    			// This part of the object is dedicated for testing :


    			// Method Information :
    			//
    			//  Description :
    			//
    			//      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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
    			//			NONE
    			//
    			//  Expectations :
			    //
			    //		Please let the test pass lord!!
			    //
			    //  Possible errors :
    			//
    			//		It says there are no problems, which is even scarier, did I just wrote a working code??
    			//
    			static void Test();

    		)  //  End of debug tool


    	private:


            // Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
            DisableCopyAndMove_MACRO( SpinWaitLoop )


            // This object will be shared among the requests to wait to synchronize which should keep waiting and which is the one request that can stop waiting
            SpinWaitLoopQueue member_spinWaitLoopQueue;


    	};  //  Class SpinWaitLoop






























//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************


































    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Default Constructor,
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          NONE
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	NONE
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline SpinWaitLoop::SpinWaitLoop() :
        member_spinWaitLoopQueue()
    	{}


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to add this instance into the spin wait loop queue and wait until it is allowed to proceed
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
        //      NONE
        //
        //  Expectations :
        //
        //      1. The intel documentation is correct
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline void SpinWaitLoop::Lock()
        {

            // This object ( hopefully, and not on the stack memory segment ) will be in a register in the current thread's context and therefore only accessable 
            // to it. It will be used to communicate with spin wait loop queue member. The members and size of both the spin wait loop queue object and the spin
            // wait loop request handle object are identical, the only difference is the functionailty working on them. This is on purpose, to allow manipulating
            // the entire instance as an integer that can be contained in a single register, and not through the regular methods interface or data members. When
            // This instance is constructed, it initializes the matching part of the instance ( unsigned integer 32 high significant bits ) to 1, and the other 
            // to 0. It then locks the memory space of the spin wait loop, so no other central processing unit can access that memory, reads the current value
            // of the spin wait loop queue as unsigned integer 64 bits, increment the queue by 1 to notify that this instance also waits for a turn, but no 
            // changes will be made to the current request allowed to stop waiting part. The old value will be stored inside the instance, it will be used to 
            // determine if the method flow should keep waiting or not. The concept is that the instance layout is :
            //
            //                                       spin wait loop queue            current request allowed to 
            //                                          request handle                      stop waiting
            //                              ___________________________________ ___________________________________
            //                              |                                 | |                                 |
            //         Address   ->         00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
            //                              |                                                                     |
            //                     High significant bit                                                 Low significant bit
            //
            // Then when reading the spin wait loop queue as an 64 bits unsigned integer, the queue itself will be stored in the high significant bits of the
            // instance, and the current request allowed to stop waiting at the low significant bits. The high significant bits of the instance now caontain
            // an handle that can tell this instance when to stop waiting. Then this part of the instance will reamin constant for the remain of the method.
            // The low significant bits value will be changed in each iteration and checked if the values are equal. When the 2 values are equal there is no
            // more need to wait, and the flow of the method can proceed
            SpinWaitLoopQueueRequestHandle spinWaitLoopQueueRequestHandle;

            // Read the value from memory of the other instance as unsigned integer 64 bits, which will contain the 2 identifiers ( it is possible because 
            // the size of this object is 8 bytes which is the size of the register as well ), add this instance to it, and store back the new value into
            // the memory while not allowing any other central processing unit in the system to access the specific memory. At last, the other instance value
            // read from memory will be stored in this instance
            *( reinterpret_cast< UnsignedInteger64bits* >( &spinWaitLoopQueueRequestHandle ) ) = Intel_CPUandMemory_PrivateConversation::Read_Add_Write_ReturnOldValue< UnsignedInteger64bits >( reinterpret_cast< UnsignedInteger64bits* >( &member_spinWaitLoopQueue ), *( reinterpret_cast< UnsignedInteger64bits* >( &spinWaitLoopQueueRequestHandle ) ) );

            // Loop forever and ever
            while ( true )
            {

                // Check if both parts of the instance ( each 32 bits unsigned integer ) are equal
                if ( spinWaitLoopQueueRequestHandle.StopWaiting() == true )
                {
                    // Both parts of the instance are equal

                    // My turn has arrived!!!
                    break;
                }

                // Delay the central processing unit for a finite time. The method uses the 'PAUSE' instruction which provides a hint to the processor
                // that a thread is trying to lock using a loop. It will improve performance and power consumption
                CentralPrcessingUnit_Pause();

                // Update the 32 low significant bits of the instance with the valid value of in the spin wait loop queue
                spinWaitLoopQueueRequestHandle.member_currentRequestAllowedToStopWaiting = EnsureReadingVariableFromSystemMemory_MACRO( member_spinWaitLoopQueue.member_currentRequestAllowedToStopWaiting );
            }

            // Ensure that the compiler will not reorder write and read across this boundary
            CompilerBarrier_AllPreviousMemoryAccessesWillNotBeReorderedWithTheNextMemoryAccesses_MACRO
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to notify that this instance has done using and the next one can stop waiting
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
        //      NONE
        //
        //  Expectations :
        //
        //      1. A call to the method 'Lock' needs to happen before this method
        //      2. 
        //
        //  Possible errors :
        //
        //      NONE
        //
        inline void SpinWaitLoop::Unlock()
        {
            // This object will be used to lock a memory area from other central processing units to access it. Then it will read the value of the current
            // request allowed to stop waiting from memory, increment it by 1 and store the result back to memory
            Intel_CPUandMemory_PrivateConversation::Read_Add_Write< UnsignedInteger32bits >( &member_spinWaitLoopQueue.member_currentRequestAllowedToStopWaiting, 1 );
        }










    }  //  Namespace CentralProcessingUnit

}  //  Namespace Universe


#endif  // SPINWAITLOOP_HPP