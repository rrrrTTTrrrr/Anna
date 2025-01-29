namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//     Use this object to create an incrementing integer sequence object. The incrementing integer sequence is created in compile time. The compiler will generate a
//     copy starting from the number of integers minus one only, and in each recurssion another number, smaller by 1, is added and another copy of the object is created 
//     until the number 0 is added which ends the recurssion in the next round
//
//  Description :
//
//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
//
// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		3. Template arguments :
//
//          1. NumberOfIntegers - an integer containing the number of integers in the incrementing integer sequence
//          2. Integers - a parameter pack that will be used to contain the incrementing integer sequence
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< UnsignedInteger64bits NumberOfIntegers, UnsignedInteger64bits... Integers >
class IncrementingIntegerSequenceGenerator NotForInheritance
{
public:


    // Create a type definition for this object
    using SelfType = IncrementingIntegerSequenceGenerator< NumberOfIntegers, Integers... >;

    // Create a type defintion of the type defintion inside this object only with the next lower value in the sequence
    using Type = typename IncrementingIntegerSequenceGenerator< NumberOfIntegers - 1UL, NumberOfIntegers - 1UL, Integers... >::Type;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
    //
    //  Description :
	//
	//		Default Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline IncrementingIntegerSequenceGenerator() = default;


	// Method Information :
	//
	//  Description :
	//
	//		Destructor, does not throw
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ~IncrementingIntegerSequenceGenerator() = default;


private:


    // Disable all copy and move related methods
    DisableCopyAndMove( IncrementingIntegerSequenceGenerator );


};  //  Class IncrementingIntegerSequenceGenerator



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - NumberOfIntegers = 0   **************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Template Class Information :
//
//  Purpose :
//
//      Template specialization for the lowest value required in the incrementing integer sequence. When the the number of integers is 0 this object
//      will bec used
//
//  Description :
//
//      1. Template arguments :
//
//          1. UnsignedInteger64bits - the type of integers in the incrementing integer sequence
//          2. Integers - this will contain the incrementing integer sequence
//
//  Excpectations :
//
//      NONE
//
//  Possible errors :
//
//      They will come
//
template< UnsignedInteger64bits... Integers >
class IncrementingIntegerSequenceGenerator< 0, Integers... >
{
public:


    // Create a type definition for this object
    using SelfType = IncrementingIntegerSequenceGenerator< 0, Integers... >;

    // Create a templated type defintion of the required incrementing integer sequence
    using Type = IncrementingIntegerSequenceHolder< Integers... >;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
    //
    //  Description :
	//
	//		Default Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline IncrementingIntegerSequenceGenerator() = default;


	// Method Information :
	//
	//  Description :
	//
	//		Destructor, does not throw
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline ~IncrementingIntegerSequenceGenerator() = default;


private:


    // Disable all copy and move related methods
    DisableCopyAndMove( IncrementingIntegerSequenceGenerator );

};



// Create a templated type defintion of the incrementing integer sequence. The user should only use this type defintion to create incrementing integer sequences
template< UnsignedInteger64bits NumberOfIntegers >
using IncrementingIntegerSequence = typename IncrementingIntegerSequenceGenerator< NumberOfIntegers >::Type;



// Usage example - unpacking tuple :
//
// The first thing is to create a wrapping function that accept a tuple :
//
//		void WrapperToHideIncrementingIntegerSequence( const Tuple< UnsignedInteger64bits, UnsignedInteger64bits >& instance )
//		{
//			return FunctionThatUnpacksTuple( instance, IncrementingIntegerSequence< 2 >{} ); 
//		}
//
//		template< typename... ArgumentIndices >
//		void FunctionThatUnpacksTuple( const Tuple< UnsignedInteger64bits, UnsignedInteger64bits >& instance, IncrementingIntegerSequenceHolder< ArgumentIndices... > )
//		{
//			Function( instance.template Entry< ArgumentIndices >()... );
//		}
//
//		void Function( UnsignedInteger64bits first, UnsignedInteger64bits second )
//		{	
//			std::cout << "First - " << first << " and the Second - " << second;
//		}
//
// The trick is the compiler automatically deduces the argument indices from the incrementing integer sequence created!



}  //  Namespace Universe