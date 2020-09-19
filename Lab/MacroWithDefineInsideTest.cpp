#include <iostream> 


using namespace std;
class Test
{
public:



private:

};  //  class Test



// #define Lord( s ) \#define k##s s

// Lord( "Jump" )
#define Concatenate2piecesOfText_MACRO( TextBeginning, TextEnd ) TextBeginning ## TextEnd
#define CreateStringByConcatenate2piecesOfTextAndWrapWithQuatationMarks_MACRO( TextBeginning, TextEnd ) CreateStringBySurroundWithQuatationMarks_MACRO( Concatenate2piecesOfText_MACRO( TextBeginning, TextEnd ) )

#define CreateStringBySurroundWithQuatationMarks_MACRO( ... ) #__VA_ARGS__

#define Loosser "/home/rrrrtttrrrr"

#define RootDirectory_MACRO Loosser/CreateStringBySurroundWithQuatationMarks_MACRO( /Anna/AnnaVersions/Anna_1083/Root/Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp )

#include RootDirectory_MACRO


#define Kok <string>

#include Kok



int main()  
{

	try
    {

    	//std::cout << kJump << std::endl;


    	std::string kk( "Lofffff" );

    	std::cout << kk << std::endl;

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}