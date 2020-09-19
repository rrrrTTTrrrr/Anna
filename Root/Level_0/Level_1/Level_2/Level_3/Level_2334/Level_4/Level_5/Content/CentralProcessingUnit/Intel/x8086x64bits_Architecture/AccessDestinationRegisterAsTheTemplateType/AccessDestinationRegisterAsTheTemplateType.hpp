#ifndef  ACCESSDESTINATIONREGISTERASTHETEMPLATETYPE_HPP
#define  ACCESSDESTINATIONREGISTERASTHETEMPLATETYPE_HPP


#include "../../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef SignedInteger8bits, Typedef UnsignedInteger8bits
#include "../../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CreateStringBySurroundWithQuatationMarks_MACRO


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
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


        // The macro should be used to create an object for each register that can be accessed through multiple assembly labels, or in other words can be accessed in
        // different size of the bits. 
        //
        // For example, for the accmulator register, the syntax will look :
        //
        //      CreateAccessForSpecificRegister( SetAccmulatorRegister, MOV, REX, EAX, AX, AL )
        //
        // The preprocessor will create the following object:
        //
        //      template< typename PrimitiveType >
        //      SetAccmulatorRegister
        //
        // Each primitive type supported will have its own template specialization.
        //
        // It is basically used to create different objects, by switching the text in the required locations!
        //
        // The comments inside are C style. This is the only way to create multi line macro
        //
        #define CreateObjectWithTheGivenAssemblyInstructionAndDestinationRegisterForEachPrimitiveType( ObjectName, AssemblyInstruction, Register64bitAssemblyLabel, Register32bitAssemblyLabel, Register16bitAssemblyLabel, Register8bitAssemblyLabel ) \
\
\
            /* Template Class Information : \
\
        	 Purpose : \
7\
                 Use this object to set the specific part of the register 8,16,32,64 bits, to the given value. \
\
        			There are a set of registers that can be approched with different assembly lablels. For example : \
\
                     The accmulator register in the intel 64 bit architecture can be approched \
                     in 4 different ways  : \
\
                                 REX  ->   64 bits \
\
                                 EAX  ->   32 lower signficanct bits \
\
                                 AX   ->   16 lower signficanct bits \
\
                                 AL   ->   8 lower signficanct bits \
\
                 When using templates and inline assembly, the template can only help in changing the type in the object at the required places. The problem this object \
                 is trying to solve is to allow matching the required size of bytes with the right assembly label for that part of the register. Then for the following \
                 example, the matching types for the registers are : \
\
                                 REX  ->   char, unsigned char \
\
                                 EAX  ->   short, unsigned short \
\
                                 AX   ->   int, unsigned int \
\
                                 AL   ->   long, unsigned long \
\
                 The types "double" and "float" are not yet supported! \
\
                 List of registers that can be addresses this way are : \
\
\
                                                             64 bit register    Lower 32 bits      Lower 16 bits      Lower 8 bits \
\
                     1. Accmulator register                        RAX              EAX                AX                 AL \
                     2. Base register                              RBX              EBX                BX                 BL \
        	         3. Counter register                           RCX              ECX                CX                 CL \
                     4. Data register                              RDX              EDX                DX                 DL \
                     5. Source index register                      RSI              ESI                SI                 SIL \
                     6. Detination index register                  RDI              EDI                DI                 DIL \
                     7. Stack base pointer register                RBP              EBP                BP                 BPL \
                     8. Stack pointer register                     RSP              ESP                SP                 SPL \
                     9. General purpose register 8                 R8               R8D                R8W                R8B \
                     10. General purpose register 9                R9               R9D                R9W                R9B \
                     11. General purpose register 10               R10              R10D               R10W               R10B \
                     12. General purpose register 11               R11              R11D               R11W               R11B \
                     13. General purpose register 12               R12              R12D               R12W               R12B \
                     14. General purpose register 13               R13              R13D               R13W               R13B \
                     15. General purpose register 14               R14              R14D               R14W               R14B \
                     16. General purpose register 15               R15              R15D               R15W               R15B \
\
\
        	 Description : \
\
                 1. This will act as the base object. Each primitive type supported will have its own template specialization. When an unsupported type will be used \
                    the compiler will choose this base object, which has no implementation, and a compile error will be raised \
\        	
        		 2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords : \
\        	
        					1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools \
        								presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is \
        								lost, so it should be avoided in most cases \
\        	
        					2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access \
        								   all the data and methods inside this part. This part will usually containt some methods and few data members \
\        	
        					3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the \
        								 methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the \
        								 suffix _IMP \
\        	
        	 Expectations : \
\        	
        			NONE \
\        	
        	 Possible errors : \
\        	
        			Too many to count */ \
