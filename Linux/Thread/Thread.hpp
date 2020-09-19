#ifndef  THREAD_HPP
#define  THREAD_HPP


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



        // Linux threads implementation :
        //
        //  1. LinuxThreads - old
        //  2. Native POSIX Threads Library ( NPTL ) - current



        // Cancel options :
        //
        // Two thread attributes that are not included in the pthread_attr_t structure are the cancel state and type. These affect the behavior of a thread in 
        // response to cancel the thread. The cancel state can be either allow cancel ( PTHREAD_CANCEL_ENABLE ) or don't allow cancel ( PTHREAD_CANCEL_DISABLE ).
        // It can be set using :
        //
        //      int pthread_setcancelstate( int state, int* oldstate )
        //
        // A thread starts with a default cancel enable state. When the state is changes to don't allow cancel, a call to this function will not terminate the thread.
        // Instead, the request remainds pending, and if the cancel state is enables again, the thread will act on any pending cancel request at the next possible
        // point for cancel. This function is using atomic operation to read and write the memory that tells the thread to cancel or not.
        //
        // Important :
        // 
        // This function does not wait for a thread to terminate. In the default case, a thread will continue to execute after a cancellation request is made,
        // until the thread reaches a cancellation point. A cancellation point is a place where the thread checks to see whether it been canceled, and then
        // acts according to the request. Posix guarantees that cancellation points will occur when a thread calls any of the functions listed above :
        //
        //      1. accept
        //      2. mq_timedsend
        //      3. putpmsg
        //      4. sigsuspend
        //      5. aio_suspend
        //      6. msgrcv
        //      7. pwrite
        //      8. sigtimedwait
        //      9. clock_nanosleep
        //      10. msgsnd
        //      11. read
        //      12. sigwait
        //      13. close
        //      14. msync
        //      15. readv
        //      16. sigwaitinfo
        //      17. connect
        //      18. nanosleep
        //      19. recv
        //      20. sleep
        //      21. creat
        //      22. open
        //      23. recvfrom
        //      24. system
        //      25. fcntl2
        //      26. pause
        //      27. recvmsg
        //      28. tcdrain
        //      29. fsync
        //      30. poll
        //      31. select
        //      32. usleep
        //      33. getmsg
        //      34. pread
        //      35. sem_timedwait
        //      36. wait
        //      37. getpmsg
        //      38. pthread_cond_timedwait
        //      39. sem_wait
        //      40. waitid
        //      41. lockf
        //      42. pthread_cond_wait
        //      43. send
        //      44. waitpid
        //      45. mq_receive
        //      46. pthread_join
        //      47. sendmsg
        //      48. write
        //      49. mq_send
        //      50. pthread_testcancel
        //      51. sendto
        //      52. writev
        //      53. mq_timedreceive
        //      54. putmsg
        //      55. sigpause
        //      56. catclose
        //      57. ftell
        //      58. getwc
        //      59. printf
        //      60. catgets
        //      61. ftello
        //      61. getwchar
        //      62. putc
        //      63. catopen
        //      64. ftw
        //      65. getwd
        //      66. putc_unlocked
        //      67. closedir
        //      68. fwprintf
        //      69. glob
        //      70. putchar
        //      71. closelog
        //      72. fwrite
        //      73. iconv_close
        //      74. putchar_unlocked
        //      75. ctermid
        //      76. fwscanf
        //      77. iconv_open
        //      78. puts
        //      79. dbm_close
        //      80. getc
        //      81. ioctl
        //      82. pututxline
        //      83. dbm_delete
        //      84. getc_unlocked
        //      85. lseek
        //      86. putwc
        //      87. dbm_fetch
        //      88. getchar
        //      89. mkstemp
        //      90. putwchar
        //      91. dbm_nextkey
        //      92. getchar_unlocked
        //      93. nftw
        //      94. readdir
        //      95. dbm_open
        //      96. getcwd
        //      97. opendir
        //      98. readdir_r
        //      99. dbm_store
        //      100. getdate
        //      101. openlog
        //      102. remove
        //      103. dlclose
        //      104. getgrent
        //      105. pclose
        //      106. rename
        //      107. dlopen
        //      108. getgrgid
        //      109. perror
        //      110. rewind
        //      111. endgrent
        //      112. getgrgid_r
        //      113. popen
        //      114. rewinddir
        //      115. endhostent
        //      116. getgrnam
        //      117. posix_fadvise
        //      118. scanf
        //      119. endnetent
        //      120. getgrnam_r
        //      121. posix_fallocate
        //      122. seekdir
        //      123. endprotoent
        //      124. gethostbyaddr
        //      125. posix_madvise
        //      126. semop
        //      127. endpwent
        //      128. gethostbyname
        //      129. posix_spawn
        //      130. setgrent
        //      131. endservent
        //      132. gethostent
        //      133. posix_spawnp
        //      134. sethostent
        //      135. endutxent
        //      136. gethostname
        //      137. posix_trace_clear
        //      138. setnetent
        //      139. fclose
        //      140. getlogin
        //      141. posix_trace_close
        //      142. setprotoent
        //      143. fcntl
        //      144. getlogin_r
        //      145. posix_trace_create
        //      146. setpwent
        //      147. fflush
        //      148. getnetbyaddr
        //      149. posix_trace_create_withlog
        //      150. setservent
        //      151. fgetc
        //      152. getnetbyname
        //      153. posix_trace_eventtypelist_getnext_id
        //      154. setutxent
        //      155. fgetpos
        //      156. getnetent
        //      157. posix_trace_eventtypelist_rewind
        //      158. strerror
        //      159. fgets
        //      160. getprotobyname
        //      161. posix_trace_flush
        //      162. syslog
        //      163. fgetwc
        //      164. getprotobynumber
        //      165. posix_trace_get_attr
        //      166. tmpfile
        //      167. fgetws
        //      168. getprotoent
        //      169. posix_trace_get_filter
        //      170. tmpnam
        //      171. fopen
        //      172. getpwent
        //      173. posix_trace_get_status
        //      174. ttyname
        //      175. fprintf
        //      176. getpwnam
        //      177. posix_trace_getnext_event
        //      178. ttyname_r
        //      179. fputc
        //      180. getpwnam_r
        //      181. posix_trace_open
        //      182. ungetc
        //      183. fputs
        //      184. getpwuid
        //      185. posix_trace_rewind
        //      186. ungetwc
        //      187. fputwc
        //      188. getpwuid_r
        //      189. posix_trace_set_filter
        //      190. pthread_rwlock_timedwrlock
        //      191. wscanf
        //      192. fsetpos
        //      193. getutxline
        //      194. pthread_rwlock_wrlock
        //      195. unlink
        //      196. fputws
        //      197. gets
        //      198. posix_trace_shutdown
        //      199. vfprintf
        //      200. fread
        //      201. getservbyname
        //      202. posix_trace_timedgetnext_event
        //      203. vfwprintf
        //      204. freopen
        //      205. getservbyport
        //      206. posix_typed_mem_open
        //      207. vprintf
        //      208. fscanf
        //      209. getservent
        //      210. pthread_rwlock_rdlock
        //      211. vwprintf
        //      212. fseek
        //      213. getutxent
        //      214. pthread_rwlock_timedrdlock
        //      215. wprintf
        //      216. fseeko
        //      217. getutxid
        //
        // If an application does not call any of the following functions for a long period of time, then there is a function to add user defined cancellation 
        // point :
        //
        //		void pthread_testcancel()
        //
        // When this function is called, if a cancel request is pending and if cancel is enables, the thread will terminate. This cancel behavior is called
        // deferred cancel. There is another behavior called asynchronous cancel, which in it the thread can terminate at any time. The function to set
        // which behavior ( PTHREAD_CANCEL_DEFERRED VS PTHREAD_CANCEL_ASYNCHRONOUS ) :
        //
        //		int pthread_setcanceltype( int type, int* oldtype )



        // Every thread has a set of functions that are called when the thread has finished. This functions are stored in a stack, and as such functions
        // can be pushed into the stack or poped off the stack. These functions are called in the following cases :
        //
        //  1. When a thread is canceled, all of the stacked functions are popped and executed
        //  2. When a thread terminates by calling "pthread_exit", the same as above happens
        //  3. When a thread calls "pthread_cleanup_pop" with a non zero execute argument, the top most function is poped and executed
        //
        // This function are not called if the thread terminates by calling 'return'!
        //
        // To push a function to the top of the stack use :
        //
        //      void pthread_cleanup_push( void (*routine)( void* ), void *arg )
        //
        // These function has no return value or errors.
        //
        // To pop a function to the top of the stack use :
        //
        //      void pthread_cleanup_push( int execute )
        //
        // To pop the function and execute it set the value of the 'execute' argument to be non zero.
        //
        // 



        // The concurrency level controls the number of kernel threads or processes on top of which the user level threads are mapped. If an implementation keeps
        // a one to one mapping, changing the concurrency level will have no effect, since it is possible for all user level threads to be scheduled. If the 
        // implementation keeps a one to many mapping, performance may be improved by increasing the number of user level threads that can run at a given time.
        // The following function only provides a hint to the system regarding the concurrency level desired :
        //
        //      int pthread_setconcurrency( int level )
        //
        // Specifying the new level as 0 instructs the implementation to manage the concurrency level as it deems appropriate!
        //
        // On success this function returns 0, otherwise a non zero number is returned.
        //
        // ERRNO :
        //
        //  1. EINVAL - new level is negative
        //  2. EAGAIN - the value specified by the new level would cause a system resource to be exceeded
        //
        //
        // The following method is to allow knowing the current concurrency of the process :
        //
        //      int pthread_getconcurrency()
        //
        // It will always succeed, but it only should be called if a previous set concurrency level was called, otherwise it returns 0
        //
        // Linux is a 1:1 rate implementation so this functions has no effect!



    	// Template Class Information :
    	//
    	//  Purpose :
    	//
    	//		Artifical Inteligence
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
    	template< typename FunctionType, typename... TemplateArguments >
    	class PosixThread NotForInheritance : public Abilities::DefaultStateCapable, public Tuple< TemplateArguments... >
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
    		inline PosixThread();


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
    		explicit inline PosixThread();


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
    		inline PosixThread( const PosixThread< FunctionType, TemplateArguments... >& other );


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
    		//   	A reference to this object
    		//
    		//  Expectations :
    		//
    		//		NONE
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline PosixThread< FunctionType, TemplateArguments... >& operator=( const PosixThread< FunctionType, TemplateArguments... >& other );


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
    		inline PosixThread( PosixThread< FunctionType, TemplateArguments... >&& other );


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
    		//   	A reference to this object
    		//
    		//  Expectations :
    		//
    		//		NONE
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline PosixThread< FunctionType, TemplateArguments... >& operator=( PosixThread< FunctionType, TemplateArguments... >&& other );


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
    		inline void Swap( PosixThread< FunctionType, TemplateArguments... >& other );


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
    		inline ~PosixThread();


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
    		inline Boolean operator==( const PosixThread< FunctionType, TemplateArguments... >& other ) const;


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
    		inline Boolean operator!=( const PosixThread< FunctionType, TemplateArguments... >& other ) const;


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


    		// This will store the handle to the POSIX Posixthread
    		pthread_t* m_thread; 

    		// This will store the attributes for the POSIX Posixthread
    		const pthread_attr_t* m_threadAttributes;

    		// This will store pointer to the function that the Posixthread will execute
    		Memory::FunctionPointer< void, void* > m_functionToExecute;


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


    	};  //  Class PosixThread



















































































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
    	template< typename FunctionType, typename... TemplateArguments >
    	inline PosixThread< FunctionType, TemplateArguments... >::PosixThread() :
    	DefaultStateCapable(),
    	Tuple< FunctionType, TemplateArguments... >(),
    	{}


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
    	template< typename FunctionType, typename... TemplateArguments >
    	inline PosixThread< FunctionType, TemplateArguments... >::PosixThread() :
    	DefaultStateCapable( false )
    	{
    		// This will be added only in test mode, to ensure that the given data to the method is valid
    		ASSERT( (), "" )

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
    	template< typename FunctionType, typename... TemplateArguments >
    	inline PosixThread< FunctionType, TemplateArguments... >::PosixThread( const PosixThread< FunctionType, TemplateArguments... >& other ) :
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
    	//   	A reference to this object
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename FunctionType, typename... TemplateArguments >
    	inline PosixThread< FunctionType, TemplateArguments... >& PosixThread< FunctionType, TemplateArguments... >::operator=( const PosixThread< FunctionType, TemplateArguments... >& other )
    	{
    		// Create a copy of the other instance
    		PosixThread copyOfOther( other );

    		// Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted
    		Swap( copyOfOther );

    		// Return a reference to this object
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
    	template< typename FunctionType, typename... TemplateArguments >
    	inline PosixThread< FunctionType, TemplateArguments... >::PosixThread( PosixThread< FunctionType, TemplateArguments... >&& other ) :
    	PosixThread< FunctionType, TemplateArguments... >()
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
    	//   	A reference to this object
    	//
    	//  Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename FunctionType, typename... TemplateArguments >
    	inline PosixThread< FunctionType, TemplateArguments... >& PosixThread< FunctionType, TemplateArguments... >::operator=( PosixThread< FunctionType, TemplateArguments... >&& other )
    	{
    	    // Create a default constructed instance
    	    PosixThread< FunctionType, TemplateArguments... > defaultConstructedInstance;

    	    // Swap between the temporary instance, which is in default state, and the other instance
    	    defaultConstructedInstance.Swap( other );

    	    // Swap between this instance and the temporary one
    	    Swap( defaultConstructedInstance );

    	    // Return a reference to this object
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
    	template< typename FunctionType, typename... TemplateArguments >
    	inline void PosixThread< FunctionType, TemplateArguments... >::Swap( PosixThread< FunctionType, TemplateArguments... >& other )
    	{
    	    // Swap betwen the booleans describing if the instances is in default state or not
    	    Abilities::DefaultStateCapable::Swap( other );
    	}


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
    	template< typename FunctionType, typename... TemplateArguments >
    	inline void PosixThread< FunctionType, TemplateArguments... >::Reset()
    	{
    	    // Create a default constructed instance, it will be used to swap with this instance, leaving this instance in default state, and delete the old data
    	    PosixThread< FunctionType, TemplateArguments... > defaultConstructedInstance;

    	    // Swap between this instance and the default constructed instance
    	    Swap( defaultConstructedInstance );
    }


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
    	template< typename FunctionType, typename... TemplateArguments >
    	inline void PosixThread< FunctionType, TemplateArguments... >::Initiate()
    	{
    	    // This will be added only in test mode, to ensure that the given data to the method is valid
    	    ASSERT( (), "" )

    	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
    	    // leave this scope it will delete the old data
    	    PosixThread< FunctionType, TemplateArguments... > temporary;

    	    // Swap between this instance and the temporary instance
    	    Swap( temporary );
    }


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
    	template< typename FunctionType, typename... TemplateArguments >
    	inline PosixThread< FunctionType, TemplateArguments... >::~PosixThread()
    	{
               // Check if the object is in default state, then noting needs to be done
               ReturnIfExpressionIsTrue_MACRO( DefaultState() )
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
    	template< typename FunctionType, typename... TemplateArguments >
    	inline Boolean PosixThread< FunctionType, TemplateArguments... >::operator==( const PosixThread< FunctionType, TemplateArguments... >& other ) const
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
    	template< typename FunctionType, typename... TemplateArguments >
    	inline Boolean PosixThread< FunctionType, TemplateArguments... >::operator!=( const PosixThread< FunctionType, TemplateArguments... >& other ) const
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



















































































// *********************************************************************************   TESTING   ********************************************************************************



















































































    	DEBUG_TOOL(

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
    		template< typename FunctionType, typename... TemplateArguments >
    		void PosixThread< FunctionType, TemplateArguments... >::Test()
    		{}

    	)  //  End of debug tool











    }  //  Namespace Linux

}  //  Namespace Universe



#endif  // THREAD_HPP