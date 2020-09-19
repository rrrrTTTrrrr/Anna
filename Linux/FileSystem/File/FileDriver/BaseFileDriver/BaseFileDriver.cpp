#ifndef  BASEFILEDRIVER_CPP
#define  BASEFILEDRIVER_CPP



#include "BASEFILEDRIVER.hpp"




// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe 
{

    namespace FileSystem
    {


    	// Forward declarations :
    	//
    	//  NONE
    	//





//	********************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ****************************************************






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
    	BaseFileDriver& BaseFileDriver::operator=( const BaseFileDriver& other ) throw( Exception )
    	{

        	// Check that this is not self assignment
        	if ( this != &other )
        	{
            	// This is not self assignment

            	// Release all the resources of this object and set the default state
            	DeleteResourcesAndSetToDefaultState();

            	// Check if the other object is in default state
            	if ( true == other.DefaultState() )
            	{
                	// The other object is in default state

                	// Nothing else needs to be done, return a reference to this object
                	return ( *this );
            	}

            	// Copy the other object resources

                // Set the UTF-8 string string the file name and path to default state
                m_fileAbsolutePath = other.m_fileAbsolutePath;

                // Open the file
                OpenFileIMP();

                // Get the file size
                m_fileSize = other.m_fileSize;
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
    	BaseFileDriver& BaseFileDriver::operator=( BaseFileDriver&& other ) throw( Exception )
    	{

        	// Check that this is not self assignment
        	if ( this != &other )
        	{
            	// This is not self assignment

            	// Release all the resources of this object and set the default state
            	DeleteResourcesAndSetToDefaultState();

            	// Check if the other object is in default state
            	if ( true == other.DefaultState() )
            	{
                	// The other object is in default state

                	// Nothing else needs to be done, return a reference to this object
                	return ( *this );
            	}

            	// Take the other object resources

                // Take the UTF-8 string string the file name and path to default state
                m_fileAbsolutePath = other.m_fileAbsolutePath;

                // Take the file descriptor
                m_fileDescriptor = other.m_fileDescriptor;

                // Take the file size
                m_fileSize = other.m_fileSize;

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
        //      Use to change the file the object is working on
        //
        //  Required arguments :
        //
        //      User information needed :
        //
    	//          1. fileAbsolutePath - the absoulte path to the file
    	//			2. requiredOperation - the type of operation, it can be to read from file or write to the file
    	//			3. permissions - the file will be opened with the given permissions, it can be read, write and execute
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
        //      1. The file does not exist
        //      2.
        //
        void BaseFileDriver::SetNewFile( const Encoding::UnicodeString& fileAbsolutePath, SignedInteger32bits requiredOperation, SignedInteger32bits permissions ) throw( std::bad_alloc, Exception, ErrnoException )
        {
            // Delete the current resources of the object and set it to default state
            DeleteResourcesAndSetToDefaultState();

            // Set the new file into the unicode string object
            m_fileAbsolutePath = fileAbsolutePath;

            // Try to open the file
            OpenFileIMP( requiredOperation, permissions );

            // Get the file size in bytes
            SetFileSizeInBytesIMP();
        }
























//  ***************************************************************************   OPERATORS IMPLEMENTATION   ********************************************************************











//  ************************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ****************************************************************











//	*************************************************************************   PRIVATE METHODS IMPLEMENTATION   ****************************************************************








// **************************************************************   NESTED CLASS PRIVATE METHODS IMPLEMENTATION -    ************************************************************











// *************************************************************************   FRIEND FUNCTIONS IMPLEMENTATION   ****************************************************************












    	// This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
    	// within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
    	// to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
    	// this functions are needed to avoid just that








// **************************************************************************************   TESTING   ***************************************************************************






















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
    		void BaseFileDriver::Test() throw( std::bad_alloc, Exception )
    		{
    		}


    	)  //  End of debug tool











    }  //  Namespace FileSystem


}  //  Namespace Universe

#endif  //  BASEFILEDRIVER_CPP