\
        	template< typename PrimitiveType > \
        	class ObjectName NotForInheritance \
        	{ \
        	public: \
\
\
                /* There is only 1 method in this object, it is a parameterized consructor, which has a default value, and therefore acts also as the default constructor. \
                 The constructor will be used to set the register to the given value : \
\
\
                 Method Information : \
\               
                      Description : \
\
                      Constructor, a default value is given, this allows this constructor to act also as the default one \
\
                  Required arguments : \
\
                      User information needed : \
\
                          value - this will be used to set the required part of the register \
\
                      Information returned to the user : \
\
                          NONE \
\
                  Return value : \
\
                      NONE \
\
                  Expectations : \
\
                      NONE \
\
                  Possible errors : \
\
                      They will come */ \
\
                explicit inline ObjectName( PrimitiveType value = 0 ); \
\
\
        		DEBUG_TOOL( \
\
        			/* This part of the object is dedicated for testing : */ \
\
\
        			/* Method Information : \
\
        			  Description : \
\
        			      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code \
\
        			  Required arguments : \
\
        			      User information needed : \
\
        			          NONE \
\
        			      Information returned to the user : \
\
        			          NONE \
\
        			  Return value : \
\
        						NONE \
\
        			  Expectations : \
\
    			    		Please let the test pass lord!! \
\
    			      Possible errors : \
\
        					It says there are no problems, which is even scarier, did I just wrote a working code?? */ \
\
        			static void Test(); \
\
        		)    /* End of debug tool */ \
\
\
        	};  /*  Class ObjectName  */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/* ************************************************************************************************************************************************************************** */ \
\
/* ******************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - SignedInteger8bits   *************************************************** */ \
\
/* ************************************************************************************************************************************************************************** */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
            /* Template Class Specialization Information : \
\
              Purpose : \
\
                  This is template specialization for the primitive type 'char', or signed integer 8 bits \
\
              Description : \
\
\
                   Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords : \
\
                          1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools \
                                      presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is \
                                      lost, so it should be avoided in most cases \
\
                          2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access \
                                         all the data and methods inside this part. This part will usually containt some methods and few data members \
\
                          3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the \
                                       methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the \
                                       suffix _IMP \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  Too many to count */ \
\
            template<> \
            class ObjectName< SignedInteger8bits > NotForInheritance \
            { \
            public: \
\
\
                 /* There is only 1 method in this object, it is a parameterized consructor, which has a default value, and therefore acts also as the default constructor. \
                 The constructor will be used to set the register to the given value : \
\
\
                 Method Information : \
\
                  Description : \
\
                      Constructor, a default value is given, this allows this constructor to act also as the default one \
\
                  Required arguments : \
\
                      User information needed : \
\
                          value - this will be used to set the required part of the register \
\
                      Information returned to the user : \
\
                          NONE \
\
                  Return value : \
\
                      NONE \
\
                  Expectations : \
\
                      NONE \
\
                  Possible errors : \
\
                      They will come */ \
\
                explicit inline ObjectName( SignedInteger8bits value = 0 ); \
\
\
            };    /*  Class ObjectName  */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/*	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   ******************************************************* */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
            /* Method Information : \
\
                    Description : \
\
                        Constructor, a default value is given, this allows this constructor to act also as the default one \
\
                    Required arguments : \
\
                        User information needed : \
\
                            value - this will be used to set the required part of the register \
\
                      Information returned to the user : \
\
                          NONE \
\
                  Return value : \
\
                      NONE \
\
                  Expectations : \
\
                      NONE \
\
                  Possible errors : \
\
                      They will come */ \
