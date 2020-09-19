#ifndef  READTEXTFILE_CPP
#define  READTEXTFILE_CPP



#include "ReadTextFile.h"




namespace Universe 
{

    namespace FileSystem
    {



        // Forward declarations :
        //
        //  NONE
        //













    //	************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ************************************













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
        ReadTextFile::ReadTextFile( const Encoding::UnicodeString& fileNameIncludingFullPath ) throw( Exception ) :
        m_uploadFileToMainMemory( fileNameIncludingFullPath ),
        m_encoding( Encoding::Unknown ),
        m_file()
        {
            // Create an object to store the address of the file in maim memory
            SmartPointers::ExceptionSafePointer< UnsignedInteger8bits > addressOfFileInMainMemory( m_uploadFileToMainMemory.UploadTheEntireFile(), SmartPointers::ARRAY_OF_OBJECTS );

            // Try to get the encoding of the file
            m_encoding = GetEncoding().WhatIsTheEncodingOfTheText( addressOfFileInMainMemory.GetResource(), numberOfBytesInFile );

            // Check if the encoding of the file was resolved, if not throw an exception
            ThrowExceptionIfExpressionIsTrue( ( SmartPointers::Unknown == m_encoding ), "ReadTextFile::Constructor failed - the encoding of the file could not been resolved" );

            // Store the file inside the unicode string
            m_file.SetNewResource( addressOfFileInMainMemory.GetResource(), numberOfBytesInFile, m_encoding );
        }


        // Method Information :
        //
        //  Description :
        //
        //   	Assignment operator, can handle with self assignment. Will operate correctly even if the other object is in default state
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
        //   	A reference to this object 
        //
    	//  Possible errors :
        //
        //	  They will come
        //
        ReadTextFile& ReadTextFile::operator=( const ReadTextFile& other ) throw( Exception )
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
                    DeleteResources();

                    //Set this object to default state
                    SetToDefaultState();

                    // Nothing else needs to be done, return a reference to this object
                    return ( *this );
                }

                // Copy the other object resources

                // Copy the upload file to main memory object
                m_uploadFileToMainMemory = other.m_uploadFileToMainMemory;

                // Copy the encoding
                m_encoding = other.m_encoding;

                // Copy the unicode string object
                m_file = other.m_file;
            }

            // Return a reference to this object
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //   	Move Assignment operator, can handle with self assignment. Takes the resources from the
        //      other object ( rvalue reference ), and set it to the default state. Will operate correctly
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
        //      They will come
        //
        ReadTextFile& ReadTextFile::operator=( ReadTextFile&& other ) throw( Exception )
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
                    DeleteResources();

                    //Set this object to default state
                    SetToDefaultState();

                    // Nothing else needs to be done, return a reference to this object
                    return ( *this );
                }

                // Take the other object resources

                // Take the upload file to main memory object
                m_uploadFileToMainMemory = other.m_uploadFileToMainMemory;

                // Take the encoding
                m_encoding = other.m_encoding;

                // Take the unicode string object
                m_file = other.m_file;

                // Set the other object to default state
                other.SetToDefaultState();
            }

            // Return a reference to this object
            return ( *this );
        }















//	*****************************************   PRIVATE METHODS IMPLEMENTATION   ******************************************
















    }  //  Namespace FileSystem

}  //  Namespace Universe

#endif  //  READTEXTFILE_CPP





