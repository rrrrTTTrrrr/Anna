#ifndef  SYSTEMCALL_HPP
#define  SYSTEMCALL_HPP


#include "../../../Root/Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA
#include "../../../Root/Content/CodingLanguages/Assembly/LanguageFeatures/Assembly_LanguageFeatures.hpp"  // Macro AbsoluteValue
#include "../../../Root/FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../Root/FunctionalityBranch/Level_0/Content/Error/ErrnoException/ErrnoException.hpp"  //  Class ErrnoException
#include "../../../Root/FunctionalityBranch/Level_0/Level_1/Level_2/Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{



	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
	// cpp source file that the object is nested within
	//
	// Forward declarations :
	//
	//  NONE
	//



    namespace Linux
    {



		// Errno can be implemented in various ways, it is unspecified whether errno is a macro or an identifer devalred with external linkage. Therefore in order
		// to find the way errno is accessed through assembly on the current system use the following :
		//
		//		#include <errno.h>
		//
		//		int main()
		//		{
		//			// Set errno to some value to produce the function call to errno
		//			errno = 9;
		//
		//			return ( 0 );
		//		}
		//
		// By plotting the assembly result of this code, the way errno is called can be known. 
		//
		// If a system call fails the following condition must be checked, the syntax in psuedo C++ code :
		//
		//		// Check if if the system call returned an error number
		//		if ( ( RAX <= -1 ) && ( RAX >= -4095 ) )
		//		{
		//			// The system call failed
		//			
		//			// Set errno to the absolute value of RAX
		//			errno = -RAX;
		//		}
		//
		// As can be seen the system call return value needs to be checked if it is a negative value between [ -4095 - -1 ], and if it does set errno to the absolute
		// value that is in the RAX register



        // This macro is used to handle with the return value after the system call. If the system call failed it will set errno appropriately, and return -1.
        // If the system call succedded the return value of the system call is returned as it is
        #define HandleSystemCallReturnValue_MACRO                                                                                                                                                                                            		\
                                                                                                                                                                                                                                             		\
            "CMP EAX, 0xFFFFF000;"                                               	/* Check if the system call failed */                                                                                                                       	\
            "JA SystemCallFailure%=;"                                            	/* If the system call failed jump to the given label */                                                                                                     	\
            "MOV %[SystemCallReturnValue], EAX;"                                 	/* The system call succedded, store the return value in the EAX part of the RAX register */                                                                 	\
            "JMP END%=;"                                                         	/* Nothing else needs to be done, jump to the 'END' label */                                                                                                	\
            "SystemCallFailure%=:;"                                              	/* Assembly label, used to make jumps to the required location if the system call failed */                                                                 	\
            "MOV EBX, EAX;"                                                      	/* Move the content of the EAX part of the RAX register to EBX part of the RBX register, the RAX register is needed to store the address of errno */        	\
            AbsoluteValue( EBX, EAX )                                            	/* Set the absolute value of the content in the EBX part of the RBX register */                                                                             	\
            "CALL __errno_location@PLT;"                           					/* Get the errno address */                                                              																		\
			"MOV DWORD PTR [EAX], EBX;" 											/* Set errno with the content of the EBX part of the RBX register */																							\
            "MOV %[SystemCallReturnValue], -1;"                                  	/* Set the system call return value to -1, to notify that the system call failed */                                                                         	\
            "END%=:;"                                                            	/* Assembly label, used to make jumps to the end of the function */



		// This macro is used to assert that the system call was successful, and if not through an exception describing the problem
		#define AssertSystemCallWasSuccessful_MACRO if ( ( systemCallReturnValue == -1 ) ) { ThrowErrnoException }


		// This constant expression will be used to determine the maximum value possible for a system call in the current system
		inline constexpr SignedInteger32bits MaximumSystemCallNumber = 333;


        // If a system call fails, the condition :
        //
        //      (signed long ) EAX > 0XFFFFF000  
        //
        // Will result in true, and EAX will now store the negative value of matching positive errno number, it looks like :
        //
        //      errno = -EAX
        //
        // Then when invoking a system call in assembly, the EAX register is used to pass the information to the calling function.     



        // A system call is the programmatic way in which an application requests service from the kernel of the operating system it is executed on. This may include
        // hardware related services, creation and execution of new processes, and communication with integral kernel services such as process scheduling. System
        // calls provide an essential interdace between a process and the operating system. In most systems this can be done only from user space.
        //
        // Generally, systems provide a interface ( in other words library or API ) that sits between normal programs and the operating system. On Unix like systems, 
        // that interface is usually part of an implementation of the C library ( libc ), such as 'glibc', the provides wrapper functions for the system calls, often
        // named the same as the system calls they invoke
        //
        // A call to one of the interface functions does not change



        // Interrupt VS System Call :
        //
        // The purpose of an interrupt handler and a system call ( and fault handler ) is largely the same, to switch the processor into kernel mode while
        // providing protection from inadvertent or malicious access to kernel structures. An interrupt is triggered by an asynchronous external event. A
        // system call ( or fault or trap ) is triggered synchronously by executing code. A process continues to execute its code in a system call, but
        // not in an interrupt.
        //
        // Note - Intel's documentation often conflates interrupt, system calls, traps and faults as 'interrupt'!
        //
        // Some processors treat system calls, traps, fault and interrupts largely the same way. Others provide different methods for implementing system
        // calls. In processors that handle all of the above in the same way, each type of interrupt, trap and fault has a unique number. The processor
        // expects the operating system to set up an array of pointers to handlers. Depending upon the number of available handlers, the operating system
        // may have a separate handler for each system call or use a register value to determine what specific system function to execute. In such a
        // system, interrupt handlers can be called synchronously the same way a system call is invoked, using the keyword 'INT'. Intel processors have
        // support for the 'SYSCALL' mechanism that provides a different way to implement system calls!



        // System calls :
        //
        // System calls are the interface between user programs and the Linux kernel. They are used to let the kernel perform various system tasks such as
        // file access, process management and networking. In the C programming language, a wrapper function would normally be called, which executes all
        // the required steps for the system call.
        //
        // To start a system call using interrupt, all the data to the system call needs to be set in the general purpose registers. Each system call has
        // a fixed number ( the numbers differ between interrupt and 'syscall' ), this number needs to be stored in 'RAX'!
        //
        // Most system calls take arguments to perform their task. These arguments are passed by writing them in the appropriate registers, before making
        // the actual call. Each parameter index has a specific register. The arguments are passed in the order they appear in the function signature of
        // the corresponding C wrapper function. After everything is set up correctly, the call to the system is made, and the kernel performs the task!
        // The return value of the system call is written to 'RAX'. The kernel uses its own stack to perform the actions. The user stack is not changed
        // in any way.
        //
        // Three way to invoke a system call :
        //
        //    1. 'int 0x80' - parameters are passed by setting the following general purpose registers :
        //
        //           System call number    Argument 1    Argument 2    Argument 3    Argument 4    Argument 5    Argument 6
        //                  EAX              EBX           ECX           EDX           ESI            EDI           EBP
        //
        //           Return value -> EAX
        //
        //    2. 'SYSCALL' - this way does not access the interrupt descriptor table and it is faster. Parameters are passed by setting the following
        //                   general purpose registers :
        //
        //           System call number    Argument 1    Argument 2    Argument 3    Argument 4    Argument 5    Argument 6
        //                  RAX              RDI           RSI           RDX           R10            R8           R9
        //
        //           Return value -> RAX



        // Anatomy of a system call :
        //
        // System calls are the primary mechanism by which user space programs interact with the linux kernel. Given their importance, it's not 
        // surprising to discover that the kernel includes a wide variety if mechanisms to ensure that system calls can be implemented generically
        // across architectures, and can be made available to user space in an efficient and consistent way.
        //
        // System calls differ from regula function calls because the code being called is in the kernel. Special instructions are needed to make
        // the processor perform a transition to ring 0 ( privileged mode ). In addition, the kernel code being invoked is identified by a system 
        // call number, rather then by a function address.
        //
        // The 'read' ( implemented in the file fs/read_write.c ) system call provides a good initial example to explore the kernel's system call 
		// machinery. From an invocation standpoint the most intersting aspect of this code is way the function is defined using the 'SYSCALL_DEFINE3' 
		// macro :
		//
		//		    SYSCALL_DEFINE3( read, unsigned int, fd, char __user *, buf, size_t, count )
		//		    {
		//		    	struct fd f = fdget_pos( fd );
		//		    	ssize_t ret = -EBADF;
		//		    	/* ... */
		//			}
		//
		// These 'SYSCALL_DEFINEn' macros are the standard way for kernel code to define a system call, where the 'n' suffix indicates the argument
		// count. The definition of these macros ( in include/linux/syscalls.h ) gives two distinct outputs for each system call.
		//
		//			    SYSCALL_METADATA( _read, 3, unsigned int, fd, char __user *, buf, size_t, count )
		//			    __SYSCALL_DEFINEx( 3, _read, unsigned int, fd, char __user *, buf, size_t, count )
		//			    {
		//			    	struct fd f = fdget_pos( fd );
		//			    	ssize_t ret = -EBADF;
		//			    	/* ... */
		//				}
		//
		// The first of these, 'SYSCALL_METADATA', builds a collection of metadata about the system call for tracing purposes. It's only expanded when
		// 'CONFIG_FTRACE_SYSCALLS' is defined for the kernel build, and its expansion gives boilerplate definitions of data that descrobes the
		// system call and its parameters.
		//
		// The '__SYSCALL_DEFINEx' holds the system call implementation. Once the various layers of macros and GCC type extensions are expanded, the 
		// resulting code includes some intersting features :
		//
		//				asmlinkage long sys_read( unsigned int fd, char __user * buf, size_t count )
		//			    __attribute__( ( alias( __stringify( SyS_read ) ) ) );
		//
		//			    static inline long SYSC_read( unsigned int fd, char __user * buf, size_t count );
		//			    asmlinkage long SyS_read( long int fd, long int buf, long int count );
		//
		//			    asmlinkage long SyS_read( long int fd, long int buf, long int count )
		//			    {
		//			    	long ret = SYSC_read( (unsigned int)fd, (char __user *)buf, (size_t)count );
		//			    	asmlinkage_protect( 3, ret, fd, buf, count );
		//			    	return ret;
		//			    }
		//
		//			    static inline long SYSC_read( unsigned int fd, char __user * buf, size_t count )
		//			    {
		//			    	struct fd f = fdget_pos( fd );
		//			    	ssize_t ret = -EBADF;
		//			    	/* ... */
		//				}
		//
		// The system call implementation actually has the name 'SYSC_read', and it is declared static and so inaccessible outside this module. Instead,
		// a wrapper function, called 'SyS_read' and aliased as 'sys_read', is visible externally. Looking closely at those aliases, a difference in
		// their parameter types appear, 'sys_read' expects the explicitly declared types ( char __user*, etc.. ), whereas 'SyS_read' just expects a 
		// bunch of long integers. Digging into the history of this, it turns out that the long version ensures that 32 bit values are correctly sign
		// extended for some 64 bit kernel platforms, preventing a historical vulnerability.
		//
		// The last thing to notice is the 'asmlinkage' directive and 'asmlinkage_protect' call. The first means that the function should expect its 
		// its arguments on the central processing unit stack instead of registers, and the generic definition of 'asmlinkage_protect' explaines that
		// it's used to prevent the compiler from assuming that it can safely reuse those areas of the stack.
		//
		// For IA64 :
		//
		//				#define asmlinkage CPP_ASMLINKAGE __attribute__(( syscall_linkage ))
		//
		// For x86_64 :
		//
		//				#define asmlinkage CPP_ASMLINKAGE __attribute__(( regparm(0) ))
		//
		// To accompany the definition of 'sys_read' there's also a declaration in 'include/linux/syscalls.h' to allow other kernel code to call into
		// the system call implementation directly. Calling system calls directly from elsewhere in the kernel is generally discouraged and is not 
		// often seen.
		//
		// System call table entries :
		//
		// Hunting for callers of 'sys_read' also points the way toward how user space reaches this function. For 'generic' architectures that don't
		// provide an override of their own, the 'include/uapi/asm-generic/unistd.h' file includes an entry referencing 'sys_read' :
		//
		//				#define __NR_read 63
		//				__SYSCALL( __NR_read, sys_read )
		//
		// This defines the generic system call number 63 for 'sys_read', and uses the '__SYSCALL' macro to associate that number with it, in an 
		// architecture specific way. For example, arm64 uses the 'asm-generic/unistd.h' header file to fill out a table that maps the system call
		// numbers to implementation function pointers. The x86_64 architecture, which does not use this generic table, defines its own mappings in
		// 'arch/x86/entry/syscalls/syscalls_64.tbl', which has an entry for 'sys_read' :
		//
		//				0 common read  sys_read
		//
		// This indicates that 'read' on x86_64 has system call number 0 and not 63, and has a common implementation for both of the ABIs for x86_64,
		// namely 'sys_read'. The 'syscalltbl.sh' scrupt generates 'arch/x86/include/generated/asm/syscalls_64.h' from the 'syscall_64.tbl' table,
		// specifically generating an invocation of the '__SYSCALL_COMMON' macro for 'sys_read'. This header file is used, in turn, to populate the
		// the system call table, 'sys_call_table', which is the key data structure that maps system call numbers to 'sys_name' functions.
		//
		// x86_64 system call invocation :
		//
		// This is inherently architecture specific. The invocation process also involves a few steps.
		//
		//			  	---------------------             
		//			  	| 64 bit user space |  			Table of system call function pointers ( using a GCC extension for array initialization that 
		//			  	|					| 			ensures any missing entries point to 'sys_ni_syscall' )
		//			  	|	   RAX = 0      |
		//			  	|      SYSCALL      |
		//			  	---------------------
		//						  |
		//						  |  Via 'MSR_LSTAR' model specific register ( MSR ) 
		//						  |
		//						  |
		//						  *
		//			 ----------------------------
		//			 | Kernel - x86_64 Assembly |       The table of system calls function pointers is accessed from 'arch/x86/entry/entry_64.s' from 
		//		     |							| 		the 'system_call' assembly entry point. It uses the RAX register to pick the relevant entry in
		//			 |       system_call()      |       the array and then calls it. Earlier in the function, the 'SAVE_ARGS' macro pushes various registers
		//			 |     kernel/entry_64.s    |       onto the stack, to match the 'asmlinkage' directive. Moving outwards, the 'system_call' entry point
		//			 ----------------------------   	is itself referenced in 'syscall_init', a function that is called early in the kernel's startup 
		//						  | 					sequence :
		//						  |
		//						  |    						void syscall_init( void )
		//						  | 						{
		//						  *								/* 
		//			  ------------------------- 				 *  LSTAR and STAR live in a bit strange symbiosis.
		//			  | Kernel - generic code |                  *  They both write to the same internal register. STAR allows to
		//			  |                       | 			     *  set CS/DS but only a 32bit target. LSTAR sets the 64bit rip.
		//			  |       sys_read()      | 				 */
		//			  |    fs/read_write.c    |
		//			  |           |           |					wrmsrl( MSR_STAR,  ( (u64)__USER32_CS )<<48  | ( (u64)__KERNEL_CS )<<32 );
		//			  |			  |           |					wrmsrl( MSR_LSTAR, system_call );
		//		  	  |			  *			  |					wrmsrl( MSR_CSTAR, ignore_sysret );
		//			  |  	 SYSC_read()      |					
		//			  -------------------------   				/* ... */
		//													}
		//
		//												The 'wrmsrl' instruction writes a value to a model specific register, in this case the address of the
		//												general 'system_call' handling funcion is written to register 'MSR_LSTAR' ( 0xC0000082 ), which is the
		//												x86_64 model specific register for handling the 'SYSCALL' instruction
		//
		// The standard ABI for how x86_64 user programs invoke a system call is to put the system call number into the RAX register, and the other
		// parameters into specific registers ( RDI, RSI, RDX... ), then issue the 'SYSCALL' instruction. This instruction causes the processor to
		// transition to ring 0 and invoke the code referenced by the 'MSR_LSTAR' model specific register - namely 'system_call'. The system call 
		// code pushes the registers onto the kernel stack, and calls the function pointer at entry RAX in the sys_call_table table



		// The low level entry point to system call is implemented in the file 'arch/x86/entry/entry_64.s'!!



        // Template Class Information :
        //
        //  Purpose :
        //
        //      This object will be used to invoke a Linux system call using the assembly instruction 'syscall'. Parameters are passed by setting the following
        //      general purpose registers :
        //
        //           System call number    Argument 1    Argument 2    Argument 3    Argument 4    Argument 5    Argument 6
        //                  RAX              RDI           RSI           RDX           R10            R8           R9
        //
        //      The return value of each system call is stored in the register 'RAX'. The return value represents the errno error number
    	//
   	    //  Description :
   	    //
    	//      1. The object inherits from the object NoInstances to prevent any instances of the object
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
    	//							 suffix __Private
    	//
    	//  Possible errors :
    	//
    	//		Too many to count
    	//
    	template< UnsignedInteger64bits NumberOfSystemCallTemplateArguments, typename... SystemCallTemplateArgumentsType >
    	class SystemCall
    	{
    	public:


            // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
    		// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
    		// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


            // Method Information :
            //
            //  Description :
            //
            //      This is a method declaration of the most general form of a method to inoke a system call from the Linux kernel. The template specialization
            //      for the method will be made upon the number of arguments provided and not on their type
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The number of system call template arguments should match to the number of template arguments provided
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            static inline SignedInteger32bits Invoke( SignedInteger32bits systemCallNumber );


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


    		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances_MACRO( SystemCall )


    	};  //  Class SystemCall






































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************






































        // Method Information :
        //
        //  Description :
        //
        //      This is a template specialization for system calls that has no arguments
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          systemCallNumber - the number of the system call to invoke
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
        //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
        //      2. The given number of system call template arguments should be 6
        //      3. 
        //
        //  Possible errors :
        //
        //      1. The system call failed - an object of type ErrnoException is thrown 
        //      2.
        //
        template<>
        inline SignedInteger32bits SystemCall< 0UL >::Invoke( SignedInteger32bits systemCallNumber )
        {
            // This will be added only in test mode, to ensure that the given data to the method is valid
            Assert_MACRO( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" )

            // This will be used to store if the system call succeeded ( true ) or not ( false )
            SignedInteger32bits systemCallReturnValue = 0;

            // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and all the
            // required registers with the arguments to the system call. Now the kernel can be invoked to execute the call. This is not possible using only C++

            __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                     	/* Move the system call number to the RAX register */
                                "SYSCALL;"                                                           	/* Invoke the kernel to execute the call */
                                HandleSystemCallReturnValue_MACRO                                       /* Check if the system call failed or not and act accordingly */

                               : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                /* Output arguments */
                               : [SystemCallNumber] "r0" ( systemCallNumber )                           /* Input arguments */
                               : "memory", "cc", "%rax", "%rbx" );                                      /* Clobbers and scratch registers */

            // Check if the system call succedded, and if not throw an errno exception
			AssertSystemCallWasSuccessful_MACRO

            // Return the return value from the system call
            return ( systemCallReturnValue );
        }




































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 1   ****************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //






































        // Template Class Information :
        //
        //  Purpose :
        //
        //      This object will be used to invoke a Linux system call using the assembly instruction 'syscall'. Parameters are passed by setting the following
        //      general purpose registers :
        //
        //           System call number    Argument 1    Argument 2    Argument 3    Argument 4    Argument 5    Argument 6
        //                  RAX              RDI           RSI           RDX           R10            R8           R9
        //
        //      The return value of each system call is stored in the register 'RAX'. The return value represents the errno error number
        //
        //  Description :
        //
        //      1. The object inherits from the object NoInstances to prevent any instances of the object
        //
        //      3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
        //
        //              1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
        //                          presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
        //                          lost, so it should be avoided in most cases
        //
        //              2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
        //                             all the data and methods inside this part. This part will usually containt some methods and few data members
        //
        //              3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
        //                           methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
        //                           suffix __Private
        //
        //  Possible errors :
        //
        //      Too many to count
        //
        template< typename... SystemCallTemplateArgumentsType >
        class SystemCall< 1UL, SystemCallTemplateArgumentsType... >
        {
        public:


            // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
            // access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
            // a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has one argument only
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 1 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 1
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            static inline SignedInteger32bits Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments );


    	private:


    		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances_MACRO( SystemCall )


        };  //  Class SystemCall







































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************






































            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has one argument only
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 1 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 1
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            template< typename... SystemCallTemplateArgumentsType >
            inline SignedInteger32bits SystemCall< 1UL, SystemCallTemplateArgumentsType... >::Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                Assert_MACRO( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" )
                Assert_MACRO( ( systemCallArguments.Size() == 1UL ), "The system call accepts 1 argument" )

                // This will be used to store if the system call succeeded ( true ) or not ( false )
                SignedInteger32bits systemCallReturnValue = 0;

                // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
                // to execute. This is not possible using only C++

                __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                         	/* Move the system call number to the RAX register */
                                    "MOVQ RDI, %[SystemCallArgument_1];"                                     	/* Move the content of the first argument to the system call into the RDI register */
                                    "SYSCALL;"                                                               	/* Invoke the kernel to execute the call */
                                    HandleSystemCallReturnValue_MACRO                                           /* Check if the system call failed or not and act accordingly */

                                   : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                    /* Output arguments */
                                   : [SystemCallNumber] "r0" ( systemCallNumber ),                              /* Input arguments */
                                     [SystemCallArgument_1] "r" ( systemCallArguments.template Entry< 0 >() )     
                                   : "memory", "cc", "%rax", "%rbx", "%rdi" );                                  /* Clobbers and scratch registers */

                // Check if the system call succedded, and if not throw an errno exception
				AssertSystemCallWasSuccessful_MACRO

                // Return the return value from the system call
                return ( systemCallReturnValue );
            }


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 2   ****************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //






































        // Template Class Information :
        //
        //  Purpose :
        //
        //      This object will be used to invoke a Linux system call using the assembly instruction 'syscall'. Parameters are passed by setting the following
        //      general purpose registers :
        //
        //           System call number    Argument 1    Argument 2    Argument 3    Argument 4    Argument 5    Argument 6
        //                  RAX              RDI           RSI           RDX           R10            R8           R9
        //
        //      The return value of each system call is stored in the register 'RAX'. The return value represents the errno error number
        //
        //  Description :
        //
        //      1. The object inherits from the object NoInstances to prevent any instances of the object
        //
        //      3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
        //
        //              1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
        //                          presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
        //                          lost, so it should be avoided in most cases
        //
        //              2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
        //                             all the data and methods inside this part. This part will usually containt some methods and few data members
        //
        //              3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
        //                           methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
        //                           suffix __Private
        //
        //  Possible errors :
        //
        //      Too many to count
        //
        template< typename... SystemCallTemplateArgumentsType >
        class SystemCall< 2UL, SystemCallTemplateArgumentsType... >
        {
        public:


            // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
            // access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
            // a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has two arguments
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 2 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 2
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            static inline SignedInteger32bits Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments );


    	private:


    		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances_MACRO( SystemCall )
			

        };  //  Class SystemCall






































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************






































            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has two arguments
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 2 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 2
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            template< typename... SystemCallTemplateArgumentsType >
            inline SignedInteger32bits SystemCall< 2UL, SystemCallTemplateArgumentsType... >::Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                Assert_MACRO( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" )
                Assert_MACRO( ( systemCallArguments.Size() == 2UL ), "The system call accepts 2 arguments" )

                // This will be used to store if the system call succeeded ( true ) or not ( false )
                SignedInteger32bits systemCallReturnValue = 0;

                // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
                // to execute. This is not possible using only C++

                __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                             	/* Move the system call number to the RAX register */
                                    "MOVQ RDI, %[SystemCallArgument_1];"                                         	/* Move the content of the first argument to the system call into the RDI register */
                                    "MOVQ RSI, %[SystemCallArgument_2];"                                         	/* Move the content of the second argument to the system call into the RDI register */
                                    "SYSCALL;"                                                                   	/* Invoke the kernel to execute the call */
                                    HandleSystemCallReturnValue_MACRO                                               /* Check if the system call failed or not and act accordingly */
                                   
                                   : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                        /* Output arguments */
                                   : [SystemCallNumber] "r0" ( systemCallNumber ),                                  /* Input arguments */
                                     [SystemCallArgument_1] "r" ( systemCallArguments.template Entry< 0 >() ), 
                                     [SystemCallArgument_2] "r" ( systemCallArguments.template Entry< 1 >() )       
                                   : "memory", "cc", "%rax", "%rbx", "%rdi", "%rsi" );                              /* Clobbers and scratch registers */

                // Check if the system call succedded, and if not throw an errno exception
				AssertSystemCallWasSuccessful_MACRO

                // Return the return value from the system call
                return ( systemCallReturnValue );
            }
































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 3   ****************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



































        // Template Class Information :
        //
        //  Purpose :
        //
        //      This object will be used to invoke a Linux system call using the assembly instruction 'syscall'. Parameters are passed by setting the following
        //      general purpose registers :
        //
        //           System call number    Argument 1    Argument 2    Argument 3    Argument 4    Argument 5    Argument 6
        //                  RAX              RDI           RSI           RDX           R10            R8           R9
        //
        //      The return value of each system call is stored in the register 'RAX'. The return value represents the errno error number
        //
        //  Description :
        //
        //      1. The object inherits from the object NoInstances to prevent any instances of the object
        //
        //      3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
        //
        //              1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
        //                          presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
        //                          lost, so it should be avoided in most cases
        //
        //              2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
        //                             all the data and methods inside this part. This part will usually containt some methods and few data members
        //
        //              3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
        //                           methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
        //                           suffix __Private
        //
        //  Possible errors :
        //
        //      Too many to count
        //
        template< typename... SystemCallTemplateArgumentsType >
        class SystemCall< 3UL, SystemCallTemplateArgumentsType... >
        {
        public:


            // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
            // access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
            // a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has three arguments
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 3 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 3
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            static inline SignedInteger32bits Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments );


    	private:


    		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances_MACRO( SystemCall )			


        };  //  Class SystemCall




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************






































            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has three arguments
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 3 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 3
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            template< typename... SystemCallTemplateArgumentsType >
            inline SignedInteger32bits SystemCall< 3UL, SystemCallTemplateArgumentsType... >::Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                Assert_MACRO( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" )
                Assert_MACRO( ( systemCallArguments.Size() == 3UL ), "The system call accepts 3 arguments" )

                // This will be used to store if the system call succeeded ( true ) or not ( false )
                SignedInteger32bits systemCallReturnValue = 0;

                // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
                // to execute. This is not possible using only C++

                __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                             		/* Move the system call number to the RAX register */
                                    "MOVQ RDI, %[SystemCallArgument_1];"                                         		/* Move the content of the first argument to the system call into the RDI register */
                                    "MOVQ RSI, %[SystemCallArgument_2];"                                         		/* Move the content of the second argument to the system call into the RSI register */
                                    "MOVQ RDX, %[SystemCallArgument_3];"                                         		/* Move the content of the third argument to the system call into the RDX register */
                                    "SYSCALL;"                                                                   		/* Invoke the kernel to execute the call */
                                    HandleSystemCallReturnValue_MACRO                                               	/* Check if the system call failed or not and act accordingly */

                                   : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                        	/* Output arguments */
                                   : [SystemCallNumber] "r0" ( systemCallNumber ),                                   	/* Input arguments */
                                     [SystemCallArgument_1] "r" ( systemCallArguments.template Entry< 0 >() ), 
                                     [SystemCallArgument_2] "r" ( systemCallArguments.template Entry< 1 >() ),       
                                     [SystemCallArgument_3] "r" ( systemCallArguments.template Entry< 2 >() )       
                                   : "memory", "cc", "%rax", "%rbx", "%rdi", "%rsi", "%rdx" );                      	/* Clobbers and scratch registers */

                // Check if the system call succedded, and if not throw an errno exception
				AssertSystemCallWasSuccessful_MACRO

                // Return the return value from the system call
                return ( systemCallReturnValue );
            }


































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 4   ****************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



































        // Template Class Information :
        //
        //  Purpose :
        //
        //      This object will be used to invoke a Linux system call using the assembly instruction 'syscall'. Parameters are passed by setting the following
        //      general purpose registers :
        //
        //           System call number    Argument 1    Argument 2    Argument 3    Argument 4    Argument 5    Argument 6
        //                  RAX              RDI           RSI           RDX           R10            R8           R9
        //
        //      The return value of each system call is stored in the register 'RAX'. The return value represents the errno error number
        //
        //  Description :
        //
        //      1. The object inherits from the object NoInstances to prevent any instances of the object
        //
        //      3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
        //
        //              1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
        //                          presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
        //                          lost, so it should be avoided in most cases
        //
        //              2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
        //                             all the data and methods inside this part. This part will usually containt some methods and few data members
        //
        //              3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
        //                           methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
        //                           suffix __Private
        //
        //  Possible errors :
        //
        //      Too many to count
        //
        template< typename... SystemCallTemplateArgumentsType >
        class SystemCall< 4UL, SystemCallTemplateArgumentsType... >
        {
        public:


            // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
            // access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
            // a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has four arguments
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 4 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 4
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            static inline SignedInteger32bits Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments );


    	private:


    		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances_MACRO( SystemCall )
			

        };  //  Class SystemCall





































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************






































            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has four arguments
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 4 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 4
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            template< typename... SystemCallTemplateArgumentsType >
            inline SignedInteger32bits SystemCall< 4UL, SystemCallTemplateArgumentsType... >::Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                Assert_MACRO( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" )
                Assert_MACRO( ( systemCallArguments.Size() == 4UL ), "The system call accepts 4 arguments" )

                // This will be used to store if the system call succeeded ( true ) or not ( false )
                SignedInteger32bits systemCallReturnValue = 0;

                // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
                // to execute. This is not possible using only C++

                __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                             			/* Move the system call number to the RAX register */
                                    "MOVQ RDI, %[SystemCallArgument_1];"                                         			/* Move the content of the first argument to the system call into the RDI register */
                                    "MOVQ RSI, %[SystemCallArgument_2];"                                         			/* Move the content of the second argument to the system call into the RSI register */
                                    "MOVQ RDX, %[SystemCallArgument_3];"                                         			/* Move the content of the third argument to the system call into the RDX register */
                                    "MOVQ R10, %[SystemCallArgument_4];"                                         			/* Move the content of the fourth argument to the system call into the R10 register */
                                    "SYSCALL;"                                                                   			/* Invoke the kernel to execute the call */
                                    HandleSystemCallReturnValue_MACRO                                               		/* Check if the system call failed or not and act accordingly */

                                   : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                        		/* Output arguments */
                                   : [SystemCallNumber] "r0" ( systemCallNumber ),                                  		/* Input arguments */
                                     [SystemCallArgument_1] "r" ( systemCallArguments.template Entry< 0 >() ), 
                                     [SystemCallArgument_2] "r" ( systemCallArguments.template Entry< 1 >() ),       
                                     [SystemCallArgument_3] "r" ( systemCallArguments.template Entry< 2 >() ),       
                                     [SystemCallArgument_4] "r" ( systemCallArguments.template Entry< 3 >() )       
                                   : "memory", "cc", "%rax", "%rbx", "%rdi", "%rsi", "%rdx", "%r10" );                    	/* Clobbers and scratch registers */

                // Check if the system call succedded, and if not throw an errno exception
				AssertSystemCallWasSuccessful_MACRO

                // Return the return value from the system call
                return ( systemCallReturnValue );
            }
































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 5   ****************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



































        // Template Class Information :
        //
        //  Purpose :
        //
        //      This object will be used to invoke a Linux system call using the assembly instruction 'syscall'. Parameters are passed by setting the following
        //      general purpose registers :
        //
        //           System call number    Argument 1    Argument 2    Argument 3    Argument 4    Argument 5    Argument 6
        //                  RAX              RDI           RSI           RDX           R10            R8           R9
        //
        //      The return value of each system call is stored in the register 'RAX'. The return value represents the errno error number
        //
        //  Description :
        //
        //      1. The object inherits from the object NoInstances to prevent any instances of the object
        //
        //      3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
        //
        //              1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
        //                          presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
        //                          lost, so it should be avoided in most cases
        //
        //              2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
        //                             all the data and methods inside this part. This part will usually containt some methods and few data members
        //
        //              3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
        //                           methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
        //                           suffix __Private
        //
        //  Possible errors :
        //
        //      Too many to count
        //
        template< typename... SystemCallTemplateArgumentsType >
        class SystemCall< 5UL, SystemCallTemplateArgumentsType... >
        {
        public:


            // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
            // access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
            // a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has five arguments
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 5 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 5
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            static inline SignedInteger32bits Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments );


    	private:


    		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances_MACRO( SystemCall )
			

        };  //  Class SystemCall





































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************






































            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has five arguments
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 5 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 5
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            template< typename... SystemCallTemplateArgumentsType >
            inline SignedInteger32bits SystemCall< 5UL, SystemCallTemplateArgumentsType... >::Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                Assert_MACRO( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" )
                Assert_MACRO( ( systemCallArguments.Size() == 5UL ), "The system call accepts 5 arguments" )

                // This will be used to store if the system call succeeded ( true ) or not ( false )
                SignedInteger32bits systemCallReturnValue = 0;

                // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
                // to execute. This is not possible using only C++

                __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                             			/* Move the system call number to the RAX register */
                                    "MOVQ RDI, %[SystemCallArgument_1];"                                         			/* Move the content of the first argument to the system call into the RDI register */
                                    "MOVQ RSI, %[SystemCallArgument_2];"                                         			/* Move the content of the second argument to the system call into the RSI register */
                                    "MOVQ RDX, %[SystemCallArgument_3];"                                         			/* Move the content of the third argument to the system call into the RDX register */
                                    "MOVQ R10, %[SystemCallArgument_4];"                                         			/* Move the content of the fourth argument to the system call into the R10 register */
                                    "MOVQ R8, %[SystemCallArgument_5];"                                          			/* Move the content of the fifth argument to the system call into the R8 register */
                                    "SYSCALL;"                                                                   			/* Invoke the kernel to execute the call */
                                    HandleSystemCallReturnValue_MACRO                                               		/* Check if the system call failed or not and act accordingly */

                                   : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                        		/* Output arguments */
                                   : [SystemCallNumber] "r0" ( systemCallNumber ),                                  		/* Input arguments */
                                     [SystemCallArgument_1] "r" ( systemCallArguments.template Entry< 0 >() ), 
                                     [SystemCallArgument_2] "r" ( systemCallArguments.template Entry< 1 >() ),       
                                     [SystemCallArgument_3] "r" ( systemCallArguments.template Entry< 2 >() ),       
                                     [SystemCallArgument_4] "r" ( systemCallArguments.template Entry< 3 >() ),       
                                     [SystemCallArgument_5] "r" ( systemCallArguments.template Entry< 4 >() )       
                                   : "memory", "cc", "%rax", "%rbx", "%rdi", "%rsi", "%rdx", "%r10", "%r8" );              /* Clobbers and scratch registers */

                // Check if the system call succedded, and if not throw an errno exception
				AssertSystemCallWasSuccessful_MACRO

                // Return the return value from the system call
                return ( systemCallReturnValue );
            }

































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 6   ****************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //






































        // Template Class Information :
        //
        //  Purpose :
        //
        //      This object will be used to invoke a Linux system call using the assembly instruction 'syscall'. Parameters are passed by setting the following
        //      general purpose registers :
        //
        //           System call number    Argument 1    Argument 2    Argument 3    Argument 4    Argument 5    Argument 6
        //                  RAX              RDI           RSI           RDX           R10            R8           R9
        //
        //      The return value of each system call is stored in the register 'RAX'. The return value represents the errno error number
        //
        //  Description :
        //
        //      1. The object inherits from the object NoInstances to prevent any instances of the object
        //
        //      3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords :
        //
        //              1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools
        //                          presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
        //                          lost, so it should be avoided in most cases
        //
        //              2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access
        //                             all the data and methods inside this part. This part will usually containt some methods and few data members
        //
        //              3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the
        //                           methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the
        //                           suffix __Private
        //
        //  Possible errors :
        //
        //      Too many to count
        //
        template< typename... SystemCallTemplateArgumentsType >
        class SystemCall< 6UL, SystemCallTemplateArgumentsType... >
        {
        public:


            // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
            // access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
            // a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has six arguments
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 6 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 6
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            static inline SignedInteger32bits Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments );


    	private:


    		// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances_MACRO( SystemCall )
			

        };  //  Class SystemCall





































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************






































            // Method Information :
            //
            //  Description :
            //
            //      This is a template specialization for system calls that has six arguments
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. systemCallNumber - the number of the system call to invoke
            //          2. systemCallArguments - the arguments required to invoke the system call ( in this case 6 )
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
            //      1. The given system call number is in the range [ 0 - MaximumSystemCallNumber ]
            //      2. The given number of system call template arguments should be 6
            //      3. 
            //
            //  Possible errors :
            //
            //      1. The system call failed - an object of type ErrnoException is thrown 
            //      2.
            //
            template< typename... SystemCallTemplateArgumentsType >
            inline SignedInteger32bits SystemCall< 6UL, SystemCallTemplateArgumentsType... >::Invoke( SignedInteger32bits systemCallNumber, const Tuple< SystemCallTemplateArgumentsType... >& systemCallArguments )
            {
                // This will be added only in test mode, to ensure that the given data to the method is valid
                Assert_MACRO( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" )
                Assert_MACRO( ( systemCallArguments.Size() == 6UL ), "The system call accepts 6 arguments" )

                // This will be used to store if the system call succeeded ( true ) or not ( false )
                SignedInteger32bits systemCallReturnValue = 0;

                // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
                // to execute. This is not possible using only C++

                __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                             			/* Move the system call number to the RAX register */
                                    "MOVQ RDI, %[SystemCallArgument_1];"                                         			/* Move the content of the first argument to the system call into the RDI register */
                                    "MOVQ RSI, %[SystemCallArgument_2];"                                         			/* Move the content of the second argument to the system call into the RSI register */
                                    "MOVQ RDX, %[SystemCallArgument_3];"                                         			/* Move the content of the third argument to the system call into the RDX register */
                                    "MOVQ R10, %[SystemCallArgument_4];"                                         			/* Move the content of the fourth argument to the system call into the R10 register */
                                    "MOVQ R8, %[SystemCallArgument_5];"                                          			/* Move the content of the fifth argument to the system call into the R8 register */
                                    "MOVQ R9, %[SystemCallArgument_6];"                                          			/* Move the content of the sixth argument to the system call into the R9 register */
                                    "SYSCALL;"                                                                   			/* Invoke the kernel to execute the call */
                                    HandleSystemCallReturnValue_MACRO                                               		/* Check if the system call failed or not and act accordingly */

                                   : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                        		/* Output arguments */
                                   : [SystemCallNumber] "r0" ( systemCallNumber ),                                  		/* Input arguments */
                                     [SystemCallArgument_1] "r" ( systemCallArguments.template Entry< 0 >() ), 
                                     [SystemCallArgument_2] "r" ( systemCallArguments.template Entry< 1 >() ),       
                                     [SystemCallArgument_3] "r" ( systemCallArguments.template Entry< 2 >() ),       
                                     [SystemCallArgument_4] "r" ( systemCallArguments.template Entry< 3 >() ),       
                                     [SystemCallArgument_5] "r" ( systemCallArguments.template Entry< 4 >() ),       
                                     [SystemCallArgument_6] "r" ( systemCallArguments.template Entry< 5 >() )       
                                   : "memory", "cc", "%rax", "%rbx", "%rdi", "%rsi", "%rdx", "%r10", "%r8", "%r9" );        /* Clobbers and scratch registers */

                // Check if the system call succedded, and if not throw an errno exception
				AssertSystemCallWasSuccessful_MACRO

                // Return the return value from the system call
                return ( systemCallReturnValue );
            }









































































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
            template< UnsignedInteger64bits NumberOfSystemCallTemplateArguments COMMA typename... SystemCallTemplateArgumentsType >
    		void SystemCall< NumberOfSystemCallTemplateArguments COMMA SystemCallTemplateArgumentsType... >::Test()
    		{
				// Create a place to store the content from read
				SignedInteger8bits testCharacter_1 = 0;

				// Display to the user to enter a character
				std::cout << "Please enter a character :" << std::endl;

				// Wait for the character
    			SystemCall< 3 COMMA UnsignedInteger64bits COMMA const SignedInteger8bits* COMMA UnsignedInteger64bits >::Invoke( 0, Tuple< UnsignedInteger64bits COMMA const SignedInteger8bits* COMMA UnsignedInteger64bits >( 0UL, &testCharacter_1, 1UL ) );

				// Write to standard output
    			SystemCall< 3 COMMA UnsignedInteger64bits COMMA const SignedInteger8bits* COMMA UnsignedInteger64bits >::Invoke( 1, Tuple< UnsignedInteger64bits COMMA const SignedInteger8bits* COMMA UnsignedInteger64bits >( 1UL, "Thank you for the character", 27UL ) );
    		}

    	)  //  End of debug tool







    }  //  Namespace Linux

}  //  Namespace Universe


#endif  // SYSTEMCALL_HPP