// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 0   ****************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template<>
inline SignedInteger32bits SystemCall< 0UL >::Invoke( const SignedInteger32bits systemCallNumber )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid
    Assert( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" );

    // This will be used to store if the system call succeeded ( true ) or not ( false )
    SignedInteger32bits systemCallReturnValue = 0;

    // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and all the
    // required registers with the arguments to the system call. Now the kernel can be invoked to execute the call. This is not possible using only C++

    __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                     	/* Move the system call number to the RAX register */
                        "SYSCALL;"                                                           	/* Invoke the kernel to execute the call */
                        HandleSystemCallReturnValue                                       /* Check if the system call failed or not and act accordingly */

                       : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                /* Output arguments */
                       : [SystemCallNumber] "r0" ( systemCallNumber )                           /* Input arguments */
                       : "memory", "cc", "%rax", "%rbx" );                                      /* Clobbers and scratch registers */

    // Check if the system call succedded, and if not throw an errno exception
	AssertSystemCallWasSuccessful;

    // Return the return value from the system call
    return ( systemCallReturnValue );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 1   ****************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename... SystemCallArgumentTypes >
inline SignedInteger32bits SystemCall< 1UL, SystemCallArgumentTypes... >::Invoke( const SignedInteger32bits systemCallNumber, SystemCallArgumentTypes... systemCallArguments )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid
    Assert( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" );
    Assert( ( sizeof...( systemCallArguments ) == 1UL ), "The system call accepts 1 argument" );

    // Store the arguments to the system call into a tuple
    const Memory::Tuple< SystemCallArgumentTypes... > systemCallArgumentsTuple( systemCallArguments... );

    // This will be used to store if the system call succeeded ( true ) or not ( false )
    SignedInteger32bits systemCallReturnValue = 0;

    // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
    // to execute. This is not possible using only C++

    __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                             /* Move the system call number to the RAX register */
                        "MOVQ RDI, %[SystemCallArgument_1];"                                        /* Move the content of the first argument to the system call into the RDI register */
                        "SYSCALL;"                                                                  /* Invoke the kernel to execute the call */
                        HandleSystemCallReturnValue                                           /* Check if the system call failed or not and act accordingly */

                       : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                    /* Output arguments */
                       : [SystemCallNumber] "r0" ( systemCallNumber ),                              /* Input arguments */
                         [SystemCallArgument_1] "r" ( systemCallArgumentsTuple.template Entry< 0 >() )     
                       : "memory", "cc", "%rax", "%rbx", "%rdi" );                                  /* Clobbers and scratch registers */

    // Check if the system call succedded, and if not throw an errno exception
    AssertSystemCallWasSuccessful;

    // Return the return value from the system call
    return ( systemCallReturnValue );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 2   ****************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename... SystemCallArgumentTypes >
inline SignedInteger32bits SystemCall< 2UL, SystemCallArgumentTypes... >::Invoke( const SignedInteger32bits systemCallNumber, SystemCallArgumentTypes... systemCallArguments )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid
    Assert( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" );
    Assert( ( sizeof...( systemCallArguments ) == 2UL ), "The system call accepts 2 arguments" );

    // Store the arguments to the system call into a tuple
    const Memory::Tuple< SystemCallArgumentTypes... > systemCallArgumentsTuple( systemCallArguments... );

    // This will be used to store if the system call succeeded ( true ) or not ( false )
    SignedInteger32bits systemCallReturnValue = 0;

    // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
    // to execute. This is not possible using only C++

    __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                                 /* Move the system call number to the RAX register */
                        "MOVQ RDI, %[SystemCallArgument_1];"                                            /* Move the content of the first argument to the system call into the RDI register */
                        "MOVQ RSI, %[SystemCallArgument_2];"                                            /* Move the content of the second argument to the system call into the RDI register */
                        "SYSCALL;"                                                                      /* Invoke the kernel to execute the call */
                        HandleSystemCallReturnValue                                               /* Check if the system call failed or not and act accordingly */
                       
                       : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                        /* Output arguments */
                       : [SystemCallNumber] "r0" ( systemCallNumber ),                                  /* Input arguments */
                         [SystemCallArgument_1] "r" ( systemCallArgumentsTuple.template Entry< 0 >() ), 
                         [SystemCallArgument_2] "r" ( systemCallArgumentsTuple.template Entry< 1 >() )       
                       : "memory", "cc", "%rax", "%rbx", "%rdi", "%rsi" );                              /* Clobbers and scratch registers */

    // Check if the system call succedded, and if not throw an errno exception
    AssertSystemCallWasSuccessful;

    // Return the return value from the system call
    return ( systemCallReturnValue );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 3   ****************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename... SystemCallArgumentTypes >
