#ifndef POINTER_HPP
#define POINTER_HPP


#include "../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure
#include "../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert


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



	// Template class Information :
	//
	//  Purpose :
	//
    //      When using a pointer in C it can point to various locations in the memory of the program. It can point to location in the stack, heap, data and text segments.
    //      Pointers can only be initialized by taking the address of an exisitng location in the stack, data, text, dynamically allocated heap location, mapped memory
    //      and libraries allocating things. They can set to any of previous, and to other pointers. Pointer is actually an unsigned long integer describing the offset 
    //      from the beginning of the program memory, this allows to C developers to assign an unsigned long integer to a pointer by casting it to the pointer type :
    //
    //          UnsignedInteger64bits address = 0x8080808080808080;
    //
    //          Type* pointer = ( Type* )address;
    //
    //      C pointers have the following operators :
    //
    //          *pointer                       ->  returns the pointed object
    //          pointer->                      ->  used when the pointed object is a struct
    //          pointer +,- integer            ->  adds or subtracts the integer times the size of the pointed object from the current address, and returns the result
    //          pointer +=,-= integer          ->  adds or subtracts the integer times the size of the pointed object from the current address, and stores the result
    //
    //      Pointers can point to one object or they can point too many contigous objects, and then they have also :
    //
    //          pointer[ integer ]             ->  the same as *( pointer +,- integer ), returns the pointed object in the required address
    //
    //      Pointers are very useful because they only have an address and a type of an object, or in other words the size in bytes of the object, therefore they can be
    //      casted to other type and then the data in the location will be understood differently.
    //
    //      One of the responsibilites of a C developer is to give back all the allocated resources, as fast as possible, for example :
    //
    //          void DoSomething( UnsignedInteger64bits size )
    //          {
    //              Type* heapMemory = ( Type* )malloc( size );
    //
    //              ...
    //
    //              free( heapMemory );
    //          }
    //
    //      In general then, the resources are allocated in a specific scope, in this case the function DoSomething, and should be deleted when control leaves the scope of
    //      the function. This is very important in big programs that use many resources, because the computer resources are limited after all.
    //
    //      This are the capabilites and required behavior of a C pointer.
    //
    //      Now, let's describe what needs to be added to a C pointer to improve it and create a C++ object from it :
    //
    //      1. The first thing is adding a size to each pointer. This is important to make sure the use of the pointer won't extended further then the required area 
    //      
    //      2. Providing all the operators a pointer have in C
    //
    //      3. To allow the user to give information about different parts of the memory segment, beside a pointer to the beginning
	//
	    //  Description :
	    //
	//		1. This object is used as a base object in inheritance. Therefore it must have a few methods virtual. When an object has a virtual method, the
	//		   C++ automatically creates a table with all the pointers to the virtual methods, where the pointer to the table is stored in the beginning of
	//		   the object. The problem arises when a new method needs to be created with the same signature as one in the base object, and the use of pointers.
	//		   Take a look at next example :
	//
	//				class Base
	//				{
	//				    void Display() { cout << "Lord" << endl; }
	//				};
	//
	//				class Derived : public Base
	//				{
	//				    void Display(); { cout << "Help Me" << endl; }    -> Derived inherits Display from Base but needs another behavior
	//				};
	//
	//         Now if a call is made :
	//
	//				Base* base = new Base;
	//				Derived* derived = new Derived;
	//
	//				base->Display( 5 );   -> Outputs "Lord"
	//				derived->Display();   -> Outputs "Help Me"
	//
	//         So far so good, a normal method is called by the static type of the pointer. This means no matter what the object the pointer is
	//		   pointing to it will call the method of the type he was declared as. This is a problematic behavior in inheritance, we need to point
	//		   to derived objects with base pointers and that the correct method will be called. But now :
	//
	//				void Do( Base* base ) { base->Display(); }
	//
	//				Base* base = new Base;
	//				Derived* derived = new Derived;
	//
	//				Do( base );        -> Outputs "Lord"
	//				Do( derived );     -> Outputs "Lord"
	//
	//         This is what virtual allow in C++, instead of calling the method by the static type in compilation, the call to the method is picked
	//		   dynamically by the actual type of the object. This is done by the pointer in the beginning of the object that points to the virtual
	//		   table of the type. Of course it can be overloaded to the derived, but then if there is a deep inheritance a method will be needed to
	//		   be overloaded for each one
	//
	//		2. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
	//
	//		3. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
	//		4. Template arguments :
	//
	//			1. Type -
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
    class Pointer
    {
    public:


        // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
		// the compiler generates a basic behavior for them if possible :


		// Method Information :
		//
		//  Description :
		//
		//   	Default Constructor
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          NONE
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Pointer();


		// Method Information :
		//
		//  Description :
		//
		//   	Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//          1. memoryAddress - the memory address to which the pointer instance needs to point to
		//			2. size - the number of elements of the template type that the instance needs to point to
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		explicit inline Pointer( Type* memoryAddress, UnsignedInteger64bits size = 1UL );


		// Method Information :
		//
		//  Description :
		//
		//   	Copy constructor, will operate correctly even if the other object is in default state
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          other - a reference to the instance that should be copied
		//
		//		Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Pointer( const Pointer< Type >& other );


		// This macro will be used to add all the functionality that is similiar in each object ( beside the name of the object ). It is done as a macro to allow
		// simple text manipulation, instead of inherting it through an object, which becomes a problem when an object inherits from 2 objects, the first is
		// any object, but the second is an object that also inhrits from the first object. This can be solved through virtual inheritance but then can only
		// be one instance of it. Furthermore, each object in the system will need to inherit from it, which will cause inheritance 'chaos'. Therefore, this
		// macro will be used to add the following methods to each object :
		//
		//		1. Assigenment operator
		//		2. Move constructor
		//		3. Move assigenment operator
		//		4. Reset
		//		5. State
		//
		ObjectInfrastructure_ForInheritance( Pointer< Type > )


		// Method Information :
		//
		//  Description :
		//
		//      This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the instance that should be swaped
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
		//		NONE
		//
		//  Possible errors :
		//
		//      They will come
		//
		inline void Swap( Pointer< Type >& other );


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          1. memoryAddress - the memory address to which the pointer instance needs to point to
		//			2. size - the number of elements of the template type that the instance needs to point to
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
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline void Initiate( Type* memoryAddress, UnsignedInteger64bits size = 1UL );


		// Method Information :
		//
		//  Description :
		//
		//   	Destructor, does not throw. Declared virtual to ensure correct deletion for derived objects
		//
		//  Required arguments :
		//
		//   	User information needed :
		//
		//          NONE
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		virtual ~Pointer() = default;


		// The following methods are the interface of the object :


	    // Method Information :
	    //
	    //  Description :
	    //
	    //      Use to get the memory segment size in terms of the template type
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
	    //      The size of the memory segment pointed in terms of the template type
	    //
	    //  Expectations :
	    //
	    //		NONE
	    //
	    //  Possible errors :
	    //
	    //      They will come
	    //
	    inline UnsignedInteger64bits Size() const;


		// The following methods declare the overloaded operators for the object :


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 instances are the same
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean operator==( const Pointer< Type >& other ) const;


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to check if the this instance does not match the other
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          other - a reference to the instance that should be compared with this object
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      1. true - if the 2 instances are not the same
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		inline Boolean operator!=( const Pointer< Type >& other ) const;


        // Method Information :
        //
        //  Description :
        //
        //      Override operator "->" so the use would be the same as with regular pointer, pointer->member = ( *pointer ).member
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
        //      The resource inside the pointer object
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state or empty
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Type* operator->();


        // Method Information :
        //
        //  Description :
        //
        //      Override operator "[]" so the use would be the same as with regular pointer, pointer[n] = *( pointer + n ) = object number n
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          index - the index of the required entry
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to the required entry
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state or empty
        //      2. The index should be in the range of this instance
        //      3. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Type& operator[]( UnsignedInteger64bits index );


        // Method Information :
        //
        //  Description :
        //
        //      Override operator "[]" so the use would be the same as with regular pointer, pointer[n] = *( pointer + n ) = object number n
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          index - the index of the required entry
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to the required entry
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state or empty
        //      2. The index should be in the range of this instance
        //      3. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline const Type& operator[]( UnsignedInteger64bits index ) const;


        // Method Information :
        //
        //  Description :
        //
        //      Override operator "+" so the use would be the same as with regular pointer, pointer + n = the address of object n
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          offset - the offset of the required entry in the resource
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The address of the required entry in the resource
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Type* operator+( UnsignedInteger64bits offset ) const;


        // Method Information :
        //
        //  Description :
        //
        //      Override operator "-" so the use would be the same as with regular pointer, pointer - n = the address of object n behind
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          offset - the offset of the required entry in the resource
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The address of the required entry in the resource
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Type* operator-( UnsignedInteger64bits offset ) const;


        // Method Information :
        //
        //  Description :
        //
        //      Override operator "+=" so the use would be the same as with regular pointer, pointer += n -> stores the address + n in the pointer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          offset - the offset to the new address to set in this instance
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
        //      1. The instance should not be in default state
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Pointer< Type >& operator+=( UnsignedInteger64bits offset );


        // Method Information :
        //
        //  Description :
        //
        //      Override operator "-=" so the use would be the same as with regular pointer, pointer -= n -> stores the address - n in the pointer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          offset - the offset to the new address to set in this instance
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
        //      1. The instance should not be in default state
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Pointer< Type >& operator-=( UnsignedInteger64bits offset );


        // Method Information :
        //
        //  Description :
        //
        //      Override operator postfix "++" so the use would be the same as with regular pointer, pointer++
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
        //      A copy of this instance before the changes made to it
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Pointer< Type > operator++( int );


        // Method Information :
        //
        //  Description :
        //
        //      Override operator ">" so the use would be the same as with regular pointer, pointer > otherPointer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to other instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true - if the pointer inside this instance has higher address then the pointer in the other instance
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Boolean operator>( Pointer< Type >& other ) const;


        // Method Information :
        //
        //  Description :
        //
        //      Override operator "<" so the use would be the same as with regular pointer, pointer < otherPointer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to other instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true - if the pointer inside this instance has lower address then the pointer in the other instance
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come 
        //
        inline Boolean operator<( Pointer< Type >& other ) const;


        // Method Information :
        //
        //  Description :
        //
        //      Override operator ">=" so the use would be the same as with regular pointer, pointer >= otherPointer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to other instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true - if the pointer inside this instance has higher or equal address to the pointer in the other instance
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Boolean operator>=( Pointer< Type >& other ) const;


        // Method Information :
        //
        //  Description :
        //
        //      Override operator "<=" so the use would be the same as with regular pointer, pointer <= otherPointer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to other instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. true - if the pointer inside this instance has lower or equal address to the pointer in the other instance
        //      2. false - otherwise
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline Boolean operator<=( Pointer< Type >& other ) const;


		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions only have
		// access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only purpose then of declaring
		// a static function is when a private static data member needs to be manipulated, or some functionality needed that does not involve the non static data members



		DEBUG_TOOL(

			// This part of the object is dedicated for testing :


			// Method Information :
			//
			//  Description :
			//
			//      This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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
			static void Test() __attribute__ (( __unused__ ));

		)  //  End of debug tool


	protected:


		// The protected part is used for inheritance. This means that only this object and the objects that will inherit from it can use the protected data
		// members or methods


        // This object will store the address of the resource
        Type* member_pointer;

        // This object will store the size of the memory segment pointed in terms of the template type
        UnsignedInteger64bits member_size;


	private:


		// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is sometimes useful
		// to allow a particular object to access private members of other object. The declration of such function is private, because these functions are part
		// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the object's scope. One of the problems that
		// friend declaration solves is when the object needs to be as a right side operand in expressions. Every method in the object is implicitly added a pointer
		// to the location of the object data with the name "this", and to enable this the method must be called from an existing instance. This means that the
		// object can only be implemented as the left side operand of an expression with methods, and friend functions and objects does not have this limitation


        // Method Information :
        //
        //  Description :
        //
        //      Create the operator "*" so the use would be the same as with regular pointer, *pointer = object
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          pointer - a reference to a pointer instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to the resource pointed by the pointer
        //
        //  Expectations :
        //
        //      1. The pointer instance should be ready
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        friend inline TYPE& operator*( Pointer< TYPE >& pointer );


        // Method Information :
        //
        //  Description :
        //
        //      Create the operator prefix "++" so the use would be the same as with regular pointer, ++pointer
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          pointer - a reference to a pointer instance
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to the pointer instance incremented to the next memory address in steps of the template type
        //
        //  Expectations :
        //
        //      1. The instance should not be in default state
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        friend inline Pointer< TYPE >& operator++( Pointer< TYPE >& pointer );


	};  //  Class Pointer




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































	// Method Information :
	//
	//  Description :
	//
	//   	Default Constructor
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          NONE
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename Type >
    inline Pointer< Type >::Pointer() :
    member_state(),
    member_pointer( 0UL	),
    member_size( 0UL )
	{}


	// Method Information :
	//
	//  Description :
	//
	//   	Constructor,
	//
	//  Required arguments :
	//
	//		User information needed :
	//
	//          1. memoryAddress - the memory address to which the pointer instance needs to point to
	//			2. size - the number of elements of the template type that the instance needs to point to
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename Type >
    Pointer< Type >::Pointer( Type* memoryAddress, UnsignedInteger64bits size ) :
    member_state( InstanceState::Ready ),
    member_pointer( memoryAddress ),
    member_size( size )
	{
	    // Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertPointer( memoryAddress )
		AssertSizeIsLargerThenZero( size )
	}


	// Method Information :
	//
	//  Description :
	//
	//   	Copy constructor, will operate correctly even if the other instance is in default state or self assignment
	//
	//  Required arguments :
	//
	//   	User information needed :
	//
	//          other - a reference to the instance that should be copied
	//
	//		Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//   	NONE
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename Type >
    inline Pointer< Type >::Pointer( const Pointer< Type >& other ) :
    member_state( other.member_state ),
    member_pointer( other.member_pointer ),
    member_size( other.member_size )
	{}


	// Method Information :
	//
	//  Description :
	//
	//      This method is used to swap the content between this instance and the other one
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          other - a reference to the instance that should be swaped
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
	//		NONE
	//
	//  Possible errors :
	//
	//      They will come
	//
	template< typename Type >
	inline void Pointer< Type >::Swap( Pointer< Type >& other )
	{
		// Swap between the state instances 
		member_state.Swap( other.member_state );

		// Swap between the pointers
		Memory::Operations::Swap< Type* >( member_pointer, other.member_pointer );

		// Swap between the sizes
		Memory::Operations::Swap< UnsignedInteger64bits >(  member_size, other.member_size );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this method to take an instance in default state and prepare it for work. It can also be used to reinitialize the instance
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          1. memoryAddress - the memory address to which the pointer instance needs to point to
	//			2. size - the number of elements of the template type that the instance needs to point to
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
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename Type >
	inline void Pointer< Type >::Initiate( Type* memoryAddress, UnsignedInteger64bits size )
	{
	    // Use the required constructor to create an instance. It will be used to swap with this instance, leaving this instance in with new data. When sequence control will
	    // leave this scope it will delete the old data
	    Pointer< Type > temporary( memoryAddress, size );

	    // Swap between this instance and the temporary instance
	    Swap( temporary );
	}


    // Method Information :
    //
    //  Description :
    //
    //      Use to get the memory segment size in terms of the template type
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
    //      The size of the memory segment pointed in terms of the template type
    //
    //  Expectations :
    //
    //		NONE
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline UnsignedInteger64bits Pointer< Type >::Size() const
    {
    	// Return the size
    	return ( member_size );
    }



































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          other - a reference to the instance that should be compared with this object
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      1. true - if the 2 instances are the same
	//      2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename Type >
    inline Boolean Pointer< Type >::operator==( const Pointer< Type >& other ) const
	{
		// Check if both or only one of the instances is in default state
		CompareInstances_BothInDefaultStateReturnTrue_OnlyOneInDefaultStateReturnFalse_OtherwiseContinue

		// Compare the pointers, and return the result
		return ( member_pointer == other.member_pointer );
	}


	// Method Information :
	//
	//  Description :
	//
	//      Use this operator to check if the this instance does not match the other
	//
	//  Required arguments :
	//
	//      User information needed :
	//
	//          other - a reference to the instance that should be compared with this object
	//
	//      Information returned to the user :
	//
	//          NONE
	//
	//  Return value :
	//
	//      1. true - if the 2 instances are not the same
	//      2. false - otherwise
	//
	//  Expectations :
	//
	//		NONE
	//
	//  Possible errors :
	//
	//		They will come
	//
	template< typename Type >
    inline Boolean Pointer< Type >::operator!=( const Pointer< Type >& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "->" so the use would be the same as with regular pointer, pointer->member = ( *pointer ).member
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
    //      The resource inside the pointer object
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state or empty
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Type* Pointer< Type >::operator->()
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady            

        // Return the pointer to the resource
        return ( member_pointer );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "[]" so the use would be the same as with regular pointer, pointer[n] = *( pointer + n ) = object number n
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          index - the index of the required entry
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A reference to the required entry
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state or empty
    //      2. The index should be in the range of this instance
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Type& Pointer< Type >::operator[]( UnsignedInteger64bits index )
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady            
        Assert( ( index < member_size ), "The given index is not in the range" )

        // Return a reference to the required entry
        return ( member_pointer[ index ] );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "[]" so the use would be the same as with regular pointer, pointer[n] = *( pointer + n ) = object number n
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          index - the index of the required entry
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A reference to the required entry
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state or empty
    //      2. The index should be in the range of this instance
    //      3. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline const Type& Pointer< Type >::operator[]( UnsignedInteger64bits index ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady            
        Assert( ( index < member_size ), "The give index is not in the range" )
        
        // Return a constant reference to the required entry
        return ( member_pointer[ index ] );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "+" so the use would be the same as with regular pointer, pointer + n = the address of object n
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          offset - the offset of the required entry in the resource
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The address of the required entry in the resource
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Type* Pointer< Type >::operator+( UnsignedInteger64bits offset ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady

        // Return the required object in the resource
        return ( member_pointer + offset );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "-" so the use would be the same as with regular pointer, pointer - n = the address of object n behind
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          offset - the offset of the required entry in the resource
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      The address of the required entry in the resource
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Type* Pointer< Type >::operator-( UnsignedInteger64bits offset ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady            

        // Return the required object in the resource
        return ( member_pointer - offset );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "+=" so the use would be the same as with regular pointer, pointer += n -> stores the address + n in the pointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          offset - the offset to the new address to set in this instance
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
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Pointer< Type >& Pointer< Type >::operator+=( UnsignedInteger64bits offset )
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady

        // Set the new address
        member_pointer += offset;

        // Return a reference to this instance
        return ( *this );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "-=" so the use would be the same as with regular pointer, pointer -= n -> stores the address - n in the pointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          offset - the offset to the new address to set in this instance
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
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Pointer< Type >& Pointer< Type >::operator-=( UnsignedInteger64bits offset )
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady            

        // Set the new address
        member_pointer -= offset;

        // Return a reference to this instance
        return ( *this );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator postfix "++" so the use would be the same as with regular pointer, pointer++
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
    //      A copy of this instance before the changes made to it
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Pointer< Type > Pointer< Type >::operator++( int )
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady            

        // Create a copy of the current instance
        Pointer< Type > temporary( *this );

        // Advance the pointer in this instance by 1
        member_pointer += 1;

        // Return a copy of the temporary instance
        return ( temporary );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator ">" so the use would be the same as with regular pointer, pointer > otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has higher address then the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Boolean Pointer< Type >::operator>( Pointer< Type >& other ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady            

        // Return the required object in the resource
        return ( member_pointer > other.member_pointer );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "<" so the use would be the same as with regular pointer, pointer < otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has lower address then the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come 
    //
    template< typename Type >
    inline Boolean Pointer< Type >::operator<( Pointer< Type >& other ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady            

        // Return the required object in the resource
        return ( member_pointer < other.member_pointer );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator ">=" so the use would be the same as with regular pointer, pointer >= otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has higher or equal address to the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Boolean Pointer< Type >::operator>=( Pointer< Type >& other ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady            

        // Return the required object in the resource
        return ( member_pointer >= other.member_pointer );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Override operator "<=" so the use would be the same as with regular pointer, pointer <= otherPointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          other - a reference to other instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      1. true - if the pointer inside this instance has lower or equal address to the pointer in the other instance
    //      2. false - otherwise
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename Type >
    inline Boolean Pointer< Type >::operator<=( Pointer< Type >& other ) const
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertThisInstanceIsReady           

        // Return the required object in the resource
        return ( member_pointer <= other.member_pointer );
    }
































// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************

































    // Method Information :
    //
    //  Description :
    //
    //      Create the operator "*" so the use would be the same as with regular pointer, *pointer = object
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          pointer - a reference to a pointer instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A reference to the resource pointed by the pointer
    //
    //  Expectations :
    //
    //      1. The pointer instance should be ready
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename TYPE >
    inline TYPE& operator*( Pointer< TYPE >& pointer )
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
    	AssertInstanceIsReady( pointer )
        
        // Return the object pointed
        return ( *pointer.member_pointer );
    }


    // Method Information :
    //
    //  Description :
    //
    //      Create the operator prefix "++" so the use would be the same as with regular pointer, ++pointer
    //
    //  Required arguments :
    //
    //      User information needed :
    //
    //          pointer - a reference to a pointer instance
    //
    //      Information returned to the user :
    //
    //          NONE
    //
    //  Return value :
    //
    //      A reference to the pointer instance incremented to the next memory address in steps of the template type
    //
    //  Expectations :
    //
    //      1. The instance should not be in default state
    //      2. 
    //
    //  Possible errors :
    //
    //      They will come
    //
    template< typename TYPE >
    inline Pointer< TYPE >& operator++( Pointer< TYPE >& pointer )
    {
		// Each method that interacts with the user directly needs to ensure that the given data is valid
		AssertInstanceIsReady(  pointer )

        // Advance the pointer by 1
        pointer.member_pointer += 1;

        // Return a reference to the pointer instance
        return ( pointer );
    }

































// *********************************************************************************   TESTING   ********************************************************************************




































	DEBUG_TOOL(

		// Method Information :
		//
		//  Description :
		//
		//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
		//		the functionality
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
		//      1. true - if the object passed the test
		//      2. false - otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. An assertion failed - class Exception is thrown
		//		2. There is no more free memory space - class std::bad_alloc is thrown
		//		3. 
		//
		template< typename Type >
		void Pointer< Type >::Test()
		{
            // Test the constructors, and deestructors :

            // Create an base pointer object with default constructor
            Pointer< SignedInteger32bits > testPointer_1;

            // Allocate memory space for one object
            SignedInteger32bits resource_1 = 0;

            // Initiate the instance
            testPointer_1.Initiate( &resource_1 );

            // Set a value
            *testPointer_1 = 8889;

            // Check that the object is actually in default state
            Assert_Test( ( *testPointer_1 == 8889 ) );

            // Create an instance using the copy constructor
            Pointer< SignedInteger32bits > testPointer_2( testPointer_1 );

            // Check that copy constructor and the comparison operator work
            Assert_Test( ( testPointer_1 == testPointer_2 ) );

            // Check that copy constructor and the non comparison operator work
            Assert_Test( ( testPointer_1 != testPointer_2 ) == false );

            // Allocate memory space for one object
            SignedInteger32bits resource_2[5] = {0};

            // Create an instance
            Pointer< SignedInteger32bits > testPointer_3( resource_2, 5 );

            // Set some values
            testPointer_3[0] = 7;
            testPointer_3[1] = 8;
            testPointer_3[2] = 9;
            testPointer_3[3] = 10;
            testPointer_3[4] = 11;

            // Check that all values were set correctly
            Assert_Test( ( ( testPointer_3[0] == 7 ) && ( testPointer_3[1] == 8 ) && ( testPointer_3[2] == 9 ) &&
                                                                        ( testPointer_3[3] == 10 ) && ( testPointer_3[4] == 11 ) ) );  

            // Check all the operators :

            // Operator addition
            auto additionPointerResult = testPointer_3 + 4;

            // Check that the operator worked well
            Assert_Test( testPointer_3[4] == *additionPointerResult );

            // Check that the operator worked well
            Assert_Test( ( testPointer_3[4] == *( testPointer_3 + 4 ) ) );
            
            // Operator addition
            auto subtractionPointerResult = testPointer_3 - 4;

            // Check that the operator worked well
            Assert_Test( *( testPointer_3.member_pointer - 4 ) == *subtractionPointerResult );

            // Operator addition and assignment
            testPointer_3 += 2;

            // Operator subtraction and assignment
            testPointer_3 -= 4;

            // Check the prefix and suffix addition 1 operators
            ++testPointer_3;
            testPointer_3++;
		}

	)  //  End of debug tool












}  //  Namespace Universe


#endif  // POINTER_HPP