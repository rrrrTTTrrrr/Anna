namespace Universe
{



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store constant type definitions of the template arguments provided. The point is that the first argument is used to tell
//		which of the template arguments type is required, when the exposed type has the index 0, and all the rest have the index increased
//		by 1. This object is the general case. Each time one type of the template arguments is exposed and can be used, and every time the 
//		exposed template argument is taken off and the next template argument type is exposed. This object is used as long as the first 
//		argument integer is not 0. It is the same concept as recursive functions, which contain the general case and a base case to stop the 
//		recursion. For example :
//
//			    template< 0, int, double, long, short, int >
//				class ConstantTypesHolder
//
//		Will store inside a type definition for 'int'.
//
//				using Type = int;
//
//
//		And for :
//
//			    template< 2, int, double, long, short, int >
//				class ConstantTypesHolder
//
//		Will store inside a type definition for 'long'
//		
//  Description :
//
//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
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
//			1. RequiredTemplateArgumentIndex - the index of the template argument that a type definition for is required
//			2. ExposedType - the current template argument type that is exposed and can be used
//			3. TemplateArguments - any amout and type of template arguments
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< UnsignedInteger64bits RequiredTemplateArgumentIndex, typename ExposedType, typename... TemplateArguments >
class ConstantTypesHolder NotForInheritance
{
public:


    // Make a recurssive call the will end with a type definition of the required template argument
    using Type = const typename ConstantTypesHolder< RequiredTemplateArgumentIndex - 1, TemplateArguments... >::Type;


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
	inline ConstantTypesHolder() = default;


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
	inline ~ConstantTypesHolder() = default;


private:


	// Disable all copy and move related methods
    DisableCopyAndMove( ConstantTypesHolder );


};  //  Class ConstantTypesHolder



// ************************************************************************************************************************************************************************** //
//                                                                                                                                                                            //
// ***********************************************   TEMPLATE SPECIALIZATION IMPLEMENTATION - RequiredTemplateArgumentIndex = 0   ******************************************* //
//                                                                                                                                                                            //      
// ************************************************************************************************************************************************************************** //



// Template Class Information :
//
//  Purpose :
//
//		Use this object to store constant type definitions of the template arguments provided. The point is that the first argument is used to tell
//		which of the template arguments type is required, when the exposed type has the index 0, and all the rest have the index increased
//		by 1. This object is the base case. When the index of the required template argument is 0, this object will be used instead of the
//		general form, to stop the recursion and create a type definition of the exposed type
//		
//  Description :
//
//		1. This object contains an instance of the object "State" to allow each instance of this object to have a defined state
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
//			1. RequiredTemplateArgumentIndex - template specialization for 0
//			2. ExposedType - the current template argument type that is exposed and can be used
//			3. TemplateArguments - any amout and type of template arguments
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename ExposedType, typename... TemplateArguments >
class ConstantTypesHolder< 0, ExposedType, TemplateArguments... > NotForInheritance
{
public:


    // Create a type defintion of the current exposed type
    using Type = const ExposedType;


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
	inline ConstantTypesHolder() = default;


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
	inline ~ConstantTypesHolder() = default;


private:


	// Disable all copy and move related methods
    DisableCopyAndMove( ConstantTypesHolder );


};  //  Class ConstantTypesHolder



}  //  Namespace Universe