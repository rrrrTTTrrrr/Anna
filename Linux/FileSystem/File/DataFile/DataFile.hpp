#ifndef  DATAFILE_HPP
#define  DATAFILE_HPP



// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../ErrorHandling/Exception/Exception.hpp"  //  Class Exception
#endif


// When a function name ends with the suffix IMP, the function is not part
// of the object interface ( capabilities ), it only used as aid to the
// function that it is, implementing only spsecific part



namespace Universe
{

    namespace FileSystem
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
  	    //      There is no exception specification on purpose. The reason is that when working
    	//      with templates, the given type of the template can overload and override any operator
    	//      and method, and therefore throw anything it see fit. This causes the problem, there is
    	//      no way of knowing what the given type throws. The only method declared with exception
    	//      specification is the destructor, which should not throw any exception anyhow, to prevent
    	//      throwing an exception while another exception is active. This will cause the program to end
    	//
    	//
    	//
    	//  Possible errors :
    	//
    	//
    	//
    	template< typename TYPE >
        class DataFile
        {
        private:


        	// Class Information :
    		//
    		//  Purpose :
    		//
    		// 		Usually proxies are used without the knowledge of the user, it acts as middle gate. This allows to postpone the decision, until more
    		//		information is received. For example, the operator square brackets "[]", if used on a pointer return the value inside the address the
    		//		pointer point to, or in other words a reference to the object pointed be the pointer. Now if an array is shared among multiple instances
    		//		and each should create a private copy every time a write operation needs to take place, then every time the operator square brackets "[]"
    		//		is used there is no way if an assignment or comparison for example needs to take place on the given reference. Then knowing the reason for
    		//		calling the square brackets operator is very important. Proxies are used in this cases, where the required operation that should take place
    		//		requires more information
    		//
   	    	//  Description :
   	    	//
    		//      There is no exception specification on purpose. The reason is that when working with templates, the given type of the template
    		//      can overload and override any operator and method, and therefore throw anything it see fit. This causes the problem, there is
    		//      no way of knowing what the given type throws. The only method declared with exception specification is the destructor, which should
    		//      not throw any exception anyhow, to prevent throwing an exception while another exception is active. This will cause the
    		//      program to end. And this class is nested within a template class, which means that the template type affect it too
    		//
    		//  Possible errors :
    		//
    		//
    		//
    		class DataFileProxy;


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
    		explicit inline DataFile();


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
    		explicit DataFile();


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
    		DataFile( const DataFile< TYPE >& other );


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
    		DataFile( DataFile< TYPE >&& other );


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
    		inline ~DataFile() throw();


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
    		void DeleteResourcesAndSetToDefaultState();


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


    		// Static data members do not belong to any instnace, it belongs to the class. Like every global variable
    		// it is created with the start of the program and only destroyed when the program ends. This means that
    		// each member method can use the static data members, but not functions outside the object's scope. It
    		// restricts the access to this object use only, but rather then that acts as global variable


    		// The following methods are private. This means that only public or protected methods can use them, in other
    		// words they not part of the interface, but rather help implement it :


    		// Method Information :
    		//
    		//  Description :
    		//
    		//		The main resource inside this object is shared among more then 1 instance. When a write operation
    		//		needs to take place, the number of instances using the resource must be checked. If only this instance
    		//		uses the resource then there are no problems and the write operation can take place. If there is more
    		//		then one instance using the resource then, the resource must be copied first, to prevent changing it
    		//		also for other instances. Only then the write operation can take place. This method then should be used
    		//		everytime before changes are made to the container
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
    		//      1. There is no more free space - class std::bad_alloc is thrown
    		//		2.
    		//
    		inline void CopyOnWriteIMP();


    		// Class Information :
    		//
    		//  Purpose :
    		//
    		// 		Usually proxies are used without the knowledge of the user, it acts as middle gate. This allows to postpone the decision, until more
    		//		information is received. For example, the operator square brackets "[]", if used on a pointer return the value inside the address the
    		//		pointer point to, or in other words a reference to the object pointed be the pointer. Now if an array is shared among multiple instances
    		//		and each should create a private copy every time a write operation needs to take place, then every time the operator square brackets "[]"
    		//		is used there is no way if an assignment or comparison for example needs to take place on the given reference. Then knowing the reason for
    		//		calling the square brackets operator is very important. Proxies are used in this cases, where the required operation that should take place
    		//		requires more information
    		//
   	    	//  Description :
   	    	//
    		//      1. There is no exception specification on purpose. The reason is that when working with templates, the given type of the template
    		//      can overload and override any operator and method, and therefore throw anything it see fit. This causes the problem, there is
    		//      no way of knowing what the given type throws. The only method declared with exception specification is the destructor, which should
    		//      not throw any exception anyhow, to prevent throwing an exception while another exception is active. This will cause the
    		//      program to end. And this class is nested within a template class, which means that the template type affect it too
    		//
    		//		2. The two operations of copying and moving this object are identical, therefore there is no need to support the both, and only copying
    		//		is supported. Furthermore, the assignment operator will not be used to copy one proxy to another, but it will be used to make the assignment
    		//		to the required entry in the proxy itself. To copy the proxy object only the copy constructor exist then, and all the operators are used
    		//		to work with the entries of the container currently in the proxy
    		//
    		//  Possible errors :
    		//
    		//
    		//
    		class DataFileProxy : private Unmoveable
        	{
        	public:


