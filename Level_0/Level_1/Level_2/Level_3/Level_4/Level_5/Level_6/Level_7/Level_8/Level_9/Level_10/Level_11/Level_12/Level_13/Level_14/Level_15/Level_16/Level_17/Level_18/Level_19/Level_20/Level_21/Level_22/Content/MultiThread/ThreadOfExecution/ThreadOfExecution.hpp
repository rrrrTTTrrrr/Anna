namespace Universe
{


namespace MultiThread
{



// https://wiki.osdev.org/Main_Page
// https://github.com/cirosantilli/x86-bare-metal-examples



// On x86 processors, multiprocessor ( and multitherad ) communication is done through the advances programmable interrupt controllers
// ( APIC ). When the operating system starts, only one logical processor is running the operating system code, to confirm to legacy
// single processor behavior.
//
// The operating system uses the advanced programmable interrupt controllers to send a startup inter processor interrupt ( SIPI ) to every
// other thread. Each thread wakes up, and updates a memory region to allow the main thread to know it exist. This way the main thread
// knows how many processors it has to work with. After each thread announces itself, it goes to a low power, interruptible state.
//
// When the operating system wants to run something on that logical processor, it has the currently running processor send an inter process
// interrupt ( IPI ) through the advanced programmable interrupt controllers. When the task is done, the logical processor can go back to
// the low power state, waiting for the next interrupt



// To start a new thread, a memory block needs to be allocated ( from a memory allocator written already ) for the stack of the new thread.
// Then a periodic timer tick which will run a scheduler code ( written already ), which saves register contents and switches between the
// threads stacks



// Intel x86 minimal runnable baremetal example :
//
// The Intel manual covers symmetric multiprocessing or shared memory multiprocessing in chapters 8-10.
//
// Table 8-1, "Broadcast INIT-SIPI-SIPI Sequence and choice of Timeouts" contains an example that basically works :
//
//		MOV ESI, ICR_LOW		; Load address of interrupt command register low dword into ESI
//		MOV EAX, 000C4500H		; Load interrupt command register encoding for broadcast INIT inter processor interrupt to all application processors into EAX
//		MOV [ESI], EAX 			; Broadcast INIT inter processor interrupt to all application processors
//								; 10-millisecond delay loop
//		MOV EAX, 000C46XXH		; Load interrupt command register encoding for broadcast SIPI IP to all application processors into EAX, where xx is the vector computed in step 10
//		MOV [ESI], EAX 			; Broadcast SIPI inter processor interrupt to all application processors
//								; 200-microsecond delay loop
//		MOV [ESI], EAX 			; Broadcast second SIPI inter processor interrupt to all application processors
//								; Waits for the timer interrupt until the timer expires
//
// At first, a single processor runs, called the bootstrap processor ( BSP ). It must wake up the other ones, called Application processors ( AP )
// through special interrupts called inter processor interrupts ( IPI ). Those interrupts can be done by programminh advanced programmable
// interrupt controller ( APIC ) through the interrupt command register ( ICR ). The format of the interrupt command register is documented
// a 10.6 "Issuing interprocessor interrupts". The inter processor interrupt happens right after the interrupt command register is set.
//
// 'ICR_LOW' is defined at 8.4.4 "MP initialization Example" as :
//
//		ICR_LOW EQU 0FEE00300H
//
// The magic value '0FEE00300H' is the memory address of the interrupt command register, as documented at table 10-1 "Local APIC Register 
// Address Map".
//
// The simplest possible method is used in the example, it sets up the interrupt command register to send broadcast inter processor 
// interrupts, which are delivered to all other processors except the current one. It is also possible, and recommended by some, to
// get information about the processors through special data structures setup by the BIOS like ACPI tables or Intel's MP configuration
// table and only wake up the ones you need one by one.
//
// 'XX' in '000C46XXH' encodes the address of the first instruction that the processor will execute as :
//
//		CS = XX * 0x100
//		IP = 0
//
// CS multiplies addresses by 0x10, so the actual memory address of the first instruction is :
//
//		XX * 0x1000
//
// If for example the value of 'XX' is 1, the processor will start at 0x1000. It must be ensures as wll that there is a 16-bit real
// mode code to be run at that memory location using the following code :
//
//		CLD 					; Clears the DF flag in the EFLAGS register. When the DF flag is set to 0, string operations increment the index registers ( ESI and/or EDI )
//		MOV ECX, $INIT_LEN
//		MOV ESI, $INIT
//		MOV EDI, 0x1000
//		REP MOVSB 				; Repeat string operation until tested condition is met. In this case copy the 8 bit byte from the DS register to the DI register, repeat the process while equal
//
//		**** NEEDS TO BE FIXED - it is written in at&t assembly ****
//
//		.code16
//		init:
//			XOR AX, AX
//			MOV DS, AX
//			/* Do stuff */
//			HLT
//		.equ INIT_LEN, . - INIT
//
//		**** NEEDS TO BE FIXED - it is written in at&t assembly ****
//
// The delay loops are an annoying part to get working, there is no simple way to do such sleeps precisely. Possible method include :
//
//		1. PIT
//		2. HPET
//		3. Calibrate the time of a busy loop with the above, and use it instead
//
// The initial processor needs to be in protected mode for this work as the address written is '0FEE00300H' which is too high for 16 bits.
// To communicate between processors, a spiclock can be used on the main process, and modify the lock from the second core. It needs to 
// be ensured that memory write back id done ( can be through 'wbinvd' ).
//
// In Linux the main initialization seems to be at the file 'arch/x86/kernel/smpboot.c'!
//
// Next steps for more convenient programmability :
//
// The previous sections wake up secondary central processing units and do basic memory synchronization with dedicated instructions, which
// is a good start. But to make multicore systems easy to program, there are more steps :
//
// 	1. Setup interrupts and run a timer that periodically decides which thread will run now. This is known as preemptive multithreading.
//	   Such system also needs to save and restore thread registers as they are started and stopped
//	2. Deal with memory conflicts. Notable, each thread will need a unique stack. It is possible to limit threads to have a fixed maximum 
//	   stack size, but the nicer way to deal with this is by 'paging', which allows for efficient "unlimitied size" stacks



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store the memory address of a specific method, and allowing to invoke it during run time. The difference between a
//		function and method, is that method is a function that belongs to an object
//
//  Description :
//
//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
//
// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		3. Template arguments :
//
//			1. ObjectType - the type of the object the method belongs to
//			2. ReturnType - the return value type of the required function
//			3. MethodArgumentTypes - the arguments types of the required function
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename FunctionType >
class ThreadOfExecution NotForInheritance
{
private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( ThreadOfExecution );


};



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - With return value and at least one argument   *****************************************  //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



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
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::NonVoid ReturnType, typename FirstArgumentType, typename... RestOfArgumentsTypes >
class ThreadOfExecution< ReturnType ( FirstArgumentType, RestOfArgumentsTypes... ) > NotForInheritance
{
public:


	// Create a type definition for the function signature
	using FunctionSignatureType = ReturnType ( FirstArgumentType, RestOfArgumentsTypes... );

	// Create a type definition for this object
	using SelfType = ThreadOfExecution< FunctionSignatureType >;


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
	//			1. callable - a constant reference to the callable that will run in the created thread of execution
	//			2. arguments - any arguments the function requires
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
	//		1. The given function encounters an error, and throws an exception
	//		2. 
	//
	explicit inline ThreadOfExecution( Callable< FunctionSignatureType >&& callable, FirstArgumentType&& firstArgument, RestOfArgumentsTypes&&... arguments );


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
	inline ~ThreadOfExecution() = default;


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
	inline void WaitForThreadOfExecutionToFinish();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_FromMemberGetMethod_Creator( /* GetMethodName */ WasExceptionThrown, /* MemberName */ member_result, /* MemberGetMethodName */ WasExceptionThrown, /* MemberType */ Boolean )
	GetByConstantReference_FromMemberGetMethod_Creator( /* GetMethodName */ ErrorMessage, /* MemberName */ member_result, /* MemberGetMethodName */ ErrorMessage, /* MemberType */ Language::String )
	GetByConstantReference_FromMemberGetMethod_Creator( /* GetMethodName */ ReturnValue, /* MemberName */ member_result, /* MemberGetMethodName */ ReturnValue, /* MemberType */ ReturnType )


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
		static inline void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:

	// This object will store the function that needs to be called in the new thread of execution
	Callable< FunctionSignatureType > member_callable;

	// This object will be used to create and manage the thread of execution
	Memory::HeapPointer< Linux::PosixThread > member_posixThreadPointer;

	// This object will store the results of user provided function that ran in the thread of execution
	ThreadOfExecutionResult< ReturnType > member_result;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		This is the actual method that will run in the thread of execution. It will be responsible to start unpacking the tuple, 
	//		it will extract the function pointer, and create a reference to the arguments part of the tuple. Finally it will call
	//		another function that will finally unpack the arguments of the tuple, and use them to call the function that the user
	//		provided. Also it will deal with the return value properly
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			argument - a pointer to void, in reality it will point to a memory address with the tuple
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A pointer to the required return value
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed static inline void* FunctionThatWillRunInTheNewThreadOfExecution__Private( void* argument );


	// Method Information :
	//
	//  Description :
	//
	//		This method will be provided with the function pointer and a tuple of arguments for the function. It will unpack the tuple
	//		and call the required function with those arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. callable - a constant reference to the callable that will run in the created thread of execution
	//			2. arguments - a tuple containing all the arguments to the function
	//          3. An incrementing integer sequence, it is part of the functionality required to invoke the function using the tuple
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A pointer to the required return value
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< UnsignedInteger64bits... ArgumentIndices >
	static inline ReturnType FunctionToUnpackTheTupleAndInvokeTheCallableWithTheArguments__Private( const Callable< FunctionSignatureType >& callable, Memory::Tuple< FirstArgumentType, RestOfArgumentsTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > );


};  //  Class ThreadOfExecution




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - With no return value and at least one argument   ***************************************  //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //




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
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename FirstArgumentType, typename... RestOfArgumentsTypes >
class ThreadOfExecution< void ( FirstArgumentType, RestOfArgumentsTypes... ) > NotForInheritance
{
public:


	// Create a type definition for the function signature
	using FunctionSignatureType = void ( FirstArgumentType, RestOfArgumentsTypes... );

	// Create a type definition for this object
	using SelfType = ThreadOfExecution< FunctionSignatureType >;


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
	//			1. callable - a constant reference to the callable that will run in the created thread of execution
	//			2. arguments - any arguments the function requires
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
	//		1. The given function encounters an error, and throws an exception
	//		2. 
	//
	explicit inline ThreadOfExecution( Callable< FunctionSignatureType >&& callable, FirstArgumentType&& firstArgument, RestOfArgumentsTypes&&... arguments );


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
	inline ~ThreadOfExecution() = default;


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
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline void WaitForThreadOfExecutionToFinish();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_FromMemberGetMethod_Creator( /* GetMethodName */ WasExceptionThrown, /* MemberName */ member_result, /* MemberGetMethodName */ WasExceptionThrown, /* MemberType */ Boolean )
	GetByConstantReference_FromMemberGetMethod_Creator( /* GetMethodName */ ErrorMessage, /* MemberName */ member_result, /* MemberGetMethodName */ ErrorMessage, /* MemberType */ Language::String )


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
		static inline void UnitTest() __attribute__ (( __unused__ )) { ThreadOfExecution< UnsignedInteger64bits ( UnsignedInteger64bits, UnsignedInteger64bits ) >::UnitTest(); }

	)  //  End of debug tool


private:


	// This object will store the function that needs to be called in the new thread of execution
	Callable< FunctionSignatureType > member_callable;

	// This object will be used to create and manage the thread of execution
	Memory::HeapPointer< Linux::PosixThread > member_posixThreadPointer;

	// This object will store the results of user provided function that ran in the thread of execution
	ThreadOfExecutionResult< void > member_result;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		This is the actual method that will run in the thread of execution. It will be responsible to start unpacking the tuple, 
	//		it will extract the function pointer, and create a reference to the arguments part of the tuple. Finally it will call
	//		another function that will finally unpack the arguments of the tuple, and use them to call the function that the user
	//		provided. Also it will deal with the return value properly
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			argument - a pointer to void, in reality it will point to a memory address with the tuple
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
	//		NONE
	//
	static inline void* FunctionThatWillRunInTheNewThreadOfExecution__Private( void* argument );


	// Method Information :
	//
	//  Description :
	//
	//		This method will be provided with the function pointer and a tuple of arguments for the function. It will unpack the tuple
	//		and call the required function with those arguments
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			1. callable - a constant reference to the callable that will run in the created thread of execution
	//			2. arguments - a tuple containing all the arguments to the function
	//          3. An incrementing integer sequence, it is part of the functionality required to invoke the function using the tuple
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A pointer to the required return value
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	template< UnsignedInteger64bits... ArgumentIndices >
	static inline void FunctionToUnpackTheTupleAndInvokeTheCallableWithTheArguments__Private( const Callable< FunctionSignatureType >& callable, Memory::Tuple< FirstArgumentType, RestOfArgumentsTypes... >& arguments, IncrementingIntegerSequenceHolder< ArgumentIndices... > );


};  //  Class ThreadOfExecution




// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function   ************************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



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
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::NonVoid ReturnType >
class ThreadOfExecution< ReturnType () > NotForInheritance
{
public:


	// Create a type definition for the function signature
	using FunctionSignatureType = ReturnType ();

	// Create a type definition for this object
	using SelfType = ThreadOfExecution< FunctionSignatureType >;


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
	//			callable - a constant reference to the callable that will run in the created thread of execution
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
	//		1. The given function encounters an error, and throws an exception
	//		2. 
	//
	explicit inline ThreadOfExecution( Callable< FunctionSignatureType >&& callable );


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
	inline ~ThreadOfExecution() = default;


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
	//      The return value from the function the user provided to execute
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	inline void WaitForThreadOfExecutionToFinish();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_FromMemberGetMethod_Creator( /* GetMethodName */ WasExceptionThrown, /* MemberName */ member_result, /* MemberGetMethodName */ WasExceptionThrown, /* MemberType */ Boolean )
	GetByConstantReference_FromMemberGetMethod_Creator( /* GetMethodName */ ErrorMessage, /* MemberName */ member_result, /* MemberGetMethodName */ ErrorMessage, /* MemberType */ Language::String )
	GetByConstantReference_FromMemberGetMethod_Creator( /* GetMethodName */ ReturnValue, /* MemberName */ member_result, /* MemberGetMethodName */ ReturnValue, /* MemberType */ ReturnType )


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
		static inline void UnitTest() __attribute__ (( __unused__ )) { ThreadOfExecution< UnsignedInteger64bits ( UnsignedInteger64bits, UnsignedInteger64bits ) >::UnitTest(); }

	)  //  End of debug tool


private:


	// This object will store the function that needs to be called in the new thread of execution
	Callable< FunctionSignatureType > member_callable;

	// This object will be used to create and manage the thread of execution
	Memory::HeapPointer< Linux::PosixThread > member_posixThreadPointer;

	// This object will store the results of user provided function that ran in the thread of execution
	ThreadOfExecutionResult< ReturnType > member_result;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		This is the actual method that will run in the thread of execution. It will be responsible to start to call the function
	//		the user provided and deal with the return value properly
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			argument - a pointer to void, in reality it will point to a memory address with the function pointer
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A pointer to the required return value
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	EnsureRetrunValueIsUsed static inline void* FunctionThatWillRunInTheNewThreadOfExecution__Private( void* argument );


};  //  Class ThreadOfExecution



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - No arguments to function and return value   ****************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



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
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template<>
class ThreadOfExecution< void () > NotForInheritance
{
public:


