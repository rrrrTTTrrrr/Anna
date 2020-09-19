#ifndef  BASICTYPESUSEORDERWITHNODUPLICATIONS_H
#define  BASICTYPESUSEORDERWITHNODUPLICATIONS_H



#include "../../../../GeneralPurposeContainers/LinkedList/DoubleLinkedList/BasicTypesDoubleLinkedList/BasicTypesDoubleLinkedList.hpp"  //  Class BasicTypesDoubleLinkedList



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
    	//      This class stores the order the given objects were used. The same object does not
        //      appear twice in the list, and only the last use of the object appears
    	//
   	    //  Description :
   	    //
  	    //      There is no exception specification on purpose. The reason is that when working with templates, the given type of the template
   	    //      can overload and override any operator and method, and therefore throw anything it see fit. This causes the problem, there is
  	    //      no way of knowing what the given type throws. The only method declared with exception specification is the destructor, which should
        //      not throw any exception anyhow, to prevent throwing an exception while another exception is active. This will cause the
    	//      program toend
        //
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename TYPE >
        class BasicTypesUseOrderWithNoDuplications
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
    		explicit inline BasicTypesUseOrderWithNoDuplications();


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
    		BasicTypesUseOrderWithNoDuplications( const BasicTypesUseOrderWithNoDuplications< TYPE >& other );


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
    		BasicTypesUseOrderWithNoDuplications< TYPE >& operator=( const BasicTypesUseOrderWithNoDuplications< TYPE >& other );


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
    		BasicTypesUseOrderWithNoDuplications( BasicTypesUseOrderWithNoDuplications< TYPE >&& other );


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
    		BasicTypesUseOrderWithNoDuplications< TYPE >& operator=( BasicTypesUseOrderWithNoDuplications< TYPE >&& other );


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
    		inline ~BasicTypesUseOrderWithNoDuplications() throw();


    		// To support Move semantics, the following 3 methods are added to every object. One method to set
    		// the object into the default state, another to check if the object is in the default state,
    		// and the last method to delete all the object resources :


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
    		void SetToDefaultState();


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
    		bool DefaultState() const;


    		// Method Information :
    		//
    		//  Description :
    		//
    		//      Use to delete the resources and set the object to default state. Note - if the object is in 
    		//		default state the method do nothing
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
    		void DeleteResourcesAndSetToDefaultState();


    		// The following methods are the interface of the object. This methods implement the
    		// capabilities of the object :


            // Method Information :
            //
            //  Description :
            //
            //      Use this to add an object to the use order list
            //
            //  Required arguments :
            //
            //      User information needed :
            //
            //          usedObject - a used object, that should be added to the use order list
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
            inline void AddUsedObject( TYPE usedObject );


            // Method Information :
            //
            //  Description :
            //
            //      Use this to get the object that was not used for the longest
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
            //      The object that was not used for the longest
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2.
            //
            inline TYPE GetLongestUnusedObject();


            // Method Information :
            //
            //  Description :
            //
            //      Use this to get the object that was not used for the longest, and remove it from the use order list
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
            //      The object that was not used for the longest
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2.
            //
            inline TYPE GetLongestUnusedObjectAndRemoveIt();


            // Method Information :
            //
            //  Description :
            //
            //      Use this to get the object that was used most recently
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
            //      The object that was used most recently
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2.
            //
            inline TYPE GetTheLastUsedObject();


            // Method Information :
            //
            //  Description :
            //
            //      Use this to get the object that was used most recently, and remove it from the use order list
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
            //      The object that was used most recently
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2.
            //
            inline TYPE GetTheLastUsedObjectAndRemoveIt();


            // Method Information :
            //
            //  Description :
            //
            //      Use this to get the number of entries in the use order list
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
            //      The number of entries in the use order list
            //
            //  Possible errors :
            //
            //      1. The object is in default state - class Exception is thrown
            //      2.
            //
            inline UnsignedInteger64bits GetSize() const;
            

    		// The following methods declare the overloaded operators for the object :


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
            void Test();

    	private:


            // This object will store the use order list
            BasicTypesDoubleLinkedList< TYPE > m_useOrderList;


            // Friend class or friend function can access private and protected members of other class in which it is declared as friend.
            // It is sometimes useful to allow a particular class to access private members of other class. The declration of such function
            // is private, because these functions are part of the implemntation, which the user should not be aware of. Furthermore the
            // use of this functions is not limited to the class's scope. The following declarations are for all the function that should
            // be friends with this class :


        };  //  Class BasicTypesUseOrderWithNoDuplications

















