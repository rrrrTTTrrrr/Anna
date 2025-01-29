#ifndef  USERDEFINEDPLATFORM_HPP
#define  USERDEFINEDPLATFORM_HPP


#include "../../../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef
#include "../../../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../Memory/Swap/Swap.hpp"  //  Class Swap
#include "../../../../Abilities/Proxy/UserDefinedProxy/UserDefinedProxy.hpp"  //  Class UserDefinedProxy


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


// When a function name ends with the suffix IMP, the function is not part of the object interface ( capabilities ), it only used as aid to the function that
// it is, implementing only spsecific part


namespace Universe
{

    namespace Memory
    {


    	// This is used when only declaring the object in this source file will be enough to pass compilation. The implementation is given to the compiler through the
    	// cpp source file that the object is nested within
    	//
    	// Forward declarations :
    	//
    	//  NONE
    	//


    	// Give proper treatment, by dealing with big and little endian encoding systems where it is required. The big or little endian encoding appear when dealing
    	// with byte order in memory. In the byte itself the bit the is closest to the address of the byte, is the high order bit
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
    	// Then in 1 byte this is always the case. But when dealing with more then 1 byte it is up to the system to decide whether the address of the first byte will
    	// contain the high order bits or the low order bits. For example for 2 bytes, store the value 1 in the 2 ways of endian encoding :
    	//
    	//    Big endian encoding :
    	//
    	//      First address of data type ->   00000000 00000001
    	//
    	//    Big endian encoding :
    	//
    	//      First address of data type ->   00000001 00000000


    	// To support move semantics every object must provide a default state. There are  how ever few exceptions, as objects that their members stay exactly the same along
    	// the run of the program, objects that don't have members at all, and objects with undefined state. This default state will be used to notify that the object should
    	// not be used


    	// Template Class Information :
    	//
    	//  Purpose :
    	//
    	//		This object will be used as an interface. Every object that deals with user defined data memory segments will be derived from this interface to ensure the 
        //      all the required functionality is implemented. The platform interface is made to ensure that every possible change the user will like to perform on the 
        //      platform will exist
    	//
    	//  Description :
    	//
    	//		1. Template arguments :
    	//
    	//			UserDefinedType - will be used to determine the type of the data the platform works on
    	//			KeyType - wil be used to determine the key used to access data
    	//
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename UserDefinedType, typename KeyType >
    	class UserDefinedPlatform
    	{
    	public:


            // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
            // generates a basic behavior for them :


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
    		inline UserDefinedPlatform() = default;


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
    		inline UserDefinedPlatform( const UserDefinedPlatform< UserDefinedType, KeyType >& other ) = default;


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Assignment operator, can handle with self assignment and instances in default state
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
    		inline UserDefinedPlatform< UserDefinedType, KeyType >& operator=( const UserDefinedPlatform< UserDefinedType, KeyType >& other ) = default;


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
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
    		inline UserDefinedPlatform( UserDefinedPlatform< UserDefinedType, KeyType >&& other ) = default;


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
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
    		inline UserDefinedPlatform< UserDefinedType, KeyType >& operator=( UserDefinedPlatform< UserDefinedType, KeyType >&& other ) = default;


    		// Method Information :
    		//
    		//  Description :
    		//
    		//   	Destructor, does not throw
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
    		inline ~UserDefinedPlatform() = default;


    		// The following methods are the interface of the object. This methods implement the capabilities of the object :


	    	// This part of the interface focus on the setting and accesing of the various entries :


            // Method Information :
            //
            //  Description :
            //
            //      Use to get access to the required data
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          key - this will used to determine the required entry
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The basic types platfrom proxy class
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. The entry index is out of the basic types platfrom range
            //      3.
            //
            inline typename Abilities::UserDefinedProxy< UserDefinedPlatform< UserDefinedType, KeyType >, KeyType, UserDefinedType > operator[]( const KeyType& key );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get a copy of the required entry
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          key - this will used to determine the required entry
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The array proxy class
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. The entry index is out of the basic types platfrom range
            //      3.
            //
            inline const UserDefinedType& operator[]( const KeyType& key ) const;


