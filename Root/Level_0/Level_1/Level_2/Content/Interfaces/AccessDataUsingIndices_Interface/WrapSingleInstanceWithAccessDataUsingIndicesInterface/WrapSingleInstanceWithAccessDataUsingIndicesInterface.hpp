#ifndef WRAPSINGLEINSTANCEWITHACCESSDATAUSINGINDICESINTERFACE_HPP
#define WRAPSINGLEINSTANCEWITHACCESSDATAUSINGINDICESINTERFACE_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../Content/Object/ObjectInfrastructure/BasicObjectFunctionality/BasicObjectFunctionality.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../Content/Object/ObjectInfrastructure/GetAndSetForMembers/GetAndSetForMembers.hpp"  //  Macro Get_MACRO, Macro Set_MACRO
#include "../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../Content/Metaprogramming/Types/PerformActionAccordingToType/PerformActionAccordingToType.hpp"  // Class PerformActionAccordingToType
#include "../../../Random/Generator/Generator.hpp"  //  Class Generator
#include "../AccessDataUsingIndices_Interface.hpp"  //  Class AccessDataUsingIndices_Interface


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
	//			1. Type -
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
	class WrapSingleInstanceWithAccessDataUsingIndicesInterface : public AccessDataUsingIndices_Interface< AnyType >
	{
	public:


		// Create a type definition for this object
		using SelfType = WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >;


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
		inline WrapSingleInstanceWithAccessDataUsingIndicesInterface();


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
		//			instance - a constant reference to an instance of the template type
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
		explicit inline WrapSingleInstanceWithAccessDataUsingIndicesInterface( const AnyType& instance );


		// Method Information :
		//
		//  Description :
		//
		//		Constructor, to allow creating a random generated instance 
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			The first argument purpose is to ensure this constructor will be called by setting a special type
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
		explicit inline WrapSingleInstanceWithAccessDataUsingIndicesInterface( RandomInstance );


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
		inline WrapSingleInstanceWithAccessDataUsingIndicesInterface( const SelfType& other );


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
		ObjectInfrastructure_WithStateAlwaysReady_MACRO( WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType > )


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
		//      User information needed :
		//
		//			instance - a constant reference to an instance of the template type
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
		inline void Initiate( const AnyType& instance );


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
		//		This version is to allow initiating random instance
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			The first argument purpose is to ensure this constructor will be called by setting a special type
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
		inline void Initiate( RandomInstance );


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
		virtual ~WrapSingleInstanceWithAccessDataUsingIndicesInterface() = default;


		// This part will contain all the get and set methods for the members of the object :


		// The size is always constant and equal to 1
		GetByValue_DeclaredVirtualAndOverride_ConstantValue_MACRO( Size, 1UL, UnsignedInteger64bits )


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
		inline Boolean operator==( const SelfType& other ) const;


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
		inline Boolean operator!=( const SelfType& other ) const;


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to get a reference to the data associated with the index. Note - the given index does not matter, it always returns
		//		the same single instance it contains
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			index - a number within the possible range of the instance
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A reference to single instance of the template type stored in this instance
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		virtual AnyType& operator[]( UnsignedInteger64bits index ) override;


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to get a constant reference to the data associated with the index. Note - the given index does not matter, it always returns
		//		the same single instance it contains
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			index - a number within the possible range of the instance
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A constant reference to single instance of the template type stored in this instance
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possi :
		//
		//		They will come
		//
		virtual const AnyType& operator[]( UnsignedInteger64bits index ) const override;


		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
		// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
		// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


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


		// This object will store the single instance of the template type
		AnyType member_instance;


	};  //  Class WrapSingleInstanceWithAccessDataUsingIndicesInterface




































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
	inline WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::WrapSingleInstanceWithAccessDataUsingIndicesInterface() :
	member_instance( PerformActionAccordingToType::GetDefaultInstance< AnyType >() )
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
	//			instance - a constant reference to an instance of the template type
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
	inline WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::WrapSingleInstanceWithAccessDataUsingIndicesInterface( const AnyType& instance ) :
	member_instance( instance )
	{}


	// Method Information :
	//
	//  Description :
	//
	//		Constructor, to allow creating a random generated instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			The first argument purpose is to ensure this constructor will be called by setting a special type
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
	WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::WrapSingleInstanceWithAccessDataUsingIndicesInterface( RandomInstance ) :
	SelfType( Random::Generator::Get< AnyType >() )
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
	template< typename AnyType >
	inline WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::WrapSingleInstanceWithAccessDataUsingIndicesInterface( const SelfType& other ) :
	member_instance( other.member_instance )
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
	template< typename AnyType >
	inline void WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::Swap( SelfType& other )
	{
	    // Swap between the stroed instances
	    Memory::Operations::Swap< AnyType >( member_instance, other.member_instance );
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
	//				instance - a constant reference to an instance of the template type
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
	inline void WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::Initiate( const AnyType& instance )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    SelfType temporary( instance );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance.
	//		This version is to allow initiating random instance
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			The first argument purpose is to ensure this constructor will be called by setting a special type
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
    inline void WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::Initiate( RandomInstance )
	{
	    // Use the required constructor to create an instance. It will be swaped with this instance, leaving this instance with the new data. When sequence control will
	    // leave this scope it delete the old data if exist
	    SelfType randomGeneratedInstance( GenerateRandomInstance );

	    // Swap between this instance and the temporary instance
	    Swap( randomGeneratedInstance );
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
	template< typename AnyType >
	inline Boolean WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::operator==( const SelfType& other ) const
	{
		// Check if the stored instance match, and return the result
		return ( member_instance == other.member_instance );
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
	template< typename AnyType >
	inline Boolean WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::operator!=( const SelfType& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to get a reference to the data associated with the index. Note - the given index does not matter, it always returns
	//		the same single instance it contains
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - a number within the possible range of the instance
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to single instance of the template type stored in this instance
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
	AnyType& WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::operator[]( UnsignedInteger64bits index )
	{
		// Return a reference to the stored instance of the template type
		return ( member_instance );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to get a constant reference to the data associated with the index. Note - the given index does not matter, it always returns
	//		the same single instance it contains
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			index - a number within the possible range of the instance
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A constant reference to single instance of the template type stored in this instance
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possi :
	//
	//		They will come
	//
	template< typename AnyType >
	const AnyType& WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::operator[]( UnsignedInteger64bits index ) const
	{
		// Return a constant reference to the stored instance of the template type
		return ( member_instance );
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
		//		1. An assertion failed - class Exception is thrown
		//		2. There is no more free memory space - class std::bad_alloc is thrown
		//		3. 
		//
		template< typename AnyType >
		void WrapSingleInstanceWithAccessDataUsingIndicesInterface< AnyType >::Test()
		{}

	)  //  End of debug tool









}  //  Namespace Universe



#endif  // WRAPSINGLEINSTANCEWITHACCESSDATAUSINGINDICESINTERFACE_HPP