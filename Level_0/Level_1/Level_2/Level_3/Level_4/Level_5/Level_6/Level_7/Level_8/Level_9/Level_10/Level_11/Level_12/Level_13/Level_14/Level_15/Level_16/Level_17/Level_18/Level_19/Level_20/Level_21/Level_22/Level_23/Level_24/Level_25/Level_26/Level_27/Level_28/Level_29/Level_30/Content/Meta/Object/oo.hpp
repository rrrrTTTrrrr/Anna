#ifndef  OBJECTMETADATA_HPP
#define  OBJECTMETADATA_HPP


#include "../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef UnsignedInteger64bits
#include "../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../Memory/MemoryOperations/Swap/Swap.hpp"  //  Class Swap
#include "./ID/ID.hpp"  //  Class ID


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


namespace Universe
{

    namespace Metadata
    {


        // This enumeration purpose is to describe the type of data the object deals with. Currently in the system there are 3 types :
        enum class DataType
        {

            Unknown = 0,                // To support move semantics
            Basic = 1,                  // These data type can be bit copied
            UserDefined = 2,            // These data types must call a special method to be copied
            Bits = 3                    // These data type can be bit copied

        };



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
    	//
    	//
   	    //  Description :
   	    //
  	    //      1. There is no exception specification on purpose. The reason is that when working with templates, the given type of the template can overload and override any
    	//		   operator and method, and therefore throw anything it see fit. This causes the problem, there is no way of knowing what the given type throws. The only method
    	//		   declared with exception specification is the destructor, which should not throw any exception anyhow, to prevent throwing an exception while another exception
    	//		   is active. This will cause the program to end
    	//
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename ObjectType >
    	class ObjectMetadata
    	{
    	public:


            // The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared the compiler
            // generates a basic behavior for them :


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
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ObjectMetadata();


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
            //          dataType - the enumeration represnting the data type the object deals with
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Exceptions :
            //
            //      1. The data type enumeration is not unknown
            //      2. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            ObjectMetadata( DataType dataType );


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
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ObjectMetadata( const ObjectMetadata< ObjectType >& other );


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
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ObjectMetadata< ObjectType >& operator=( const ObjectMetadata< ObjectType >& other );


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
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ObjectMetadata( ObjectMetadata< ObjectType >&& other );


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
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ObjectMetadata< ObjectType >& operator=( ObjectMetadata< ObjectType >&& other );


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
            inline void Swap( ObjectMetadata< ObjectType >& other );


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to set a new memory segment to point too
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          dataType - the enumeration represnting the data type the object deals with
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      NONE
            //
            //  Exceptions :
            //
            //      1. The data type enumeration is not unknown
            //      2. 
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline void Initiate( DataType dataType );


            // Method Information :
            //
            //  Description :
            //
            //      Destructor, does not throw
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
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline ~ObjectMetadata();


    		// To support Move semantics, the following 3 methods are added to every object. One method to set the object into the default state, another to check if the
    		// object is in the default state, and the last method to delete all the object resources and set the object to default state :


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
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline void SetToDefaultState();


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
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      They will come
            //
            inline bool DefaultState() const;


            // Method Information :
            //
            //  Description :
            //
            //      Use to delete the instance resources and set it to default state
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
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. Deleting the object resources failed
            //      2.
            //
            inline void DeleteResourcesAndSetToDefaultState();


    		// The following methods are the interface of the object. This methods implement the capabilities of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use this method to get the object ID 
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
            //      The object ID
            //
            //  Exceptions :
            //
            //      NONE
            //
            //  Possible errors :
            //
            //      1. Deleting the object resources failed
            //      2.
            //
            inline UnsignedInteger64bits ID() const;


    		// The following methods declare the overloaded operators for the object :


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this operator to check if the this instance match the other
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
            //  Expectations :
            //
            //      NONE
            //
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		bool operator==( const ObjectMetadata< ObjectType >& other ) const;


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use this operator to check if the this instance does not match the other
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
            //  Expectations :
            //
            //      NONE
            //
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline bool operator!=( const ObjectMetadata< ObjectType >& other ) const;


    		// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the class. Satic functions only have
    		// access to static data members, which means all other data members can not be used. The only purpose then of declaring a static function is when a private
    		// static data member needs to be manipulated, or some functionality needed that does not involve the non static data members


    		DEBUG_TOOL(

    			// This part of the class is dedicated for testing :


    			// Method Information :
    			//
    			//  Description :
    			//
    			//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
    			//		the functionality
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
    			static void Test();

    		)  //  End of debug tool


    	private:


            // GENERAL INFORMATION :


            // This object will store if the object is copyable
            Boolean m_isTheObjectCopyable;

            // This object will store if the object is movable
            Boolean m_isTheObjectMoveable;

