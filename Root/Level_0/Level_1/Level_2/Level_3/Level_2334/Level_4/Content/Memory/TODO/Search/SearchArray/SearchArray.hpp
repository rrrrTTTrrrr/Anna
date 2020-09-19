#ifndef  SEARCHARRAY_HPP
#define  SEARCHARRAY_HPP


#include "../Search/Search.hpp"  //  Class search

// The following includes represent the supported array containers
#include "../../Array/BasicTypes/BasicTypesArray/BasicTypesArray.hpp"  //   Class BasicTypesArray
#include "../../Array/BasicTypes/BasicTypesFixedSizeArray/BasicTypesFixedSizeArray.hpp"  //   Class BasicTypesFixedSizeArray
#include "../../Array/Objects/ObjectsArray/ObjectsArray.hpp"  //   Class ObjectsArray
#include "../../Array/Objects/ObjectsFixedSizeArray/ObjectsFixedSizeArray.hpp"  //   Class ObjectsFixedSizeArray


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
        // with byte order in memory


        // To support move semantics every class must provide a default state. This state
        // will be used to notify that resources were taken from current instance by
        // a move operation :
        //
        //
        // When the object is in this state it should not be used ( the object is empty )


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
        //      Use this class to chack if a pattern exist in a data contained as an array container object. Furthermore it can also provide
        //      reference to all the apperances of the pattern in the data
        //
        //  Description :
        //
        //      There is no exception specification on purpose. The reason is that when working with templates, the given type of the template
        //      can overload and override any operator and method, and therefore throw anything it see fit. This causes the problem, there is
        //      no way of knowing what the given type throws. The only method declared with exception specification is the destructor, which should
        //      not throw any exception anyhow, to prevent throwing an exception while another exception is active. This will cause the
        //      program to end
        //
        //  Possible errors :
        //
        //
        //
        template< typename TYPE >
        class SearchArray : public Search< TYPE >
        {
        public:


            // The following methods are the basic methods for each object. How to create, destroy, copy
            // and move the object. This methods if not declared the compiler generates a basic behavior
            // for them :


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
            explicit inline SearchArray();


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
            //          pattern - a reference to a container object
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
            //      1. There is no more free memory space - class std::bad_alloc is thrown
            //      2. 
            //
            explicit inline SearchArray( const TYPE& pattern );


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
            inline SearchArray( const SearchArray< TYPE >& other );


            // Method Information :
            //
            //  Description :
            //
            //      Assignment operator, can handle with self assignment. Will operate correctly even if the other object is in default state
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
            SearchArray< TYPE >& operator=( const SearchArray< TYPE >& other );


            // Method Information :
            //
            //  Description :
            //
            //      Move constructor, takes the resources from the other object ( rvalue reference ), and set it to
            //      the default state. Will operate correctly even if the other object is in default state
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
            inline SearchArray( SearchArray< TYPE >&& other );


            // Method Information :
            //
            //  Description :
            //
            //      Move Assignment operator, can handle with self assignment. takes the resources from the
            //      other object ( rvalue reference ), and set it to the default state. will operate correctly
            //      even if the other object is in default state
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
            SearchArray< TYPE >& operator=( SearchArray< TYPE >&& other );


            // Method Information :
            //
            //  Description :
            //
            //      Destructor,
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
            inline ~SearchArray() throw();


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
            //      Use to delete the object resources and set the object to default state. Note - if the object is in default
            //      state the method do nothing
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
            virtual inline void DeleteResourcesAndSetToDefaultState();


            // The following part of the interface was inhertid from the search object, and needs to be implemented. The methods
            // are virtual, if the base class has a virtual method the same method in a derived object is automatically virtual,
            // and all this methods were declared pure virtual in the base class :


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
            virtual inline void SetNewPattern( const TYPE& newPattern );


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
            virtual UnsignedInteger64bits FirstApperance( const TYPE& data );


            // Method Information :
            //
            //  Description :
            //
            //      Use to get the offset to the first appearance of the pattern in the data. Important note - the size of the
            //      given array with the offsets must be checked, and if it is 0 then the pattern does not exist in the data
            //      even once
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          1. data - the address of the data that the pattern should be searched in
            //          2. dataSize - the size of the data that the pattern should be searched in
            //
            //      Information returned to the user :
            //
            //          NONE
            //
            //  Return value :
            //
            //      1. If the pattern exist in the data - The offsets to all of the apperances of the pattern in the data
            //      2. If the pattern does not exist in the data even once - the size of the returned array will be 0
            //
            //  Possible errors :
            //
            //      1. The object is in default state
            //      2. There is no more free memory space - class std::bad_alloc is thrown
            //      3. 
            //
            virtual BasicTypesArray< UnsignedInteger64bits > AllApperances( const TYPE& data );


            // The following methods declare the overloaded operators for the object :



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
                //      2. There is no more free memory space - class std::bad_alloc is thrown
                //      3. 
                //
                static void Test();


            )  //  End of debug tool


        private:




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
            virtual void CreateLookupTableWithTheReturnAmountIfCurrentEntryDoesNotMatchIMP();


        };  //  Class SearchArray


































