// namespace Universe
// {


// namespace Random
// {


// namespace CompileTimeGenerator
// {



// // A linear congruential generator ( LCG ) is an algorithm that yields a sequence of pseudo randomized numbers calculated with a discontinuous
// // piecewise linear equation. The method represents one of the oldest and best known pseudorandom number generator algorithms. The generator
// // is defined by the recurrence relation :
// //
// //		nextRandomValue = ( multiplier * previousRandomValue + increment ) % modulusValue
// //
// // Under the following conditions :
// //
// //	1. modulusValue must be larger than 0
// //	2. multiplier must be smaller than the modulusValue
// //	3. increment must be smaller than the modulusValue
// //	4. The first value ( seed ) must be smaller than the modulusValue
// //
// // In case the increment is 0, the generator is often called a multiplicative congruential generator ( MCG ), or Lehmer RNG. The non zero case
// // is called mixed congruential generator.



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
// class InitializeLinearCongruentialGenerator NotForInheritance
// {
// public:


// 	// Create a type definition for this object
// 	using SelfType = InitializeLinearCongruentialGenerator< IntegerType, Seed, Multiplier, Increment, ModulusValue >;


// 	// Create a type definition for the linear congruential generator
// 	using Type = LinearCongruentialGenerator< IntegerType, Seed, Multiplier, Increment, ModulusValue >;

// 	// This object will store the seed as the value
// 	static constexpr IntegerType Value = Seed;


// private:


//     // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
//     NoInstances( InitializeLinearCongruentialGenerator );


// };  //  Class InitializeLinearCongruentialGenerator



// }  //  Namespace CompileTimeGenerator


// }  //  Namespace Random


// }  //  Namespace Universe
