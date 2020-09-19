#ifndef SEQUENTIALPLATFORM_INTERFACE_HPP
#define SEQUENTIALPLATFORM_INTERFACE_HPP


#include "../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../../ObjectBranch/Content/InstanceState/InstanceState.hpp"  //  Class InstanceState


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



	namespace Memory
    {



        // When you first declare:
        //
        //      class A
        //      {
        //          public:
        //          virtual void foo() = 0;
        //      };
        //
        // You are declaring the method foo public, virtual and pure. When a class contains at least a pure method it's called abstract. It means that the class cannot be 
        // instantiated because it needs the pure methods implementations.
        //
        // You can obviously inherit from an abstract class, and you can also inherit from an abstract class and not implement some or all of the pure methods of the base 
        // class, in this case the child class is abstract as well, which is the case of your class B :
        //
        //      class B: public A
        //      {
        //          public:
        //          virtual void foo() = 0;
        //      };
        //
        // In B you could easily omit the virtual declaration because the definition is already inherited from the base class. In this case class B is an abstract class and 
        // therefore cannot be instantiated, just like A.



		// Class Information :
		//
		//  Purpose :
		//
		//		This object presents interface for sequential platform. This is used to create a uniform way to access the object that implement
		//		this interface with no regard to the implementation 
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
		//			1. Type - the type of the data that will be stored in the sequential platform
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename DataType >
 		class SequentialPlatform_Interface : public AccessDataUsingIndices_Interface< DataType >
		{
		public:


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
 			//			instanceState - the state to initialize the instance
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
			inline SequentialPlatform_Interface() = default;


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
			inline SequentialPlatform_Interface( const SequentialPlatform_Interface< DataType >& other ) = default;


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
            inline SequentialPlatform_Interface< DataType >& operator=( const SequentialPlatform_Interface< DataType >& other ) = default;


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
            inline SequentialPlatform_Interface( SequentialPlatform_Interface< DataType >&& other ) = default;


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
            inline SequentialPlatform_Interface< DataType >& operator=( SequentialPlatform_Interface< DataType >&& other ) = default;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. size - the number of entries in the sequential platform
			//			2. instance - a reference to the instance that will be used to Initialize all the entries of the sequential platform
			//			3. maximumCapacityAllowedForThisInstance - the maximum memory capacity allowed for this instance
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
			//		1. The maximum capacity is larger then 0
			//		1. The given size is larger then 0
			//		2. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			virtual void Initiate( UnsignedInteger64bits size, const DataType& instance, UnsignedInteger64bits maximumCapacityAllowedForThisInstance ) = 0;


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
	        //          other - a constant reference to an other sequential platform instance
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
	        //      1. The given sequential platform instance is ready 
	        //      2. The given sequential platform instance size should be larger then 0
	        //      3. 
	        //
	        //  Possible errors :
	        //
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			virtual void Initiate( const SequentialPlatform_Interface< DataType >& other ) = 0;


			// Method Information :
			//
			//  Description :
			//
			//		Destructor, does not throw. Only declared to ensure that each object that inherits from this interface, will have a virtual destructor
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
			virtual ~SequentialPlatform_Interface() = default;


			// The following methods are the interface that each inherting object will have to implement :


	        // Method Information :
			//
			//  Description :
			//		
			//      Use this method to get a handle that can be used to obtain information on the state of the instance
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//          NONE
			//		
			//      Information returned to the user
			//
			//         NONE
			//		
			// Return value :
			//		
			//      NONE
			//			
			// Expectations :
			//		
			//      NONE
			//		
			// Possible errors :
			//	
			//      They will come
			//
			virtual InstanceState State() const = 0;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the maximum size the sequential platform is allowed to grow to
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
			//		The maximum size the sequential platform is allowed to grow to
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
			//		Use this method to get the entire memory space allocated for the sequential platform, this can be different then size, if the platfrom 
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
			//		Use this method to add data to the sequential platform. The data will be added at the provided index, which means that after the
			//		addition accessing the data with the given index will return the currently added data, furthermore the data currently represented
			//		by the index will be advanced one index up, as well as all the rest of the data above the index
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. addTheDataAtThisIndex - the index in which the data should be added in the sequential platform instance
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
			//		1. The dynamic sequential platform instance should be ready
			//		2. The given index should be smaller or equal to the dynamic sequential platform size
			//		3. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			virtual void AddData( UnsignedInteger64bits addTheDataAtThisIndex, const DataType& dataToAdd ) = 0;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to add data to the sequential platform. The data will be added starting from the provided index
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. addTheDataStartingAtThisIndex - add the data starting from this index
			//			2. dataToAdd - a constant reference to a sequential platform instance
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
			//		1. The dynamic sequential platform instance should be ready
			//		2. The given index should be smaller or equal to the dynamic sequential platform size
			//		3. The sequential platform given by the reference should be ready
			//		4. The sequential platform given by the reference should have a size larger then 0
			//		5. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			virtual void AddData( UnsignedInteger64bits addTheDataStartingAtThisIndex, const SequentialPlatform_Interface< DataType >& dataToAdd ) = 0;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to remove data from the sequential platform. The data will be removed from the provided index, which means that after 
			//		the removal the data currently represented by the index plus one will be drawn back one index down, as well as all the rest of 
			//		the data above the index
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. indexOfFirstDataToRemove - the first index from which data should be removed from the sequential platform instance
			//			2. sizeToRemove - the number of entries to remove from the dynamic sequential platform
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
			//		1. The given index to remove the data from should exist in the sequential platform instance
			//		2. 
			//
			//  Possible errors :
			//
			//		NONE
			//
			virtual void RemoveData( UnsignedInteger64bits indexOfFirstDataToRemove, UnsignedInteger64bits sizeToRemove ) = 0;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to reserve memory space at the sequential platform. This method will allocate memory space in advance, without
			//		the need for the actual data, and then the data can just be set into the allocated memory when needed
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			1. reserveStartingFromThisIndex - the first index from which memory space should be reserved at the sequential platform instance
			//			2. sizeToReserve - the number of entries to reserve
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
			//		1. The given index should be smaller or equal to the dynamic sequential platform size
			//		2. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			virtual void Reserve( UnsignedInteger64bits reserveStartingFromThisIndex, UnsignedInteger64bits sizeToReserve ) = 0;


			// The following methods declare the overloaded operators for the object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to add the content of another instance to the end of this instance
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			data - a reference to the instance that should be concatenated to the end of this instance
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
			//		1. The instance should be ready
			//		2. The data instance should be ready
			//		3. 
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			virtual DynamicSequentialPlatform_Interface< DataType >& operator+=( const SequentialPlatform_Interface< DataType >& data ) = 0;


		};  //  Class SequentialPlatform_Interface










	}  //  Namespace Memory

}  //  Namespace Universe



#endif  // SEQUENTIALPLATFORM_INTERFACE_HPP