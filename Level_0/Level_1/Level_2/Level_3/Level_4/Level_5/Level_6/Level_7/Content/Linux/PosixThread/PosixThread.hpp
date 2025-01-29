namespace Universe
{


namespace Linux
{



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
// When this function is called, if a cancel request is pending and if cancel is enabled, the thread will terminate. This cancel behavior is called
// deferred cancel. There is another behavior called asynchronous cancel, which in it the thread can terminate at any time. The function to set
// the behavior ( PTHREAD_CANCEL_DEFERRED VS PTHREAD_CANCEL_ASYNCHRONOUS ) :
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
//      The supported values for the scope are :
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
//		Artifical Inteligence
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class PosixThread NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = PosixThread;

	// Create a type definition for the function
	using FunctionPointerType = void* (*)( void* );


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. functionPointer - a pointer to the function that the thread of execution will run
	//			2. argumentPointer - the argument that will be supplied to the function
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		1. The pointer to the function should not be NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	explicit inline PosixThread( FunctionPointerType const functionPointer, void* const argumentPointer = nullptr );


	// Method Information :
	//
	//  Description :
	//
	//		Destructor, does not throw
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
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


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to wait for the thread of execution to finish
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
    //      The value returned from the function that was running on the thread of execution
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    inline void* WaitForThreadOfExecutionToFinish();


	DEBUG_TOOL(

		// This part of the object is dedicated for testing :


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
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
		static void UnitTest() __attribute__ (( __unused__ )) {}

	)  //  End of debug tool


private:


    // Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
    DisableCopyAndMove( PosixThread );


	// This object will be used to create the new thread of execution
	pthread_t member_thread;

	// This pointer will store the memory address of the function that will be executed in the created thread of execution
	FunctionPointerType member_functionPointer;

	// This pointer will store the memory address of the argument to pass to the function
	void* member_argumentPointer;

    // This object will store if the thread of execution already finished running
    Boolean member_didThreadOfExecutionFinished;


};  //  Class PosixThread
