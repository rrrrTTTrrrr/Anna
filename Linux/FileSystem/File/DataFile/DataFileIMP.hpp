#ifndef  DATAFILE_HPP
#define  DATAFILE_HPP



// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Exception/Exception.hpp"  //  Class Exception
#endif


// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part



namespace Universe
{

    namespace FileSystem
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
    	// with byte order in memory. In the byte itself the bit the is closest to the
    	// address of the byte, is the high order bit
    	//
    	//    The closest bit to the    The farest bit from the
    	//     address of the byte        address of the byte
    	//                        |      |
    	//      Byte address ->   00000000
    	//                        |      |
    	//            High order bit    Low order bit
    	//
    	// Then the value 1 will be stored this way :
    	//
    	//      Byte address ->   00000001
    	//                        |      |
    	//            High order bit    Low order bit
    	//
    	// Then in 1 byte this is always the case. But when dealing with more then 1 byte
    	// it is up to the system to decide whether the address of the first byte will
    	// contain the high order bits or the low order bits. For example for 2 bytes,
    	// store the value 1 in the 2 ways of endian encoding :
    	//
    	//    Big endian encoding :
    	//
    	//      First address of data type ->   00000000 00000001
    	//
    	//    Big endian encoding :
    	//
    	//      First address of data type ->   00000001 00000000


    	// To support move semantics every object must provide a default state. There are
    	// how ever few exceptions, as objects that their members stay exactly the same along
    	// the run of the program, objects that don't have members at all, and objects with
    	// undefined state. This default state will be used to notify that the object should
    	// not be used :
    	//
    	//
    	// When the object is in this state it should not be used ( the object is empty )


    	// Constructor of derived object, when called, all the base class constructors are executed
    	// first, according to the order they appear in the class declaration, and only then the
    	// user code is executed

    	// Destructor of derived object, when it is called, the user code existing in the destructor
    	// itself is executed first and then all the destructors of the base objects, in an opposite
    	// way from which they were constructed


		// Template class Information :
    	//
    	//  Purpose :
    	//
    	//
    	//
   	    //  Description :
   	    //
  	    //      There is no exception specification on purpose. The reason is that when working with templates, the given type of the template
   	    //      can overload and override any operator and method, and therefore throw anything it see fit. This causes the problem, there is
  	    //      no way of knowing what the given type throws. The only method declared with exception specification is the destructor, which should
        //      not throw any exception anyhow, to prevent throwing an exception while another exception is active. This will cause the
    	//      program to end
        //
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename TYPE >
        class DataFile : private AloneIstand
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
    		explicit inline DataFile();


            // Method Information :
            //
            //  Description :
            //
            //      Constructor,
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. fileNameIncludingFullPath - the absolute path to the file including the file name itself
            //          2. filePageSizeInBytes - the number of bytes each file page should be, this number must divide by the template type size with no remainder
            //          3. maximumNumberOfFilePagesInMainMemory - the maximum amount of file pages in main memory
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
            //      They will come
            //
            explicit inline DataFile( const Encoding::UnicodeString& fileNameIncludingFullPath, UnsignedInteger64bits filePageSizeInBytes, UnsignedInteger64bits maximumNumberOfFilePagesInMainMemory );


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
    		inline ~DataFile() throw();


    		// To support Move semantics, the following 3 methods are added to every object. One method to set
    		// the object into the default state, another to check if the object is in the default state,
    		// and the last method to delete all the object resources and set the object to default state :


    		// Method Information :
    		//
    		//  Description :
    		//
        	//      Use to set the object into his default state. This method does not delete the resources inside, it
    		//      only set the data members inside the object to the default value. Note - if this method is used
    		//      and there are still resources used, all those resources will not be accessable anymore, and therefore
    		//      can not be deleted
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
    		//	    They will come
    		//
    		void SetToDefaultState();


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Use to check if the object is in default state
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
    		//      1. true, if instance is at default state
    		//      2. false, if instance is not at default state
    		//
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		bool DefaultState() const;


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use to delete the object resources and set the object to default state. Note - if the object is in default
    		//		state the method do nothing
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
    		//  Possible errors :
    		//
    		//      1. Deleting the object resources failed
    		//      2.
    		//
    		void DeleteResourcesAndSetToDefaultState();


    		// The following methods are the interface of the object. This methods implement the capabilities of the object :











