namespace Universe
{


namespace CentralProcessingUnit
{



// Create all the tuples with the named data members for the different divison functions for each integer type
//
CreateTupleWithTwoNamedDataMembers( DivisonResultSignedInteger8bits, SignedInteger8bits, Quotient, SignedInteger8bits, Remainder )
CreateTupleWithTwoNamedDataMembers( DivisonResultSignedInteger16bits, SignedInteger16bits, Quotient, SignedInteger16bits, Remainder )
CreateTupleWithTwoNamedDataMembers( DivisonResultSignedInteger32bits, SignedInteger32bits, Quotient, SignedInteger32bits, Remainder )
CreateTupleWithTwoNamedDataMembers( DivisonResultSignedInteger64bits, SignedInteger64bits, Quotient, SignedInteger64bits, Remainder )

CreateTupleWithTwoNamedDataMembers( DivisonResultUnsignedInteger8bits, UnsignedInteger8bits, Quotient, UnsignedInteger8bits, Remainder )
CreateTupleWithTwoNamedDataMembers( DivisonResultUnsignedInteger16bits, UnsignedInteger16bits, Quotient, UnsignedInteger16bits, Remainder )
CreateTupleWithTwoNamedDataMembers( DivisonResultUnsignedInteger32bits, UnsignedInteger32bits, Quotient, UnsignedInteger32bits, Remainder )
CreateTupleWithTwoNamedDataMembers( DivisonResultUnsignedInteger64bits, UnsignedInteger64bits, Quotient, UnsignedInteger64bits, Remainder )



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
// 		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
class Arithmetics NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Arithmetics;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
	// or some functionality needed that does not involve the non static data members


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to perform the divison operation, and reutrn the quotient and remainder. The reason for this function,
    //      is to allow performing division and return as a result the quotient and remainder, and just want of them when using the
    //      standard C++ operations for divison '/' and modulo '%'.
    //
    //      The assembly instruction that will be used to achieve this is 'IDIV' for an operand size of byte. It divides the value in
    //		the AX register by the source operand ( divisor ) and stores the quotient in the AL register and remainder in the AH register.
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow 
    //			flag ( OF ) are undefined
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. dividend - a one byte size signed integer to be used as the dividend
    //          2. divisor - a one byte size signed integer to be used as the divisor
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
    //      1. The divisor must not be 0
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	EnsureRetrunValueIsUsed static inline DivisonResultSignedInteger8bits Divison( const SignedInteger8bits dividend, const SignedInteger8bits divisor );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to perform the divison operation, and reutrn the quotient and remainder. The reason for this function,
    //      is to allow performing division and return as a result the quotient and remainder, and just want of them when using the
    //      standard C++ operations for divison '/' and modulo '%'.
    //
    //      The assembly instruction that will be used to achieve this is 'IDIV' for an operand size of word. It divides the value in
    //		the DX:AX registers ( this means that DX is taken as the two most significant bytes and AX as the less significant bytes to 
    //      create a dobule word ) by the source operand ( divisor ) and stores the quotient in the AX register and remainder in the 
    //      DX register. In this method the DX part of the dividend is not used, and therefore it will be filled using sign extend,
    //      which takes the state of the sign bit in AX, and set all the bits in DX to it.
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow 
    //			flag ( OF ) are undefined
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. dividend - a word size signed integer to be used as the dividend
    //          2. divisor - a word size signed integer to be used as the divisor
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
    //      1. The divisor must not be 0
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	EnsureRetrunValueIsUsed static inline DivisonResultSignedInteger16bits Divison( const SignedInteger16bits dividend, const SignedInteger16bits divisor );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to perform the divison operation, and reutrn the quotient and remainder. The reason for this function,
    //      is to allow performing division and return as a result the quotient and remainder, and just want of them when using the
    //      standard C++ operations for divison '/' and modulo '%'.
    //
    //      The assembly instruction that will be used to achieve this is 'IDIV' for an operand size of double word. It divides the value in
    //		the EDX:EAX registers ( this means that EDX is taken as the four most significant bytes and EAX as the less significant bytes to 
    //      create a quad word ) by the source operand ( divisor ) and stores the quotient in the EAX register and remainder in the EDX 
    //      register. In this method the DX part of the dividend is not used, and therefore it will be filled using sign extend, which takes
    //      the state of the sign bit in EAX, and set all the bits in EDX to it.
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow 
    //			flag ( OF ) are undefined
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. dividend - a double word size signed integer to be used as the dividend
    //          2. divisor - a double word size signed integer to be used as the divisor
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
    //      1. The divisor must not be 0
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	EnsureRetrunValueIsUsed static inline DivisonResultSignedInteger32bits Divison( const SignedInteger32bits dividend, const SignedInteger32bits divisor );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to perform the divison operation, and reutrn the quotient and remainder. The reason for this function,
    //      is to allow performing division and return as a result the quotient and remainder, and just want of them when using the
    //      standard C++ operations for divison '/' and modulo '%'.
    //
    //      The assembly instruction that will be used to achieve this is 'IDIV' for an operand size of quad word. It divides the value in
    //		the RDX:RAX registers ( this means that RDX is taken as the eight most significant bytes and RAX as the less significant bytes to 
    //      create a dobule quad word ) by the source operand ( divisor ) and stores the quotient in the RAX register and remainder in the 
    //      RDX register. In this method the RDX part of the dividend is not used, and therefore it will be filled using sign extend,
    //      which takes the state of the sign bit in RAX, and set all the bits in RDX to it.
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow 
    //			flag ( OF ) are undefined
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. dividend - a quad word size signed integer to be used as the dividend
    //          2. divisor - a quad word size signed integer to be used as the divisor
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
    //      1. The divisor must not be 0
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
	EnsureRetrunValueIsUsed static inline DivisonResultSignedInteger64bits Divison( const SignedInteger64bits dividend, const SignedInteger64bits divisor );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to perform the divison operation, and reutrn the quotient and remainder. The reason for this function,
    //      is to allow performing division and return as a result the quotient and remainder, and just want of them when using the
    //      standard C++ operations for divison '/' and modulo '%'.
    //
    //      The assembly instruction that will be used to achieve this is 'DIV' for an operand size of byte. It divides the value in
    //      the AX register by the source operand ( divisor ) and stores the quotient in the AL register and remainder in the AH 
    //      register.
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow 
    //          flag ( OF ) are undefined
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. dividend - a one byte size unsigned integer to be used as the dividend
    //          2. divisor - a one byte size unsigned integer to be used as the divisor
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
    //      1. The divisor must not be 0
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline DivisonResultUnsignedInteger8bits Divison( const UnsignedInteger8bits dividend, const UnsignedInteger8bits divisor );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to perform the divison operation, and reutrn the quotient and remainder. The reason for this function,
    //      is to allow performing division and return as a result the quotient and remainder, and just want of them when using the
    //      standard C++ operations for divison '/' and modulo '%'.
    //
    //      The assembly instruction that will be used to achieve this is 'DIV' for an operand size of word. It divides the value in
    //      the DX:AX registers ( this means that DX is taken as the two most significant bytes and AX as the less significant bytes to 
    //      create a dobule word ) by the source operand ( divisor ) and stores the quotient in the AX register and remainder in the DX 
    //      register. In this method the DX part of the dividend is not used, and therefore all the bits will be turned off.
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow 
    //          flag ( OF ) are undefined
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. dividend - a word size unsigned integer to be used as the dividend
    //          2. divisor - a word size unsigned integer to be used as the divisor
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
    //      1. The divisor must not be 0
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline DivisonResultUnsignedInteger16bits Divison( const UnsignedInteger16bits dividend, const UnsignedInteger16bits divisor );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to perform the divison operation, and reutrn the quotient and remainder. The reason for this function,
    //      is to allow performing division and return as a result the quotient and remainder, and just want of them when using the
    //      standard C++ operations for divison '/' and modulo '%'.
    //
    //      The assembly instruction that will be used to achieve this is 'DIV' for an operand size of double word. It divides the value in
    //      the EDX:EAX registers ( this means that EDX is taken as the four most significant bytes and EAX as the less significant bytes to 
    //      create a quad word ) by the source operand ( divisor ) and stores the quotient in the EAX register and remainder in the EDX 
    //      register. In this method the EDX part of the dividend is not used, and therefore all the bits will be turned off.
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow 
    //          flag ( OF ) are undefined
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. dividend - a double word size unsigned integer to be used as the dividend
    //          2. divisor - a double word size unsigned integer to be used as the divisor
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
    //      1. The divisor must not be 0
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline DivisonResultUnsignedInteger32bits Divison( const UnsignedInteger32bits dividend, const UnsignedInteger32bits divisor );


