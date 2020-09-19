#include <iostream> 


using namespace std;


// const char buffer[] = "int";


// template< const char* ptr >
//  func()
// {
//   std::cout << ptr << std::endl;
// }
	#define ss( a, ... ) a##ss( __VA_ARGS__ )



	//
	//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOMEDEVIL
	//		
	#define Concatenate2piecesOfText_MACRO( TextBeginning, TextEnd ) TextBeginning ## TextEnd


	// Use this macro to concatenate 3 pieces of text :
	//
	//		TextBeginning = HANDSOME, TextMiddle = AND HOT, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOMEHOTDEVIL
	//		
	#define Concatenate3piecesOfText_MACRO( TextBeginning, TextMiddle, TextEnd ) TextBeginning ## TextEnd ## TextEnd


	// Use this macro to concatenate 4 pieces of text :
	//
	//		TextBeginning = HANDSOME, TextLowerMiddle = HOT, TextHigherMiddle = LIKE, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOMEHOTLIKEDEVIL
	//		
	#define Concatenate4piecesOfText_MACRO( TextBeginning, TextLowerMiddle, TextHigherMiddle, TextEnd ) TextBeginning ## TextLowerMiddle ## TextHigherMiddle ## TextEnd

int main()  
{

	try
    {

  		// func<buffer>();

  		std::cout << Concatenate3piecesOfText_MACRO( hhhhhhhhh, hhhhhhhhh, hhhhhhhhh ) << std::endl;
  		std::cout << Concatenate4piecesOfText_MACRO( hhhhhhhhh, hhhhhhhhh, hhhhhhhhh, lOLLLLLLLLLLLLLLLLL ) << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}