    		// The following methods declare the overloaded operators for the object :


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this operator to check if the this object matches the other object. Important note - if both objects
    		//      are in default state, then the objects still match and false will be returned
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//          other - a reference to the object that should be compared with this object
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//      1. true - if the 2 objects are the same
    		//      2. false - otherwise
    		//
    		//  Possible errors :
    		//
    		//      1. Both of the objects are in default state - class Exception is thrown
    		//      2. The template type object does not have the comparison operator ( == )
    		//      3. 
    		//
    		bool operator==( const DataFile< TYPE >& other ) const;


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this operator to check if the this object does not match the other object. Important note - if both objects
    		//      are in default state, then the objects still match and false will be returned
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//          other - a reference to the object that should be compared with this object
    		//
    		//      Information returned to the user :
    		//
    		//          NONE
    		//
    		//  Return value :
    		//
    		//      1. true - if the 2 objects are not the same
    		//      2. false - otherwise
    		//
    		//  Possible errors :
    		//
    		//      1. Both of the objects are in default state - class Exception is thrown
    		//      2. The template type object does not have the comparison operator ( != )
    		//      3. 
    		//
    		bool operator!=( const DataFile< TYPE >& other ) const;


    		// The following functions are declared static. Static functions do not belong to any of
    		// the instances, but rather to the class. Satic functions only have access to static
    		// data members, which means all other data members can not be used. The only purpose
    		// then of declaring a static function is when a private static data member needs to be
    		// manipulated


    		// This part of the class is dedicated for testing :


    		// All the following methods will be added only in test mode, they are not part of the implementation, their purpose is to
    		// help locate problems in the code


    		DEBUG_TOOL(


    			// This part of the class is dedicated for testing :


    			// Method Information :
    			//
    			//  Description :
    			//
    			//      This method is used to test the object
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
    			//  Possible errors :
    			//
    			//      1. A method does not work correctly - class Exception is thrown
    			//		2. There is no more free memory space - class std::bad_alloc is thrown
    			//		3. 
    			//
    			static void Test() throw( std::bad_alloc, Exception );


    		)  //  End of debug tool


    	private:


            // This object will store the size of the file pages in bytes
            UnsignedInteger64bits m_pageFileSizeInBytes;

            // This object will store the size of the file pages
            UnsignedInteger64bits m_pageFileSizeInTemplateType;

            // This object will store the maximum memory space that the file should occupy in main memory ( in other words, 
            // the maximum amount of pages in main memory )
            UnsignedInteger64bits m_maximumNumberOfFilePagesInMainMemory;

            // This object will be used to upload the file from secondary memory to main memory
            UploadFileToMainMemory m_uploadFileToMainMemory;

            // This object will store the number of template type that fit in the file
            UnsignedInteger64bits m_fileSizeInTemplateType;

            // This object will store the file pages in main memory
            GeneralPurposeContainers::ObjectsArray< SmartPointers::AutomaticPointer< TYPE > > m_file;

            // This object will store the use order of the file pages in main memory and also it will store the current 
            // number of file pages in main memory
            GeneralPurposeContainers::BasicTypesUseOrderWithNoDuplications< UnsignedInteger64bits > m_filePagesUseOrder;


        	// Static data members do not belong to any instnace, it belongs to the class. Like every global variable
    		// it is created with the start of the program and only destroyed when the program ends. This means that
    		// each member method can use the static data members, but not functions outside the object's scope. It
    		// restricts the access to this object use only, but rather then that acts as global variable


    		// The following methods are private. This means that only public or protected methods can use them, in other
    		// words they not part of the interface, but rather help implement it :


            // Method Information :
            //
            //  Description :
            //
            //      Use to check if the value divides by the template type size with no remainder, and only if it 
            //      does the method will return the value divided by the template type size
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          value - the value that should be checked if it divides by the template type size with no remainder
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The value divided by the template type size
            //
            //  Possible errors :
            //
            //      1. The given value does not divide by the template type with no remainder - class Exception is thrown
            //      2. 
            //
            inline UnsignedInteger64bits AssertTheValueDividesByTheTemplateTypeWithNoRemainderIMP( UnsignedInteger64bits value ) const;


    		// Friend class or friend function can access private and protected members of other class in which it is declared as friend.
    		// It is sometimes useful to allow a particular class to access private members of other class. The declration of such function
    		// is private, because these functions are part of the implemntation, which the user should not be aware of. Furthermore the
    		// use of this functions is not limited to the class's scope. The following declarations are for all the function that should
    		// be friends with this class :




    	};  //  Class DataFile


















































