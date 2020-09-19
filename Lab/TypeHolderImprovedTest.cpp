#include <iostream> 


using namespace std;


        template< int NumberOfArguments, typename... TemplateArguments >
        class TypeHolder
        {};


        template< typename ExposedType, typename... TemplateArguments >
        class TypeHolder< 1, ExposedType, TemplateArguments... >
        {
        public:

            // Create a typedef of the current exposed type
            typedef ExposedType m_type;

        };


        template< int NumberOfArguments, typename ExposedType, typename... TemplateArguments >
        class TypeHolder< NumberOfArguments, ExposedType, TemplateArguments... >
        {
        public:

            // Create a typedef of the current exposed type
            typedef typename TypeHolder< NumberOfArguments - 1, TemplateArguments... >::m_type m_type;

        };




int main()  
{

	try
    {

    	TypeHolder< 2, int, double >::m_type tt = 67.3;

    	decltype( tt ) m = 44.987;

    	std::cout << m << std::endl;


    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}