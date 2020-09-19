#include <iostream>	

#define CreateStringBySurroundWithQuatationMarks_MACRO( ... ) #__VA_ARGS__


#define AbsoluteValue( RegisterLabelWithSignedInteger_AfterTheCallWillContainTheResultAbsolutevalue, RegisterLabelToUseForTheComputation ) 	CreateStringBySurroundWithQuatationMarks_MACRO( CMP RegisterLabelWithSignedInteger_AfterTheCallWillContainTheResultAbsolutevalue, 0; )\
																																			CreateStringBySurroundWithQuatationMarks_MACRO( JGE POSITIVE%=; )  \
																																			CreateStringBySurroundWithQuatationMarks_MACRO( MOV RegisterLabelToUseForTheComputation, RegisterLabelWithSignedInteger_AfterTheCallWillContainTheResultAbsolutevalue; )			\
																																			CreateStringBySurroundWithQuatationMarks_MACRO( SAR RegisterLabelToUseForTheComputation, 31; )																						\
																																			CreateStringBySurroundWithQuatationMarks_MACRO( XOR RegisterLabelWithSignedInteger_AfterTheCallWillContainTheResultAbsolutevalue, RegisterLabelToUseForTheComputation; )			\
																																			CreateStringBySurroundWithQuatationMarks_MACRO( ADD RegisterLabelWithSignedInteger_AfterTheCallWillContainTheResultAbsolutevalue, 1; )											\
																																			"POSITIVE%=:;"






int AbsoluteValue33( int value )
{
	 __asm__ volatile (  AbsoluteValue( %[Value], EBX )

	                    : [Value] "+ir" ( value )
	                    : "ir0" ( value )
	                    : "memory", "cc", "%eax", "%ebx" ); 

	return ( value );

}


int main()
{


	std::cout << AbsoluteValue33( -567 ) << std::endl;



	int ll = 98;

	 __asm__ volatile (  "CMP rax, 0x45600000;"
						 "JA SystemCallFailure%=;"
						 "MOV %[Value], 888;"
						 "SystemCallFailure%=:;"
	                    : [Value] "+ir" ( ll )
	                    : "ir0" ( ll )
	                    : "memory", "cc", "%eax", "%ebx" ); 

	std::cout << ll << std::endl;

}