            	// The following methods are the basic methods for each object. How to create, destroy, copy
            	// and move the object. This methods if not declared the compiler generates a basic behavior
            	// for them :


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
    			//          1. dataFileObject - a reference to the object the proxy is nested within
    			//          2. entryIndex - the index of the required entry
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
    			explicit inline DataFileProxy( DataFile< TYPE >& dataFile, UnsignedInteger64bits entryIndex );


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
    			inline DataFileProxy( const DataFileProxy& other );


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
    			inline ~DataFileProxy() throw();


    			// The following methods are the interface of the object. This methods implement the
    			// capabilities of the object :











    			// The following methods declare the overloaded operators for the object :




    		private:


    			// This object will store a reference to the outer object
    			DataFile< TYPE >& m_dataFileObject;

    			// This object will store the required entry index
    			UnsignedInteger64bits m_entryIndex;


    		// Friend class or friend function can access private and protected members of other class in which it is declared as friend.
    			// It is sometimes useful to allow a particular class to access private members of other class. The declration of such function
    			// is private, because these functions are part of the implemntation, which the user should not be aware of. Furthermore the
    			// use of this functions is not limited to the class's scope. The following declarations are for all the function that should
    			// be friends with this class :




    		};  //  Class DataFileProxy


    	// Friend class or friend function can access private and protected members of other class in which it is declared as friend.
    			// It is sometimes useful to allow a particular class to access private members of other class. The declration of such function
    			// is private, because these functions are part of the implemntation, which the user should not be aware of. Furthermore the
    			// use of this functions is not limited to the class's scope. The following declarations are for all the function that should
    			// be friends with this class :




    		};  //  Class DataFile













//	**************************************   END PART OF DECLRATIONS, IMPLMENTATION TIME   ************************************









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
    	template< typename TYPE >
    	DataFile< TYPE >::DataFile() :


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
    	DataFile< TYPE >::DataFile( const DataFile< TYPE >& other ) :


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
    	DataFile< TYPE >& DataFile< TYPE >::operator=( const DataFile< TYPE >& other )
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
    	DataFile< TYPE >::DataFile( DataFile< TYPE >&& other ) :
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
    	DataFile< TYPE >& DataFile< TYPE >::operator=( DataFile< TYPE >&& other )
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

    	// Set the object to default state
    		SetToDefaultState();
    	}










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
    		}













//  ****************************************************   TEMPLATE OR INLINE STATIC FUNCTIONS IMPLEMENTATION   ***********************************************










    	//	*****************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************










// Method Information :
    	//
    	//  Description :
    	//
    	//		The main resource inside this object is shared among more then 1 instance. When a write operation
    	//		needs to take place, the number of instances using the resource must be checked. If only this instance
    	//		uses the resource then there are no problems and the write operation can take place. If there is more
    	//		then one instance using the resource then, the resource must be copied first, to prevent changing it
    	//		also for other instances. Only then the write operation can take place. This method then should be used
    	//		everytime before changes are made to the container
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
    	//      1. There is no more free space - class std::bad_alloc is thrown
    	//		2.
    	//
    	template< typename TYPE >
    	inline void DataFile< TYPE >::CopyOnWriteIMP()
    	{
    		// Check if only this instance uses the shared resource
    		RETURN_IF_THE_VALUES_ARE_EQUAL( 1, .GetNumberOfReferencesToSharedResource() )

    		// More then 1 instance uses the shared resource, Create a new copy of the resource

    	}











// *****************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ******************************************************** 











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
    	//          1. dataFile - a reference to the object the proxy was created for
    	//          2. entryIndex - the index of the required entry
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
        inline DataFile< TYPE >::DataFileProxy::DataFileProxy( DataFile< TYPE >& dataFile, UnsignedInteger64bits entryIndex ) :
    	m_dataFileObject( dataFile ),
    	m_entryIndex( entryIndex )
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
        inline DataFile< TYPE >::DataFileProxy::DataFileProxy( const DataFileProxy< O >& other ) :
    	m_dataFileObject( other.m_dataFileObject ),
    	m_entryIndex( other.entryIndex )
    	{}


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
        inline DataFile< TYPE >::DataFileProxy::~DataFileProxy() throw()
{}














// *******************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   **************************************************************












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
    )








    }  //  Namespace namespace

}  //  Namespace Universe



#endif  // DATAFILE_HPP