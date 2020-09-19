#ifndef MANIPULATEDATAUSINGSEQUENTIALPLATFORMASKEY_INTERFACE_HPP
#define MANIPULATEDATAUSINGSEQUENTIALPLATFORMASKEY_INTERFACE_HPP


#include "../../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../Content/Memory/SequentialPlatforms/CommonFunctionality/Interfaces/GetAndSetDataUsingIndices_Interface/GetAndSetDataUsingIndices_Interface.hpp"  //  Class GetAndSetDataUsingIndices_Interface
#include "../../../../../../../../Content/InvokableObjects/InvokableObject/InvokableObject.hpp"  //  Class InvokableObject


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
	//	NONE
	//



	namespace Memory
    {



		// Class Information :
		//
		//  Purpose :
		//
		//		Artifical Inteligence
		//
		//  Description :
		//
		//		1. The main purpose of an interface is to ensure that the group of objects that inherit from it, will be forced to implement some
		//		   functionality. The interface will decalre some methods, will not implement them, and the purpose that all the inherting objects
		//		   will have to implement them. This methods that the interface decalres but doesn't provide a definition are called pure virtual,
		//		   methods. The syntax for pure virtual methods are :
		//
		//				virtual void PureVirutalMethod( UnsignedInteger64bits number ) = 0;
		//
		//		   A pure virtual method means, that the object 'lacks' some part of the implementation, and therefore no instances of the object
		//		   can be created, because it is not a 'complete object'. Now, each object that inherits from it, will be forced to implement that
		//		   missing functionality, and instances of the inherting object can exist. As said above this is good to ensure a group of objects
		//		   implement some functionality, but it also gives the ability to point only to the 'interface part' of the object and use it without
		//		   actually knowing the exact type of the object. This is used, for example, to create containers of pointers to different objects,
		//		   that all inherit from the same object, and this is also valid to base objects that are not pure interfaces
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
		//			1. SequentialPlatformDataType - the data type of the sequential platform, which are the keys for the platforms
		//			2. DataType - the type of data the platform stores
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename SequentialPlatformDataType, typename DataType >
		class ManipulateDataUsingSequentialPlatformAsKey_Interface
		{
		public:


			// Create a type definition for this object
			using SelfType = ManipulateDataUsingSequentialPlatformAsKey_Interface< SequentialPlatformDataType, DataType >;

			// Create a type definition for the key
			using KeyType = GetAndSetDataUsingIndices_Interface< SequentialPlatformDataType >;


			// Method Information :
			//
			//  Description :
			//
			//		Default constructor,
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
			inline ManipulateDataUsingSequentialPlatformAsKey_Interface() = default;


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
			inline ManipulateDataUsingSequentialPlatformAsKey_Interface( const SelfType& other ) = default;


			// Method Information :
			//
			//  Description :
			//
			//      Assignment operator, can handle with self assignment and instances in default state
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//          other - a reference to the object that should be copied
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//      A reference to this object
			//
			//  Excpectations :
			//
			//      NONE
			//
			//  Possible errors :
			//
			//      They will come
			//
			inline SelfType& operator=( const SelfType& other ) = default;


			// Method Information :
			//
			//  Description :
			//
			//      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//          other - a reference to the object that should be moved
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//      NONE
			//
			//  Excpectations :
			//
			//      NONE
			//
			//  Possible errors :
			//
			//      They will come
			//
			inline ManipulateDataUsingSequentialPlatformAsKey_Interface( SelfType&& other ) = default;


			// Method Information :
			//
			//  Description :
			//
			//      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//          other - a reference to the object that should be moved
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//      A reference to this object
			//
			//  Excpectations :
			//
			//      NONE
			//
			//  Possible errors :
			//
			//      They will come
			//
			inline SelfType& operator=( SelfType&& other ) = default;


			// Method Information :
			//
			//  Description :
			//
			//		Destructor, does not throw. Only declared to ensure that each object that inherits from this interface, will have a virtual desctructor
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
			virtual ~ManipulateDataUsingSequentialPlatformAsKey_Interface() = default;


			// The following methods are the interface that each inherting object will have to implement :


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
			virtual UnsignedInteger64bits MaximumCapacity() const = 0;


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
			virtual UnsignedInteger64bits Capacity() const = 0;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the size of the platform
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
			//		The size of the platform
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual UnsignedInteger64bits Size() const = 0;


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
			virtual Boolean KeyExist( const KeyType& key ) const = 0;


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
			//		They will come
			//
			virtual Boolean DataExist( const DataType& data ) const = 0;


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
			virtual void AddData( const KeyType& key, const DataType& dataToAdd ) = 0;


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
			virtual DataType RemoveData( const KeyType& key ) = 0;


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
			virtual void ForEachElementDo( const InvokableObject< Boolean, DataType&, const KeyType& >& action ) = 0;


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
			virtual void ForEachElementDo( const InvokableObject< Boolean, const DataType&, const KeyType& >& action ) const = 0;


			// The following methods declare the overloaded operators for the object, which each inherting object will have to implement :


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
			//		1. The platform instance shuld be ready
			//		2. The given sequential platform instance is ready 
			//		3. The given sequential platform instance is not empty
			//		4. The given key should exist in the platform instance
			//		5. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual DataType& operator[]( const KeyType& key ) = 0;


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
			//		1. The platform instance shuld be ready
			//		2. The given sequential platform instance is ready 
			//		3. The given sequential platform instance is not empty
			//		4. The given key should exist in the platform instance
			//		5. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual const DataType& operator[]( const KeyType& key ) const = 0;


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
			//		1. The platform instance shuld be ready
			//		2. The other platform instance should be ready
			//		3. The other platform instance size shoule be larger then 0
			//		4. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			virtual SelfType& operator+=( const SelfType& data ) = 0;


		};  //  Class HeaderFileNameFirstLetterUpperCase




































	}  //  Namespace Memory

}  //  Namespace Universe



#endif  // MANIPULATEDATAUSINGSEQUENTIALPLATFORMASKEY_INTERFACE_HPP