inline SignedInteger32bits SystemCall< 3UL, SystemCallArgumentTypes... >::Invoke( const SignedInteger32bits systemCallNumber, SystemCallArgumentTypes... systemCallArguments )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid
    Assert( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" );
    Assert( ( sizeof...( systemCallArguments ) == 3UL ), "The system call accepts 3 arguments" );

    // Store the arguments to the system call into a tuple
    const Memory::Tuple< SystemCallArgumentTypes... > systemCallArgumentsTuple( systemCallArguments... );

    // This will be used to store if the system call succeeded ( true ) or not ( false )
    SignedInteger32bits systemCallReturnValue = 0;

    // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
    // to execute. This is not possible using only C++

    __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                                     /* Move the system call number to the RAX register */
                        "MOVQ RDI, %[SystemCallArgument_1];"                                                /* Move the content of the first argument to the system call into the RDI register */
                        "MOVQ RSI, %[SystemCallArgument_2];"                                                /* Move the content of the second argument to the system call into the RSI register */
                        "MOVQ RDX, %[SystemCallArgument_3];"                                                /* Move the content of the third argument to the system call into the RDX register */
                        "SYSCALL;"                                                                          /* Invoke the kernel to execute the call */
                        HandleSystemCallReturnValue                                                   /* Check if the system call failed or not and act accordingly */

                       : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                            /* Output arguments */
                       : [SystemCallNumber] "r0" ( systemCallNumber ),                                      /* Input arguments */
                         [SystemCallArgument_1] "r" ( systemCallArgumentsTuple.template Entry< 0 >() ), 
                         [SystemCallArgument_2] "r" ( systemCallArgumentsTuple.template Entry< 1 >() ),       
                         [SystemCallArgument_3] "r" ( systemCallArgumentsTuple.template Entry< 2 >() )       
                       : "memory", "cc", "%rax", "%rbx", "%rdi", "%rsi", "%rdx" );                          /* Clobbers and scratch registers */

    // Check if the system call succedded, and if not throw an errno exception
    AssertSystemCallWasSuccessful;

    // Return the return value from the system call
    return ( systemCallReturnValue );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 4   ****************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename... SystemCallArgumentTypes >
inline SignedInteger32bits SystemCall< 4UL, SystemCallArgumentTypes... >::Invoke( const SignedInteger32bits systemCallNumber, SystemCallArgumentTypes... systemCallArguments )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid
    Assert( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" );
    Assert( ( sizeof...( systemCallArguments ) == 4UL ), "The system call accepts 4 arguments" );

    // Store the arguments to the system call into a tuple
    const Memory::Tuple< SystemCallArgumentTypes... > systemCallArgumentsTuple( systemCallArguments... );

    // This will be used to store if the system call succeeded ( true ) or not ( false )
    SignedInteger32bits systemCallReturnValue = 0;

    // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
    // to execute. This is not possible using only C++

    __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                                         /* Move the system call number to the RAX register */
                        "MOVQ RDI, %[SystemCallArgument_1];"                                                    /* Move the content of the first argument to the system call into the RDI register */
                        "MOVQ RSI, %[SystemCallArgument_2];"                                                    /* Move the content of the second argument to the system call into the RSI register */
                        "MOVQ RDX, %[SystemCallArgument_3];"                                                    /* Move the content of the third argument to the system call into the RDX register */
                        "MOVQ R10, %[SystemCallArgument_4];"                                                    /* Move the content of the fourth argument to the system call into the R10 register */
                        "SYSCALL;"                                                                              /* Invoke the kernel to execute the call */
                        HandleSystemCallReturnValue                                                       /* Check if the system call failed or not and act accordingly */

                       : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                                /* Output arguments */
                       : [SystemCallNumber] "r0" ( systemCallNumber ),                                          /* Input arguments */
                         [SystemCallArgument_1] "r" ( systemCallArgumentsTuple.template Entry< 0 >() ), 
                         [SystemCallArgument_2] "r" ( systemCallArgumentsTuple.template Entry< 1 >() ),       
                         [SystemCallArgument_3] "r" ( systemCallArgumentsTuple.template Entry< 2 >() ),       
                         [SystemCallArgument_4] "r" ( systemCallArgumentsTuple.template Entry< 3 >() )       
                       : "memory", "cc", "%rax", "%rbx", "%rdi", "%rsi", "%rdx", "%r10" );                      /* Clobbers and scratch registers */

    // Check if the system call succedded, and if not throw an errno exception
    AssertSystemCallWasSuccessful;

    // Return the return value from the system call
    return ( systemCallReturnValue );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 5   ****************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename... SystemCallArgumentTypes >
