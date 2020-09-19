#ifndef DYNAMICSTACK_HPP
#define DYNAMICSTACK_HPP


#include "../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../Stack_Interface/Stack_Interface.hpp"  //  Class Stack_Interface
#include "../../../../../../Content/Memory/SequentialPlatforms/CommonFunctionality/SequentialPlatformsInterfaces/DynamicSequentialPlatform_Interface/DynamicSequentialPlatform_Interface.hpp"  //  Class DynamicSequentialPlatform_Interface
#include "../../../../../../../../../../../Content/Metaprogramming/NumericLimits/NumericLimits.hpp"  //  Class NumericLimits
#include "../../../../../../../../../../../Content/Metaprogramming/Tuple/Tuple.hpp"  //  Class Tuple
#include "../../../../../../../../Content/Random/Generator/Generator.hpp"  //  Class Generator
#include "../../../../../../../../Content/NumericRange/NumericRange.hpp"  //  Class NumericRange


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../../../../../../../TestBranch/SanityCheck/SanityCheck.hpp"  //  Class SanityCheck
#include "../../../../../../Content/Memory/SequentialPlatforms/DoubleLinkedList/DoubleLinkedList.hpp"  //  Class DoubleLinkedList
#endif


namespace Universe
{

    namespace Memory
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



		// Why is the size of an empty class not zero?
		//
		// To ensure that the addresses of two different insances will be different. For the same reason, "new" always returns pointers to distinct instances.
		// Consider :
		//
		//		class Empty
		//		{}
		//
		//		void DoSomething()
		//		{
    	//			Empty a;
    	//			Empty b;
    	//
    	//			if ( &a == &b )
    	//			{
    	//				std::cout << "Impossible - report error to compiler supplier" << std::endl;
    	//			}
    	//		
    	//		}
    	//
    	// There is an interesting rule that says that an empty base class need not be represented by a separate byte :
    	//
    	//		class Derived : public Empty
    	//		{
    	//			int a;
    	//			...
    	//		}
    	//
    	//		void DoOtherThing( Derived* pointer )
    	//		{
    	//			void* p1 = pointer;
    	//			void* p2 = &p->a;
    	//
    	//			if ( p1 == p2 )
    	//			{
    	//				std::cout << "Nice - good optimizer" << std::endl;
    	//			}
    	//
    	//		}
    	//
    	// This optimization is safe and can be most useful. It allows a programmer to use empty classes to represent very simple concepts without overhead.
    	// Some current compilers provide this "empty base class optimization"


		// Template Class Information :
		//
		//  Purpose :
		//
		//		This object implements the concept of 'First In Last Out'. This means that this container has two operations, one to push into the
		//		stack and another to pop off the stack. Each pop takes off only the last element entered to the stack
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
		//			1. DataType - any type
		//
		//		4. The rational behind 
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		class DynamicStack : public Stack_Interface< DataType >
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
			inline DynamicStack();


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
			//			data - a reference to the first data to push to the stack
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
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			explicit inline DynamicStack( const DataType& data );


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
			//				data - a reference to the first data to push to the stack
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
			explicit inline DynamicStack( Tuple< const DataType& > arguments );


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
			inline DynamicStack( const DynamicStack< DynamicSequentialPlatformImplementationType, DataType >& other );


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
			ObjectInfrastructure_ForInheritance_StateTakenFromMember_MACRO( ConsiderAsOneArgument( DynamicStack< DynamicSequentialPlatformImplementationType, DataType > ), member_dynamicStack )


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
			inline void Swap( DynamicStack< DynamicSequentialPlatformImplementationType, DataType >& other );


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
			//			data - a reference to the first data to push to the Dynamicstack
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
			//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
			//		2. 
			//
			inline void Initiate( const DataType& data );


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
			virtual ~DynamicStack() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the dynamic stack size
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
			//		The dynamic stack size
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
			//      Use this method to get the stack capacity
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
			//		The stack capacity
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
			//      Use this method to push data into the dynamic stack
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			data - a constant reference to the data to push to the top of the dynamic stack
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
			//		1. The capacity still can contain more entries of the stack
			//		2.
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc will be thrown
			//		2. 
			//
			virtual void PushIn( const DataType& data ) override;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to pop out the data that was last entered to the dynamic stack, and get a copy of it
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
			//		A copy of the data last entered to the dynamic stack
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. The instance size should be at least 1
			//		3. 
			//
			//  Possible errors :
			//
			//		NONE
			//
			virtual DataType PopOut() override;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a reference to the data last entered to the dynamic stack. This means that using this method a reference will be
			//		returned to the data that will be removed if the pop out method will be used
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
			//		A reference to the data last entered to the dynamic stack
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. The instance size should be at least 1
			//		3. 
			//
			//  Possible errors :
			//
			//		NONE
			//
			virtual DataType& PeakTop() override;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a constant reference to the data last entered to the dynamic stack. This means that using this method a reference will be
			//		returned to the data that will be removed if the pop out method will be used
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
			//		A constant reference to the data last entered to the dynamic stack
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. The instance size should be at least 1
			//		3. 
			//
			//  Possible errors :
			//
			//		NONE
			//
			virtual const DataType& PeakTop() const override;


