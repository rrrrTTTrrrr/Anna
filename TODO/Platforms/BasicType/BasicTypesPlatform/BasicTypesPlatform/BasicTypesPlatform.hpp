#ifndef  BASICTYPESPLATFORM_HPP
#define  BASICTYPESPLATFORM_HPP


#include "../../../../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef
#include "../../../../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../Memory/MemoryOperations/Swap/Swap.hpp"  //  Class Swap
#include "../../../../../Abilities/Proxy/BasicTypesProxy/BasicTypesProxy.hpp"  //  Class BasicTypesProxy


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
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
    	//		This object will be used as an interface. Every object that deals with basic types memory segments will be derived from this interface to ensure the all the 
    	//		required functionality is implemented. The platform interface is made to ensure that every possible change the user will like to perform on the platform
    	//		will exist
    	//
    	//  Description :
    	//
    	//		1. Template arguments :
    	//
    	//			BasicType - will be used to determine the type of the data the platform works on
    	//			KeyType - wil be used to determine the key used to access data
    	//
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename DerivedObjectType, typename KeyType, typename BasicType >
    	class BasicTypesPlatform
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
    		inline BasicTypesPlatform();


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
            //          size - the size of the platform
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
            explicit inline BasicTypesPlatform( UnsignedInteger64bits size );


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
    		inline BasicTypesPlatform( const BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >& other );


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
    		inline BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >& operator=( const BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >& other );


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
    		inline BasicTypesPlatform( BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >&& other );


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
    		inline BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >& operator=( BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >&& other );


            // Method Information :
            //
            //  Description :
            //
            //      This method is used to swap the content between this instance and the other one
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          other - a reference to the object that should be swaped
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
            inline void Swap( BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >& other );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to take an instance in default state and prepare it for work. It can also be uses to reinitialize the instance
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          size - the size of the platform
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
            //      1. The object 
            //      2. 
            //
            virtual inline void Initiate( UnsignedInteger64bits size );


            // Method Information :
            //
            //  Description :
            //
            //      Use to set the object into his default state. It does not delete the resources, if the method is used all the information inside will be lost and
            //      a memory leak will occuer
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
            virtual inline void SetToDefaultState();


            // Method Information :
            //
            //  Description :
            //
            //      Use to check if the object is in default state
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
            //      1. true, if instance is at default state
            //      2. false, if instance is not at default state
            //
            //  Possible errors :
            //
            //      They will come
            //
            virtual inline bool DefaultState() const;


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
    		virtual inline ~BasicTypesPlatform() = default;


    		// INTERFACE :


            // This part of the interface focus on accessing the metadata of the platform :


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the size of the platorm
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
            //      The size of the platorm
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2.
            //
            inline UnsignedInteger64bits Size() const;


	    	// This part of the interface focus on the setting and accesing of the various entries using index, and finding the required index for values :


            // Method Information :
            //
            //  Description :
            //
            //      Use to get access to the required data associated with the key
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
            //      2. The key does not exist in the platform
            //      3.
            //
            virtual inline typename Abilities::BasicTypesProxy< BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >, KeyType, BasicType > operator[]( const KeyType& key ) = 0;


            // Method Information :
            //
            //  Description :
            //
            //      Use to get access to the required data associated with the key for constant instances
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
            //      A copy of the data associated with the key
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. The key does not exist in the platform
            //      3.
            //
            virtual inline BasicType operator[]( const KeyType& key ) const = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to find the key of the required basic type value
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//			value - the value that needs to be located
	    	//
	    	//      Information returned to the user :
	    	//
	    	//          NONE
	    	//
	    	//  Return value :
            //
            //      1. A copy of the key associated with value, if the value exist
            //		2. If the value does not exist, each derived object shall decide how to notify that the value does not exist
	    	//
	    	//  Possible errors :
	    	//
	    	//      1. The instance is in default state
	    	//      2. 
	    	//
	    	virtual inline KeyType FindKey( BasicType value ) const = 0;


	    	// This part of the interface focus on dealing with changes, the various possibilites are adding and removing entries from the platform :


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to add an other instance before the entry associated with the key
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
	    	virtual inline void AddBefore( const KeyType& key, const DerivedObjectType& other ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to add a value before the entry associated with the key
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//          1. key - this will used to determine the required entry
	    	//			2. value - the value that needs to be added before
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
	    	virtual inline void AddBefore( const KeyType& key, BasicType value ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to add an other instance after the entry associated with the key
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
	    	virtual inline void AddAfter( const KeyType& key, const DerivedObjectType& other ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
            //      Use this method to add a value before the entry associated with the key
	    	//
	    	//  Required arguments :
	    	//
	    	//      User information needed :
	    	//
	    	//          1. key - this will used to determine the required entry
	    	//			2. value - the value that needs to be added after
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
	    	virtual inline void AddAfter( const KeyType& key, BasicType value ) = 0;


	    	// Method Information :
	    	//
	    	//  Description :
	    	//
	    	//      Use this method to remove all the entries starting from the one associated with the key
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
	    	virtual inline void Remove( const KeyType& key, UnsignedInteger64bits size ) = 0;


        protected:


            // The protected part is used for inheritance. This means that only this object and the objects that will inherit from it can use the protected data
            // members or methods

            // This object will store the platform size
            UnsignedInteger64bits m_size;


        private:


            // Allow the arithmetic proxy object, to access protected and private sections of this object
            friend class Abilities::BasicTypesProxy< BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >, KeyType, BasicType >;


            // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
            // rather help implement it :


            // This part of focus on the methods required by each platform to allow the proxy 2 things. The first is access to the data, for constant and non constant 
            // instances. The second is the required operation the proxy needs to execute before the instance can change :


            // Method Information :
            //
            //  Description :
            //
            //      This method will be used for non constant objects
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
            //      A reference to the data
            //
            //  Possible errors :
            //
            //      They will come
            //
            virtual inline BasicType& GetData_IMP( const KeyType& key ) = 0;


            // Method Information :
            //
            //  Description :
            //
            //      This method will be used for non constant objects
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
            //      A reference to the data
            //
            //  Possible errors :
            //
            //      They will come
            //
            virtual inline BasicType GetData_IMP( const KeyType& key ) const = 0;


            // Method Information :
            //
            //  Description :
            //
            //      This method can be used when the default behavior for operators that change the state of the object is not good enough. It is very important for object 
            //      with shared main resource inside. When a write operation needs to take place, the number of instances using the resource must be checked. If only one
            //      instance uses the resource then there are no problems and the write operation can take place. If there is more then one instance using the resource then, 
            //      the resource must be copied first, to prevent changing it also for other instances. Only then the write operation can take place. This method then should 
            //      be used everytime before changes are made to the inherting object
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
            virtual inline void ExecuteTaskBeforeObjectChanges_IMP() = 0;


    	};  //  Class BasicTypesPlatform














































//  *******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************









































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
        template< typename DerivedObjectType, typename KeyType, typename BasicType >
        inline BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >::BasicTypesPlatform() :
        m_size( 0 )
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
        //          size - the size of the platform
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
        template< typename DerivedObjectType, typename KeyType, typename BasicType >
        inline BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >::BasicTypesPlatform( UnsignedInteger64bits size ) :
        m_size( size )
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Copy constructor, will operate correctly even if the other object is in default state
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
        //      A reference to the new copy is returned
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename DerivedObjectType, typename KeyType, typename BasicType >
        inline BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >::BasicTypesPlatform( const BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >& other ) :
        m_size( other.m_size )
        {}


        // Method Information :
        //
        //  Description :
        //
        //      Assignment operator, can handle with self assignment and instances in default state
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
        //      They will come
        //
        template< typename DerivedObjectType, typename KeyType, typename BasicType >
        inline BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >& BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >::operator=( const BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >& other )
        {
            // Create a copy of the other instance
            BasicTypesPlatform< DerivedObjectType, KeyType, BasicType > temporary( other );

            // Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
            Swap( temporary );

            // Return a reference to this object
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Move constructor, takes the resources from the other instance, and set it to default state. Can handle with self assignment and instances in default state
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
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename DerivedObjectType, typename KeyType, typename BasicType >
        inline BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >::BasicTypesPlatform( BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >&& other ) :
        BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >()
        {
            // Swap between this instance, which is in default state, and the other one
            Swap( other );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Move Assignment operator, delete the current resources of the instance, takes the resources from the other instance and set it to default state
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
        template< typename DerivedObjectType, typename KeyType, typename BasicType >
        inline BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >& BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >::operator=( BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >&& other )
        {
            // Create a default constructed instance
            BasicTypesPlatform< DerivedObjectType, KeyType, BasicType > defaultConstructedInstance;

            // Swap between the default constructed instance, which is in default state, and the other instance
            defaultConstructedInstance.Swap( other );

            // Swap between this instance and the default constructed instance one
            Swap( defaultConstructedInstance );

            // Return a reference to this object
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      This method is used to swap the content between this instance and the other one
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          other - a reference to the object that should be swaped
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
        template< typename DerivedObjectType, typename KeyType, typename BasicType >
        inline void BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >::Swap( BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >& other )
        {
            // Swap the size
            Memory::Swap< UnsignedInteger64bits >( m_size, other.m_size );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to take an instance in default state and prepare it for work. It can also be uses to reinitialize the instance
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          size - the size of the platform
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
        //      1. The object 
        //      2. 
        //
        template< typename DerivedObjectType, typename KeyType, typename BasicType >
        inline void BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >::Initiate( UnsignedInteger64bits size )
        {
            // Create a temporary instance
            BasicTypesPlatform< DerivedObjectType, KeyType, BasicType > temporary( size );

            // Swap between this instance and the temporary
            Swap( temporary );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to set the object into his default state. It does not delete the resources, if the method is used all the information inside will be lost and
        //      a memory leak will occuer
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
        template< typename DerivedObjectType, typename KeyType, typename BasicType >
        inline void BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >::SetToDefaultState()
        {
            // Set the size to 0
            m_size = 0;
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to check if the object is in default state
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
        //      1. true, if instance is at default state
        //      2. false, if instance is not at default state
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename DerivedObjectType, typename KeyType, typename BasicType >
        inline bool BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >::DefaultState() const
        {

            // Check if the object is not in default state
            if ( m_size == 0 )
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
        //      Use to get the size of the platorm
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
        //      The size of the platorm
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2.
        //
        template< typename DerivedObjectType, typename KeyType, typename BasicType >
        inline UnsignedInteger64bits BasicTypesPlatform< DerivedObjectType, KeyType, BasicType >::Size() const
        {
            // Return the size of the platform
            return ( m_size );
        }













    }  //  Namespace Memory

}  //  Namespace Universe



#endif  // BASICTYPESPLATFORM_HPP