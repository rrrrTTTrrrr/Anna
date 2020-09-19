#ifndef ENSURECONSTANTQUALIFIERISNOTREMOVEDFORREFERENCETYPES_HPP
#define ENSURECONSTANTQUALIFIERISNOTREMOVEDFORREFERENCETYPES_HPP


#include "../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert


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



    // The object that deals with this problem in boost is - call_traits



	// Template Class Information :
	//
	//  Purpose :
	//
    //      In a C++ template with a generic type :
    //
    //          template< typename Type >
    //          void Follow( const Type instance )
    //          {}
    //          
    //      If the template provided is a reference, for example 'int&', the reference type '&' conversion operator binds stronger then the 'const' 
    //      qualifier. The function will end up with :
    //
    //          void Follow( int& )
    //
    //      And not :
    //
    //          void Follow( const int& )
    //
    //      To solve this problem this object exist. This is the general form, for any type which is not a reference, the template type will stay 
    //      the same. For any reference type, it will be converted to a constant reference using a type definition, to ensure that the compiler
    //      does not change the constant qualifier. This is the main template it will be used for all the types beside references. This object
    //      can be used for return types as well as for arguments to methods types
	//
	//  Description :
	//
    //      1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
    //         providing 3 keywords :
    //
    //          1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
    //                      obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
    //                      member is public all the encapsulation is lost, so it should be avoided in most cases
    //
    //          2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
    //                         be able to access all the data and methods inside this part. This part will usually containt some methods and few
    //                         data members
    //
    //          3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
    //                       and all the methods the developer needed to implement the interface presented in the public part. Every method in this
    //                       part will end with the suffix __Private
    //
    //      2. Template arguments :
    //
    //          1. Type - any type
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		Too many to count
	//
	template< typename TYPE >
	class EnsureConstantQualifierIsNotRemovedForReferenceTypes NotForInheritance
	{
	public:


        // Create a type definition for the template argument which should stay the same
        using Type = const TYPE;


	private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( EnsureConstantQualifierIsNotRemovedForReferenceTypes )


	};  //  Class EnsureConstantQualifierIsNotRemovedForReferenceTypes






































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For types declared as references   ******************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //






































    // Template Class Information :
    //
    //  Purpose :
    //
    //      In a C++ template with a generic type :
    //
    //          template< typename Type >
    //          void Follow( const Type instance )
    //          {}
    //          
    //      If the template provided is a reference, for example 'int&', the reference type '&' conversion operator binds stronger then the 'const' 
    //      qualifier. The function will end up with :
    //
    //          void Follow( int& )
    //
    //      And not :
    //
    //          void Follow( const int& )
    //
    //      To solve this problem this object exist. This is the general form, for any type which is not a reference, the template type will stay 
    //      the same. For any reference type, it will be converted to a constant reference using a type definition, to ensure that the compiler
    //      does not change the constant qualifier. This is the template specialization for reference types, and it will contain a type definition
    //      for the constant reference
    //
    //  Description :
    //
    //      1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
    //         providing 3 keywords :
    //
    //          1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
    //                      obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
    //                      member is public all the encapsulation is lost, so it should be avoided in most cases
    //
    //          2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
    //                         be able to access all the data and methods inside this part. This part will usually containt some methods and few
    //                         data members
    //
    //          3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
    //                       and all the methods the developer needed to implement the interface presented in the public part. Every method in this
    //                       part will end with the suffix __Private
    //
    //      2. Template arguments :
    //
    //          1. Type - any type
    //
    //  Expectations :
    //
    //      NONE
    //
    //  Possible errors :
    //
    //      Too many to count
    //
    template< typename TYPE >
    class EnsureConstantQualifierIsNotRemovedForReferenceTypes< TYPE& > NotForInheritance
    {
    public:


        // Create a type definition for the template argument which should stay the same
        using Type = const TYPE&;


    private:


        // Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
        NoInstances_MACRO( EnsureConstantQualifierIsNotRemovedForReferenceTypes )


    };  //  Class EnsureConstantQualifierIsNotRemovedForReferenceTypes













}  //  Namespace Universe



#endif  // ENSURECONSTANTQUALIFIERISNOTREMOVEDFORREFERENCETYPES_HPP