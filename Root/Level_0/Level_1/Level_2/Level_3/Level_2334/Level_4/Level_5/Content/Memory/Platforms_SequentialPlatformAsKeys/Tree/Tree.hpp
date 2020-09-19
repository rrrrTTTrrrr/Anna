#ifndef TREE_HPP
#define TREE_HPP


#include "../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "TreeNode/TreeNode.hpp"  //  Class TreeNode
#include "../CommonFunctionality/Interfaces/ManipulateDataUsingSequentialPlatformAsKey_Interface/ManipulateDataUsingSequentialPlatformAsKey_Interface.hpp"  //  Class ManipulateDataUsingSequentialPlatformAsKey_Interface
#include "../../../../../Content/Memory/SequentialPlatforms/SingleLinkedList/SingleLinkedList.hpp"  //  Class SingleLinkedList
#include "../../../../../Content/Memory/SequentialPlatforms/HeapArray/HeapArray.hpp"  //  Class HeapArray
#include "../../../../../Content/Memory/SequentialPlatforms/CommonFunctionality/Interfaces/GetAndSetDataUsingIndices_Interface/GetAndSetDataUsingIndices_Interface.hpp"  //  Class GetAndSetDataUsingIndices_Interface
#include "../../../../../../../../../../Content/Metaprogramming/Types/TypeCheck/BuiltIn/TypeCheck_BuiltInType/TypeCheck_BuiltInType.hpp"  //  Class TypeCheck_BuiltInType
#include "../../../../../../Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../TestBranch/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
#include "../../../../../../../../../../TestBranch/PlatfromGeneralTest/PlatformTest.hpp"  //  Class PlatformTest
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



    namespace Memory
    {



        // The keyword inline is not allowed in declaration of friend template specialization



        // When declaring an outside template method friend with an class template, all instances of that methods no matter the template object are friends with all instances 
        // of the object no matter the template object also here, meaning Read< int > will be friends with operator*< double >, Therefore this two declarations are made. 
        // operator* is declared as a template method using a declared ( but not yet defined ) templated class. Pointer then defines the template instantiation of operator* 
        // matching the template instantiation of Pointer as a friend. Note - no exception specification on purpose, becuase when using templates there is no way of knowing 
        // what the given type will throw



        // Operator "->" :
        //
        //  someClass->Something()
        //
        // Will be converted by the compiler to the following statement :
        //
        //  someClass.operator->()->Something()
        //
        // The first call to the overloaded operator-> gives a pointer of some type which has an accessible member function called Something



        // C++ has two kinds of enumeration :
        //
        //  1. enum classes
        //  2. Plain enums
        //
        //  Here are a couple of examples how to declare them :
        //
        //      enum class Color { red, green, blue }; // enum class
        //      enum Animal { dog, cat, bird, human }; // plain enum 
        //
        // What is the difference between two?
        //
        //  enum classes - enumerator names are local to the enum and their values do not implicitly convert to other types ( like another enum or int )
        //  Plain enums - where enumerator names are in the same scope as the enum and their values implicitly convert to integers and other types
        //
        // Enum classes should be preferred because they cause fewer surprises that could potentially lead to bugs



        // To overload operator "++" for prefix and postfix use the following syntax :
        //
        //      class Number 
        //      {
        //      public:
        //          Number& operator++ ();     // prefix ++: no parameter, returns a reference
        //          Number  operator++ (int);  // postfix ++: dummy parameter, returns a value
        //      };    



        //      When using a pointer in C it can point to various locations in the memory of the program. It can point to location in the stack, heap, data and text segments.
        //      Pointers can only be initialized by taking the address of an exisitng location in the stack, data, text, dynamically allocated heap location, mapped memory
        //      and libraries allocating things. They can set to any of previous, and to other pointers. Pointer is actually an unsigned long integer describing the offset 
        //      from the beginning of the program memory, this allows to C developers to assign an unsigned long integer to a pointer by casting it to the pointer type :
        //
        //          UnsignedInteger64bits address = 0x8080808080808080;
        //
        //          PointerType* pointer = ( PointerType* )address;
        //
        //      C pointers have the following operators :
        //
        //          *pointer                       ->  returns the pointed object
        //          pointer->                      ->  used when the pointed object is a struct
        //          pointer +,- integer            ->  adds or subtracts the integer times the size of the pointed object from the current address, and returns the result
        //          pointer +=,-= integer          ->  adds or subtracts the integer times the size of the pointed object from the current address, and stores the result
        //
        //      Pointers can point to one object or they can point too many contigous objects, and then they have also :
        //
        //          pointer[ integer ]             ->  the same as *( pointer +,- integer ), returns the pointed object in the required address
        //
        //      Pointers are very useful because they only have an address and a type of an object, or in other words the size in bytes of the object, therefore they can be
        //      casted to other type and then the data in the location will be understood differently.
        //
        //      One of the responsibilites of a C developer is to give back all the allocated resources, as fast as possible, for example :
        //
        //          void DoSomething( UnsignedInteger64bits size )
        //          {
        //              PointerType* heapMemory = ( PointerType* )malloc( size );
        //
        //              ...
        //
        //              free( heapMemory );
        //          }
        //
        //      In general then, the resources are allocated in a specific scope, in this case the function DoSomething, and should be deleted when control leaves the scope of
        //      the function. This is very important in big programs that use many resources, because the computer resources are limited after all.
        //
        //      This are the capabilites and required behavior of a C pointer.
        //
        //      Now, let's describe what needs to be added to a C pointer to improve it and create a C++ object from it :
        //
        //      1. The first thing is adding a size to each pointer. This is important to make sure the use of the pointer won't extended further then the required area 
        //      
        //      2. Providing all the operators a pointer have in C
        //
        //      3. To allow the user to give information about different parts of the memory segment, beside a pointer to the beginning



        // Pure virtual methods needs to be redeclared in the derived object because :
        //
        //      1. The standard says so
        //      2. It makes the compiler's work easier by not climbing up the hierarchy to check if such function exists
        //      3. You might want to declare it lower in the hierarchy
        //      4. In order to instantiate the class the compiler must know that this object is concrete



        // User defined conversion :
        //
        // Enables implicit or explicit conversion from class type to another type. Conversion function is a method that has
        // no parameters, no explicit return type, and has the form :
        //
        //          operator TYPE() { method body }
        //
        // For example :
        //
        //          class Jupiter
        //          {
        //          public:
        //
        //              operator int() { return m_int; }
        //
        //          private:
        //
        //              int m_int = 9;
        //          };
        //
        // And then it can be used as :
        //
        //          Jupiter jupiter;
        //
        //          int small = jupiter;



        // Member functions can be called from a constructor or destructor of an abstract class. The effect of making a virtual call to a pure 
        // virtual function directly or indirectly for the object being create or destroyed from such a constrctor or destructor is undefined!



		// Template Class Information :
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
		//		3. Template arguments :
		//
		//			1. NodeIdentifierType - the type of data the sequential platform contains, which forms the keys to the platform data
		//			2. DataType - the data type that the tree will store
		//			3. MaximumNumberOfChildNodesForEachNode - the maximum number of pointers that each node will have to child nodes
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		class Tree : public ManipulateDataUsingSequentialPlatformAsKey_Interface< NodeIdentifierType, DataType >
		{
		public:


			// Create a type definition for this object
			using SelfType = Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >;

			// Create a type definition for the tree nodes
			using TreeNodeType = TreeNode< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >;


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
			//			maximumCapacityAllowedForTheInstance - the maximum capacity this instance should use
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
			explicit inline Tree( UnsignedInteger64bits maximumCapacityAllowedForTheInstance = NumericLimits< UnsignedInteger64bits >::Maximum() );


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
			//			1. key - a constant reference to a sequential platform instance
			//			2. data - a constant reference to the data to be associated with the key
			//			3. maximumCapacityAllowedForTheInstance - the maximum capacity this instance should use
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
			//		1. The given sequential platform instance is not empty
			//		2. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			explicit inline Tree( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key, const DataType& data, UnsignedInteger64bits maximumCapacityAllowedForTheInstance = NumericLimits< UnsignedInteger64bits >::Maximum() );


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
			explicit inline Tree( const Tuple< const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >&, const DataType&, UnsignedInteger64bits >& arguments );


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
			//			other - a reference to the instance that should be copied
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
			Tree( const SelfType& other );


			// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
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
			ObjectInfrastructure_ForInheritance_MACRO( ConsiderAsOneArgument( Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode > ) )


			// Method Information :
			//
			//  Description :
			//
			//      This method is used to swap the content between this instance and the other one
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			other - a reference to the instance that should be swaped
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//      NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//      They will come
			//
			inline void Swap( SelfType& other );


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
			//			1. key - a constant reference to a sequential platform instance
			//			2. data - a constant reference to the data to be associated with the key
			//			3. maximumCapacityAllowedForTheInstance - the maximum capacity this instance should use
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
			//		1. The given sequential platform instance is not empty
			//		2. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void Initiate( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key, const DataType& data, UnsignedInteger64bits maximumCapacityAllowedForTheInstance );


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
			virtual ~Tree();


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the maximum size the platform is allowed to grow to
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
			//		The maximum size the platform is allowed to grow to
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual UnsignedInteger64bits MaximumCapacity() const override;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the entire memory space allocated for the platform, this can be different then size, if the platfrom 
			//		allocates memory space prior to use. This is needed to prevent multiple allocations and copies of the data
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
			//		The entire memory space allocated for the platform
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual UnsignedInteger64bits Capacity() const override;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the number of nodes in the tree instance
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
			//		The number of nodes in the tree instance
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual UnsignedInteger64bits Size() const override;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to check if a key exist in the platform
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			key - a constant reference to a sequential platform instance to check if exist in the platform
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		True if the key exist in the platform, and false otherwise
			//
			//  Expectations :
			//
			//		1. The platform instance is ready
			//		2. The given sequential platform instance is ready 
			//		3. The given sequential platform instance is not empty
			//		4. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual Boolean KeyExist( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key ) const override;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to check if a data exist in the platform
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			data - a constant reference to the data instance to check if exist in the platform
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		True if the given data already exist in the platform instance, and false otherwise
			//
			//  Expectations :
			//
			//		1. The platform instance is ready
			//		2. 
			//
			//  Possible errors :
			//
			//		NONE
			//
			virtual Boolean DataExist( const DataType& data ) const override;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to add data to the platform, the data will be identified by the key
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. key - a constant reference to a sequential platform instance
			//			2. dataToAdd - a constant reference to the data to add
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
			//		1. The platform instance is ready
			//		2. The given key should not exist already in the platform
			//		3. The maximum capacity of the platform allows to add more data
			//		4. The given sequential platform instance is ready 
			//		5. The given sequential platform instance is not empty
			//		6. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			virtual void AddData( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key, const DataType& data ) override;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to remove the data associated with the key from the platform
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			key - a constant reference to a sequential platform instance
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
			//		1. The platform instance is ready
			//		2. The given sequential platform instance is ready 
			//		3. The given sequential platform instance is not empty
			//		4. The given key should exist in the platform instance
			//		5. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual DataType RemoveData( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key ) override;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to perform a certain action on all the entries of a sequential platform instance. The required action can be passed
			//		as any invokable object. This includes functions, methods, lambda expressions and functors. The invokable object will accept each time
			//		the data of one entry of the sequential platform instance, the index of it and will return a boolean, with the value true if the passing
			//		on all the entries should stop, and false if it should continue
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			action - a constant reference to an invokable object which can contain the action in any form required
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		1. The platform instance should be ready
			//		2. The invokable object instance should be ready
			//		3. 
			//
			//  Possible errors :
			//
			//		1. The invokation of the object failes and throws an exception
			//		2.
			//
			virtual void ForEachElementDo( const InvokableObject< Boolean, DataType&, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& >& action ) override;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to perform a certain action on all the entries of a sequential platform instance. The required action can be passed
			//		as any invokable object. This includes functions, methods, lambda expressions and functors. The invokable object will accept each time
			//		the data of one entry of the sequential platform instance, the index of it and will return a boolean, with the value true if the passing
			//		on all the entries should stop, and false if it should continue. This version is for constant platform instances
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			action - a constant reference to an invokable object which can contain the action in any form required
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		1. The platform instance should be ready
			//		2. The invokable object instance should be ready
			//		3. 
			//
			//  Possible errors :
			//
			//		1. The invokation of the object failes and throws an exception
			//		2.
			//
			virtual void ForEachElementDo( const InvokableObject< Boolean, const DataType&, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& >& action ) const override;


			// The following methods declare the overloaded operators for the object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to get a reference to the required data
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			key - a constant reference to a sequential platform instance
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A reference to the required data
			//
			//  Expectations :
			//
			//		1. The given sequential platform instance is ready 
			//		2. The given sequential platform instance is not empty
			//		3. The given key should exist in the platform instance
			//		4. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual DataType& operator[]( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key ) override;


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to get a constant reference to the required data. This version is for constant instances
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			key - a constant reference to a sequential platform instance
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
	        //      A constant reference to the required data
			//
			//  Expectations :
			//
			//		1. The given sequential platform instance is ready 
			//		2. The given sequential platform instance is not empty
			//		3. The given key should exist in the platform instance
			//		4. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual const DataType& operator[]( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key ) const override;


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to check if the this instance match the other
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			other - a reference to the instance that should be compared with this object
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//      1. true - if the 2 instances are the same
			//      2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual Boolean operator==( const SelfType& other ) const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to check if the this instance does not match the other
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			other - a reference to the instance that should be compared with this object
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//      1. true - if the 2 instances are not the same
			//      2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual inline Boolean operator!=( const SelfType& other ) const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to add the content of another platform instance to this instance
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			data - a constant reference to another platfrom instance
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
			//		1. The other platform instance should be ready
			//		2. The other platform instance size shoule be larger then 0
			//		3. The other platfrom instance must not contain any key that already exist in the current instance
			//		4.  
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			virtual ManipulateDataUsingSequentialPlatformAsKey_Interface< NodeIdentifierType, DataType >& operator+=( const ManipulateDataUsingSequentialPlatformAsKey_Interface< NodeIdentifierType, DataType >& other ) override;


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
	        //      User information needed :
	        //
	        //          1. rangeForSize - this will be used to limit the possible size of the random instance
	        //          2. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
	        //
	        //      Information returned to the user :
	        //
	        //          NONE
	        //
	        //  Return value :
	        //
	        //      A random generated instance
	        //
	        //  Expectations :
	        //
	        //      NONE
	        //
	        //  Possible errors :
	        //
	        //      They will come
	        //
            template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
	        static inline SelfType GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 1000UL ), ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


			DEBUG_TOOL(

				// This part of the object is dedicated for testing :

				inline void DisplayTree() const;


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


 			// This object will store the memory address of the tree root node
 			TreeNodeType* member_treeRoot;

 			// This object will store the number of nodes with data in the tree instance
 			UnsignedInteger64bits member_size;

 			// This object will store the maximum capacity allowed for this instance
 			UnsignedInteger64bits member_maximumCapacity;


 			// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the start of the program
			// and only destroyed when the program ends. The access to the static member is bound to this object of course


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to build all the path declared by the key, and set the data into the last node of the path
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. key - a constant reference to a sequential platform instance
			//			2. data - a constant reference to the data to be associated with the key
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
			//		1. The given sequential platform instance is not empty
			//		2. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			void CreateThePathRequiredByTheKeyAndSetTheDataInTheLastNodeOfThePath__Private( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key, const DataType& data );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to discover how much of the path that the key declares already exist. It will find the first entry of the key that a 
			//		node is still does not exist in the tree for it, and return the node memory address and the index in the key that the exploration 
			//		stopped at 
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			key - a constant reference to a sequential platform instance
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//			A tuple with the node memory address and the index in the key that the exploration stopped at 
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			Tuple< TreeNodeType*, UnsignedInteger64bits > PassOnTheKeyToDiscoverHowMuchOfThePathAlreadyExist__Private( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key ) const;

	
			// Method Information :
			//
			//  Description :
			//
			//		Use this method to check if a specific node, contains a child node with the required identifier
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. node - a pointer to the node that contains the child node to check on
			//			2. childNodeIdentifer - the required identifer of the child node
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//			True if a child node with the required identifer exist, and false otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean IsChildNodeWithSpecificIdentiferExist__Private( const TreeNodeType* node, const NodeIdentifierType& childNodeIdentifer ) const;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get a pointer to a child node with the required identifier
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. node - a pointer to the node that contains the child node
			//			2. childNodeIdentifer - the required identifer of the child node
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		A pointer to a child node with the required identifier			
			//
			//  Expectations :
			//
			//		1. A child node with the required identifier exist
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline TreeNodeType* GetPointerToChildNodeWithSpecificIdentifer__Private( const TreeNodeType* node, const NodeIdentifierType& childNodeIdentifer ) const;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to recursively pass on the tree nodes and copy the structure of the other instance to this instance
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. nodeInThisInstance - the memory addrss of the node in this instance to copy to
			//			2. nodeInOtherInstance - the memory address of the equivalent node in the other instance to copy
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
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			void CopyNodesRecursively__Private( TreeNodeType* nodeInThisInstance, const TreeNodeType* nodeInOtherInstance );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to recursively delete all the nodes of the tree. The pointer should be the tree root pointer
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			node - the memory address of the node to delete
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
			void DeleteAllNodesRecursively__Private( TreeNodeType* node );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to remove all the nodes that won't be used anymore due to deleting the data
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			key - a constant reference to a sequential platform instance
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
			//		1. The given pointer to the node is not NULL
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			void DeleteAllEmptyNodesInThePathDeclaredByTheKey__Private( TreeNodeType* node );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to recursively pass on the tree instances and check if the match
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. nodeInThisInstance - the memory addrss of the node in this instance to compare to
			//			2. nodeInOtherInstance - the memory address of the equivalent node in the other instance to compare
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		True if the tree instances match, and false otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			Boolean CompareInstancesRecursively__Private( const TreeNodeType* nodeInThisInstance, const TreeNodeType* nodeInOtherInstance ) const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to perform a certain action on all the entries of a platform instance. This method is to allow invoking	functions,
			//		functors and lambda expressions on each entry. This method is to allow passing to the functor also the key of the current entry. 
			//		This is a recursive method
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. node - a pointer to a tree node
			//			2. key - a reference to a single linked list instance
			//			3. action - a constant reference to an invokable object which can contain the action in any form required
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		True if the there is no more need to pass on the nodes, and false otherwise. This is only used to allow the caller to end the 
			//		passing on the nodes before passed on all of them, if a certian condition is met
			//
			//  Expectations :
			//
			//		1. The platform should be ready 
			//		2. The platform should have a size larger then 0
			//		3. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline Boolean PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( TreeNodeType* node, SingleLinkedList< NodeIdentifierType >& key, const InvokableObject< Boolean, DataType&, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& >& action );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to perform a certain action on all the entries of a platform instance. This method is to allow invoking	functions,
			//		functors and lambda expressions on each entry. This method is to allow passing to the functor also the key of the current entry. 
			//		This is a recursive method
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. node - a pointer to a tree node
			//			2. key - a reference to a single linked list instance
			//			3. action - a constant reference to an invokable object which can contain the action in any form required
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		True if the there is no more need to pass on the nodes, and false otherwise. This is only used to allow the caller to end the 
			//		passing on the nodes before passed on all of them, if a certian condition is met
			//
			//  Expectations :
			//
			//		1. The platform should be ready 
			//		2. The platform should have a size larger then 0
			//		3. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			inline Boolean PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( const TreeNodeType* node, SingleLinkedList< NodeIdentifierType >& key, const InvokableObject< Boolean, const DataType&, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& >& action ) const;


			// Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
			// the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
			// thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
			// and the error message will be displayed. This method should not be used, because it does nothing during run time
			CompileTimeAssert( ( MaximumNumberOfChildNodesForEachNode > 0UL ), "Memory::TreeNode failed - the given maximum number of child nodes should be larger then 0" );


		};  //  Class Tree




































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
		//			maximumCapacityAllowedForTheInstance - the maximum capacity this instance should use
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
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		inline Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::Tree( UnsignedInteger64bits maximumCapacityAllowedForTheInstance ) :
		member_state(),
		member_treeRoot( nullptr ),
		member_size( 0UL ),
		member_maximumCapacity( maximumCapacityAllowedForTheInstance )
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
		//			1. key - a constant reference to a sequential platform instance
		//			2. data - a constant reference to the data to be associated with the key
		//			3. maximumCapacityAllowedForTheInstance - the maximum capacity this instance should use
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
		//		1. The given sequential platform instance is not empty
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		inline Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::Tree( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key, const DataType& data, UnsignedInteger64bits maximumCapacityAllowedForTheInstance ) :
		member_state( InstanceState::Ready ),
		member_treeRoot( new TreeNodeType() ),
		member_size( 0UL ),
		member_maximumCapacity( maximumCapacityAllowedForTheInstance )
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			AssertSizeIsLargerThenZero_MACRO( ( key.Size() > 0UL ) )

			// Build all the path declared from the key and set the data in the last node of the path
			CreateThePathRequiredByTheKeyAndSetTheDataInTheLastNodeOfThePath__Private( key, data );

			// Increment the number of nodes with data in the tree instance by 1
			member_size += 1UL;
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
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		inline Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::Tree( const Tuple< const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >&, const DataType&, UnsignedInteger64bits >& arguments ) :
		Tree( arguments.template Entry< 0 >(), arguments.template Entry< 1 >(), arguments.template Entry< 2 >() )
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
		//			other - a reference to the instance that should be copied
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
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
	 	Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::Tree( const SelfType& other ) :
		member_state( other.member_state ),
		member_treeRoot( nullptr ),
		member_size( other.member_size ),
		member_maximumCapacity( other.member_maximumCapacity )
		{

			// Check if the other instance is ready for use
			if ( other.member_state.Get() == InstanceState::Ready )
			{
				// The other instance is ready for use

				// Allocate the tree root
				member_treeRoot = new TreeNodeType();

				// Copy the structure of the other tree instance recursively
				CopyNodesRecursively__Private( member_treeRoot, other.member_treeRoot );
			}

		}


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
		//			other - a reference to the instance that should be swaped
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
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		inline void Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::Swap( SelfType& other )
		{
			// Swap between the state of the instances
			member_state.Swap( other.member_state );

		    // Swap between the root arrays
			Memory::Operations::Swap< TreeNodeType* >( member_treeRoot, other.member_treeRoot );

		    // Swap between the sizes
		    Memory::Operations::Swap< UnsignedInteger64bits >( member_size, other.member_size );

		    // Swap between the maximum capacities
		    Memory::Operations::Swap< UnsignedInteger64bits >( member_maximumCapacity, other.member_maximumCapacity );
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
		//			1. key - a constant reference to a sequential platform instance
		//			2. data - a constant reference to the data to be associated with the key
		//			3. maximumCapacityAllowedForTheInstance - the maximum capacity this instance should use
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
		//		1. The given sequential platform instance is not empty
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		inline void Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::Initiate( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key, const DataType& data, UnsignedInteger64bits maximumCapacityAllowedForTheInstance )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( key, data, maximumCapacityAllowedForTheInstance );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
    	}


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
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::~Tree()
		{
		    // Check if the object is in default state, then noting needs to be done
		    ReturnIfExpressionIsTrue_MACRO( member_state.Get() == InstanceState::Default )

			// Delete all the nodes in the tree
		    DeleteAllNodesRecursively__Private( member_treeRoot );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the maximum size the platform is allowed to grow to
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
		//		The maximum size the platform is allowed to grow to
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		UnsignedInteger64bits Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::MaximumCapacity() const
		{
			// Return the maximum capacity allowed for every instance of this object
			return ( member_maximumCapacity );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the entire memory space allocated for the platform, this can be different then size, if the platfrom 
		//		allocates memory space prior to use. This is needed to prevent multiple allocations and copies of the data
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
		//		The entire memory space allocated for the platform
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		UnsignedInteger64bits Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::Capacity() const
		{
			// Return the current capacity for this instance. In this case the capacity and the size are always the same
			return ( member_size );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the number of nodes in the tree instance
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
		//		The number of nodes in the tree instance
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		inline UnsignedInteger64bits Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::Size() const
		{
			// Return the number of node
			return ( member_size );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to check if a key exist in the platform
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			key - a constant reference to a sequential platform instance to check if exist in the platform
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		True if the key exist in the platform, and false otherwise
		//
		//  Expectations :
		//
		//		1. The platform instance is ready
		//		2. The given sequential platform instance is ready 
		//		3. The given sequential platform instance is not empty
		//		4. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		Boolean Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::KeyExist( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertSizeIsLargerThenZero_MACRO( key.Size() )

			// Check if the instance is empty
			if ( member_size == 0UL )
			{
				// The instance is empty

				// The key does not exist, return false
				return ( false );
			}

			// Pass on the key and check if all the path it declares already exist
			Tuple< TreeNodeType*, UnsignedInteger64bits > tuple_passOnPathResult( PassOnTheKeyToDiscoverHowMuchOfThePathAlreadyExist__Private( key ) );

			// Check if the all the path the key represents already exist ( if the given size mataches the key size ) and if the last node in the path
			// contains data, and return the result
			return ( ( tuple_passOnPathResult.template Entry< 1 >() == key.Size() ) && ( tuple_passOnPathResult.template Entry< 0 >()->DataExist() == true ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to check if a data exist in the platform
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			data - a constant reference to the data instance to check if exist in the platform
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		True if the given data already exist in the platform instance, and false otherwise
		//
		//  Expectations :
		//
		//		1. The platform instance is ready
		//		2. 
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		Boolean Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::DataExist( const DataType& data ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO

			// Check if the size of the platform is zero, which means it contains no data
			ReturnValueIfExpressionIsTrue_MACRO( ( member_size == 0UL ), false )

			// This boolean will store the result, true if the data exist, and false otherwise
			Boolean dataExistOrNot = false;

			// This lambda expression will be used on each data in the tree instance, to check for the required data. In case the required data
			// was found, it will return true to stop the passing on all the data, and otherwise false to continue the passing
			CreateLambdaExpressionInstanceWithArguments( ConsiderAsOneArgument ( [ &data, &dataExistOrNot ]( const DataType& currentData, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& ) -> Boolean 
			{

				// Check if the data looked for match the data of the given argument
				if ( data == currentData )
				{
					// The required data exist

					// Set the boolean to true
					dataExistOrNot = true;

					// Return true, to end the recursion
					return ( true );
				}

				// If control of the method reached here the current element does not match the data looked for, return false to continue the recursion
				return ( false );

			} ), lambdaExpressionToCheckForSpecificData, Boolean, const DataType&, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& )

			// Pass on all the data in the tree instance, and use the lambda expression above to check for the required data
			ForEachElementDo( lambdaExpressionToCheckForSpecificData );

			// Return the boolean with the result if the data exist
			return ( dataExistOrNot );
		}



		// Method Information :
		//
		//  Description :
		//
		//		Use this method to add data to the platform, the data will be identified by the key
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. key - a constant reference to a sequential platform instance
		//			2. dataToAdd - a constant reference to the data to add
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
		//		1. The platform instance is ready
		//		2. The given key should not exist already in the platform
		//		3. The maximum capacity of the platform allows to add more data
		//		4. The given sequential platform instance is ready 
		//		5. The given sequential platform instance is not empty
		//		6. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		void Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::AddData( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key, const DataType& data )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert_MACRO( ( member_size < member_maximumCapacity ), "The maximum capacity for the instance was reached" )
			AssertSizeIsLargerThenZero_MACRO( key.Size() )

			// Check if the instance is in default state
			if ( member_state.Get() == InstanceState::Default )
			{
				// The instance is in default state

				// Create a temporary instance with the new data
				SelfType temporaryInstanceWithTheNewData( key, data, member_maximumCapacity );

				// Swap between this instance and the temporary
				Swap( temporaryInstanceWithTheNewData );
			}
			else
			{
				// Build all the path declared from the key and set the data in the last node of the path
				CreateThePathRequiredByTheKeyAndSetTheDataInTheLastNodeOfThePath__Private( key, data );	

				// Increment the number of nodes with data in the tree instance by 1
				member_size += 1UL;	
			}

		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to remove the data associated with the key from the platform
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			key - a constant reference to a sequential platform instance
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
		//		1. The platform instance is ready
		//		2. The given sequential platform instance is ready 
		//		3. The given sequential platform instance is not empty
		//		4. The given key should exist in the platform instance
		//		5. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		DataType Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::RemoveData( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO
			AssertThisInstanceSizeIsLargerThenZero_MACRO
			AssertSizeIsLargerThenZero_MACRO( key.Size() )

			// Pass on the key and find the node that contains the value in the last entry. This is where the data is stored, and this is where the
			// deletion of all the unused nodes should start from
			Tuple< TreeNodeType*, UnsignedInteger64bits > tuple_pathDeletionNeedsToStartFromThisNodeAndThisIndexInTheKey( PassOnTheKeyToDiscoverHowMuchOfThePathAlreadyExist__Private( key ) );

			// Assert that the path declared by the key already exist in the tree instance
			Assert_MACRO( ( ( tuple_pathDeletionNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 1 >() == key.Size() ) && ( tuple_pathDeletionNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >()->DataExist() == true ) ), "The given key does not exist in the tree instance" )

			// This object will store a copy of the data to return it at the end of the execution
			DataType copyOfRemovedData = MOVE( tuple_pathDeletionNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >()->Data() );

			// Remove the data from the node
			tuple_pathDeletionNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >()->RemoveData();

			// Recursively pass on the nodes starting from the parent node of the node that stored the data and delete all the unused nodes
			DeleteAllEmptyNodesInThePathDeclaredByTheKey__Private( tuple_pathDeletionNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >() );

			// Check if the tree root has no child nodes which means it is empty
			if ( member_size == 1UL )
			{
				// The tree instance is empty

				// Reset the instance
				Reset();
			}
			else
			{
				// Decrement the number of nodes with data in the tree instance by 1
				member_size -= 1UL;
			}

			// Return a copy of the removed data
			return ( MOVE( copyOfRemovedData ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to perform a certain action on all the entries of a sequential platform instance. The required action can be passed
		//		as any invokable object. This includes functions, methods, lambda expressions and functors. The invokable object will accept each time
		//		the data of one entry of the sequential platform instance, the index of it and will return a boolean, with the value true if the passing
		//		on all the entries should stop, and false if it should continue
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			action - a constant reference to an invokable object which can contain the action in any form required
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		1. The platform instance should be ready
		//		2. The invokable object instance should be ready
		//		3. 
		//
		//  Possible errors :
		//
		//		1. The invokation of the object failes and throws an exception
		//		2.
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		void Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::ForEachElementDo( const InvokableObject< Boolean, DataType&, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& >& action )
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO
			AssertThisInstanceSizeIsLargerThenZero_MACRO

			// This object will store the key for each data passed to the action to execute
			SingleLinkedList< NodeIdentifierType > key;

			// Loop on all the child nodes of the tree root
			for ( UnsignedInteger64bits childNodeIndex = 0UL ; childNodeIndex < member_treeRoot->NumberOfChildNodes() ; ++childNodeIndex )
			{
				// Pass the function to execute on each data in the instance to the recursice method
				PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( member_treeRoot->GetChildNode( childNodeIndex ), key, action );
			}

		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to perform a certain action on all the entries of a sequential platform instance. The required action can be passed
		//		as any invokable object. This includes functions, methods, lambda expressions and functors. The invokable object will accept each time
		//		the data of one entry of the sequential platform instance, the index of it and will return a boolean, with the value true if the passing
		//		on all the entries should stop, and false if it should continue. This version is for constant platform instances
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			action - a constant reference to an invokable object which can contain the action in any form required
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		1. The platform instance should be ready
		//		2. The invokable object instance should be ready
		//		3. 
		//
		//  Possible errors :
		//
		//		1. The invokation of the object failes and throws an exception
		//		2.
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		void Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::ForEachElementDo( const InvokableObject< Boolean, const DataType&, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& >& action ) const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertThisInstanceIsReady_MACRO
			AssertThisInstanceSizeIsLargerThenZero_MACRO

			// This object will store the key for each data passed to the action to execute
			SingleLinkedList< NodeIdentifierType > key;

			// Loop on all the child nodes of the tree root
			for ( UnsignedInteger64bits childNodeIndex = 0UL ; childNodeIndex < member_treeRoot->NumberOfChildNodes() ; ++childNodeIndex )
			{
				// Pass the function to execute on each data in the instance to the recursice method
				PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( member_treeRoot->GetChildNode( childNodeIndex ), key, action );
			}

		}
































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************


































		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to get a reference to the required data
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			key - a constant reference to a sequential platform instance
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A reference to the required data
		//
		//  Expectations :
		//
		//		2. The given sequential platform instance is ready 
		//		3. The given sequential platform instance is not empty
		//		4. The given key should exist in the platform instance
		//		5. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		DataType& Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::operator[]( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key )
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			AssertThisInstanceIsReady_MACRO
			AssertThisInstanceSizeIsLargerThenZero_MACRO
			AssertSizeIsLargerThenZero_MACRO( key.Size() )

			// Pass on the key and find the node that contains the value in the last entry. This is where the data is stored
			Tuple< TreeNodeType*, UnsignedInteger64bits > tuple_nodeWithData( PassOnTheKeyToDiscoverHowMuchOfThePathAlreadyExist__Private( key ) );

			// Assert that the path declared by the key already exist in the tree instance
			Assert_MACRO( ( ( tuple_nodeWithData.template Entry< 1 >() == key.Size() ) && ( tuple_nodeWithData.template Entry< 0 >()->DataExist() == true ) ), "The given key does not exist in the tree instance" )
			
			// Return a reference to the data
			return ( tuple_nodeWithData.template Entry< 0 >()->Data() );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to get a constant reference to the required data. This version is for constant instances
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			key - a constant reference to a sequential platform instance
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
        //      A constant reference to the required data
		//
		//  Expectations :
		//
		//		2. The given sequential platform instance is ready 
		//		3. The given sequential platform instance is not empty
		//		4. The given key should exist in the platform instance
		//		5. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		const DataType& Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::operator[]( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key ) const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			AssertThisInstanceIsReady_MACRO
			AssertThisInstanceSizeIsLargerThenZero_MACRO
			AssertSizeIsLargerThenZero_MACRO( key.Size() )

			// Pass on the key and find the node that contains the value in the last entry. This is where the data is stored
			Tuple< TreeNodeType*, UnsignedInteger64bits > tuple_nodeWithData( PassOnTheKeyToDiscoverHowMuchOfThePathAlreadyExist__Private( key ) );

			// Assert that the path declared by the key already exist in the tree instance
			Assert_MACRO( ( ( tuple_nodeWithData.template Entry< 1 >() == key.Size() ) && ( tuple_nodeWithData.template Entry< 0 >()->DataExist() == true ) ), "The given key does not exist in the tree instance" )
			
			// Return a constant reference to the data
			return ( tuple_nodeWithData.template Entry< 0 >()->Data() );
		}

		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 instances are the same
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		Boolean Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::operator==( const SelfType& other ) const
		{
			// Check if both or only one of the instances is in default state
			CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue_MACRO

			// Check if the size of both the trees is the same
			if ( member_size != other.member_size )
			{
				// The sizes are different

				// Return false
				return ( false );
			}

			// Compare between the tree instances recursively, and return the result
			return ( CompareInstancesRecursively__Private( member_treeRoot, other.member_treeRoot ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance does not match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 instances are not the same
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		inline Boolean Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::operator!=( const SelfType& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to add the content of another platform instance to this instance
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			data - a constant reference to another platfrom instance
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
		//		1. The other platform instance should be ready
		//		2. The other platform instance size shoule be larger then 0
		//		3. The other platfrom instance must not contain any key that already exist in the current instance
		//		4.  
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		ManipulateDataUsingSequentialPlatformAsKey_Interface< NodeIdentifierType, DataType >& Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::operator+=( const ManipulateDataUsingSequentialPlatformAsKey_Interface< NodeIdentifierType, DataType >& other )
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			AssertSizeIsLargerThenZero_MACRO( other.Size() )

			// This lambda expression will be used to add all the data in the other tree instance into this instance
			CreateLambdaExpressionInstanceWithArguments( ConsiderAsOneArgument ( [ this ]( const DataType& currentData, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& currentKey ) -> Boolean 
			{

				// Add the current key and associated data to this instance
				this->AddData( currentKey, currentData );

				// Return false, to continue adding the data
				return ( false );

			} ), lambdaExpressionToAddAllTheDataOfTheOtherInstanceToThisInstance, Boolean, const DataType&, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& )

			// Pass on all the data in the tree instance, and use the lambda expression above to check for the required data
			other.ForEachElementDo( lambdaExpressionToAddAllTheDataOfTheOtherInstanceToThisInstance );

			// Return a reference to this instance
			return ( *this );
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
        //      User information needed :
        //
        //          1. rangeForSize - this will be used to limit the possible size of the random instance
        //          2. argumentsNeededToGenerateRandomInstanceOfDataType - any arguments needed to create a random instance of the data type
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A random generated instance
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode > Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForSize, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType )
        {
            // Create an instance
            SelfType randomInstance;

            // Pick a number for the number of keys and associated data to enter
            UnsignedInteger64bits randomInstanceSize = Random::Generator::Get< UnsignedInteger64bits >( rangeForSize );

            // Loop to add the required amount of entries to the random instance
            while ( randomInstance.Size() < randomInstanceSize )
            {
            	// Generate a random key
            	HeapArray< NodeIdentifierType > randomKey = MOVE( HeapArray< NodeIdentifierType >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits >( 1UL, 50UL ) ) );

            	// Check if the key already exist
            	if ( randomInstance.KeyExist( randomKey ) == true )
            	{
            		// The key already exist

            		// Continue to the next iteration
            		continue;
            	}

                // Generate a random data and add it to the random instance
            	randomInstance.AddData( randomKey, Random::Generator::Get< DataType >( argumentsNeededToGenerateRandomInstanceOfDataType... ) );
            }

            // Return a copy of the instance
            return ( MOVE( randomInstance ) );
        }































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to build all the path declared by the key, and set the data into the last node of the path
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. key - a constant reference to a sequential platform instance
		//			2. data - a constant reference to the data to be associated with the key
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
		//		1. The given sequential platform instance is not empty
		//		2. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		void Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::CreateThePathRequiredByTheKeyAndSetTheDataInTheLastNodeOfThePath__Private( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key, const DataType& data )
		{

			// Try catch block to ensure that all the memory space allocated is deleted in case of an exception
			try
			{

				// Pass on the key and find from where the building of the path it declares needs to start, and what already exist in the tree
				Tuple< TreeNodeType*, UnsignedInteger64bits > tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey( PassOnTheKeyToDiscoverHowMuchOfThePathAlreadyExist__Private( key ) );

				// So far information on what exist already in the tree instance, and what is left to construct was gathered. Now will start the actual 
				// building for the part of the path which is still does not exist

				// Loop on all the entries of the key left to build the path
				while ( tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 1 >() < key.Size() )
				{
					// Allocate new node
					TreeNodeType* newNodeWithCurrentIdentifier = new TreeNodeType( key[ tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 1 >() ], tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >() );

					// Add the new node as a child node to the current pointed node
					tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >()->AddChildNode( newNodeWithCurrentIdentifier );

					// Set the current node to the new node allocated
					tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >() = newNodeWithCurrentIdentifier;

					// Increment the key index by 1
					tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 1 >() += 1UL;
				}

				// Check that the last node of the path does not contain other data
				Assert_MACRO( ( tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >()->DataExist() == false ), "The last node of the path already contains data" )

				// The building of the path declared by the key was finished, all there is left to do is to set the data in the last node
				tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >()->AddData( data );

			}
			catch ( const std::bad_alloc& exception )
			{

				// Check if the tree root pointer is not NULL
				if ( member_treeRoot != nullptr )
				{
					// Delete all the nodes allocated so far
					DeleteAllNodesRecursively__Private( member_treeRoot );
				}

				// Rethrow the exception to notify the caller that the operation failed
				throw;

			}

		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to discover how much of the path that the key declares already exist. It will find the first entry of the key that a 
		//		node is still does not exist in the tree for it, and return the node memory address and the index in the key that the exploration 
		//		stopped at 
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			key - a constant reference to a sequential platform instance
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//			A tuple with the node memory address and the index in the key that the exploration stopped at 
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		Tuple< TreeNode< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >*, UnsignedInteger64bits > Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::PassOnTheKeyToDiscoverHowMuchOfThePathAlreadyExist__Private( const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key ) const
		{
			// This tuple will store the result of the method, the node memory addres and the index in the key that the exploration stopped at. The exploration
			// will start from the tree root and the first index in of the key which is 0
			Tuple< TreeNodeType*, UnsignedInteger64bits > tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey( member_treeRoot, 0UL );

			// Loop on all the entries of the key
			while ( tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 1 >() < key.Size() )
			{

				// Check if one of the child nodes of the current node contains the identifier in the current entry of the key
				if ( IsChildNodeWithSpecificIdentiferExist__Private( tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >(), key[ tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 1 >() ] ) == false )
				{
					// A child node with the required identifier does not exist

					// Return the tuple result
					return ( tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey );					
				}

				// Set the current node to the child node with the required identifier
				tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >() = GetPointerToChildNodeWithSpecificIdentifer__Private( tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 0 >(), key[ tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 1 >() ] );

				// Increment the key index by 1
				tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey.template Entry< 1 >() += 1UL;
			}

			// Return the tuple result
			return ( tuple_pathCreationNeedsToStartFromThisNodeAndThisIndexInTheKey );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to check if a specific node, contains a child node with the required identifier
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. node - a pointer to the node that contains the child node to check on
		//			2. childNodeIdentifer - the required identifer of the child node
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//			True if a child node with the required identifer exist, and false otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		inline Boolean Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::IsChildNodeWithSpecificIdentiferExist__Private( const TreeNodeType* node, const NodeIdentifierType& childNodeIdentifer ) const
		{

			// Loop on all the child nodes of the given node
			for ( UnsignedInteger64bits childNodeIndex = 0UL ; childNodeIndex < node->NumberOfChildNodes() ; ++childNodeIndex )
			{

				// Check if the pointer points to a node with the required child node identifer
				if ( node->GetChildNode( childNodeIndex )->Identifier() == childNodeIdentifer )
				{
					// A child node with the required identifier exist

					// Return true
					return ( true );
				}

			}

			// If control of the method reached here, no child node with the required identifier exist, return false
			return ( false );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get a pointer to a child node with the required identifier
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. node - a pointer to the node that contains the child node
		//			2. childNodeIdentifer - the required identifer of the child node
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A pointer to a child node with the required identifier			
		//
		//  Expectations :
		//
		//		1. A child node with the required identifier exist
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		inline TreeNode< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >* Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::GetPointerToChildNodeWithSpecificIdentifer__Private( const TreeNodeType* node, const NodeIdentifierType& childNodeIdentifer ) const
		{

			// Loop on all the child nodes of the given node
			for ( UnsignedInteger64bits childNodeIndex = 0UL ; childNodeIndex < node->NumberOfChildNodes() ; ++childNodeIndex )
			{

				// Check if the pointer points to a node with the required child node identifer
				if ( node->GetChildNode( childNodeIndex )->Identifier() == childNodeIdentifer )
				{
					// A child node with the required identifier exist

					// Return the pointer to the child node
					return ( node->GetChildNode( childNodeIndex ) );
				}

			}

			// If control of the method reached here, no child node with the required identifier exist, throw an exception
			ThrowException( "A child node with the required identifier does not exist" )
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to recursively pass on the tree nodes and copy the structure of the other instance to this instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. nodeInThisInstance - the memory addrss of the node in this instance to copy to
		//			2. nodeInOtherInstance - the memory address of the equivalent node in the other instance to copy
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
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		void Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::CopyNodesRecursively__Private( TreeNodeType* nodeInThisInstance, const TreeNodeType* nodeInOtherInstance )
		{

			// Try catch block to ensure that all the memory space allocated is deleted in case of an exception
			try
			{

				// Loop on all the entries of the other instance root tree array
				for ( UnsignedInteger64bits childNodeIndex = 0UL ; childNodeIndex < nodeInOtherInstance->NumberOfChildNodes() ; ++childNodeIndex )
				{
					// Copy the current node from the other instance
					nodeInThisInstance->AddChildNode( new TreeNodeType( nodeInOtherInstance->GetChildNode( childNodeIndex )->Identifier(), nodeInThisInstance ) );

					// Check if the current node from the other instance contains data
					if ( nodeInOtherInstance->GetChildNode( childNodeIndex )->DataExist() == true )
					{
						// The curent node in the other instance contains data

						// Copy also the data
						nodeInThisInstance->GetChildNode( childNodeIndex )->AddData( nodeInOtherInstance->GetChildNode( childNodeIndex )->Data() );
					}

					// Continue the copy recursively on this branch of nodes
					CopyNodesRecursively__Private( nodeInThisInstance->GetChildNode( childNodeIndex ), nodeInOtherInstance->GetChildNode( childNodeIndex ) );
				}


			}
			catch ( const std::bad_alloc& exception )
			{

				// Check if the tree root pointer is not NULL
				if ( member_treeRoot != nullptr )
				{
					// Delete all the nodes allocated so far
					DeleteAllNodesRecursively__Private( member_treeRoot );
				}

				// Rethrow the exception to notify the caller that the operation failed
				throw;

			}

		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to recursively delete all the nodes of the tree. The pointer should be the tree root pointer
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			node - the memory address of the node to delete
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
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		void Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::DeleteAllNodesRecursively__Private( TreeNodeType* node )
		{

			// Loop on all the exisiting child nodes of the node
			for ( UnsignedInteger64bits childNodeIndex = 0UL ; childNodeIndex < node->NumberOfChildNodes() ; ++childNodeIndex )
			{
				// Continute the deletion recursively on this branch of nodes
				DeleteAllNodesRecursively__Private( node->GetChildNode( childNodeIndex ) );
			}

			// Delete this node
			delete node;
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to remove all the nodes that won't be used anymore due to deleting the data
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			key - a constant reference to a sequential platform instance
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
		//		1. The given pointer to the node is not NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		void Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::DeleteAllEmptyNodesInThePathDeclaredByTheKey__Private( TreeNodeType* node )
		{
			// This pointer will store the memory address of the parent node
			TreeNodeType* currentParentNode = nullptr;

			// Loop on all the nodes of the key the contain no data, and no child nodes
			while ( ( node->NumberOfChildNodes() == 0UL ) && ( node->DataExist() == false ) && ( node != member_treeRoot ) )
			{
				// The current node needs to be deleted

				// Set the parent node
				currentParentNode = node->ParentNode();

				// Remove the pointer, from the parent node child array nodes, that point to the this node and move all the pointers above it one entry down
				currentParentNode->RemoveChildNode( GetPointerToChildNodeWithSpecificIdentifer__Private( currentParentNode, node->Identifier() ) );

				// delete the current node
				delete node;

				// Set the current node to the parent node
				node = currentParentNode;
			}

		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to recursively pass on the tree instances and check if the match
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			1. nodeInThisInstance - the memory addrss of the node in this instance to compare to
		//			2. nodeInOtherInstance - the memory address of the equivalent node in the other instance to compare
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		True if the tree instances match, and false otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		Boolean Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::CompareInstancesRecursively__Private( const TreeNodeType* nodeInThisInstance, const TreeNodeType* nodeInOtherInstance ) const
		{
			// To compare nodes, two things needs to be checked. The first is regrding the data, if one instance holds data so does the other must hold
			// data, furthermore the data must be the same. The second is that both nodes has the same number of pointers to child nodes, the pointer
			// will not be the same of course, just the number of pointers!

			// Compare the current nodes in both instances
			if ( ( nodeInThisInstance->DataExist() != nodeInOtherInstance->DataExist() ) || ( nodeInThisInstance->NumberOfChildNodes() != nodeInOtherInstance->NumberOfChildNodes() ) || ( ( nodeInThisInstance->DataExist() == true ) && ( nodeInThisInstance->Data() != nodeInOtherInstance->Data() ) ) )
			{
				// The nodes does not match

				// Return false
				return ( false );				
			}

			// Loop on all the entries of the child nodes arrays
			for ( UnsignedInteger64bits childNodeIndex = 0UL ; childNodeIndex < nodeInThisInstance->NumberOfChildNodes() ; ++childNodeIndex )
			{

				// Continute the comparison recursively on this branch of nodes
				if ( CompareInstancesRecursively__Private( nodeInThisInstance->GetChildNode( childNodeIndex ), nodeInOtherInstance->GetChildNode( childNodeIndex ) ) == false )
				{
					// The branches in both trees does not match

					// Return false
					return ( false );
				}

			}

			// If control of the method reached here then the current branch in both trees match, return true 
			return ( true );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to perform a certain action on all the entries of a platform instance. This method is to allow invoking	functions,
		//		functors and lambda expressions on each entry. This method is to allow passing to the functor also the key of the current entry. 
		//		This is a recursive method
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. node - a pointer to a tree node
		//			2. key - a reference to a single linked list instance
		//			3. action - a constant reference to an invokable object which can contain the action in any form required
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//		True if the there is no more need to pass on the nodes, and false otherwise. This is only used to allow the caller to end the 
		//		passing on the nodes before passed on all of them, if a certian condition is met
		//
		//  Expectations :
		//
		//		1. The platform should be ready 
		//		2. The platform should have a size larger then 0
		//		3. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		inline Boolean Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( TreeNodeType* node, SingleLinkedList< NodeIdentifierType >& key, const InvokableObject< Boolean, DataType&, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& >& action )
		{
			// Add the identifer of the current node to the key
			key.AddData( key.Size(), node->Identifier() );

			// Check if the current node contains data
			if ( node->DataExist() == true )
			{
				// The current node contains data

				// Execute the required action on the data in the node, and check the return value, if the passing on the nodes should stop
				if ( action( node->Data(), key ) == true )
				{
					// The passing on the node should be stopped

					// Return true
					return ( true );
				}

			}

			// Pass on the all the child nodes of the current node, and recursively execute this method on them
			for ( UnsignedInteger64bits childNodeIndex = 0UL ; childNodeIndex < node->NumberOfChildNodes() ; ++childNodeIndex )
			{
				
				// Perform the recursive call on the current child node, and check the return value, if the passing on the nodes should stop
				if ( PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( node->GetChildNode( childNodeIndex ), key, action ) == true )
				{
					// The passing on the node should be stopped

					// Return true
					return ( true );
				}

			}

			// Remove the identifer of the current node from the key
			key.RemoveData( key.Size() - 1UL );

			// Return false to continue the recurssion
			return ( false );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to perform a certain action on all the entries of a platform instance. This method is to allow invoking	functions,
		//		functors and lambda expressions on each entry. This method is to allow passing to the functor also the key of the current entry. 
		//		This is a recursive method
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. node - a pointer to a tree node
		//			2. key - a reference to a single linked list instance
		//			3. action - a constant reference to an invokable object which can contain the action in any form required
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//		True if the there is no more need to pass on the nodes, and false otherwise. This is only used to allow the caller to end the 
		//		passing on the nodes before passed on all of them, if a certian condition is met
		//
		//  Expectations :
		//
		//		1. The platform should be ready 
		//		2. The platform should have a size larger then 0
		//		3. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename NodeIdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
		inline Boolean Tree< NodeIdentifierType, DataType, MaximumNumberOfChildNodesForEachNode >::PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( const TreeNodeType* node, SingleLinkedList< NodeIdentifierType >& key, const InvokableObject< Boolean, const DataType&, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& >& action )  const
		{
			// Add the identifer of the current node to the key
			key.AddData( key.Size(), node->Identifier() );

			// Check if the current node contains data
			if ( node->DataExist() == true )
			{
				// The current node contains data

				// Execute the required action on the data in the node, and check the return value, if the passing on the nodes should stop
				if ( action( node->Data(), key ) == true )
				{
					// The passing on the node should be stopped

					// Return true
					return ( true );
				}

			}

			// Pass on the all the child nodes of the current node, and recursively execute this method on them
			for ( UnsignedInteger64bits childNodeIndex = 0UL ; childNodeIndex < node->NumberOfChildNodes() ; ++childNodeIndex )
			{
				
				// Perform the recursive call on the current child node, and check the return value, if the passing on the nodes should stop
				if ( PassRecursivelyOnAllTheNodesAndExecuteTheRequiredAction__Private( node->GetChildNode( childNodeIndex ), key, action ) == true )
				{
					// The passing on the node should be stopped

					// Return true
					return ( true );
				}

			}

			// Remove the identifer of the current node from the key
			key.RemoveData( key.Size() - 1UL );

			// Return false to continue the recurssion
			return ( false );
		}







































// *********************************************************************************   TESTING   ********************************************************************************




































		DEBUG_TOOL(

			template< typename NodeIdentifierType COMMA typename DataType COMMA UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
			inline void Tree< NodeIdentifierType COMMA DataType COMMA MaximumNumberOfChildNodesForEachNode >::DisplayTree() const
			{
				// This lambda expression will be used on each data in the tree instance, to check for the required data. In case the required data
				// was found, it will return true to stop the passing on all the data, and otherwise false to continue the passing
				CreateLambdaExpressionInstanceWithArguments( ConsiderAsOneArgument ( []( const DataType& currentData, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& key ) -> Boolean 
				{
					std::cout << "KEY --  ";

					for ( UnsignedInteger64bits index = 0UL ; index < key.Size() ; ++index )
					{
						std::cout << key[ index ] << " ";
					}

					std::cout << std::endl;

					std::cout << "DATA --  " << currentData << std::endl << std::endl;

					return ( false );

				} ), lambdaExpressionToDisplatTreeInstanceContent, Boolean, const DataType&, const GetAndSetDataUsingIndices_Interface< NodeIdentifierType >& )

				// Pass on all the data in the tree instance, and use the lambda expression above to check for the required data
				ForEachElementDo( lambdaExpressionToDisplatTreeInstanceContent );
			}


			// Method Information :
			//
			//  Description :
			//
			//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
			//		the functionality
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			NONE
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//      1. true - if the object passed the test
			//      2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		1. An assertion failed - class Exception or ErrnoException is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			template< typename NodeIdentifierType COMMA typename DataType COMMA UnsignedInteger64bits MaximumNumberOfChildNodesForEachNode >
			void Tree< NodeIdentifierType COMMA DataType COMMA MaximumNumberOfChildNodesForEachNode >::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::NoParameterizedConstructor< Tree< NodeIdentifierType COMMA DataType COMMA MaximumNumberOfChildNodesForEachNode > >();

				// Test all the functionality required by the manipulate data using sequential platforms as keys
				Testing::PlatformTest::Full< SelfType COMMA NodeIdentifierType COMMA DataType >( 100, NumericRange< UnsignedInteger64bits >( 1UL, 20UL ), NumericRange< NodeIdentifierType >( 1, MaximumNumberOfChildNodesForEachNode ) );
			}

		)  //  End of debug tool











    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // TREE_HPP