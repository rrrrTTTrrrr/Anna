#ifndef OBJECTINFRASTRUCTURE_HPP
#define OBJECTINFRASTRUCTURE_HPP


namespace Universe
{





// ************************************************************************************************************************************************************************** //
// **														   				OBJECT INFRASTRUCTURE METHODS    												   			   ** //
// ************************************************************************************************************************************************************************** //




	// This macro will be used to create the assignment operator. The required arguments are :
	//
	//		... - the name of the object that will contain the method
	//
	#define AssignmentOperator_MACRO()																																	\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Assignment operator, can handle with self assignment and instances in default state    																		\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
				User information needed :    																															\
		    																																							\
					other - a reference to the instance that should be copied    																						\
		    																																							\
				Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	A reference to this instance    																															\	
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline SelfType& operator=( const SelfType& other )    																											\
		{    																																							\
			/* Create a copy of the other instance */   																												\
			SelfType copyOfOther( other );    																															\
																																										\
			/* Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted */   				\
			Swap( copyOfOther );    																																	\
																																										\
			/* Return a reference to this instance */   																												\
			return ( *this );    																																		\
		}




	// This macro will be used to create the move constructor. The required arguments are :
	//
	//		... - the name of the object that will contain the method
	// 												
	#define MoveConstructor_MACRO( ObjectName )																																\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances 					\
				in default state    																																	\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
		   	User information needed :    																																\
		    																																							\
		          other - a reference to the instance that should be moved    																							\
		    																																							\
		      Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	NONE    																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline ObjectName( SelfType&& other ) :    																														\
		SelfType()    																																					\
		{    																																							\
			/* Swap between this instance, which is in default state, and the other one */   																			\
			Swap( other );    																																			\
		}




	// This macro will be used to create the move assignment operator. The required arguments are :
	//
	//		... - the name of the object that will contain the method
	// 												
	#define MoveAssignmentOperator_MACRO()																																\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state    			\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
		   	User information needed :    																																\
		    																																							\
		          other - a reference to the instance that should be moved    																							\
		    																																							\
		      Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		   	A reference to this instance    																															\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		inline SelfType& operator=( SelfType&& other )    																												\
		{    																																							\
		    /* Create a default constructed instance */   																												\
		    SelfType defaultConstructedInstance;    																													\
																																										\
		    /* Swap between the temporary instance, which is in default state, and the other instance, this will leave the other instance in default state */  			\
		    defaultConstructedInstance.Swap( other );    																												\
																																										\
		    /* Swap between this instance and the temporary one */   																									\
		    Swap( defaultConstructedInstance );    																														\
																																										\
		    /* Return a reference to this instance */   																												\
		    return ( *this );    																																		\
		}




	// This macro will be used to create a swap method between instances of the object
	//
	#define Swap_MACRO()																																				\
																																										\
																																										\
		/* Method Information :																																			\
																																										\
		  Description :																																					\
																																										\
				This method is used to swap the content between this instance and the other one 																		\
																																										\
		  Required arguments :																																			\
																																										\
				User information needed :																																\
																																										\
					other - a reference to the instance that should be swaped																							\
																																										\
				Information returned to the user :																														\
																																										\
					NONE																																				\
																																										\
		  Return value :																																				\
																																										\
				NONE																																					\
																																										\
		  Expectations :																																				\
																																										\
				NONE																																					\
																																										\
		  Possible errors :																																				\
																																										\
				They will come */																																		\
																																										\
		inline void Swap( SelfType& other )																																\
		{            																																					\
            /* Swap between the instances. This works also on objects with pointer to a virtual table, because both instances point to the 								\
               same virtual table, which means the same memory address */																								\
            Memory::Operations::Swap< SelfType >( this, &other, 1UL );																									\
		}							




	// This macro will be used to create the reset method. The required arguments are :
	//
	//		MethodSpecifier - this is given to allow changing the method specifier between inline and virtual
	//		... - the name of the object that will contain the method
	// 												
	#define Reset_MACRO( MethodSpecifier )																																\
																																										\
																																										\
		/* Method Information :    																																		\
		    																																							\
		  Description :    																																				\
		    																																							\
		      Use this method to take an instance already initialized, delete the current resources and set it to default state    										\
		    																																							\
		  Required arguments :    																																		\
		    																																							\
		      User information needed :    																																\
		    																																							\
					NONE    																																			\
		    																																							\
		      Information returned to the user :    																													\
		    																																							\
		          NONE    																																				\
		    																																							\
		  Return value :    																																			\
		    																																							\
		      NONE    																																					\
		    																																							\
		  Expectations :    																																			\
		    																																							\
				NONE    																																				\
		    																																							\
		  Possible errors :    																																			\
		    																																							\
				They will come */   																																	\
		    																																							\
		MethodSpecifier void Reset()    																																\
		{    																																							\
		    /* Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it 				\
			will delete the old resources */   																															\
		    SelfType defaultConstructedInstance;    																													\
																																										\
		    /* Swap between this instance and the default constructed instance */   																					\
		    Swap( defaultConstructedInstance );    																														\
		}




// ************************************************************************************************************************************************************************** //
// **	 														   				    OBJECT														   				    	   ** //
// ************************************************************************************************************************************************************************** //




	// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
	// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
	// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
	// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
	// macro will be used to add the following methods to each object :
	//
	//		1. Assignment operator
	//		2. Move constructor
	//		3. Move assignment operator
	//		4. Swap
	//		5. Reset
	//
	#define ObjectInfrastructure_MACRO( ObjectName ) 																															\
																																										\
		AssignmentOperator_MACRO()																																		\
																																										\
		MoveConstructor_MACRO( ConsiderAsOneArgument( ObjectName ) )																																\
																																										\
		MoveAssignmentOperator_MACRO() 																																	\
																																										\
		Swap_MACRO()																																					\
																																										\
		Reset_MACRO( inline )




// ************************************************************************************************************************************************************************** //
// **														   	    	   OBJECT FOR INHERITANCE    											   				           ** //
// ************************************************************************************************************************************************************************** //




	// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
	// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
	// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
	// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
	// macro will be used to add the following methods to each object :
	//
	//		1. Assignment operator
	//		2. Move constructor
	//		3. Move assignment operator
	//		4. Swap
	//		5. Reset
	//
	#define ObjectInfrastructure_ForInheritance_MACRO( ObjectName ) 																											\
																																										\
		AssignmentOperator_MACRO()																																		\
																																										\
		MoveConstructor_MACRO( ConsiderAsOneArgument( ObjectName ) )																																\
																																										\
		MoveAssignmentOperator_MACRO() 																																	\
																																										\
		Swap_MACRO()																																					\
																																										\
		Reset_MACRO( virtual )




// ************************************************************************************************************************************************************************** //
// **									   			  		   OBJECT WITHOUT COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR									   			  	   ** //
// ************************************************************************************************************************************************************************** //




	// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
	// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
	// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
	// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
	// macro will be used to add the following methods to each object :
	//
	//		1. Move constructor
	//		2. Move assignment operator
	//		3. Swap
	//		4. Reset
	//
	#define ObjectInfrastructure_WithoutAssignmentOperator_MACRO( ObjectName ) 																							\
																																										\
		MoveConstructor_MACRO( ConsiderAsOneArgument( ObjectName ) )																																\
																																										\
		MoveAssignmentOperator_MACRO() 																																	\
																																										\
		Swap_MACRO()																																					\
																																										\
		Reset_MACRO( inline )




// ************************************************************************************************************************************************************************** //
// **    											  OBJECT FOR INHERITANCE WITHOUT COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR    										   ** //
// ************************************************************************************************************************************************************************** //




	// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
	// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
	// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
	// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
	// macro will be used to add the following methods to each object :
	//
	//		1. Move constructor
	//		2. Move assignment operator
	//		3. Swap
	//		4. Reset
	//
	#define ObjectInfrastructure_ForInheritance_WithoutAssignmentOperator_MACRO( ObjectName ) 																					\
																																										\
		MoveConstructor_MACRO( ConsiderAsOneArgument( ObjectName ) )																															\
																																										\
		MoveAssignmentOperator_MACRO() 																																	\
																																										\
		Swap_MACRO()																																					\
																																										\
		Reset_MACRO( virtual )




// ************************************************************************************************************************************************************************** //
// **														             OBJECT WITH ONLY SWAP AND RESET												 	               ** //
// ************************************************************************************************************************************************************************** //




	// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
	// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
	// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
	// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
	// macro will be used to add the following methods to each object :
	//
	//		1. Swap
	//		2. Reset
	//
	#define ObjectInfrastructure_OnlySwapAndReset_MACRO() 																										 		\
																																										\
		Swap_MACRO()																																					\
																																										\
		Reset_MACRO( inline )




// ************************************************************************************************************************************************************************** //
// **											                 OBJECT FOR INHERITANCE WITH ONLY SWAP AND RESET   											               ** //
// ************************************************************************************************************************************************************************** //




	// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
	// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
	// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
	// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
	// macro will be used to add the following methods to each object :
	//
	//		1. Swap
	//		2. Reset
	//
	#define ObjectInfrastructure_ForInheritance_OnlySwapAndReset_MACRO() 																								\
																																										\
		Swap_MACRO()																																					\
																																										\
		Reset_MACRO( virtual )





}  //  namespace Universe


#endif   // OBJECTINFRASTRUCTURE_HPP