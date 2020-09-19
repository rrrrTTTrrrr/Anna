#ifndef  READTEXTFILE_H
#define  READTEXTFILE_H


#include "../../../../ErrorHandling/Exception.h"  //  Class Exception
#include "../../../../Definitions/VariableTypesDefinitions.h"  //  Typedef UnsignedInteger64bits, Typedef UnsignedInteger8bits
#include "../../../../Encoding/Unicode/UnicodeString/UnicodeString.h"  //  Class UnicodeString
#include "../../UploadFileToMainMemory/UploadFileToMainMemory.h"  //  Class UploadFileToMainMemory



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
        class ReadTextFile
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
        	explicit inline ReadTextFile() throw();


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
            explicit ReadTextFile( const Encoding::UnicodeString& fileNameIncludingFullPath ) throw( Exception );


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
        	explicit inline ReadTextFile( const ReadTextFile& other ) throw( Exception );


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
        	ReadTextFile& operator=( const ReadTextFile& other ) throw( Exception );


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
        	explicit inline ReadTextFile( ReadTextFile&& other ) throw( Exception );


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
        	ReadTextFile& operator=( ReadTextFile&& other ) throw( Exception );


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
        	inline ~ReadTextFile() throw();


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
            inline void SetToDefaultState() throw();


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
        	inline bool DefaultState() const throw();


            // Method Information :
            //
            //  Description :
            //
            //      Use to delete the object resources. Note - if the object is in default state the method do nothing
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
            inline void DeleteResources() throw();


            // The following methods are the interface of the object. This methods implement the
            // capabilities of the object :


            // The following methods declare the overloaded operators for the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the value inside a byte
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          arrayIndex - the index of the byte in the file
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The value inside the required byte
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2. The byte index is out of the file range - class Exception is thrown
            //      3.
            //
            inline Encoding::UnicodeCharacter operator[]( UnsignedInteger64bits unicodeCharacterIndex ) const;


    	private: 


            // This object will be used to upload the file into main memory
            UploadFileToMainMemory m_uploadFileToMainMemory;

            // This object will store the file encoding
            Encoding::EncodingType m_encoding;

            // This object will store the file in main memory
            Encoding::UnicodeString m_file;


    	};  //  Class ReadTextFile


















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
        //	    They will come
        //
        inline ReadTextFile::ReadTextFile() throw() :
        m_uploadFileToMainMemory(),
        m_encoding( Encoding::Unknown ),
        m_file()
        {}


    	// Method Information :
        //
        //  Description :
        //
        //   	Copy constructor,
        //
        //  Required arguments :
        //
        //   	User information needed :
        //
        //          other - a reference to the object that should be copied
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
        //        They will come
        //
        inline ReadTextFile::ReadTextFile( const ReadTextFile& other ) throw( Exception ) :
        m_uploadFileToMainMemory( other.m_uploadFileToMainMemory ),
        m_encoding( other.m_encoding ),
        m_file( other.m_file )
        {}


    	// Method Information :
        //
        //  Description :
        //
        //      Move constructor, take the resources from the other object ( rvalue reference ), and set it to
        //      the default state. Will operate correctly even if the other object is in default state
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
        //	    They will come
        //
        inline ReadTextFile::ReadTextFile( ReadTextFile&& other ) throw( Exception ) :
        m_uploadFileToMainMemory( other.m_uploadFileToMainMemory ),
        m_encoding( other.m_encoding ),
        m_file( other.m_file )
        {
            // Set the other object to default state, this way it can't be used
            other.SetToDefaultState();
        }


        // Method Information :
        //
        //  Description :
        //
        //        Destructor,
        //
        //  Required arguments :
        //
        //   	  User information needed :
        //
        //            NONE
        //
        //        Information returned to the user :
        //
        //            NONE
        //
        //  Return value :
        //
        //   	NONE
        //
    	//  Possible errors :
        //
        //	    They will come
        //
        inline ReadTextFile::~ReadTextFile() throw()
        {}


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
        inline void ReadTextFile::SetToDefaultState() throw()
        {
            // Set the upload file to memory object to default state
            m_uploadFileToMainMemory.SetToDefaultState();

            // Set the array object containing the file to default state
            m_file.SetToDefaultState();
        }


        // Method Information :
        //
        //  Description :
        //
        //		Use to check if the object is in default state
        //
        //  Required arguments :
        //
        //   	User information needed :
        //
        //           NONE
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
        //	    They will come
        //
        inline bool ReadTextFile::DefaultState() const throw()
        {

            // Check if the object is in default state
            if ( true == m_uploadFileToMainMemory.DefaultState() && 
                 Encoding::Unknown == m_encoding &&
                 true == m_file.DefaultState() )
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
        //      Use to delete the object resources. Note - if the object is in default state the method do nothing
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
        inline void ReadTextFile::DeleteResources() throw()
        {
            // Release the resources of this object

            // Delete the resources of the upload to memory object
            m_uploadFileToMainMemory.DeleteResources();

            // Delete the resources of the array containing the file
            m_file.DeleteResources();
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the value inside a byte
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          arrayIndex - the index of the byte in the file
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      The value inside the required byte
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2. The byte index is out of the file range - class Exception is thrown
        //      3.
        //
        inline Encoding::UnicodeCharacter ReadTextFile::operator[]( UnsignedInteger64bits unicodeCharacterIndex ) const
        {
            // Check that this object is not in default state
            ThrowExceptionIfExpressionIsTrue( DefaultState(), "ReadTextFile::operator[] failed - the object is in default state" );

            // Return a copy of the value in the byte
            return ( m_file[ unicodeCharacterIndex ] );
        }















//	*****************************************   PRIVATE METHODS IMPLEMENTATION   ******************************************  

















    // Method Information :
    //
    //  Description :
    //
    //      The main resource inside this object is shared among more then 1 instance. When a write operation 
    //      needs to take place, the number of instances using the resource must be checked. If only this instance
    //      uses the resource then there are no problems and the write operation can take place. If there is more 
    //      then one instance using the resource then, the resource must be copied first, to prevent changing it 
    //      also for other instances. Only then the write operation can take place. This method then should be used
    //      everytime before changes are made to the container
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
    //      1. There is no more free space - class std::bad_alloc is thrown
    //      2. 
    //
    inline void ::CopyOnWriteIMP() throw( std::bad_alloc )
    {
        // Check if only this instance uses the shared resource
        RETURN_IF_THE_VALUES_ARE_EQUAL( 1, .GetNumberOfReferencesToSharedResource() )

        // More then 1 instance uses the shared resource, Create a new copy of the resource

        

    }















// ******************************************   NESTED CLASS IMPLEMENTATION -    **************************************** 




















    }  //   Namespace FileSystem    

}  //   Namespace Universe

#endif  // READTEXTFILE_H









