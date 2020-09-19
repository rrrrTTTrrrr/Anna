#ifndef GETANDSETFORMEMBERS_HPP
#define GETANDSETFORMEMBERS_HPP


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
	#define GetByValue_MACRO( GetMethodName, MemberName, MemberType )																									\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by value the content of the member   																								\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	The content of the member by value    																														\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline MemberType GetMethodName() const    																														\
		{    																																							\
			/* Return by value the content of the member */   																											\
			return ( MemberName );    																																	\
		}



	// This macro will be used to create a get by value method for a specific member of an object, only if the instance is ready. The required 
	// arguments are :
	//
	//		GetMethodName - the name for the get method
	//		MemberName - the name of the specific member that the get method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetByValueOnlyIfInstanceIsReady_MACRO( GetMethodName, MemberName, MemberType )																				\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by value the content of the member, and check if the instance is ready before   														\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	The content of the member by value    																														\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline MemberType GetMethodName() const    																														\
		{    																																							\
			/* Assert that this instance is ready */																													\
			AssertThisInstanceIsReady_MACRO;																															\
																																										\
			/* Return by value the content of the member */   																											\
			return ( MemberName );    																																	\
		}



	// This macro will be used to create a virtual get by value method for a specific member of an object. The required arguments are :
	//
	//		GetMethodName - the name for the get method
	//		MemberName - the name of the specific member that the get method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetByValue_DeclaredVirtualAndOverride_MACRO( GetMethodName, MemberName, MemberType )																		\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by value the content of the member   																								\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	The content of the member by value    																														\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		virtual MemberType GetMethodName() const override    																											\
		{    																																							\
			/* Return by value the content of the member */   																											\
			return ( MemberName );    																																	\
		}



	// This macro will be used to create a virtual get by value method for a specific member of an object, only if the instance is ready. The required
	// arguments are :
	//
	//		GetMethodName - the name for the get method
	//		MemberName - the name of the specific member that the get method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetByValueOnlyIfInstanceIsReady_DeclaredVirtualAndOverride_MACRO( GetMethodName, MemberName, MemberType )													\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by value the content of the member, and check if the instance is ready before   														\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	The content of the member by value    																														\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		virtual inline MemberType GetMethodName() const override																										\
		{    																																							\
			/* Assert that this instance is ready */																													\
			AssertThisInstanceIsReady_MACRO;																															\
																																										\
			/* Return by value the content of the member */   																											\
			return ( MemberName );    																																	\
		}



	// This macro will be used to create a virtual get by value method for a specific member of an object. The required arguments are :
	//
	//		GetMethodName - the name for the get method
	//		Value - a number
	//		ValueType - the type of the number
	//
	#define GetByValue_DeclaredVirtualAndOverride_ConstantValue_MACRO( GetMethodName, Value, ValueType )																	\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by value the content of the member   																								\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	The content of the member by value    																														\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		virtual ValueType GetMethodName() const override    																											\
		{    																																							\
			/* Return by value the content of the member */   																											\
			return ( Value );    																																		\
		}



	// This macro will be used to create a get by reference method for a specific member of an object. The required arguments are :
	//
	//		GetMethodName - the name for the get method
	//		MemberName - the name of the specific member that the get method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetByReference_MACRO( GetMethodName, MemberName, MemberType )																								\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by reference the content of the member   																							\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
			The content of the member by reference    																													\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline MemberType& GetMethodName()    																															\
		{    																																							\
			/* Return by reference the content of the member */   																										\
			return ( MemberName );    																																	\
		}



	// This macro will be used to create a get by reference method for a specific member of an object, only if the instance is ready. The required 
	// arguments are :
	//
	//		GetMethodName - the name for the get method
	//		MemberName - the name of the specific member that the get method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetByReferenceOnlyIfInstanceIsReady_MACRO( GetMethodName, MemberName, MemberType )																			\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by reference the content of the member, and check if the instance is ready before   													\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	The content of the member by reference    																													\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline MemberType& GetMethodName()    																															\
		{    																																							\
			/* Assert that this instance is ready */																													\
			AssertThisInstanceIsReady_MACRO;																															\
																																										\
			/* Return by reference the content of the member */   																										\
			return ( MemberName );    																																	\
		}



	// This macro will be used to create a get by reference method for a specific member of an object. The required arguments are :
	//
	//		GetMethodName - the name for the get method
	//		MemberName - the name of the specific member that the get method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetByConstantReference_MACRO( GetMethodName, MemberName, MemberType )																						\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by a constant reference the content of the member   																							\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
			The content of the member by reference    																													\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline const MemberType& GetMethodName() const    																												\
		{    																																							\
			/* Return by constant reference the content of the member */   																								\
			return ( MemberName );    																																	\
		}



	// This macro will be used to create a get by reference method for a specific member of an object, only if the instance is ready. The required 
	// arguments are :
	//
	//		GetMethodName - the name for the get method
	//		MemberName - the name of the specific member that the get method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetByConstantReferenceOnlyIfInstanceIsReady_MACRO( GetMethodName, MemberName, MemberType )																	\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by constant reference the content of the member, and check if the instance is ready before   													\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	The content of the member by reference    																													\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline const MemberType& GetMethodName() const    																												\
		{    																																							\
			/* Assert that this instance is ready */																													\
			AssertThisInstanceIsReady_MACRO;																															\
																																										\
			/* Return by constant reference the content of the member */   																								\
			return ( MemberName );    																																	\
		}



	// This macro will be used to create a virtual get by reference method for a specific member of an object. The required arguments are :
	//
	//		GetMethodName - the name for the get method
	//		MemberName - the name of the specific member that the get method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetByReference_DeclaredVirtualAndOverride_MACRO( GetMethodName, MemberName, MemberType )																	\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by reference the content of the member   																							\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
			The content of the member by reference    																													\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		virtual MemberType& GetMethodName() override    																												\
		{    																																							\
			/* Return by reference the content of the member */   																										\
			return ( MemberName );    																																	\
		}



	// This macro will be used to create a get by reference method for a specific member of an object, only if the instance is ready. The required 
	// arguments are :
	//
	//		GetMethodName - the name for the get method
	//		MemberName - the name of the specific member that the get method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetByReferenceOnlyIfInstanceIsReady_DeclaredVirtualAndOverride_MACRO( GetMethodName, MemberName, MemberType )												\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by reference the content of the member, and check if the instance is ready before   													\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	The content of the member by reference    																													\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		virtual MemberType& GetMethodName() override    																												\
		{    																																							\
			/* Assert that this instance is ready */																													\
			AssertThisInstanceIsReady_MACRO;																															\
																																										\
			/* Return by reference the content of the member */   																										\
			return ( MemberName );    																																	\
		}



	// This macro will be used to create a virtual get by reference method for a specific member of an object. The required arguments are :
	//
	//		GetMethodName - the name for the get method
	//		MemberName - the name of the specific member that the get method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetByConstantReference_DeclaredVirtualAndOverride_MACRO( GetMethodName, MemberName, MemberType )															\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by constant reference the content of the member   																					\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
			The content of the member by reference    																													\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		virtual const MemberType& GetMethodName() const override    																									\
		{    																																							\
			/* Return by constant reference the content of the member */   																								\
			return ( MemberName );    																																	\
		}



	// This macro will be used to create a get by reference method for a specific member of an object, only if the instance is ready. The required 
	// arguments are :
	//
	//		GetMethodName - the name for the get method
	//		MemberName - the name of the specific member that the get method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetByConstantReferenceOnlyIfInstanceIsReady_DeclaredVirtualAndOverride_MACRO( GetMethodName, MemberName, MemberType )										\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by constant reference the content of the member, and check if the instance is ready before   										\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	The content of the member by reference    																													\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		virtual const MemberType& GetMethodName() const override    																									\
		{    																																							\
			/* Assert that this instance is ready */																													\
			AssertThisInstanceIsReady_MACRO;																															\
																																										\
			/* Return by constant reference the content of the member */   																								\
			return ( MemberName );    																																	\
		}




