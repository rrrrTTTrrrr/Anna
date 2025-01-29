namespace Universe
{


namespace User
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
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class WriteToStandardOutput NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = WriteToStandardOutput;


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
	inline WriteToStandardOutput();


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
	inline ~WriteToStandardOutput() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to write to standard output the state of the bits for the value
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          value - the value that the bits will be displayed for
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//		A reference to this insance, to allow chaining calls
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
    template< Concepts::BuiltIn BuiltInType >
	inline const WriteToStandardOutput& Bits( const BuiltInType value ) const;


	// The following methods declare the overloaded operators for the object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to write the content of an object that can be converted to string to the screen for the user to view
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    value - a constant reference to an object that can be converted to string
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to this insance, to allow chaining calls
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
	template< Concepts::ConvertibleToString ConvertibleToStringType > requires ( !Concepts::SameAs< ConvertibleToStringType, AsciiCharacter* > )
	inline const WriteToStandardOutput& operator<<( const ConvertibleToStringType& value ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to write the content of a boolean to the screen for the user to view
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    value - a boolean value
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to this insance, to allow chaining calls
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		NONE
	//
	inline const WriteToStandardOutput& operator<<( const Boolean value ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to write the content of an ascii literal to the screen for the user to view
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    asciiLiteral - a pointer with the memory address of the ascii literal
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to this insance, to allow chaining calls
	//
	//  Expectations :
	//
	//		1. The given pointer is not NULL
	//		2. The size of ascii literal is larger then 0
	//		3.
	//
	//  Possible errors :
	//
	//		NONE
	//			
	inline const WriteToStandardOutput& operator<<( const AsciiCharacter* const asciiLiteral ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to write the content of a string to the screen for the user to view
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    string - a constant reference to a string
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to this insance, to allow chaining calls
	//
	//  Expectations :
	//
	//		1. Currently only the english language is supported for displaying
	//		2.
	//
	//  Possible errors :
	//
	//		1. There is no more free memory space - Class std::bad_alloc is thrown
	//		2. 
	//
	inline const WriteToStandardOutput& operator<<( const Language::String& string ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to write the content of a sequential data structure with strings to the screen for the user to view
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    strings - a constant reference to a sequential data structure that contains strings
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to this insance, to allow chaining calls
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
	inline const WriteToStandardOutput& operator<<( const SequentialDataStructure< Language::String >& strings ) const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to write the content of a sequential data structure, as long as the data is built in, to the screen for the user to view
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    contentToDisplay - a constant reference to a sequential data structure that contains built in data
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		A reference to this insance, to allow chaining calls
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
	template< Concepts::ConvertibleToString ConvertibleToStringType >
	inline const WriteToStandardOutput& operator<<( const SequentialDataStructure< ConvertibleToStringType >& contentToDisplay ) const;


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
		static void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
	DisableCopyAndMove( WriteToStandardOutput );


	// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
	// the interface, but rather help implement it :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to move the cursor on the scrren one line down
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
	//		A reference to this insance, to allow chaining calls
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
    inline const WriteToStandardOutput& MoveCursorLineDown__Private() const;


};  //  Class WriteToStandardOutput



inline WriteToStandardOutput output;