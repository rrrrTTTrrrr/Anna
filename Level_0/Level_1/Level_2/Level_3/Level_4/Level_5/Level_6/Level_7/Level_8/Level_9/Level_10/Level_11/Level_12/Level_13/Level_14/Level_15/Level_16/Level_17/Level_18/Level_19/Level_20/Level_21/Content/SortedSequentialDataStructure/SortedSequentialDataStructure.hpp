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
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< Concepts::RawButPointerIsAllowed DataType, typename MemoryManagerType = Memory::MainMemoryManager >
class SortedSequentialDataStructure NotForInheritance
{
private:


	// The following object will be used to determine properties on the given template type. These properties will be used to determine the
	// behavior and the methods that object will contain according to the template type. This is needed because this object is a template,
	// therefore the deduction of the template type is done on the all object and before any method declaration. To workaround this issue
	// the method must have also a template parameter, to make the compiler perform the template type deduction on the method itself as
	// well only when the template type is known
	template< typename DummyType >
	class TypeCheckRequirements
	{
	public:


		// This is the method that will do the actual checking. It will detect if the template type has at least one of the operators '>' or
		// '<' implemented
		static constexpr Boolean DoesTypeImplementIsLargerOrIsSmallerOperators()
		{
			// Check if the template type has implemented at least one of the operators '<' or '>', and return the result
			return ( OperatorDetector_Larger< DataType >::Result() == true || OperatorDetector_Smaller< DataType >::Result() == true );
		}


		// This is the method that will do the actual checking. It will detect if the template type has not implemented any of the operators
		// '>' or '<'
		static constexpr Boolean DoesTypeDoNotImplementIsLargerOrIsSmallerOperators()
		{
			// Check if the template type has not implemented any one of the operators '<' or '>', and return the result
			return ( OperatorDetector_Larger< DataType >::Result() == false && OperatorDetector_Smaller< DataType >::Result() == false );
		}


		// This is the method that will do the actual checking. It will detect if the template type has implemented the operator '>'
		static constexpr Boolean DoesTypeImplementIsLargerOperator()
		{
			// Check if the template type has implemented the operator '>', and return the result
			return ( OperatorDetector_Larger< DataType >::Result() == true );
		}


		// This is the method that will do the actual checking. It will detect if the template type has implemented the operator '<',
		// but not the '>' operator
		static constexpr Boolean DoesTypeImplementIsSmallerOperatorButNotIsLargerOperator()
		{
			// Check if the template type has implemented the operator '<' but not the '>', and return the result
			return ( OperatorDetector_Larger< DataType >::Result() == false && OperatorDetector_Smaller< DataType >::Result() == true );
		}


	};


public:


	// Create a type definition for this object
	using SelfType = SortedSequentialDataStructure< DataType, MemoryManagerType >;

	// Create a type definition for the 'isLarger' function type
	using SelfIsLargerFunctioType = Boolean ( const DataType&, const DataType& );


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


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
	//			memoryHandlerName - the enumeration of the memory handler to use
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
	template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::DoesTypeImplementIsLargerOrIsSmallerOperators() == true, Boolean >::Type = true >
	explicit inline SortedSequentialDataStructure( const MemoryHandlerName memoryHandlerName = MemoryHandlerName::Vector ) :
		member_sequentialDataStructure( memoryHandlerName ),
		member_isLargerFunctionPointer()
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
	template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::DoesTypeDoNotImplementIsLargerOrIsSmallerOperators() == true, Boolean >::Type = true >
	inline SortedSequentialDataStructure( const MemoryHandlerName memoryHandlerName, const FunctionPointer< SelfIsLargerFunctioType >& isLargerFunctionPointer ) :
		member_sequentialDataStructure( memoryHandlerName ),
		member_isLargerFunctionPointer( isLargerFunctionPointer )
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
	//		    other - a reference to the instance that should be copied
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
	inline SortedSequentialDataStructure( const SelfType& other );


