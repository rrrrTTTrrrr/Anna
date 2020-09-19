#ifndef TESTFUNCTOROBJECT_1_HPP
#define TESTFUNCTOROBJECT_1_HPP


#include <iostream>  //  Class std::cout, Class std::endl


#include "../../../../Root/Level_0/Level_1/Level_2/Level_3/Content/InvokableObjects/CommonFunctionality/Functor_Interface/Functor_Interface.hpp"  //  Class Functor_Interface
#include "../../../../Root/Level_0/Level_1/Level_2/Level_3/Content/BindObjects/Tuple/Tuple.hpp"  //  Class Tuple


namespace Universe
{


    // When a type is forward declared, all the compiler knows is that this type exists. It does not know its size, members or methods. This is why its
	// called incomplete type. Therefore, it can not be used to declare a variable, member or base class since the compiler would need the layout of the
	// type. In other words, it can not be used for anything that requires information on the specific type. What can be done is declaring pointer and
	// reference to the incomplete type. The pointer and refernce can act as a variable, argument to a method or as the return type.
	//
	// Forward declarations :
	//
	//  NONE
	//


	namespace Testing
    {


		// Template Class Information :
		//
		//  Purpose :
		//
		//		Artifical Inteligence
		//
		//  Description :
		//
		//		1. This object contains an instance of the object "InstanceState" to allow each instance of this object to have a defined state
		//
		// 		2. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
		//		   providing 3 keywords :
		//
		//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
		//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
		//						member is public all the encapsulation is lost, so it should be avoided in most cases
		//
		//			2. Protected - this part is for developing purposes, inheritance. A software developer can inherit from this object and it will
		//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
		//						   data members
		//
		//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
		//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
		//						 part will end with the suffix __Private
		//
		//		3. Template arguments :
		//
		//			1. Type -
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		template< typename Type, typename ReturnValueType, typename... FunctorArgumentTypes >
		class TestFunctorObject_1 : public Functor_Interface< ReturnValueType, FunctorArgumentTypes... >
		{
		public:


			// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
			// the compiler generates a basic behavior for them if possible :


			// Method Information :
			//
			//  Description :
			//
			//		Constructor,
			//
			//  Required arguments :
			//
 			//		User information needed :
			//
 			//			NONE
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			explicit inline TestFunctorObject_1( UnsignedInteger64bits size );


			// Method Information :
			//
			//  Description :
			//
			//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
			//
			//  Required arguments :
			//
		    //		User information needed :
			//
			//			other - a reference to the instance that should be copied
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			inline TestFunctorObject_1( const TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >& other );


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
			//			other - a reference to the instance that should be swaped
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//      NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//      They will come
			//
			inline void Swap( TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >& other );


			// Method Information :
			//
			//  Description :
			//
			//		Destructor, does not throw
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			NONE
			//
			//      Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		NONE
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual ~TestFunctorObject_1();


			// The following methods declare the overloaded operators for the object :


			// Method Information :
			//
			//  Description :
			//
			//		The purpose of this method is to allow an instance of the object that will implement it, to be called as if it were a function
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			arguments - any argument the object that will implement this operator will need
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		Any return value needed by the implementing object
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual ReturnValueType operator()( FunctorArgumentTypes... arguments ) override;


			// Method Information :
			//
			//  Description :
			//
			//		The purpose of this method is to allow an instance of the object that will implement it, to be called as if it were a function
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			arguments - any argument the object that will implement this operator will need
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		Any return value needed by the implementing object
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual ReturnValueType operator()( FunctorArgumentTypes... arguments ) const;


			// Method Information :
			//
			//  Description :
			//
			//      Use this operator to invoke the functor pointed to be this instance, using a tuple of arguments. This operator will give instances of
			//		this object the ability to be used as if they are functions. Now to invoke a function using a tuple, the syntax is as follows :
		    //
		    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
		    //
		    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
		    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the function :
		    //
		    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
		    //
		    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
		    //		invoke the functor
			//
			//  Required arguments :
			//
			//		User information needed :
			//
			//			arguments - a tuple containing the arguments required to invoke the functor
			//
			//		Information returned to the user :
			//
			//			NONE
			//
			//  Return value :
			//
			//		The return value from invoking the function will be returned
			//
			//  Expectations :
			//
			//		1. The instance should be ready
			//		2. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			virtual ReturnValueType operator()( const Tuple< FunctorArgumentTypes... >& arguments ) override;


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
	        //      A reference to the required object
	        //
			//  Expectations :
			//
			//		NONE
			//
	        //  Possible errors :
	        //
	        //		They will come
	        //
	        inline Type& operator[]( unsigned long index ) const;


		private :


			// This object will store an array allocated on the heap memory segment
			Type* member_array;

			// This object will store the array size
			UnsignedInteger64bits member_size;


		};  //  Class TestFunctorObject_1




































//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************





































		// Method Information :
		//
		//  Description :
		//
		//		Constructor,
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename Type, typename ReturnValueType, typename... FunctorArgumentTypes >
		inline TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >::TestFunctorObject_1( UnsignedInteger64bits size ) :
		member_array( new Type[ size ] ),
		member_size( size )
		{}