inline SignedInteger32bits SystemCall< 5UL, SystemCallArgumentTypes... >::Invoke( const SignedInteger32bits systemCallNumber, SystemCallArgumentTypes... systemCallArguments )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid
    Assert( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" );
    Assert( ( sizeof...( systemCallArguments ) == 5UL ), "The system call accepts 5 arguments" );

    // Store the arguments to the system call into a tuple
    const Memory::Tuple< SystemCallArgumentTypes... > systemCallArgumentsTuple( systemCallArguments... );

    // This will be used to store if the system call succeeded ( true ) or not ( false )
    SignedInteger32bits systemCallReturnValue = 0;

    // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
    // to execute. This is not possible using only C++

    __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                                         /* Move the system call number to the RAX register */
                        "MOVQ RDI, %[SystemCallArgument_1];"                                                    /* Move the content of the first argument to the system call into the RDI register */
                        "MOVQ RSI, %[SystemCallArgument_2];"                                                    /* Move the content of the second argument to the system call into the RSI register */
                        "MOVQ RDX, %[SystemCallArgument_3];"                                                    /* Move the content of the third argument to the system call into the RDX register */
                        "MOVQ R10, %[SystemCallArgument_4];"                                                    /* Move the content of the fourth argument to the system call into the R10 register */
                        "MOVQ R8, %[SystemCallArgument_5];"                                                     /* Move the content of the fifth argument to the system call into the R8 register */
                        "SYSCALL;"                                                                              /* Invoke the kernel to execute the call */
                        HandleSystemCallReturnValue                                                       /* Check if the system call failed or not and act accordingly */

                       : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                                /* Output arguments */
                       : [SystemCallNumber] "r0" ( systemCallNumber ),                                          /* Input arguments */
                         [SystemCallArgument_1] "r" ( systemCallArgumentsTuple.template Entry< 0 >() ), 
                         [SystemCallArgument_2] "r" ( systemCallArgumentsTuple.template Entry< 1 >() ),       
                         [SystemCallArgument_3] "r" ( systemCallArgumentsTuple.template Entry< 2 >() ),       
                         [SystemCallArgument_4] "r" ( systemCallArgumentsTuple.template Entry< 3 >() ),       
                         [SystemCallArgument_5] "r" ( systemCallArgumentsTuple.template Entry< 4 >() )       
                       : "memory", "cc", "%rax", "%rbx", "%rdi", "%rsi", "%rdx", "%r10", "%r8" );              /* Clobbers and scratch registers */

    // Check if the system call succedded, and if not throw an errno exception
    AssertSystemCallWasSuccessful;

    // Return the return value from the system call
    return ( systemCallReturnValue );
}



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - Number of system call arguments is 6   ****************************************** //
//                                                                                                                                                                            //
// ************************************************************************************************************************************************************************** //



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