\
            inline ObjectName< SignedInteger8bits >::ObjectName( SignedInteger8bits value ) \
            { \
                 /* Set the lower 8 bits of the register to given value */ \
                __asm__ volatile ( CreateStringBySurroundWithQuatationMarks_MACRO( AssemblyInstruction Register8bitAssemblyLabel, %[value]\n\t )      /* Assembly code */ \
                                   :                                                                                                                  /* Output arguments */ \
                                   : [value] "ir" ( value )                                                                                           /* Input arguments */ \
                                   : "memory", "cc" );                                                                                                /* Clobbers and scratch registers */ \
            } \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/* ************************************************************************************************************************************************************************** */ \
\
/* *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - UnsignedInteger8bits   ************************************************** */ \
\
/* ************************************************************************************************************************************************************************** */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
             /* Template Class Specialization Information : \
\
              Purpose : \
\
                  This is template specialization for the primitive type 'unsigned char', or unsigned integer 8 bits \
\
              Description : \
\
\
                   Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords : \
\
                          1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools \
                                      presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is \
                                      lost, so it should be avoided in most cases \
\
                          2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access \
                                         all the data and methods inside this part. This part will usually containt some methods and few data members \
\
                          3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the \
                                       methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the \
                                       suffix _IMP \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  Too many to count */ \
\
            template<> \
            class ObjectName< UnsignedInteger8bits > NotForInheritance \
            { \
            public: \
\
\
                 /* There is only 1 method in this object, it is a parameterized consructor, which has a default value, and therefore acts also as the default constructor. \
                 The constructor will be used to set the register to the given value : */ \
\
\
                 /* Method Information : \
\
                  Description : \
\
                      Constructor, a default value is given, this allows this constructor to act also as the default one \
\
                  Required arguments : \
\
                      User information needed : \
\
                          value - this will be used to set the required part of the register \
\
                      Information returned to the user : \
\
                          NONE
\
                  Return value : \
\
                      NONE \  
\
                  Expectations : \
\
                      NONE \
\
                  Possible errors : \
\
                      They will come */ \
\
                explicit inline ObjectName( UnsignedInteger8bits value = 0 ); \
\
\
            };    /*  Class ObjectName  */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/*  *******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   ******************************************************* */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
             /* Method Information : \
\
              Description : \
\
                  Constructor, a default value is given, this allows this constructor to act also as the default one \
\
              Required arguments : \
\
                  User information needed : \
\
                      value - this will be used to set the required part of the register \
\
                  Information returned to the user : \
\
                      NONE \
\
              Return value : \
\
                  NONE \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  They will come */ \
\
            inline ObjectName< UnsignedInteger8bits >::ObjectName( UnsignedInteger8bits value ) \
            { \
                 /* Set the lower 8 bits of the register to given value */ \
                __asm__ volatile ( CreateStringBySurroundWithQuatationMarks_MACRO( AssemblyInstruction Register8bitAssemblyLabel, %[value]\n\t )    /* Assembly code */ \
                                   :                                                                                                                  /* Output arguments */ \
                                   : [value] "ir" ( value )                                                                                           /* Input arguments */ \
                                   : "memory", "cc" );                                                                                                /* Clobbers and scratch registers */ \
            } \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/* ************************************************************************************************************************************************************************** */ \
\
/* *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - SignedInteger16bits   *************************************************** */ \
\
/* ************************************************************************************************************************************************************************** */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
             /* Template Class Specialization Information : \
\
              Purpose : \
\
                  This is template specialization for the primitive type 'short', or signed integer 16 bits \
\
              Description : \
\
\
                   Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords : \
\
                          1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools \                                     presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
                                      lost, so it should be avoided in most cases \
\
                          2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access \
                                         all the data and methods inside this part. This part will usually containt some methods and few data members \
\
                          3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the \
                                       methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the \
                                       suffix _IMP \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  Too many to count */ \
