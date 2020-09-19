#ifndef  READDATAFILE_H
#define  READDATAFILE_H


#include "../../../../Encoding/Unicode/UnicodeString/UnicodeString.h"  //  Class UnicodeString
#include "../../../../Definitions/VariableTypesDefinitions.h"  //  Typedef UnsignedInteger64bits
#include "../../UploadFileToMainMemory/UploadFileToMainMemory.h"  //  Class UploadFileToMainMemory
#include "../../../../GeneralPurposeContainers/Array/Objects/ObjectsFixedSizeArray/ObjectsFixedSizeArray.h"  //  Class ObjectsFixedSizeArray
#include "../../../../GeneralPurposeContainers/Array/BasicTypes/BasicTypesFixedSizeArray/BasicTypesFixedSizeArray.h"  //  Class BasicTypesFixedSizeArray
#include "../../../../DesignPatterns/UseOrder/UseOrderWithNoDuplications/BasicTypesUseOrderWithNoDuplications/BasicTypesUseOrderWithNoDuplications.h"  //  Class BasicTypesUseOrderWithNoDuplications



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
    	//      program toend
        //
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename T >
        class ReadDataFile
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
    		explicit inline ReadDataFile();


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
            //          2. filePageSizeInBytes - the number of bytes each file page should be
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
            explicit inline ReadDataFile( const Encoding::UnicodeString& fileNameIncludingFullPath, UnsignedInteger64bits filePageSizeInBytes, UnsignedInteger64bits maximumNumberOfFilePagesInMainMemory );


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
    		explicit ReadDataFile( const ReadDataFile& other );


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
    		ReadDataFile& operator=( const ReadDataFile& other );


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
    		explicit ReadDataFile( ReadDataFile&& other );


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
    		ReadDataFile& operator=( ReadDataFile&& other );


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
    		inline ~ReadDataFile() throw();


    		// To support Move semantics, the following 3 methods are added to every object. One method to set
    		// the object into the default state, another to check if the object is in the default state,
    		// and the last method to delete all the object resources :


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
    		//      Use to delete the object resources and set object to default state. Note - if the object is in 
            //      default state the method do nothing
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


    		// The following methods are the interface of the object. This methods implement the
    		// capabilities of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the file size in bytes
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
            //      The number of bytes the file is stored on
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2.
            //
            inline void GetAmountOfTemplateTypeInFilePage() const;


            // Method Information :
            //
            //  Description :
            //
            //      Use to change the file that needs to be read
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. newFileNameIncludingFullPath - the absolute path to the file including the file name itself
            //          2. newFilePageSizeInBytes - the number of bytes each file page should be
            //          3. newMaximumNumberOfFilePagesInMainMemory - the maximum amount of file pages in main memory
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
            //      1. 
            //      2.
            //
            inline void SetNewFileToRead( const Encoding::UnicodeString& newFileNameIncludingFullPath, UnsignedInteger64bits newFilePageSizeInBytes, UnsignedInteger64bits newMaximumNumberOfFilePagesInMainMemory );


    		// The following methods declare the overloaded operators for the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use to access the required data in the file
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          fileEntryIndex - the index of the required data in the file, the index will be treated not for bytes but rather for the template type multiples
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      A copy of the required data from the file
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2.
            //
            inline T operator[]( UnsignedInteger64bits fileEntryIndex ) const;


    	private:


            // This object will store the size of the file pages in bytes
            UnsignedInteger64bits m_pageFileSizeInBytes;

            // This object will store the size of the file pages
            UnsignedInteger64bits m_pageFileSizeInTemplateType;

            // This object will store the maximum memory space that the file should occupy in main memory ( in other words, the maximum amount of pages 
            // in main memory )
            UnsignedInteger64bits m_maximumNumberOfFilePagesInMainMemory;

            // This object will be used to upload the file from secondary memory to main memory
            UploadFileToMainMemory m_uploadFileToMainMemory;

            // This object will store the number of template type that fit in the file
            UnsignedInteger64bits m_fileSizeInTemplateType;

            // This object will store the file in main memory
            GeneralPurposeContainers::ObjectsFixedSizeArray< GeneralPurposeContainers::BasicTypesFixedSizeArray< T > > m_readFile;

            // This object will store the use order of the file pages in main memory
            DesignPatterns::BasicTypesUseOrderWithNoDuplications< UnsignedInteger64bits > m_filePagesUseOrder;

            // This object will store the number of file pages currently in main memory
            UnsignedInteger64bits m_numberOfFilePagesInMainMemory;


            // Method Information :
            //
            //  Description :
            //
            //      Use to calculate the index of the basic type fixed size array the data is in
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          filePageSizeInBytes - the number of bytes each file page should be, this number must divide by the template type size with no remainder
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The number of the template type that should appear in every page
            //
            //  Possible errors :
            //
            //      1. The given file page size in bytes does not divide by the template type with no remainder - class Exception is thrown
            //      2. 
            //
            inline UnsignedInteger64bits CheckIfPageSizeInBytesDivideByTheTemplateTypeSizeWithNoRemainderIMP( UnsignedInteger64bits filePageSizeInBytes ) const;

      
            // Method Information :
            //
            //  Description :
            //
            //      Use to calculate the index of the basic type fixed size array the data is in
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          fileEntryIndex - the index of the required data in the file
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The index of the basic types fixed size array that the data is in 
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline UnsignedInteger64bits GetIndexOfArrayTheDataIsInIMP( UnsignedInteger64bits fileEntryIndex ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use to calculate the index of the data inside the basic types fixed size array
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          fileEntryIndex - the index of the required data in the file
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The index of the data inside the basic types fixed size array 
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline UnsignedInteger64bits GetTheIndexOfDataInsideTheArrayIMP( UnsignedInteger64bits fileEntryIndex ) const;


            // Method Information :
            //
            //  Description :
            //
            //      Use to check if the required file currently exist in main memory, and if not upload it
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          filePageIndex - the index of the required file page
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
            inline void UploadFilePageIfNotInMainMemoryIMP( UnsignedInteger64bits filePageIndex );


        };  //  Class ReadDataFile


















