#include <iostream>

void Test_1()
{
	long y = 0;
	long yy = 0;

	__asm__ ( "MOV QWORD PTR [ rbp - 16 ], 20\n\t" );

	std::cout << y << std::endl;

	__asm__ ( "MOV QWORD PTR [ rbp - 16 ], 45\n\t" );

	std::cout << y << std::endl;

	__asm__ ( "MOV rbx, QWORD PTR [ rbp - 16 ]\n\t"
			  "MOV QWORD PTR [ rbp - 8 ], rbx\n\t" );

	std::cout << yy << std::endl;

	__asm__ ( "LOCK\n\t" 
		      "INC QWORD PTR [ rbp - 8 ]\n\t" );

	std::cout << yy << std::endl;

	std::cout << std::endl << std::endl;
}

void Test_2()
{
	int index = 0;

	__asm__ ( "MOV RCX, 10\n\t"
			  "raff:\n\t"
			  "INC DWORD PTR [ rbp - 4 ]\n\t"
			  "LOOP raff\n\t" );

	std::cout << index << std::endl;

	std::cout << std::endl << std::endl;
}

void Test_3()
{
	long registerValue = 0;

	__asm__ ( "MOV RCX, 10\n\t"
			  "MOV QWORD PTR [ rbp - 8 ], RCX\n\t" );

	std::cout << registerValue << std::endl;

	std::cout << std::endl << std::endl;
}

void Test_4()
{
	long registerValue = 0;

	__asm__ ( "MOV RCX, 99\n\t"
			  "PUSH RCX\n\t"
			  "XOR RAX, RAX\n\t"
			  "POP RAX\n\t"
			  "MOV QWORD PTR [ rbp - 8 ], RAX\n\t" );

	std::cout << registerValue << std::endl;

	std::cout << std::endl << std::endl;
}

void Test_5()
{
	int registerValue = 0;

	__asm__ ( "SUB RSP, 4\n\t"
			  "MOV DWORD PTR [ rbp - 8 ], 88\n\t"
			  "MOV EAX, DWORD PTR [ rbp - 8 ]\n\t"
			  "MOV DWORD PTR [ rbp - 4 ], EAX\n\t"
			  "ADD RSP, 4\n\t" );

	std::cout << registerValue << std::endl;

	std::cout << std::endl << std::endl;
}

void Test_6()
{
	long registerValue = 211111;

	long test = 0;
	long test1 = 0;

	__asm__ ( "MOV RAX, [ RBP - 24 ]\n\t"
			  "MOV [ RBP - 16 ], RAX\n\t" );

	std::cout << test << std::endl;
	++registerValue;


	__asm__ ( "MOV RAX, 26\n\t"
			  "PUSH RAX\n\t"
			  "MOV RBX, [ RBP - 32 ]\n\t"
			  "MOV [ RBP - 8 ], RBX\n\t" );

	std::cout << test1 << std::endl;
	std::cout << registerValue << std::endl;

	std::cout << std::endl << std::endl;
}

void Test_7()
{
	// __asm__ ( "MOV RAX, 26\n\t"
	// 	  "PUSH RAX\n\t"
	// 	  "MOV RBX, [ RBP - 32 ]\n\t"
	// 	  __asm__ ( "MOV [ RBP - 8 ], RBX\n\t" ); );

	// __asm__ can not be embedded into one another!!
}

void Test_8()
{
	// int localVariable = 0;

	// int localVariableOffset = 0;

	// long BaseAddress = 0;

	// long* ggg_BaseAddress = &BaseAddress;

	// int* ggg_localVariableOffset = &localVariableOffset;

	// int* ggg_localVariable = &localVariable;

	unsigned long RBP = 0;

	__asm__ ( "MOV [ RBP - 8 ], RBP\n\t" );

	// std::cout << localVariable << std::endl;
	// std::cout << ggg_localVariable << std::endl << std::endl;
	// ++RBP;
	// --RBP;
	// std::cout << localVariableOffset << std::endl;
	// std::cout << ggg_localVariableOffset << std::endl << std::endl;

	// std::cout << BaseAddress << std::endl;
	// std::cout << ggg_BaseAddress << std::endl << std::endl;

	// unsigned long offset = RBP - (unsigned long)&localVariable;

	std::cout << RBP << std::endl;
	// std::cout << offset << std::endl;

}




void Test_10()
{
	unsigned short first = 1;

	__asm__ ( "BT WORD PTR [ RBP - 2 ], 2\n\t"
			  "JC DAVID\n\t"
		  	  "DUDI :\n\t"
		  	  "MOV WORD PTR [ RBP - 2 ], 666\n\t"
		  	  "JMP FINISH\n\t"
		  	  "DAVID :\n\t"
		  	  "MOV WORD PTR [ RBP - 2 ], 777\n\t"
		  	  "FINISH :\n\t" );

	std::cout << first << std::endl;
}


void Test_11() 
{
	unsigned short first = 1;

	__asm__ ( "BT WORD PTR [ RBP - 2 ], 3\n\t"
			  "JC DAVID1\n\t"
		  	  "DUDI1 :\n\t"
		  	  "MOV WORD PTR [ RBP - 2 ], 666\n\t"
		  	  "DAVID1 :\n\t"
		  	  "MOV WORD PTR [ RBP - 2 ], 777\n\t"
		  	  "FINISH1 :\n\t" );

	std::cout << first << std::endl;
}

unsigned short Test_12() 
{

	__asm__ ( "SUB RSP, 2\n\t"
			  "BT WORD PTR [ RBP - 2 ], 2\n\t"
			  "JC DAVID3\n\t"
		  	  "DUDI4 :\n\t"
		  	  "MOV WORD PTR [ RBP - 2 ], 666\n\t"
		  	  "JMP FINISH3\n\t"
		  	  "DAVID3 :\n\t"
		  	  "MOV WORD PTR [ RBP - 2 ], 777\n\t"
		  	  "FINISH3 :\n\t" );

	return ( 8 );
}

    #define CreatePointerToRegisterAccordingToTheSize_REX( SizeInBytes ) switch ( SizeInBytes )\
    																	 {\
\
																		 	case 1 :\
																		 		register UnsignedInteger8bits* pointerToRegister __asm__ ( "AL" );\
																		 		break;\
\
																		 	case 2 :\
																		 		register UnsignedInteger8bits* pointerToRegister __asm__ ( "AX" );\
																		 		break;\
\
																		 	case 4 :\
																		 		register UnsignedInteger8bits* pointerToRegister __asm__ ( "EAX" );\
																		 		break;\
\
																		 	default :\ // SizeInBytes = 8
																		 		register UnsignedInteger8bits* pointerToRegister __asm__ ( "REX" );\
\
    																	 }

// It's a flag, it can only hold true or false (technically 1 or 0, but effectively the truth values as shown).

// In terms of using it, no, you don't compare it to something and then use jg. It's at the same level of abstraction as other flags so you can just use:

// jc somewhere         ; jump if carry flag is set
// jnc somewhere_else   ; jump if carry flag is not set
// It's set automatically by certain instructions so, for example, to add two values and detect carry, you can use something like:

// add ax,bx
// jc  too_big
// And, while it's mostly set by those instructions, you can also do it manually with stc (set), clc (clear) and cmc (complement). For example, it's
//  often useful to clear it before-hand if you're entering a loop where the value is carried forward to the next iteration.

int main()
{

	Test_1();
	Test_2();
	Test_3();
	Test_4();
	Test_5();
	Test_6();
	Test_7();
	Test_8();
	Test_10();
	Test_11();
	Test_12();


	return ( 0 );
}