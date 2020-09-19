#ifndef SYSTEMMEMORY_FILESYSTEM_HPP
#define SYSTEMMEMORY_FILESYSTEM_HPP


#include "../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../FunctionalityBranch/Level_0/Level_1/Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../Content/Memory/Platforms/Tree/Tree.hpp"  //  Class Tree
#include "../Content/Metaprogramming/Tuple/Tuple.hpp"  //  Class Tuple
#include "../FunctionalityBranch/Level_0/Content/Random/Generator/Generator.hpp"  //  Class Generator


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{



	// When a type is forward declared, all the compiler knows is that this type exists. It does not know its size, members or methods. This is why its
	// called incomplete type. Therefore, it can not be used to declare a variable, member or base class since the compiler would need the layout of the
	// type. In other words, it can not be used for anything that requires information on the specific type. What can be done is declaring pointer and
	// reference to the incomplete type. The pointer and refernce can act as a variable, argument to a method or as the return type.
	//
	// Forward declarations :
	//
	//  NONE
	//



	// What are aggregates and why they are speical?
	//
	// Formal definition form the C++ standard - an aggregate is an array or a class with no user declared constructors, no private or protected 
	// non static data members, no base classes, and no virtual functions!
	//
	// First of all, any array is an aggregate. A class can also be an aggregate, and although noting is said about structures and unions, they
	// also can be aggregates. In C++ the term class referes to all classes, structures and unions. A class then can only be an aggregate if it
	// satisfies the criteria from the above definitions. What do these criteria imply?
	//
	// 	1. This does not mean an aggregate class cannot have constructors, in fact it can have default consturctor, copy and move constructors as
	//     long as they are implicitly decalred by the compiler, and not explicitly by the user
	//
	// 	2. No private or protected non static data members. It can have many private and protected member functions as well as many private and
	//     protected static data members and member functions as needed and not violate the rules for aggregate classes
	//
	// 	3. An aggregate class can have a user defined copy assignment operator and destructor
	//
	// 	4. An array is an aggregate even if it has non aggregate class type as data
	//
	// Aggregates, unlike non aggregate calsses can be initialized with curly braces '{}'. For exmaple :
	//
	//		UnsignedInteger64bits Array[ size ] = { 1, 2, 3, ... };
	//
	// There are 4 cases :
	//
	//	1. The size is equal to the number of values - all the elements of the array are initialized
	//
	//	2. The size of the array is larger then number of values - only the first entries of the array are initialized with the values and the rest
	//	   if possible are value initialized
	//
	//	3. The size of the array is smaller then number of values - the compiler will issue an error
	//
	//	4. In case the size of the array is not supplied, it is the same as case 1
	//
	// 
	//



	// Class Information :
	//
	//  Purpose :
	//
	//		Artifical Inteligence
	//
	//  Description :
	//
	//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
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
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	class SystemMemory_FileSystem NotForInheritance
	{
	public:


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
		//		Information returned to the user :
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
		inline SystemMemory_FileSystem();


		// Method Information :
		//
		//  Description :
		//
		//		Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
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
		explicit inline SystemMemory_FileSystem();


		// Method Information :
		//
		//  Description :
		//
		//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
		//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
		//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
		//
		//				1.
		//
		//		Information returned to the user :
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
		explicit inline SystemMemory_FileSystem( const Tuple< Type >& arguments );


		// Method Information :
		//
		//  Description :
		//
		//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		    other - a reference to the instance that should be copied
		//
		//		Information returned to the user :
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
		inline SystemMemory_FileSystem( const SystemMemory_FileSystem& other );


		// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
		// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
		// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
		// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
		// macro will be used to add the following methods to each object :
		//
		//		1. Assigenment operator
		//		2. Move constructor
		//		3. Move assigenment operator
		//		4. Reset
		//		5. State
		//
		ObjectInfrastructure_MACRO( SystemMemory_FileSystem )


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		    other - a reference to the instance that should be swapped
		//
		//		Information returned to the user :
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
		inline void Swap( SystemMemory_FileSystem& other );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
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
		inline void Initiate();


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
		//		Information returned to the user :
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
		inline ~SystemMemory_FileSystem();


		// The following methods give access and manipulate the data inside this object :











		// The following methods declare the overloaded operators for the object :


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		    other - a reference to the instance that should be compared with this object
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		Boolean operator==( const SystemMemory_FileSystem& other ) const;


		// Method Information :
		//
		//  Description :
		//
		//		Use this operator to check if the this instance does not match the other
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		    other - a reference to the instance that should be compared with this object
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		1. true - if the 2 instances are not the same
		//		2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean operator!=( const SystemMemory_FileSystem& other ) const;


		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
		// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
		// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to generate a random instance of this object
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			rangeFor - this will be used to limit the possible values of the {} in the random instance
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A random generated instance
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		static inline SystemMemory_FileSystem GenerateRandomInstance( NumericRange< Type > rangeFor = NumericRange< Type >() );


		DEBUG_TOOL(

			// This part of the object is dedicated for testing :


			// Method Information :
			//
			//  Description :
			//
			//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			NONE
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//			NONE
			//
			//  Expectations :
			//
			//		Please let the test pass lord!!
			//
			//  Possible errors :
			//
			//		It says there are no problems, which is even scarier, did I just wrote a working code??
			//
			static void Test() __attribute__ (( __unused__ ));

		)  //  End of debug tool


	private:


		// This object will store all the files currently loaded into the system memory
		Memory::Tree< UnicodeCharacter, File, 26UL > member_filesLoadedToSystemMemory;


		// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program
		// and only destroyed when the program ends. The access to the static member is bound to this object of course


		// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
		// rather help implement it :


		// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
		// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
		// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
		// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
		// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
		// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


	};  //  Class SystemMemory_FileSystem




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































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
	//		Information returned to the user :
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
	inline SystemMemory_FileSystem::SystemMemory_FileSystem() :
	member_state(),
	member_filesLoadedToSystemMemory()
	{}


	// Method Information :
	//
	//  Description :
	//
	//		Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
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
	SystemMemory_FileSystem::SystemMemory_FileSystem() :
	member_state( InstanceState::Ready ),
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		Assert_MACRO( (), "" )

	}


	// Method Information :
	//
	//  Description :
	//
	//		Constructor, to allow creating an instance with the same arguments as the parameterized constructor, just that the arguments will be
	//		wrapped in a tuple, to allow more automatic creation of instances. Each parameterized constructor will have an equivalent constructor
	//		to inokve with a tuple, which will only call the required constructor and unpack the tuple to the arguments inisde
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			arguments - the arguments needed to construct an instance, only wrapped in a tuple. The arguments are :
	//
	//				1.
	//
	//		Information returned to the user :
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
	inline SystemMemory_FileSystem::SystemMemory_FileSystem( const Tuple< Type >& arguments ) :
	SystemMemory_FileSystem( arguments.template Entry< 0 >(), arguments.template Entry< 1 >() )
	{}


	// Method Information :
	//
	//  Description :
	//
	//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
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
	inline SystemMemory_FileSystem::SystemMemory_FileSystem( const SystemMemory_FileSystem& other ) :
	member_state( other.member_state ),
	{}


	// Method Information :
	//
	//  Description :
	//
	//		This method is used to swap the content between this instance and the other one
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		other - a reference to the instance that should be swaped
	//
	//		Information returned to the user :
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
	void SystemMemory_FileSystem::Swap( SystemMemory_FileSystem& other )
	{
	    // Swap betwen the state instances
	    member_state.Swap( other.member_state );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
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
	inline void SystemMemory_FileSystem::Initiate()
	{
	    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
	    // leave this scope it delete the old data if exist
	    SystemMemory_FileSystem instanceCreatedUsingTheRequiredConstructor(  );

	    // Swap between this instance and the temporary instance
	    Swap( instanceCreatedUsingTheRequiredConstructor );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Destructor, does not throw any exceptions
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			NONE
	//
	//		Information returned to the user :
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
	inline SystemMemory_FileSystem::~SystemMemory_FileSystem()
	{
   	    // Check if the object is in default state, then noting needs to be done
   	    ReturnIfExpressionIsTrue_MACRO( member_state.Get() == InstanceState::Default )
	}




































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	Boolean SystemMemory_FileSystem::operator==( const SystemMemory_FileSystem& other ) const
	{
		// Check if both or only one of the instances is in default state
		CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		1. true - if the 2 instances are not the same
	//		2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline Boolean SystemMemory_FileSystem::operator!=( const SystemMemory_FileSystem& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************




































	// Method Information :
	//
	//  Description :
	//
	//      Use this method to generate a random instance of this object
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			rangeFor - this will be used to limit the possible values of the {} in the random instance
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A random generated instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline SystemMemory_FileSystem SystemMemory_FileSystem::GenerateRandomInstance( NumericRange< Type > rangeFor )
	{
		// Create an instance
		SystemMemory_FileSystem randomInstance;

		// Return a copy of the instance
		return ( MOVE( randomInstance ) );
	}




































//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************




































//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************




































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************





































}  //  Namespace Universe



#endif  // SYSTEMMEMORY_FILESYSTEM_HPP