#ifndef  FIXEDSIZEARRAYBITS_HPP
#define  FIXEDSIZEARRAYBITS_HPP


#include "../../../../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef UnsignedInteger64bits
#include "../../../../../BasicUtilities/C++/cpp_BasicUtilities.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../Memory/MemoryOperations/Swap/Swap.hpp"  //  Class Swap
#include "../../../../../Memory/MemoryOperations/Copy/Copy.hpp"  //  Class Copy
#include "../../../../../Memory/MemoryOperations/Compare/Compare.hpp"  //  Class Compare
#include "../../../../../Memory/MemoryOperations/Set/Set.hpp"  //  Class Set
#include "../../../../../Abilities/Proxy/Bits/Bits.hpp"  //  Class Proxy::Bits
#include "../../../../../DataTypes/SmartPointers/HeapSharedBitsPointer/HeapSharedBitsPointer.hpp"  //  Class HeapSharedBitsPointer


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#endif


// When a function name ends with the suffix IMP, the function is not part of the object interface ( capabilities ), it only used as aid to the function that
// it is, implementing only spsecific part



namespace Universe
{

    namespace Abilities
    {

        namespace FixedSizeArray
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


        	// Template class Information :
        	//
        	//  Purpose :
        	//
        	//      Use this object to manage a contigous segment of basic types data, when the number of entries required is known in advance
        	//
       	    //  Description :
       	    //
      	    //		1. The access to elements in the container should be through the operator []. This will allow the object to prevent copying the resource when it needs to 
            //         only read from it. In other words it will allow the resource inside each instance to be shared as long as changes are not made to it. To implement this 
            //         the arithmetic for basic types containers object is inherited. This object will add the functionality of a proxy. Instead of returning the data or a 
            //         reference to data, a proxy instance is created with the knowledge of the required data, this gives the abililty to know what is the next required thing 
            //         from the data. The basic change is if we need to write or read. For example,
      	    //
      	    //					container[ index ] + 3
      	    //
      	    //		   In this case a proxy will be created from the first part of the expression, and then the operator+ will be choosen from the proxy. This method does not 
            //         change the instance, it only needs to read the data, and therefore no copy on write is needed, but in the case,
      	    //
      	    //					container[ index ] += 3
      	    //
      	    //			In this case the object does need to change, and therefore the proxy must make sure the container performs a copy on write prior to actual writing
        	//
        	//  Possible errors :
        	//
        	//
        	//
            class Bits 
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
        		inline Bits();


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
                //          1. size - the required number of bits
                //          2. state - a boolean describing the state of the bit
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //        NONE
                //
                //  Possible errors :
                //
                //      1. There is no more free memory space - class std::bad_alloc is thrown
                //      2. The given size of the basic types fixed size platfrom is 0
                //      3. The object does not have assignment operator
                //      4. 
                //
                explicit inline Bits( UnsignedInteger64bits size, Boolean state = 0 );


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
        		inline Bits( const Bits& other );


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
        		inline Bits& operator=( const Bits& other );


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
        		inline Bits( Bits&& other );


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
        		inline Bits& operator=( Bits&& other );


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
                inline void Swap( Bits& other );


                // Method Information :
                //
                //  Description :
                //
                //      Use this to set a new size for the basic types fixed size platfrom. Note - all previous data in the platfrom will be lost
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          1. size - the required number of bits
                //          2. state - a boolean describing the state of the bit
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
                //      1. The given size of the new basic types fixed size platfrom is 0 
                //      2.
                //
                inline void Initiate( UnsignedInteger64bits newSize, Boolean state = 0 );


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
        		virtual inline ~Bits() = default;


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


                // Method Information :
                //
                //  Description :
                //
                //      Use this to set all the entries of the basic types fixed size platfrom to the required value
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          state - a boolean describing the required state for the bits
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
                //      1. The object does not have an assignment operator
                //      2. The object is in default state
                //      3.
                //
                inline void SetAll( Boolean state );


                // Method Information :
                //
                //  Description :
                //
                //      Use to get the number of entries in the basic types fixed size platfrom
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
                //      The size of the basic types fixed size platfrom
                //
                //  Possible errors :
                //
                //      1. The object is in default state
                //      2.
                //
                inline UnsignedInteger64bits Size() const;


        		// The following methods declare the overloaded operators for the object :


                // Method Information :
                //
                //  Description :
                //
                //      Use to get reference to an entry
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          index - the index of the entry required
                //
                //      Information returned to the user :
                //
                //          NONE
                //
                //  Return value :
                //
                //      The basic types fixed size platfrom proxy class
                //
                //  Possible errors :
                //
                //      1. The object is in default state
                //      2. The entry index is out of the basic types fixed size platfrom range
                //      3.
                //
                inline Proxy::Bits< Bits, UnsignedInteger64bits > operator[]( const UnsignedInteger64bits& index );