	// Add the following infrastructure to the object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( SortedSequentialDataStructure )


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
	inline ~SortedSequentialDataStructure() = default;


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_FromMemberGetMethod_Creator( /* GetMethodName */ Size, /* MemberName */ member_sequentialDataStructure, /* MemberGetMethodName */ Size, /* MemberType */ LargestUnsignedInteger )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to add data to the instance. The new data will be added to the required location according to its proportion
	//		to the existing data in the instance
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			data - a universal reference to a data to add
	//
	//      Information returned to the user :
	//
	//          NONE
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
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	template< typename UniversalReferenceDataType > requires ( CompareTypesRegardlessOfQualifiersAndReference< UniversalReferenceDataType, DataType >::Result == true )
	inline void Insert( UniversalReferenceDataType&& data );


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the location of a single element in the data. There might multiple apperances of the data, the
	//		method will return the location only of one of them, and it is not guranteed to be the first
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			data - the data to search for in the instance
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A tuple with the first entry containing a boolean to describe if the data was found or not. If it was found the boolean 
	//		will contain true, then the second entry will contain the index that the data was found at
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Memory::Tuple< Boolean, LargestUnsignedInteger > SearchSingleElement( const DataType& data ) const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get a view on the data considered highest value in the instance
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A constant reference to the data considered highest value in the instance
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const DataType& PeakTop() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get a view on the data considered lowest value in the instance
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A constant reference to the data considered lowest value in the instance
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline const DataType& PeakBottom() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to remove the data considered highest value in the instance, and return a copy of it
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A copy of the data considered highest value in the instance
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline DataType PopTop();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to remove the data considered lowest value in the instance, and return a copy of it
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A copy of the data considered lowest value in the instance
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline DataType PopBottom();


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    other - a reference to the instance that should be compared with this object
	//
	//		Information returned to the user :
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
	EnsureRetrunValueIsUsed inline Boolean operator==( const SelfType& other ) const;


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
	//		    other - a reference to the instance that should be compared with this object
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
	EnsureRetrunValueIsUsed inline Boolean operator!=( const SelfType& other ) const;


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
		static inline void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// This sequential data structure will store the sorted data
	SequentialDataStructure< DataType, MemoryManagerType > member_sequentialDataStructure;

	// This function pointer will store the memory address of the function that will be used to determine if the left side operand
	// is larger then the right side operand, in case the type does not have those operators implemented
	FunctionPointer< SelfIsLargerFunctioType > member_isLargerFunctionPointer;


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to get the location of a single element in the data. There might multiple apperances of the data, the
	//		method will return the location only of one of them, and it is not guranteed to be the first
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//			data - the data to search for in the instance
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	A tuple with the first entry containing a boolean to describe if the data was found or not. If it was found the boolean 
	//		will contain true, then the second entry will contain the index that the data was found at
	//
	//  Expectations :
	//
	//		1. The instance should be ready
	//		2.
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Memory::Tuple< Boolean, LargestUnsignedInteger > SearchSingleElement__Private( const DataType& data ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check which operand is larger. This overload is for cases where the data type object has implemented
	//		the is larger operator '>'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    1. leftSideOperand - a constant reference to the operand to check if is larger
	//			2. rightSideOperand - a constant reference to the operand to check if is smaller
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A boolean with the value true if the left side operand is larger then the right one, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::DoesTypeImplementIsLargerOperator() == true, Boolean >::Type = true >
	EnsureRetrunValueIsUsed inline Boolean IsLarger__Private( const DataType& leftSideOperand, const DataType& rightSideOperand ) const
	{
		// Check if the left side operand is larger then the right one and return the result
		return ( leftSideOperand > rightSideOperand );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check which operand is larger. This overload is for cases where the data type object has implemented
	//		the is smaller operator '<'
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    1. leftSideOperand - a constant reference to the operand to check if is larger
	//			2. rightSideOperand - a constant reference to the operand to check if is smaller
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A boolean with the value true if the left side operand is larger then the right one, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::DoesTypeImplementIsSmallerOperatorButNotIsLargerOperator() == true, Boolean >::Type = true >
	EnsureRetrunValueIsUsed inline Boolean IsLarger__Private( const DataType& leftSideOperand, const DataType& rightSideOperand ) const
	{
		// Check if the left side operand is smaller then the right one and return the negotiated result
		return ( !( leftSideOperand < rightSideOperand ) );
	}


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to check which operand is larger. This overload is for cases where the data type object has not implemented
	//		the is smaller operator '<' or is larger operator '>', and therefore the user must provide a function to perform the check
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    1. leftSideOperand - a constant reference to the operand to check if is larger
	//			2. rightSideOperand - a constant reference to the operand to check if is smaller
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A boolean with the value true if the left side operand is larger then the right one, and false otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename DummyType = void, typename ProvideTypeOnlyIfAssertionIsTrue< TypeCheckRequirements< DummyType >::DoesTypeDoNotImplementIsLargerOrIsSmallerOperators() == true, Boolean >::Type = true >
	EnsureRetrunValueIsUsed inline Boolean IsLarger__Private( const DataType& leftSideOperand, const DataType& rightSideOperand ) const
	{
		// Use the user provided function to check if the left side operand is larger then the right side one, and return the result
		return ( member_isLargerFunctionPointer( leftSideOperand, rightSideOperand ) );
	}


};  //  Class SortedSequentialDataStructure