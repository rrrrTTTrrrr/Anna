#ifndef  SEARCH_HPP
#define  SEARCH_HPP


#include <new>   //  Class std::bad_alloc


#include "../../../Definitions/VariableTypesDefinitions.hpp"  //  Typedef UnsignedInteger64bits
#include "../../../BasicUtilities/cpp_BasicUtilities.hpp"  //  Macro DEBUG_TOOL


// The following includes represent the supported array containers
#include "../../Array/BasicTypes/BasicTypesArray/BasicTypesArray.hpp"  //   Class BasicTypesArray
#include "../../Array/BasicTypes/BasicTypesFixedSizeArray/BasicTypesFixedSizeArray.hpp"  //   Class BasicTypesFixedSizeArray
#include "../../Array/Objects/ObjectsArray/ObjectsArray.hpp"  //   Class ObjectsArray
#include "../../Array/Objects/ObjectsFixedSizeArray/ObjectsFixedSizeArray.hpp"  //   Class ObjectsFixedSizeArray

// The following includes represent the supported linked list containers
#include "../../LinkedList/DoubleLinkedList/BasicTypesDoubleLinkedList/BasicTypesDoubleLinkedList.hpp"  //   Class BasicTypesDoubleLinkedList


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include <iostream>
#include "../../../ErrorHandling/Exception/Exception.hpp"  //  Class Exception
#include "../../../ErrorHandling/Assert/Assert.hpp"  //  Class Assert
#include "../../../GeneralPurposeContainers/RawDataToContainer/RawDataToContainer.hpp"  //  Class RawDataToContainer
#include "../../../Encoding/Ascii/AsciiString/AsciiString.hpp"  //   Class Ascii
#endif


// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part



namespace Universe
{

    namespace GeneralPurposeContainers
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
    	// Constructor of derived object, when called, all the base class constructors are executed
    	// first, according to the order they appear in the class declaration, and only then the
    	// user code is executed

    	// Destructor of derived object, when it is called, the user code existing in the destructor
    	// itself is executed first and then all the destructors of the base objects, in an opposite
    	// way from which they were constructed


		// Template class Information :
    	//
    	//  Purpose :
    	//
    	//
    	//
   	    //  Description :
   	    //
        //      1. There is no exception specification on purpose. The reason is that when working with templates, the given type of the template
        //      can overload and override any operator and method, and therefore throw anything it see fit. This causes the problem, there is
        //      no way of knowing what the given type throws. The only method declared with exception specification is the destructor, which should
        //      not throw any exception anyhow, to prevent throwing an exception while another exception is active. This will cause the
        //      program to end
        //
        //      2. The algorithm :
        //
        //          Notion : n = array size, k = pattern size
        //
        //          This object deals with searching data in containers that manage array. Now if the required pattern consist of entry in the array,
        //          in the search every element should be checked until a match is found or the end of the array reached. This search for one specific 
        //          entry then will have a worst case of passing on all the entries ( O(n) ). This is not the case if the pattern is a set of more then 
        //          one entry. Every entry now must be matched with the pattern and this makes the worst case to O(n*k). To reduce the need of constant
        //          repeat checking entries in the data that were already checked, a lookup table is created, which tells the index on the data where
        //          to move next and start a new search for the pattern. While nothing is known on the data, the pattern is do known
        //
        //          To logic is as follows :
        //
        //          All the entries before the current entry must be used to find if a match is found. A match between entries starting from the beginning of
        //          the pattern, and entries starting from the second entry. They both have an initial size of the current index on the pattern minus 1.
        //          In each loop the size is decreasing by 1. Then for the first set of entries th beginning point is fixed, and the end point decreases
        //          as the size decreases. For second set the end point is fixed and the beginning point increases as the size decreases. It looks for the
        //          longest match 
        //
        //          For example,
        //
        //                                  pattern -> bbfddsdfffbbfyyy
        //
        //          pattern[4] has before him "bbfd", so the following check must be done  :
        //
        //
        //                              First loop
        //
        //                                  entries starting from the beginning -> bbf
        //                                  entries starting from the second entry -> bfd
        //                                  size = 3
        //                                  
        //                              Second loop
        //
        //                                  entries starting from the beginning -> bb
        //                                  entries starting from the second entry -> fd
        //                                  size = 2
        //
        //                              Third loop
        //
        //                                  entries starting from the beginning -> b
        //                                  entries starting from the second entry -> d
        //                                  size = 1
        //
        //          As can be seen the sets dont match in any case therefore the index on the data should advance the amount pattern index has,
        //          which means all this data before can not match no need to check it again
        //
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename TYPE >
        class Search
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
    		explicit inline Search();


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
        	//          pattern - a reference to a container object
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
    		explicit inline Search( const TYPE& pattern );


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
    		inline Search( const Search< TYPE >& other );


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
    		Search< TYPE >& operator=( const Search< TYPE >& other );


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
    		inline Search( Search< TYPE >&& other );


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
    		Search< TYPE >& operator=( Search< TYPE >&& other );


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
    		inline ~Search() throw();


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
    		inline void DeleteResourcesAndSetToDefaultState();


