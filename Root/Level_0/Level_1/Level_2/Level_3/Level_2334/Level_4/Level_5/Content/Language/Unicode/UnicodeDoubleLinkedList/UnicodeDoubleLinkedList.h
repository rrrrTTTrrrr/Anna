#ifndef  UNICODEDOUBLELINKEDLIST_H
#define  UNICODEDOUBLELINKEDLIST_H


#include "iostream"


#include "../../../Definitions/VariableTypesDefinitions.h"  //  Typedef UnsignedInteger64bits
#include "../../../BasicUtilities/cpp_BasicUtilities.h"  //  Function ThrowExceptionIfPointerIsNULL, Function ThrowExceptionIfExpressionIsTrue, Function ThrowExceptionIfValueOneIsEqualToValueTwo
#include "../../EncodingDefinitions/EncodingDefinitions.h"  //  Typedef UnicodeScalarValue, Enum EncodingType
#include "../../../GeneralPurposeContainers/LinkedList/DoubleLinkedList/BasicTypesDoubleLinkedList/BasicTypesDoubleLinkedList.h"  //  Class BasicTypesDoubleLinkedList
#include "../UnicodeTransferFormat_8/UTF8.h"  //  Class UTF8
#include "../UnicodeTransferFormat_16/UTF16.h"  //  Class UTF16




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


		// Class Information :
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
    	class UnicodeDoubleLinkedList : public GeneralPurposeContainers::BasicTypesDoubleLinkedList< UnicodeScalarValue >
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
    		explicit inline UnicodeDoubleLinkedList() throw();


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
            inline UnicodeDoubleLinkedList( const void* UTFencoding, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception );


            // Method Information :
            //
            //  Description :
            //
            //      Constructor, for UTF encoded strings with given size
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
            //      4. The given size of the UTF encoding is 0 - class Exception is thrown
            //      5. 
            //
            inline UnicodeDoubleLinkedList( const void* UTFencoding, UnsignedInteger64bits UTFencodingNumberOfBytes, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception );


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
    		inline UnicodeDoubleLinkedList( const UnicodeDoubleLinkedList& other ) throw( std::bad_alloc, Exception );


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
    		UnicodeDoubleLinkedList& operator=( const UnicodeDoubleLinkedList& other ) throw( std::bad_alloc, Exception );


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
    		inline UnicodeDoubleLinkedList( UnicodeDoubleLinkedList&& other ) throw();


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
    		UnicodeDoubleLinkedList& operator=( UnicodeDoubleLinkedList&& other ) throw();


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
    		virtual inline ~UnicodeDoubleLinkedList() throw();


    		// The following methods are the interface of the object. This methods implement the
    		// capabilities of the object :




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
            //      Use this method to transform the UTF encoding ending with NULL into unicdoe scalar values double linked list
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
            //      Use this method to transform the UTF encoding with given size into unicdoe scalar values double linked list
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. UTFencoding - the address of the UTF encoding
            //          2. UTFencodingNumberOfBytes - the size of the UTF encoding
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


			// Friend class or friend function can access private and protected members of other class in which it is declared as friend.
			// It is sometimes useful to allow a particular class to access private members of other class. The declration of such function
			// is private, because these functions are part of the implemntation, which the user should not be aware of. Furthermore the
			// use of this functions is not limited to the class's scope. The following declarations are for all the function that should
			// be friends with this class :


		};  //  Class UnicodeDoubleLinkedList



















//	***********************************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   *****************************************************************



















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
    	inline UnicodeDoubleLinkedList::UnicodeDoubleLinkedList() throw() :
        BasicTypesDoubleLinkedList(),
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
        inline UnicodeDoubleLinkedList::UnicodeDoubleLinkedList( const void* UTFencoding, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception ) :
        BasicTypesDoubleLinkedList(),
        m_UTF8(),
        m_UTF16()
        {
            // Check that the pointer is not NULL
            ThrowExceptionIfPointerIsNULL( UTFencoding, "UnicodeDoubleLinkedList::Construction failed - the given pointer is NULL" );

            // The UTF encoding options are : Ascii, UTF-8, UTF-16 little and big endian, UTF-32 little and big endian

            // Create the unicode scalar values double linked list from the UTF encdoing
            AddUTFencodingToTheEndIMP( UTFencoding, encodingType );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Constructor, for UTF encoded strings with given size
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
        //      4. The given size of the UTF encoding is 0 - class Exception is thrown
        //      5. 
        //
        inline UnicodeDoubleLinkedList::UnicodeDoubleLinkedList( const void* UTFencoding, UnsignedInteger64bits UTFencodingNumberOfBytes, Encoding::EncodingType encodingType ) throw( std::bad_alloc, Exception ):
        BasicTypesDoubleLinkedList(),
        m_UTF8(),
        m_UTF16()
        {
            // Check that the pointer is not NULL
            ThrowExceptionIfPointerIsNULL( UTFencoding, "UnicodeDoubleLinkedList::Construction failed - the given pointer is NULL" );

            // Check that the given number of bytes in the UTF encoding is not 0
            ThrowExceptionIfValueOneIsEqualToValueTwo< UnsignedInteger64bits >( UTFencodingNumberOfBytes, 0, "UnicodeDoubleLinkedList::Construction failed - the given size of the UTF encoding is 0" );

            // Check that the number of bytes in the UTF encoding divides by the encoding type with no remainder
            ThrowExceptionIfNumberOfBytesDoesNotDivideByEncodingTypeWithNoRemainderIMP( UTFencodingNumberOfBytes, encodingType );

            // The UTF encoding options are : Ascii, UTF-8, UTF-16 little and big endian, UTF-32 little and big endian

            // Create the unicode scalar values double linked list from the UTF encdoing
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
    	inline UnicodeDoubleLinkedList::UnicodeDoubleLinkedList( const UnicodeDoubleLinkedList& other ) throw( std::bad_alloc, Exception ) :
        BasicTypesDoubleLinkedList( other ),
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
        inline UnicodeDoubleLinkedList& UnicodeDoubleLinkedList::operator=( const UnicodeDoubleLinkedList& other ) throw( std::bad_alloc, Exception )
        {
            // Use the assignment operator of the base class basic types double linked list
            BasicTypesDoubleLinkedList::operator=( other );
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
    	inline UnicodeDoubleLinkedList::UnicodeDoubleLinkedList( UnicodeDoubleLinkedList&& other ) throw() :
        BasicTypesDoubleLinkedList( other ),
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
        inline UnicodeDoubleLinkedList& UnicodeDoubleLinkedList::operator=( UnicodeDoubleLinkedList&& other ) throw()
        {
            // Use the move assignment operator of the base class basic types double linked list
            BasicTypesDoubleLinkedList::operator=( other );
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
    	virtual inline UnicodeDoubleLinkedList::~UnicodeDoubleLinkedList() throw()
        {}























//  ***********************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ******************************************************************


























//	****************************************************************   PRIVATE METHODS IMPLEMENTATION   *************************************************************************




























// ************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -  UnicodeDoubleLinkedListProxy  ***********************************************


























    }  //  Namespace Encoding

}  //  Namespace Universe



#endif  // UNICODEDOUBLELINKEDLIST_H