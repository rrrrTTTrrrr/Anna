#include <iostream> 

using namespace std;

template<class t> struct constify { typedef t type; };
template<class t> struct constify<t&> { typedef const t& type; };



	template< typename TYPE >
	class EnsureConstantQualifierIsNotRemovedForReferenceTypes
	{
	public:


        // Create a type definition for the template argument which should stay the same
        using Type = TYPE;


	private:




	};  //  Class EnsureConstantQualifierIsNotRemovedForReferenceTypes


    template< typename TYPE >
    class EnsureConstantQualifierIsNotRemovedForReferenceTypes< TYPE& >
    {
    public:


        // Create a type definition for the template argument which should stay the same
        using Type = const TYPE&;


    private:




    };  //  Class EnsureConstantQualifierIsNotRemovedForReferenceTypes













template< typename tt >
class Test
{
public:

	virtual ~Test() {}

	virtual typename EnsureConstantQualifierIsNotRemovedForReferenceTypes<tt>::Type operator[]( int i ) = 0;

private:

};  //  class Test


template< typename tt >
class Test1 : Test< tt& >
{
public:

	Test1() : m_t(  89 ) {}

	virtual ~Test1() {}


	virtual const tt& operator[]( int ) override { std::cout << "Champ" << std::endl; return( m_t ); }

private:

	int m_t;

};  //  class Test


template< typename tt >
class Test6
{
public:

    virtual ~Test6() {}

    virtual tt& operator[]( int i ) = 0;

private:

};  //  class Test6


template< typename tt >
class Test9 : Test6< tt&& >
{
public:

    Test9() : m_t(  89 ) {}

    virtual ~Test9() {}


    virtual tt& operator[]( int ) override { std::cout << "Champ" << std::endl; return( m_t ); }

private:

    int m_t;

};  //  class Test


template< typename tt >
class Test2
{
public:

    virtual ~Test2() {}

    virtual void Liker( typename EnsureConstantQualifierIsNotRemovedForReferenceTypes<tt>::Type rr ) = 0;

private:

};  //  class Test2


template< typename tt >
class Test3 : Test2< tt& >
{
public:

    Test3() : m_t(  89 ) {}

    virtual ~Test3() {}


    virtual void Liker( const tt& rr ) override { std::cout << rr << std::endl; }

private:

    int m_t;

};  //  class Test



int main()  
{

	try
    {

    	Test1< int > tt;

    	tt[9];

        Test9< int > tt1;

        tt1[9];

        Test3< int > rr;

        rr.Liker( 56 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}