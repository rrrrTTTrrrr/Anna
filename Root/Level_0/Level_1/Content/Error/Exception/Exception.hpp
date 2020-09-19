#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP


#include <iostream>  //  Class std::cout, Class std::endl


#include "../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA
#include "../../../../Content/AsciiStringAndIntegers/AsciiStringAndIntegers.hpp"  //  Class AsciiStringAndIntegers


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{

    namespace Error
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



        // Use the following macro to throw an exception
        //
        #define ThrowException( ErrorMessage ) throw( Error::Exception( __FILE__, __FUNCTION__, __LINE__, ErrorMessage ) );



		// Class Information :
		//
		//  Purpose :
		//
        //		This object is a package sent up in the function stack to describe an exception from correct behavior. Every function that can deal with 
        //		the condition should catch it, and perform the required operations. If non of the functions will catch the exception the execution will 
        //		terminate. The termination method can be set to ensure clean up and such
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
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class Exception
		{
		public:


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
			//          NONE
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
			//		They will come
			//
			inline Exception();


            // Method Information :
            //
            //  Description :
            //
            //      Constructor,
            //
            //  Required arguments :
            //
            //          1. fileName - an ascii string with the file name from which the exception was thrown
            //          2. functionName - an ascii string with the function name from which the exception was thrown
            //          3. lineNumber - the number of line from which the exception was thrown
            //          4. errorMessage - the memory address of the user error message
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
            //      1. The given pointer to the file name is not NULL
            //      2. The given pointer to the function name is not NULL
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            explicit inline Exception( const char* fileName, const char* functionName, SignedInteger32bits lineNumber, const char* errorMessage );


			// Method Information :
			//
			//  Description :
			//
			//		Copy constructor, will operate correctly even if the other object is in default state
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//          other - a reference to the instance that should be copied
			//
			//		Information returned to the user :
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
			//		They will come
			//
			inline Exception( const Exception& other );


            // Method Information :
            //
            //  Description :
            //
            //      Assignment operator, can handle with self assignment and instances in default state
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the instance that should be copied
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to this instance
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
    		inline Exception& operator=( const Exception& other );


            // Method Information :
            //
            //  Description :
            //
            //      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the instance that should be moved
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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
    		inline Exception( Exception&& other );


            // Method Information :
            //
            //  Description :
            //
            //      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the instance that should be moved
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A reference to this instance
            //
            //  Expectations :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
    		inline Exception& operator=( Exception&& other );


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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline void Swap( Exception& other );


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
            //          NONE
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
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            virtual void Reset();


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
            //          1. fileName - an ascii string with the file name from which the exception was thrown
            //          2. functionName - an ascii string with the function name from which the exception was thrown
            //          3. lineNumber - the number of line from which the exception was thrown
            //          4. errorMessage - the memory address of the user error message
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
            //      1. The given pointer to the file name is not NULL
            //      2. The given pointer to the function name is not NULL
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            virtual void Initiate( const char* fileName, const char* functionName, SignedInteger32bits lineNumber, const char* errorMessage );


			// Method Information :
			//
			//  Description :
			//
			//		Destructor, does not throw. Declared virtual to ensure correct deletion for derived objects
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//          NONE
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
			//		They will come
			//
			virtual ~Exception() = default;


			// The following methods are the interface of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to display
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
            //      NONE
            //
			//  Expectations :
			//
	        //      1. The instance contains an error message
	        //      2. 
			//
            //  Possible errors :
            //
            //      They will come
            //
            virtual void TellMe() const;


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
			Boolean operator==( const Exception& other ) const;


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
			inline Boolean operator!=( const Exception& other ) const;


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


		private:


            // This object will store the error message
            char member_formattedErrorMessage[512];


			// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
			// rather help implement it :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to format the error message that will be dispayed to the user
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. fileName - an ascii string with the file name from which the exception was thrown
            //          2. functionName - an ascii string with the function name from which the exception was thrown
            //          3. lineNumber - the number of line from which the exception was thrown
            //          4. errorMessage - the memory address of the user error message
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
            //      1. The given pointer to the file name is not NULL
            //      2. The given pointer to the function name is not NULL
            //      3. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            void FormatErrorMessage_Private( const char* fileName, const char* functionName, SignedInteger32bits lineNumber, const char* errorMessage );


		};  //  Class Exception



#include "Exception.inl"



	}  //  Namespace Error

}  //  Namespace Universe


#endif  // EXCEPTION_HPP