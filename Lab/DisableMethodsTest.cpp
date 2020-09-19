#include <iostream> 


using namespace std;

	// Use the following macro to disable the copy constructor and assignment operator. This means that each object that contains this macro, the instances
	// will not be able to be copied
	#define DisableCopyConstructorAndAssignmentOperator( ObjectName ) 		\
																			\
		/* Disable the copy constructor	*/									\
		ObjectName( const ObjectName& other ) = delete;						\
																			\
		/* Disable the assignment operator	*/								\
		ObjectName& operator=( const ObjectName& other ) = delete;			\


	// Use the following macro to disable the move constructor and move assignment operator. This means that each object that contains this macro, the 
		// instances will not be able to be moved
	#define DisableMoveConstructorAndMoveAssignmentOperatorForTemplateObject( ObjectName ) 		\
																								\
		/* Disable the move constructor	*/														\
		ObjectName( ObjectName&& other ) = delete;												\
																								\
		/* Disable the move assignment operator	*/												\
		ObjectName& operator=( ObjectName&& other ) = delete;									\


	// Use the following macro to disable the all copy and move operations. This means that each object that contains this macro, the instances will 
		// not be able to be copied or moved
	#define DisableMoveAndCopy( ObjectName ) 												\
																							\
		/* Disable the copy constructor and assignment operator	*/							\
		DisableCopyConstructorAndAssignmentOperator( ObjectName )							\
																							\
		/* Disable the move constructor and move assignment operator	*/					\
		DisableMoveConstructorAndMoveAssignmentOperatorForTemplateObject( ObjectName )		\


	// Use the following macro to disable the default constructor, destructor, and all copy and move operations. This means that this object will
	// have no instances. It used mainly for objects will only static methods
	#define NoInstances( ObjectName ) 											\
																				\
		/* Disable the default constructor	*/									\
		ObjectName() = delete;													\
																				\
		/* Disable the destructor	*/											\
		~ObjectName() = delete;													\
																				\
		/* Disable all the copy and move related methods of the object */		\
		DisableMoveAndCopy( ObjectName )										\

class Test
{
public:

	Test( int y ) : s(y) {}

	int s;

private:

	DisableCopyConstructorAndAssignmentOperator( Test )

};  //  class Test


class Test1
{
public:

	Test1( int y ) : s(y) {}

	int s;

private:

	DisableMoveConstructorAndMoveAssignmentOperatorForTemplateObject( Test1 )

};  //  class Test

class Test2
{
public:

	int s;

private:

	DisableMoveAndCopy( Test2 )

};  //  class Test

class Test3
{
public:

	int s;

private:

	NoInstances( Test3 )

};  //  class Test

int main()  
{

	try
    {

    	// Test tt( 9 );
    	// Test tt1( tt );
    	// Test tt2( 78 );
    	// tt2 = tt;

    	// Test1 tt3( 9 );
    	// Test1 tt4( std::move( tt3 ) );
    	// Test1 tt5( 78 );
    	// tt3 = std::move( tt5 );

    	Test2 tt( 9 );
    	Test2 tt1( tt );
    	Test2 tt2( 78 );
    	tt2 = tt;

    	Test2 tt3( 9 );
    	Test2 tt4( std::move( tt3 ) );
    	Test2 tt5( 78 );
    	tt3 = std::move( tt5 );

    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}