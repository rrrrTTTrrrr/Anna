#ifndef  DATAFILE_HPP
#define  DATAFILE_HPP


#include "../../../../../GeneralPurposeContainers/Array/Objects/ObjectsFixedSizeArray/ObjectsFixedSizeArray.hpp"  // Class ObjectsFixedSizeArray
#include "../../../../../GeneralPurposeContainers/Array/BasicTypes/BasicTypesFixedSizeArray/BasicTypesFixedSizeArray.hpp"  //  Class BasicTypesFixedSizeArray
#include "../../FileDriver/Read/Read.hpp"  //  Class Read
#include "../../FileDriver/Write/Write.hpp"  //  Class Write
#include "../../../../../GeneralPurposeContainers/UseOrder/UseOrderWithNoDuplications/BasicTypesUseOrderWithNoDuplications/BasicTypesUseOrderWithNoDuplications.hpp"  //  Class BasicTypesUseOrderWithNoDuplications



// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Exception/Exception.hpp"  //  Class Exception
#endif


// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part



namespace Universe
{

    namespace 
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
    	// not be used
    	// Template class Information :
    	//
    	//  Purpose :
    	//
    	//
    	//
   	    //  Description :
   	    //
  	    //      1. There is no exception specification on purpose. The reason is that when working with templates, the given type of the template
   	    //         can overload and override any operator and method, and therefore throw anything it see fit. This causes the problem, there is
  	    //         no way of knowing what the given type throws. The only method declared with exception specification is the destructor, which should
        //         not throw any exception anyhow, to prevent throwing an exception while another exception is active. This will cause the
    	//         program to end
        //      2. The template type size in bytes should be divided by 2 with no remainder 
        //      
        //
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename TYPE >
        class DataFile : public GeneralPurposeContainers::ObjectsFixedSizeArray< GeneralPurposeContainers::BasicTypesFixedSizeArray< TYPE > >
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
    		inline DataFile();


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
            //          fileAbsolutePath - the absolute path to the file including the file name itself
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
            explicit inline DataFile( const Encoding::UnicodeString& fileAbsolutePath );


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
    		inline DataFile( const DataFile< TYPE >& other );


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
    		DataFile< TYPE >& operator=( const DataFile< TYPE >& other );


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
    		inline DataFile( DataFile< TYPE >&& other );


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
    		DataFile< TYPE >& operator=( DataFile< TYPE >&& other );


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
    		virtual inline ~DataFile() throw();


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
    		virtual void SetToDefaultState();


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
    		virtual bool DefaultState() const;


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
    		virtual void DeleteResourcesAndSetToDefaultState();


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
    		// manipulated, or some functionality needed that does not involve the non static data members


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


            // In case files are smaller then the maximum allowed memory usage then, accessing the pages through
            // the actual index in the object fixed size array object is good enough. When the files are larger
            // files that should be in a higher index in order to correctly


            // This object will be used to communicate with the file system driver and read the required part of the file
            Read m_read;

            // This object will be used to communicate with the file system driver and write the required part to the file
            Write m_write;            

            // This object will store the use order of the file pages in main memory
            DesignPatterns::BasicTypesUseOrderWithNoDuplications< UnsignedInteger64bits > m_filePagesUseOrder;

            // This object will store the number of file pages currently in main memory
            UnsignedInteger64bits m_numberOfFilePagesInMainMemory;

            // To be able to deal with files of every size, only the required pages from the file will be uploaded to main memory ( RAM ).
            // To maintain this a lookup table is needed, it will have the number of entries equal to the number of file pages. Then when
            // a certain file page is required, the file page location or number will be used as an index to the lookup table, which will
            // contain the index to the location of the file page on main memory ( RAM ), and if the maximum value of an unsigned integer
            // with 64 bits is found the file page needs to be brought up from secondary memory ( DISK )
            GeneralPurposeContainers::BasicTypesArray< UnsignedInteger64bits > m_filePageNumberToFilePageIndexOnRAM;


            // The following data members will be used to configure the object :


            // This object will store the maximum allowed usage of main memory for the current instance in bytes ( currently 2MB )
            const UnsignedInteger64bits m_maximumMemoryAllowedInBytes = 2097152;

            // This object will store the file page size in bytes
            const UnsignedInteger64bits m_filePageSizeInBytes = 4096;


        	// Static data members do not belong to any instnace, it belongs to the class. Like every global variable
    		// it is created with the start of the program and only destroyed when the program ends. This means that
    		// each member method can use the static data members, but not functions outside the object's scope. It
    		// restricts the access to this object use only, but rather then that acts as global variable


    		// The following methods are private. This means that only public or protected methods can use them, in other
    		// words they not part of the interface, but rather help implement it :


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
    	template< typename TYPE >
    	inline DataFile< TYPE >::DataFile() :
        ObjectsFixedSizeArray(),
        m_read(),
        m_write(),
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
        //          fileAbsolutePath - the absolute path to the file including the file name itself
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
    	DataFile< TYPE >::DataFile( const Encoding::UnicodeString& fileAbsolutePath ) :
        ObjectsFixedSizeArray( ( m_maximumMemoryAllowedInBytes / m_filePageSizeInBytes ), BasicTypesFixedSizeArray< TYPE >( ( m_filePageSizeInBytes / sizeof( TYPE ) ), 0 ) ),
        m_read( fileAbsolutePath ),
        m_write( fileAbsolutePath ),
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
    	template< typename TYPE >
    	DataFile< TYPE >::DataFile( const DataFile& other ) :
        ObjectsFixedSizeArray( other ),
        m_read( other.m_read ),
        m_write( other.m_write ),
        m_filePagesUseOrder( other.m_filePagesUseOrder ),
        m_numberOfFilePagesInMainMemory( other.m_numberOfFilePagesInMainMemory )
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
    	template< typename TYPE >
    	DataFile< TYPE >& DataFile< TYPE >::operator=( const DataFile& other )
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

