#ifndef  UNICODESTRING_H
#define  UNICODESTRING_H


#include <new>  //  Class std::bad_alloc


#include "../../../ErrorHandling/Exception.h"  //  Class Exception
#include "../../../Definitions/VariableTypesDefinitions.h"  //  Typedef UnsignedInteger64bits, Typedef UnsignedInteger32bits, Typedef UnsignedInteger8bits, Typedef UnsignedInteger16bits
#include "../../Ascii/AsciiString/AsciiString.h"  //  Class AsciiString
#include "../UnicodeTransferFormat_8/UTF8.h"  //  Class UTF-8
#include "../UnicodeTransferFormat_16/UTF16.h"  //  Class UTF-16
#include "../../EncodingDefinitions/EncodingDefinitions.h"  //  Enum EncodingType, Typedef UnicodeScalarValue
#include "../../../GeneralPurposeContainers/Array/BasicTypes/BasicTypesArray/BasicTypesArray.h"  //  Class BasicTypesArray




// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part



namespace Universe
{

    namespace Encoding
    {


    	// This is used when only declaring the object in this source file will be enough to
    	// pass compilation. The implementation is given to the compiler through the cpp source
    	// file that the object is nested within
    	//
    	// Forward declarations :
    	//
    	//  NONE
    	//


    	// Give proper treatment, by dealing with big and little endian encoding systems
    	// where it is required. The big or little endian encoding appear when dealing
    	// with byte order in memory


    	// To support move semantics every class must provide a default state. This state
    	// will be used to notify that resources were taken from current instance by
    	// a move operation :
    	//
    	//
   		// When the object is in this state it should not be used ( the object is empty )


    	// Constructor of derived object, when called, all the base class constructors are executed
    	// first, according to the order they appear in the class declaration, and only then the
    	// user code is executed

    	// Destructor of derived object, when it is called, the user code existing in the destructor
    	// itself is executed first and then all the destructors of the base objects, in an opposite
    	// way from which they were constructed


        // A virtual function or virtual method is a function or method whose behavior can be overridden
        // within an inheriting class by a function with the same signature
        //
        // whereas..
        //
        // A pure virtual function or pure virtual method is a virtual function that is required to be 
        // implemented by a derived class that is not abstract


        // Abstract classes and construction of such
        //
        // An abstract class cannot be instantiated. He must be inherited in order to have it's constructor called,
        // and since the derived class calls the constructor of the abstract class it doesn't matter what is the
        // protection level, as long as the Derived class can access it.
        //
        // So it doesn't matter if the constructor is public or protected. One reason that one could possibly have 
        // for making it protected is to serve as a reminder that the class must be constructed through inheritance


        // A pure virtual function must be implemented in a derived type that will be directly instantiated, however 
        // the base type can still define an implementation. A derived class can explicitly call the base class 
        // implementation ( if access permissions allow it ) by using a fully-scoped name
        //
        // The use case is when there's a more-or-less reasonable default behavior, but the class designer wants that
        //  sort-of-default behavior be invoked only explicitly. It can also be the case what you want derived classes
        //  to always perform their own work but also be able to call a common set of functionality


        // The 3 dots function argument, for example :
        //
        //  void function( int index, ... )
        //
        // They usually mark the function as having a variable number of arguments. In a real system, however, a system 
        // call can’t actually have a variable number of arguments. System calls must have a well-defined prototype, 
        // because user programs can access them only through hardware “gates”. Therefore, the dots in the prototype 
        // represent not a variable number of arguments but a single optional argument, traditionally identified as 
        // char *argp. The dots are simply there to prevent type checking during compilation. Using a pointer is the 
        // way to pass arbitrary data to the function


        // There are two ways to look at inline functios :
        //
        //  1. Inline functions are declared in the header because, in order to inline a function call, the compiler must be 
        //  able to see the function body. For a naive compiler to do that, the function body must be in the same translation 
        //  unit as the call. ( A modern compiler can optimize across translation units, and so a function call may be 
        //  inlined even though the function definition is in a separate translation unit, but these optimizations are 
        //  expensive, aren't always enabled, and weren't always supported by the compiler )
        //
        //  2. Functions declared in the header must be marked inline because otherwise, every translation unit which includes 
        //  the header will contain a definition of the function, and the linker will complain about multiple definitions ( a 
        //  violation of the One Definition Rule ). The inline keyword suppresses this, allowing multiple translation units to
        //  contain (identical) definitions
        //
        // The two explanations really boil down to the fact that the inline keyword doesn't exactly do what you'd expect.
        //
        // A C++ compiler is free to apply the inlining optimization ( replace a function call with the body of the called 
        // function, saving the call overhead) any time it likes, as long as it doesn't alter the observable behavior of the program.
        //
        // The inline keyword makes it easier for the compiler to apply this optimization, by allowing the function definition to 
        // be visible in multiple translation units, but using the keyword doesn't mean the compiler has to inline the function, and 
        // not using the keyword doesn't forbid the compiler from inlining the function