	// Create a type definition for the function signature
	using FunctionSignatureType = void ();

	// Create a type definition for this object
	using SelfType = ThreadOfExecution< FunctionSignatureType >;


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
	//			callable - a constant reference to the callable that will run in the created thread of execution
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
	//		1. The given function encounters an error, and throws an exception
	//		2. 
	//
	explicit inline ThreadOfExecution( Callable< FunctionSignatureType >&& callable );


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
	inline ~ThreadOfExecution() = default;


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
	inline void WaitForThreadOfExecutionToFinish();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_FromMemberGetMethod_Creator( /* GetMethodName */ WasExceptionThrown, /* MemberName */ member_result, /* MemberGetMethodName */ WasExceptionThrown, /* MemberType */ Boolean )
	GetByConstantReference_FromMemberGetMethod_Creator( /* GetMethodName */ ErrorMessage, /* MemberName */ member_result, /* MemberGetMethodName */ ErrorMessage, /* MemberType */ Language::String )


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
		static inline void UnitTest() __attribute__ (( __unused__ )) { ThreadOfExecution< UnsignedInteger64bits ( UnsignedInteger64bits, UnsignedInteger64bits ) >::UnitTest(); }

	)  //  End of debug tool


private:


	// This object will store the function that needs to be called in the new thread of execution
	Callable< FunctionSignatureType > member_callable;

	// This object will be used to create and manage the thread of execution
	Memory::HeapPointer< Linux::PosixThread > member_posixThreadPointer;

	// This object will store the results of user provided function that ran in the thread of execution
	ThreadOfExecutionResult< void > member_result;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//		This is the actual method that will run in the thread of execution, it will invoke inside it the function that the user
	//		provided
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			argument - a pointer to void, in reality it will point to a memory address with the tuple
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
	//		NONE
	//
	static inline void* FunctionThatWillRunInTheNewThreadOfExecution__Private( void* argument );


};  //  Class ThreadOfExecution