//  **************************************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   *************************************************************

















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
    	inline BasicTypesUseOrderWithNoDuplications< TYPE >::BasicTypesUseOrderWithNoDuplications() :
        m_useOrderList()
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
    	inline BasicTypesUseOrderWithNoDuplications< TYPE >::BasicTypesUseOrderWithNoDuplications( const BasicTypesUseOrderWithNoDuplications< TYPE >& other ) :
        m_useOrderList( other.m_useOrderList )
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
    	BasicTypesUseOrderWithNoDuplications< TYPE >& BasicTypesUseOrderWithNoDuplications< TYPE >::operator=( const BasicTypesUseOrderWithNoDuplications< TYPE >& other )
    	{

    		// Check that this is not self assignment
    		if ( this != &other )
    		{
    			// This is not self assignment

    			// Check if the other object is in default state
    			if ( true == other.DefaultState() )
    			{
    				// The other object is in default state

                    // Release all the resources of this object
                    DeleteResourcesAndSetToDefaultState();

    				// Nothing else needs to be done, return a reference to this object
    				return ( *this );
    			}

    			// Copy the other object resources

                // Copy the use order list 
                m_useOrderList = other.m_useOrderList;
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
    	BasicTypesUseOrderWithNoDuplications< TYPE >::BasicTypesUseOrderWithNoDuplications( BasicTypesUseOrderWithNoDuplications< TYPE >&& other ) :
        m_useOrderList( other.m_useOrderList )
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
    	BasicTypesUseOrderWithNoDuplications< TYPE >& BasicTypesUseOrderWithNoDuplications< TYPE >::operator=( BasicTypesUseOrderWithNoDuplications< TYPE >&& other )
    	{

    		// Check that this is not self assignment
    		if ( this != &other )
    		{
    			// This is not self assignment

    			// Check if the other object is in default state
    			if ( true == other.DefaultState() )
    				{
    				// The other object is in default state

                    // Release all the resources of this object
                    DeleteResourcesAndSetToDefaultState();

    				// Nothing else needs to be done, return a reference to this object
    				return ( *this );
    			}

    			// Take the other object resources

                // Take the use order list 
                m_useOrderList = other.m_useOrderList;

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
        inline BasicTypesUseOrderWithNoDuplications< TYPE >::~BasicTypesUseOrderWithNoDuplications() throw()
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
    	void BasicTypesUseOrderWithNoDuplications< TYPE >::SetToDefaultState()
        {
            // Set the single linked list containing the use order to default state
            m_useOrderList.SetToDefaultState();
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
    	bool BasicTypesUseOrderWithNoDuplications< TYPE >::DefaultState() const
    	{

    		// Check if the object is in default state
    		if ( true == m_useOrderList.DefaultState() )
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
    	//      Use to delete the resources and set the object to default state. Note - if the object is in 
    	//		default state the method do nothing
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
    	void BasicTypesUseOrderWithNoDuplications< TYPE >::DeleteResourcesAndSetToDefaultState()
    	{
            // Check that this object is not in default state, then nothing needs to be done
            RETURN_IF_EXPRESSION_IS_TRUE( DefaultState() )

    		// Release the resources of this object

            // Delete the resources of the single linked list containing the use order list
            m_useOrderList.DeleteResourcesAndSetToDefaultState();
    	}


        // Method Information :
        //
        //  Description :
        //
        //      Use this to get the number of entries in the use order list
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
        //      The number of entries in the use order list
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2.
        //
        template< typename TYPE >
        inline UnsignedInteger64bits BasicTypesUseOrderWithNoDuplications< TYPE >::GetSize() const
        {
            // Return the number of entries in the use order list
            return ( m_useOrderList.GetSize() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this to add an object to the use order list
        //
        //  Required arguments :
        //
        //      User information needed :
        //
        //          usedObject - a used object, that should be added to the use order list
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
        inline void BasicTypesUseOrderWithNoDuplications< TYPE >::AddUsedObject( TYPE usedObject )
        {

            // Check if the object is in default state
            if ( true == DefaultState() )
            {
                // The object is in default state

                // Add the used object to the use order list
                m_useOrderList.PushHead( usedObject );                
            }
            else
            {
                // There can be no duplications, therefore a pass must be made to remove any duplications from the list.
                // Only the last use is recorded. Because every time an object is added to the use order list, all the
                // duplications are deleted, there can only be 1 copy of it in the use order list, then if 1 appearance
                // is found and removed the search can end
                m_useOrderList.RemoveFirstApperance( usedObject );

                // Add the used object to the use order list
                m_useOrderList.PushHead( usedObject );
            }

        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this to get the object that was not used for the longest
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
        //      The object that was not used for the longest
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2.
        //
        template< typename TYPE >
        inline TYPE BasicTypesUseOrderWithNoDuplications< TYPE >::GetLongestUnusedObject()
        {
            // Return the object that was not used for the longest
            return ( m_useOrderList.GetTailData() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this to get the object that was not used for the longest, and remove it from the use order list
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
        //      The object that was not used for the longest
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2.
        //
        template< typename TYPE >
        inline TYPE BasicTypesUseOrderWithNoDuplications< TYPE >::GetLongestUnusedObjectAndRemoveIt()
        {
            // Return the object that was not used for the longest and remove the node that contain it 
            return ( m_useOrderList.PopTailAndGetTheDataInside() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this to get the object that was used most recently
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
        //      The object that was used most recently
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2.
        //
        template< typename TYPE >
        inline TYPE BasicTypesUseOrderWithNoDuplications< TYPE >::GetTheLastUsedObject()
        {
            // Return the object that was not used for the longest
            return ( m_useOrderList.GetHeadData() );
        }


        // Method Information :
        //
        //  Description :
        //
        //      Use this to get the object that was used most recently, and remove it from the use order list
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
        //      The object that was used most recently
        //
        //  Possible errors :
        //
        //      1. The object is in default state - class Exception is thrown
        //      2.
        //
        template< typename TYPE >
        inline TYPE BasicTypesUseOrderWithNoDuplications< TYPE >::GetTheLastUsedObjectAndRemoveIt()
        {
            // Return the object that was not used for the longest and remove the node that contain it 
            return ( m_useOrderList.PopHeadAndGetTheDataInside() );
        }























//  ***************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************
































//  **************************************************************   PRIVATE METHODS IMPLEMENTATION   ****************************************************************************

























// ***************************************************************   NESTED CLASS IMPLEMENTATION -    ****************************************************************************


























// ***************************************************************************   TESTING   *************************************************************************************


















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
        void BasicTypesUseOrderWithNoDuplications< TYPE >::Test()
        {
            // Get an handle to the assert object
            ErrorHandling::Assert& assert = ErrorHandling::Assert::GetHandle();

            // Add an object to the use order list
            AddUsedObject( 99 );

            // Check that the size is 1
            assert.True( ( 1 != GetSize() ), "BasicTypesUseOrderWithNoDuplications::Test failed - the add used object method does not work correctly" );

            // Check that the object that was not used he longest is the same as the object that was used most recently because there is
            // only 1 object is the use order list
            assert.False( ( GetLongestUnusedObject() == GetTheLastUsedObject() ), "BasicTypesUseOrderWithNoDuplications::Test failed - the longest unused object is different from the object the was last used" );

            // Check that the get the longest unused object and remove it method works
            assert.False( ( GetLongestUnusedObjectAndRemoveIt() == 99 ), "BasicTypesUseOrderWithNoDuplications::Test failed - the get longest unused object and remove method does not work correctly" );

            // Check that the size is 0
            assert.True( ( 0 != GetSize() ), "BasicTypesUseOrderWithNoDuplications::Test failed - the get longest unused object and remove method did not change the size correctly" );

            // Add an object to the use order list
            AddUsedObject( 101 );

            // Check that the size is 1
            assert.True( ( 1 != GetSize() ), "BasicTypesUseOrderWithNoDuplications::Test failed - the add used object method does not work correctly" );

            // Check that the object that was not used he longest is the same as the object that was used most recently because there is
            // only 1 object is the use order list
            assert.False( ( GetLongestUnusedObject() == GetTheLastUsedObject() ), "BasicTypesUseOrderWithNoDuplications::Test failed - the longest unused object is different from the object the was last used" );

            // Check that the get the longest unused object and remove it method works
            assert.False( ( GetTheLastUsedObjectAndRemoveIt() == 101 ), "BasicTypesUseOrderWithNoDuplications::Test failed - the get last used object and remove method does not work correctly" );

            // Check that the size is 0
            assert.True( ( 0 != GetSize() ), "BasicTypesUseOrderWithNoDuplications::Test failed - the get last used object and remove method did not change the size correctly" );

            // Add some object to the use order list
            AddUsedObject( 77 );
            AddUsedObject( 66 );
            AddUsedObject( 55 );
            AddUsedObject( 66 );
            AddUsedObject( 101 );
            AddUsedObject( 302 );
            AddUsedObject( 42 );

            // Check that the size is 7
            assert.True( ( 6 != GetSize() ), "BasicTypesUseOrderWithNoDuplications::Test failed - the add used object method does not work correctly" );

            // Remove all the object from the use order list
            assert.False( ( GetLongestUnusedObjectAndRemoveIt() == 77 ), "BasicTypesUseOrderWithNoDuplications::Test failed - the get longest unused object and remove method does not work correctly" );

            // Check that the get the longest unused object and remove it method works
            assert.False( ( GetLongestUnusedObjectAndRemoveIt() == 55 ), "BasicTypesUseOrderWithNoDuplications::Test failed - the get longest unused object and remove method does not work correctly" );

            // Check that the get the longest unused object and remove it method works
            assert.False( ( GetLongestUnusedObjectAndRemoveIt() == 66 ), "BasicTypesUseOrderWithNoDuplications::Test failed - the get longest unused object and remove method does not work correctly" );

            // Check that the get the longest unused object and remove it method works
            assert.False( ( GetLongestUnusedObjectAndRemoveIt() == 101 ), "BasicTypesUseOrderWithNoDuplications::Test failed - the get longest unused object and remove method does not work correctly" );

            // Check that the get the longest unused object and remove it method works
            assert.False( ( GetLongestUnusedObjectAndRemoveIt() == 302 ), "BasicTypesUseOrderWithNoDuplications::Test failed - the get longest unused object and remove method does not work correctly" );

            // Check that the get the longest unused object and remove it method works
            assert.False( ( GetLongestUnusedObjectAndRemoveIt() == 42 ), "BasicTypesUseOrderWithNoDuplications::Test failed - the get longest unused object and remove method does not work correctly" );
        }











    }  //  Namespace GeneralPurposeContainers

}  //  Namespace Universe



#endif  // BASICTYPESUSEORDERWITHNODUPLICATIONS_H