                // Method Information :
                //
                //  Description :
                //
                //      Use to get reference to an entry
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          index - the index of the entry required
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
                //      2. The entry index is out of the basic types fixed size platfrom range
                //      3.
                //
                inline Boolean operator[]( const UnsignedInteger64bits& index ) const;


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
        		bool operator==( const Bits& other ) const;


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
        		inline bool operator!=( const Bits& other ) const;


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


        	protected:


        		// The protected part is used for inheritance. This means that only this object and the objects that inherit from it can use the protected members data or methods


                // This object will store the basic types fixed size platfrom
                DataTypes::HeapSharedBitsPointer m_fixedSizeArray;


        	private:


                // Allow the inherited arithmetic proxy object, to access protected and private sections of this object
                friend class Proxy::Bits< Bits, UnsignedInteger64bits >;


                // The following methods are private. This means that only public or protected methods can use them, in other words they not part of the interface, but
                // rather help implement it :


                // Method Information :
                //
                //  Description :
                //
                //      Use this method to copy the basic types fixed size platfrom to a new memory space
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
                inline void Copy_IMP();


                // The following methods decalre the pure virtual methods derived :


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
                //          index - the index to the required element in the container
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
                virtual inline DataTypes::Bit GetData_IMP( const UnsignedInteger64bits& index );