// ************************************************************************************************************************************************************************** //
// **														   				    SET    												   			                           ** //
// ************************************************************************************************************************************************************************** //




	// This macro will be used to create a set method for a specific member of an object. The required arguments are :
	//
	//		SetMethodName - the name for the set method
	//		MemberName - the name of the specific member that the set method will be used on
	//		MemberType - the type of the specific member
	//
	#define Set_MACRO( SetMethodName, MemberName, MemberType )																											\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to set the content of a member   																											\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
				NONE																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline void SetMethodName( const MemberType& instance )    																										\
		{    																																							\
			/* Set the content of the member */   																														\
			MemberName = instance;    																																	\
		}



	// This macro will be used to create a set method for a specific member of an object, only if the instance is ready. The required arguments are :
	//
	//		SetMethodName - the name for the set method
	//		MemberName - the name of the specific member that the set method will be used on
	//		MemberType - the type of the specific member
	//
	#define SetOnlyIfInstanceIsReady_MACRO( SetMethodName, MemberName, MemberType )																						\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to set the content of a member, only if the instance is ready   																			\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
				NONE																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline void SetMethodName( const MemberType& instance )    																										\
		{    																																							\
			/* Assert that this instance is ready */																													\
			AssertThisInstanceIsReady_MACRO;																															\
																																										\
			/* Set the content of the member */   																														\
			MemberName = instance;    																																	\
		}



	// This macro will be used to create a set method for a specific pointer member of an object. The required arguments are :
	//
	//		SetMethodName - the name for the set method
	//		MemberName - the name of the specific member that the set method will be used on
	//		MemberType - the type of the specific member
	//
	#define SetPointerMember_MACRO( SetMethodName, MemberName, MemberType )																								\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to set the content of a pointer member   																									\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
				NONE																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline void SetMethodName( MemberType* instance )    																										\
		{    																																							\
			/* Set the content of the member */   																														\
			MemberName = instance;    																																	\
		}



	// This macro will be used to create a set method for a specific constant pointer member of an object. The required arguments are :
	//
	//		SetMethodName - the name for the set method
	//		MemberName - the name of the specific member that the set method will be used on
	//		MemberType - the type of the specific member
	//
	#define SetPointerToConstantObjectMember_MACRO( SetMethodName, MemberName, MemberType )																								\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to set the content of a pointer to constant object member   																									\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
				NONE																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline void SetMethodName( const MemberType* instance )    																										\
		{    																																							\
			/* Set the content of the member */   																														\
			MemberName = instance;    																																	\
		}



	// This macro will be used to create a set method for a specific pointer member of an object. The required arguments are :
	//
	//		SetMethodName - the name for the set method
	//		MemberName - the name of the specific member that the set method will be used on
	//		MemberType - the type of the specific member
	//
	#define SetPointerMemberIfInstanceIsReady_MACRO( SetMethodName, MemberName, MemberType )																			\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to set the content of a pointer member   																									\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
				NONE																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline void SetMethodName( MemberType* instance )    																										\
		{    																																							\
			/* Assert that this instance is ready */																													\
			AssertThisInstanceIsReady_MACRO;																															\
																																										\
			/* Set the content of the member */   																														\
			MemberName = instance;    																																	\
		}




	// This macro will be used to create a set method for a specific constant pointer member of an object. The required arguments are :
	//
	//		SetMethodName - the name for the set method
	//		MemberName - the name of the specific member that the set method will be used on
	//		MemberType - the type of the specific member
	//
	#define SetPointerToConstantObjectMemberIfInstanceIsReady_MACRO( SetMethodName, MemberName, MemberType )																			\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to set the content of a pointer member   																									\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
				NONE																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline void SetMethodName( const MemberType* instance )    																										\
		{    																																							\
			/* Assert that this instance is ready */																													\
			AssertThisInstanceIsReady_MACRO;																															\
																																										\
			/* Set the content of the member */   																														\
			MemberName = instance;    																																	\
		}