	    	// This part of the interface focus on dealing with changes, the various possibilites are adding and removing entries from the platform :


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to add an other basic types platform before the given one
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//          1. key - this will used to determine the required entry
	    	//			2. other - a reference to an other to be added before the given entry
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
	    	//
	    	//  Return value :
	    	//
    		//		NONE
	    	//
	    	//  Possible errors :
	    	//
	    	//      1. The given pointer is NULL
	    	//      2. 
	    	//
	    	virtual inline bool AddBefore( const KeyType& key, const UserDefinedPlatform< UserDefinedType, KeyType >& other ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to add an entry before the given one
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//          1. key - this will used to determine the required entry
	    	//			2. instance - a reference to an instance that needs to be put before
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
	    	//
	    	//  Return value :
	    	//
    		//		NONE
	    	//
	    	//  Possible errors :
	    	//
	    	//      1. The given pointer is NULL
	    	//      2. 
	    	//
	    	virtual inline bool AddBefore( const KeyType& key, const UserDefinedType& instance ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to add a other UserDefinedplatform after the given one
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//          1. key - this will used to determine the required entry
	    	//			2. other - a reference to an other to be added after the given entry
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
	    	//
	    	//  Return value :
	    	//
    		//		NONE
	    	//
	    	//  Possible errors :
	    	//
	    	//      1. The given pointer is NULL
	    	//      2. 
	    	//
	    	virtual inline bool AddAfter( const KeyType& key, const UserDefinedPlatform< UserDefinedType, KeyType >& other ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to add an entry after the given one
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//          1. key - this will used to determine the required entry
	    	//			2. instance - a reference to an instance that needs to be put before
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
	    	//
	    	//  Return value :
	    	//
    		//		NONE
	    	//
	    	//  Possible errors :
	    	//
	    	//      1. The given pointer is NULL
	    	//      2. 
	    	//
	    	virtual inline bool AddAfter( const KeyType& key, const UserDefinedType& instance ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to remove an entry
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//          key - this will used to determine the required entry
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
	    	//
	    	//  Return value :
	    	//
    		//		NONE
	    	//
	    	//  Possible errors :
	    	//
	    	//      1. The given pointer is NULL
	    	//      2. 
	    	//
	    	virtual inline bool Remove( const KeyType& key ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to remove an entry before the given one
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//          key - this will used to determine the required entry
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
	    	//
	    	//  Return value :
	    	//
    		//		NONE
	    	//
	    	//  Possible errors :
	    	//
	    	//      1. The given pointer is NULL
	    	//      2. 
	    	//
	    	virtual inline bool RemoveBefore( const KeyType& key ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to remove a number of entries before the given one
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//          1. key - this will used to determine the required entry
	    	//			2. size- the number of entries before that needs to be moved
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
	    	//
	    	//  Return value :
	    	//
    		//		NONE
	    	//
	    	//  Possible errors :
	    	//
	    	//      1. The given pointer is NULL
	    	//      2. 
	    	//
	    	virtual inline bool RemoveBefore( const KeyType& key, UnsignedInteger64bits size ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to remove an entry after the given one
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//          key - this will used to determine the required entry
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
	    	//
	    	//  Return value :
	    	//
    		//		NONE
	    	//
	    	//  Possible errors :
	    	//
	    	//      1. The given pointer is NULL
	    	//      2. 
	    	//
	    	virtual inline bool RemoveAfter( const KeyType& key ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to remove a number of entries after the given one
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//          1. key - this will used to determine the required entry
	    	//			2. size- the number of entries after that needs to be moved
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
	    	//
	    	//  Return value :
	    	//
    		//		NONE
	    	//
	    	//  Possible errors :
	    	//
	    	//      1. The given pointer is NULL
	    	//      2. 
	    	//
	    	virtual inline bool RemoveAfter( const KeyType& key, UnsignedInteger64bits size ) = 0;


    	};  //  Class UserDefinedPlatform














    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // USERDEFINEDPLATFORM_HPP