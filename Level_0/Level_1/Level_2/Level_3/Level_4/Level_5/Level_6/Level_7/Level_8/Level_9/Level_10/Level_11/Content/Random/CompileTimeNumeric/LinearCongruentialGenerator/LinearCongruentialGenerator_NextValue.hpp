// namespace Universe
// {


// namespace Random
// {


// namespace CompileTimeGenerator
// {



// // Class Information :
// //
// //  Purpose :
// //
// //		Artifical Inteligence
// //
// //  Description :
// //
// // 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
// //		   providing 3 keywords :
// //
// //			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
// //						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
// //						member is public all the encapsulation is lost, so it should be avoided in most cases
// //
// //			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
// //						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
// //						   data members
// //
// //			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
// //						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
// //						 part will end with the suffix __Private
// //
// //		2. Template arguments :
// //
// //			1.
// //
// //  Expectations :
// //
// //		NONE
// //
// //  Possible errors :
// //
// //		Too many to count
// //
// template< Concepts::Integer IntegerType, IntegerType Seed, IntegerType Multiplier = 48271, IntegerType Increment = 0, IntegerType ModulusValue = NumericLimits< IntegerType >::Maximum() - 1 >
// class LinearCongruentialGenerator_NextValue NotForInheritance
// {
// public:


// 	// Create a type definition for this object
// 	using SelfType = LinearCongruentialGenerator_NextValue< IntegerType, Seed, Multiplier, Increment, ModulusValue >;


// 	// Create a type definition for the next linear congruential generator
// 	using Type = LinearCongruentialGenerator< IntegerType, ( ( Multiplier * Seed + Increment ) % ModulusValue ), Multiplier, Increment, ModulusValue >;

// 	// This object will use the previous random number to generate the new random number
// 	static constexpr IntegerType Value = ( Multiplier * Seed + Increment ) % ModulusValue;


// private:


//     // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
//     NoInstances( LinearCongruentialGenerator_NextValue );


// };  //  Class LinearCongruentialGenerator_NextValue



// }  //  Namespace CompileTimeGenerator


// }  //  Namespace Random


// }  //  Namespace Universe