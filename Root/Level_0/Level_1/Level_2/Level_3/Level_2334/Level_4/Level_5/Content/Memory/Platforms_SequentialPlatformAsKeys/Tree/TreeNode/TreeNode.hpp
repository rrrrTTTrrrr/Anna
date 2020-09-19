#ifndef TREENODE_HPP
#define TREENODE_HPP


#include "../../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../Content/Memory/SequentialPlatforms/Array/Array.hpp"  //  Class Array
#include "../../../../../../../../../../../Content/Metaprogramming/Types/PerformActionAccordingToType/PerformActionAccordingToType.hpp"  //  Class PerformActionAccordingToType


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
		//			1. IdentifierType - the type of the object that will be used to identify the node
		//			2. DataType - the type of data that this node will store
		//			3. MaximumNumberOfChildNodes - the maximum number of pointers to child nodes
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		class TreeNode NotForInheritance
		{
		public:


			// Create a type definition for this object
			using SelfType = TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >;


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
			inline TreeNode();


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
			//			1. identifier - a reference to the identification of the node
			//			2. parentNode - the memory address of the previous node in the tree ( the node that is closer to the root )
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
			explicit inline TreeNode( const IdentifierType& identifier, SelfType* parentNode );


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
			//			1. identifier - a reference to the identification of the node
			//			2. parentNode - the memory address of the previous node in the tree ( the node that is closer to the root )
			//			3. data - a reference to the data, that a copy of it should be stored in this node
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
			explicit inline TreeNode( const IdentifierType& identifier, SelfType* parentNode, const DataType& data );


			// This macro will be used to all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
			// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
			// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
			// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
			// macro will be used to add the following methods to each object :
			//
			//		1. Reset
			//
			ObjectInfrastructure_OnlyReset_MACRO( ConsiderAsOneArgument( TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes > ) )


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
			//			1. identifier - a reference to the identification of the node
			//			2. parentNode - the memory address of the previous node in the tree ( the node that is closer to the root )
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
			inline void Initiate( const IdentifierType& identifier, SelfType* parentNode );


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
			//			1. identifier - a reference to the identification of the node
			//			2. parentNode - the memory address of the previous node in the tree ( the node that is closer to the root )
			//			3. data - a reference to the data, that a copy of it should be stored in this node
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
			inline void Initiate( const IdentifierType& identifier, SelfType* parentNode, const DataType& data );


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
			inline ~TreeNode() = default;


			// The following methods give access and manipulate the data inside this object :


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a constant reference to the node identifier
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
			//		A constant reference to the node identifier
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline const IdentifierType& Identifier() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the memory address of the parent node
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
			//		The memory address of the parent node
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline SelfType* ParentNode() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to set the memory address of the parent node
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			parentNode - the memory address of the previous node in the tree ( the node that is closer to the root )
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
			inline void SetParentNode( SelfType* parentNode );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a refernce to the array containing the pointers to the child nodes
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
			//		A refernce to the array containing the pointers to the child nodes
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Array< SelfType*, MaximumNumberOfChildNodes >& ChildNodes();


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a constant refernce to the array containing the pointers to the child nodes
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
			//		A constant refernce to the array containing the pointers to the child nodes
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline const Array< SelfType*, MaximumNumberOfChildNodes >& ChildNodes() const;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to get the number of used pointers in the array of child nodes
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
			//		The number of used pointers in the array of child nodes
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline UnsignedInteger64bits NumberOfChildNodes() const;


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to add a child node
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			childNode - a pointer to the memory address of the child node to add
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
			//		1. The given pointer to the child node is not NULL
			//		2. The maximum number of allowed child nodes was not yet reached
			//		3. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void AddChildNode( TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >* childNode );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to remove the pointer that points to the node with the given identifier
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			childNode - the memory address of the child node that needs to be removed
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
			//		1. A node with the required identifier do exist
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline void RemoveChildNode( TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >* childNode );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a pointer to the required child node
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			index - the index of the required pointer to child node
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
			//		1. The given index is in the possible range [ 0, MaximumNumberOfChildNodes - 1 ]
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			SelfType* GetChildNode( UnsignedInteger64bits index ) const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to check if the node contains data
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
			//		A boolean with value true if the node contains data, and false otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline Boolean DataExist() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a reference to the data inside this node
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
			//		a reference to the data inside this node
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline DataType& Data();


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get a constant reference to the data inside this node
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
			//		a constant reference to the data inside this node
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline const DataType& Data() const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to add data to this node
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			data - a constant reference to the data that a copy of it will be stored in this node
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
			inline void AddData( const DataType& data );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to remove the data inside this node
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
			inline void RemoveData();


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


            // Disable all copy and move related methods
            DisableCopyAndMove_MACRO( TreeNode )


            // This object will store the identifier of the node
            IdentifierType member_identifier;

            // This boolean will store if the current node contains also data or not
            Boolean member_containsDataOrNot;

            // This object will store the data of the node if exist
            DataType member_data;

            // This object will store the memory address of the parent node
            SelfType* member_parentNode;

            // This object will store the memory addresses of the child nodes
            Array< SelfType*, MaximumNumberOfChildNodes > member_childNodes;

            // This object will store the number of child nodes this node contains
            UnsignedInteger64bits member_numberOfChildNodes;


			// Assert all the requirements on the template arguments provided to the object. To perform a compile time assert the C++ language provides
			// the keyword 'static_assert', which receives an expression and an error message to display if the expression result is false. The important
			// thing is that the expression is evaluted during compile time, and therefore if the expression is false the compilation will be terminated
			// and the error message will be displayed. This method should not be used, because it does nothing during run time
			CompileTimeAssert( ( MaximumNumberOfChildNodes > 0UL ), "Memory::TreeNode failed - the given maximum number of child nodes should be larger then 0" );


		};  //  Class TreeNode




































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
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::TreeNode() :
		member_identifier(),
		member_containsDataOrNot( false ),
		member_data(),
		member_parentNode( nullptr ),
		member_childNodes( nullptr ),
		member_numberOfChildNodes( 0UL )
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
		//			1. identifier - a reference to the identification of the node
		//			2. parentNode - the memory address of the previous node in the tree ( the node that is closer to the root )
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
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::TreeNode( const IdentifierType& identifier, SelfType* parentNode ) :
		member_identifier( identifier ),
		member_containsDataOrNot( false ),
		member_data(),
		member_parentNode( parentNode ),
		member_childNodes( nullptr ),
		member_numberOfChildNodes( 0UL )
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
		//			1. identifier - a reference to the identification of the node
		//			2. parentNode - the memory address of the previous node in the tree ( the node that is closer to the root )
		//			3. data - a reference to the data, that a copy of it should be stored in this node
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
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::TreeNode( const IdentifierType& identifier, SelfType* parentNode, const DataType& data ) :
		member_identifier( identifier ),
		member_containsDataOrNot( true ),
		member_data( data ),
		member_parentNode( parentNode ),
		member_childNodes( nullptr ),
		member_numberOfChildNodes( 0UL )
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
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline void TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::Swap( SelfType& other )
		{
			// Swap the node identifiers
			Memory::Operations::Swap< IdentifierType >( member_identifier, other.member_identifier );

			// Swap the booleans that notify if data exist or not in this node
			Memory::Operations::Swap< Boolean >( member_containsDataOrNot, other.member_containsDataOrNot );

			// Swap between the data
			Memory::Operations::Swap< DataType >( member_data, other.member_data );
			
			// Swap between the pointers to the parent nodes
			Memory::Operations::Swap< SelfType* >( member_parentNode, other.member_parentNode );

			// Swap between the pointers to the child nodes
			member_childNodes.Swap( other.member_childNodes );

			// Swap between the number of child nodes
			Memory::Operations::Swap< UnsignedInteger64bits >( member_numberOfChildNodes, other.member_numberOfChildNodes );
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
		//			1. identifier - a reference to the identification of the node
		//			2. parentNode - the memory address of the previous node in the tree ( the node that is closer to the root )
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
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline void TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::Initiate( const IdentifierType& identifier, SelfType* parentNode )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( identifier, parentNode );

		    // Swap between this instance and the temporary instance
		    Swap__Private( temporary );
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
		//			1. identifier - a reference to the identification of the node
		//			2. parentNode - the memory address of the previous node in the tree ( the node that is closer to the root )
		//			3. data - a reference to the data, that a copy of it should be stored in this node
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
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline void TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::Initiate( const IdentifierType& identifier, SelfType* parentNode, const DataType& data )
		{
		    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
		    // leave this scope it will delete the old data
		    SelfType temporary( identifier, parentNode, data );

		    // Swap between this instance and the temporary instance
		    Swap__Private( temporary );
    	}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get a constant reference to the node identifier
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
		//		A constant reference to the node identifier
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline const IdentifierType& TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::Identifier() const
		{
			// Return a constant reference to the node identifier
			return ( member_identifier );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the memory address of the parent node
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
		//		The memory address of the parent node
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >* TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::ParentNode() const
		{
			// Return the memory address of the parent node
			return ( member_parentNode );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to set the memory address of the parent node
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			parentNode - the memory address of the previous node in the tree ( the node that is closer to the root )
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
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline void TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::SetParentNode( SelfType* parentNode )
		{
			// Set the memory address of the parent node
			member_parentNode = parentNode;
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to get the number of used pointers in the array of child nodes
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
		//		The number of used pointers in the array of child nodes
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline UnsignedInteger64bits TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::NumberOfChildNodes() const
		{
			// Return the number of used pointers in the array of child nodes
			return ( member_numberOfChildNodes );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to add a child node
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			childNode - a pointer to the memory address of the child node to add
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
		//		1. The given pointer to the child node is not NULL
		//		2. The maximum number of allowed child nodes was not yet reached
		//		3. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline void TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::AddChildNode( TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >* childNode )
		{
			// Assert that the number of child nodes did not reach that limit
			AssertPointer_MACRO( childNode )
			Assert_MACRO( ( member_numberOfChildNodes < MaximumNumberOfChildNodes ), "The node can not contain any more child nodes" )

			// Add the child node to the first unused entry of the child nodes array
			member_childNodes[ member_numberOfChildNodes ] = childNode;

			// Increment the number of child nodes by 1
			member_numberOfChildNodes += 1UL;
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to remove the pointer that points to the node with the given identifier
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			childNode - the memory address of the child node that needs to be removed
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
		//		1. A node with the required identifier do exist
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline void TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::RemoveChildNode( TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >* childNode )
		{
			// This object will be used as an index to loop on the array
			UnsignedInteger64bits childNodesArrayIndex = 0UL;

			// Loop on all the entries of the array to find the index of the required pointer
			while ( childNodesArrayIndex < member_numberOfChildNodes )
			{

				// Check if the current pointer points to a node with the required identifier
				if ( member_childNodes[ childNodesArrayIndex ] == childNode )
				{
					// The required pointer to the node with the identifier was found

					// Break the loop
					break;
				}

				// Increase the array index by 1
				childNodesArrayIndex += 1UL;
			}

			// Assert that a child node with the required identifer was found
			Assert_MACRO( ( childNodesArrayIndex < member_numberOfChildNodes ), "A child node with the required identifier does not exist" )

			// Increase the array index by 1, to point to the next pointer after the pointer to remove
			childNodesArrayIndex += 1UL;

			// Loop on all the entries of the array to move down one entry all the pointers above the pointer to remove
			while ( childNodesArrayIndex < member_numberOfChildNodes )
			{
				// Move the pointer one entry down
				member_childNodes[ childNodesArrayIndex - 1UL ] = member_childNodes[ childNodesArrayIndex ];
			}

			// Decrement the number of child nodes by 1
			member_numberOfChildNodes -= 1UL;
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get a pointer to the required child node
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			index - the index of the required pointer to child node
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
		//		1. The given index is in the possible range [ 0, MaximumNumberOfChildNodes - 1 ]
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >* TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::GetChildNode( UnsignedInteger64bits index ) const
		{
			// This will be added only in test mode, to ensure that the given data to the method is valid
			AssertIndex_MACRO( index, MaximumNumberOfChildNodes )
			
			// Return a the pointer in the required entry
			return ( member_childNodes[ index ] );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to check if the node contains data
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
		//		A boolean with value true if the node contains data, and false otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline Boolean TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::DataExist() const
		{
			// Return the boolean storing if the node contains data or not
			return ( member_containsDataOrNot );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get a reference to the data inside this node
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
		//		a reference to the data inside this node
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline DataType& TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::Data()
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert_MACRO( ( member_containsDataOrNot == true ), "The node does not contain any data" )

			// Return a reference to the data inside this node
			return ( member_data );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get a constant reference to the data inside this node
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
		//		a constant reference to the data inside this node
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline const DataType& TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::Data() const
		{
			// Each method that interacts with the user directly needs to ensure that the given data is valid
			Assert_MACRO( ( member_containsDataOrNot == true ), "The node does not contain any data" )

			// Return a constant reference to the data inside this node
			return ( member_data );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to add data to this node
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			data - a constant reference to the data that a copy of it will be stored in this node
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
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline void TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::AddData( const DataType& data )
		{
			// Set the data
			member_data = data;

			// Set the boolean that describes if data exist or not to true
			member_containsDataOrNot = true;
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to remove the data inside this node
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
		template< typename IdentifierType, typename DataType, UnsignedInteger64bits MaximumNumberOfChildNodes >
		inline void TreeNode< IdentifierType, DataType, MaximumNumberOfChildNodes >::RemoveData()
		{
			// Reset the data instance
			PerformActionAccordingToType::Reset< DataType >( member_data );

			// Set the boolean that describes if data exist or not to false
			member_containsDataOrNot = false;
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
			template< typename IdentifierType COMMA typename DataType COMMA UnsignedInteger64bits MaximumNumberOfChildNodes >
			void TreeNode< IdentifierType COMMA DataType COMMA MaximumNumberOfChildNodes >::Test()
			{}

		)  //  End of debug tool











    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // TREENODE_HPP