            // This object will store if the object is a singleton. Singleton means that there should be only 1 instance existing in the program
            Boolean m_isTheObjectSingleton;


            // DATA INFORMATION :


            // This object will store data type that the object deals with
            DataType m_dataType;

            // This object will store if the object deals with more then instance of data, which would make it a container
            Boolean m_isTheObjectContainer;

            // This object will store if the object deals with only 1 instance of data
            Boolean m_isTheObjectHasOnlyOneInstanceOfData;

            // This object will store if the object has at least one pure virtual method which means it is an interface, it can not be instanted by it's own, another
            // object must derive from it and implement the additional functionality required
            Boolean m_interface;


            // INHERITANCE INFORMATION :


            // This object will store if the object can be used as a base for other objects
            Boolean m_isThisObjectCanServeAsBaseForOtherObjects;

            // This object will store if the object derived from base objects
            UnsignedInteger64bits m_isThereBaseObjects;

            // This object will store the number of base objects the object drives from
            UnsignedInteger64bits m_numberOfBaseObjects;

            // This object will store if the object has at least one pure virtual method which means it is an interface, it can not be instanted by it's own, another
            // object must derive from it and implement the additional functionality required
            Boolean m_isThereAtLeastOnePureVirtualMethod;

            // This object will store the number of pure virtual methods the object has
            UnsignedInteger64bits m_numberOfPureVirtualMethods;


            // TEMPLATE INFORMATION :


            // This object will store if the object is templated
            Boolean m_isTheObjectTemplated;

            // This object will store the number of template arguments the object needs
            UnsignedInteger64bits m_numberOfTemplateArguments;


            // METHODS INFORMATION :


            // This object will store the number of methods the objects has
            UnsignedInteger64bits m_numberOfMethods;

            // This object will store the number of methods that does not change the object state ( or in others, constant )
            UnsignedInteger64bits m_numberOfMethodsThatDoesNotChangeTheStateOfTheObject;

            // This object will store the number of virtual methods the object has
            UnsignedInteger64bits m_numberOfVirtualMethods;


            // Public methods :


            // This object will store if the object has public methods
            Boolean m_areThereAnyPublicMethods;

            // This object will store the number of public methods the object has
            UnsignedInteger64bits m_numberOfPublicMethods;

            // This object will store the number of public methods that does not change the object state ( or in others, constant )
            UnsignedInteger64bits m_numberOfPublicMethodsThatDoesNotChangeTheStateOfTheObject;

            // This object will store the number of public virtual methods the object has
            UnsignedInteger64bits m_numberOfPublicVirtualMethods;

            // This object will store the number of methods that each object should have, like constructor and destructor, these will be considered as core methods
            UnsignedInteger64bits m_numberOfCoreMethods;

            // This object will store the number of constructors the object has
            UnsignedInteger64bits m_numberOfConstructors;

            // This object will store if the object has a default constructor
            Boolean m_isThereDefaultConstructor;

            // This object will store if the object has a copy constructor
            Boolean m_isThereCopyConstructor;

            // This object will store if the object has a assignment operator
            Boolean m_isThereAssignmentOperator;

            // This object will store if the object has a move constructor
            Boolean m_isThereMoveConstructor;

            // This object will store if the object has a move assignment operator
            Boolean m_isThereMoveAssignmentOperator;

            // This object will store if the object has a swap method
            Boolean m_isThereSwap;

            // This object will store if the object has at least one initiate method
            Boolean m_isThereInitiate;

            // This object will store the number of initiate methods the object has
            UnsignedInteger64bits m_numberOfInitiateMethods;

            // This object will store if the object has a method to set to object to default state
            Boolean m_isThereMethodToSetTheObjectToDefaultState;

            // This object will store if the object has a method to check if the object is in default state
            Boolean m_isThereMethodToCheckIfTheObjectIsInDefaultState;

            // This object will store if the object has a method to delete the resources and set to default state
            Boolean m_isThereMethodToDeleteTheResourcesAndSetToDefaultState;

            // This object will store the number of public methods that are the interface of the object, the method that the user will use on a prepared instance
            UnsignedInteger64bits m_numberOfInterfaceMethods;

            // This object will store the number of public operators the object has
            UnsignedInteger64bits m_numberOfPublicOperators;

            // This object will store the number of public static methods the object has
            UnsignedInteger64bits m_numberOfPublicStaticMethods;

            // This object will store if the object has a test method
            Boolean m_isThereMethodToTestTheObject;


            // Protected methods :


            // This object will store if the object has protected methods
            Boolean m_areThereAnyProtectedMethods;

            // This object will store the number of protected methods the object has
            UnsignedInteger64bits m_numberOfProtectedMethods; 

            // This object will store the number of protected methods that does not change the object state ( or in others, constant )
            UnsignedInteger64bits m_numberOfProtectedMethodsThatDoesNotChangeTheStateOfTheObject;