		// Method Information :
		//
		//  Description :
		//
		//		Copy constructor, will operate correctly even if the other instance is in default state or self assignment
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the instance that should be copied
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename Type, typename ReturnValueType, typename... FunctorArgumentTypes >
		inline TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >::TestFunctorObject_1( const TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >& other ) :
		member_array( new Type[ other.member_size ] ),
		member_size( other.member_size )
		{

			for ( UnsignedInteger64bits index = 0UL ; index < member_size ; ++index )
			{
				member_array[ index ] = other.member_array[ index ];
			}

		}


		// Method Information :
		//
		//  Description :
		//
		//		This method is used to swap the content between this instance and the other one
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			other - a reference to the instance that should be swaped
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename Type, typename ReturnValueType, typename... FunctorArgumentTypes >
		inline void TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >::Swap( TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >& other )
		{
			// Swap the memory address
			Type* otherMemoryAddressCopy = other.member_array;
			other.member_array = member_array;
			member_array = otherMemoryAddressCopy; 

			// Swap the size
			unsigned long otherSizeCopy = other.member_size;
			other.member_size = member_size;
			member_size = otherSizeCopy; 
		}


		// Method Information :
		//
		//  Description :
		//
		//		Destructor, does not throw
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			NONE
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		NONE
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename Type, typename ReturnValueType, typename... FunctorArgumentTypes >
		inline TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >::~TestFunctorObject_1()
		{

			if ( member_array == 0UL )
			{
		    	delete[] member_array;
		    }

		}






























//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************


































		// Method Information :
		//
		//  Description :
		//
		//		The purpose of this method is to allow an instance of the object that will implement it, to be called as if it were a function
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - any argument the object that will implement this operator will need
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		Any return value needed by the implementing object
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename Type, typename ReturnValueType, typename... FunctorArgumentTypes >
		ReturnValueType TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >::operator()( FunctorArgumentTypes... arguments )
		{
			// Create a tuple to store the function arguments, and to allow accesing each one of them seperatly
			Tuple< FunctorArgumentTypes... >  argumentsTuple( arguments... );

			// Set the required member array entry with the current value
			member_array[ argumentsTuple.template Entry< 1 >() ] = argumentsTuple.template Entry< 0 >();

			// Return false to keep the loop of the for each going
			return ( false );
		}


		// Method Information :
		//
		//  Description :
		//
		//		The purpose of this method is to allow an instance of the object that will implement it, to be called as if it were a function
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - any argument the object that will implement this operator will need
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		Any return value needed by the implementing object
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename Type, typename ReturnValueType, typename... FunctorArgumentTypes >
		ReturnValueType TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >::operator()( FunctorArgumentTypes... /*arguments*/ ) const
		{
			// // Create a tuple to store the function arguments, and to allow accesing each one of them seperatly
			// Tuple< FunctorArgumentTypes... >  argumentsTuple( arguments... );

			// // Set the required member array entry with the current value
			// member_array[ argumentsTuple.template Entry< 1 >() ] = argumentsTuple.template Entry< 0 >();

			// Return false to keep the loop of the for each going
			return ( false );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this operator to invoke the functor pointed to be this instance, using a tuple of arguments. This operator will give instances of
		//		this object the ability to be used as if they are functions. Now to invoke a function using a tuple, the syntax is as follows :
	    //
	    //				MethodSomething( tupleInstance.Entry< 0 >(), tupleInstance.Entry< 1 >(), tupleInstance.Entry< 2 >() );
	    //
	    //      To avoid writing all the arguments by hand, parameter pack expansion exist. To use it an integer sequence needs to be passed to the function. 
	    //		This sequence will be used to unpack the tuple of arguments, and allow an easy invoke of the function :
	    //
	    //				MethodSomething( tupleInstance.Entry< INTEGERS >() );
	    //
	    //		Then this method is just a wrapper to the method the receives the integer sequence as an argument and perform the expansion pack, and then
	    //		invoke the functor
		//
		//  Required arguments :
		//
		//		User information needed :
		//
		//			arguments - a tuple containing the arguments required to invoke the functor
		//
		//		Information returned to the user :
		//
		//			NONE
		//
		//  Return value :
		//
		//		The return value from invoking the function will be returned
		//
		//  Expectations :
		//
		//		1. The instance should be ready
		//		2. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename Type, typename ReturnValueType, typename... FunctorArgumentTypes >
		ReturnValueType TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >::operator()( const Tuple< FunctorArgumentTypes... >& arguments )
		{
			// Set the required member array entry with the current value
			member_array[ arguments.template Entry< 1 >() ] = arguments.template Entry< 0 >();

			// Return false to keep the loop of the for each going
			return ( false );
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
        //      A reference to the required object
        //
		//  Expectations :
		//
		//		NONE
		//
        //  Possible errors :
        //
        //		They will come
        //
		template< typename Type, typename ReturnValueType, typename... FunctorArgumentTypes >
        inline Type& TestFunctorObject_1< Type, ReturnValueType, FunctorArgumentTypes... >::operator[]( unsigned long index ) const
        {
        	// Return a reference to the entry
        	return ( member_array[ index ] );
        }





    }  //  Namespace Testing

}  //  Namespace Universe



#endif  // TESTFUNCTOROBJECT_1_HPP