template< typename... SystemCallArgumentTypes >
inline SignedInteger32bits SystemCall< 6UL, SystemCallArgumentTypes... >::Invoke( const SignedInteger32bits systemCallNumber, SystemCallArgumentTypes... systemCallArguments )
{
    // This will be added only in test mode, to ensure that the given data to the method is valid
    Assert( ( systemCallNumber < MaximumSystemCallNumber ), "The given system call number is larger then the number of existing system calls" );
    Assert( ( sizeof...( systemCallArguments ) == 6UL ), "The system call accepts 6 arguments" );

    // Store the arguments to the system call into a tuple
    const Memory::Tuple< SystemCallArgumentTypes... > systemCallArgumentsTuple( systemCallArguments... );

    // This will be used to store if the system call succeeded ( true ) or not ( false )
    SignedInteger32bits systemCallReturnValue = 0;

    // The following is an extended inline assembly statement. It will be used to load the 'RAX' register with the system call number and invoke the kernel
    // to execute. This is not possible using only C++

    __asm__ volatile (  "MOV EAX, %[SystemCallNumber];"                                                         /* Move the system call number to the RAX register */
                        "MOVQ RDI, %[SystemCallArgument_1];"                                                    /* Move the content of the first argument to the system call into the RDI register */
                        "MOVQ RSI, %[SystemCallArgument_2];"                                                    /* Move the content of the second argument to the system call into the RSI register */
                        "MOVQ RDX, %[SystemCallArgument_3];"                                                    /* Move the content of the third argument to the system call into the RDX register */
                        "MOVQ R10, %[SystemCallArgument_4];"                                                    /* Move the content of the fourth argument to the system call into the R10 register */
                        "MOVQ R8, %[SystemCallArgument_5];"                                                     /* Move the content of the fifth argument to the system call into the R8 register */
                        "MOVQ R9, %[SystemCallArgument_6];"                                                     /* Move the content of the sixth argument to the system call into the R9 register */
                        "SYSCALL;"                                                                              /* Invoke the kernel to execute the call */
                        HandleSystemCallReturnValue                                                       /* Check if the system call failed or not and act accordingly */

                       : [SystemCallReturnValue] "+ir" ( systemCallReturnValue )                                /* Output arguments */
                       : [SystemCallNumber] "r0" ( systemCallNumber ),                                          /* Input arguments */
                         [SystemCallArgument_1] "r" ( systemCallArgumentsTuple.template Entry< 0 >() ), 
                         [SystemCallArgument_2] "r" ( systemCallArgumentsTuple.template Entry< 1 >() ),       
                         [SystemCallArgument_3] "r" ( systemCallArgumentsTuple.template Entry< 2 >() ),       
                         [SystemCallArgument_4] "r" ( systemCallArgumentsTuple.template Entry< 3 >() ),       
                         [SystemCallArgument_5] "r" ( systemCallArgumentsTuple.template Entry< 4 >() ),       
                         [SystemCallArgument_6] "r" ( systemCallArgumentsTuple.template Entry< 5 >() )       
                       : "memory", "cc", "%rax", "%rbx", "%rdi", "%rsi", "%rdx", "%r10", "%r8", "%r9" );        /* Clobbers and scratch registers */

    // Check if the system call succedded, and if not throw an errno exception
    AssertSystemCallWasSuccessful;

    // Return the return value from the system call
    return ( systemCallReturnValue );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

    template< UnsignedInteger64bits NumberOfSystemCallArguments COMMA typename... SystemCallArgumentTypes >
    void SystemCall< NumberOfSystemCallArguments COMMA SystemCallArgumentTypes... >::UnitTest()
    {
        // Create a place to store the content from read
        SignedInteger8bits testCharacter_1 = 0;

        // Display to the user to enter a character
        std::cout << "Please enter a character :" << std::endl;

        // Wait for the character
        SystemCall< 3 COMMA UnsignedInteger64bits COMMA const SignedInteger8bits* COMMA UnsignedInteger64bits >::Invoke( 0, 0UL, &testCharacter_1, 1UL );

        // Write to standard output
        SystemCall< 3 COMMA UnsignedInteger64bits COMMA const SignedInteger8bits* COMMA UnsignedInteger64bits >::Invoke( 1, 1UL, "Thank you for the character", 27UL );
    }

)  //  End of debug tool




}  //  Namespace Linux


}  //  Namespace Universe