\
            template<> \
            class ObjectName< SignedInteger16bits > NotForInheritance \
            { \
            public: \
\
\
                 /* There is only 1 method in this object, it is a parameterized consructor, which has a default value, and therefore acts also as the default constructor. \
                 The constructor will be used to set the register to the given value : */ \
\
\
                 /* Method Information : \
\
                  Description : \
\
                      Constructor, a default value is given, this allows this constructor to act also as the default one \
\
                  Required arguments : \
\
                      User information needed : \
\
                          value - this will be used to set the required part of the register \
\
                      Information returned to the user : \
\
                          NONE \
\
                  Return value : \
\
                      NONE \
\
                  Expectations : \
\
                      NONE \
\
                  Possible errors : \
\
                      They will come */ \
\
                explicit inline ObjectName( SignedInteger16bits value = 0 ); \
\
\
            };    /*  Class ObjectName */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/*  *******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   ******************************************************* */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
             /* Method Information : \
\
              Description : \
\
                  Constructor, a default value is given, this allows this constructor to act also as the default one \
\
              Required arguments : \
\
                  User information needed : \
\
                      value - this will be used to set the required part of the register \
\
                  Information returned to the user : \
\
                      NONE \
\
              Return value : \
\
                  NONE \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  They will come */ \
\
            inline ObjectName< SignedInteger16bits >::ObjectName( SignedInteger16bits value ) \
            { \
                 /* Set the lower 16 bits of the register to given value */ \
                __asm__ volatile ( CreateStringBySurroundWithQuatationMarks_MACRO( AssemblyInstruction Register16bitAssemblyLabel, %[value]\n\t )    /* Assembly code */ \
                                   :                                                                                                                   /* Output arguments */ \
                                   : [value] "ir" ( value )                                                                                            /* Input arguments */ \
                                   : "memory", "cc" );                                                                                                 /* Clobbers and scratch registers */ \
            } \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/* ************************************************************************************************************************************************************************** */ \
\
/* *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - UnsignedInteger16bits   ************************************************* */ \
\
/* ************************************************************************************************************************************************************************** */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
            /* Template Class Specialization Information : \
\
              Purpose : \
\
                  This is template specialization for the primitive type 'unsigned short', or unsigned integer 16 bits \
\
              Description : \
\
\
                   Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords : \
\
                          1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools \                                     presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
                                      lost, so it should be avoided in most cases \
\
                          2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access \
                                         all the data and methods inside this part. This part will usually containt some methods and few data members \
\
                          3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the \
                                       methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the \
                                       suffix _IMP \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  Too many to count */ \
\
            template<> \
            class ObjectName< UnsignedInteger16bits > NotForInheritance \
            { \
            public: \
\
\
                 /* There is only 1 method in this object, it is a parameterized consructor, which has a default value, and therefore acts also as the default constructor. \
                 The constructor will be used to set the register to the given value : \
\
\
                 Method Information : \
\
                  Description : \
\
                      Constructor, a default value is given, this allows this constructor to act also as the default one \
\
                  Required arguments : \
\
                      User information needed : \
\
                          value - this will be used to set the required part of the register \ 
\
                      Information returned to the user : \
\
                          NONE \
\
                  Return value : \
\
                      NONE \
\
                  Expectations : \
\
                      NONE \
\
                  Possible errors : \
\
                      They will come */ \
\
                explicit inline ObjectName( UnsignedInteger16bits value = 0 ); \
\
\
            };    /*  Class ObjectName */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/*  *******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   ******************************************************* */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
            /* Method Information : \
\
              Description : \
\
                  Constructor, a default value is given, this allows this constructor to act also as the default one \
\
              Required arguments : \
\
                  User information needed : \
\
                      value - this will be used to set the required part of the register \
\
                  Information returned to the user : \
\
                      NONE \
\
              Return value : \
\
                  NONE \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  They will come */ \
\
            inline ObjectName< UnsignedInteger16bits >::ObjectName( UnsignedInteger16bits value ) \
            { \
                 /* Set the lower 16 bits of the register to given value */ \
                __asm__ volatile ( CreateStringBySurroundWithQuatationMarks_MACRO( AssemblyInstruction Register16bitAssemblyLabel, %[value]\n\t )    /* Assembly code */ \
                                   :                                                                                                                   /* Output arguments */ \
                                   : [value] "ir" ( value )                                                                                            /* Input arguments */ \
                                   : "memory", "cc" );                                                                                                 /* Clobbers and scratch registers */ \
            } \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/* ************************************************************************************************************************************************************************** */ \
