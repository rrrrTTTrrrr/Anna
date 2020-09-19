#ifndef TYPECHECK_DEFAULTCONSTRUCTIBLE_HPP
#define TYPECHECK_DEFAULTCONSTRUCTIBLE_HPP


#include "../../../../../CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA, Macro CompileTimeAssert
#include "../../../../CommonFunctionality/IntegralConstant/IntegralConstant.hpp"  //  Class IntegralConstant
#include "../../../../CommonFunctionality/BypassTheNeedForConstructor/BypassTheNeedForConstructor.hpp"  //  Function BypassTheNeedForConstructor
#include "../../../../CommonFunctionality/ValidAndInvalid/ValidAndInvalid.hpp"  //  Typedef Valid, Class Invalid


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



	// Class Information :
	//
	//  Purpose :
	//
    //      This object implements the required functionality for checking if a type has a default constructor or not. It will contain a set of 2
    //      overloaded methods. The first method will do the actual checking, by using the 'decltype' operator, and trying to use it on a call to
    //      the default constructor of the type :
    //
    //          decltype( Type() )
    //
    //      The check will be made as a template parameter. This way if the type has a default constructor, the expression will be well formed, and 
    //      this method will be choosen from the set of 2 overloaded methods. The second method will be the fallback, in case the type does not
    //      contain a default constructor, the above expression will be ill-formed, and therefore the second method will be choosen, whcih fits
    //      all possible conditions. The last step is to figure out which of the 2 methods were choosen by the compiler. This is done be making 
    //      the first method return the type 'Valid' and the second one return the type 'Invalid'. This types have a different size, and by comparing
    //      the size, it can be known which version of the methods were choosen
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
	class TypeCheck_DefaultConstructible_Implementaion
	{
	public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline TypeCheck_DefaultConstructible_Implementaion() = default;


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        virtual ~TypeCheck_DefaultConstructible_Implementaion() = default;


        // The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
        // access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
        // a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


        // Method Information :
        //
        //  Description :
        //
        //      This method is only declared, there is no need for implementation. It is part of a set of 2 overloaded methods. It will be choosen when the
        //      template type has a default constructor
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename Type, typename = decltype( Type() ) >
        static inline Valid CheckTypeForDefaultConstructor( int );


        // Method Information :
        //
        //  Description :
        //
        //      This method is only declared, there is no need for implementation. It is part of a set of 2 overloaded methods. It will be choosen when the
        //      template type does not have a default constructor
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename Type >
        static inline Invalid CheckTypeForDefaultConstructor( ... );


	private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeCheck_DefaultConstructible_Implementaion )


	};  //  Class TypeCheck_DefaultConstructible_Implementaion






































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ********************************************************************   TypeCheck_DefaultConstructible   ****************************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //







































	// Template Class Information :
	//
	//  Purpose :
	//
	//		Use this object to provide a type check. In general If the given type has a default constructor, this object will contain a boolean
    //      value of true, and otherwise false. This is the main template it will check the type for a default constructor using the object
    //      'TypeCheck_DefaultConstructible_Implementaion', and will contain a boolean with the result
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
	template< typename Type >
	class TypeCheck_DefaultConstructible : public IntegralConstant< Boolean, sizeof( TypeCheck_DefaultConstructible_Implementaion::CheckTypeForDefaultConstructor< Type >( 0 ) ) == sizeof( Valid ) >
	{
	public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline TypeCheck_DefaultConstructible() = default;


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        virtual ~TypeCheck_DefaultConstructible() = default;


	private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeCheck_DefaultConstructible )


	};  //  Class TypeCheck_DefaultConstructible



































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ******************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For array of the same type with the size   ***************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //







































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. In general If the given type has a default constructor, this object will contain a boolean
    //      value of true, and otherwise false. This a template specialization for array of the template type with the size of it. It will check
    //      the type for a default constructor and will contain a boolean with the result
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
    template< typename Type, UnsignedInteger64bits ArraySize >
    class TypeCheck_DefaultConstructible< Type[ ArraySize ] > : public TypeCheck_DefaultConstructible< Type >
    {
    public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline TypeCheck_DefaultConstructible() = default;


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        virtual ~TypeCheck_DefaultConstructible() = default;


    private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeCheck_DefaultConstructible )


    };  //  Class TypeCheck_DefaultConstructible






































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// **************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For array of the same type   *********************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //







































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. In general If the given type has a default constructor, this object will contain a boolean
    //      value of true, and otherwise false. This a template specialization for array of the template type. It will check the type for a default
    //      constructor and will contain a boolean with the result
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
    template< typename Type >
    class TypeCheck_DefaultConstructible< Type[] > : public TypeCheck_DefaultConstructible< Type >
    {
    public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline TypeCheck_DefaultConstructible() = default;


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        virtual ~TypeCheck_DefaultConstructible() = default;


    private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeCheck_DefaultConstructible )


    };  //  Class TypeCheck_DefaultConstructible








































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For lvalue references   ************************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //







































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. In general If the given type has a default constructor, this object will contain a boolean
    //      value of true, and otherwise false. This a template specialization for lvalue references of the type, which can not be default 
    //      constructed, and therefore conatin a boolean with the value false
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
    template< typename Type >
    class TypeCheck_DefaultConstructible< Type& > : public IntegralConstant< Boolean, false >
    {
    public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline TypeCheck_DefaultConstructible() = default;


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        virtual ~TypeCheck_DefaultConstructible() = default;


    private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeCheck_DefaultConstructible )


    };  //  Class TypeCheck_DefaultConstructible






































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For rvalue reference   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //







































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. In general If the given type has a default constructor, this object will contain a boolean
    //      value of true, and otherwise false. This a template specialization for rvalue references of the type, which can not be default 
    //      constructed, and therefore conatin a boolean with the value false
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
    template< typename Type >
    class TypeCheck_DefaultConstructible< Type&& > : public IntegralConstant< Boolean, false >
    {
    public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline TypeCheck_DefaultConstructible() = default;


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        virtual ~TypeCheck_DefaultConstructible() = default;


    private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeCheck_DefaultConstructible )


    };  //  Class TypeCheck_DefaultConstructible






































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// *******************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For type = void   ***************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //







































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. In general If the given type has a default constructor, this object will contain a boolean
    //      value of true, and otherwise false. This a template specialization for the type 'void', which the syntax is legit :
    //
    //          void()
    //
    //      and without this template specialization will result in true, therefore this object will conatin a boolean with the value false
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
    template<>
    class TypeCheck_DefaultConstructible< void > : public IntegralConstant< Boolean, false >
    {
    public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline TypeCheck_DefaultConstructible() = default;


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        virtual ~TypeCheck_DefaultConstructible() = default;


    private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeCheck_DefaultConstructible )


    };  //  Class TypeCheck_DefaultConstructible





































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ****************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For type = void const   ************************************************** //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //







































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. In general If the given type has a default constructor, this object will contain a boolean
    //      value of true, and otherwise false. This a template specialization for the type 'void const', which the syntax is legit :
    //
    //          void const()
    //
    //      and without this template specialization will result in true, therefore this object will conatin a boolean with the value false
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
    template<>
    class TypeCheck_DefaultConstructible< void const > : public IntegralConstant< Boolean, false >
    {
    public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline TypeCheck_DefaultConstructible() = default;


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        virtual ~TypeCheck_DefaultConstructible() = default;


    private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeCheck_DefaultConstructible )


    };  //  Class TypeCheck_DefaultConstructible







































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For type = void volatile   ************************************************ //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //







































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. In general If the given type has a default constructor, this object will contain a boolean
    //      value of true, and otherwise false. This a template specialization for the type 'void volatile', which the syntax is legit :
    //
    //          void volatile()
    //
    //      and without this template specialization will result in true, therefore this object will conatin a boolean with the value false
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
    template<>
    class TypeCheck_DefaultConstructible< void volatile > : public IntegralConstant< Boolean, false >
    {
    public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline TypeCheck_DefaultConstructible() = default;


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        virtual ~TypeCheck_DefaultConstructible() = default;


    private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeCheck_DefaultConstructible )


    };  //  Class TypeCheck_DefaultConstructible







































// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ************************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - For type = void const volatile   ********************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //







































    // Template Class Information :
    //
    //  Purpose :
    //
    //      Use this object to provide a type check. In general If the given type has a default constructor, this object will contain a boolean
    //      value of true, and otherwise false. This a template specialization for the type 'void const volatile', which the syntax is legit :
    //
    //          void const volatile()
    //
    //      and without this template specialization will result in true, therefore this object will conatin a boolean with the value false
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
    template<>
    class TypeCheck_DefaultConstructible< void const volatile > : public IntegralConstant< Boolean, false >
    {
    public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
        // generates a basic behavior for them :


        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline TypeCheck_DefaultConstructible() = default;


        // Method Information :
        //
        //  Description :
        //
        //      Destructor, does not throw
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          NONE
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        virtual ~TypeCheck_DefaultConstructible() = default;


    private:


        // Disable all copy and move related methods
        DisableCopyAndMove_MACRO( TypeCheck_DefaultConstructible )


    };  //  Class TypeCheck_DefaultConstructible








}  //  Namespace Universe



#endif  // TYPECHECK_DEFAULTCONSTRUCTIBLE_HPP