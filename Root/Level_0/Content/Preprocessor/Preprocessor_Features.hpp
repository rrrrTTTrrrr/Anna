#ifndef PREPROCESSOR_FEATURES_HPP
#define PREPROCESSOR_FEATURES_HPP


namespace Universe
{




// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   						PREPROCESSOR                                                                           ** //
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
	#define Concatenate2piecesOfText_MACRO( TextBeginning, TextEnd ) TextBeginning ## TextEnd


	// Use this macro to concatenate 3 pieces of text :
	//
	//		TextBeginning = HANDSOME, TextMiddle = AND HOT, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOMEHOTDEVIL
	//		
	#define Concatenate3piecesOfText_MACRO( TextBeginning, TextMiddle, TextEnd ) CTextBeginning ## TextMiddle ## TextEnd


	// Use this macro to concatenate 4 pieces of text :
	//
	//		TextBeginning = HANDSOME, TextLowerMiddle = HOT, TextHigherMiddle = LIKE, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOMEHOTLIKEDEVIL
	//		
	#define Concatenate4piecesOfText_MACRO( TextBeginning, TextLowerMiddle, TextHigherMiddle, TextEnd ) TextBeginning ## TextLowerMiddle ## TextHigherMiddle ## TextEnd


	// Use this macro to concatenate 2 pieces of text with space between them :
	//
	//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOME DEVIL
	//		
	#define ConcatenateTextWithSpaceBetween_MACRO( TextBeginning, TextEnd ) TextBeginning TextEnd


	// Use this macro to concatenate 2 pieces of text with comma between them :
	//
	//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOME,DEVIL
	//		
	#define ConcatenateTextWithCommaBetween_MACRO( TextBeginning, TextEnd ) TextBeginning,TextEnd


	// Use this macro to add quatation marks "" around some text :
	//
	//		Text = DEVIL  -->  after MACRO  -->   "DEVIL"
	//
	// This macro can also deal with text containing comma ','. When providing text with comma to the preprocessor, instead of one argument, it will consider it
	// as 2 arguments. This macro is used to solve this problem
	//
	//		Text = DEVIL,HANDSOME   -->   after MACRO   -->   DEVIL,HANDSOME
	//		
	#define CreateStringBySurroundWithQuatationMarks_MACRO( ... ) #__VA_ARGS__


	// Use this macro to concatenate 2 pieces of text and wrap them with quatation marks :
	//
	//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   "HANDSOMEDEVIL"
	//		
	#define CreateStringByConcatenate2piecesOfTextAndWrapWithQuatationMarks_MACRO( TextBeginning, TextEnd ) CreateStringBySurroundWithQuatationMarks_MACRO( ConcatenateText_MACRO( TextBeginning, TextEnd ) )


	// Use this macro to concatenate 2 pieces of text with space between and wrap them with quatation marks :
	//
	//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   "HANDSOME DEVIL"
	//		
	#define CreateStringByConcatenate2piecesOfTextWithSpaceBetweenAndWrapWithQuatationMarks_MACRO( TextBeginning, TextEnd ) CreateStringBySurroundWithQuatationMarks_MACRO( ConcatenateTextWithSpaceBetween_MACRO( TextBeginning, TextEnd ) )










}  //  namespace Universe


#endif   // PREPROCESSOR_FEATURES_HPP
