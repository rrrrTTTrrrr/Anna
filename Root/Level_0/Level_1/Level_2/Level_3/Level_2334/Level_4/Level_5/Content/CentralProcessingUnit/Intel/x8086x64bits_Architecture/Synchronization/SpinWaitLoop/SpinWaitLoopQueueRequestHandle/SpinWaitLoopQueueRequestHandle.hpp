#ifndef  SPINWAITLOOPQUEUEREQUESTHANDLE_HPP
#define  SPINWAITLOOPQUEUEREQUESTHANDLE_HPP


#include "../../../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../SpinWaitLoopQueue/SpinWaitLoopQueue.hpp"  //  Class SpinWaitLoopQueue


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
        //      NONE
        //



    	// Class Information :
    	//
    	//  Purpose :
    	//
        //      Each request to wait for the turn is performed using this object. To wait an instance of this object is created in the local context of the function
        //      performing the spin wait loop. It will be initialized as follows :
        //
        //              member_currentRequestAllowedToStopWaiting = 0
        //              member_spinLoopWaitQueueRequestHandle = 1
        //
        //      It is created in the context of each method so it is not shared, only the spin wait loop queue is shared, therefore to construct this object a reference
        //      to the spin wait loop queue is needed. It will add to the current valus in its values and store it back, so that all others can also see the request. The
        //      old value in the spin wait loop queue member will be stored and used to work with the spin wait loop queue, to continousuly update the current request 
        //      allowed to stop waiting and check if it matches the handle. When it matches it can stop waiting, its turn has arrived!
        //
        //      The instance layout :
        //
        //                                                                spin wait loop queue            current request allowed to 
        //                                                                   request handle                      stop waiting
        //                                                        ___________________________________ ___________________________________
        //                                                        |                                 | |                                 |
        //                                   Address   ->         00000000 00000000 00000000 00000000 00000000 00000000 00000000 00000000
        //                                                        |                                                                     |
        //                                               High significant bit                                                 Low significant bit
    	//
    	//  Description :
    	//
        //      1. This object does not contain a 'InstanceState' instance to ensure 8 byte alignment
    	//
    	// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
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
    	//							 suffix __Private
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		Too many to count
    	//
    	class SpinWaitLoopQueueRequestHandle NotForInheritance
    	{
    	public:


            // This number represents the current request in the queue that was allowed to stop waiting. This is the "shared" part, which its value
            // is refetched in the spin wait loop to check if the matches the wait request handler of this instance 
            UnsignedInteger32bits member_currentRequestAllowedToStopWaiting;

            // This will store the handle to the request to wait for this instance turn. This value will be initialized in the constructor and will
            // not be changed from there. It will conatin the value of the queue in the time of the request. This value will be used in the spin 
            // wait loop, to allow the instance to check if it can stop waiting.
            UnsignedInteger32bits member_spinLoopWaitQueueRequestHandle;


            // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
            // generates a basic behavior for them :


            // Method Information :
            //
            //  Description :
            //
            //      Constructor,
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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline SpinWaitLoopQueueRequestHandle();


            // The following methods are the interface of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to check in each loop if it should keep waiting or not
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
            //      1. true - if the it should keep waiting
            //      2. false - otherwise
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            constexpr Boolean StopWaiting();


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
    			static inline void Test() __attribute__ (( __unused__ ));

    		)  //  End of debug tool


    	};  //  Class SpinWaitLoopQueueRequestHandle




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Constructor,
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
    	inline SpinWaitLoopQueueRequestHandle::SpinWaitLoopQueueRequestHandle() :
    	member_currentRequestAllowedToStopWaiting( 0U ),
        member_spinLoopWaitQueueRequestHandle( 1U )
    	{}


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to check in each loop if it should keep waiting or not
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
        //      1. true - if the it should keep waiting
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        constexpr Boolean SpinWaitLoopQueueRequestHandle::StopWaiting()
        {
            // Check if the identifier of the request that should stop wait matches this instance identifier
            return ( member_spinLoopWaitQueueRequestHandle == member_currentRequestAllowedToStopWaiting );
        }






























// *********************************************************************************   TESTING   ********************************************************************************

































        DEBUG_TOOL(

            // Method Information :
            //
            //  Description :
            //
            //      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
            //      the functionality
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
            //      NONE
            //
            //  Possible errors :
            //
            //      1. A method does not work correctly - class Exception is thrown
            //      2. There is no more free memory space - class std::bad_alloc is thrown
            //      3. 
            //
            inline void SpinWaitLoopQueueRequestHandle::Test()
            {}

        )  //  End of debug tool





    }  //  Namespace CentralProcessingUnit

}  //  Namespace Universe



#endif  // SPINWAITLOOPQUEUEREQUESTHANDLE_HPP