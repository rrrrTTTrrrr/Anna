namespace Universe
{


namespace Language
{



// typename :
//
// The keyword typename was introduced to specify that the identifier that follows is a type. Consider the following example:
//
//      template <class T>
//      Class MyClass
//      {
//          typename T::SubType * ptr;
//          ...
//      };
//
// Here, typename is used to clarify that SubType is a type of class T. Thus, ptr is a pointer to the type T::SubType. Without typename, 
// SubType would be considered a static member. Thus :
//
//      T::SubType * ptr
//
// would be a multiplication of value SubType of type T with ptr



// One of the primary goal when overloading operator() is to create a functor. A functor acts just like a function, but it has the 
// advantages that it is stateful, meaning it can keep data reflecting its state between calls. 
//
// Here is a simple functor example :
// 
//      struct Count
//      {
//          int counter = 0;
//  
//          int operator()( int integer ) { return ( counter += integer ); }
//      }
//
//      Count countThis;
//      std::cout << countThis( 10 ) << std::endl;      // Display "10"
//      std::cout << countThis( 20 ) << std::endl;      //prints "30"
//
// Functors are heavily used with generic programming. The purpose is to be able to plug-in custom function or functor when needed.
//
// For example,
//
//      template< typename Functor >
//      void DoSomething( Functor functor )
//      {}
//
// This is very generic since it is parametrized by a function. By using the operator(), this function lets you use either a functor 
// or a function pointer



// std::uncaught_exception :
//
// This function is used to detect if an exception is currently active! this is important because throwing exception when another exception 
// is active will cause the call of the terminate function, and the end of the program
//
// Returns true if an exception has been thrown but the initialization of the exception declaration in the matching handler ( including 
// an automatic call to unexpected or terminate ) is not yet complete. Or in other words, it returns true if an exception has been thrown 
// and has not yet been handled by its appropriate catch handler, including stack unwinding
//
// Returns false in all other cases, including when unexpected or terminate is explicitly called by the program



// The keyword inline is not allowed in declaration of friend template specialization



// When declaring an outside template method friend with an class template, all instances of that methods no matter the template object 
// are friends with all instances of the object no matter the template object also here, meaning AutomaticPointer< int > will be friends 
// with operator*< double >, Therefore this two declarations are made. operator* is declared as a template method using a declared ( but 
// not yet defined ) templated class. AutomaticPointer then defines the template instantiation of operator* matching the template 
// instantiation of AutomaticPointer as a friend. Note - no exception specification on purpose, becuase when using templates there is 
// no way of knowing what the given type will throw



// Operator "->" :
//
//      someClass->Something()
//
// Will be converted by the compiler to the following statement :
//
//      someClass.operator->()->Something()
//
// The first call to the overloaded operator-> gives a pointer of some type which has an accessible member function called Something



// The keyword inline is not allowed in declaration of friend template specialization



// When declaring an outside template method friend with an class template, all instances of that methods no matter the template object are friends with all instances 
// of the object no matter the template object also here, meaning Pointer< int > will be friends with operator*< double >, Therefore this two declarations are made. 
// operator* is declared  as a template method using a declared ( but not yet defined ) templated class. Pointer then defines the template instantiation of operator* 
// matching the template instantiation of Pointer as a friend. Note - no exception specification on purpose, becuase when using templates there is no way of knowing 
// what the given type will throw



// Namespaces avoid name clashes. Polymorphism is outside their charter!



// Operator "->" :
//
//  someClass->Something()
//
// Will be converted by the compiler to the following statement :
//
//  someClass.operator->()->Something()
//
// The first call to the overloaded operator-> gives a pointer of some type which has an accessible member function called Something



// C++ has two kinds of enumeration :
//
//  1. enum classes
//  2. Plain enums
//
//  Here are a couple of examples how to declare them :
//
//      enum class Color { red, green, blue }; // enum class
//      enum Animal { dog, cat, bird, human }; // plain enum 
//
// What is the difference between two?
//
//  enum classes - enumerator names are local to the enum and their values do not implicitly convert to other types ( like another enum or int )
//  Plain enums - where enumerator names are in the same scope as the enum and their values implicitly convert to integers and other types
//
// Enum classes should be preferred because they cause fewer surprises that could potentially lead to bugs



// To overload operator "++" for prefix and postfix use the following syntax :
//
//      class Number 
//      {
//      public:
//
//          Number& operator++ ();     // prefix ++: no parameter, returns a reference
//          Number  operator++ (int);  // postfix ++: dummy parameter, returns a value
//
//      };



// When a template specialization is created, it is an entirly different object. All the interface and data members must be redeclared!



// Class Information :
//
//  Purpose :
//
//		This object will represent a unicode character
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
class Character NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = Character;


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
	//			character - this will be used to initialize the instance
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
	//		1. The given character should be valid, this means a value between [0 - 1114111)
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	explicit inline Character( const UnsignedInteger32bits character = 0U );


	// Method Information :
	//
	//  Description :
	//
	//		Constructor, to allow converting ascii characters
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//			asciiCharacter - an ascii character that will be used to initialize the instance
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
	//		1. The given character should be valid ascii character ( 1 - 127 )
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline Character( const AsciiCharacter asciiCharacter );


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
	inline Character( const SelfType& other );


	// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done
	// as a macro to allow simple text manipulation, instead of inherting it through an object, which becomes a problem when an object
	// inherits from 2 objects, the first is any object, but the second is an object that also inhrits from the first object. This can be
	// solved through virtual inheritance but then can only be one instance of it. Furthermore, each object in the system will need to
	// inherit from it, which will cause inheritance 'chaos'. Therefore, this macro will be used to add the following methods to each object :
	//
	//		1. Assigenment operator
	//		2. Move constructor
	//		3. Move assigenment operator
	//		4. Swap
	//		5. Reset
	//
	ObjectInfrastructure( Character )


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
	inline ~Character() = default;


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to check if the current character value represents an ascii character
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
	//		If the current character represents an ascii character then true is returned, otherwise false
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsAsciiCharacter() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get the value as built in ascii character
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    NONE
	//
	//		Information returned to the user :
	//
	//			NONE
	//
	//  Return value :
	//
	//		Built in ascii character
	//
	//  Expectations :
	//
	//		1. The value inside the instance represents an ascii character
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline AsciiCharacter GetAsAsciiCharacter() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to check if the current character value represent a digit
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
	//		If the current character represent a digit then true is returned, otherwise false
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsDigit() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to check if the current character value represent an English letter in the capital form
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
	//		If the current character represent an English capital letter then true is returned, otherwise false
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsEnglishCapitalLetter() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to check if the current character value represent an English letter in the small form
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
	//		If the current character represent an English small letter then true is returned, otherwise false
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsEnglishSmallLetter() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to check if the current character value represent an English letter
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
	//		If the current character represent an English letter then true is returned, otherwise false
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	EnsureRetrunValueIsUsed inline Boolean IsEnglishLetter() const;


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to convert an english alphabet letter from small to capital form
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
	//		1. The current value in the instance describes one of the letters in the english alphabet
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void ConvertToEnglishCapitalLetter();


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to convert an english alphabet letter from capital to small form
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
	//		1. The current value in the instance describes one of the letters in the english alphabet
	//		2. 
	//
	//  Possible errors :
	//
	//		They will come
	//
	inline void ConvertToEnglishSmallLetter();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get a pointer that contains the memory address of the unsigned integer that represents the character
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
	//      The memory address of the unsigned integer that represents the character
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed inline UnsignedInteger32bits* GetMemoryAddressOfUnsignedIntegerThatRepresentsTheCharacter();


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to get a constant pointer that contains the memory address of the unsigned integer that represents the 
	//		character. This version is for constant instances
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
	//      A constant pointer that contains the memory address of the unsigned integer that represents the character
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed inline const UnsignedInteger32bits* GetMemoryAddressOfUnsignedIntegerThatRepresentsTheCharacter() const;


	// The following methods declare the overloaded operators for the object :


    // This macro will add to objects, that deal with numeric types as data members, all the operators C++ had to offer for each numeric 
    // type. This will make the object appear as the data itself, to some extent
	AddAllOperatorsToObject( member_character, UnsignedInteger32bits, , )


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


	// Method Information :
	//
	//  Description :
	//
	//		Use this operator to set the value of the character from an ascii character
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//		    asciiCharacter - an ascii character that will be used to set the instance
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
	inline void operator=( const AsciiCharacter asciiCharacter );


	// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
	// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
	// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
	// or some functionality needed that does not involve the non static data members


	// Method Information :
	//
	//  Description :
	//
    //      Use this method to get a character instance that represents the minimum of the object
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
    //      A character instance that represents the minimum of the object
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed static inline Character Minimum();


	// Method Information :
	//
	//  Description :
	//
    //      Use this method to get a character instance that represents the maximum of the object
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
    //      A character instance that represents the maximum of the object
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	EnsureRetrunValueIsUsed static inline Character Maximum();


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


	// This object will store the character
	UnsignedInteger32bits member_character;


};  //  Class Character