// ************************************************************************************************************************************************************************** //
// **														   				    MOVE    												   			                       ** //
// ************************************************************************************************************************************************************************** //




	// This macro will be used to create a move method for a specific member of an object. The method will return a reference to the member, which
	// will allow to perform a move operation on it. The required arguments are :
	//
	//		MoveMethodName - the name for the move method
	//		MemberName - the name of the specific member that the move method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetForMove_MACRO( MoveMethodName, MemberName, MemberType )																									\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by reference the content of the member to allow perofrm a moving operation on it														\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
			The content of the member by reference    																													\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline MemberType&& MoveMethodName()   																															\
		{    																																							\
			/* Return by reference the content of the member */   																										\
			return ( MOVE( MemberName ) );    																																	\
		}



	// This macro will be used to create a move method for a specific member of an object, only if the instance is ready. The method will return a
	// reference to the member, which will allow to perform a move operation on it. The required arguments are :
	//
	//		MoveMethodName - the name for the get method
	//		MemberName - the name of the specific member that the move method will retrive for the caller
	//		MemberType - the type of the specific member
	//
	#define GetForMoveOnlyIfInstanceIsReady_MACRO( MoveMethodName, MemberName, MemberType )																				\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to get by reference the content of the member to allow perofrm a moving operation on it, and check if the instance is 						\
		   	ready before   																																				\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	The content of the member by reference    																													\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline MemberType&& MoveMethodName()    																														\
		{    																																							\
			/* Assert that this instance is ready */																													\
			AssertThisInstanceIsReady_MACRO;																															\
																																										\
			/* Return by reference the content of the member */   																										\
			return ( MOVE( MemberName ) );    																																	\
		}



	// This macro will be used to create a set by move method for a specific member of an object. The required arguments are :
	//
	//		SetByMoveMethodName - the name for the set method
	//		MemberName - the name of the specific member that the set method will be used on
	//		MemberType - the type of the specific member
	//
	#define SetByMove_MACRO( SetByMoveMethodName, MemberName, MemberType )																								\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to set by move the content of a member   																									\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
				NONE																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline void SetByMoveMethodName( MemberType&& instance )    																									\
		{    																																							\
			/* Set by move the content of the member */   																												\
			MemberName = MOVE( instance );    																															\
		}



	// This macro will be used to create a set by move method for a specific member of an object, only if the instance is ready. The required 
	// arguments are :
	//
	//		SetByMoveMethodName - the name for the set method
	//		MemberName - the name of the specific member that the set method will be used on
	//		MemberType - the type of the specific member
	//
	#define SetByMoveOnlyIfInstanceIsReady_MACRO( SetByMoveMethodName, MemberName, MemberType )																			\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Use this method to set by move the content of a member, only if the instance is ready   																	\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					NONE    																																			\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
				NONE																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline void SetByMoveMethodName( MemberType&& instance )    																									\
		{    																																							\
			/* Assert that this instance is ready */																													\
			AssertThisInstanceIsReady_MACRO;																															\
																																										\
			/* Set the content of the member */   																														\
			MemberName = MOVE( instance );    																															\
		}









}  //  namespace Universe


#endif   // GETANDSETFORMEMBERS_HPP