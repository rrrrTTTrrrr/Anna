#include <iostream>


#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/BuiltIn/TypeCheck_BuiltInType/TypeCheck_BuiltInType.hpp"


#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/FunctionalityBranch/Level_0/Content/Error/Exception/Exception.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"


using namespace std;
using namespace Universe;


int main()
{

    try
    {


        Assert_MACRO( ( TypeCheck_BuiltInType< int* >::Result() == true ), "1" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const int* >::Result() == true ), "2" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const int* const >::Result() == true ), "3" )
        Assert_MACRO( ( TypeCheck_BuiltInType< int&& >::Result() == true ), "4" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const int&& >::Result() == true ), "5" )
        Assert_MACRO( ( TypeCheck_BuiltInType< int& >::Result() == true ), "6" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const int& >::Result() == true ), "7" )
        Assert_MACRO( ( TypeCheck_BuiltInType< volatile int& >::Result() == true ), "8" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const volatile int& >::Result() == true ), "9" )
        Assert_MACRO( ( TypeCheck_BuiltInType< volatile int&& >::Result() == true ), "10" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const volatile int&& >::Result() == true ), "11" )
        Assert_MACRO( ( TypeCheck_BuiltInType< UnsignedInteger8bits >::Result() == true ), "12" )
        Assert_MACRO( ( TypeCheck_BuiltInType< UnsignedInteger16bits >::Result() == true ), "13" )
        Assert_MACRO( ( TypeCheck_BuiltInType< UnsignedInteger32bits >::Result() == true ), "14" )
        Assert_MACRO( ( TypeCheck_BuiltInType< UnsignedInteger64bits >::Result() == true ), "15" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const UnsignedInteger8bits >::Result() == true ), "16" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const UnsignedInteger16bits >::Result() == true ), "17" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const UnsignedInteger32bits >::Result() == true ), "18" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const UnsignedInteger64bits >::Result() == true ), "19" )
        Assert_MACRO( ( TypeCheck_BuiltInType< SignedInteger8bits >::Result() == true ), "20" )
        Assert_MACRO( ( TypeCheck_BuiltInType< SignedInteger16bits >::Result() == true ), "21" )
        Assert_MACRO( ( TypeCheck_BuiltInType< SignedInteger32bits >::Result() == true ), "22" )
        Assert_MACRO( ( TypeCheck_BuiltInType< SignedInteger64bits >::Result() == true ), "23" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const SignedInteger8bits >::Result() == true ), "24" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const SignedInteger16bits >::Result() == true ), "25" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const SignedInteger32bits >::Result() == true ), "26" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const SignedInteger64bits >::Result() == true ), "27" )
        Assert_MACRO( ( TypeCheck_BuiltInType< Boolean >::Result() == true ), "28" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const Boolean >::Result() == true ), "29" )
        Assert_MACRO( ( TypeCheck_BuiltInType< FloatingPoint >::Result() == true ), "30" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const FloatingPoint >::Result() == true ), "31" )
        Assert_MACRO( ( TypeCheck_BuiltInType< DoublePrecisionFloatingPoint >::Result() == true ), "32" )
        Assert_MACRO( ( TypeCheck_BuiltInType< const DoublePrecisionFloatingPoint >::Result() == true ), "33" )

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