\
/* *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - SignedInteger32bits   *************************************************** */ \
\
/* ************************************************************************************************************************************************************************** */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
            /* Template Class Specialization Information : \
\
              Purpose : \
\
                  This is template specialization for the primitive type 'int', or signed integer 32 bits \
\
              Description : \
\
\
                   Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords : \
\
                          1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools \                                     presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
                                      lost, so it should be avoided in most cases \
\
                          2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access \
                                         all the data and methods inside this part. This part will usually containt some methods and few data members \
\
                          3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the \
                                       methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the \
                                       suffix _IMP
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  Too many to count */ \
\
            template<> \
            class ObjectName< SignedInteger32bits > NotForInheritance \
            { \
            public: \
\
\
                 /* There is only 1 method in this object, it is a parameterized consructor, which has a default value, and therefore acts also as the default constructor. \
                 The constructor will be used to set the register to the given value : */ \
\
\
                 /* Method Information : \
\
                  Description : \
\
                      Constructor, a default value is given, this allows this constructor to act also as the default one \
\
                  Required arguments : \
\
                      User information needed : \
\
                          value - this will be used to set the required part of the register \
\
                      Information returned to the user : \
\
                          NONE \
\
                  Return value : \
\
                      NONE \
\
                  Expectations : \
\
                      NONE \
\
                  Possible errors : \
\
                      They will come */ \
\
                explicit inline ObjectName( SignedInteger32bits value = 0 ); \
\
\
            };    /*  Class ObjectName */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/*  *******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   ******************************************************* */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
            /* Method Information : \
\
              Description : \
\
                  Constructor, a default value is given, this allows this constructor to act also as the default one \
\
              Required arguments : \
\
                  User information needed : \
\
                      value - this will be used to set the required part of the register \
\
                  Information returned to the user : \
\
                      NONE \
\
              Return value : \
\
                  NONE \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  They will come */ \
\
            inline ObjectName< SignedInteger32bits >::ObjectName( SignedInteger32bits value ) \
            { \
                 /* Set the lower 32 bits of the register to given value */ \
                __asm__ volatile ( CreateStringBySurroundWithQuatationMarks_MACRO( AssemblyInstruction Register32bitAssemblyLabel, %[value]\n\t )    /* Assembly code */ \
                                   :                                                                                                                   /* Output arguments */ \
                                   : [value] "ir" ( value )                                                                                            /* Input arguments */ \
                                   : "memory", "cc" );                                                                                                 /* Clobbers and scratch registers */ \
            } \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/* ************************************************************************************************************************************************************************** */ \
\
/* *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - UnsignedInteger32bits   ************************************************* */ \
\
/* ************************************************************************************************************************************************************************** */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
             /* Template Class Specialization Information : \
\
              Purpose : \
\
                  This is template specialization for the primitive type 'unsigned int', or unsigned integer 32 bits
\
              Description : \
\
\
                   Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords : \
\
                          1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools \                                     presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
                                      lost, so it should be avoided in most cases \
\
                          2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access \
                                         all the data and methods inside this part. This part will usually containt some methods and few data members \
\
                          3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the \
                                       methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the \
                                       suffix _IMP \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  Too many to count */ \
\
            template<> \
            class ObjectName< UnsignedInteger32bits > NotForInheritance \
            { \
            public: \
\
\
                /* There is only 1 method in this object, it is a parameterized consructor, which has a default value, and therefore acts also as the default constructor. \
                 The constructor will be used to set the register to the given value : */ \
\
\
                 /* Method Information : \
\
                  Description : \
\
                      Constructor, a default value is given, this allows this constructor to act also as the default one \
\
                  Required arguments : \
\
                      User information needed : \
\
                          value - this will be used to set the required part of the register \
\
                      Information returned to the user : \
\
                          NONE \
\
                  Return value : \
\
                      NONE \
\
                  Expectations : \
\
                      NONE \
\
                  Possible errors : \
\
                      They will come */ \
\
                explicit inline ObjectName( UnsignedInteger32bits value = 0 ); \
\
\
            };    /*  Class ObjectName */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/*  *******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   ******************************************************* */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
            /* Method Information : \
\
              Description : \
\
                  Constructor, a default value is given, this allows this constructor to act also as the default one \
\
              Required arguments : \
\
                  User information needed : \
\
                      value - this will be used to set the required part of the register \
\
                  Information returned to the user : \
\
                      NONE \
\
              Return value : \
\
                  NONE \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  They will come */ \
