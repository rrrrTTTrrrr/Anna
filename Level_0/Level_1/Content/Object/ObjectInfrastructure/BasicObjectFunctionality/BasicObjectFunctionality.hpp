namespace Universe
{




// ************************************************************************************************************************************************************************** //
// **														   				OBJECT INFRASTRUCTURE METHODS    												   			   ** //
// ************************************************************************************************************************************************************************** //



// The following macros will be used to add all the functionality that is similiar in each object, like an assignment operator and move 
// constructor. It is done as a macro to allow simple text manipulation, instead of inherting it through an object, which becomes a problem
// when an object inherits from 2 objects, the first is any object, but the second is an object that also inhrits from the first object. 
// This can be solved through virtual inheritance but then can only be one instance of it. Furthermore, each object in the system will need
// to inherit from it, which will cause inheritance 'chaos'




// This macro will be used to create the assignment operator. The required arguments are :
//
//		... - the name of the object that will contain the method
//
#define AssignmentOperator_Creator()																																																				\
																																																												\
																																																												\
	/* Method Information :    																																																					\
	    																																																										\
	  Description :    																																																							\
	    																																																										\
	   	Assignment operator, can handle with self assignment and instances in default state    																																					\
	    																																																										\
	  Required arguments :    																																																					\
	    																																																										\
			User information needed :    																																																		\
	    																																																										\
				other - a reference to the instance that should be copied    																																									\
	    																																																										\
			Information returned to the user :    																																																\
	    																																																										\
	          NONE    																																																							\
	    																																																										\
	  Return value :    																																																						\
	    																																																										\
	   	A reference to this instance    																																																		\	
	    																																																										\
	  Expectations :    																																																						\
	    																																																										\
			NONE    																																																							\
	    																																																										\
	  Possible errors :    																																																						\
	    																																																										\
			They will come */   																																																				\
	    																																																										\
	inline SelfType& operator=( const SelfType& other )    																																														\
	{    																																																										\
		/* Create a copy of the other instance */   																																															\
		SelfType copyOfOther( other );    																																																		\
																																																												\
		/* Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted */   																							\
		Swap( copyOfOther );    																																																				\
																																																												\
		/* Return a reference to this instance */   																																															\
		return ( *this );    																																																					\
	}




// This macro will be used to create the move constructor. The required arguments are :
//
//		... - the name of the object that will contain the method
// 												
#define MoveConstructor_Creator( ObjectName )																																																		\
																																																												\
																																																												\
	/* Method Information :    																																																					\
	    																																																										\
	  Description :    																																																							\
	    																																																										\
	   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances 																								\
			in default state    																																																				\
	    																																																										\
	  Required arguments :    																																																					\
	    																																																										\
	   	User information needed :    																																																			\
	    																																																										\
	          other - a reference to the instance that should be moved    																																										\
	    																																																										\
	      Information returned to the user :    																																																\
	    																																																										\
	          NONE    																																																							\
	    																																																										\
	  Return value :    																																																						\
	    																																																										\
	   	NONE    																																																								\
	    																																																										\
	  Expectations :    																																																						\
	    																																																										\
			NONE    																																																							\
	    																																																										\
	  Possible errors :    																																																						\
	    																																																										\
			They will come */   																																																				\
	    																																																										\
	inline ObjectName( SelfType&& other ) :    																																																	\
		SelfType()    																																																							\
	{    																																																										\
		/* Swap between this instance, which is in default state, and the other one */   																																						\
		Swap( other );    																																																						\
	}




// This macro will be used to create the move assignment operator. The required arguments are :
//
//		... - the name of the object that will contain the method
// 												
#define MoveAssignmentOperator_Creator()																																																			\
																																																												\
																																																												\
	/* Method Information :    																																																					\
	    																																																										\
	  Description :    																																																							\
	    																																																										\
	   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state    																						\
	    																																																										\
	  Required arguments :    																																																					\
	    																																																										\
	   	User information needed :    																																																			\
	    																																																										\
	          other - a reference to the instance that should be moved    																																										\
	    																																																										\
	      Information returned to the user :    																																																\
	    																																																										\
	          NONE    																																																							\
	    																																																										\
	  Return value :    																																																						\
	    																																																										\
	   	A reference to this instance    																																																		\
	    																																																										\
	  Expectations :    																																																						\
	    																																																										\
			NONE    																																																							\
	    																																																										\
	  Possible errors :    																																																						\
	    																																																										\
			They will come */   																																																				\
	    																																																										\
	inline SelfType& operator=( SelfType&& other )    																																															\
	{    																																																										\
	    /* Create a default constructed instance */   																																															\
	    SelfType defaultConstructedInstance;    																																																\
																																																												\
	    /* Swap between the temporary instance, which is in default state, and the other instance, this will leave the other instance in default state */  																						\
	    defaultConstructedInstance.Swap( other );    																																															\
																																																												\
	    /* Swap between this instance and the temporary one */   																																												\
	    Swap( defaultConstructedInstance );    																																																	\
																																																												\
	    /* Return a reference to this instance */   																																															\
	    return ( *this );    																																																					\
	}




// This macro will be used to create a swap method between instances of the object
//
#define Swap_Creator()																																																							\
																																																												\
																																																												\
	/* Method Information :																																																						\
																																																												\
	  Description :																																																								\
																																																												\
			This method is used to swap the content between this instance and the other one 																																					\
																																																												\
	  Required arguments :																																																						\
																																																												\
			User information needed :																																																			\
																																																												\
				other - a reference to the instance that should be swapped																																										\
																																																												\
			Information returned to the user :																																																	\
																																																												\
				NONE																																																							\
																																																												\
	  Return value :																																																							\
																																																												\
			NONE																																																								\
																																																												\
	  Expectations :																																																							\
																																																												\
			NONE																																																								\
																																																												\
	  Possible errors :																																																							\
																																																												\
			They will come */																																																					\
																																																												\
	inline void Swap( SelfType& other )																																																			\
	{            																																																								\
        /* Swap between the instances. This works also on objects with pointer to a virtual table, because both instances point to the 																											\
           same virtual table, which means the same memory address */																																											\
																																																												\
        /* This object will store the number of single bytes that needs to be swapped */																																						\
        UnsignedInteger8bits numberOfBytesToSwapOneByOne = sizeof( SelfType ) % 8;																																								\
        																																																										\
        /* This object will store the number of eight bytes blocks needs to be swapped */ 																																						\
        UnsignedInteger64bits numberOfEightBytesBlocksToSwap = sizeof( SelfType ) / 8; 																																							\
																																																													\
        /* This object will be used to point to the first memory segment as single bytes */ 																																					\
        UnsignedInteger8bits* memoryAddressOnThisInstancePointedAsSingleByte = reinterpret_cast< UnsignedInteger8bits* >( this ); 																												\
        																																																										\
        /* This object will be used to point to destination as blocks of 8 bytes */ 																																							\
        UnsignedInteger8bits* memoryAddressOnOtherInstancePointedAsSingleByte = reinterpret_cast< UnsignedInteger8bits* >( &other );																											\
																																																													\
        /* This object will store a copy of the current byte in this instance every iteration */ 																																				\
        UnsignedInteger8bits copyOfByteInThisInstance = 0; 																																														\
																																																													\
        /* Loop on until there is no more single elements to swap */ 																																											\
        for ( UnsignedInteger8bits currentSingleEntryIndex = 0UL ; currentSingleEntryIndex < numberOfBytesToSwapOneByOne ; ++currentSingleEntryIndex ) 																							\
        { 																																																										\
            /* Swap the current element */ 																																																		\
            copyOfByteInThisInstance = memoryAddressOnThisInstancePointedAsSingleByte[ currentSingleEntryIndex ]; 																																\
            memoryAddressOnThisInstancePointedAsSingleByte[ currentSingleEntryIndex ] = memoryAddressOnOtherInstancePointedAsSingleByte[ currentSingleEntryIndex ]; 																			\
            memoryAddressOnOtherInstancePointedAsSingleByte[ currentSingleEntryIndex ] = copyOfByteInThisInstance; 																																\
        }																																																										\
																																																													\
        /* This object will be used to point to the first memory segment as blocks of 8 bytes */ 																																				\
        UnsignedInteger64bits* memoryAddressOnThisInstancePointedAsEightBytesBlock = reinterpret_cast< UnsignedInteger64bits* >( reinterpret_cast< UnsignedInteger8bits* >( this ) + numberOfBytesToSwapOneByOne ); 							\
																																																													\
        /* This object will be used to point to second array as blocks of 8 bytes */ 																																							\
        UnsignedInteger64bits* memoryAddressOnOtherInstancePointedAsEightBytesBlock = reinterpret_cast< UnsignedInteger64bits* >( reinterpret_cast< UnsignedInteger8bits* >( &other ) + numberOfBytesToSwapOneByOne ); 							\
																																																													\
    	/* This object will store a copy of the current eight bytes in this instance every iteration */ 																																		\
        UnsignedInteger64bits copyOfEightBytesInThisInstance = 0;																																												\
																																																													\
        /* Loop on until there is no more 8 bytes blocks to swap */																																												\
        for ( UnsignedInteger64bits currentEightBytesBlockIndex = 0 ; currentEightBytesBlockIndex < numberOfEightBytesBlocksToSwap ; ++currentEightBytesBlockIndex )																			\
        { 																																																										\
            /* Swap the current eight bytes */ 																																																	\
            copyOfEightBytesInThisInstance = memoryAddressOnThisInstancePointedAsEightBytesBlock[ currentEightBytesBlockIndex ]; 																												\
            memoryAddressOnThisInstancePointedAsEightBytesBlock[ currentEightBytesBlockIndex ] = memoryAddressOnOtherInstancePointedAsEightBytesBlock[ currentEightBytesBlockIndex ]; 															\
            memoryAddressOnOtherInstancePointedAsEightBytesBlock[ currentEightBytesBlockIndex ] = copyOfEightBytesInThisInstance; 																												\
        } 																																																										\
	}							




// This macro will be used to create the reset method. The required arguments are :
//
//		MethodSpecifier - this is given to allow changing the method specifier between inline and virtual
//		... - the name of the object that will contain the method
// 												
#define Reset_Creator( MethodSpecifier )																																																			\
																																																												\
																																																												\
	/* Method Information :    																																																					\
	    																																																										\
	  Description :    																																																							\
	    																																																										\
	      Use this method to take an instance already initialized, delete the current resources and set it to default state    																													\
	    																																																										\
	  Required arguments :    																																																					\
	    																																																										\
	      User information needed :    																																																			\
	    																																																										\
				NONE    																																																						\
	    																																																										\
	      Information returned to the user :    																																																\
	    																																																										\
	          NONE    																																																							\
	    																																																										\
	  Return value :    																																																						\
	    																																																										\
	      NONE    																																																								\
	    																																																										\
	  Expectations :    																																																						\
	    																																																										\
			NONE    																																																							\
	    																																																										\
	  Possible errors :    																																																						\
	    																																																										\
			They will come */   																																																				\
	    																																																										\
	MethodSpecifier void Reset()    																																																			\
	{    																																																										\
	    /* Create a default constructed instance. Swap it with this instance, which will be left in default state. When control leaves this method it 																							\
		will delete the old resources */   																																																		\
	    SelfType defaultConstructedInstance;    																																																\
																																																												\
	    /* Swap between this instance and the default constructed instance */   																																								\
	    Swap( defaultConstructedInstance );    																																																	\
	}



// ************************************************************************************************************************************************************************** //
// **														   		COMPARE INSTANCES THAT CAN CONTAIN NULL POINTERS                                                       ** //
// ************************************************************************************************************************************************************************** //



// This macro should be used when comparing instances that has pointers that can be NULL. If both instances has the pointer as NULL, it
// will return true, and if only one instance has the pointer has NULL it will return false
//
#define CompareInstancesPointers( thisPointer, otherPointer ) ReturnValueIfExpressionIsTrue( ( thisPointer == otherPointer ) && ( thisPointer == nullptr ), true ); ReturnValueIfExpressionIsTrue( ( thisPointer == nullptr ) && ( otherPointer == nullptr ), false )



// ************************************************************************************************************************************************************************** //
// **	 														   				    OBJECT														   				    	   ** //
// ************************************************************************************************************************************************************************** //



// Use this macro in objects that require all the functionality :
//
//		1. Assignment operator
//		2. Move constructor
//		3. Move assignment operator
//		4. Swap
//		5. Reset
//
#define ObjectInfrastructure( ObjectName ) 																																																\
																																																												\
	AssignmentOperator_Creator()																																																					\
																																																												\
	MoveConstructor_Creator( ObjectName )																																																			\
																																																												\
	MoveAssignmentOperator_Creator() 																																																				\
																																																												\
	Swap_Creator()																																																								\
																																																												\
	Reset_Creator( inline )



// ************************************************************************************************************************************************************************** //
// **														   	    	   OBJECT FOR INHERITANCE    											   				           ** //
// ************************************************************************************************************************************************************************** //



// Use this macro in objects that require all the functionality, and are meant to be used in inheritance :
//
//		1. Assignment operator
//		2. Move constructor
//		3. Move assignment operator
//		4. Swap
//		5. Reset
//
#define ObjectInfrastructure_ForInheritance( ObjectName ) 																																												\
																																																												\
	AssignmentOperator_Creator()																																																					\
																																																												\
	MoveConstructor_Creator( ObjectName )																																																			\
																																																												\
	MoveAssignmentOperator_Creator() 																																																				\
																																																												\
	Swap_Creator()																																																								\
																																																												\
	Reset_Creator( virtual )



// ************************************************************************************************************************************************************************** //
// **	 					   			 OBJECT WITHOUT THE ABILITY TO COPY ITSELF ( NO COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR )										   ** //
// ************************************************************************************************************************************************************************** //



// Use this macro in objects that require all the functionality :
//
//		1. Move constructor
//		2. Move assignment operator
//		3. Swap
//		4. Reset
//
#define ObjectInfrastructureWithoutTheAbilityToCopyItself( ObjectName ) 																																									\
																																																												\
	MoveConstructor_Creator( ObjectName )																																																			\
																																																												\
	MoveAssignmentOperator_Creator() 																																																				\
																																																												\
	Swap_Creator()																																																								\
																																																												\
	Reset_Creator( inline )



// ************************************************************************************************************************************************************************** //
// **	 					   		OBJECT WITHOUT THE ABILITY TO COPY ITSELF ( NO COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR ) FOR INHERITANCE						       ** //
// ************************************************************************************************************************************************************************** //



// Use this macro in objects that require all the functionality, and are meant to be used in inheritance :
//
//		1. Move constructor
//		2. Move assignment operator
//		3. Swap
//		4. Reset
//
#define ObjectInfrastructureWithoutTheAbilityToCopyItself_ForInheritance( ObjectName ) 																																					\
																																																												\
	MoveConstructor_Creator( ObjectName )																																																			\
																																																												\
	MoveAssignmentOperator_Creator() 																																																				\
																																																												\
	Swap_Creator()																																																								\
																																																												\
	Reset_Creator( virtual )



// ************************************************************************************************************************************************************************** //
// **											                          INFRASTRUCTURE FOR INTERFACE   											                       ** //
// ************************************************************************************************************************************************************************** //



// Use this macro in interfaces that require all the functionality, and are meant to be used in inheritance :
//
//		1. Defualt constructor
//		2. Copy constructor
//		3. Assignment operator
//		4. Move constructor
//		5. Move assignment operator
//		6. Destructor
//
#define InterfaceInfrastructure_ForInheritance( ObjectName ) 																																												\
																																																												\
	inline ObjectName() = default;																																																				\
																																																												\
	inline ObjectName( const SelfType& other ) = default;																																														\
																																																												\
	inline SelfType& operator=( const SelfType& other ) = default;																																												\
																																																												\
	inline ObjectName( SelfType&& other ) = default;																																															\
																																																												\
	inline SelfType& operator=( SelfType&& other ) = default;																																													\
																																																												\
	virtual ~ObjectName() = default;



}  //  namespace Universe