namespace Universe
{


namespace CentralProcessingUnit
{



// A temporary rvalue can not bind to a non-const lvalue reference. It's the rule. Both clang and gcc don't compile the following code :
//
//
//      struct STRUCT
//      {
//          STRUCT( int a ) {}
//      };
//
//      void func1( int& i ) {}
//      void func2( STRUCT& s ) {}
//      void func3( int i ) {}
//      void func4( STRUCT s ) {}
//
//      void main()
//      {
//          func1( int( 56 ) );         // ERROR: C2664 - can't bind temporary to a non const reference
//          func2( STRUCT( 65 ) );      // ERROR: C2664 - can't bind temporary to a non const reference
//          func3( int( 46 ) );         // OK: anonymous int is created then assigned to a parameter
//          func4( STRUCT( 12 ) );      // OK: anonymous object is created then assigned to a parameter
//      }
//
//
// Instead there are alternatives :
//
//      void func1( int&& i ) {}   -->   rvalue reference
//      
//      void func1( const int& i ) {}   -->   lvalue const reference
//   
// Legacy from C++03 - A ( lvalue ) reference to a non-const type supposed to able to change the parameter then passing a temporary object such as 56 is not 
// logical because it not changeable. A reference to a const type supposed to just observe the value as read-only, then passing a temporary value such as 52 
// is legal. In C++11 you can reference to a non-const temporary object by using the rvalue reference sign ( && )



//	Use following macros to obtain the content of all the 16 multi purpose registers in the 64 bits Intel architecture :
//
//			64 bit register 	Lower 32 bits 		Lower 16 bits 		Lower 8 bits
//
//				  rax 				 eax 				 ax 				  al	
//				  rbx 				 ebx 				 bx 				  bl	
//				  rcx 				 ecx 				 cx 				  cl	
//				  rdx 				 edx 				 dx 				  dl	
//				  rsi 				 esi 				 si 				  sil	
//				  rdi 				 edi 				 di 				  dil	
//				  rbp 				 ebp 				 bp 				  bpl	
//				  rsp 				 esp 				 sp 				  spl	
//				  r8 				 r8d 				 r8w 				  r8b	
//				  r9 				 r9d 				 r9w 				  r9b	
//				  r10 				 r10d 				 r10w 				  r10b	
//				  r11 				 r11d 				 r11w 				  r11b	
//				  r12 				 r12d 				 r12w 				  r12b	
//				  r13 				 r13d 				 r13w 				  r13b	
//				  r14 				 r14d 				 r14w 				  r14b	
//				  r15 				 r15d 				 r15w 				  r15b



// Use this macro to create a variable with the name given, and store the content of the 64 bit RAX multi purpose register into it
//
#define GetRegisterContent_RAX( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], RAX;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit RBX multi purpose register into it
//
#define GetRegisterContent_RBX( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], RBX;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit RCX multi purpose register into it
//
#define GetRegisterContent_RCX( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], RCX;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit RDX multi purpose register into it
//
#define GetRegisterContent_RDX( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], RDX;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit RSI multi purpose register into it
//
#define GetRegisterContent_RSI( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], RSI;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit RDI multi purpose register into it
//
#define GetRegisterContent_RDI( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], RDI;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit RBP multi purpose register into it
//
#define GetRegisterContent_RBP( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This pointer will store the content of the required register */ 																								\
	void* VariableNameToStoreRegisterContent = 0UL; 																												\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], RBP;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit RSP multi purpose register into it
//
#define GetRegisterContent_RSP( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This pointer will store the content of the required register */ 																								\
	void* VariableNameToStoreRegisterContent = 0UL; 																												\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], RSP;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit R8 multi purpose register into it
//
#define GetRegisterContent_R8( VariableNameToStoreRegisterContent )																									\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], R8;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit R9 multi purpose register into it
//
#define GetRegisterContent_R9( VariableNameToStoreRegisterContent )																									\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], R9;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit R10 multi purpose register into it
//
#define GetRegisterContent_R10( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], R10;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit R11 multi purpose register into it
//
#define GetRegisterContent_R11( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], R11;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */

// Use this macro to create a variable with the name given, and store the content of the 64 bit R12 multi purpose register into it
//
#define GetRegisterContent_R12( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], R12;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit R13 multi purpose register into it
//
#define GetRegisterContent_R13( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], R13;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit R14 multi purpose register into it
//
#define GetRegisterContent_R14( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], R14;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */


// Use this macro to create a variable with the name given, and store the content of the 64 bit R15 multi purpose register into it
//
#define GetRegisterContent_R15( VariableNameToStoreRegisterContent )																								\
																																									\
	/* This object will store the content of the required register */ 																								\
	LargestUnsignedInteger VariableNameToStoreRegisterContent = 0UL; 																								\
																																									\
    /* The following is an extended inline assembly statement. It will be used to read the required register content into a variable. This is not 					\
       possible only using C++ */ 																																	\
    __asm__ volatile ( "MOVQ %[registerContentDestination], R15;"          								/* Assembly code */ 										\
																																									\
                        : [registerContentDestination] "=m" ( VariableNameToStoreRegisterContent )     	/* Output arguments */ 										\
                        :       																		/* Input arguments */ 										\
                        : "memory" )	                                                       			/* Clobbers and scratch registers */



}  //  Namespace CentralProcessingUnit


}  //  Namespace Universe