//	**************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ************************************

















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
    	template< typename T >
    	inline ReadDataFile< T >::ReadDataFile() :
        m_pageFileSizeInBytes( 0 ),
        m_pageFileSizeInTemplateType( 0 ),
        m_maximumNumberOfFilePagesInMainMemory( 0 ),
        m_uploadFileToMainMemory(),
        m_fileSizeInTemplateType( 0 ),
        m_readFile(),
        m_filePagesUseOrder(),
        m_numberOfFilePagesInMainMemory( 0 )
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
    	//   	NONE
    	//
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename T >
    	inline ReadDataFile< T >::ReadDataFile( const Encoding::UnicodeString& fileNameIncludingFullPath, UnsignedInteger64bits filePageSizeInBytes, UnsignedInteger64bits maximumNumberOfFilePagesInMainMemory ) :
        m_pageFileSizeInBytes( filePageSizeInBytes ),
        m_pageFileSizeInTemplateType( CheckIfPageSizeInBytesDivideByTheTemplateTypeSizeWithNoRemainderIMP( filePageSizeInBytes ) ),
        m_maximumNumberOfFilePagesInMainMemory( maximumNumberOfFilePagesInMainMemory ),
        m_uploadFileToMainMemory( fileNameIncludingFullPath ),
        m_fileSizeInTemplateType( m_uploadFileToMainMemory.GetSize() / sizeof( T ) ),
        m_readFile( m_fileSizeInTemplateType / m_pageFileSizeInTemplateType ),
        m_filePagesUseOrder(),
        m_numberOfFilePagesInMainMemory( 0 )
        {}



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
    	template< typename T >
    	inline ReadDataFile< T >::ReadDataFile( const ReadDataFile& other ) :
        m_pageFileSizeInBytes( other.m_pageFileSizeInBytes ),
        m_pageFileSizeInTemplateType( other.m_pageFileSizeInTemplateType ),
        m_maximumNumberOfFilePagesInMainMemory( other.m_maximumNumberOfFilePagesInMainMemory ),
        m_uploadFileToMainMemory( other.m_uploadFileToMainMemory ),
        m_fileSizeInTemplateType( other.m_fileSizeInTemplateType ),
        m_readFile( other.m_readFile ),
        m_filePagesUseOrder( other.m_filePagesUseOrder ),
        m_numberOfFilePagesInMainMemory( 0 )
        {}


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
    	template< typename T >
    	ReadDataFile< T >& ReadDataFile< T >::operator=( const ReadDataFile& other )
    	{

    		// Check that this is not self assignment
    		if ( this != &other )
    		{
    			// This is not self assignment

    			// Check if the other object is in default state
    			if ( true == other.DefaultState() )
    			{
    				// The other object is in default state

                    // Release all the resources of this object
                    DeleteResourcesAndSetToDefaultState();

    				// Nothing else needs to be done, return a reference to this object
    				return ( *this );
    			}

    			// Copy the other object resources

                // Copy the file page size on bytes
                m_pageFileSizeInBytes = other.m_pageFileSizeInBytes;

                // Copy the file page size
                m_pageFileSizeInTemplateType = other.m_pageFileSizeInTemplateType;

                // Copy the maximum amount of file pages that should be in main memory
                m_maximumNumberOfFilePagesInMainMemory = other.m_maximumNumberOfFilePagesInMainMemory;

                // Copy the upload file to main memory object
                m_uploadFileToMainMemory = other.m_uploadFileToMainMemory;

                // Copy the number of template type that fits in the file
                m_fileSizeInTemplateType = other.m_fileSizeInTemplateType;

                // Copy the file itself from the other object to this object
                m_readFile = other.m_readFile;

                // Copy the file pages use order list
                m_filePagesUseOrder = other.m_filePagesUseOrder;

                // Copy the number of file pages currently in main memory
                m_numberOfFilePagesInMainMemory = other.m_numberOfFilePagesInMainMemory;
    		}

    		// Return a reference to this object
    		return ( *this );
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
    	template< typename T >
    	ReadDataFile< T >::ReadDataFile( ReadDataFile&& other ) :
        m_pageFileSizeInBytes( other.m_pageFileSizeInBytes ),
        m_pageFileSizeInTemplateType( other.m_pageFileSizeInTemplateType ),
        m_maximumNumberOfFilePagesInMainMemory( other.m_maximumNumberOfFilePagesInMainMemory ),
        m_uploadFileToMainMemory( other.m_uploadFileToMainMemory ),
        m_fileSizeInTemplateType( other.m_fileSizeInTemplateType ),
        m_readFile( other.m_readFile ),
        m_filePagesUseOrder( other.m_filePagesUseOrder ),
        m_numberOfFilePagesInMainMemory( other.m_numberOfFilePagesInMainMemory )
    	{
    		// Set the other object to default state, this way it can't be used
    		other.SetToDefaultState();
    	}


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
    	template< typename T >
    	ReadDataFile< T >& ReadDataFile< T >::operator=( ReadDataFile&& other )
    	{

    		// Check that this is not self assignment
    		if ( this != &other )
    		{
    			// This is not self assignment

    			// Check if the other object is in default state
    			if ( true == other.DefaultState() )
				{
    				// The other object is in default state

                    // Release all the resources of this object
                    DeleteResourcesAndSetToDefaultState();

    				// Nothing else needs to be done, return a reference to this object
    				return ( *this );
    			}

    			// Take the other object resources

                // Take the file page size on bytes
                m_pageFileSizeInBytes = other.m_pageFileSizeInBytes;

                // Take the file page size
                m_pageFileSizeInTemplateType = other.m_pageFileSizeInTemplateType;

                // Take the maximum amount of file pages that should be in main memory
                m_maximumNumberOfFilePagesInMainMemory = other.m_maximumNumberOfFilePagesInMainMemory;

                // Take the upload file to main memory object
                m_uploadFileToMainMemory = other.m_uploadFileToMainMemory;

                // Take the number of template type that fits in the file
                m_fileSizeInTemplateType = other.m_fileSizeInTemplateType;

                // Take the file itself from the other object to this object
                m_readFile = other.m_readFile;

                // Take the file pages use order list
                m_filePagesUseOrder = other.m_filePagesUseOrder;

                // Take the number of file pages currently in main memory
                m_numberOfFilePagesInMainMemory = other.m_numberOfFilePagesInMainMemory;

    			// Set the other object to default state
            	other.SetToDefaultState();
    		}

    		// Return a reference to this object
    		return ( *this );
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
    	template< typename T >
        inline ReadDataFile< T >::~ReadDataFile() throw()
        {
            // Delete the object resources
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
    	template< typename T >
    	void ReadDataFile< T >::SetToDefaultState()
        {
            // Set the file page size in bytes to 0
            m_pageFileSizeInBytes = 0;

            // Set the file page size to 0
            m_pageFileSizeInTemplateType = 0;

            // Set the maximum amount of file pages that should be in main memory to 0
            m_maximumNumberOfFilePagesInMainMemory = 0;

            // Set the upload file to main memory object to default state
            m_uploadFileToMainMemory.SetToDefaultState();

            // Set the number of template type that fits into the file to 0
            m_fileSizeInTemplateType = 0;

            // Set the read file array to default state
            m_readFile.SetToDefaultState();

            // Set the file pages use order object to default state
            m_filePagesUseOrder.SetToDefaultState();

            // Set the number of file pages currently in main memory to 0
            m_numberOfFilePagesInMainMemory = 0;
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
    	template< typename T >
    	bool ReadDataFile< T >::DefaultState() const
    	{

    		// Check if the object is in default state
    		if ( 0 == m_pageFileSizeInBytes &&
                 0 == m_pageFileSizeInTemplateType &&
                 0 == m_maximumNumberOfFilePagesInMainMemory &&
                 true == m_uploadFileToMainMemory.DefaultState() &&
                 0 == m_fileSizeInTemplateType &&
                 true == m_readFile.DefaultState() && 
                 true == m_filePagesUseOrder.DefaultState() &&
                 0 == m_numberOfFilePagesInMainMemory )
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
    	//      Use to delete the object resources and set object to default state. Note - if the object is in 
        //      default state the method do nothing
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
    	template< typename T >
    	void ReadDataFile< T >::DeleteResourcesAndSetToDefaultState()
    	{
    		// Check if the object is in default state, then noting needs to be done
    		RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

    		// Release the resources of this object

            // Delete the resources of the upload file to main memory object
            m_uploadFileToMainMemory.DeleteResourcesAndSetToDefaultState();

            // Delete the resources of the read file array
            m_readFile.DeleteResourcesAndSetToDefaultState();

            // Delete the resource of the file pages use order list
            m_filePagesUseOrder.DeleteResourcesAndSetToDefaultState();

            // Set the object to default state
            SetToDefaultState();
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the number of template type in the file
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
        //      The number of template type in the file
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2.
        //
        template< typename T >
        inline void ReadDataFile< T >::GetAmountOfTemplateTypeInFilePage() const
        {
            // Check that this object is not in default state
            ThrowExceptionIfExpressionIsTrue( DefaultState(), "ReadDataFile::GetAmountOfTemplateTypeInFilePage failed - the object is in default state" );

            // Return the size of the file in bytes
            return ( m_fileSizeInTemplateType );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to change the file that needs to be read
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          1. newFileNameIncludingFullPath - the absolute path to the file including the file name itself
        //          2. newFilePageSizeInBytes - the number of bytes each file page should be
        //          3. newMaximumNumberOfFilePagesInMainMemory - the maximum amount of file pages in main memory
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
        //      1. 
        //      2.
        //
        template< typename T >
        inline void ReadDataFile< T >::SetNewFileToRead( const Encoding::UnicodeString& newFileNameIncludingFullPath, UnsignedInteger64bits newFilePageSizeInBytes, UnsignedInteger64bits newMaximumNumberOfFilePagesInMainMemory )
        {
            // Delete the current resources of the object
            DeleteResourcesAndSetToDefaultState();

            // Set the new file page size in bytes
            m_pageFileSizeInBytes = newFilePageSizeInBytes;

            // Set the new file page size in multiple of the template type
            m_pageFileSizeInTemplateType = CheckIfPageSizeInBytesDivideByTheTemplateTypeSizeWithNoRemainderIMP( newFilePageSizeInBytes );

            // Set the new maximum file pages that should be in main memory
            m_maximumNumberOfFilePagesInMainMemory = newMaximumNumberOfFilePagesInMainMemory;

            // Set the upload file to main memory object to the new file
            m_uploadFileToMainMemory.SetNewFile( newFileNameIncludingFullPath );

            // Set the file size in the multiple of the template type
            m_fileSizeInTemplateType = ( m_uploadFileToMainMemory.GetSize() / sizeof( T ) );

            // Set the number 
            m_readFile.SetNewSize( m_fileSizeInTemplateType / m_pageFileSizeInTemplateType );

            // The number of file pages currently in main memory is already set to 0
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to access the required data in the file
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          fileEntryIndex - the index of the required data in the file, the index will be treated not for bytes but rather for the template type multiples
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      A copy of the required data from the file
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2.
        //
        template< typename T >
        inline T ReadDataFile< T >::operator[]( UnsignedInteger64bits fileEntryIndex ) const
        {
            // Check that this object is not in default state
            ThrowExceptionIfExpressionIsTrue( DefaultState(), "ReadDataFile::operator[] failed - the object is in default state" );

            // Check that the index does not exceed the end of file
            ThrowExceptionIfExpressionIsTrue( ( fileEntryIndex > m_fileSizeInTemplateType ), "ReadDataFile::operator[] failed - the given index exceed the end of file" );

            // Create an object to store the index of the array that should store the file page
            UnsignedInteger64bits arrayIndexOfFilePage = GetIndexOfArrayTheDataIsInIMP( fileEntryIndex );

            // Check if the file exist in main memory and if not upload it
            UploadFilePageIfNotInMainMemoryIMP( arrayIndexOfFilePage );

            // Return a copy of the required data in the file
            return ( m_readFile[ arrayIndexOfFilePage ][ GetTheIndexOfDataInsideTheArrayIMP( fileEntryIndex ) ] );
        }




















//	*****************************************   PRIVATE METHODS IMPLEMENTATION   ******************************************  





















        // Method Information :
        //
        //  Description :
        //
        //      Use to calculate the index of the basic type fixed size array the data is in
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          filePageSizeInBytes - the number of bytes each file page should be, this number must divide by the template type size with no remainder
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The number of the template type that should appear in every page
        //
        //  Possible errors :
        //
        //      1. The given file page size in bytes does not divide by the template type with no remainder - class Exception is thrown
        //      2. 
        //
        template< typename T >
        inline UnsignedInteger64bits ReadDataFile< T >::CheckIfPageSizeInBytesDivideByTheTemplateTypeSizeWithNoRemainderIMP( UnsignedInteger64bits filePageSizeInBytes ) const
        {
            // Check if the given file page size in bytes divide by the template type with no remainder
            ThrowExceptionIfExpressionIsTrue( ( ( filePageSizeInBytes % sizeof( T ) ) != 0 ), "ReadDataFile::CheckIfPageSizeInBytesDivideByTheTemplateTypeSizeWithNoRemainderIMP failed - the given file page size in bytes does not divide by th template type with no remainder" );

            // Return the number template type that should appear in every page
            return ( filePageSizeInBytes / sizeof( T ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to calculate the index of the basic type fixed size array the data is in
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          fileEntryIndex - the index of the required data in the file
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The index of the basic types fixed size array that the data is in 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename T >
        inline UnsignedInteger64bits ReadDataFile< T >::GetIndexOfArrayTheDataIsInIMP( UnsignedInteger64bits fileEntryIndex ) const
        {
            // Return the index of the array the data is in
            return ( ( fileEntryIndex / m_pageFileSizeInTemplateType ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to calculate the index of the data inside the basic types fixed size array
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          fileEntryIndex - the index of the required data in the file
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The index of the data inside the basic types fixed size array 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename T >
        inline UnsignedInteger64bits ReadDataFile< T >::GetTheIndexOfDataInsideTheArrayIMP( UnsignedInteger64bits fileEntryIndex ) const
        {
            // Return the index of the array the data is in
            return ( ( fileEntryIndex % m_pageFileSizeInTemplateType ) );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the required file currently exist in main memory, and if not upload it
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          filePageIndex - the index of the required file page
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
        template< typename T >
        void ReadDataFile< T >::UploadFilePageIfNotInMainMemoryIMP( UnsignedInteger64bits filePageIndex )
        {

            // Check if the file page is currently in main memory
            if ( true == m_readFile[ filePageIndex ].DefaultState() )
            {
                // The file is not in main memory

                // Check if the maximum number of file pages that should be in main memory has been reached
                if ( m_maximumNumberOfFilePagesInMainMemory == m_numberOfFilePagesInMainMemory )
                {
                    // The maximum number of file pages in main memory has been reached

                    // Remove the file page that was not used for the longest from main memory
                    m_readFile[ m_filePagesUseOrder.GetTheObjectThatWasNotUsedForTheLongestAndRemoveItFromTheUseOrderList() ].DeleteResourcesAndSetToDefaultState();

                    // Decrese the number of file pages in main memory by 1
                    m_numberOfFilePagesInMainMemory -= 1;
                }

                // Upload the required file to main memory and set it inside the matching array
                m_readFile[ filePageIndex ].SetNewBasicTypesFixedSizeArray( m_uploadFileToMainMemory.UploadPartOfTheFile( ( filePageIndex * m_pageFileSizeInBytes ), m_pageFileSizeInBytes ), m_pageFileSizeInTemplateType );

                // Increase the number of file pages in main memory by 1
                m_numberOfFilePagesInMainMemory += 1;            
            }

        }











    }  //  Namespace FileSystem

}  //  Namespace Universe



#endif  // READDATAFILE_H










