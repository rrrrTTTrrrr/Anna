#ifndef  THREADATTRIBUTES_HPP
#define  THREADATTRIBUTES_HPP


#include <pthread.h>  //  Threads functionality


#include "../Definitions/VariableTypesDefinitions.hpp"  //  Typedef
#include "../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../Memory/MemoryOperations/Swap/Swap.hpp"  //  Class Swap
#include "../Abilities/DefaultStateCapable/DefaultStateCapable.hpp"  //  Class DefaultStateCapable


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe
{

    namespace Linux
    {



    	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
    	// cpp source file that the object is nested within
    	//
    	// Forward declarations :
    	//
    	//  NONE
    	//



        // Thread attributes :
        //
        // The pthread_attr_t structure can be used to modify the default thread attributes. The following function will initialize the structure :
        //
        //      int pthread_attr_init( pthread_attr_t* attr )
        //
        // And destroy :
        //
        //      int pthread_attr_destroy( pthread_attr_t* attr )
        //
        // Inside this structure the following attributes exist :
        //
        //  1. Detach :
        //
        //      Threads can be detached. If a thread's termination status is not required, the thred can execute in detached mode, by modifying the 
        //      detach state in the thread's attribute structure. The following function is used :
        //
        //          int pthread_attr_setdetachstate( pthread_attr_t* attr, int detachState )
        //
        //      The following values may be specified :
        //
        //          1. PTHREAD_CREATE_DETACHED - threads that are created using this, the parent thread does not need the termination value
        //          2. PTHREAD_CREATE_JOINABLE - threads that are created using this, the parent thread need the termination value
        //
        //      The default value is creating the thread joinable.
        //
        //      On success this function returns 0, otherwise a non zero number is returned.
        //
        //      ERRNO :
        //
        //          1. EINVAL - invalid detach state value
        //
        //      And to get if the thread should be detached or not :
        //
        //          int pthread_attr_setdetachstate( const pthread_attr_t* attr, int* detachState )
        //
        //      On success this function returns 0, otherwise a non zero number is returned.
        //
        //  2. Scheduling related attributes :
        //
        //      The scheduling attributes will be set in the attributes structure. By default the system will use the attributes of the thread that
        //      created them, and ignore the attributes structure. To tell the system to use the provided attributes structure, use the following function :
        //
        //          int pthread_attr_setinheritsched( pthread_attr_t* attr, int inheritsched )
        //
        //      The inherited scheduler integer can be :
        //
        //          1. PTHREAD_INHERIT_SCHED - using this causes the thread to inherit the creating thread attributes
        //          2. PTHREAD_EXPLICIT_SCHED - using the causes the thread to use the attributes structure
        //
        //      On success this function returns 0, otherwise a non zero number is returned.
        //
        //      ERRNO :
        //
        //          1. EINVAL - invalid inherit scheduling value
        //          2. ENOTSUP - attempt was made to set the attribute to an unsupported value
        //
        //      To get the current scheduling attributes use :
        //
        //          int pthread_attr_getinheritsched( pthread_attr_t* _attr, int* inheritsched )
        //
        //      On success this function returns 0, otherwise a non zero number is returned.
        //      
        //      Now, so far these functions will be used to tell the system if to use the given attribute structure for scheduling setting or not. The
        //      existing scheduling attributes are :
        //
        //          1. Thread policy :
        //              
        //              To set the scheduling policy use :
        //
        //                  int pthread_attr_setschedpolicy( pthread_attr_r* attr, int policy )
        //
        //              The supported values for normal scheduling policies are SCHED_OTHER, SCHED_IDLE and SCHED_BATCH. The scheduling priority 
        //              will be ignored with this options. The real time policies are SCHED_FIFO and SCHED_RR.  
        //
        //              On success returns 0, on error returns a non zero error number.
        //
        //              ERRNO :
        //
        //                  1. EINVAL - invalid inherit scheduling value
        //                  2. ENOTSUP - attempt was made to set the attribute to an unsupported value
        //
        //              To get the current policy used :
        //
        //                  int pthread_attr_getschedpolicy( pthread_attr_r* attr, int* policy )
        //
        //              On success returns 0, on error returns a non zero error number.
        //
        //          2. Thread scheduling priority :
        //
        //              To set the scheduling priority use :
        //
        //                  int pthread_attr_setschedparam( pthread_attr_t* attr, const struct sched_param* param )
        //
        //              On success returns 0, on error returns a non zero error number.
        //
        //              ERRNO :
        //
        //                  1. EINVAL - the priority specified does not make sense for the current scheduling policy
        //                  2. ENOTSUP - NOTE, on linux this value is never returned
        //
        //              The scheduling parameter structure :
        //
        //                  structure sched_param
        //                  {
        //
        //                      int sched_priority;
        //
        //                  };
        //
        //              The permitted values are per implementation. In Linux thread scheduled under one of the normal scheduling policies SCHED_OTHER, SCHED_IDLE
        //              and SCHED_BATCH the implementation don't take into account this value, and it should always be 0. Processes scheduled under one of the real
        //              time policies SCHED_FIFO and SCHED_RR have a scheduling priority in the range 1 ( low ) to 99 ( high ). POSIX requires a minimum of 32
        //              distinct priority levels for the real time policies, therefore to make it portable use the following functions to get the supported range
        //              in the current system :
        //
        //                  int sched_get_priority_max( int policy )
        //
        //                  int sched_get_priority_min( int policy )
        //
        //              These functions return the maximum and minimum value that can be used with the scheduling algorithm identified by the policy. The 
        //              supported policy values are SCHED_FIFO, SCHED_RR, SCHED_OTHER, SCHED_BATCH, SCHED_IDLE and SCHED_DEADLINE. Processes with numerically
        //              higher priority values are scheduled before processes with lower priority values, thus the maxmium value of the range will always be
        //              bigger then the minimum value. 
        //
        //              On failure this functions return -1 and ERRNO is set appropriatly
        //
        //              ERRNO :
        //
        //                  1. EINVAL - the policy value does not identify any scheduling policy
        //
        //              To get the current scheduling priority use :
        //
        //                  int pthread_attr_getschedparam( pthread_attr_t* attr, const struct sched_param* param )
        //
        //              On success returns 0, on error returns a non zero error number
        //
        //  3. Scope :
        //
        //      The scope attribute defines a set of threads against which a thread competes for system resources ( CPU, memory, GPU etc... ). To set the 
        //      scope use :
        //
        //          int pthread_setscope( pthread_attr_r* attr, int scope )
        //
        //      The supported values for tge scope are :
        //
        //          1. PTHREAD_SCOPE_SYSTEM - the thread competes for resources with all other threads in all processes on the system that are in the same 
        //                                    scheduling allocation domain, which is a group of one or more processors ). This means that all the threads 
        //                                    the has the same policy and priority are competing against one another
        //
        //          2. PTHREAD_SCOPE_PROCESS - the thread competing for resources with all other threads in the same process that were also created with 
        //                                     this scope value. This threads are scheduled relative to other threads in the process according to their 
        //                                     scheduling policy and priority
        //
        //      POSIX requires that an implementation support at least one of these scopes. Linux only support PTHREAD_SCOPE_SYSTEM
        //
        //      On success returns 0, on error returns a non zero error number.
        //
        //      ERRNO :
        //
        //          1. EINVAL - invalid inherit scheduling value
        //          2. ENOTSUP - the scope value is PTHREAD_SCOPE_SYSTEM which is not supported
        //
        //      To get the current policy used :
        //
        //          int pthread_getscope( pthread_attr_r* attr, int* scope )
        //
        //      On success returns 0, on error returns a non zero error number.
        //
        //  4. Guard size :
        //
        //      The guard size attribute defines if the thread will have a buffer at the end of the stack to act as a guard against invalid assignments.  
        //      When the guard size is more then 0, the system allocates an additional region of at least the guard size in bytes at the end. In case the
        //      guard size is 0, the default guard size is the system page size. To set the guard size attribute use :
        //
        //          int pthread_attr_setguardsize( pthread_attr_t* attr, size_t guardsize )
        //
        //      On success this function returns 0, on error they return a nonzero error number.
        //
        //      ERRNO :
        //
        //          1. EINVAL - invalid attribute structure or guard size ( On Linux this function always succeed )
        //
        //      To get the current guard size attribute :
        //
        //          int pthread_attr_getguardsize( pthread_attr_t* attr, size_t* guardsize )
        //
        //      On success this function returns 0, on error they return a nonzero error number.
        //
        //      ERRNO :
        //
        //          1. EINVAL - invalid attribute structure ( On Linux this function always succeed )
        //
        //      A guard area consists of virtual memory pages that are protected to prevent read and write access. If a thread overflows its stack into
        //      the guard area, then on most hard architectures, it receives a segmentation overflow signal ( SIGSEGV ). Guard areas start on page boundries
        //      and the guard size in internally rounded to the system page size when creating a thread. Choosing a guard size larger than the default size
        //      may be necessary for detecting stack overflow if a thread allocates large data structures on the stack.
        //
        //  5. Stack related attributes :
        //
        //      There are 2 stack related attributes, the size and address. The stack size attribute determines the minimum size in bytes that will be 
        //      allocated for threads created using the attribute structure. To set the stack size use :
        //
        //          int pthread_attr_setstacksize( pthread_attr_t* attr, size_t stacksize )
        //
        //      On success this function returns 0, on error they return a nonzero error number.
        //
        //      ERRNO :
        //
        //          1. EINVAL - can happen in 2 cases, the first is the stack size provided is less then PTHREAD_STACK_MIN value, or if the stack size is
        //                      not a multiple of the system page size
        //
        //      A thread's stack size is fixed at the time of thread creation. Only the main thread can dynamically grow its stack
        //
        //      To get the current stack size use :
        //
        //          int pthread_attr_getstacksize( pthread_attr_t* attr, size_t* stacksize )
        //
        //      On success this function returns 0, on error they return a nonzero error number.       
        //
        //      The stack address should point to the lowest addressable byte of a buffer. The function also needs the stack size as an argument, to know
        //      the pointed buffer size. To set the stack address and size use :
        //
        //          int pthread_attr_setstack( pthread_attr_t* attr, void* stackaddr, size_t stacksize )
        //
        //      These functions are provided for applications that must ensure that a thread's stack is placed in a particular location. For most applications
        //      this is not necessary, and the use of these functions should be avoided. When an application uses this function it takes over the responsebility
        //      of allocating the stack. Any guard size that was set is ignored, the application can allocate the guard area if needed. The address should be
        //      suitably aligned, for full portability, align it on a page boundary ( sysconf( _SC_PAGESIZE ) ). The stack size should also be aligned.
        //
        //      On success this function returns 0, on error they return a nonzero error number.
        //
        //      ERRNO :
        //
        //          1. EINVAL - can happen in 3 cases, the first is the stack size provided is less then PTHREAD_STACK_MIN value, or if the stack size is
        //                      not a multiple of the system page size. The last case is if the stack address or the stack address plus the stack size are
        //                      not suitably aligned
        //
        //          2. EACCES - if the stack area described by the stack address and size are not both readable and writable by the caller
        //
        //      A thread's stack size is fixed at the time of thread creation. Only the main thread can dynamically grow its stack
        //
        //      To get the current stack address and size use :
        //
        //          int pthread_attr_getstack( pthread_attr_t* attr, void* stackaddr, size_t* stacksize )
        //
        //      On success this function returns 0, on error they return a nonzero error number     



    	// Class Information :
    	//
    	//  Purpose :
    	//
    	//		Use this object to set the attributes the thread of execution should be initialized with. This means that this object should be used by the thread that 
        //      goona create the new thread. The use of this object to create a new POSIX thread is optional, the default values are :
        //
        //          1. Detach state = PTHREAD_CREATE_JOINABLE ( in other words, don't detach )
        //
        //          2. Scope = PTHREAD_SCOPE_SYSTEM ( the only one LINUX support )
        //
        //          3. Inherit scheduler = PTHREAD_INHERIT_SCHED ( the thread will inherit the father thread scheduling attributes )
        //
        //          4. Scheduling policy = SYSTEM CHOICE
        //
        //          5. Scheduling priority = 0
        //
        //          6. Guard size = LINUX_PAGE_SIZE
        //
        //          7. Stack address = SYSTEM CHOICE
        //
        //          8. Stack size = SYSTEM CHOICE
        //
        //      Use this object then to tell the system that to use this attributes for the new thread instead of the default ones
        //          
    	//  Description :
    	//
    	//		1. This object inherits a well defined default state, to state that it is not suited for use in it's current state, from the object DefaultStateCapable
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
    	class ThreadAttributes NotForInheritance : public Abilities::DefaultStateCapable
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
    		inline ThreadAttributes();


			// Method Information :
    		//
    		//  Description :
    		//
    		//   	Constructor,
    		//
    		//  Required arguments :
    		//
        	//		User information needed :
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
    		explicit inline ThreadAttributes();


			// Method Information :
    		//
    		//  Description :
    		//
    		//   	Copy constructor, will operate correctly even if the other instance is in default state or self assignment
    		//
    		//  Required arguments :
    		//
    	    //   	User information needed :
    		//
    		//          other - a reference to the instance that should be copied
    		//
    		//		Information returned to the user :
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
    		inline ThreadAttributes( const ThreadAttributes& other );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Assignment operator, can handle with self assignment and instances in default state
    		//
    		//  Required arguments :
    		//
    		//		User information needed :
    		//
    		//			other - a reference to the instance that should be copied
    		//
    		//		Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to this instance
    		//
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline ThreadAttributes& operator=( const ThreadAttributes& other );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
    		//
    		//  Required arguments :
    		//
    		//   	User information needed :
    		//
    		//          other - a reference to the instance that should be moved
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
    		inline ThreadAttributes( ThreadAttributes&& other );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
    		//
    		//  Required arguments :
    		//
    		//   	User information needed :
    		//
    		//          other - a reference to the instance that should be moved
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to this instance
    		//
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline ThreadAttributes& operator=( ThreadAttributes&& other );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      This method is used to swap the content between this instance and the other one
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//          other - a reference to the instance that should be swaped
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
			//		NONE
			//
			//  Possible errors :
    		//
    		//      They will come
    		//
    		inline void Swap( ThreadAttributes& other );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//			NONE
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
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline void Reset();


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//			NONE
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
    		//		NONE
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline void Initiate();


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Destructor, does not throw
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
    		inline ~ThreadAttributes();


    		// The following methods give access and manipulate the data inside this object :











    		// The following methods declare the overloaded operators for the object :


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this operator to check if the this instance match the other
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//          other - a reference to the instance that should be compared with this object
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//      1. true - if the 2 objects are the same
    		//      2. false - otherwise
    		//
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		Boolean operator==( const ThreadAttributes& other ) const;


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this operator to check if the this instance does not match the other
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//          other - a reference to the instance that should be compared with this object
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//      1. true - if the 2 objects are not the same
    		//      2. false - otherwise
    		//
    		//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
    		//
    		//		They will come
    		//
    		inline Boolean operator!=( const ThreadAttributes& other ) const;


    		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
    		// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
    		// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


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


            // This structure will store the thread attributes
            pthread_attr_t m_threadAttributes;


        	// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program
    		// and only destroyed when the program ends. The access to the static member is bound to this object of course


    		// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
    		// rather help implement it :


    		// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
    		// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
    		// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
    		// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
    		// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
    		// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


    	};  //  Class ThreadAttributes



















































































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
    	inline ThreadAttributes::ThreadAttributes() :
    	DefaultStateCapable(),
        m_threadAttributes()        
    	{}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Constructor, this constructor will only initialize the instance, but the attributes still need to be set after
    	//
    	//  Required arguments :
    	//
    	//		User information needed :
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
    	ThreadAttributes::ThreadAttributes( bool terminateValueOfThreadIsNeededOrNot, bool inheritSchedulingAttributesOrNot,   ) :
    	DefaultStateCapable( false )
        m_threadAttributes()
    	{
    		// This will be added only in test mode, to ensure that the given data to the method is valid
    		ASSERT( (), "" )

            // Try to initialize the attribute structure, and if a failure has occured throw an exception describing the problem. This function never fails
            // in Linux, but still checking never killed anyone, or no?
            ErrorHandling::Assert< ErrorHandling::ErrnoException >::True( ( pthread_attr_init( &m_threadAttributes ) == 0 ), "ThreadAttributes::Constructor" );
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Constructor, this constructor will only initialize the instance, but the attributes still need to be set after
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
        ThreadAttributes::ThreadAttributes() :
        DefaultStateCapable( false )
        m_threadAttributes()
        {
            // This will be added only in test mode, to ensure that the given data to the method is valid
            ASSERT( (), "" )

            // 

        }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Copy constructor, will operate correctly even if the other instance is in default state or self assignment
		//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the instance that should be copied
    	//
    	//		Information returned to the user :
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
    	inline ThreadAttributes::ThreadAttributes( const ThreadAttributes& other ) :
    	DefaultStateCapable( other )
    	{}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Assignment operator, can handle with self assignment and instances in default state
    	//
    	//  Required arguments :
    	//
    	//		User information needed :
    	//
    	//			other - a reference to the instance that should be copied
    	//
    	//		Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	A reference to this instance
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline ThreadAttributes& ThreadAttributes::operator=( const ThreadAttributes& other )
    	{
    		// Create a copy of the other instance
    		ThreadAttributes copyOfOther( other );

    		// Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted
    		Swap( copyOfOther );

    		// Return a reference to this instance
    		return ( *this );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the instance that should be moved
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
    	inline ThreadAttributes::ThreadAttributes( ThreadAttributes&& other ) :
    	ThreadAttributes()
    	{
    		// Swap between this instance, which is in default state, and the other one
    		Swap( other );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the instance that should be moved
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	A reference to this instance
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline ThreadAttributes& ThreadAttributes::operator=( ThreadAttributes&& other )
    	{
    	    // Create a default constructed instance
    	    ThreadAttributes defaultConstructedInstance;

    	    // Swap between the temporary instance, which is in default state, and the other instance, this will leave the other instance in default state
    	    defaultConstructedInstance.Swap( other );

    	    // Swap between this instance and the temporary one
    	    Swap( defaultConstructedInstance );

    	    // Return a reference to this instance
    	    return ( *this );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      This method is used to swap the content between this instance and the other one
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//		other - a reference to the instance that should be swaped
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
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//      They will come
    	//
    	void ThreadAttributes::Swap( ThreadAttributes& other )
    	{
    	    // Swap betwen the booleans describing if the instances is in default state or not
    	    Abilities::DefaultStateCapable::Swap( other );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this method to take an instance already initialized, delete the current resources and set it to default state
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//			NONE
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
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline void ThreadAttributes::Reset()
    	{
    	    // Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it will delete the
    	    // old resources
    	    ThreadAttributes defaultConstructedInstance;

    	    // Swap between this instance and the default constructed instance
    	    Swap( defaultConstructedInstance );
        }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this method to take an instance in default state and prepare it for work. The method will have the same effect on instances already initialized. Each
    	//		constructor except for the default constructor, should have a corresponding "Initiate" method. This will provide the functionality to take the instance out
    	//		of default state, into the options presented by the constructors. The constructor the will be used :
    	//
    	//								ThreadAttributes(  )
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//			NONE
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
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline void ThreadAttributes::Initiate()
    	{
    	    // This will be added only in test mode, to ensure that the given data to the method is valid
    	    ASSERT( (), "" )

    	    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
    	    // leave this scope it delete the old data if exist
    	    ThreadAttributes instanceCreatedUsingTheRequiredConstructor(  );

    	    // Swap between this instance and the temporary instance
    	    Swap( instanceCreatedUsingTheRequiredConstructor );
        }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Destructor, does not throw any exceptions
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
    	inline ThreadAttributes::~ThreadAttributes()
    	{
               // Check if the object is in default state, then noting needs to be done
               ReturnIfExpressionIsTrue_MACRO( DefaultState() )
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to set if the thread that creates the new thread needs to know the termination status of the thread or not. If it is needed the 
        //      thread should be created using the join option 
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
        inline void ThreadAttributes::TerminationValueOfTheThreadIsNeeded()
        {
            // Check if the 
            // Try to set the attribute structure, and if a failure has occured throw an exception describing the problem
            ErrorHandling::Assert< ErrorHandling::ErrnoException >::True( ( pthread_attr_setdetachstate( &m_threadAttributes, detachOrJoin ) == 0 ), "ThreadAttributes::TerminationValueOfTheThreadIsNeeded" );            
        }



















































































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



















































































    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this operator to check if the this instance match the other
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//          other - a reference to the instance that should be compared with this object
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//      1. true - if the 2 objects are the same
    	//      2. false - otherwise
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//      1. The template type object does not have the comparison operator ( == )
    	//      2. 
    	//
    	Boolean ThreadAttributes::operator==( const ThreadAttributes& other ) const
    	{}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this operator to check if the this instance does not match the other
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//          other - a reference to the instance that should be compared with this object
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//      1. true - if the 2 objects are not the same
    	//      2. false - otherwise
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//      1. The template type object does not have the comparison operator ( == )
    	//      2. 
    	//
    	inline Boolean ThreadAttributes::operator!=( const ThreadAttributes& other ) const
    	{
    		// Return the negotiated value from the equal operator
    		return ( !( *this == other ) );
    	}













//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



















































































//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************



















































































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************



















































































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



















































































// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************



















































































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************



















































































    }  //  Namespace Linux

}  //  Namespace Universe



#endif  // THREADATTRIBUTES_HPP