//	*******************************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   *********************************************************************



































        // Method Information :
        //
        //  Description :
        //
        //      Default Constructor, used to support move semantics
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
        //  Possible errors :
        //
        //      They will come
        //
        template< typename TYPE >
        inline DataFile< TYPE >::DataFile() :
        m_pageFileSizeInBytes( 0 ),
        m_pageFileSizeInTemplateType( 0 ),
        m_maximumNumberOfFilePagesInMainMemory( 0 ),
        m_uploadFileToMainMemory(),
        m_fileSizeInTemplateType( 0 ),
        m_file(),
        m_filePagesUseOrder()   
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Constructor,
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. fileNameIncludingFullPath - the absolute path to the file including the file name itself
        //          2. filePageSizeInBytes - the number of bytes each file page should be, this number must divide by the template type size with no remainder
        //          3. maximumNumberOfFilePagesInMainMemory - the maximum amount of file pages in main memory
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
        //      They will come
        //
        template< typename TYPE >
        inline DataFile< TYPE >::DataFile( const Encoding::UnicodeString& fileNameIncludingFullPath, UnsignedInteger64bits filePageSizeInBytes, UnsignedInteger64bits maximumNumberOfFilePagesInMainMemory ) :
        m_pageFileSizeInBytes( filePageSizeInBytes ),
        m_pageFileSizeInTemplateType( ReturnPageFileSizeInTemplateTypeIfFilePageSizeInBytesDivideByTheTemplateTypeSizeWithNoRemainderIMP( filePageSizeInBytes ) ),
        m_maximumNumberOfFilePagesInMainMemory( maximumNumberOfFilePagesInMainMemory ),
        m_uploadFileToMainMemory( fileNameIncludingFullPath ),
        m_fileSizeInTemplateType( ReturnFileSizeInTemplateTypeIfFileSizeInBytesDivideByTheTemplateTypeSizeWithNoRemainderIMP( m_uploadFileToMainMemory.GetSize() ) ),
        m_file( m_pageFileSizeInTemplateType / m_fileSizeInTemplateType ),
        m_filePagesUseOrder()       
        {}


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
    	template< typename TYPE >
        inline DataFile< TYPE >::~DataFile() throw()
        {
            // Delete the object resources and set the default state
            DeleteResourcesAndSetToDefaultState();
        }


        // Method Information :
    	//
    	//  Description :
    	//
        //      Use to set the object into his default state. This method does not delete the resources inside, it
    	//      only set the data members inside the object to the default value. Note - if this method is used
    	//      and there are still resources used, all those resources will not be accessable anymore, and therefore
    	//      can not be deleted
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
    	//	    They will come
    	//
    	template< typename TYPE >
    	void DataFile< TYPE >::SetToDefaultState()
        {
            // Set the file page size in bytes to 0
            m_pageFileSizeInBytes = 0;

            // Set the file page size in the template type to 0
            m_pageFileSizeInTemplateType = 0;

            // Set the maximum amount of file pages that should be in main memory to 0
            m_maximumNumberOfFilePagesInMainMemory = 0;

            // Set the upload file to main memory object to default state
            m_uploadFileToMainMemory.SetToDefaultState();

            // Set the number of template type that fits into the file to 0
            m_fileSizeInTemplateType = 0;

            // Set the read file array to default state
            m_file.SetToDefaultState();

            // Set the file pages use order object to default state
            m_filePagesUseOrder.SetToDefaultState();
        }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//   	Use to check if the object is in default state
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
    	//      1. true, if instance is at default state
    	//      2. false, if instance is not at default state
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename TYPE >
    	bool DataFile< TYPE >::DefaultState() const
    	{

            // Check if the object is in default state
            if ( ( m_pageFileSizeInBytes == 0 ) &&
                 ( m_pageFileSizeInTemplateType == 0 ) &&
                 ( m_maximumNumberOfFilePagesInMainMemory == 0 ) &&
                 ( m_uploadFileToMainMemory.DefaultState() == true ) &&
                 ( m_fileSizeInTemplateType == 0 ) &&
                 ( m_file.DefaultState() == true ) && 
                 ( m_filePagesUseOrder.DefaultState() == true ) )
    		{
    		    // The object is in default state
            	return ( true );
        	}

        	// The object is not in default state
        	return ( false );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use to delete the object resources and set the object to default state. Note - if the object is in default
    	//		state the method do nothing
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
    	//  Possible errors :
    	//
    	//      1. Deleting the object resources failed
    	//      2.
    	//
    	template< typename TYPE >
    	void DataFile< TYPE >::DeleteResourcesAndSetToDefaultState()
    	{
    		// Check if the object is in default state, then noting needs to be done
    		RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

    		// Release the resources of this object

            // Delete the upload file to main memory object resources and set to default state
            m_uploadFileToMainMemory.DeleteResourcesAndSetToDefaultState();

            // Delete the read file array object resources and set to default state
            m_file.DeleteResourcesAndSetToDefaultState();

            // Delete the file pages use order object resources and set to default state
            m_filePagesUseOrder.DeleteResourcesAndSetToDefaultState();

            // Set the file page size in bytes to 0
            m_pageFileSizeInBytes = 0;

            // Set the file page size in the template type to 0
            m_pageFileSizeInTemplateType = 0;

            // Set the maximum amount of file pages that should be in main memory to 0
            m_maximumNumberOfFilePagesInMainMemory = 0;

            // Set the number of template type that fits into the file to 0
            m_fileSizeInTemplateType = 0;
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//		Use this method to read from the file
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
    	//  Possible errors :
    	//
    	//      1. Deleting the object resources failed
    	//      2.
    	//
    	template< typename TYPE >
    	void DataFile< TYPE >::DeleteResourcesAndSetToDefaultState(  )
















































//  ***********************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   *****************************************************












































    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this operator to check if the this object matches the other object. Important note - if both objects
    	//      are in default state, then the objects still match and false will be returned
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//          other - a reference to the object that should be compared with this object
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//      1. true - if the 2 objects are the same
    	//      2. false - otherwise
    	//
    	//  Possible errors :
    	//
    	//      1. Both of the objects are in default state - class Exception is thrown
    	//      2. The template type object does not have the comparison operator ( == )
    	//      3. 
    	//
    	template< typename TYPE >
    	bool DataFile< TYPE >::operator==( const DataFile< TYPE >& other ) const
    	{
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this operator to check if the this object does not match the other object. Important note - if both objects
    	//      are in default state, then the objects still match and false will be returned
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//          other - a reference to the object that should be compared with this object
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//      1. true - if the 2 objects are not the same
    	//      2. false - otherwise
    	//
    	//  Possible errors :
    	//
    	//      1. Both of the objects are in default state - class Exception is thrown
    	//      2. The template type object does not have the comparison operator ( != )
    	//      3. 
    	//
    	template< typename TYPE >
    	bool DataFile< TYPE >::operator!=( const DataFile< TYPE >& other ) const
    	{
    		}

































//  *****************************************************************   TEMPLATE OR INLINE STATIC FUNCTIONS IMPLEMENTATION   ***************************************************
































//	**********************************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ************************************************





























        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the value divides by the template type size with no remainder, and only if it 
        //      does the method will return the value divided by the template type size
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          value - the value that should be checked if it divides by the template type size with no remainder
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The value divided by the template type size
        //
        //  Possible errors :
        //
        //      1. The given value does not divide by the template type with no remainder - class Exception is thrown
        //      2. 
        //
        template< typename TYPE >
        inline UnsignedInteger64bits DataFile< TYPE >::AssertTheValueDividesByTheTemplateTypeWithNoRemainderIMP( UnsignedInteger64bits value ) const
        {
            // Check if the given file page size in bytes divide by the template type with no remainder
            Assert::True( ( ( value % sizeof( TYPE ) ) != 0 ), "DataFile::AssertTheValueDividesByTheTemplateTypeWithNoRemainderIMP failed - the given value does not divide by the template type with no remainder" );

            // Return the number of template types that should appear in every page
            return ( value / sizeof( TYPE ) );
        }







































// *******************************************************   NESTED CLASS IMPLEMENTATION -    ****************************************************************











// *******************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   *******************************************












    	// This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
    	// within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
    	// to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
    	// this functions are needed to avoid just that








// ***********************************************************************   TESTING   ***********************************************************************












    	// All the following methods will be added only in test mode, they are not part of the implementation, their purpose is to
    	// help locate problems in the code


    	DEBUG_TOOL(
    		// Method Information :
    			//
    			//  Description :
    			//
    			//      This method is used to test the object
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
    			//  Possible errors :
    			//
    			//      1. A method does not work correctly - class Exception is thrown
    			//		2. There is no more free memory space - class std::bad_alloc is thrown
    			//		3. 
    			//
    			template< typename TYPE >
    	void DataFile< TYPE >::Test() throw( std::bad_alloc, Exception )
    			{
    			// Get an handle to the assert object
    			ErrorHandling::Assert& assert = ErrorHandling::Assert::GetHandle();
    	}


    )  //  End of debug tool











    }  //  Namespace FileSystem

}  //  Namespace Universe



#endif  // DATAFILE_HPP