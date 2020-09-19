#include <iostream> 


using namespace std;
class Test
{
public:



private:

};  //  class Test


// #define MM( g, y ) #g #y


// // Use this macro to perform an assembly instruction on 2 registers, when both the content of the registers will be used as a value
// #define Instruction2arguments_Register_Register( InstructionName, SourceRegister, DestinationRegister ) "\""#InstructionName #DestinationRegister, #SourceRegister\n\t"\""


// #define stringify_literal( x ) #x

#define innnnnn( yy ) "\"" #yy "\""
#define GGGG(sequence) "\"" #sequence "\""


#define GGGG1(sequence,SEF,FFG) "\"" #sequence " " #SEF ", " #FFG "\""
#define SURROUND_WITH_QUATION_MARKS( TEXT ) "\"" #TEXT "nt\""



	// Use this macro to concatenate 2 pieces of text :
	//
	//		Text = DEVIL  -->  after MACRO  -->   "DEVIL"
	//		
	#define ConcatenateText_MACRO( TextBeginning, TextEnd ) #TextBeginning#TextEnd



	// Use this macro to concatenate the 2 pieces of text and wrap them in quation marks "" :
	//
	//		TEXT = DEVIL  -->  after MACRO  -->   "DEVIL"
	//		
	#define SurroundWithQuationMarks_MACRO( TextBeginning, TextEnd ) "\"" ConcatenateTextWithSpaceBetween_MACRO( TextBeginning, TextEnd ) "\""


	#define ffff( TextBeginning, TextEnd ) #TextBeginning#TextEnd
	#define ConcatenateTextWithSpaceBetween_MACRO( TextBeginning, TextEnd ) #TextBeginning " " #TextEnd

	#define ThisEvaluatesToNothing " "


	#define ConcatenateTextWithSpaceBetween222_MACRO( Fool, TextBeginning, TextEnd ) #Fool " " #TextBeginning " " #TextEnd


int main()  
{

	try
    {

    	cout << GGGG( Got ) << endl;
    	cout << GGGG1( Got, GOOTY, RAX ) << endl;
    	cout << innnnnn( Got ) << endl;
    	cout << SURROUND_WITH_QUATION_MARKS( Gotlllll ) << endl;
    	cout << SurroundWithQuationMarks_MACRO( KKKKKKKKKKKKK, bbbbbbbbbbbbbbbbb ) << endl;
		cout << ConcatenateTextWithSpaceBetween222_MACRO( ThisEvaluatesToNothing ,ksmvkdlvs, SSSSSSSSSSSSSSSS ) << endl;


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}