\
            inline ObjectName< UnsignedInteger32bits >::ObjectName( UnsignedInteger32bits value ) \
            { \
                 /* Set the lower 32 bits of the register to given value */ \
                __asm__ volatile ( CreateStringBySurroundWithQuatationMarks_MACRO( AssemblyInstruction Register32bitAssemblyLabel, %[value]\n\t )    /* Assembly code */ \
                                   :                                                                                                                   /* Output arguments */ \
                                   : [value] "ir" ( value )                                                                                            /* Input arguments */ \
                                   : "memory", "cc" );                                                                                                 /* Clobbers and scratch registers */ \
            } \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/* ************************************************************************************************************************************************************************** */ \
\
/* *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - SignedInteger64bits   *************************************************** */ \
\
/* ************************************************************************************************************************************************************************** */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
            /* Template Class Specialization Information : \
\
              Purpose : \
\
                  This is template specialization for the primitive type 'long', or signed integer 64 bits
\
              Description : \
\
\
                   Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords : \
\
                          1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools \                                     presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
                                      lost, so it should be avoided in most cases \
\
                          2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access \
                                         all the data and methods inside this part. This part will usually containt some methods and few data members \
\
                          3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the \
                                       methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the \
                                       suffix _IMP \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  Too many to count */ \
\
            template<> \
            class ObjectName< SignedInteger64bits > NotForInheritance \
            { \
            public: \
\
\
                /* There is only 1 method in this object, it is a parameterized consructor, which has a default value, and therefore acts also as the default constructor. \
                 The constructor will be used to set the register to the given value : */ \
\
\
                /* Method Information : \
\
                  Description : \
\
                      Constructor, a default value is given, this allows this constructor to act also as the default one \
\
                  Required arguments : \
\
                      User information needed : \
\
                          value - this will be used to set the required part of the register \
\
                      Information returned to the user : \
\
                          NONE \
\
                  Return value : \
\
                      NONE \
\
                  Expectations : \
\
                      NONE \
\
                  Possible errors : \
\
                      They will come */ \
\
                explicit inline ObjectName( SignedInteger64bits value = 0 ); \
\
\
            };    /*  Class ObjectName */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/*  *******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   ******************************************************* */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
            /* Method Information : \
\
              Description : \
\
                  Constructor, a default value is given, this allows this constructor to act also as the default one \
\
              Required arguments : \
\
                  User information needed : \
\
                      value - this will be used to set the required part of the register \
\
                  Information returned to the user : \
\
                      NONE \
\
              Return value : \
\
                  NONE \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  They will come */ \
\
            inline ObjectName< SignedInteger64bits >::ObjectName( SignedInteger64bits value ) \
            { \
                 /* Set the lower 64 bits of the register to given value */ \
                __asm__ volatile ( CreateStringBySurroundWithQuatationMarks_MACRO( AssemblyInstruction Register64bitAssemblyLabel, %[value]\n\t )    /* Assembly code */ \
                                   :                                                                                                                   /* Output arguments */ \
                                   : [value] "ir" ( value )                                                                                            /* Input arguments */ \
                                   : "memory", "cc" );                                                                                                 /* Clobbers and scratch registers */ \
            } \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/* ************************************************************************************************************************************************************************** */ \
\
/* *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - UnsignedInteger64bits   ************************************************* */ \
\
/* ************************************************************************************************************************************************************************** */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
            /* Template Class Specialization Information : \
\
              Purpose : \
\
                  This is template specialization for the primitive type 'unsigned long', or unsigned integer 64 bits \
\
              Description : \
\
\
                   Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by providing 3 keywords : \
\                   
                          1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the obejct using the tools \                                     presented here. This part will usually contain only methods and not data members. If a data member is public all the encapsulation is
                                      lost, so it should be avoided in most cases \
\
                          2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will be able to access \
                                         all the data and methods inside this part. This part will usually containt some methods and few data members \
\
                          3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object and all the \
                                       methods the developer needed to implement the interface presented in the public part. Every method in this part will end with the \
                                       suffix _IMP \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  Too many to count */ \