//  ****************************************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ************************************************************































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
        template< typename TYPE >
        inline SearchArray< TYPE >::SearchArray() :
        Search< TYPE >()
        m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry()
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
        //          pattern - a reference to a container object
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
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2. 
        //
        template< typename TYPE >
        inline SearchArray< TYPE >::SearchArray( const TYPE& pattern ) :
        Search< TYPE >( pattern )
        m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry( pattern.Size(), 0 )
        {
            // Initialize the values to the array with the amount to back on the data, if a mismatch with the pattern occuers
            CreateLookupTableWithTheReturnAmountIfCurrentEntryDoesNotMatchIMP();
        }


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
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2. 
        //
        template< typename TYPE >
        inline SearchArray< TYPE >::SearchArray( const SearchArray< TYPE >& other ) :
        Search< TYPE >( other )
        m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry( other.m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry )
        {}



        // Method Information :
        //
        //  Description :
        //
        //      Assignment operator, can handle with self assignment. Will operate correctly even if the other object is in default state
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
        //      1. There is no more free memory space - class std::bad_alloc is thrown
        //      2. 
        //
        template< typename TYPE >
        SearchArray< TYPE >& SearchArray< TYPE >::operator=( const SearchArray< TYPE >& other )
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
                m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry = other.m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry;
            }

            // Return a reference to this object
            return ( *this );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Move constructor, takes the resources from the other object ( rvalue reference ), and set it to
        //      the default state. Will operate correctly even if the other object is in default state
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
        template< typename TYPE >
        inline SearchArray< TYPE >::SearchArray( SearchArray< TYPE >&& other ) :
        Search< TYPE >( other ),
        m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry( other.m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry )
        {
            // Set the other object to default state, this way it can't be used
            other.SetToDefaultState();
        }


        // Method Information :
        //
        //  Description :
        //
        //      Move Assignment operator, can handle with self assignment. takes the resources from the
        //      other object ( rvalue reference ), and set it to the default state. will operate correctly
        //      even if the other object is in default state
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
        template< typename TYPE >
        SearchArray< TYPE >& SearchArray< TYPE >::operator=( SearchArray< TYPE >&& other )
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
                m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry = other.m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry;

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
        //      Destructor,
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
        template< typename TYPE >
        inline SearchArray< TYPE >::~SearchArray() throw()
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
        template< typename TYPE >
        inline void SearchArray< TYPE >::SetToDefaultState()
        {
            // Set the base class containning the pattern to default state
            Search< TYPE >::SetToDefaultState();

            // Set the object containning the array with the back amount for every entry in the pattern to default state
            m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry.SetToDefaultState();
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
        template< typename TYPE >
        inline bool SearchArray< TYPE >::DefaultState() const
        {

            // Check if the object is in default state
            if ( ( Search< TYPE >::DefaultState() == true ) &&
                 ( m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry.DefaultState() == true ) )
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
        //      state the method do nothing
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
        inline void SearchArray< TYPE >::DeleteResourcesAndSetToDefaultState()
        {
            // Check if the object is in default state, then noting needs to be done
            RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

            // Release the resources of this object

            // Delete the resources of the object containning the pattern
            Search< TYPE >::DeleteResourcesAndSetToDefaultState();

            // Delete the resources of the object containning the array with the back amount for every entry in the pattern to default state
            m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry.DeleteResourcesAndSetToDefaultState();
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
        inline void SearchArray< TYPE >::SetNewPattern( const TYPE& newPattern )
        {
            // Set the new pattern to the basic types fixed size array
            Search< TYPE >::SetNewPattern( newPattern );

            // Set new size to lookup table array
            m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry.SetNewSize( newPattern.Size() );

            // Initialize the values to the array with the amount to back on the data, if a mismatch with the pattern occuers
            CreateLookupTableWithTheReturnAmountIfCurrentEntryDoesNotMatchIMP();
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

                        // The next location depends on the amount that should be backed, therefore add the value inside the array
                        // with back amount for every entry in the pattern, to the data index
                        dataIndex += m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry[ patternIndex ];

                        break;
                    }

                }

                // Check if the loop passed on all the pattern, which means that the pattern also exist in this location in the data
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
                        dataIndex += m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry[ patternIndex ];

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

            // Return the object with the offsets to the pattern in the data
            return ( apperances );
        }



























//  ***********************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   *******************************************






































//  **************************************************************   PRIVATE METHODS IMPLEMENTATION   ****************************************************************************






































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
        void SearchArray< TYPE >::CreateLookupTableWithTheReturnAmountIfCurrentEntryDoesNotMatchIMP()
        {
            // Create space to store the size of the array
            UnsignedInteger64bits patternSize = m_pattern.Size();

            // Set the first entry in the array to 1 for sake of convention
            m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry[0] = 1;

            // Check if the pattern length is 1
            if ( patternSize == 1 )
            {
                // Pattern length is 1 then return control
                return;
            }

            // If the second entry of the pattern mismatch the data then the pointer on the data should just move to
            // the next entry
            m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry[1] = 1;

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
                            m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry[ patternIndex ] = ( ( patternIndex - 1 ) - entriesSetSize );

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
                    m_backAmountIfCurrentEntryDoesNotMatchForEveryEntry[ patternIndex ] = patternIndex;
                }

            }

        }



























// ********************************************************************************   TESTING   *********************************************************************************































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
            //      2. There is no more free memory space - class std::bad_alloc is thrown
            //      3. 
            //
            template< typename TYPE >
            void SearchArray< TYPE >::Test()
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

















    }  //  Namespace GeneralPurposeContainers

}  //  Namespace Universe



#endif  // SEARCHARRAY_HPP