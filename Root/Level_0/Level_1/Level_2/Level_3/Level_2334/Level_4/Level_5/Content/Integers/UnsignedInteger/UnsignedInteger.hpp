#ifndef  UNSIGNEDINTEGER_HPP
#define  UNSIGNEDINTEGER_HPP


#include "../Definitions/VariableTypesDefinitions.hpp"  //  Typedef
#include "../BasicUtilities/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../Memory/Swap/Swap.hpp"  //  Class Swap


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


// When a function name ends with the suffix IMP, the function is not part of the object interface ( capabilities ), it only used as aid to the function that
// it is, implementing only spsecific part


namespace Universe
{

    namespace DataTypes
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
    	class UnsignedInteger
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
    		inline UnsignedInteger();


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
    		explicit UnsignedInteger();


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
    		inline UnsignedInteger( const UnsignedInteger& other );


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
    		inline UnsignedInteger& operator=( const UnsignedInteger& other );


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
    		inline UnsignedInteger( UnsignedInteger&& other );


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
    		inline UnsignedInteger& operator=( UnsignedInteger&& other );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      This method is used to swap the content between 2 instances of this object
    		//
    		//  Required arguments :
    		//
    		//      User information needed :
    		//
    		//          firstObject - a reference to the first object to swap
    		//          secondObject - a reference to the second object to swap
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
    		static void Swap( UnsignedInteger& firstObject, UnsignedInteger& secondObject );


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use his method is used to delete the resources of the instance
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
    		void Delete();


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
    		inline ~UnsignedInteger();


    		// To support Move semantics, the following 3 methods are added to every object. One method to set the object into the default state, another to check if the
    		// object is in the default state, and the last method to delete all the object resources and set the object to default state :


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
    		//  Possible errors :
    		//
    		//	    They will come
    		//
    		inline void SetToDefaultState();


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
    		//  Possible errors :
    		//
    		//      1. Deleting the object resources failed
    		//      2.
    		//
    		inline void DeleteResourcesAndSetToDefaultState();


    		// The following methods are the interface of the object. This methods implement the capabilities of the object :











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
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		bool operator==( const UnsignedInteger& other ) const;


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
    		//  Possible errors :
    		//
    		//		They will come
    		//
    		inline bool operator!=( const UnsignedInteger& other ) const;


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


    	};  //  Class UnsignedInteger










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
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline UnsignedInteger::UnsignedInteger() :
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
    	UnsignedInteger::UnsignedInteger() :
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
    	inline UnsignedInteger::UnsignedInteger( const UnsignedInteger& other ) :
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
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline UnsignedInteger& UnsignedInteger::operator=( const UnsignedInteger& other )
    	{
    		// Create a copy of the other instance
    		UnsignedInteger temporaryObject( other );

    		// Swap between this instance and the temporary one, this will leave the temporary instance with the old data, and he will delete it
    		Swap( *this, temporaryObject );

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
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline UnsignedInteger::UnsignedInteger( UnsignedInteger&& other ) :
    	UnsignedInteger()
    	{
    		// Swap between this instance, which is in default state, and the other one
    		Swap( *this, other );
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
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline UnsignedInteger& UnsignedInteger::operator=( UnsignedInteger&& other )
    	{
    	    // Create a default constructed instance
    	    UnsignedInteger temporaryObject;

    	    // Swap between the temporary instance, which is in default state, and the other instance
    	    Swap( temporaryObject, other );

    	    // Swap between this instance and the temporary one
    	    Swap( *this, temporaryObject );

    	    // Return a reference to this object
    	    return ( *this );
    	}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      This method is used to swap the content between 2 instances of this object
    	//
    	//  Required arguments :
    	//
    	//      User information needed :
    	//
    	//          firstObject - a reference to the first object to swap
    	//          secondObject - a reference to the second object to swap
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
    	void UnsignedInteger::Swap( UnsignedInteger& firstObject, UnsignedInteger& secondObject )
    	{}


    	// Method Information :
    	//
    	//  Description :
    	//
    	//      Use his method is used to delete the resources of the instance
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
    	void UnsignedInteger::Delete()
    	{
    		// Delete the object resources
    		Delete();
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
    	//  Possible errors :
    	//
    	//		They will come
    	//
    	inline UnsignedInteger::~UnsignedInteger()
    	{
           	// Delete the object resources
           	Delete();
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
    	//  Possible errors :
    	//
    	//	    They will come
    	//
    	inline void UnsignedInteger::SetToDefaultState()
    	{
    	    // Create a default constructed instance
    	    UnsignedInteger temporaryObject;

    	    // Swap between this instance and the temporary one
    	    Swap( *this, temporaryObject );
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
    	inline bool UnsignedInteger::DefaultState() const
    	{

    		// Check if the object is in default state
    		if ()
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
    	//  Possible errors :
    	//
    	//      1. Deleting the object resources failed
    	//      2.
    	//
    	inline void UnsignedInteger::DeleteResourcesAndSetToDefaultState()
    	{
    		// Release the resources of this object
    		Delete();

    		// Set the object to default state
    		SetToDefaultState();
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
    	//  Possible errors :
    	//
    	//      1. The template type object does not have the comparison operator ( == )
    	//      2. 
    	//
    	bool UnsignedInteger::operator==( const UnsignedInteger& other ) const
    	{}


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
    	//  Possible errors :
    	//
    	//      1. The template type object does not have the comparison operator ( == )
    	//      2. 
    	//
    	inline bool UnsignedInteger::operator!=( const UnsignedInteger& other ) const
    	{
    		// Return the negotiated value from the equal operator
    		return ( !( *this == other ) );
    	}













//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************










//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************










//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************










// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************











// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************












    }  //  Namespace DataTypes

}  //  Namespace Universe



#endif  // UNSIGNEDINTEGER_HPP