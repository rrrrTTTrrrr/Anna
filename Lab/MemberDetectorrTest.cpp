#include <iostream> 
#include "../Root/Content/Metaprogramming/CommonFunctionality/DetectObjectsMembers/MemberDetector/MemberDetector.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1088/Root/Content/Metaprogramming/CommonFunctionality/DetectObjectsMembers/OperatorDetector/OperatorDetector.hpp"

using namespace std;
using namespace Universe;

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"


CreateMemberDetector( goddir )
CreateMemberDetector( Fuck )
CreateMemberDetector( Lfdrt )
CreateMemberDetector( kort )

CreateOperatorDetector( Add, + )
CreateOperatorDetector( DivideAnd, |= )


class Test
{
public:

	void Fuck() const {}

	void Gmail() {}

	// int operator()() { return ( 9 ); }

    // int operator+() { return ( 9 ); }
    // int operator-() { return ( 9 ); }
    // int operator*() { return ( 9 ); }
    // int operator/( double ) { return ( 9 ); }
    // double operator%( double ) { return ( 9 ); }
    // double operator+=( double ) { return ( 9 ); }
    // double operator-=( double ) { return ( 9 ); }
    // double operator*=( double ) { return ( 9 ); }
    // double operator/=( double ) { return ( 9 ); }
    // double operator%=( double ) { return ( 9 ); }


    // double operator^( double ) { return ( 9 ); }
    // double operator|( double ) { return ( 9 ); }
    // double operator&( double ) { return ( 9 ); }
    // double operator^=( double ) { return ( 9 ); }
    // double operator|=( double ) { return ( 9 ); }
    // double operator&=( double ) { return ( 9 ); }

    // double operator<<( double ) { return ( 9 ); }
    // double operator>>( double ) { return ( 9 ); }
    // double operator<<=( double ) { return ( 9 ); }
    // double operator>>=( double ) { return ( 9 ); }


    // double operator==( double ) { return ( 9 ); }
    // double operator!=( double ) { return ( 9 ); }
    // double operator<( double ) { return ( 9 ); }
    // double operator>( double ) { return ( 9 ); }
    // double operator<=( double ) { return ( 9 ); }
    // double operator>=( double ) { return ( 9 ); }

    // double operator||( double ) { return ( 9 ); }
    // double operator&&( double ) { return ( 9 ); }

    // double operator++( int ) { return ( 9 ); }
    // double operator--( int ) { return ( 9 ); }

    //double operator->() { return ( 9 ); }
    //double operator->*( int ) { return ( 9 ); }

    // double operator()() { return ( 9 ); }
    // double operator[]( int ) { return ( 9 ); }
    // double operator~() { return ( 9 ); }
    // double operator!() { return ( 9 ); }



protected:

	std::string kort;

private:

	int goddir;


};  //  class Test



template<typename T>
struct is_callable {
private:
    typedef char(&yes)[1];
    typedef char(&no)[2];

    struct Fallback { void operator-(); };
    struct Derived : T, Fallback { };

    template<typename U, U> struct Check;

    template<typename>
    static yes test(...);

    template<typename C>
    static no test(Check<void (Fallback::*)(), &C::operator- >*);

public:
    static const bool value = sizeof(test<Derived>(0)) == sizeof(yes);
};


void goo()
{
	std::cout << "Wowwwww" << std::endl;
}




int main()  
{

	try
    {

    	// std::cout << MemberDetector_goddir< Test >() << std::endl;
    	// std::cout << MemberDetector_Fuck< Test >() << std::endl;
    	// std::cout << MemberDetector_Lfdrt< Test >() << std::endl;
    	// std::cout << MemberDetector_kort< Test >() << std::endl;

     //    std::cout << "Lordddddd" << std::endl;
     //    std::cout << OperatorDetector_Add< Test >() << std::endl;
     //    std::cout << "Lordddddd" << std::endl << std::endl;

        std::cout << OperatorDetector_Addition< Test >() << std::endl;

        std::cout << OperatorDetector_AdditionAndAssignment< Test >() << std::endl;

        std::cout << OperatorDetector_Subtraction< Test >() << std::endl;

        std::cout << OperatorDetector_SubtractionAndAssignment< Test >() << std::endl;

        std::cout << OperatorDetector_Multiply< Test >() << std::endl;

        std::cout << OperatorDetector_MultiplyAndAssignment< Test >() << std::endl;

        std::cout << OperatorDetector_Modulo< Test >() << std::endl;

        std::cout << OperatorDetector_ModuloAndAssignment< Test >() << std::endl;



        std::cout << OperatorDetector_XOR< Test >() << std::endl;

        std::cout << OperatorDetector_XorAndAssignment< Test >() << std::endl;

        std::cout << OperatorDetector_AND< Test >() << std::endl;

        std::cout << OperatorDetector_AndAndAssignment< Test >() << std::endl;

        std::cout << OperatorDetector_OR< Test >() << std::endl;

        std::cout << OperatorDetector_OrAndAssignment< Test >() << std::endl;




        std::cout << OperatorDetector_LeftShift< Test >() << std::endl;

        std::cout << OperatorDetector_LeftShiftAndAssignment< Test >() << std::endl;

        std::cout << OperatorDetector_RightShift< Test >() << std::endl;

        std::cout << OperatorDetector_RightShiftAndAssignment< Test >() << std::endl;




        std::cout << OperatorDetector_Equal< Test >() << std::endl;

        std::cout << OperatorDetector_NotEqual< Test >() << std::endl;

        std::cout << OperatorDetector_Larger< Test >() << std::endl;

        std::cout << OperatorDetector_Smaller< Test >() << std::endl;

        std::cout << OperatorDetector_LargerOrEqual< Test >() << std::endl;

        std::cout << OperatorDetector_SmallerOrEqual< Test >() << std::endl;


        std::cout << OperatorDetector_AndCondition< Test >() << std::endl;

        std::cout << OperatorDetector_OrCondition< Test >() << std::endl;

        std::cout << OperatorDetector_IncrementOne< Test >() << std::endl;

        std::cout << OperatorDetector_DecrementOne< Test >() << std::endl;


        //std::cout << OperatorDetector_ss< Test >() << std::endl;

        std::cout << OperatorDetector_DereferencePointerToMember< Test >() << std::endl << std::endl;
        std::cout << OperatorDetector_RoundBrackets< Test >() << std::endl;
        std::cout << OperatorDetector_SquareBrackets< Test >() << std::endl;


    	// std::cout << is_callable< Test >::value << std::endl;


        std::cout << OperatorDetector_LogicalNot< Test >() << std::endl;
        std::cout << OperatorDetector_BitwiseNot< Test >() << std::endl;
        std::cout << OperatorDetector_StructureDereference< Test >() << std::endl;



    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}



#pragma GCC diagnostic pop
