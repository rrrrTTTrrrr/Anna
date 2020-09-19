#ifndef TYPEHOLDER_HPP
#define TYPEHOLDER_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert


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
	//		Use this object to store a type. It will enable a few operations on the type, like a type definition that can be used. It also enables
	//		to cast a memory address into the type stored in each instance
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
	//		3. Template arguments :
	//
	//			AnyType - any type acceptable
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
	class TypeHolder NotForInheritance
	{
	public:


		// Create a type definition for this object
		using SelfType = TypeHolder< AnyType >;

        // Create a type definition for the template type
        using TemplateType = AnyType;


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
		inline TypeHolder() = default;


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
		inline ~TypeHolder() = default;


		// The following methods give access and manipulate the data inside this object :


		// Method Information :
	    //
	    //  Description :
		//
		//		Use this method to cast the pointer given to the type stored inside this instance, and return a refernce to it
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			memoryAddressToCastOn - a memory address that needs to be cast to type inside this instance
		//
		//      Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		A refernce to the instance, stored in the given memory address, casted to the type stored in this isntance
		//
		//  Expectations :
		//
		//		1. The given memory address should not be NULL
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline AnyType& Cast( void* memoryAddressToCastOn ) const;


	private:


    	// Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeHolder )


	};  //  Class TypeHolder



























//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




























	// Method Information :
    //
    //  Description :
	//
	//		Use this method to cast the pointer given to the type stored inside this instance, and return a refernce to it
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			memoryAddressToCastOn - a memory address that needs to be cast to type inside this instance
	//
	//      Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A refernce to the instance, stored in the given memory address, casted to the type stored in this isntance
	//
	//  Expectations :
	//
	//		1. The given memory address should not be NULL
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename AnyType >
	inline AnyType& TypeHolder< AnyType >::Cast( void* memoryAddressToCastOn ) const
	{
		// Cast the given memory addrss to the type stored in this instance, and return a refernce to it
		return ( *( reinterpret_cast< AnyType* >( memoryAddressToCastOn ) ) );
	}




}  //  Namespace Universe



#endif  // TYPEHOLDER_HPP