                // Method Information :
                //
                //  Description :
                //
                //      This method will be used for constant objects
                //
                //  Required arguments :
                //
                //      User information needed :
                //
                //          index - the index to the required element in the container
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
                virtual inline Boolean GetData_IMP( const UnsignedInteger64bits& index ) const;


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
                virtual inline void ExecuteTaskBeforeObjectChanges_IMP();


        	};  //  Class Basic













































//  *******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************












































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
        	inline Bits::Bits() :
            m_fixedSizeArray()
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
            //          1. size - the required number of bits
            //          2. state - a boolean describing the state of the bit
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //        NONE
            //
            //  Possible errors :
            //
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. The given size of the basic types fixed size platfrom is 0
            //      3. The object does not have assignment operator
            //      4. 
            //
            inline Bits::Bits( UnsignedInteger64bits size, Boolean state ) :
            m_fixedSizeArray( size )
            {
                // Set the bits of the memory segment to the required state
                SetAll( state );
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
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	inline Bits::Bits( const Bits& other ) :
        	m_fixedSizeArray( other.m_fixedSizeArray )
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
        	inline Bits& Bits::operator=( const Bits& other )
        	{
        		// Create a copy of the other instance
        		Bits temporary( other );

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
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	inline Bits::Bits( Bits&& other ) :
        	Bits()
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
        	//  Possible errors :
        	//
        	//		They will come
        	//
        	inline Bits& Bits::operator=( Bits&& other )
        	{
        	    // Create a default constructed instance
        	    Bits defaultConstructedInstance;

        	    // Swap between the temporary instance, which is in default state, and the other instance
        	    defaultConstructedInstance.Swap( other );

        	    // Swap between this instance and the temporary one
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
            inline void Bits::Swap( Bits& other )
        	{
                // Swap between the heap shared pointers
                m_fixedSizeArray.Swap( other.m_fixedSizeArray );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use this to set a new size for the basic types fixed size platfrom. Note - all previous data in the platfrom will be lost
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. size - the required number of bits
            //          2. state - a boolean describing the state of the bit
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
            //      1. The given size of the new basic types fixed size platfrom is 0 
            //      2.
            //
            void Bits::Initiate( UnsignedInteger64bits newSize, Boolean state )
            {
                // Create a new temporary instance
                Bits temporary( newSize, state );

                // Swap between this instance and the temporary one
                Swap( temporary );
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
        	inline void Bits::SetToDefaultState()
        	{
                // Set the heap shared pointer to default state
                m_fixedSizeArray.SetToDefaultState();
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
        	inline bool Bits::DefaultState() const
        	{

        		// Check if the object is in default state
        		if ( m_fixedSizeArray.DefaultState() == true )
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
        	inline void Bits::DeleteResourcesAndSetToDefaultState()
        	{
                // Check if the object is in default state, then noting needs to be done
                RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

                // Delete the memory space
                m_fixedSizeArray.DeleteResourcesAndSetToDefaultState();
        	}


            // Method Information :
            //
            //  Description :
            //
            //      Use this to set all the entries of the basic types fixed size platfrom to the required value
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          state - a boolean describing the required state for the bits
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
            //      1. The object does not have an assignment operator
            //      2. The object is in default state
            //      3.
            //
            inline void Bits::SetAll( Boolean state )
            {
                // A write operation is about to take place, check if only this instance uses the resource, if not, copy it to a new one that only this instance uses
                ExecuteTaskBeforeObjectChanges_IMP();

                // Set the all the entries to the required value
                Memory::Set::Bits( m_fixedSizeArray, state );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the number of entries in the basic types fixed size platfrom
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
            //      The size of the basic types fixed size platfrom
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2.
            //
            inline UnsignedInteger64bits Bits::Size() const
            {
                // Return the number of entries in the basic types fixed size platfrom
                return ( m_fixedSizeArray.Size() );
            }















































//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************













































            // Method Information :
            //
            //  Description :
            //
            //      Use to get reference to an entry
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - the index of the entry required
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      The basic types fixed size platfrom proxy class
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. The entry index is out of the basic types fixed size platfrom range
            //      3.
            //
            inline Proxy::Bits< Bits, UnsignedInteger64bits > Bits::operator[]( const UnsignedInteger64bits& index )
            {
                // Create the proxy class and return it
                return ( Proxy::Bits< Bits, UnsignedInteger64bits >( *this, index ) );
            }


            // Method Information :
            //
            //  Description :
            //
            //      Use to get reference to an entry
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          index - the index of the entry required
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
            //      2. The entry index is out of the basic types fixed size platfrom range
            //      3.
            //
            inline Boolean Bits::operator[]( const UnsignedInteger64bits& index ) const
            {
                // Return a copy of the value in the entry
                return ( m_fixedSizeArray[ index ] );
            }


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
        	inline bool Bits::operator==( const Bits& other ) const
        	{
                // Return the result of the comparison
                return ( Memory::Compare::Bits( m_fixedSizeArray, other.m_fixedSizeArray ) );
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
        	//  Possible errors :
        	//
        	//      1. The template type object does not have the comparison operator ( == )
        	//      2. 
        	//
        	inline bool Bits::operator!=( const Bits& other ) const
        	{
        		// Return the negotiated value from the equal operator
        		return ( !( *this == other ) );
        	}















































//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************







































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
            //          index - this will be used to identify the required data
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
            inline DataTypes::Bit Bits::GetData_IMP( const UnsignedInteger64bits& index )
            {
                // Return a reference to the data
                return ( m_fixedSizeArray[ index ] );
            }


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
            //          index - this will be used to identify the required data
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
            inline Boolean Bits::GetData_IMP( const UnsignedInteger64bits& index ) const
            {
                // Return a copy of the data
                return ( m_fixedSizeArray[ index ] );
            }


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
            inline void Bits::ExecuteTaskBeforeObjectChanges_IMP()
            {
                // Check if only this instance uses the shared resource
                RETURN_IF_THE_VALUES_ARE_EQUAL( m_fixedSizeArray.Counter(), 1 )

                // More then 1 instance uses the shared resource, Create a new copy of the resource            
                Copy_IMP();
            }









































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************








































            // Method Information :
            //
            //  Description :
            //
            //      Use this method to copy the basic types fixed size platfrom to a new memory space
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
            inline void Bits::Copy_IMP()
            {
                // This object will store the new allocated memory space
                DataTypes::HeapSharedBitsPointer temporary( m_fixedSizeArray.Size() );

                // Copy the basic types fixed size platfrom to the new memory space
                Memory::Copy::Bits( m_fixedSizeArray, temporary );

                // Swap between the temporary and this instance
                m_fixedSizeArray.Swap( temporary );
            }









































// ********************************************************************************   TESTING   *********************************************************************************








































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
        		void Bits::Test()
        		{
                    // Create an instance of the object using the default constructor
                    Bits testArray_1;

                    // Check that it is really in default state
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( testArray_1.DefaultState(), "Bits::Test failed - 1" );

                    // Create an instnace of the object using the parameterized constructor
                    Bits testArray_2( 67 );

                    // Check the size of the array
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( 67 == testArray_2.Size() ), "Bits::Test failed - 2" );            

                    // Create an instnace of the object using the parameterized constructor
                    Bits testArray_3( 67, true );

                    // Check the size of the array
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( 67 == testArray_3.Size() ) && ( testArray_3[45] == true ), "Bits::Test failed - 3" );            

                    // Create an instance using the copy constructor
                    Bits testArray_4( testArray_3 );

                    // Check that the 2 instnaces point to the same address
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_3 == testArray_4 ), "Bits::Test failed - 4" );            

                    // A write operation is performed, to check that the object uses the copy on write method before
                    testArray_4[5] |= 1;

                    // Check that the 2 instnaces point to the same address
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_3 != testArray_4 ), "Bits::Test failed - 5" );                                              

                    // Check if the addition works
                    ErrorHandling::Assert< ErrorHandling::Exception >::True( ( testArray_4[5] == true ), "Bits::Test failed - 6" );
                }

        	)  //  End of debug tool



















        }  //  Namespace FixedSizeArray

    }  //  Namespace Abilities

}  //  Namespace Universe


#endif  // FIXEDSIZEARRAYBITS_HPP