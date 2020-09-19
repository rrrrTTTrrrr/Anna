#ifndef  READWRITETEXTFILE_CPP
#define  READWRITETEXTFILE_CPP



#include "ReadWriteTextFile.h"




namespace Universe 
{

    namespace
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
    	ReadWriteTextFile& ReadWriteTextFile::operator=( const ReadWriteTextFile& other ) throw( Exception )
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
    	ReadWriteTextFile& ReadWriteTextFile::operator=( ReadWriteTextFile&& other ) throw( Exception )
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

            	// Set the other object to default state
            	other.SetToDefaultState();
        	}

        	// Return a reference to this object
        	return ( *this );
    	}











//  ****************************************************************   OPERATORS IMPLEMENTATION   *************************************************************************










//	**************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************








// *********************************************   NESTED CLASS PRIVATE METHODS IMPLEMENTATION -  ReadWriteTextFileProxy  *******************************************











// **************************************************************   FRIEND FUNCTIONS IMPLEMENTATION   *********************************************************************












    	// This functions are declared outside the class scope, to enable the class to be the right side operand. This can not be for a method
    // within the class. When a method or operator of a class is used, the object the operator or method belongs to must be known, in order
    // to set the implicit this pointer to the method. Therefore the class must be presented first which means to be the left side operand,
    // this functions are needed to avoid just that








    }  //  Namespace


}  //  Namespace Universe

#endif  //  READWRITETEXTFILE_CPP





