#include <iostream> 

using namespace std;


template< int NumberOfArgumentsMinusOne, typename ExposedType, typename... TemplateArguments >
class TypesHolder
{
public:

    // Create a type defintion of the current exposed type
    using Type = typename TypesHolder< NumberOfArgumentsMinusOne - 1, TemplateArguments... >::Type;

};


template< typename ExposedType, typename... TemplateArguments >
class TypesHolder< 0, ExposedType, TemplateArguments... >
{
public:

    // Create a type defintion of the current exposed type
    using Type = ExposedType;

};



template< typename... args >
void Foo()
{
	typename TypesHolder< 1, args... >::Type gg = 89999999999;

	std::cout << gg << std::endl;
}


template< typename... args >
class Test
{
public:
	template< int n >
	typename TypesHolder< n, args... >::Type GetTypeWithValue()
	{
		typename TypesHolder< n, args... >::Type ii = 8999.897;
		return ( ii );
	}


};


int main()  
{

	try
    {
    	Foo< int, long, double, int >();

    	Test< double, int, int > plk;

    	auto ff = plk.GetTypeWithValue< 0 >();

    	std::cout << ff << std::endl;


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}