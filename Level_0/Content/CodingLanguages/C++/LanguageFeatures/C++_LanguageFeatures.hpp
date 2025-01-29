namespace Universe
{




// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   						C/C++ LANGUAGE                                                                         ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //



// ************************************************************************************************************************************************************************** //
// **														   						MACRO SUPPORT                                                                          ** //
// ************************************************************************************************************************************************************************** //



// MACROS - are useful in creating a template function in c, the arguments type is not specified, This way it can accept every type, of course the type must match certain 
// conditions. It is also needed when returning, from a c++ template function the call is treated as normal function call, even if it is inlined, meaning using the return, 
// would only go up in the stack to the calling function of the template one. For macro it is different, the pre-proccessor writes the text in the source file before it 
// reaches the compiler, and therefore it treated as part of the total function, and not as a function call. IN GENERAL macros should be avoided in c++ becuase the compiler 
// error messages are far better then dealing with the preprocessor error messages


// To make multiline macros use the syntax :
//
//		#define Macro( X ) {'\'
//		'\'
//				...'\'
//		'\'
//		}'\'
//
// Note - the marks '' are there only to prevent the compiler error "multi line comment"
//
// Only C style comments can be used in multiline macro!!


// The pound character "#" in macros - used to notify to the preprocessor that an expansion to the parameter to the literal, for example :
//
//			#define MakeString( string ) #string
//
//			MakeString( LORD )   ->   equals "LORD"
//
// Token passing operator "##" - allows tokens used as actual arguments to be concatenated to form other tokens. It is useful to merger two tokens into one while expanding
// macros. This is calles token pasting or token concatenation. When the macro is expanded, the two tokens on either side of each "##" operator are combined into a single
// token, which then rplaces the "##" and the two original tokens in the macro expansion, for example :
//
//			#define ConcatenateTwoArguments( first, second ) first##second
//
//			ConcatenateTwoArguments( X, Y )  ->   equals XY
//
// To concatenate a macro argument and a string :
//
//			MacroArgument ## String


// If a macro to change the operator itself for example :
//
//			#define CreateOperator( OperatorType ) int operator OperatorType()
//
// The variable should be jus written and then the macro can be used :
//
//			CreateOperator( + ) OR CreateOperator( - )


// The preprocessor is not aware of brace-matching so it will see three arguments in the following example :
//
//          MACRO( a, {1, 2} )
//
// the second and third are {1 and 2}, respectively.
//
// This is a known limitation of the preprocessor. Therefore a macro is created with the name comma that will be used inside macro's when a comma is needed outside 
// a parentheses
#define COMMA ,


// In C++ template objects can have more then one template argument, this means a comma needs to appear between the template arguments to seperate
// them. Becasue this commas are not in wrapped by parentheses the preprocessor will conside it as multiple arguments. The following macro is created
// to avoid that, by notifying the preprocessor that it should be considered as one argument
#define ConsiderAsOneArgument( ... ) __VA_ARGS__



// ************************************************************************************************************************************************************************** //
// **														   						 TEST MODE                                                                             ** //
// ************************************************************************************************************************************************************************** //



// Major problem with MACRO is that the code inside will not be able to be debugged with gdb. This means that to actually test the program the MACRO must be removed. This 
// is annoying when all the point of this is to work for testing. There is no currently other way of adding code only if required to the executable, then the setbacks 
// must be absorbed for now


#ifdef TEST_MODE
#define DEBUG_TOOL( DEBUG_CODE ) DEBUG_CODE
#else
#define DEBUG_TOOL( DEBUG_CODE )
#endif



// ************************************************************************************************************************************************************************** //
// **														   				      TEXT MANIPULATION                                                                        ** //
// ************************************************************************************************************************************************************************** //



// Macros arguments, that are supposed to be placed be the actual string given, can be emitted by just not providing anything, and they therefore won't appear
// in the result text :
//
//		For example the macro,
//
//					KAKA( Argument1, Argument2 ) #Argument1 " " #Argument2
//
//		If the macro is called using 2 arguments :
//
//					KAKA( Fuck, Sister )  -->   Fuck Sister
//
//		If one of the arguments are not needed :
//
//					KAKA( , Soda )  -->  Soda
//


// Use this macro to concatenate 2 pieces of text :
//
//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOMEDEVIL
//		
#define Concatenate2piecesOfText( TextBeginning, TextEnd ) TextBeginning ## TextEnd


// Use this macro to concatenate 3 pieces of text :
//
//		TextBeginning = HANDSOME, TextMiddle = AND HOT, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOMEHOTDEVIL
//		
#define Concatenate3piecesOfText( TextBeginning, TextMiddle, TextEnd ) TextBeginning ## TextMiddle ## TextEnd


// Use this macro to concatenate 4 pieces of text :
//
//		TextBeginning = HANDSOME, TextLowerMiddle = HOT, TextHigherMiddle = LIKE, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOMEHOTLIKEDEVIL
//		
#define Concatenate4piecesOfText( TextBeginning, TextLowerMiddle, TextHigherMiddle, TextEnd ) TextBeginning ## TextLowerMiddle ## TextHigherMiddle ## TextEnd


// Use this macro to concatenate 2 pieces of text with space between them :
//
//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOME DEVIL
//		
#define ConcatenateTextWithSpaceBetween( TextBeginning, TextEnd ) TextBeginning TextEnd


// Use this macro to concatenate 2 pieces of text with comma between them :
//
//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOME,DEVIL
//		
#define ConcatenateTextWithCommaBetween( TextBeginning, TextEnd ) TextBeginning,TextEnd


// Use this macro to add quatation marks "" around some text :
//
//		Text = DEVIL  -->  after MACRO  -->   "DEVIL"
//
// This macro can also deal with text containing comma ','. When providing text with comma to the preprocessor, instead of one argument, it will consider it
// as 2 arguments. This macro is used to solve this problem
//
//		Text = DEVIL,HANDSOME   -->   after MACRO   -->   DEVIL,HANDSOME
//		
#define CreateStringBySurroundWithQuatationMarks( ... ) #__VA_ARGS__


// Use this macro to concatenate 2 pieces of text and wrap them with quatation marks :
//
//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   "HANDSOMEDEVIL"
//		
#define CreateStringByConcatenate2piecesOfTextAndWrapWithQuatationMarks( TextBeginning, TextEnd ) CreateStringBySurroundWithQuatationMarks( ConcatenateText( TextBeginning, TextEnd ) )


// Use this macro to concatenate 2 pieces of text with space between and wrap them with quatation marks :
//
//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   "HANDSOME DEVIL"
//		
#define CreateStringByConcatenate2piecesOfTextWithSpaceBetweenAndWrapWithQuatationMarks( TextBeginning, TextEnd ) CreateStringBySurroundWithQuatationMarks( ConcatenateTextWithSpaceBetween( TextBeginning, TextEnd ) )



// ************************************************************************************************************************************************************************** //
// **														   			  		   TYPE DEFINITIONS                                                                        ** //
// ************************************************************************************************************************************************************************** //



// The new name of using a deduced type, instead of 'auto'
//
#define DeduceType auto



// The new name of using ascii character, instead of 'char'
//
// Range :  0 to 127 
using AsciiCharacter = char;


// The new name of using singed 8 bits, instead of 'char'
//
// Range :  -128 to 127 
using SignedInteger8bits = char;


// The new name of using unsinged 8 bits, instead of 'unsigned char'
//
// Range :  0 to 255 
using UnsignedInteger8bits = unsigned char;


// The new name of using singed 16 bits, instead of 'short'
//
// Range :  -32,768 until 32,767
using SignedInteger16bits = short ;


// The new name of using unsinged 16 bits, instead of 'unsigned short'
//
// Range :  0 until 65,535
using UnsignedInteger16bits = unsigned short; 


// The new name of using singed 32 bits, instead of 'int'
//
// Range :  -2,147,483,648 until 2,147,483,647
using SignedInteger32bits = int;


// The new name of using unsinged 32 bits, instead of 'unsigned int'
//
// Range :  0 until 4,294,967,295
using UnsignedInteger32bits = unsigned int;


// The new name of using singed 64 bits, instead of 'long'
//
// Range :  -9,223,372,036,854,775,808 until 9,223,372,036,854,775,807
using SignedInteger64bits = long;


// The new name of using unsinged 64 bits, instead of 'unsigned long'
//
// Range :  0 until 18,446,744,073,709,551,615
using UnsignedInteger64bits = unsigned long;


// The new name of using boolean, instead of 'bool'
//
// Range :  false, true
using Boolean = bool;


// The new name of using floating point, instead of 'float'
//
// Range :  1.17549e-38 until 3.40282e+38
using FloatingPoint32bits = float;


// The new name of using double precision floating point, instead of 'double'
//
// Range :  2.22507e-308 until 1.79769e+308
using FloatingPoint64bits = double;


// The new name of using singed 64 bits, instead of 'long'
//
// Range :  -9,223,372,036,854,775,808 until 9,223,372,036,854,775,807
using LargestSignedInteger = long;


// The new name of using unsinged 64 bits, instead of 'unsigned long'
//
// Range :  0 until 18,446,744,073,709,551,615
using LargestUnsignedInteger = unsigned long;



// ************************************************************************************************************************************************************************** //
// **														   			  		     CV QUALIFIERS                                                                         ** //
// ************************************************************************************************************************************************************************** //



// This term referes to the keywords 'const' and 'volatile' when used on a method of an object!



// ************************************************************************************************************************************************************************** //
// **														   			  		   STATIC ASSERTION                                                                        ** //
// ************************************************************************************************************************************************************************** //



// Static assertions are a way to check if a condition is true when the code is compiled. Then this is used to make the compiler stop the compilation
// and issue the appropriate error message given. The condition that needs to be checked must be a constant expression. 
//
// Prior to the C++11 standard the primary mean of producing a compile time error message was via the #error directive, which causes the implementation
// to produce a diagnostic message that includes the message that followed it. For example :
//
//      #if defined( ANNA )
//      #error "Please want me"
//      #endif
//
// This approach works well for simple tasks. However, it fails for things like checking the size of data types. It is because the tokens such as 
// 'sizeof' are not converted to source tokens until after the preprocessing translation stage at which point preprocessing directives can not be 
// used anymore. 
//
// Syntax :
//
//		static_assert( Boolean / constexpr, message )  	( C++11 )
//
//		static_assert( Boolean / constexpr )		 	( C++17 )
//
// A static assert declaration may appear at namespace and block scope and inside a class body. If a true value is given, this declaration has no effect.
// Otherwise a compile time error is issued, and the message, if exist, is included in the diagnostic message


// The follwing macro will be used instead of the keyword 'static_assert' to make the meaning of using it more understood from the name
#define CompileTimeAssert( Expression, ErrorMessage ) static_assert( Expression, ErrorMessage )



// ************************************************************************************************************************************************************************** //
// **														   			  DISABLE DEFAULT GENERATED METHODS                                                                ** //
// ************************************************************************************************************************************************************************** //



// NOTE - For all the follwing macros the object name must not contain template arguments, it should be only the name


// Use the following macro to disable the copy constructor and assignment operator. This means that each object that contains this macro, the instances
// will not be able to be copied
#define DisableCopyConstructorAndAssignmentOperator( ObjectName ) 		\
																				\
	/* Disable the copy constructor	*/											\
	ObjectName( const ObjectName& other ) = delete;								\
																				\
	/* Disable the assignment operator	*/										\
	ObjectName& operator=( const ObjectName& other ) = delete


// Use the following macro to disable the move constructor and move assignment operator. This means that each object that contains this macro, the 
// instances will not be able to be moved
#define DisableMoveConstructorAndMoveAssignmentOperatorForTemplateObject( ObjectName ) 		\
																									\
	/* Disable the move constructor	*/																\
	ObjectName( ObjectName&& other ) = delete;														\
																									\
	/* Disable the move assignment operator	*/														\
	ObjectName& operator=( ObjectName&& other ) = delete


// Use the following macro to disable the all copy and move operations. This means that each object that contains this macro, the instances will 
// not be able to be copied or moved
#define DisableCopyAndMove( ObjectName ) 																			\
																														\
	/* Disable the copy constructor and assignment operator	*/															\
	DisableCopyConstructorAndAssignmentOperator( ObjectName );													\
																														\
	/* Disable the move constructor and move assignment operator	*/													\
	DisableMoveConstructorAndMoveAssignmentOperatorForTemplateObject( ObjectName )


// Use the following macro to disable the default constructor, destructor, and all copy and move operations. This means that this object will
// have no instances. It used mainly for objects will only static methods
#define NoInstances( ObjectName ) 									\
																			\
	/* Disable the default constructor	*/									\
	ObjectName() = delete;													\
																			\
	/* Disable the destructor	*/											\
	~ObjectName() = delete;													\
																			\
	/* Disable all the copy and move related methods of the object */		\
	DisableCopyAndMove( ObjectName )



// ************************************************************************************************************************************************************************** //
// **														   			         DISABLE OPERATORS                                                                         ** //
// ************************************************************************************************************************************************************************** //



// Use the following macro to disable the address of operator '&'. This means that the memory address of the object instances should not be used,
//
#define DisableTheAbilityToTakeTheMemoryAddressOfTheInstanceByDeletingTheAddressOfOperator( ObjectName ) 		\
																													\
	/* Disable the address of operator for non constant instances	*/												\
	friend ObjectName* operator&( ObjectName& instance ) = delete; 													\
																													\
	/* Disable the address of operator for constant instances	*/													\
	friend const ObjectName* operator&( const ObjectName& instance ) = delete



// ************************************************************************************************************************************************************************** //
// **														   				    FORWARD DECLARATIONS                                                                       ** //
// ************************************************************************************************************************************************************************** //



// When a type is forward declared, all the compiler knows is that this type exists. It does not know its size, members or methods. This is why its
// called 'incomplete type'. Therefore, it can not be used to declared a member or base class since the compiler would need the layout of the type.
//
// Assuming the following forward declaration :
//
//		class X;
//
// The things that can be done are :
//
//	1. Declare a pointer or a reference to the incomplete type :
//
//		class Foo
//		{
//			X* pointer;
//			X& reference;
//		};
//
//	2. Declare functions or methods which accept or return incomplete types :
//		
//		void Foo( X );
//
//		X Foot();
//
//	3. Declare functions or methods which accept or return pointers and references to the incomplete type ( but without using its members ) :
//
//		void Feet( X* pointer, X& reference );
//
//		X& FeetPlease();
//
//		X* FootPleas();
//
// The things that can not be done :
//
//	1. Use it as a base class :
//
//		class Foo : public X    // COMPILE ERROR!
//		{};
//
//	2. Use it to declare a member :
//
//		class Foo
//		{
//			X member;    // COMPILE ERROR!
//		};
//
//	3. Define functions or methods using this type :
//
//		void Foott( X instance )    // COMPILE ERROR!
//		{}
//
//		X Feeet()				    // COMPILE ERROR!
//		{}
//
//	4. Use its methods or members :
//
//		class PleaseGiveMeFeetWomen
//		{
//			X* member;
//
//			void MaybeRapeAndGoToJail()
//			{
//				member->SomeMethod();				
//				
//				int integer = member->SomeMember;
//			}
//
//		};
//
// When it comes to templates, there is no absolute rule, whether an incomplete type can be used as a template parameter is dependent on the way
// the type is used in the template



// ************************************************************************************************************************************************************************** //
// **														   				      HEADER GUIDELINES                                                                        ** //
// ************************************************************************************************************************************************************************** //



// 1. Use include guards, make the include guard the same as the file name, syntax :
//
// 			#ifndef FILE_H
// 			#define FILE_H
//
// 			#endif   //  FILE_H
//
//    The reason is that it can help prevent danger circular references between header files which can cause infinite loops, and compilation failures. Furthermore, 
//    in the absence of an include guard, a file will need to be processed multiple times and can cause significant build delays in large systems
//
// 2. Adding "using namespace" statements at top level in a header file. Headers should define only the names that are part of the interface, not names used in 
//    its own implementation. However, a using directive at top level in a header file injects names into every file that includes the header
//
// 3. Header should contain one functionality, and not multiple
//
// 4. The header file should include or forward declare all that it needs to compile
//
// 5. Don't include headers that only the cpp file uses.
//
// 6. Use forward declaration instead of including the entire header when possible



// ************************************************************************************************************************************************************************** //
// **														   			     NAME MANGALING AND EXTERN 'C'                                                                    ** //
// ************************************************************************************************************************************************************************** //



// C++ supports function overloading, i.e., there can be more than one function with same name and differences in parameters. How does C++ compiler distinguishes 
// between different functions when it generates object code – it changes names by adding information about arguments. This technique of adding additional 
// information to function names is called Name Mangling. C++ standard doesn’t specify any particular technique for name mangling, so different compilers may 
// append different information to function names
//
// Consider following declarations of function foo :
//
// 			int foo( void ) { return 1; }
//
// 			int foo( int ) { return 0; }
//
// 			void goo( void ) { int I = foo(), j = foo( 0 ); }
//
// A C++ compiler may mangle above names to the following :
// 
// 			int foo_v( void ) { return 1; }
//
// 			int foo_i( int ) { return 0; }
//
// 			void goo_v( void ) { int I = foo_v(), j = foo_i( 0 ); }
//
// How to handle C symbols when linking from C++?
//
// In C, names may not be mangled as C doesn’t support function overloading. So how to make sure that name of a symbol is not changed when we link a C code in C++. 
// For example, see the following C++ program that uses printf() function of C :
//
// 		int printf( const char* format, … );
//
// 		int main()
// 		{
// 			printf(“War”);
// 			return ( 0 );
// 		}
//
// This will not compile. The reason for compiler error is simple, the name of printf is changed by C++ compiler and it doesn’t find definition of the function 
// with the new name. The solution for this problem is extern “C” in C++. When some code is put in extern “C” block, the  C++ compiler ensures that the function 
// names are unmangled – that the compiler emits a binary file with their names unchanged, as a C compiler would do. If we change the above program to following, 
// the program works fine and prints “War” on console :
//
// 		extern “C” 
// 		{
// 			int printf( const char* format, … );
// 		}
//
// 		int main()
// 		{
// 			printf(“War”);
// 			return ( 0 );
// 		}
//
// To conclude:
//
// 		1. Since C++ supports function overloading, additional information has to be added to function names ( called name mangling ) to avoid conflicts in binary 
//		   code
//
// 		2. Function names may not be changed in C as C doesn’t support function overloading. To avoid linking problems, C++ supports extern “C” block. C++ compiler 
//		   makes sure that names inside extern “C” block are not changed



// ************************************************************************************************************************************************************************** //
// **														   					 FUNCTIONS ATTRIBUTES                                                                      ** //
// ************************************************************************************************************************************************************************** //



// Function Attribute - always_inline :
//
//	Use to enforce the compiler to inline the function
//
#define AlwaysInlineFunction inline __attribute__(( always_inline ))


// Function Attribute - naked :
//
// 	This attribute tells the compiler that the function is an embedded assembly function. You can write the body of the function entirely in assembly code using
// 	__asm statements. The compiler does not generate prologue and epilogue sequences for functions with the naked attribute. The compiler only supports basic 
// 	__asm statements in those functions. Using extended assembly, parameter references or mixing C code with __asm statements might not work reliably!
//
#define AssemblyFunction __attribute__(( naked ))



// ************************************************************************************************************************************************************************** //
// **														   				    POINTERS RELATED MACROS                                                                    ** //
// ************************************************************************************************************************************************************************** //



// The current macro is defined as a macro and not as an inline function becuase the return statement won't have the right affect in an inline function, the required 
// operation is not to return to the direct caller of this macro, but to the caller of the the function that called this macro
#define ReturnValueIfPointerIsNull( Pointer, Value ) do { if ( ( Pointer == nullptr ) ) { return ( Value ); } } while( false )

// The current macro is defined as a macro and not as an inline function becuase the return statement won't have the right affect in an inline function, the required 
// operation is not to return to the direct caller of this macro, but to the caller of the the function that called this macro
#define ReturnValueIfPointerIsNotNull( Pointer, Value ) do { if ( ( Pointer != nullptr ) ) { return ( Value ); } } while( false )


// The current macro is defined as a macro and not as an inline function becuase the return statement won't have the right affect in an inline function, the required 
// operation is not to return to the diredt caller of this macro, but to the caller of the the function called this macro
#define ReturnIfPointerIsNull( Pointer ) do { if ( ( Pointer == nullptr ) ) { return; } } while( false )



// ************************************************************************************************************************************************************************** //
// **														   				COMMAND LINE ARGUMENTS CHECKING                                                                ** //
// ************************************************************************************************************************************************************************** //



// Use this to check that the number of command line arguments is larger or equal the required amount
#define ReturnErrorNumberIfCommandLineArgumentsAreNotEnough( CommandLineArgumentsNumber, RequiredCommandLineArguments, ErrorNumber ) do { if ( ( CommandLineArgumentsNumber < RequiredCommandLineArguments ) ) { return ( ErrorNumber ); } } while( false )


// Use this to check that the number of command line arguments is equal the required amount
#define ReturnErrorNumberIfCommandLineArgumentsAreNotEqual( CommandLineArgumentsNumber, RequiredCommandLineArguments, ErrorNumber ) do { if ( ( CommandLineArgumentsNumber != RequiredCommandLineArguments ) ) { return ( ErrorNumber ); } } while( false )


// Use this to check that the number of command line arguments is equal the required amount
#define DisplayErrorMessaeAndReturnErrorNumberIfCommandLineArgumentsAreNotEqual( CommandLineArgumentsNumber, RequiredCommandLineArguments, ErrorNumber, ErrorMessage ) do { if ( ( CommandLineArgumentsNumber != RequiredCommandLineArguments ) ) { std::cout << ErrorMessage << std::endl; return ( ErrorNumber ); } } while( false )




// ************************************************************************************************************************************************************************** //
// **														   				 	  EXPRESSIONS SUPPORT                                                                      ** //
// ************************************************************************************************************************************************************************** //




// Use this to check the result of an expression is true and return the given value, it is useful because from this return the current function is ended, while 
// with inline functions it is immposible
#define ReturnValueIfExpressionIsTrue( Expression, ReturnValue ) do { if( ( ( Expression ) == true ) ) { return ( ReturnValue ); } } while( false )


// Use this to check the result of an expression is false and return the given value, it is useful because from this return the current function is ended, while 
// with inline functions it is immposible
#define ReturnValueIfExpressionIsFalse( Expression, ReturnValue ) do { if( ( ( Expression ) == false ) ) { return ( ReturnValue ); } } while( false )


// Use this to check the result of an expression is true then return. it is useful because from this return the current function is ended, while  with inline 
// functions it is immposible
#define ReturnIfExpressionIsTrue( Expression ) do { if( ( ( Expression ) == true ) ) { return; } } while( false )


// Use this to check the result of an expression is true then return. it is useful because from this return the current function is ended, while  with inline 
// functions it is immposible
#define ReturnIfExpressionIsFalse( Expression ) do { if( ( ( Expression ) == false ) ) { return; } } while( false )


// Use this to check if 2 values are equal then return. it is useful because from this return the current function is ended, while  with inline  functions
// it is immposible
#define ReturnIfTheValuesAreEqual( VALUE_1, VALUE_2 ) do { if( ( VALUE_1 == VALUE_2 ) ) { return; } } while( false )


// Use this to check if 2 values are not equal then return. it is useful because from this return the current function is ended, while  with inline  functions
// it is immposible
#define ReturnIfTheValuesAreNotEqual( VALUE_1, VALUE_2 ) do { if( ( VALUE_1 != VALUE_2 ) ) { return; } } while( false )



// ************************************************************************************************************************************************************************** //
// **														   				    OBJECT ORIENTED SUPPORT                                                                    ** //
// ************************************************************************************************************************************************************************** //



// This macro will be used to state that the object is not for inheritance
#define NotForInheritance final 


// The access modifiers work on class level, and not on object level, That is, two objects of the same class can access each other private members, Furthermore 
// inner class ( or nested class ) is always a friend of the class it is declared within, so the inner class can access outer class private and protected members 
// also


// The following object will be used to notify that a specific template argument is currently not in use
class UnsedTemplateArgument
{};



// ************************************************************************************************************************************************************************** //
// **														   				       TWO'S COMPLEMENT                                                                        ** //
// ************************************************************************************************************************************************************************** //



// Two's complement is a mathematical operation on binary numbers, it is used as signed number representation. The two's complement of an N-bit numbers is defined
// as its complement with respect 2 ^ N, for example :
//
//		010    ->    110
//
// As can be seen there are 3 bits :
//
//		2 ^ 3 = 8 = 2 ( 010 ) + 6 ( 110 )
//
// Two's complement is the most common method of representing signed integres on computers. In this scheme, if the binary number 010 in 2 base encodes the signed
// integer 2 in 10 base, then its two's complement 110 in base 2, encodes the inverse -2 in 10 base. In other words to reverse the sign of any integer in this
// scheme, the two's compliment can be used
//
// Compared to systems for representing signed numbers, two's complement has the advantage that the fundamental arithmetic operations of addition, subtraction
// and multiplication are identical to those for unsigned binary numbers ( as long as the inputs are represented in the same number of bits, and any overflow 
// beyond those bits is discarded from the result ). This property makes the system simpler to implement
//
// Conveniently, another way of finding the two's complement of a number is to take it's one's complement and add one, the sum of a number and it's one's 
// complement is all bits ON or ( 2 ^ N ) - 1, and by definition the sum of a number and it's two's complement is 2 ^ N
//
// Another way of looking at it, is that the 7 lower significant bits have the same meaning 2^0, 2^1 etc... How ever the meaning of the most significant bit
// is changed, insted of 2^7 it represents -2^7



// ************************************************************************************************************************************************************************** //
// **														   				    BIG OR LITTLE ENDIAN SUPPORT                                                               ** //
// ************************************************************************************************************************************************************************** //



// BIG ENDIAN - the most significant byte, which is the byte containing the most significant bits, is stored first and the following bytes are stored in decreasing 
// significance order with the least significant byte, which is the byte containing the least significant bit, being stored at last place
//
// LITTLE ENDIAN - reverses the order of the sequence and stores the least significant byte at the first location with the most significant byte being stored last
//
// It is important to remember that inside the byte, the left most bit is the most significant while the right most bit is the less significant, and this is always 
// true, no matter if the system uses little or big endian
//
// For example :
//
// The value 1 will be stored this way - 00000001
// And after left shifting 2 times - 00000100
//
// When left shifting a variable with more then 1 byte, the shifting will be performed this way :
//
// For the example the next state of the bits will be used - 11111111 00000000
//
// In little endian left shifting 2 times will give the result - 11111100 00000011
// In big endian left shifting 2 times will give the result - 11111100 00000000
//
// The important thing to note that for big endian it is simple, the bits move the expected way, one after the other, but for little endian the bits are added to the 
// far side of the next byte


// Give proper treatment, by dealing with big and little endian encoding systems where it is required. The big or little endian encoding appear when dealing
// with byte order in memory. In the byte itself the bit the is closest to the address of the byte, is the high order bit
//
//    The closest bit to the    The farest bit from the
//     address of the byte        address of the byte
//                        |      |
//      Byte address ->   00000000
//                        |      |
//            High order bit    Low order bit
//
// Then the value 1 will be stored this way :
//
//      Byte address ->   00000001
//                        |      |
//            High order bit    Low order bit
//
// Then in 1 byte this is always the case. But when dealing with more then 1 byte it is up to the system to decide whether the address of the first byte will
// contain the high order bits or the low order bits. For example for 2 bytes, store the value 1 in the 2 ways of endian encoding :
//
//    Little endian encoding :
//
//      First address of data type ->   00000000 00000001
//
//    Big endian encoding :
//
//      First address of data type ->   00000001 00000000


// Verify if the current encoding is little or big endian, returns true for little endian and false for big endian  
inline constexpr bool IsLittleEndian()
{
	// Create a variable with more then 1 octet and set it to 1
	constexpr UnsignedInteger16bits sample = 1U;

	// If the encoding is little endian the one bit set on in the variable will be in the first byte. The reference then points to a location 
	// with value other then zero will be converted to the boolean value true. For the big endian the only bit on would at the part of the 
	// variable that the reference is not reaching and therefore the value would be zero so be calm
	return ( static_cast< const UnsignedInteger8bits& >( sample ) );
}



// ************************************************************************************************************************************************************************** //
// **														   				         KEYWORDS                                                                              ** //
// ************************************************************************************************************************************************************************** //



// *************************************************************************   KEYWORD - inline    ************************************************************************** //


// When the program executes the function call instruction the CPU stores the memory address of the instruction following the function call, copies the  aarguments of the
// function on the stack and finally transfers control to the specified function. The CPU then executes the function code, stores the function return value in a predefined 
// memory location/register and returns control to the calling function. This can become overhead if the execution time of function is less than the switching time from 
// the caller function to called function ( callee ). For functions that are large and/or perform complex tasks, the overhead of the function call is usually insignificant 
// compared to the amount of time the function takes to run. However, for small, commonly-used functions, the time needed to make the function call is often a lot more 
// than the time needed to actually execute the function’s code. This overhead occurs for small functions because execution time of small function is less than the 
// switching time
//
// C++ provides an inline functions to reduce the function call overhead. Inline function is a function that is expanded in line when it is called. When the inline 
// function is called whole code of the inline function gets inserted or substituted at the point of inline function call. This substitution is performed by the C++ 
// compiler at compile time. Inline function may increase efficiency if it is small. The syntax for defining the function inline is :
//
// 		inline reutrnType FunctionName( arguments )
// 		{
//     		// code
// 		}  
//
// Remember, inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining. Compiler may not perform inlining in such circumstances 
// like :
//
// 		1. Function contains a loop
// 		2. Function contains static variables
// 		3. Function is recursive
// 		4. Function return type is other than void, and the return statement doesn’t exist in function body
// 		5. Function contains switch or goto statement
//
// Inline functions provide following advantages :
//
// 		1. Function call overhead doesn’t occur
// 		2. Saves overhead of a return call from a function
// 		3. Enable compiler to perform context specific optimization on the body of function. Such optimizations are not possible for normal function calls
//
// Inline function disadvantages :
//
// 		1. The inlined functons's local variables are been taken into account in the amount of local variables the function that uses the inline function. THerefore, there
//		   cases where the additional variables are more then the available registers in the system and the memory will be need to be used, which slow down execution
//
// 		2. The size of the binary executable file will be larger, due to all the duplication of same code. Therefore,
//
//		3. Inline functions does not have an address in memory, because there code is written directly and not in specific memory address that every call control moves over
//		   to the first instruction there. This means low instruction cache hit which can slow down execution
//
// 		4. Inline functions might cause thrashing because inlining might increase size of the binary executable file. Thrashing in memory causes performance of computer 
//		   to degrade



// Inline functions - are more than a simple copy-paste procedure ( in contrast to, say, preprocessor macros ). They behave like normal functions, so any return value would 
// be reflected to the caller just like a normal functions. furthermore the compiler is free to decide whether the function is too complicated too be inlined, meaning the 
// inline reserved keyword is a request from the compiler not an obligation. Also every template function is an inline function as well, because the template must be inlined 
// into the required file



// Virtual functions, which means wait until run time to choose the method, in general can not be inlined. To inline the compiler must know the method it will use!



// The guaranteed effect of 'inline' as applied to a function, is to allow the function to be defined identically, with external linkage, in multiple translation units.
// This means defininf the function in a header, that can be included in multiple translation. This now extends also to variables. In practical this allows to use
// 'inline' to define external linkage constant namespace scope variable, or any static class data member, in a header file, so that multiple definitions that result
// when that header is included in multiple translation units are okay with the linker, it will just choose one of them.


// **************************************************************************   KEYWORD - mutable *************************************************************************** //


// When an instance of an object is declared constant, this means only bitwise constant ( makes sure that the actual bits are not changed ) is supported. But, 
// the concept of constant instance, can be also defined through the eyes of the user. Does the user will notice any change upon using the instance?
//
// This means that parts in the instance can change, as long as the "state" of the instance that the user perceive is constant! 
//
// The point then is to allow making changes to data members that are part of the implementation, and do not effect the view of the user. The mutable keyword 
// can be used to exclude members from this checking. The mutable keyword is a way to pierce the constant veil draped over an instance. In case of a reference 
// or a pointer to a constant object, only read access is allowed for any visible data members, and only methods declared constant can be used. The exception 
// is data members declared as mutable, they can be changed inside constant methods. In other words, it allows the differentiation of bitwise constant and logical 
// constant. Bitwise constant means that the actual object bits can not be changed, while logical constant means that the object doesn't change in a way that is 
// visible through the public interface. The important note when using mutable is that it is all up to the programmer to ensure that the mutable doesn't destroy 
// the constant concept and is only used in useful special cases. Furthermore, the mutable keyword helps because it clearly marks data members that are subject 
// to these special cases


// *************************************************************************   KEYWORD - volatile *************************************************************************** //


// The voltaile keyword is a qualifier that is applied to a variable when it is declared. It tells the compiler that the value of the variable may change at any
// time, without any action being taken by the code the compiler finds nearby!
//
// The following examples demonstrate a few cases where proper use of the volatile is needed :
//
//		1. Code that works fine, until compiler optimizations is enabled
//		2. Code that works fine, until interrupts are enabled
//		3. RTOS tasks that work fine in isolation, until some other task is spawned
//
// The syntax :
//
//		volatile UnsignedInteger64bits variable
//
//		volatile UnsignedInteger64bits* pointer - a pointer to a volatile variable
//
//		UnsignedInteger64bits* volatile pointer - a volatile pointer to a not volatile variable
//
// Finally, if the volatile keyword is applied to a structure or a union, the entire contents of them will become volatile!
//
// A variable should be declared volatile whenever its value could change unexpectedly. In practice, only three types of variables could change :
//
//		1. Memory mapped peripheral registers
//		2. Global variables modified by an interrupt service routine
//		3. Global variables accessed by multiple tasks within a multi threaded application
//		
// Peripheral registers :
//
// Embedded systems contain real hardware, usually with sophisticated peripherals. These peripherals contain registers whose values may change asynchronously
// to the program flow. For example a register that is used as a flag :
//
//		UnsignedInteger64bits* pointerToMemoryMappedInputOutputDevice = ( UnsignedInteger64bits* ) 0x1234;
//
//		// Loop as long as the flag register is 0
//		while ( *pointerToMemoryMappedInputOutputDevice == 0 )
//		{
//			...
//		}
//
// This code will certainly fail as soon as compiler optimizations will be enabled. The compiler will generate assembly language that looks something like
// this :
//
//			mov pointerToMemoryMappedInputOutputDevice, 0x1234
//			mov a, [ pointerToMemoryMappedInputOutputDevice ]
//		loop.
//			...
//			bz loop
//
// The ratinale is that once the accumulator was read, there is no need to reread it from memory because it does not change anywhere in the function. Then 
// the accumulator will stay the same, which will create an infinite loop. To force the compiler use the volatile keyword :
//
//		volatile UnsignedInteger64bits* pointerToMemoryMappedInputOutputDevice = ( volatile UnsignedInteger64bits* ) 0x1234;
//
// The assembly will now look :
//
//			mov pointerToMemoryMappedInputOutputDevice, 0x1234
//		loop.
//			...
//			mov a, [ pointerToMemoryMappedInputOutputDevice ]
//			bz loop
//
// Interrupt service routines :
//
// Interrupt service routines often set variables that are tested in mainline code. For example, a serial port interrupt may test each received character 
// to see if it is an ETX character ( notify end of message ). If the character is an ETX, the interrupt service routine might set a global flag. An
// incorrect implementation of this might be :
//
//		boolean globalVariable_ETXfound = false;
//
//		void main()
//		{
//			...
//
//			while ( globalVariable_ETXfound == false )
//			{
//				// Wait
//			}
//
//		}
//
//		interrupt void InterruptServiceRoutine()
//		{
//			...
//			
//			if ( receivedCharacter == ETX )
//			{
//				globalVariable_ETXfound = true;
//			}
//
//		}
//
// The problem is that the compiler does not know that the global variable will be changed from the interrupt service routines, and therefore assume that the
// value is constant. The solution is to declare the variable volatile!
//
// Multithreaded applications :
//
// Despite the presence of queues, pipes and other scheduler aware communications mechanisms in real time operating systems, it is still possible that RTOS 
// tasks will exchange information via a shared memory location. The compiler has no idea what a context switch is or when one might occur. Thus, a task 
// asynchronously modifying a shared global is conceptually the same as the interrupt service routine scenario. All shared global objects ( variables,
// memory buffers, hardware registers etc... ) must be declared volatile to prevent compiler optimization from introducing unexpected  behavior


// Volatile is an instruction to the compiler that says, whenever this variable is used, make sure that it is loaded from main memory or caches. In a 
// more hardware agnostic way its whenever this variable is used, assume that it's value could have changed, even if there is no such assumption
// provable from examining the entire program. Practically. volatile is meant for the cases when a variable memory can change from external causes
// like memory mapped input and output.
//
// Volatile member functions work similar to constant member functions, it means that the receiver object is treated as though it were declared as a
// volatile ( volatile T* ). Consequentially, any reference to it will be considered as volatile. Moreover, a volatile object can only call volatile
// member functions


// ***********************************************************************   KEYWORD - __attribute__   ********************************************************************** //


// In GNU ceratin things are declared about functions called in the program which help the compiler optimize function calls and check the code more
// carefully. The keyword '__attribute__' allows to specifiy special attributes when making a declration. This keyword is followed by an attribute
// specification inside double parentheses. The attribute may be specified as it is, or with preceding and following '__', this allows using them
// to be used in header files without being concerned about a possible macro of the same name. For example :
//
//		void FuckThis() __attribute__ (( __unused__ ));
//
// To be effective, the attribute needs to be applied to the declaration ( in the header ). If a call is being compiled, and the declaration the
// compiler has seen lacks the attribute, the compiler normally will not be able to issue a diagnostic based on the attribute.
//
// The following are a list of the attributes that currently being used in the system :
//
//	1. unused - this attribute, aatched to a function, means that the function is meant to be possibly unused. GCC will not produce a warning
//				for this function
//
//	2. section ( "section-name" ) - normally, the compiler places the code it generates in the 'text' section. Sometimes, more sections are needed
//	   or particular functions needs to appear in special sections. The 'section' attribute specifies that a function lives in particular section.
//	   For example, the declaration :
//
//			extern void FeetPlease( void ) __attribute__ (( section( "Women" ) )) - puts the function in the section 'Women'
//
//	3.


// *************************************************************************   KEYWORD - override   ************************************************************************* //


// The identifier 'override', if used, appears immediately after the declarator in the syntax of a member function declration or a member function
// definition inside a class definition. The identifier 'override' ensures that the function is virtual and is overriding a virtual function from
// a base class. 'override' is an identifier with a special meaning when used after member function declarators, it's not resetved keyword otherwise!



// ************************************************************************************************************************************************************************** //
// **														   				        OPERATORS                                                                              ** //
// ************************************************************************************************************************************************************************** //



// ***************************************************************************   SHIFT OPERATORS   ************************************************************************** //


// This is used to move the bits of a variable. In every shift the new bits added to the variable are always in state off ( 0 ) :
//
// 		left shift “<<”         →    a * 2
//	
// 		right shift “>>”        →    a / 2


// ****************************************************************************   OPERATOR - *&   *************************************************************************** //


// The operator "&" means call by reference. The function is allowed to change the variable. By all means a pointer is also a variable, so this syntax is equal 
// to the former pointer to pointer syntax "**". The reference operator allows for more readable code, and stronger type checking


// ****************************************************************************   OPERATOR - ->   *************************************************************************** //


// The operator "->" is synonym for :
//
// 		a->b    ==    (*a).b
//
// This operator must return a pointer. The idea is that the operator should return a pointer to the real object that should have the pointer applied to. The 
// syntax is:
//
// 		ResourceInsideTheObject* operator→()
//
// This is required because the compiler will evaluate the following expression as:
//
// 		Class->member     ==    ( Class.operator->() )->member


// *************************************************************************   OPERATOR - sizeof   ************************************************************************** //


// The operator 'sizeof' queries the size of the object or type. Used when actual size of the object must be known. Synatx :
//
//		sizeof( type ) OR sizeof ( expression )
//
// Both versions are constant expressions of type std::size_t. The first yields the size in bytes of the object representation of type, the second
// yields the size in bytes of the object representation of the type of expression, if that expression is evaluated. The result of this operator is
// always nonzero, even if applied to an empty class type!



// ************************************************************************************************************************************************************************** //
// **														   				     ESCAPE CHARACTERS                                                                         ** //
// ************************************************************************************************************************************************************************** //



// The escape characters always begin with the character backslash "\". Here is the Escape characters list :
//
// 		1. \n - new line
// 		2. \' - character one quote
// 		3. \" - character two quotes



// ************************************************************************************************************************************************************************** //
// **														   				     VARIADIC FUNCTIONS                                                                        ** //
// ************************************************************************************************************************************************************************** //



// Prior to C++11, the only way to write functions that take an arbitrary number of arguments was to use variadic functions like printf, with  the ellipsis syntax (...) 
// and the accompanying va_ family of macros. It is type unsafe ( all type resolution has to be done explicitly with casts in va_arg, at runtime ), it's tricky to get 
// right. The va_ macros perform low-level memory manipulation. This all leads to many errors
//
// Use the header "cstdarg". To create a variadic function, an ellipsis (...) must be placed at the end of a parameter list. Inside the body of the function, a variable 
// of type va_list must be defined. Then the macros :
//
//		1. va_start( va_list ap, last fixed param ) - this macro initializes the va_list for subsequent use by va_arg(), va_end(), and must be called first. The 
//		   argument last fixed param is the name of the last argument before the variable argument list, that is, the last argument of which the calling function 
//		   knows the type
//
//		2. va_arg( va_list ap, cast type )- this macro expands to an expression that has the type and value of the next argument in  the  call
//
//		3. va_end( va_list ap ) - end the use of the va_list
//
// can be used.
//
// One of the more annoying problems is leaving something that is clearly known at compile-time, to run-time. Yes, when we write a variadic function we don't know all 
// the ways it's going to be used. But when the compiler puts the whole program together, it does know. It sees perfectly well all the invocations of the function 
// throughout the program, and all the possible argument types it gets passed ( types are, after all, resolved at compile-time in C++ )



// ************************************************************************************************************************************************************************** //
// **														   			  		  LAMBDA EXPRESSION                                                                        ** //
// ************************************************************************************************************************************************************************** //



// Functors are more "complex functions", that can store information across multiple invokes of the function. It is implemented through creating a new
// object with the operator '()' overloaded, and it contain whatever data members and everything an object can do. The problem is that there are multiple
// uses to this functors, and when they are gonna be used only in one place in the program, writing an object each time divides the code and creates more 
// code. Therefore, to allow this unique functors more easily, the function needs to be written in a special syntax directly where functions and functors are
// expected.
//
// C++ solves this through 'lambda' expression. It allows to write inline, annonymous functor to replace the object that needs to be created for the purpose.
// The syntax :
//
//			[ Captures ] < Template Parameters > ( Parameters ) Specifiers Exception Attributes -> ReturnType Requires { Function Body }
//
// But mostly the following is used :
//
//			[ Captures ] ( Parameters ) -> ReturnType { Function Body }
//


// *************************************************************************   Capturing Variables   ************************************************************************ //


// This provides a way to access information from outside the lambda expression given arguments and local variables. Syntax :
//
//			void func( const int& rockie )
//			{
//				std::transform( [rockie]( int fool ) { rockie = 0; } )
//			}
//
// Capture can be done in the following ways :
//
//	1. [&variable] - captures by reference
//	2. [&] - captures all variables used in the lambda by reference
//	3. [=] - captures all variables used in the lambda by value
//	4. [&, variable] - captures variables by reference, beside variable by value
//	5. [=, &variable] - captures variables by value, besides variable by reference
//
// The generated operator() is declared constant by default, with the implication that captures will be constant when they are accessed by 
// default. This can be changed using the mutable request that operator() will not be constant. Lambda expressions without a capture have 
// an implicit conversion to function pointers type. The conversion function is constant always.
//
// A lambda expression can use a variable without capturing it if the variable is :
//
//	1. Non local variable or has static or thread local storage duration ( in which case the variable can not be captured )
//	2. A reference that has been initialized with a constant expression
//
// A lambda expression can read the value of a variable without capturing it if the variable is :
//
//	1. Has constant non volatile integral or enumeration type and has been initialized with a constant expression
//	2. Constant expression and has no mutable members


// *************************************************************************   Template Parameters   ************************************************************************ //


// A template parameter list used to provide names to the template parameters of a generic lambda. Like in template declaration, the template parameter list may
// be followed by an optional requires clause, which specifies the constraints on the template arguments. If provided the template parameter list cannot be empty
// ( <> is not allowed )
//


// *****************************************************************************   Parameters   ***************************************************************************** //


// The list of parameters, as in any regular function!


// *****************************************************************************   Specifiers   ***************************************************************************** //


// Optional sequence of specifiers. The possibilites are :
//
//	1. mutable - allows body to modify the parameters captured by copy, and to call their constant member functions
//	2. constexpr - explicitly specifies that the function call operator is a constant expression function. When the specifier is not present. the function
//   			   call operator will be constant expression anyway, if it happens to satisfy all constant exprssion function requirements. A function
//				   declared as constant expression is implicitly and inline function
//	3. consteval - specifies that the function call operator is an immediate function. This can not be used with constant expression also


// *****************************************************************************   Exception   ****************************************************************************** //


// Provides the exception specification or the noexcept clause for opertor() of the closure type


// *****************************************************************************   Attributes   ***************************************************************************** //


// Provides the attribute specification for the type of the function call operator of the closure type


// ****************************************************************************   Return Types   **************************************************************************** //


// In simple cases the return type of the lambda is deduced by the compiler, but it should not be used. The return type should appear for clearity. The return 
// type is specified as follows :
//
//			[] ( int Solo ) -> int { Function Body }
//



// ************************************************************************************************************************************************************************** //
// **													         	CONVERT MEMORY TYPE SIZES TO SIZE IN BYTES                                                             ** //
// ************************************************************************************************************************************************************************** //



// Use this function to convert KiloByte into size in single bytes
constexpr inline LargestUnsignedInteger KiloByte( const LargestUnsignedInteger SizeInKiloByte )
{
	// To convert between kilobytes to single bytes the following method is used :
	//
	//		KiloByte = 1024 Bytes
	//
	// Then,
	//
	//		6 KiloByte = 6 * 1024 Bytes

	// Multiply the given size in KiloByte by 1024, and return the result
	return ( SizeInKiloByte * 1024UL );
}


// Use this function to convert MegaByte into size in single bytes
constexpr inline LargestUnsignedInteger MegaByte( const LargestUnsignedInteger SizeInMegaByte )
{
	// To convert between MegaBytes to single bytes the following method is used :
	//
	//		MegaByte = 1024 KiloByte = 1024 * 1024 Bytes
	//
	// Then,
	//
	//		6 MegaByte = 6 * ( 1024 * 1024 ) Bytes

	// Multiply the given size in MegaByte by 1024 twice, and return the result
	return ( SizeInMegaByte * ( 1024UL * 1024UL ) );
}


// Use this function to convert GigaByte into size in single bytes
constexpr inline LargestUnsignedInteger GigaByte( const LargestUnsignedInteger SizeInGigaByte )
{
	// To convert between MegaBytes to single bytes the following method is used :
	//
	//		GigaByte = 1024 MegaByte = ( 1024 * 1024 ) KiloByte = ( 1024 * 1024 * 1024 ) Bytes
	//
	// Then,
	//
	//		6 GigaByte = 6 * ( 1024 * 1024 * 1024 ) Bytes

	// Multiply the given size in GigaByte by 1024 three times, and return the result
	return ( SizeInGigaByte * ( 1024UL * 1024UL * 1024UL ) );
}



// ************************************************************************************************************************************************************************** //
// **													         				FLOATING POINT NUMBERS                                                                     ** //
// ************************************************************************************************************************************************************************** //



// ******************************************************************************   Overview   ****************************************************************************** //


// Real numbers are :
//
//		pi = 3.14159265...
//		e =  2.71828...
//
// Scentific notation has a single digit to the left of the decimal point. A number in scientific notation with no leading 0's is called 
// 'normalised number' :
//
//		1.0 * 10 power 8
//
// Not in normalised form :
//
//		0.1 * 10 power -2
//		10.0 * 10 power -9
//
// Binary numbers can also be represented in scientific notation :
//
//		1.0 * 2 power -3
//
// Computer arithemtic that supports such numbers is called 'Floating point'.
//
// The form is : 
//
//		1.xxx... * 2 power yyy...
//
// Using normalised scientific notation :
//
//	1. Simplifies the exchange of data that includes floating point numbers
//	2. Simplifies the arithemetic algorithm to know that the numbers will always be in this form
//	3. Increase the accuracy of the numbers that can be stored in a word, since each unnecessary leading 0 is replaced by another significant digit
//     to the right of the decimal point


// **************************************************************   Representation of floating point numbers   ************************************************************** //


// In general :
//
//		( -1 power Sign ) * Mantissa * ( 2 power Exponent )
//
//		bit 31 ( 1 bit )             -   Sign
//		bits 23-30 ( 8 bits )        -   Exponent
//		bits 0-22 ( 23 bits )        -   Mantissa
//
// A single precision floating point number occupies 32 bits, so there is a compromise between the size of the mantissa and the size of the
// exponent. These chosen sizes provide a range of approximately :
//
//		negative or positive [ ( 10 power -38 ), ( 10 power 38 ) ]
//
// - Overflow - the exponent is too large to be represented in the exponent field
// - Underflow - the number is too small to be represented in the exponent field
//
// To reduce the chances of underflow or overflow, the double precision floating point can be used, which consists of 64 bits :
//
//		bit 63 ( 1 bit )             -   Sign
//		bits 52-62 ( 11 bits )       -   Exponent
//		bits 0-51 ( 52 bits )        -   Mantissa
//
// Providing a range of :
//
//		negative or positive [ ( 10 power -308 ), ( 10 power 308 ) ]


// ******************************************************************   IEEE 754 floating point standard   ****************************************************************** //


// The above formats are described in this standard.
//
// Since the mantissa is always '1.xxxxxxx...' in the normalised form, no need to represent the leading 1. So, effectively :
//
//	- Single precision mantissa  ->  1 bit + 23 bits
//	- Double precision mantissa  ->  1 bit + 52 bits
//
// Since zero '0.0' has no leading 1, to distinguish it from others, it is given the reserved bitpattern all 0s for the exponent so that hardware 
// won't attach a leading 1 to it. Thus :
//
//	- Zero ( 0.0 ) = 0000000...0000000
//	
//	- Other numbers = ( -1 power Sign ) * ( 1 + Mantissa ) * ( 2 power Exponent )
//
// If the mantissa bits are numbered from left to right :
//
//		mantissa = m1 * ( 2 power -1 ) + m2 * ( 2 power -2 ) + m3 * ( 2 power -3 ) ...
//
// Negative exponents could pose a problem in comparisons, for example ( with two's complement ) :
//
//									sign   exponent           mantissa
//
//			1.0 * ( 2 power -1 )     0     11111111    000000 00000000 00000000
//			1.0 * ( 2 power +1 )     0     00000001    000000 00000000 00000000
//
// With this representation, the first exponent shows a 'larger' binary number, making direct comparisons more difficult. To avoid this 'Biased notation'
// is used for exponents. If the real exponent of a number is 'X' then it represented as 'X + bias'. IEEE single precision used a bias of 127. therefore
// an exponent will be represented as :
//
//			-1 is represented as -> -1 + 127 = 126 = 01111110
//			0 is represented as -> 0 + 127 = 127 = 01111111
//			-1 is represented as -> +1 + 127 = 128 = 10000000
//			-1 is represented as -> +5 + 127 = 132 = 10000100
//
// So the actual exponent is found by subtracting the bias from the stored exponent. To conclude :
//
//		( -1 power Sign ) * ( 1.0 + Mantissa ) * ( 2 power ( Exponent - bias ) )


// **********************************************************************   floating point addition   *********************************************************************** //


// Add the following two decimal numbers in scientific notation :
//
//						[ 8.70 * ( 10 power -1 ) ] + [ 9.95 * ( 10 power 1 ) ]
//
// 1. Rewrite the smaller number such that its exponent matches with the exponent of the large number :
//
//						[ 8.70 * ( 10 power -1 ) ] = [ 0.087 * ( 10 power 1 ) ]   
//
// 2. Add the mantissas :
//
//						9.95 + 0.087 = 10.037
//
// 3. Put the result in normalised form :
//
//						[ 10.037 * ( 10 power 1 ) ] = [ 1.0037 * ( 10 power 2 ) ]  ( shift mantissa, adjust exponent )
//
// 4. Check for overflow or underflow of the exponent after normalisation
//
// 5. Round the result - if the mantissa does not fit in the space reserved for it, it has to be rounded off. For example, if only 4 digits are
//    allowed for the mantissa :
//
//						[ 1.0037 * ( 10 power 2 ) ] -> [ 1.004 * ( 10 power 2 ) ]


// *******************************************************************   floating point multiplication   ******************************************************************** //


// Add the following two decimal numbers in scientific notation :
//
//						[ 1.110 * ( 10 power 10 ) ] + [ 9.200 * ( 10 power -5 ) ]
//
// 1. Add the exponents to find the result exponent :
//
//						10 + ( -5 ) = 5
//
// 2. If the addition was done with biased exponents, bias will be added twice, thererfore it needs to be subtracted once to compensate :
//
//						[ 10 + 127 ] + [ -5 + 127 ] = 259 - 127 = 132
//
// 3. Multiply the mantissas :
//
//						1.110 * 9.200 = 10.212000 -> only 3 digits behind the decimal point can be stord so the result - [ 10.212 * 10 power 5 ]
//
// 3. Put the result in normalised form :
//
//						[ 10.212 * 10 power 5 ] = [ 1.0212 * 10 power 6 ]  ( shift mantissa, adjust exponent )
//
// 4. Check for overflow or underflow of the exponent after normalisation
//
// 5. Round the result - if the mantissa does not fit in the space reserved for it, it has to be rounded off. For example, if only 4 digits are
//    allowed for the mantissa :
//
//						[ 1.0212 * 10 power 6 ] -> [ 1.021 * 10 power 6 ]



// ************************************************************************************************************************************************************************** //
// **														   	   OBJECTS WITH SPECIAL MEANING FOR CONSTRUCTORS                                                           ** //
// ************************************************************************************************************************************************************************** //



// This object will passed to constructor of templated objects, that manage a resource and the arguments required to construct it are not known.
// This is needed to ensure the correct constructor will be called
class BuildResourceFromArguments
{};

inline BuildResourceFromArguments buildResourceFromArguments;



// ************************************************************************************************************************************************************************** //
// **														   			  	    UNUSED RETURN VALUE                                                                        ** //
// ************************************************************************************************************************************************************************** //



// The attribute no discard can be used to indicate that the return value of a function must be used. If the return value is ignored, the
// the compiler should give a warning. The attribute can be added to :
//
//		1. Function
//		2. Type
//
#define EnsureRetrunValueIsUsed [[nodiscard]]



// ************************************************************************************************************************************************************************** //
// **														   			  	    UNUSED RETURN VALUE                                                                        ** //
// ************************************************************************************************************************************************************************** //



// This function should be used for cases where a function needs to perform differently during compile time and run time
//
inline constexpr Boolean IsEvaluatedDuringCompileTime()
{
	// Check if the function is used druring compile time or run time
	if consteval
	{
		// The function is called during compile time
		return ( true );
	}
	else
	{
		// The function is called during run time
		return ( false );		
	}
}



// ************************************************************************************************************************************************************************** //
// **														   				   INLINE FILES ( .inl )                                                                       ** //
// ************************************************************************************************************************************************************************** //



// '.inl' files are never mandatory and have no special significance to the compiler. It is just a way of structuring the code that provides a
// hint to the humans that might read it.
//
// Files with inline content mainly used for the following purposes :
//
//	1. For definitions of inline functions
//	2. For definitions of function templates
//
// One of the work flow with inline files is to put the declarations of the functions in a header file, implement all the functions in the inline
// file, and include in the bottom of the header file the inline file. This way the implementation is seperated from the declarations.
//
// There are a few cases where inline files are a necessity, and one of them is when a dependency cycle between header code.
//
// For example :
//
//		Header file "Mother.hpp" :
//
//			class Mother
//			{
//				inline void DoSomething()
//				{ 
//					... 
//				}
//
//				inline void DoSomething( Father& father )
//				{
//					father.DoSomething();
//				}
//			}
//
//		Header file "Father.hpp" :
//
//			class Father
//			{
//				inline void DoSomething()
//				{ 
//					... 
//				}
//
//				inline void DoSomething( Mother& mother )
//				{
//					mother.DoSomething();
//				}
//			}
//		
// This does not compile in any way, including using forward declaration. The solution is then to break down definition and implementation into two.
//
// This will look like :
//
//		Header file "Mother.hpp" :
//
//			class Father;
//
//			class Mother
//			{
//				inline void DoSomething();
//				inline void DoSomething( Father& father );
//			}
//
//		Inline file "Mother.inl" :
//
//			#include <Mother.hpp>
//			#include <Father.hpp>
//			
//			inline void Mother::DoSomething()
//			{
//				...
//			}
//
//			inline void Mother::DoSomething( Father& father )
//			{
//				father.DoSomething();
//			}
//
//		Header file "Father.hpp" :
//
//			class Mother;
//
//			class Father
//			{
//				inline void DoSomething();
//				inline void DoSomething( Mother& mother );
//			}
//
//		Inline file "Father.inl" :
//
//			#include <Father.hpp>
//			#include <Mother.hpp>
//			
//			inline void Father::DoSomething()
//			{
//				...
//			}
//
//			inline void Father::DoSomething( Mother& mother )
//			{
//				mother.DoSomething();
//			}
//
// This way the required inline file can be included and it will work!



// ************************************************************************************************************************************************************************** //
// **												   						ASCII STRING SIZE                                                                              ** //
// ************************************************************************************************************************************************************************** //



// Method Information :
//
//  Description :
//
//      Use this method to find the size of an ascii string
//
//  Required arguments :
//
//      User information needed :
//
//			asciiStringPointer - a pointer to the memory address of the ascii string
//
//      Information returned to the user :
//
//          NONE
//
//  Return value :
//
//		The size of the ascii string. If the given pointer is NULL or the size of the string is larger then 1 million characters it will 
//		return 0
//
//  Expectations :
//
//      1. The given pointer is not NULL	
//		2. The string ends with a null terminator ( 0 )
//		3.
//
//  Possible errors :
//
//      They will come
//
inline LargestUnsignedInteger AsciiStringSize( const AsciiCharacter* const asciiStringPointer )
{
    // Check if the given pointer is NULL
    if ( asciiStringPointer == nullptr )
    {
        // The given pointer is NULL 

        // Notify the user of the error
        return ( 0UL );
    }

    // Create an object to store the length of the string
    LargestUnsignedInteger asciiStringSize = 0UL;

    // Store the a copy of the pointer
    const AsciiCharacter* asciiStringPointerCopy = asciiStringPointer;

    // Loop until the error message is exhausted to find the size, use the error message size as index to the error message string
    while ( *asciiStringPointerCopy != 0 )
    {
        // Increase the error message size by 1
        asciiStringSize += 1UL;

        // Check that the string size is not larger then 1 million
        if ( asciiStringSize > 1000000UL )
        {
            // The string might be without a null terminator

            // Notify the user of the error
            return ( 0UL );     
        }

        // Advance the pointer to the next entry
        asciiStringPointerCopy += 1UL;
    }

    // Return the size of the string
    return ( asciiStringSize );
}



}  //  namespace Universe