			// The following methods declare the overloaded operators for the object :


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
			inline Boolean operator==( const DynamicStack< DynamicSequentialPlatformImplementationType, DataType >& other ) const;


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
			//			other - a reference to the instance that should be compared with this object
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
			inline Boolean operator!=( const DynamicStack< DynamicSequentialPlatformImplementationType, DataType >& other ) const;


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
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
	        //
	        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
	        static inline DynamicStack< DynamicSequentialPlatformImplementationType, DataType > GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForSize = NumericRange< UnsignedInteger64bits >( 1UL, 100000UL ), ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType );


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


 			// This object will be used to store the Dynamicstack. This will be a sequential platform which implements the dynamic sequential platform interface
 			DynamicSequentialPlatformImplementationType< DataType > member_dynamicStack;


		};  //  Class DynamicStack




































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
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		inline DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::DynamicStack() :
		member_dynamicStack()
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
		//			data - a reference to the first data to push to the Dynamicstack
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
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		inline DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::DynamicStack( const DataType& data ) :
		member_dynamicStack( data )
		{}


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
		//				data - a reference to the first data to push to the stack
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
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		inline DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::DynamicStack( Tuple< const DataType& > arguments ) :
		DynamicStack< DynamicSequentialPlatformImplementationType, DataType >( arguments.template Entry< 0 >() )
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
		//		They will come
		//
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		inline DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::DynamicStack( const DynamicStack< DynamicSequentialPlatformImplementationType, DataType >& other ) :
		member_dynamicStack( other.member_dynamicStack )
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
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		inline void DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::Swap( DynamicStack< DynamicSequentialPlatformImplementationType, DataType >& other )
		{
		    // Swap between the instances that store the Dynamicstack
		    member_dynamicStack.Swap( other.member_dynamicStack );
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
		//			data - a reference to the first data to push to the Dynamicstack
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
		//		1. No more free memory space exist in the heap - Class std::bad_alloc is thrown
		//		2. 
		//
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		inline void DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::Initiate( const DataType& data )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    DynamicStack< DynamicSequentialPlatformImplementationType, DataType > temporary( data );

		    // Swap between this instance and the temporary instance
		    Swap( temporary );
    	}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the dynamic stack size
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
		//		The dynamic stack size
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		UnsignedInteger64bits DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::Size() const
		{
			// Return the size of the dynamic stack
			return ( member_dynamicStack.Size() );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the stack capacity
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
		//		The stack capacity
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		UnsignedInteger64bits DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::Capacity() const
		{
			// Return the maximum number of unsigned integer 64 bits, to notify that in this case the capacity limit is the computer system memory 
			// that actually exist
			return ( NumericLimits< UnsignedInteger64bits >::Maximum() );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to push data into the dynamic stack
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			data - a constant reference to the data to push to the top of the dynamic stack
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
		//		1. The capacity still can contain more entries of the stack
		//		2.
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc will be thrown
		//		2. 
		//
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		void DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::PushIn( const DataType& data )
		{
			// Push the data to the top of the dynamic stack
			member_dynamicStack.AddData( 0UL, data );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to pop out the data that was last entered to the dynamic stack, and get a copy of it
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
		//		A copy of the data last entered to the dynamic stack
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. The instance size should be at least 1
		//		3. 
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		DataType DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::PopOut()
		{
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThisInstanceSizeIsLargerThenZero_MACRO

			// Remove the data last entered to the dynamic stack, and return a copy of it
			return ( MOVE( member_dynamicStack.RemoveData( 0UL ) ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get a reference to the data last entered to the dynamic stack. This means that using this method a reference will be
		//		returned to the data that will be removed if the pop out method will be used
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
		//		A reference to the data last entered to the dynamic stack
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. The instance size should be at least 1
		//		3. 
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		DataType& DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::PeakTop()
		{
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThisInstanceSizeIsLargerThenZero_MACRO

			// Return a reference to the data at the top of the dynamic stack
			return ( member_dynamicStack[0] );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get a constant reference to the data last entered to the dynamic stack. This means that using this method a reference will be
		//		returned to the data that will be removed if the pop out method will be used
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
		//		A constant reference to the data last entered to the dynamic stack
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. The instance size should be at least 1
		//		3. 
		//
		//  Possible errors :
		//
		//		NONE
		//
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		const DataType& DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::PeakTop() const
		{
            // Each method that interacts with the user directly needs to ensure that the given data is valid
            AssertThisInstanceSizeIsLargerThenZero_MACRO

			// Return a constant reference to the data at the top of the dynamic stack
			return ( member_dynamicStack[0] );
		}



































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































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
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		inline Boolean DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::operator==( const DynamicStack< DynamicSequentialPlatformImplementationType, DataType >& other ) const
		{
			// Compare the stacks of both instances, and return the result
			return ( member_dynamicStack == other.member_dynamicStack );
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
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
		inline Boolean DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::operator!=( const DynamicStack< DynamicSequentialPlatformImplementationType, DataType >& other ) const
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
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
        //
		template< template< typename > class DynamicSequentialPlatformImplementationType, typename DataType >
        template< typename... ArgumentsTypesNeededToGenerateRandomInstanceOfDataType >
        inline DynamicStack< DynamicSequentialPlatformImplementationType, DataType > DynamicStack< DynamicSequentialPlatformImplementationType, DataType >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits > rangeForSize, ArgumentsTypesNeededToGenerateRandomInstanceOfDataType... argumentsNeededToGenerateRandomInstanceOfDataType )
        {
            // Create an instance
            DynamicStack< DynamicSequentialPlatformImplementationType, DataType > randomInstance;

            // Create a random instance of the dynamic sequential platform implementation type and store it
            randomInstance.member_dynamicStack = DynamicSequentialPlatformImplementationType< DataType >::GenerateRandomInstance( rangeForSize, argumentsNeededToGenerateRandomInstanceOfDataType... );

            // Return a copy of the instance
            return ( MOVE( randomInstance ) );
        }




































// *********************************************************************************   TESTING   ********************************************************************************




































		DEBUG_TOOL(

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
			template< template< typename > class DynamicSequentialPlatformImplementationType COMMA typename DataType >
			void DynamicStack< DynamicSequentialPlatformImplementationType COMMA DataType >::Test()
			{
				// Perform a sanity to ensure that all the methods that are common among all objects, for example defualt constructor, copy constructor,
				// destructor, swap and more, seem to work correctly
				Testing::SanityCheck::Full< DynamicStack< DynamicSequentialPlatformImplementationType COMMA DataType > COMMA const DataType& >();

				// Create a test instance
				DynamicStack< DoubleLinkedList COMMA UnsignedInteger64bits > testStack_1;

				// Add elements to the Dynamicstack
				for ( UnsignedInteger64bits index = 0UL ; index < 100000UL ; ++index )
				{
					// Add an element to the top of the Dynamicstack
					testStack_1.PushIn( 34UL );
				}

				// Pop all the elements from the Dynamicstack
				for ( UnsignedInteger64bits index = 0UL ; index < 100000UL ; ++index )
				{
					// Add an element to the top of the Dynamicstack
					Assert_MACRO( ( testStack_1.PopOut() == 34UL ), "Test failed - 1" )
				}

				// Add elements to the Dynamicstack
				for ( UnsignedInteger64bits index = 0UL ; index < 100000UL ; ++index )
				{
					// Add an element to the top of the Dynamicstack
					testStack_1.PushIn( 3444UL );
				}

				// Pop all the elements from the Dynamicstack
				for ( UnsignedInteger64bits index = 0UL ; index < 100000UL ; ++index )
				{
					// Add an element to the top of the Dynamicstack
					Assert_MACRO( ( testStack_1.PopOut() == 3444UL ), "Test failed - 2" )
				}

				// Create a test instance
				DynamicStack< DoubleLinkedList COMMA UnsignedInteger64bits > testStack_2 = MOVE( DynamicStack< DoubleLinkedList COMMA UnsignedInteger64bits >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits >( 200000UL, 300000UL ) ) );

				// Check that the instances are different
				Assert_MACRO( ( testStack_1 != testStack_2 ), "Test failed - 3" )

				// Use the assignment operator
				testStack_1 = testStack_2;

				// Check that the instances match
				Assert_MACRO( ( testStack_1 == testStack_2 ), "Test failed - 4" )
			}

		)  //  End of debug tool











    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // DYNAMICSTACK_HPP