    // Method Information :
    //
    //  Description :
    //
    //      Use this method to perform the divison operation, and reutrn the quotient and remainder. The reason for this function,
    //      is to allow performing division and return as a result the quotient and remainder, and just want of them when using the
    //      standard C++ operations for divison '/' and modulo '%'.
    //
    //      The assembly instruction that will be used to achieve this is 'DIV' for an operand size of quad word. It divides the value in
    //      the RDX:RAX registers ( this means that RDX is taken as the eight most significant bytes and RAX as the less significant bytes to 
    //      create a dobule quad word ) by the source operand ( divisor ) and stores the quotient in the RAX register and remainder in the 
    //      RDX register. In this method the RDX part of the dividend is not used, and therefore all the bits will be turned off.
    //
    //      Flags affected :
    //
    //          Carry flag ( OF ), parity flag ( PF ), auxilary flag ( AF ), sign flag ( SF ), zero flag ( ZF ) and the overflow 
    //          flag ( OF ) are undefined
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          1. dividend - a quad word size unsigned integer to be used as the dividend
    //          2. divisor - a quad word size unsigned integer to be used as the divisor
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
    //      1. The divisor must not be 0
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    EnsureRetrunValueIsUsed static inline DivisonResultUnsignedInteger64bits Divison( const UnsignedInteger64bits dividend, const UnsignedInteger64bits divisor );


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
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( Arithmetics );


};  //  Class Arithmetics