                // Call the base object assignment operator
                GeneralPurposeContainers::ObjectsFixedSizeArray< BasicTypesFixedSizeArray< TYPE > >::operator=( other );

                // Copy the read object
                m_read = other.m_read;

                // Copy the write object
                m_write = other.m_write;

                // Copy the file pages use order object
                m_filePagesUseOrder = other.m_filePagesUseOrder;

                // Copy the number pages currently in main memory
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
    	template< typename TYPE >
    	DataFile< TYPE >::DataFile( DataFile&& other ) :
        ObjectsFixedSizeArray( other ),
        m_read( other.m_read ),
        m_write( other.m_write ),
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
    	template< typename TYPE >
    	DataFile< TYPE >& DataFile< TYPE >::operator=( DataFile&& other )
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

                // Call the base object move assignment operator
                GeneralPurposeContainers::ObjectsFixedSizeArray< BasicTypesFixedSizeArray< TYPE > >::operator=( other );

                // Take the read object
                m_read = other.m_read;

                // Take the write object
                m_write = other.m_write;

                // Take the file pages use order object
                m_filePagesUseOrder = other.m_filePagesUseOrder;

                // Take the number pages currently in main memory
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
            // Call the base class set to default state method
            GeneralPurposeContainers::ObjectsFixedSizeArray< BasicTypesFixedSizeArray< TYPE > >::SetToDefaultState();

            // Set to default state the read object
            m_read.SetToDefaultState();

            // Set to default state the write object
            m_write.SetToDefaultState();

            // Set the file pages use order object
            m_filePagesUseOrder.SetToDefaultState();

            // Set the number of pages currently in main memory to 0
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
    	template< typename TYPE >
    	bool DataFile< TYPE >::DefaultState() const
    	{

    		// Check if the object is in default state
    		if ( ( GeneralPurposeContainers::ObjectsFixedSizeArray< BasicTypesFixedSizeArray< TYPE > >::DefaultState() == true ) &&
                 ( m_read.DefaultState() == true ) &&
                 ( m_write.DefaultState() == true ) &&
                 ( m_filePagesUseOrder.DefaultState() == true ) &&
                 ( m_numberOfFilePagesInMainMemory == 0 ) )
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

            // Call the base class set to default state method
            GeneralPurposeContainers::ObjectsFixedSizeArray< BasicTypesFixedSizeArray< TYPE > >::DeleteResourcesAndSetToDefaultState();

            // Set to default state the read object
            m_read.DeleteResourcesAndSetToDefaultState();

            // Set to default state the write object
            m_write.DeleteResourcesAndSetToDefaultState();

            // Set the file pages use order object
            m_filePagesUseOrder.DeleteResourcesAndSetToDefaultState();

            // Set the number of pages currently in main memory to 0
            m_numberOfFilePagesInMainMemory = 0;
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use to change the file
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          fileAbsolutePath - the absolute path to the file including the file name itself
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
        inline void ReadDataFile< T >::SetNewFile( const Encoding::UnicodeString& fileAbsolutePath )
        {
            // Set all the entries of the basic types fixed size array objects to 0
            SetAllEntriesToObject( GeneralPurposeContainers::BasicTypesFixedSizeArray< TYPE >( ( m_filePageSizeInBytes / sizeof( TYPE ) ), 0 ) );

            // Set the new file in the read object
            m_read.SetNewFile( fileAbsolutePath );

            // Set the new file in the write object
            m_write.SetNewFile( fileAbsolutePath );

            // Set the file pages use order object to default state
            m_filePagesUseOrder.DeleteResourcesAndSetToDefaultState();

            // Set the number of file pages in memory to 0;
            m_numberOfFilePagesInMainMemory = 0;
        }





























//  ***********************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   *******************************************






























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
            // The 2 instances will be considered equal, when they both point to the same file. And this
            // is what the equal opeartor in the read object does, so return the result
            return ( m_read == other.m_read );
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
            // The 2 instances will be considered equal, when they both point to the same file. And this
            // is what the equal opeartor in the read object does, so return the negotiated result
            return ( !( m_read == other.m_read ) );
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
        template< typename TYPE >
        inline TYPE DataFile< TYPE >::operator[]( UnsignedInteger64bits fileEntryIndex ) const
        {
            // Create an object to store the index of the array that should store the file page
            UnsignedInteger64bits arrayIndexOfFilePage = GetObjectsFixedSizeIndexIMP( fileEntryIndex );

            // Check if the file exist in main memory and if not upload it
            UploadFilePageIfNotInMainMemoryIMP( arrayIndexOfFilePage );

            // Return a copy of the required data in the file
            return ( m_readFile[ arrayIndexOfFilePage ][ GetTheIndexOfDataInsideTheArrayIMP( fileEntryIndex ) ] );
        }























//  ****************************************************   TEMPLATE OR INLINE STATIC FUNCTIONS IMPLEMENTATION   ***********************************************










//	*****************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************
























        // Method Information :
        //
        //  Description :
        //
        //      Use to calculate the index of the objects fixed size array, or in other words the index of the required
        //      basic types fixed size array object
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
        //      The index of the required basic types array object in the objects fixed size array object
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename T >
        inline UnsignedInteger64bits ReadDataFile< T >::GetObjectsFixedSizeIndexIMP( UnsignedInteger64bits fileEntryIndex ) const
        {
            // Return the index of the array the data is in
            return ( ( fileEntryIndex / m_filePageSizeInBytes ) );
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
            }


        )  //  End of debug tool











    }
    }  //  Namespace 

}  //  Namespace Universe



#endif  // DATAFILE_HPP