#include <iostream>


#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_NonConstantNonVolatile_LvalueReference/TypeCheck_NonConstantNonVolatile_LvalueReference.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_ConstantNonVolatile_LvalueReference/TypeCheck_ConstantNonVolatile_LvalueReference.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_NonConstant_LvalueReference/TypeCheck_NonConstant_LvalueReference.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_NonConstantNonVolatile_RvalueReference/TypeCheck_NonConstantNonVolatile_RvalueReference.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_ConstantNonVolatile_RvalueReference/TypeCheck_ConstantNonVolatile_RvalueReference.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_NonConstant_RvalueReference/TypeCheck_NonConstant_RvalueReference.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_LvalueReference/TypeCheck_LvalueReference.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_RvalueReference/TypeCheck_RvalueReference.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_Constant_Reference/TypeCheck_Constant_Reference.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_NonConstant_Reference/TypeCheck_NonConstant_Reference.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Reference/TypeCheck_Reference/TypeCheck_Reference.hpp"


#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/FunctionalityBranch/Level_0/Content/Error/Exception/Exception.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"


using namespace std;
using namespace Universe;


int main()
{

    try
    {


        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< const int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< const int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< const int* const >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< const int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< const int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< const volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< volatile int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_LvalueReference< const volatile int&& >::Result() == false ), "Here mate" )


        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< const int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< const int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< const int* const >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< const int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< const int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< const volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< volatile int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_LvalueReference< const volatile int&& >::Result() == false ), "Here mate" )


        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< const int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< const int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< const int* const >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< const int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< const int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< volatile int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< const volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< volatile int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_LvalueReference< const volatile int&& >::Result() == false ), "Here mate" )


        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< const int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< const int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< const int* const >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< const int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< const int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< const volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< volatile int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstantNonVolatile_RvalueReference< const volatile int&& >::Result() == false ), "Here mate" )


        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< const int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< const int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< const int* const >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< const int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< const int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< const volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< volatile int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_ConstantNonVolatile_RvalueReference< const volatile int&& >::Result() == false ), "Here mate" )


        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< const int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< const int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< const int* const >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< const int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< const int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< const volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< volatile int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_RvalueReference< const volatile int&& >::Result() == false ), "Here mate" )


        Assert_MACRO( ( TypeCheck_LvalueReference< int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< const int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< const int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< const int* const >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< const int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< const int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< volatile int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< const volatile int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< volatile int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_LvalueReference< const volatile int&& >::Result() == false ), "Here mate" )


        Assert_MACRO( ( TypeCheck_RvalueReference< int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< const int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< const int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< const int* const >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< const int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< const int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< const volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< volatile int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_RvalueReference< const volatile int&& >::Result() == true ), "Here mate" )


        Assert_MACRO( ( TypeCheck_Constant_Reference< int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< const int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< const int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< const int* const >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< const int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< const int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< const volatile int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< volatile int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Constant_Reference< const volatile int&& >::Result() == true ), "Here mate" )


        Assert_MACRO( ( TypeCheck_NonConstant_Reference< int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< const int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< const int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< const int* const >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< const int&& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< const int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< volatile int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< const volatile int& >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< volatile int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_NonConstant_Reference< const volatile int&& >::Result() == false ), "Here mate" )


        Assert_MACRO( ( TypeCheck_Reference< int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< const int >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< const int* >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< const int* const >::Result() == false ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< const int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< const int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< volatile int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< const volatile int& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< volatile int&& >::Result() == true ), "Here mate" )
        Assert_MACRO( ( TypeCheck_Reference< const volatile int&& >::Result() == true ), "Here mate" )


    }
    catch ( const Error::Exception& exception )
    {
    	exception.TellMe();
    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}