    		// The following methods are the interface of the object. This methods implement the capabilities of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the current pattern size
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
            //      The size of the pattern inside the object
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2.
            //
            inline UnsignedInteger64bits GetPatterSize() const;


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the current pattern
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
            //      1. The object is in default state
            //      2.
            //
            inline TYPE GetPattern() const;


            // Method Information :
            //
            //  Description :
            //
            //      Use to set new pattern 
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          newPattern - a reference to an array object containing the pattern
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
            //      1. The object is in default state
            //      2. There is no more free memory space - class std::bad_alloc is thrown
            //      3. 
            //
            inline void SetNewPattern( const TYPE& newPattern );


            // The following part of the interface will be implemented by inherting objects. Therefore all the following 
            // method are declared virtual :


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the offset to the first appearance of the pattern in the data. Important note - the largest value
            //      possible for unsigned integer with 64 bits ( ~0 ) is reserved for detecting that the pattern was not found
            //      in the given data
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          data - a reference to an array container object
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. If the pattern exist in the data - The offset to the first apperance of the pattern in the data
            //      2. If the pattern does not exist in the data - the maximum value of an unsigned integer with 64 bits ( ~0 )
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. 
            //
            UnsignedInteger64bits FirstApperance( const TYPE& data ) = 0;


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the offset to the all of appearance of the pattern in the data. Important note - if no appearance
            //      was found the size of the given array will be 0
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          data - a reference to an container object that manages array
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. If the pattern exist in the data - The offsets to all of the apperances of the pattern in the data
            //      2. If the pattern does not exist in the data even once - the size of the returned array object will be 0
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. There is no more free memory space - class std::bad_alloc is thrown
            //      3. 
            //
            BasicTypesArray< UnsignedInteger64bits > AllApperances( const TYPE& data );


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
    		inline bool operator==( const Search< TYPE >& other ) const;


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
    		inline bool operator!=( const Search< TYPE >& other ) const;


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


            // This object will store the given pattern to find. The pattern type must be conatiner and to have a method
            // with the name Size to get the container size
            TYPE m_pattern;

            // This object will be used to store the amount the data index has to advance before starting a new search
            // after a mismatch was found between the pattern and the data
            BasicTypesFixedSizeArray< UnsignedInteger64bits > m_advanceDataIndex;

            // This object will be used to store the first index of every apperance of the pattern in the data
            BasicTypesArray< UnsignedInteger64bits > m_apperances;

            // This part will contain information on the overlapping patterns in the data :

            // This object will store 