            // This object will store the number of protected virtual methods the object has
            UnsignedInteger64bits m_numberOfProtectedVirtualMethods;         
            
            // This object will store the number of protected operators the object has
            UnsignedInteger64bits m_numberOfProtectedOperators;

            // This object will store the number of protected static methods the object has
            UnsignedInteger64bits m_numberOfProtectedStaticMethods;


            // Private methods :


            // This object will store if the object has private methods
            Boolean m_areThereAnyPrivateMethods;

            // This object will store the number of private methods the object has
            UnsignedInteger64bits m_numberOfPrivateMethods;  

            // This object will store the number of private methods that does not change the object state ( or in others, constant )
            UnsignedInteger64bits m_numberOfPrivateMethodsThatDoesNotChangeTheStateOfTheObject;

            // This object will store the number of private virtual methods the object has
            UnsignedInteger64bits m_numberOfPrivateVirtualMethods;

            // This object will store the number of regular private methods
            UnsignedInteger64bits m_numberOfRegularPrivateMethods;

            // This object will store the number of private operators the object has
            UnsignedInteger64bits m_numberOfPrivateOperators;

            // This object will store the number of private static methods the object has
            UnsignedInteger64bits m_numberOfPrivateStaticMethods;          

            // This object will store the number of private friend functions the object has
            UnsignedInteger64bits m_numberOfPrivateFriendFunctions;

            // This object will store the number of private friend objects the object has
            UnsignedInteger64bits m_numberOfPrivateFriendObjects;


            // DATA MEMBERS INFORMATION :


            // Public data members :


            // This object will store the number of public static data members
            UnsignedInteger64bits m_numberOfPublicStaticDataMembers;


            // Protected data members :


            // This object will store the number of protected data members the object has
            UnsignedInteger64bits m_numberOfProtectedDataMembers;


            // Private data members :


            // This object will store the number of protected data members the object has
            UnsignedInteger64bits m_numberOfPrivateDataMembers;






        	// Static data members do not belong to any instance, it belongs to the object. Like every global variable it is created with the start of the program
    		// and only destroyed when the program ends. This means that each member method can use the static data members, but not functions outside the object's
    		// scope. It restricts the access to this object use only, but rather then that acts as global variable


    		// The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
    		// rather help implement it :


