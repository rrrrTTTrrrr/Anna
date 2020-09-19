#ifndef DOUBLELINKEDLISTNODE_HPP
#define DOUBLELINKEDLISTNODE_HPP


#include "../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../../../../../../../../Content/Object/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../../../Content/Object/ObjectInfrastructure/GetAndSetForMembers/GetAndSetForMembers.hpp"  //  Macro Get_MACRO, Macro Set_MACRO
#include "../../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert


// This additional headers are only needed in test mode
#ifdef TEST_MODE
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


		// Template Class Information :
		//
		//  Purpose :
		//
		//		Artifical Inteligence
		//
		//  Description :
		//
		// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
		//		2. Template arguments :
		//
		//			1. Type - any type
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename AnyType >
		class DoubleLinkedListNode NotForInheritance
		{
		public:


            // Create a type definition for this object
            using SelfType = DoubleLinkedListNode< AnyType >;


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
			inline DoubleLinkedListNode();


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
			//			1. data - a reference to the data that a copy of it will be stored in this node
			//			2. nextNode - the memory address of of the next node
			//			3. previousNode - the memory address of of the previous node
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
			explicit inline DoubleLinkedListNode( const AnyType& data, SelfType* nextNode, SelfType* previousNode );


			// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
			//		1. Reset
			//
			ObjectInfrastructure_OnlyReset_MACRO( DoubleLinkedListNode< AnyType > )


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
			//			1. data - a reference to the data that a copy of it will be stored in this node
			//			2. nextNode - the memory address of of the next node
			//			3. previousNode - the memory address of of the previous node
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
			//		They will come
			//
			inline void Initiate( const AnyType& data, SelfType* nextNode, SelfType* previousNode );


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
			inline ~DoubleLinkedListNode() = default;


			// This part will contain all the get and set methods for the members of the object :


			// Member - member_data
			GetByReference_MACRO( Data, member_data, Type )
			Set_MACRO( SetData, member_data, Type )
			GetForMove_MACRO( MoveData, member_data, Type )
			SetByMove_MACRO( SetDataByMove, member_data, Type )

			// Member - member_nextNode
			GetByValue_MACRO( NextNode, member_nextNode, SelfType* )
			Set_MACRO( SetNextNode, member_nextNode, SelfType* )

			// Member - member_previousNode
			GetByValue_MACRO( PreviousNode, member_previousNode, SelfType* )
			Set_MACRO( SetPreviousNode, member_previousNode, SelfType* )


			// The following methods give access and manipulate the data inside this object :
			

			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a the pointer to the next node
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
			//		A pointer to the next node
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline SelfType* NextNode() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a constant reference to the pointer to the next node
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
			//		A constant reference to the pointer to the next node
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void SetNextNode( SelfType* nextNode );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a the pointer to the previous node
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
			//		A pointer to the previous node
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline SelfType* PreviousNode() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a constant reference to the pointer to the previous node
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
			//		A constant reference to the pointer to the previous node
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void SetPreviousNode( SelfType* previousNode );


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
				static inline void Test() __attribute__ (( __unused__ ));

			)  //  End of debug tool


		private:


            // Disable all copy and move related methods
            DisableCopyAndMove_MACRO( DoubleLinkedListNode )


			// This object will store the data
			AnyType member_data;

			// This object will store the memory address of the next node
			SelfType* member_nextNode;

			// This object will store the memory address of the previous node
			SelfType* member_previousNode;


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


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
			inline void Swap__Private( SelfType& other );


		};  //  Class DoubleLinkedListNode




































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
		template< typename AnyType >
		inline DoubleLinkedListNode< AnyType >::DoubleLinkedListNode() :
		member_data(),
		member_nextNode( 0UL ),
		member_previousNode( 0UL )
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
		//			1. data - a reference to the data that a copy of it will be stored in this node
		//			2. nextNode - the memory address of of the next node
		//			3. previousNode - the memory address of of the previous node
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
		template< typename AnyType >
		inline DoubleLinkedListNode< AnyType >::DoubleLinkedListNode( const AnyType& data, SelfType* nextNode, SelfType* previousNode ) :
		member_data( data ),
		member_nextNode( nextNode ),
		member_previousNode( previousNode )
		{}


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
		//			1. data - a reference to the data that a copy of it will be stored in this node
		//			2. nextNode - the memory address of of the next node
		//			3. previousNode - the memory address of of the previous node
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
		template< typename AnyType >
		inline void DoubleLinkedListNode< AnyType >::Initiate( const AnyType& data, SelfType* nextNode, SelfType* previousNode )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( data, nextNode, previousNode );

		    // Swap between this instance and the temporary instance
		    Swap__Private( temporary );
    	}






























//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************


































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
		template< typename AnyType >
		inline void DoubleLinkedListNode< AnyType >::Swap__Private( SelfType& other )
		{
			// Swap between the data
			Memory::Operations::Swap< AnyType >( member_data, other.member_data );

			// Swap between the pointers to the next node
			Memory::Operations::Swap< SelfType* >( member_nextNode, other.member_nextNode );

			// Swap between the pointers to the previous node
			Memory::Operations::Swap< SelfType* >( member_previousNode, other.member_previousNode );
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
			template< typename AnyType >
			inline void DoubleLinkedListNode< AnyType >::Test()
			{}

		)  //  End of debug tool











    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // DOUBLELINKEDLISTNODE_HPP