		// Template class Information :
    	//
    	//  Purpose :
    	//
    	//
    	//
   	    //  Description :
   	    //
    	//
    	//
    	//  Possible errors :
    	//
    	//
    	//
    	class UnicodeString : public GeneralPurposeContainers::BasicTypesArray< UnicodeScalarValue >
        {
        public:


            // The following methods are the basic methods for each object. How to create, destroy, copy
            // and move the object. This methods if not declared the compiler generates a basic behavior
            // for them :


            // Method Information :
    	    //
    	    //  Description :
            //
    		//   	Default Constructor, used to support move semantics
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
			//  Possible errors :
    		//
    		//		They will come
    		//
    		explicit inline UnicodeString() throw();


            // Method Information :
            //
            //  Description :
            //
            //      Constructor, for UTF encoded strings
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTFencoding - the address of the UTF encoding
            //          2. encodingType - this will be used to determine the UTF encoding
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. The UTF encoding does not end with NULL
            //      3. The given pointer is NULL - class Exception is thrown
            //      4. 
            //
            explicit inline UnicodeString( const void* UTFencoding, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Constructor, for UTF encoded strings with size given ( instead of NULL at the end )
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTFencoding - the address of the UTF encoding
            //          2. UTFencodingNumberOfBytes - the number of bytes in the UTF encoding
            //          3. encodingType - this will be used to determine the UTF encoding
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. The UTF encoding does not end with NULL
            //      3. The given pointer is NULL - class Exception is thrown
            //      4. The given size of the UTF encoding is 0 - class Exception is thrown
            //      5. 
            //
            explicit inline UnicodeString( const void* UTFencoding, UnsignedInteger64bits UTFencodingNumberOfBytes, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception );


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
    		//          other - a reference to the object that should be copied
    		//
    		//		Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to the new copy is returned
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline UnicodeString( const UnicodeString& other ) throw();


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Assignment operator, can handle with self assignment. Will operate correctly even if the other object is in default state
    		//
    		//  Required arguments :
    		//
    		//		User information needed :
    		//
    		//			other - a reference to the object that should be copied
    		//
    		//		Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to this object
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		UnicodeString& operator=( const UnicodeString& other ) throw();


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move constructor, takes the resources from the other object ( rvalue reference ), and set it to
    		//		the default state. Will operate correctly even if the other object is in default state
    		//
    		//  Required arguments :
    		//
    		//   	User information needed :
    		//
    		//          other - a reference to the object that should be moved
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	NONE
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline UnicodeString( UnicodeString&& other ) throw();


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move Assignment operator, can handle with self assignment. takes the resources from the
    		//    	other object ( rvalue reference ), and set it to the default state. will operate correctly
    		//      even if the other object is in default state
    		//
    		//  Required arguments :
    		//
    		//   	User information needed :
    		//
    		//          other - a reference to the object that should be moved
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//   	A reference to this object
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		UnicodeString& operator=( UnicodeString&& other ) throw();


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Destructor,
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
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		virtual inline ~UnicodeString() throw();


    		// The following methods are the interface of the object. This methods implement the
    		// capabilities of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the unicode string size ( in other words, the number of unicode scalar values ), not including the ending NULL    
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
            //      The unicode string size 
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2.
            //
            inline UnsignedInteger64bits GetSize() const throw( Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Use to change the unicode string
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTFencoding - the address of the UTF encoding
            //          2. encodingType - this will be used to determine the UTF encoding
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. The given pointer is NULL - class Exception is thrown
            //      2. There is no more free memory space - class std::bad_alloc is thrown
            //      3. 
            //
            inline void SetNewUnicodeString( const void* newUTFencoding, Encoding::EncodingType newEncodingType ) throw( std::bad_alloc, Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Use to change the unicode string with size given ( instead of NULL at the end )
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTFencoding - the address of the UTF encoding
            //          2. UTFencodingNumberOfBytes - the number of bytes in the UTF encoding
            //          3. encodingType - this will be used to determine the UTF encoding
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. The given pointer is NULL - class Exception is thrown
            //      2. There is no more free memory space - class std::bad_alloc is thrown
            //      3. The given size of the UTF encoding is 0 - class Exception is thrown
            //      4. 
            //
            inline void SetNewUnicodeStringWithSize( const void* newUTFencoding, UnsignedInteger64bits newUTFencodingNumberOfBytes, Encoding::EncodingType newEncodingType ) throw( std::bad_alloc, Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the unicode string encoded as UTF-8
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
            //      The address of the unicode string encoded as UTF-8
            //
            //      Note - the responsibility for deleting the memory space is on the user
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2. 
            //
            inline UnsignedInteger8bits* GetUnicodeStringEncodedAsUTF8() const throw( std::bad_alloc, Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the unicode string encoded as UTF-16
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
            //      The address of the unicode string encoded as UTF-16
            //
            //      Note - the responsibility for deleting the memory space is on the user
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2. 
            //
            inline UnsignedInteger16bits* GetUnicodeStringEncodedAsUTF16() const throw( std::bad_alloc, Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the unicode string encoded as UTF-32
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
            //      The address of the unicode string encoded as UTF-32
            //
            //      Note - the responsibility for deleting the memory space is on the user
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2. 
            //
            inline UnicodeScalarValue* GetUnicodeStringEncodedAsUTF32() const throw( std::bad_alloc, Exception );


    		// The following methods declare the overloaded operators for the object :


    	private:


            // This object will be used to perform the functionality of UTF-8 
            UTF8 m_UTF8;

            // This object will be used to perform the functionality of UTF-16
            UTF16 m_UTF16;


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to transform the UTF encoding into unicdoe scalar values string   
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTFencoding - the address of the UTF encoding
            //          2. encodingType - this will be used to determine the UTF encoding
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2.
            //
            void AddUTFencodingToTheEndIMP( const void* UTFencoding, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to throw an exception if the given size in bytes of the UTF encoding divides by the encoding type with no remainder
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTFencodingNumberOfBytes - the size of the UTF encoding
            //          2. encodingType - this will be used to determine the UTF encoding
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. If the given size in bytes of the UTF encoding divides by the encoding type with no remainder - class Exception is thrown
            //      2.
            //
            void ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP( UnsignedInteger64bits UTFencodingNumberOfBytes, Encoding::EncodingType encodingType ) throw( Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to transform the UTF endoing into unicdoe scalar values string   
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTFencoding - the address of the UTF encoding
            //          2. UTFencodingNumberOfBytes - the number of bytes in the UTF encoding
            //          3. encodingType - this will be used to determine the UTF encoding
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2.
            //
            void AddUTFencodingWithGivenSizeToTheEndIMP( const void* UTFencoding, UnsignedInteger64bits UTFencodingNumberOfBytes, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception );


            // Friend class or friend function can access private and protected members of other class in which it is declared as friend. 
            // It is sometimes useful to allow a particular class to access private members of other class. The declration of such function 
            // is private, because these functions are part of the implemntation, which the user should not be aware of. Furthermore the 
            // use of this functions is not limited to the class's scope. The following declarations are for all the function that should 
            // be friends with this class :
 

    	};  //  Class UnicodeString





















//	********************************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ********************************************************************























    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Default Constructor, used to support move semantics
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
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline UnicodeString::UnicodeString() throw() :
        BasicTypesArray(),
        m_UTF8(),
        m_UTF16()
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Constructor, for UTF encoded strings
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. UTFencoding - the address of the UTF encoding
        //          2. encodingType - this will be used to determine the UTF encoding
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2. The UTF encoding does not end with NULL
        //      3. The given pointer is NULL - class Exception is thrown
        //      4. 
        //
    	inline UnicodeString::UnicodeString( const void* UTFencoding, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception ):
        BasicTypesArray< UnicodeScalarValue >(),
        m_UTF8(),
        m_UTF16()
        {
            // Check that the pointer is not NULL
            ThrowExceptionIfPointerIsNULL( UTFencoding, "UnicodeString::Construction failed - the given pointer is NULL" );

            // The UTF encoding options are : Ascii, UTF-8, UTF-16 little and big endian, UTF-32 little and big endian

            // Create the unicode scalar values string from the UTF encdoing
            AddUTFencodingToTheEndIMP( UTFencoding, encodingType );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Constructor, for UTF encoded strings with size given ( instead of NULL at the end )
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. UTFencoding - the address of the UTF encoding
        //          2. UTFencodingNumberOfBytes - the number of bytes in the UTF encoding
        //          3. encodingType - this will be used to determine the UTF encoding
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2. The UTF encoding does not end with NULL
        //      3. The given pointer is NULL - class Exception is thrown
        //      4. The given size of the UTF encoding is 0 - class Exception is thrown
        //      5. 
        //
        inline UnicodeString::UnicodeString( const void* UTFencoding, UnsignedInteger64bits UTFencodingNumberOfBytes, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception ) :
        BasicTypesArray< UnicodeScalarValue >(),
        m_UTF8(),
        m_UTF16()
        {
            // Check that the pointer is not NULL
            ThrowExceptionIfPointerIsNULL( UTFencoding, "UnicodeString::Construction failed - the given pointer is NULL" );

            // Check that the given number of bytes in the UTF encoding is not 0
            ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( UTFencodingNumberOfBytes, 0, "UnicodeString::Construction failed - the given size of the UTF encoding is 0" );

            // Check that the number of bytes in the UTF encoding divides by the encoding type with no remainder
            ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP( UTFencodingNumberOfBytes, encodingType );

            // The UTF encoding options are : Ascii, UTF-8, UTF-16 little and big endian, UTF-32 little and big endian

            // Create the unicode scalar values string from the UTF encdoing
            AddUTFencodingWithGivenSizeToTheEndIMP( UTFencoding, UTFencodingNumberOfBytes, encodingType );
        }


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
    	//          other - a reference to the object that should be copied
    	//
    	//		Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	A reference to the new copy is returned
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline UnicodeString::UnicodeString( const UnicodeString& other ) throw() :
        BasicTypesArray< UnicodeScalarValue >( other ),
        m_UTF8(),
        m_UTF16()
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Assignment operator, can handle with self assignment. Will operate correctly even if the other object is in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be copied
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this object 
        //
        //  Possible errors :
        //
        //    They will come
        //
        inline UnicodeString& UnicodeString::operator=( const UnicodeString& other ) throw( std::bad_alloc, Exception )
        {
            // Use the assignment operator of the base class basic types array
            BasicTypesArray< UnicodeScalarValue >::operator=( other );
        }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Move constructor, takes the resources from the other object ( rvalue reference ), and set it to
    	//		the default state. Will operate correctly even if the other object is in default state
    	//
    	//  Required arguments :
    	//
    	//   	User information needed :
    	//
    	//          other - a reference to the object that should be moved
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline UnicodeString::UnicodeString( UnicodeString&& other ) throw() :
        BasicTypesArray< UnicodeScalarValue >( other ),
        m_UTF8(),
        m_UTF16()
        {
    		// Set the other object to default state, this way it can't be used
    		other.SetToDefaultState();
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Move Assignment operator, can handle with self assignment. Takes the resources from the
        //      other object ( rvalue reference ), and set it to the default state. Will operate correctly
        //      even if the other object is in default state
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be moved
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A reference to this object
        //
        //  Possible errors :
        //
        //      They will come
        //
        inline UnicodeString& UnicodeString::operator=( UnicodeString&& other ) throw()
        {
            // Use the move assignment operator of the base class basic types array
            BasicTypesArray< UnicodeScalarValue >::operator=( other );
        }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Destructor,
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
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline UnicodeString::~UnicodeString() throw()
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the unicode string encoded as UTF-8
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
        //      The address of the unicode string encoded as UTF-8
        //
        //      Note - the responsibility for deleting the memory space is on the user
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2. 
        //
        inline UnsignedInteger8bits* UnicodeString::GetUnicodeStringEncodedAsUTF8() const throw( std::bad_alloc, Exception )
        {
            // Check that this object is not in default state
            ThrowExceptionIfExpressionIsTrue( DefaultState(), "UnicodeString::GetUnicodeStringEncodedAsUTF8 failed - the object is in default state" );

            // Use the UTF-8 object to create the UTF-8 encoding
            return ( m_UTF8.GetUnicodeStringEncodedAsUTF8( m_unicodeString.GetHandleToBasicTypesArray() ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the unicode string encoded as UTF-16
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
        //      The address of the unicode string encoded as UTF-16
        //
        //      Note - the responsibility for deleting the memory space is on the user
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2. 
        //
        inline UnsignedInteger16bits* UnicodeString::GetUnicodeStringEncodedAsUTF16() const throw( std::bad_alloc, Exception )
        {
            // Check that this object is not in default state
            ThrowExceptionIfExpressionIsTrue( DefaultState(), "UnicodeString::GetUnicodeStringEncodedAsUTF16 failed - the object is in default state" );

            // Use the UTF-16 object to create the UTF-16 encoding
            return ( m_UTF16.GetUnicodeStringEncodedAsUTF16( m_unicodeString.GetHandleToBasicTypesArray() ) );
        }

























//  ***********************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ******************************************************************



























//	**************************************************************   PRIVATE METHODS IMPLEMENTATION   ****************************************************************************






















// *******************************************************   NESTED CLASS IMPLEMENTATION -  UnicodeStringProxy  *****************************************************************






























// ******************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***************************************************************















        // This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
        // within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
        // to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
        // this functions are needed to avoid just that








    }  //  Namespace Encoding

}  //  Namespace Universe



#endif  // UNICODESTRING_H