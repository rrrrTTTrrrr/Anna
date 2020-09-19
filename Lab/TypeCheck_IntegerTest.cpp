#include <iostream>


#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/Content/Metaprogramming/Types/TypeCheck/Integers/TypeCheck_Integer/TypeCheck_Integer.hpp"


#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/FunctionalityBranch/Level_0/Content/Error/Exception/Exception.hpp"
#include "/home/rrrrtttrrrr/Anna/AnnaVersions/Anna_1091/Root/FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"


using namespace std;
using namespace Universe;


int main()
{

    try
    {


    	// Call the test method of the object
    	Assert_MACRO( ( TypeCheck_Integer< UnsignedInteger8bits >::Result() == true ), "1" )
        Assert_MACRO( ( TypeCheck_Integer< UnsignedInteger16bits >::Result() == true ), "2" )
        Assert_MACRO( ( TypeCheck_Integer< UnsignedInteger32bits >::Result() == true ), "3" )
        Assert_MACRO( ( TypeCheck_Integer< UnsignedInteger64bits >::Result() == true ), "4" )
        Assert_MACRO( ( TypeCheck_Integer< const UnsignedInteger8bits >::Result() == true ), "5" )
        Assert_MACRO( ( TypeCheck_Integer< const UnsignedInteger16bits >::Result() == true ), "6" )
        Assert_MACRO( ( TypeCheck_Integer< const UnsignedInteger32bits >::Result() == true ), "7" )
        Assert_MACRO( ( TypeCheck_Integer< const UnsignedInteger64bits >::Result() == true ), "8" )
        Assert_MACRO( ( TypeCheck_Integer< SignedInteger8bits >::Result() == true ), "9" )
        Assert_MACRO( ( TypeCheck_Integer< SignedInteger16bits >::Result() == true ), "10" )
        Assert_MACRO( ( TypeCheck_Integer< SignedInteger32bits >::Result() == true ), "11" )
        Assert_MACRO( ( TypeCheck_Integer< SignedInteger64bits >::Result() == true ), "12" )
        Assert_MACRO( ( TypeCheck_Integer< const SignedInteger8bits >::Result() == true ), "13" )
        Assert_MACRO( ( TypeCheck_Integer< const SignedInteger16bits >::Result() == true ), "14" )
        Assert_MACRO( ( TypeCheck_Integer< const SignedInteger32bits >::Result() == true ), "15" )
        Assert_MACRO( ( TypeCheck_Integer< const SignedInteger64bits >::Result() == true ), "16" )
        Assert_MACRO( ( TypeCheck_Integer< Boolean >::Result() == true ), "17" )
        Assert_MACRO( ( TypeCheck_Integer< const Boolean >::Result() == true ), "18" )


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


