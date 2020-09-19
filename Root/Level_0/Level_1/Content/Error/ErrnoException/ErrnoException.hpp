#ifndef ERRNOEXCEPTION_HPP
#define ERRNOEXCEPTION_HPP


#include <cerrno>  //  Macro errno
#include <cstring>  //  Function strerror


#include "../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  // Macro DEBUG_TOOL, Macro COMMA
#include "../Exception/Exception.hpp"  //  Class Exception


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



        // There are 2 function provided by the C programming language to display the text message associated with errno :
        //
        //  1. perror - displays the string passed to it, followed by a colon and space, and then the textual representation of the current errno value
        //
        //  2. strerror - returns a pointer to the textual representation of the current error value



        // Use the following macro to throw an errno exception
        //
        #define ThrowErrnoException throw( Error::ErrnoException( __FILE__, __FUNCTION__, __LINE__ ) );



		// Class Information :
		//
		//  Purpose :
		//
        //		This object is a package sent up in the function stack to describe an exception from correct behavior. Every function that can deal with 
        //		the condition should catch it, and perform the required operations. If non of the functions will catch the exception the execution will 
        //		terminate. The termination method can be set to ensure clean up and such. This object should be used when dealing with linux system
        //      calls that write their error codes to errno
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
		//
		// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
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
		class ErrnoException : public Exception
		{
		public:


			// Create a type definition for the object itself
			using ObjectType = ErrnoException;


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
			inline ErrnoException();


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
            //      NONE
            //
			explicit inline ErrnoException( const char* fileName, const char* functionName, SignedInteger32bits lineNumber );


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
			inline ErrnoException( const ErrnoException& other );


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
    		inline ErrnoException& operator=( const ErrnoException& other );


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
    		inline ErrnoException( ErrnoException&& other );


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
    		inline ErrnoException& operator=( ErrnoException&& other );


			// Method Information :
			//
			//  Description :
			//
			//		This method is used to swap the content between this instance and the other one
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//		    other - a reference to the instance that should be swapped
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
			inline void Swap( ErrnoException& other );


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
            virtual void Initiate( const char* fileName, const char* functionName, SignedInteger32bits lineNumber );


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
			virtual ~ErrnoException() = default;


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
			inline Boolean operator==( const ErrnoException& other ) const;


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
			inline Boolean operator!=( const ErrnoException& other ) const;


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
				static void Test() __attribute__ (( __unused__ ));

			)  //  End of debug tool


		};  //  Class ErrnoException




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************




































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
		inline ErrnoException::ErrnoException() :
		Exception()
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
        //          1. fileName - an ascii string with the file name from which the exception was thrown
        //          2. functionName - an ascii string with the function name from which the exception was thrown
        //          3. lineNumber - the number of line from which the exception was thrown
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
		//		They will come
		//
		ErrnoException::ErrnoException( const char* fileName, const char* functionName, SignedInteger32bits lineNumber ) :
		Exception( fileName, functionName, lineNumber, strerror( errno ) )
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
		inline ErrnoException::ErrnoException( const ErrnoException& other ) :
		Exception( other )
		{}


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
        inline ErrnoException& ErrnoException::operator=( const ErrnoException& other )
        {
            // Create a copy of the other instance
            ErrnoException copyOfOther( other );

            // Swap between this instance and the copy of the other one, this will leave the copy instance with the old data, and it will be deleted
            Swap( copyOfOther );

            // Return a reference to this instance
            return ( *this );
        }


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
        inline ErrnoException::ErrnoException( ErrnoException&& other ) :
        ErrnoException()
        {
            // Swap between this instance, which is in default state, and the other one
            Swap( other );
        }


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
        inline ErrnoException& ErrnoException::operator=( ErrnoException&& other )
        {
            // Create a default constructed instance
            ErrnoException defaultConstructedInstance;

            // Swap between the temporary instance, which is in default state, and the other instance, this will leave the other instance in default state
            defaultConstructedInstance.Swap( other );

            // Swap between this instance and the temporary one
            Swap( defaultConstructedInstance );

            // Return a reference to this instance
            return ( *this );
        }


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//		other - a reference to the instance that should be swaped
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
		void ErrnoException::Swap( ErrnoException& other )
		{
			// Swap the base exception instances
			Exception::Swap( other );
		}





































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************




































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
		inline Boolean ErrnoException::operator==( const ErrnoException& other ) const
		{
			// Call the base object exception equal operator
			return ( Exception::operator==( other ) );
		}


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
		inline Boolean ErrnoException::operator!=( const ErrnoException& other ) const
		{
			// Return the negotiated value from the equal operator
			return ( !( *this == other ) );
		}












	}  //  Namespace Error

}  //  Namespace Universe



#endif  // ERRNOEXCEPTION_HPP