    		// Friend class or friend function can access private and protected members of other class in which it is declared as friend. It is sometimes useful
    		// to allow a particular class to access private members of other class. The declration of such function is private, because these functions are part
    		// of the implemntation, which the user should not be aware of. The use of this functions is not limited to the class's scope. One of the problems that
    		// friend addition to the object solves is when the object needs to be as a left side operand in expressions. Every method in the object is implicitly
    		// added a pointer to the location of the object data with name the "this", and to enable this the method must be called from an existing instance.
    		// This means that the object can only be implemented as the right side operand of an expression with methods, and friend functions and objects does
    		// not have this limitation


    	};  //  Class ObjectMetadata










































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************












































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
        //  Exceptions :
        //
        //      NONE
        //
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename ObjectType >
    	inline ObjectMetadata< ObjectType >::ObjectMetadata() :
        m_dataType( DataType::Unknown )
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
    	//          dataType - the enumeration represnting the data type the object deals with
    	//
    	//      Information returned to the user :
    	//
    	//          NONE
    	//
    	//  Return value :
    	//
    	//   	NONE
    	//
        //  Exceptions :
        //
        //      1. The data type enumeration is not unknown
        //      2. 
        //
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename ObjectType >
    	ObjectMetadata< ObjectType >::ObjectMetadata( DataType dataType ) :
        m_dataType( dataType )
    	{
            // This will be added only in test mode, to ensure that the given data to the method is valid
            ASSERT( ( dataType != DataType::Unknown ), "Metadata::ObjectMetadata::Constructor failed - the data type is unknown" )
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
        //  Exceptions :
        //
        //      NONE
        //
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename ObjectType >
    	inline ObjectMetadata< ObjectType >::ObjectMetadata( const ObjectMetadata< ObjectType >& other ) :
        m_dataType( other.m_dataType )
    	{}


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
        //  Exceptions :
        //
        //      NONE
        //
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename ObjectType >
    	inline ObjectMetadata< ObjectType >& ObjectMetadata< ObjectType >::operator=( const ObjectMetadata< ObjectType >& other )
    	{
    		// Create a copy of the other instance
    		ObjectMetadata< ObjectType > temporary( other );

    		// Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
    		Swap( temporary );

    		// Return a reference to this object
    		return ( *this );
    	}


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
        //  Exceptions :
        //
        //      NONE
        //
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename ObjectType >
    	inline ObjectMetadata< ObjectType >::ObjectMetadata( ObjectMetadata< ObjectType >&& other ) :
    	ObjectMetadata< ObjectType >()
    	{
    		// Swap between this instance, which is in default state, and the other one
    		Swap( other );
    	}


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
        //  Exceptions :
        //
        //      NONE
        //
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename ObjectType >
    	inline ObjectMetadata< ObjectType >& ObjectMetadata< ObjectType >::operator=( ObjectMetadata< ObjectType >&& other )
    	{
    	    // Create a default constructed instance
    	    ObjectMetadata< ObjectType > defaultConstructedInstance;

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
        template< typename ObjectType >
        inline void ObjectMetadata< ObjectType >::Swap( ObjectMetadata< ObjectType >& other )
    	{
            // Swap between the data type
            Memory::Swap< DataType >( m_dataType, other.m_dataType );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to set a new memory segment to point too
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          dataType - the enumeration represnting the data type the object deals with
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      NONE
        //
        //  Exceptions :
        //
        //      1. The data type enumeration is not unknown
        //      2. 
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename ObjectType >
        inline void ObjectMetadata< ObjectType >::Initiate( DataType dataType )
        {
            // This will be added only in test mode, to ensure that the given data to the method is valid
            ASSERT( ( dataType != DataType::Unknown ), "Metadata::ObjectMetadata::Initiate failed - the data type is unknown" )

            // Create a temporary instance of the this object
            ObjectMetadata< ObjectType > temporary( dataType );

            // Swap between this instance and the temporary one
            Swap( temporary );
        }


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
        //  Exceptions :
        //
        //      NONE
        //
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename ObjectType >
    	inline ObjectMetadata< ObjectType >::~ObjectMetadata()
    	{
           	// Delete the object resources
           	DeleteResourcesAndSetToDefaultState();
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use to set the object into his default state. It does not delete the resources, if the method is used all the information inside will be lost and
    	//		a memory leak will occuer
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
        //  Exceptions :
        //
        //      NONE
        //
    	//  Possible errors :
    	//
    	//	    They will come
    	//
    	template< typename ObjectType >
    	inline void ObjectMetadata< ObjectType >::SetToDefaultState()
    	{
            // Set the data type to unknown
            m_dataType = DataType::Unknown;
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
        //  Exceptions :
        //
        //      NONE
        //
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	template< typename ObjectType >
    	inline bool ObjectMetadata< ObjectType >::DefaultState() const
    	{
            // Check if the instance is in default state, and return the result
            return ( m_dataType == DataType::Unknown );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use to delete the instance resources and set it to default state
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
        //  Exceptions :
        //
        //      NONE
        //
    	//  Possible errors :
    	//
    	//      1. Deleting the object resources failed
    	//      2.
    	//
    	template< typename ObjectType >
    	inline void ObjectMetadata< ObjectType >::DeleteResourcesAndSetToDefaultState()
    	{
            // Check if the object is in default state, then noting needs to be done
            RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

    		// Set the object to default state
    		SetToDefaultState();
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use this method to get the object ID 
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
        //      The object ID
        //
        //  Exceptions :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      1. Deleting the object resources failed
        //      2.
        //
        template< typename ObjectType >
        inline UnsignedInteger64bits ObjectMetadata< ObjectType >::ID() const
        {
            // Return the object ID
            return ( ID().Get< ObjectType >() );
        }








































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************














































        // Method Information :
        //
        //  Description :
        //
        //      Use this operator to check if the this instance match the other
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
        //  Expectations :
        //
        //      NONE
        //
        //  Possible errors :
        //
        //      They will come
        //
        template< typename ObjectType >
        inline Boolean ObjectMetadata< ObjectType >::operator==( const ObjectMetadata< ObjectType >& other ) const
        {
            // Check if the pointers and the sizes inside both instance match, and return the result
            return ( ( m_dataType == other.m_dataType ) );
        }


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use this operator to check if the this instance does not match the other
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
        //  Expectations :
        //
        //      NONE
        //
    	//  Possible errors :
    	//
    	//      1. The template type object does not have the comparison operator ( == )
    	//      2. 
    	//
    	template< typename ObjectType >
    	inline bool ObjectMetadata< ObjectType >::operator!=( const ObjectMetadata< ObjectType >& other ) const
    	{
    		// Return the negotiated value from the equal operator
    		return ( !( *this == other ) );
    	}



















































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************










//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************










//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************










// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************











// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************












// *********************************************************************************   TESTING   ********************************************************************************






















    	DEBUG_TOOL(

    		// Method Information :
    		//
    		//  Description :
    		//
    		//      This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
    		//		the functionality
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
    		template< typename ObjectType >
    		void ObjectMetadata< ObjectType >::Test()
    		{}

    	)  //  End of debug tool











    }  //  Namespace Metadata

}  //  Namespace Universe



#endif  // OBJECTMETADATA_HPP