\
            template<> \
            class ObjectName< UnsignedInteger64bits > NotForInheritance \
            { \
            public: \
\
\
                 /* There is only 1 method in this object, it is a parameterized consructor, which has a default value, and therefore acts also as the default constructor. \
                 The constructor will be used to set the register to the given value : */ \
\
\
                 /* Method Information : \
\
                  Description : \
\
                      Constructor, a default value is given, this allows this constructor to act also as the default one \
\
                  Required arguments : \
\
                      User information needed : \
\
                          value - this will be used to set the required part of the register \
\
                      Information returned to the user : \
\
                          NONE \
\
                  Return value : \
\
                      NONE \
\
                  Expectations : \
\
                      NONE \
\
                  Possible errors : \
\
                      They will come */ \
\
                explicit inline ObjectName( UnsignedInteger64bits value = 0 ); \
\
\
            };    /*  Class ObjectName */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/*  *******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   ******************************************************* */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
            /* Method Information : \
\
              Description : \
\
                  Constructor, a default value is given, this allows this constructor to act also as the default one \
\
              Required arguments : \
\
                  User information needed : \
\
                      value - this will be used to set the required part of the register \
\
                  Information returned to the user : \
\
                      NONE \
\
              Return value : \
\
                  NONE \
\
              Expectations : \
\
                  NONE \
\
              Possible errors : \
\
                  They will come */ \
\
            inline ObjectName< UnsignedInteger64bits >::ObjectName( UnsignedInteger64bits value ) \
            { \
                /* Set the lower 64 bits of the register to given value */ \
                __asm__ volatile ( CreateStringBySurroundWithQuatationMarks_MACRO( AssemblyInstruction Register64bitAssemblyLabel, %[value]\n\t )    /* Assembly code */ \
                                   :                                                                                                                   /* Output arguments */ \
                                   : [value] "ir" ( value )                                                                                            /* Input arguments */ \
                                   : "memory", "cc" );                                                                                                 /* Clobbers and scratch registers */ \
            } \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
/* *********************************************************************************   TESTING   ******************************************************************************** */ \
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
\
        	DEBUG_TOOL( \
\
        		/* Method Information : \
\
        		  Description : \
\
        		      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement \
        			  the functionality \
\
        		  Required arguments : \
\
        		      User information needed : \
\
        		          NONE \
\
        		      Information returned to the user : \
\
        		          NONE \
\
        		  Return value : \
\
        		      1. true - if the object passed the test \
        		      2. false - otherwise \
\
        		  Expectations : \
\
        				NONE \
\
        		  Possible errors : \
\
        		        1. A method does not work correctly - class Exception is thrown \
        				2. There is no more free memory space - class std::bad_alloc is thrown \
        				3. */ \
\
        		template< typename PrimitiveType > \
        		void ObjectName< PrimitiveType >::Test() \
        		{ \
        			long y = 9; \
\
        			SetAccmulatorRegister< SignedInteger64bits >( -999 ); \
\
        			__asm__ volatile ( "MOV %[y], RAX\n\t" \
        								: [y] "=ir" ( y ) \
        								: \
        								: "memory" ); \
\
        			std::cout << y << std::endl; \
        		} \
\
        	)    /* End of debug tool */



    	// Template Class Information :
    	//
    	//  Purpose :
    	//
    	//		This macro will be used to create the an object that can set the specific register according to the template type. It will perform the MOV 
		// 		Instruction, where the register part will be the destination and the immediate value will be the source
		//
		//		The create object will have the name :
		//
		//				SetAccmulatorRegister
    	//
    	//  Description :
    	//
    	//		NONE 
    	//
    	//	Expectations :
    	//
    	//		NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
		CreateObjectWithTheGivenAssemblyInstructionAndDestinationRegisterForEachPrimitiveType( SetAccmulatorRegister, MOV, RAX, EAX, AX, AL )












    }  //  Namespace CentralProcessingUnit

}  //  Namespace Universe



#endif  // ACCESSDESTINATIONREGISTERASTHETEMPLATETYPE_HPP