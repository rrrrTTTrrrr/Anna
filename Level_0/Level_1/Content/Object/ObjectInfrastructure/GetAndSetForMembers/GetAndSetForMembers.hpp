namespace Universe
{




// ************************************************************************************************************************************************************************** //
// **														   				    GET    												   			                           ** //
// ************************************************************************************************************************************************************************** //




// This macro will be used to create a get by value method for a specific member of an object. The required arguments are :
//
//		GetMethodName - the name for the get method
//		MemberName - the name of the specific member that the get method will retrive for the caller
//		MemberType - the type of the specific member
//
// The method will return a copy of the member
//
#define GetByValue_Creator( GetMethodName, MemberName, MemberType )																		\
																																\
																																\
	EnsureRetrunValueIsUsed inline MemberType GetMethodName() const   															\
	{    																														\
		return ( MemberName );    																								\
	}


// This macro will be used to create a get by value method for a specific member and method of that member. The required arguments are :
//
//		GetMethodName - the name for the get method
//		MemberName - the name of the specific member that the get method will retrive for the caller
//		MemberGetMethodName - the name of the get method of the member to invoke
//		ReturnValueType - the type of the specific member
//
// The method will return a copy of the member
//
#define GetByValue_FromMemberGetMethod_Creator( GetMethodName, MemberName, MemberGetMethodName, ReturnValueType )						\
																																\
																																\
	EnsureRetrunValueIsUsed inline ReturnValueType GetMethodName() const    													\
	{    																														\
		return ( MemberName.MemberGetMethodName() );    																		\
	}


// This macro will be used to create a get by value method for a specific member and method of that member. The required arguments are :
//
//		GetMethodName - the name for the get method
//		MemberName - the name of the specific member that the get method will retrive for the caller
//		MemberGetMethodName - the name of the get method of the member to invoke
//		ReturnValueType - the type of the specific member
//
// The method will return a copy of the member
//
#define GetByValue_FromNonConstantMemberGetMethod_Creator( GetMethodName, MemberName, MemberGetMethodName, ReturnValueType )			\
																																\
																																\
	EnsureRetrunValueIsUsed inline ReturnValueType GetMethodName()    															\
	{    																														\
		return ( MemberName.MemberGetMethodName() );    																		\
	}



// This macro will be used to create a get by value method, which always return a constant value. The required arguments are :
//
//		GetMethodName - the name for the get method
//		Value - the constant value to return
//		ValueTyep - the type of the value
//
// The method will return a copy of the value
//
#define GetByValue_ConstantValue_Creator( GetMethodName, Value, ValueType )																\
																																\
																																\
	constexpr ValueType GetMethodName() const    																				\
	{    																														\
		return ( Value );    																									\
	}



// This macro will be used to create a get by value method for a specific member of an object. The method will be declared as 'virtual' and
// 'override'. The required arguments are :
//
//		GetMethodName - the name for the get method
//		MemberName - the name of the specific member that the get method will retrive for the caller
//		MemberType - the type of the specific member
//
// The method will return a copy of the member
//
#define GetByValue_DeclaredVirtualAndOverride_Creator( GetMethodName, MemberName, MemberType )											\
																																\
																																\
	virtual MemberType GetMethodName() const override    																		\
	{    																														\
		return ( MemberName );    																								\
	}



// This macro will be used to create a get by value method, which always return a constant value. The method will be declared as 'virtual' and
// 'override'. The required arguments are :
//
//		GetMethodName - the name for the get method
//		Value - the constant value to return
//		ValueTyep - the type of the value
//
// The method will return a copy of the value
//
#define GetByValue_DeclaredVirtualAndOverride_ConstantValue_Creator( GetMethodName, Value, ValueType )									\
																																\
																																\
	virtual ValueType GetMethodName() const override    																		\
	{    																														\
		return ( Value );    																									\
	}



// This macro will be used to create a get by reference method for a specific member of an object. The required arguments are :
//
//		GetMethodName - the name for the get method
//		MemberName - the name of the specific member that the get method will retrive for the caller
//		MemberType - the type of the specific member
//
// The method will return a reference to the member
//
#define GetByReference_Creator( GetMethodName, MemberName, MemberType )																	\
																																\
																																\
	EnsureRetrunValueIsUsed inline MemberType& GetMethodName()    																\
	{    																														\
		return ( MemberName );    																								\
	}



// This macro will be used to create a get by reference method for a specific member of an object. The method will be declared as 'virtual' and
// 'override'. The required arguments are :
//
//		GetMethodName - the name for the get method
//		MemberName - the name of the specific member that the get method will retrive for the caller
//		MemberType - the type of the specific member
//
// The method will return a reference to the member
//
#define GetByReference_DeclaredVirtualAndOverride_Creator( GetMethodName, MemberName, MemberType )										\
																																\
																																\
	virtual MemberType& GetMethodName() override    																			\
	{    																														\
		return ( MemberName );    																								\
	}



// This macro will be used to create a get by constant reference method for a specific member of an object. The required arguments are :
//
//		GetMethodName - the name for the get method
//		MemberName - the name of the specific member that the get method will retrive for the caller
//		MemberType - the type of the specific member
//
// The method will return a constant reference to the member
//
#define GetByConstantReference_Creator( GetMethodName, MemberName, MemberType )															\
																																\
																																\
	EnsureRetrunValueIsUsed inline const MemberType& GetMethodName() const    													\
	{    																														\
		return ( MemberName );    																								\
	}



// This macro will be used to create a get by constant reference method for a specific member and method of that member. The required arguments are :
//
//		GetMethodName - the name for the get method
//		MemberName - the name of the specific member that the get method will retrive for the caller
//		MemberGetMethodName - the name of the get method of the member to invoke
//		ReturnValueType - the type of the specific member
//
// The method will return a copy of the member
//
#define GetByConstantReference_FromMemberGetMethod_Creator( GetMethodName, MemberName, MemberGetMethodName, ReturnValueType )			\
																																\
																																\
	EnsureRetrunValueIsUsed inline const ReturnValueType& GetMethodName() const    												\
	{    																														\
		return ( MemberName.MemberGetMethodName() );    																		\
	}



// This macro will be used to create a get by constant reference method for a specific member of an object. The method will be declared as 'virtual' and
// 'override'. The required arguments are :
//
//		GetMethodName - the name for the get method
//		MemberName - the name of the specific member that the get method will retrive for the caller
//		MemberType - the type of the specific member
//
// The method will return a constant reference to the member
//
#define GetByConstantReference_DeclaredVirtualAndOverride_Creator( GetMethodName, MemberName, MemberType )								\
																																\
																																\
	virtual const MemberType& GetMethodName() const override    																\
	{    																														\
		return ( MemberName );    																								\
	}




// ************************************************************************************************************************************************************************** //
// **														   				    SET    												   			                           ** //
// ************************************************************************************************************************************************************************** //




// This macro will be used to create two methods to set a specific member of an object. One setting by copying the given data, and another
// for taking the resources of the given data instead of copying it. The required arguments are :
//
//		SetMethodName - the name for the set method
//		MemberName - the name of the specific member that the set method will be used on
//		MemberType - the type of the specific member
//
#define Set_Creator( SetMethodName, MemberName, MemberType )																			\
																																\
																																\
	inline void SetMethodName( const MemberType& instance )    																	\
	{    																														\
		MemberName = instance;    																								\
	}																															\
																																\
																																\
	inline void SetMethodName( MemberType&& instance )    																		\
	{    																														\
		MemberName = TakeResourcesAndLeaveInstanceInDefaultState( instance );    												\
	}



// This macro will be used to create a set method for a specific member of an object. The required arguments are :
//
//		SetMethodName - the name for the set method
//		MemberName - the name of the specific member that the set method will be used on
//		MemberType - the type of the specific member
//
#define SetByValue_Creator( SetMethodName, MemberName, MemberType )																		\
																																\
																																\
	inline void SetMethodName( const MemberType instance )    																	\
	{    																														\
		MemberName = instance;    																								\
	}



// This macro will be used to create a set method for a specific member of an object. The required arguments are :
//
//		SetMethodName - the name for the set method
//		MemberName - the name of the specific member that the set method will be used on
//		MemberType - the type of the specific member
//
#define SetPointerByValue_Creator( SetMethodName, MemberName, MemberType )																\
																																\
																																\
	inline void SetMethodName( MemberType* const instance )    																	\
	{    																														\
		MemberName = instance;    																								\
	}



}  //  namespace Universe