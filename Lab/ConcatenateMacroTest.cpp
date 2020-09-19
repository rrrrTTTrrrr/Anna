#include <iostream> 


using namespace std;
class Test
{
public:



private:

};  //  class Test



// #define Got( a, b  ) #a ## Loba

	// Use this macro to concatenate 2 pieces of text :
	//
	//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOMEDEVIL
	//		
	#define Concatenate2piecesOfText_MACRO( TextBeginning, TextEnd ) TextBeginning TextEnd

	// Use this macro to concatenate 3 pieces of text :
	//
	//		TextBeginning = HANDSOME, TextEnd = DEVIL  -->  after MACRO  -->   HANDSOMEDEVIL
	//		
	#define Concatenate3piecesOfText_MACRO( TextBeginning, TextMiddle, TextEnd ) Concatenate2piecesOfText_MACRO( TextBeginning, TextMiddle )TextEnd
	#define Concatenate4piecesOfText_MACRO( TextBeginning, TextLowerMiddle, TextHigherMiddle, TextEnd ) TextBeginning, TextLowerMiddle, TextHigherMiddle ), TextEnd


	#define Lokdkn( a, b, c ,d ) Concatenate4piecesOfText_MACRO( a, b, c, d )
	#define Lokdkn2( a, b, c ,d ) Concatenate4piecesOfText_MACRO( a, b, c, dFUKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK )
	#define Lokdkn3( a, b, c ,d ) Concatenate4piecesOfText_MACRO( a, b, c, _dFUKKKKKKKKKKKKKKKKKKKKKKKKKKKKKKK_ )

	#define LSA( a, b ,c ) "#a"

    	#define Instruction_2arguments_Register_Register_MACRO( InstructionName, SourceRegister, DestinationRegister ) "\"" #InstructionName " " #DestinationRegister "," #SourceRegister "\n\t" "\""

    	#define Instruction_ExtendedInlineAssembly_2arguments_Register_ImmediateValue_MACRO( InstructionName, SourceImmediateValue, DestinationRegister ) "\"" #InstructionName " " #DestinationRegister "," "%[" #SourceImmediateValue "]\n\t" "\""

        #define kkkk( FG, FG1, FG2 ) Instruction_ExtendedInlineAssembly_2arguments_Register_ImmediateValue_MACRO( FG, FG1, FG2 )


    // template<typename _Tp>
    // struct __is_member_pointer_helper : public false_type 
    // {};

    // template<typename _Tp, typename _Cp>
    // struct __is_member_pointer_helper<_Tp _Cp::*> : public true_type 
    // {};

    #define COMMA ,
        #define cookie Lopa
        #define cookie1() Lopaaa

        #define con( a, b ) a ## b
        #define con2( a, b, c ) a ## b ## c
        #define rr( a, b,c ) QUOTE( a b, %[ c ]\n\t )
        #define rrt( a,b,c ) Concatenate4piecesOfText_MACRO( a, b, c, H )

#define SurroundWithQuationMarks_MACRO( Text ) #Text
#define Q(x) #x
#define gg( x,h ) Q( x ## h )
#define QUOTE(x,h) #x , #h

        class test
        {
        public:
            test() {}

            void Lord() {}
            int OO() { return 8; }
        };

        void LL()
        {}


        #define tt11(...) #__VA_ARGS__
        #define tt111(...) tt11(__VA_ARGS__)
        // #define VERSION_STR STRINGIFY(VERSION)

int main()  
{

	try
    {
        tt11( aaaaaaaaaaaaaaa, HHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH )

        
    	cout << Concatenate2piecesOfText_MACRO( Lopa, XXXXXXXX ) << endl;
    	cout << Concatenate3piecesOfText_MACRO( Lopa, XXXXXXXX, BRUTALLLLLLLLLLL ) << endl;
    	cout << Concatenate4piecesOfText_MACRO( hhhhhhhhhhhhhhhhhhhhhhhh, Lopa, XXXXXXXX, BRUTALLLLLLLLLLL ) << endl;
    	cout << Lokdkn( hhhhhhhhhhhhhhhhhhhhhhhh, Lopa, XXXXXXXX, BRUTALLLLLLLLLLL ) << endl;
    	cout << Lokdkn2( hhhhhhhhhhhhhhhhhhhhhhhh, Lopa, XXXXXXXX, BRUTALLLLLLLLLLL ) << endl;
    	cout << Lokdkn3( hhhhhhhhhhhhhhhhhhhhhhhh, Lopa, XXXXXXXX, BRUTALLLLLLLLLLL ) << endl;
    	cout << LSA( yuuu, djkfjkvmd, jkdvjkdjk ) << endl;
    	cout << Instruction_2arguments_Register_Register_MACRO( yuuu, djkfjkvmd, jkdvjkdjk ) << endl;
    	cout << Instruction_ExtendedInlineAssembly_2arguments_Register_ImmediateValue_MACRO( yuuu, djkfjkvmd, jkdvjkdjk ) << endl;
        cout << kkkk( LORD, DAMN, BITCH ) << endl;

        // int* mm = new int( 8 );


        if ( __is_member_pointer_helper< int test::* >::value )
        {
            cout << "YESSSSSSSSSS" << endl;
        }

        cout << endl << endl;


        cout << "\"kkkk\"" << endl;

        // cout << cookie1() << endl;
        // cout << cookie() << endl;
        // cout << cookie1 << endl;
        // cout << cookie << endl;

        cout << con2( ab, ba, ab ) << endl;

        rr( A, B, C )
        rrt( A, B, C )
        SurroundWithQuationMarks_MACRO( cARAMELLL )




    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}