namespace Universe
{



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
//		1. This object is used only to wrap some static methods, which can be used without any instance of the object
//
//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
//
// 		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class Loop NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Loop;


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
	// or some functionality needed that does not involve the non static data members


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pass on all the required entries of the source and copy them to the target
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. instance - the instance of which the entires will be set
	//			2. startingIndex - the index from which the set will start on the target
	//			3. size - the number of entries to set
	//			4. data - a constant reference to the data set the entries with
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
	//		1. The size of the instance must be larger then 0
	//		2. The size to set must be larger then 0
	//		3. The index to start from on the target should be smaller then the size of the target
	//		4. The size left in the instance after the starting index should be larger or equal to the size to set
	//		5.
	//
	//  Possible errors :
	//
	//      They will come
	//
    template< typename MemoryHandlerButNotVectorType > requires ( CompareRegardlessOfTemplateArguments< MemoryHandlerButNotVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == false )
    static inline void Set( MemoryHandlerButNotVectorType& instance, const LargestUnsignedInteger startingIndex, const LargestUnsignedInteger size, const typename MemoryHandlerButNotVectorType::MemoryHandlerButNotVectorType& data );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pass on all the required entries of the source and copy them to the target. This version is for cases where
	//		the two memory handler are of type - Vector. In this case the memory is contiguous and the operation can be performed much faster
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. instance - the instance of which the entires will be set
	//			2. startingIndex - the index from which the set will start on the target
	//			3. size - the number of entries to set
	//			4. data - a constant reference to the data set the entries with
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
	//		1. The size of the instance must be larger then 0
	//		2. The size to set must be larger then 0
	//		3. The index to start from on the target should be smaller then the size of the target
	//		4. The size left in the instance after the starting index should be larger or equal to the size to set
	//		5.
	//
	//  Possible errors :
	//
	//      They will come
	//
    template< typename VectorType > requires ( CompareRegardlessOfTemplateArguments< VectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true )
    static inline void Set( VectorType& instance, const LargestUnsignedInteger startingIndex, const LargestUnsignedInteger size, const typename VectorType::SelfDataType& data );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pass on all the required entries of the source and copy them to the target
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. destination - the instance of which the entires will be assigned
	//          2. source - the instance of from the data will be taken to assign the target entries
	//			3. destinationStartingIndex - the index from which the assignment will start on the target
	//			4. sourceStartingIndex - the index from which the assignment will start from the source
	//			5. size - the number of entries to assign from the source into the target
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
	//		1. The size to copy target must be larger then 0
	//		2. The size to copy source must be larger then 0
	//		3. The size to assign must be larger then 0
	//		4. The index to start from on the assignment target should be smaller then the size to copy target
	//		5. The index to start from on the assignment source should be smaller then the size to copy source
	//		6. The size to copy target minus the index to start from should be larger or equal then the size to assign
	//		7. The size to copy source minus the index to start from should be larger or equal then the size to assign
	//		8.
	//
	//  Possible errors :
	//
	//      They will come
	//
	template< typename DestinationMemoryHandlerButNotVectorType, typename SourceMemoryHandlerButNotVectorType > requires ( CompareRegardlessOfTemplateArguments< DestinationMemoryHandlerButNotVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == false && CompareRegardlessOfTemplateArguments< SourceMemoryHandlerButNotVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == false && CompareTypes< typename DestinationMemoryHandlerButNotVectorType::SelfDataType, typename SourceMemoryHandlerButNotVectorType::SelfDataType >::Result == true )
	static inline void Copy( DestinationMemoryHandlerButNotVectorType& destination, const SourceMemoryHandlerButNotVectorType& source, const LargestUnsignedInteger destinationStartingIndex, const LargestUnsignedInteger sourceStartingIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pass on all the required entries of the source and copy them to the target. This version is for cases where
	//		the two memory handler are of type - Vector. In this case the memory is contiguous and the operation can be performed much faster
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. destination - the instance of which the entires will be assigned
	//          2. source - the instance of from the data will be taken to assign the target entries
	//			3. destinationStartingIndex - the index from which the assignment will start on the target
	//			4. sourceStartingIndex - the index from which the assignment will start from the source
	//			5. size - the number of entries to assign from the source into the target
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
	//		1. The size to copy target must be larger then 0
	//		2. The size to copy source must be larger then 0
	//		3. The size to assign must be larger then 0
	//		4. The index to start from on the assignment target should be smaller then the size to copy target
	//		5. The index to start from on the assignment source should be smaller then the size to copy source
	//		6. The size to copy target minus the index to start from should be larger or equal then the size to assign
	//		7. The size to copy source minus the index to start from should be larger or equal then the size to assign
	//		8.
	//
	//  Possible errors :
	//
	//      They will come
	//
	template< typename DestinationVectorType, typename SourceVectorType > requires ( CompareRegardlessOfTemplateArguments< DestinationVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareRegardlessOfTemplateArguments< SourceVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareTypes< typename DestinationVectorType::SelfDataType, typename SourceVectorType::SelfDataType >::Result == true )
	static inline void Copy( DestinationVectorType& destination, const SourceVectorType& source, const LargestUnsignedInteger destinationStartingIndex, const LargestUnsignedInteger sourceStartingIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pass on all the required entries of the source and move them to the target
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. destination - the instance of which the entires will be assigned
	//          2. source - the instance of from the data will be taken to assign the target entries
	//			3. destinationStartingIndex - the index from which the assignment will start on the target
	//			4. sourceStartingIndex - the index from which the assignment will start from the source
	//			5. size - the number of entries to assign from the source into the target
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
	//		1. The size to move target must be larger then 0
	//		2. The size to move source must be larger then 0
	//		3. The size to assign must be larger then 0
	//		4. The index to start from on the assignment target should be smaller then the size to move target
	//		5. The index to start from on the assignment source should be smaller then the size to move source
	//		6. The size to move target minus the index to start from should be larger or equal then the size to assign
	//		7. The size to move source minus the index to start from should be larger or equal then the size to assign
	//		8.
	//
	//  Possible errors :
	//
	//      They will come
	//
	template< typename DestinationMemoryHandlerButNotVectorType, typename SourceMemoryHandlerButNotVectorType > requires ( CompareRegardlessOfTemplateArguments< DestinationMemoryHandlerButNotVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == false && CompareRegardlessOfTemplateArguments< SourceMemoryHandlerButNotVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == false && CompareTypes< typename DestinationMemoryHandlerButNotVectorType::SelfDataType, typename SourceMemoryHandlerButNotVectorType::SelfDataType >::Result == true )
	static inline void Move( DestinationMemoryHandlerButNotVectorType& destination, SourceMemoryHandlerButNotVectorType&& source, const LargestUnsignedInteger destinationStartingIndex, const LargestUnsignedInteger sourceStartingIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pass on all the required entries of the source and move them to the target. This version is for cases where
	//		the two memory handler are of type - Vector. In this case the memory is contiguous and the operation can be performed much faster
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. destination - the instance of which the entires will be assigned
	//          2. source - the instance of from the data will be taken to assign the target entries
	//			3. destinationStartingIndex - the index from which the assignment will start on the target
	//			4. sourceStartingIndex - the index from which the assignment will start from the source
	//			5. size - the number of entries to assign from the source into the target
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
	//		1. The size to move target must be larger then 0
	//		2. The size to move source must be larger then 0
	//		3. The size to assign must be larger then 0
	//		4. The index to start from on the assignment target should be smaller then the size to move target
	//		5. The index to start from on the assignment source should be smaller then the size to move source
	//		6. The size to move target minus the index to start from should be larger or equal then the size to assign
	//		7. The size to move source minus the index to start from should be larger or equal then the size to assign
	//		8.
	//
	//  Possible errors :
	//
	//      They will come
	//
	template< typename DestinationVectorType, typename SourceVectorType > requires ( CompareRegardlessOfTemplateArguments< DestinationVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareRegardlessOfTemplateArguments< SourceVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareTypes< typename DestinationVectorType::SelfDataType, typename SourceVectorType::SelfDataType >::Result == true )
	static inline void Move( DestinationVectorType& destination, SourceVectorType&& source, const LargestUnsignedInteger destinationStartingIndex, const LargestUnsignedInteger sourceStartingIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pass on all the required entries of the instances and compare them
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. firstInstance - the first instance to be compared
	//          2. secondInstance - the second instance to be compared
	//			3. firstInstanceStartingIndex - the index from which comparison will start on the first instance
	//			4. secondInstanceStartingIndex - the index from which comparison will start on the second instance
	//			5. size - the number of entries to compare between the instances
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      True in case all the data in the entries of both the instances match, and false otherwise
	//
	//  Expectations :
	//
	//		1. The size of the first instance must be larger then 0
	//		2. The size of the second instance must be larger then 0
	//		3. The size to compare must be larger then 0
	//		4. The index to start from on the first instance should be smaller then the size of the first instance
	//		5. The index to start from on the second instance should be smaller then the size of the second instance
	//		6. The size of the first instance minus the index to start from should be larger or equal then the size to compare
	//		7. The size of the second instance minus the index to start from should be larger or equal then the size to compare
	//		8.
	//
	//  Possible errors :
	//
	//      They will come
	//
	template< typename FirstMemoryHandlerType, typename SecondMemoryHandlerType > requires ( ( CompareRegardlessOfTemplateArguments< FirstMemoryHandlerType, Memory::Vector< LargestUnsignedInteger > >::Result == false || CompareRegardlessOfTemplateArguments< SecondMemoryHandlerType, Memory::Vector< LargestUnsignedInteger > >::Result == false ) && CompareTypes< typename FirstMemoryHandlerType::SelfDataType, typename SecondMemoryHandlerType::SelfDataType >::Result == true )
	EnsureRetrunValueIsUsed static inline Boolean Compare( const FirstMemoryHandlerType& firstInstance, const SecondMemoryHandlerType& secondInstance, const LargestUnsignedInteger firstInstanceStartingIndex, const LargestUnsignedInteger secondInstanceStartingIndex, const LargestUnsignedInteger size );


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to pass on all the required entries of the instances and compare them
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. firstInstance - the first instance to be compared
	//          2. secondInstance - the second instance to be compared
	//			3. firstInstanceStartingIndex - the index from which comparison will start on the first instance
	//			4. secondInstanceStartingIndex - the index from which comparison will start on the second instance
	//			5. size - the number of entries to compare between the instances
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      True in case all the data in the entries of both the instances match, and false otherwise
	//
	//  Expectations :
	//
	//		1. The size of the first instance must be larger then 0
	//		2. The size of the second instance must be larger then 0
	//		3. The size to compare must be larger then 0
	//		4. The index to start from on the first instance should be smaller then the size of the first instance
	//		5. The index to start from on the second instance should be smaller then the size of the second instance
	//		6. The size of the first instance minus the index to start from should be larger or equal then the size to compare
	//		7. The size of the second instance minus the index to start from should be larger or equal then the size to compare
	//		8.
	//
	//  Possible errors :
	//
	//      They will come
	//
    template< typename FirstMemoryHandlerVectorType, typename SecondMemoryHandlerVectorType > requires ( CompareRegardlessOfTemplateArguments< FirstMemoryHandlerVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareRegardlessOfTemplateArguments< SecondMemoryHandlerVectorType, Memory::Vector< LargestUnsignedInteger > >::Result == true && CompareTypes< typename FirstMemoryHandlerVectorType::SelfDataType, typename SecondMemoryHandlerVectorType::SelfDataType >::Result == true )
    EnsureRetrunValueIsUsed static inline Boolean Compare( const FirstMemoryHandlerVectorType& firstInstance, const SecondMemoryHandlerVectorType& secondInstance, const LargestUnsignedInteger firstInstanceStartingIndex, const LargestUnsignedInteger secondInstanceStartingIndex, const LargestUnsignedInteger size );


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
		static void UnitTest() __attribute__ (( __unused__ )) {}

	)  //  End of debug tool


private:


	// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
	NoInstances( Loop );


};  //  Class Loop