        	// Static data members do not belong to any instnace, it belongs to the class. Like every global variable
    		// it is created with the start of the program and only destroyed when the program ends. This means that
    		// each member method can use the static data members, but not functions outside the object's scope. It
    		// restricts the access to this object use only, but rather then that acts as global variable


    		// The following methods are private. This means that only public or protected methods can use them, in other
    		// words they not part of the interface, but rather help implement it :


            // The following part of the private methods was inhertid from the search object, and needs to be implemented. The methods
            // are virtual, if the base class has a virtual method the same method in a derived object is automatically virtual,
            // and all this methods were declared pure virtual in the base class :


            // Method Information :
            //
            //  Description :
            //
            //      Use to create the array that should be looked up every time a mismatch between the pattern and the data occurs.
            //      The question is from where the search should continue when a mismtach happens. For this purpose, for every entry
            //      in the pattern, the longest subpattern that matches a subpattern with the same size only that starts at the beginning
            //      must be found, if it exist, and then if a mismatch with the data happens in the entry, then the length of the
            //      subpattern must be backed, and the search should continue from there 
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
            void SetAdvanceDataIndexIMP();


    		// Friend class or friend function can access private and protected members of other class in which it is declared as friend.
    		// It is sometimes useful to allow a particular class to access private members of other class. The declration of such function
    		// is private, because these functions are part of the implemntation, which the user should not be aware of. Furthermore the
    		// use of this functions is not limited to the class's scope. The following declarations are for all the function that should
    		// be friends with this class :




    	};  //  Class Search



























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
    	inline Search< TYPE >::Search() :
        m_pattern(),
        m_advanceDataIndex()
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
    	//          pattern - a reference to a container object
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
    	inline Search< TYPE >::Search( const TYPE& pattern ) :
        m_pattern( pattern ),
        m_advanceDataIndex( pattern.Size(), 0 )
        {
            // Initialize the values to the array with the amount to back on the data, if a mismatch with the pattern occuers
            SetAdvanceDataIndexIMP();
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
    	template< typename TYPE >
    	inline Search< TYPE >::Search( const Search& other ) :
        m_pattern( other.m_pattern ),
        m_advanceDataIndex( other.m_advanceDataIndex )
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
    	Search< TYPE >& Search< TYPE >::operator=( const Search& other )
    	{

            // Check that this is not self assignment
            if ( this != &other )
            {
                // This is not self assignment

                // Check if the other object is in default state
                if ( true == other.DefaultState() )
                {
                    // The other object is in default state

                    // Release all the resources of this object and set the default state
                    DeleteResourcesAndSetToDefaultState();

                    // Nothing else needs to be done, return a reference to this object
                    return ( *this );
                }

                // Copy the other object resources

                // Copy the pattern
                m_pattern = other.m_pattern;

                // Copy the array with the back amount for every entry in the pattern
                m_advanceDataIndex = other.m_advanceDataIndex;
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
    	inline Search< TYPE >::Search( Search&& other ) :
        m_pattern( other.m_pattern ),
        m_advanceDataIndex( other.m_advanceDataIndex )
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
    	Search< TYPE >& Search< TYPE >::operator=( Search&& other )
    	{

            // Check that this is not self assignment
            if ( this != &other )
            {
                // This is not self assignment

                // Check if the other object is in default state
                if ( true == other.DefaultState() )
                {
                    // The other object is in default state

                    // Release all the resources of this object and set the default state
                    DeleteResourcesAndSetToDefaultState();

                    // Nothing else needs to be done, return a reference to this object
                    return ( *this );
                }

                // Take the other object resources

                // Take the pattern
                m_pattern = other.m_pattern;

                // Take the array with the back amount for every entry in the pattern
                m_advanceDataIndex = other.m_advanceDataIndex;

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
        inline Search< TYPE >::~Search() throw()
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
    	template< typename TYPE >
    	inline void Search< TYPE >::SetToDefaultState()
        {
            // Set the object containning the pattern to default state
            m_pattern.SetToDefaultState();

            // Set the object containning the array with the back amount for every entry in the pattern to default state
            m_advanceDataIndex.SetToDefaultState();
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
    	inline bool Search< TYPE >::DefaultState() const
    	{

            // Check if the object is in default state
            if ( ( m_pattern.DefaultState() == true ) &&
                 ( m_advanceDataIndex.DefaultState() == true ) )
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
    	inline void Search< TYPE >::DeleteResourcesAndSetToDefaultState()
    	{
    		// Check if the object is in default state, then noting needs to be done
    		RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

    		// Release the resources of this object

            // Delete the resources of the object containning the pattern
            m_pattern.DeleteResourcesAndSetToDefaultState();

            // Delete the resources of the object containning the array with the back amount for every entry in the pattern to default state
            m_advanceDataIndex.DeleteResourcesAndSetToDefaultState();
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the current pattern size
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
        //      The size of the pattern inside the object
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2.
        //
        template< typename TYPE >
        inline UnsignedInteger64bits Search< TYPE >::GetPatterSize() const
        {
            // Return a copy of the pattern
            return ( m_pattern.Size() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the current pattern
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
        //      1. The object is in default state
        //      2.
        //
        template< typename TYPE >
        inline TYPE Search< TYPE >::GetPattern() const
        {
            // Return a copy of the pattern
            return ( m_pattern );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to set new pattern 
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          newPattern - a reference to an array object containing the pattern
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
        //      1. The object is in default state
        //      2. There is no more free memory space - class std::bad_alloc is thrown
        //      3. 
        //
        template< typename TYPE >
        inline void Search< TYPE >::SetNewPattern( const TYPE& newPattern )
        {
            // Set the new pattern to the basic types fixed size array
            m_pattern = newPattern;

            // Set new size to lookup table array
            m_advanceDataIndex.SetNewSize( newPattern.Size() );

            // Initialize the values to the array with the amount to back on the data, if a mismatch with the pattern occuers
            SetAdvanceDataIndexIMP();
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the offset to the first appearance of the pattern in the data. Important note - the largest value
        //      possible for unsigned integer with 64 bits ( ~0 ) is reserved for detecting that the pattern was not found
        //      in the given data
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          data - a reference to an array container object
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. If the pattern exist in the data - The offset to the first apperance of the pattern in the data
        //      2. If the pattern does not exist in the data - the maximum value of an unsigned integer with 64 bits ( ~0 )
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. 
        //
        template< typename TYPE >
        inline UnsignedInteger64bits SearchArray< TYPE >::FirstApperance( const TYPE& data )
        {
            // Create space to store the data size
            UnsignedInteger64bits dataSize = data.Size();

            // Create space to store the pattern size
            UnsignedInteger64bits patternSize = m_pattern.Size();

            // Create space to store the data index 
            UnsignedInteger64bits dataIndex = 0 ;

            // Create space to store the pattern index 
            UnsignedInteger64bits patternIndex = 0 ;

            // Loop on all the data and try to find the pattern
            while ( dataIndex < dataSize )
            {

                // Loop on all the pattern to see if current location in the data matches the pattern
                for ( UnsignedInteger64bits patternIndex = 0 ; patternIndex < patternSize ; ++patternIndex )
                {

                    // Check if the current data and pattern entry does not match
                    if ( m_pattern[ patternIndex ] != data[ dataIndex + patternIndex ] )
                    {
                        // The data and the pattern does not match, then current location in the data does not contain the pattern
                        // and the serach needs to continue from the next location

                        // Advance the data index to the next location
                        dataIndex += m_advanceDataIndex[ patternIndex ];

                        // Break the loop
                        break;
                    }

                }

                // Check if the loop passed on all the pattern, which means a match was found
                if ( patternIndex == patternSize )
                {
                    // The pattern exist in the current location in the data, return the offset to this location
                    return ( dataIndex );
                }

            }

            // If control reached here then the pattern does not exist in the data, return the maximum value of an unsigned integer with 64 bits
            return ( ~0 );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the offset to the all of appearances of the pattern in the data. The apperances will be in the
        //      array in the same order they appear in the data
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          data - a reference to an container object that manages array
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. If the pattern exist in the data - The offsets to all of the apperances of the pattern in the data
        //      2. If the pattern does not exist in the data even once - the size of the returned array object will be 0
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. There is no more free memory space - class std::bad_alloc is thrown
        //      3. 
        //
        template< typename TYPE >
        BasicTypesArray< UnsignedInteger64bits > SearchArray< TYPE >::AllApperances( const TYPE& data )
        {
            // Create an object to store the offsets to all the apperances of the pattern in the data
            BasicTypesArray< UnsignedInteger64bits > apperances;

            // Create space to store the data size
            UnsignedInteger64bits dataSize = data.Size();

            // Create space to store the pattern size
            UnsignedInteger64bits patternSize = m_pattern.Size();

            // Create space to store the data index 
            UnsignedInteger64bits dataIndex = 0 ;

            // Create space to store the pattern index 
            UnsignedInteger64bits patternIndex = 0 ;

            // Loop on all the data and try to find the pattern
            while ( dataIndex < dataSize )
            {

                // Loop on all the pattern to see if current location in the data matches the pattern
                for ( UnsignedInteger64bits patternIndex = 0 ; patternIndex < patternSize ; ++patternIndex )
                {

                    // Check if the current data and pattern entry does not match
                    if ( m_pattern[ patternIndex ] != data[ dataIndex + patternIndex ] )
                    {
                        // The data and the pattern does not match, then current location in the data does not contain the pattern
                        // and the serach needs to continue from the next location

                        // The next location depends on the amount that should be backed, therefore add the value inside the array
                        // with back amount for every entry in the pattern, to the data index
                        dataIndex += m_advanceDataIndex[ patternIndex ];

                        break;
                    }

                }

                // Check if the loop passed on all the pattern, which means that the pattern also exist in this location in the data
                if ( patternIndex == patternSize )
                {
                    // The pattern exist in the current location in the data, return the offset to this location
                    apperances.PushTail( dataIndex );
                }

            }

            // Check if the current apperances array match the one in this instance
            if ( apperances == m_apperances )
            {
                // Then the data didn
            }

            // Return the object with the offsets to the pattern in the data
            return ( apperances );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use to get the offset to the all of appearance of the pattern in the data. Important note - if no appearance
        //      was found the size of the given array will be 0
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          data - a reference to an container object that manages array
        //
        //      Information returned to the user :
        //
        //          NONE
        //
        //  Return value :
        //
        //      1. If the pattern exist in the data - The offsets to all of the apperances of the pattern in the data
        //      2. If the pattern does not exist in the data even once - the size of the returned array object will be 0
        //
        //  Possible errors :
        //
        //      1. The object is in default state
        //      2. There is no more free memory space - class std::bad_alloc is thrown
        //      3. 
        //
        template< typename TYPE >
        BasicTypesArray< UnsignedInteger64bits > SearchArray< TYPE >::SetOverlapPatternsInformation()
        {
            // This array will contain information on how to remove all apperances of the paatern from the data.
            // This array is required if the pattern apperances overlap each other. Then for every apperance an
            // entry will be created with the amount that needs to be removed from that point
            BasicTypesArray< UnsignedInteger64bits > m_overlapingPatternsInformation;

            // Create space to store the pattern size
            UnsignedInteger64bits patternSize = m_pattern.Size();

            // Create space to store the apperances index 
            UnsignedInteger64bits apperancesIndex = 0 ;

            // Create space to store the pattern index 
            UnsignedInteger64bits patternIndex = 0 ;

            // Loop on all the data and try to find the pattern
            while ( dataIndex < dataSize )
            {

                // Loop on all the pattern to see if current location in the data matches the pattern
                for ( UnsignedInteger64bits patternIndex = 0 ; patternIndex < patternSize ; ++patternIndex )
                {

                    // Check if the current data and pattern entry does not match
                    if ( m_pattern[ patternIndex ] != data[ dataIndex + patternIndex ] )
                    {
                        // The data and the pattern does not match, then current location in the data does not contain the pattern
                        // and the serach needs to continue from the next location

                        // The next location depends on the amount that should be backed, therefore add the value inside the array
                        // with back amount for every entry in the pattern, to the data index
                        dataIndex += m_advanceDataIndex[ patternIndex ];

                        break;
                    }

                }

                // Check if the loop passed on all the pattern, which means that the pattern also exist in this location in the data
                if ( patternIndex == patternSize )
                {

                    // Check if the apperance overlap 
                    // The pattern exist in the current location in the data, return the offset to this location
                    m_apperances.PushTail( dataIndex );
                }

            }

            // Return the object with the offsets to the pattern in the data
            return ( apperances );
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
    	inline bool Search< TYPE >::operator==( const Search< TYPE >& other ) const
    	{

            // Check if the pattern is the same in both instances
            if ( m_pattern == other.m_pattern )
            {
                // The patterns are the same, and so is the instances
                return ( true );
            }

            // The patterns do not match, return false
            return ( false );
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
    	inline bool Search< TYPE >::operator!=( const Search< TYPE >& other ) const
    	{

            // Check if the pattern is the same in both instances
            if ( m_pattern == other.m_pattern )
            {
                // The patterns are not the same, and so is the instances
                return ( false );
            }

            // The patterns do match, return true
            return ( true );
        }























//  ****************************************************   TEMPLATE OR INLINE STATIC FUNCTIONS IMPLEMENTATION   ***********************************************


























//	*****************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************






















        // Method Information :
        //
        //  Description :
        //
        //      Use to create the array that should be looked up every time a mismatch between the pattern and the data occurs.
        //      The question is from where the search should continue when a mismtach happens. For this purpose, for every entry
        //      in the pattern, the longest subpattern that matches a subpattern with the same size only that starts at the beginning
        //      must be found, if it exist, and then if a mismatch with the data happens in the entry, then the length of the
        //      subpattern must be backed, and the search should continue from there 
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
        void SearchArray< TYPE >::SetAdvanceDataIndexIMP()
        {
            // Create space to store the size of the array
            UnsignedInteger64bits patternSize = m_pattern.Size();

            // Set the first entry in the array to 1 for sake of convention
            m_advanceDataIndex[0] = 1;

            // Check if the pattern length is 1
            if ( patternSize == 1 )
            {
                // Pattern length is 1 then return control
                return;
            }

            // If the second entry of the pattern mismatch the data then the pointer on the data should just move to
            // the next entry
            m_advanceDataIndex[1] = 1;

            // Check if the pattern length is 2
            if ( patternSize == 2 )
            {
                // Pattern length is 2 then return control
                return;
            }

            // Create space to store the index on the set of entries
            UnsignedInteger64bits setOfEntriesIndex = 0;

            // Create space to store the length of the current set of entries size
            UnsignedInteger64bits entriesSetSize = 0;

            // Create space to contain the beginning index of the set of entries that has the end point fixed
            UnsignedInteger64bits setOfEntriesWithEndPointFixedBeginningIndex = 1;

            // Loop starting from third entry until the pattern is exhausted 
            for ( UnsignedInteger64bits patternIndex = 2 ; patternIndex < patternSize ; ++patternIndex )
            {
                // Set the beginning index of the set of entries that has the end point fixed to 1
                setOfEntriesWithEndPointFixedBeginningIndex = 1;

                // Loop on all the entries before the current entry in the pattern, starting from the second entry
                for ( entriesSetSize = ( patternIndex - 1 ) ; entriesSetSize >= 1 ; --entriesSetSize, ++setOfEntriesWithEndPointFixedBeginningIndex )
                {

                    // Check if the current entry is identical to the first entry
                    if ( m_pattern[0] == m_pattern[ setOfEntriesWithEndPointFixedBeginningIndex ] )
                    {
                        // The first entries are the same

                        // Loop on the subpattern, and check if all the rest of it also matches the subpattern that starts from the
                        // beginning of the pattern
                        for ( setOfEntriesIndex = 0 ; setOfEntriesIndex < entriesSetSize ; ++setOfEntriesIndex )
                        {

                            // Check if current characters in both subpattern are equal
                            if ( m_pattern[ setOfEntriesIndex ] != m_pattern[ setOfEntriesWithEndPointFixedBeginningIndex + setOfEntriesIndex ] )
                            {
                                // The two characters are different break the loop
                                break;
                            }

                        }

                        // Check if the loop passed on all th set entries, which means that a match was found
                        if ( setOfEntriesIndex == entriesSetSize )
                        {
                            // A match between sets was found

                            // This means that the index on data should advance the number of entries before the current pattern index
                            // subtracted by the set entries size
                            m_advanceDataIndex[ patternIndex ] = ( ( patternIndex - 1 ) - entriesSetSize );

                            // The longest match was found for current entry in the pattern, advance to the next entry
                            break;
                        }

                    }

                }

                // Check if the entries set size is 0, which means no match was found
                if ( entriesSetSize == 0 )
                {
                    // No match was found, then all the current data should not be checked again and the search should advance the size
                    // of entries that were already looked for in current search of pattern in data
                    m_advanceDataIndex[ patternIndex ] = patternIndex;
                }

            }

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
    	        void Search< TYPE >::Test() throw( std::bad_alloc, Exception )
    			{
                    // Test the constructors, and destructors :

                    // Test the default constructor
                    SearchArray< Encoding::AsciiString > testSearchArray_1;

                    // Check that the instnace is at default state
                    ErrorHandling::Assert::True( testSearchArray_1.DefaultState(), "SearchArray::Test failed - the default constructor does not work correctly" );

                    // Test the parametrized constructor
                    SearchArray< Encoding::AsciiString > testSearchArray_2( RawDataToContainer::RawAsciiStringToAsciiStringObject( "Lona" ) );

                    // Check if the pattern appear in the text
                    ErrorHandling::Assert::True( ( testSearchArray_2.FirstApperance( RawDataToContainer::RawAsciiStringToAsciiStringObject( "jnvjnvjfnjaLonandjvnjvnj" ) ) == 11 ), "SearchArray::Test failed - the pattern Lona was not found and it does exist" );
                
                    // Test the parametrized constructor
                    SearchArray< Encoding::AsciiString > testSearchArray_3( "a", 1 );

                    // Check if the pattern appear in the text
                    ErrorHandling::Assert::True( ( testSearchArray_3.FirstApperance( RawDataToContainer::RawAsciiStringToAsciiStringObject( "jnvjnvjfnjaLonandjvnjvnj" ) ) == 10 ), "SearchArray::Test failed - the pattern Lona was not found and it does exist" );

                    // Test the parametrized constructor
                    SearchArray< Encoding::AsciiString > testSearchArray_4( RawDataToContainer::RawAsciiStringToAsciiStringObject( "Lona23" ) );

                    // Check if the pattern appear in the text
                    ErrorHandling::Assert::True( ( testSearchArray_4.FirstApperance( RawDataToContainer::RawAsciiStringToAsciiStringObject( "jnvjnvjfnjaLona23ndjvnjvnj" ) ) == 11 ), "SearchArray::Test failed - the pattern Lona was not found and it does exist" );
                }

            )  //  End of debug tool


        }















    }  //  Namespace GeneralPurposeContainers

}  //  Namespace Universe



#endif  // SEARCH_HPP