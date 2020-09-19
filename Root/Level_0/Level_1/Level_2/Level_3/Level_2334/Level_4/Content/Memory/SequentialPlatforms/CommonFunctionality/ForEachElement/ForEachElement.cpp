#ifndef  FOREACHELEMENT_CPP
#define  FOREACHELEMENT_CPP


#include "ForEachElement.hpp"


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#include "../../Array/Array.hpp"  //  Class Array
#include "../../DoubleLinkedList/DoubleLinkedList.hpp"  //  Class DoubleLinkedList
#include "../../../../../../../../../../TestBranch/TestingTools/Objects/TestFunctorObject_1/TestFunctorObject_1.hpp"  //  Class TestFunctorObject_1
#endif


namespace Universe 
{

    namespace Memory
    {


		// Forward declarations :
		//
		//  NONE
		//























// *********************************************************************************   TESTING   ********************************************************************************




































		DEBUG_TOOL(

			// Method Information :
			//
			//  Description :
			//
			//		This method is used to test the object. It is not part of the implementation, it is only used to find problem with the code that does implement
			//		the functionality
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
			//		1. true - if the object passed the test
			//		2. false - otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		1. An assertion failed - class Exception is thrown
			//		2. There is no more free memory space - class std::bad_alloc is thrown
			//		3. 
			//
			void ForEachElement::Test()
			{
				// Create an array instance
				Array< UnsignedInteger64bits COMMA 89UL > testArray_1( 89UL );

				// Add 2 for each element in the array
				Do< UnsignedInteger64bits >( testArray_1, FunctionPointer< Boolean, UnsignedInteger64bits&, UnsignedInteger64bits >( []( UnsignedInteger64bits& currentElement, UnsignedInteger64bits ) -> Boolean 
				{

					currentElement += 2UL;

					return ( false );

				} ) );

				// Verify that the for each operation was succesful
				Do< UnsignedInteger64bits >( testArray_1, FunctionPointer< Boolean, UnsignedInteger64bits&, UnsignedInteger64bits >( []( UnsignedInteger64bits& currentElement, UnsignedInteger64bits ) -> Boolean 
				{

					Assert_Test_MACRO( currentElement == 91UL )

					return ( false );

				} ) );

				// Create an array instance
				const Array< UnsignedInteger64bits COMMA 89UL > testArray_2( 6555UL );

				// Verify that the for each operation was succesful
				Do< UnsignedInteger64bits >( testArray_2, FunctionPointer< Boolean, const UnsignedInteger64bits&, UnsignedInteger64bits >( []( const UnsignedInteger64bits& currentElement, UnsignedInteger64bits ) -> Boolean 
				{

					Assert_Test_MACRO( currentElement == 6555UL )

					return ( false );

				} ) );

				// Create a type definition
				using TestFunctorObjectType = Testing::TestFunctorObject_1< UnsignedInteger64bits COMMA Boolean COMMA UnsignedInteger64bits& COMMA UnsignedInteger64bits >;

				// Create a type definition for constant sequential platform
				using TestConstantFunctorObjectType = Testing::TestFunctorObject_1< UnsignedInteger64bits COMMA Boolean COMMA const UnsignedInteger64bits& COMMA UnsignedInteger64bits >;

				// Create a test object instance
				TestConstantFunctorObjectType testFunctorObject_1( 89UL );

				// Set the contents of the arry into the test object instance
				Do< UnsignedInteger64bits >( testArray_2, FunctorInvoker< TestConstantFunctorObjectType COMMA Boolean COMMA const UnsignedInteger64bits& COMMA UnsignedInteger64bits >( testFunctorObject_1 ) );

				// Set the contents of the arry into the test object instance
				Do< UnsignedInteger64bits >( testArray_1, FunctorInvoker< TestFunctorObjectType COMMA Boolean COMMA UnsignedInteger64bits& COMMA UnsignedInteger64bits >( TestFunctorObjectType( 89UL ) ) );

				// Create an array instance
				DoubleLinkedList< UnsignedInteger64bits > testDoubleLinkedList_1 = MOVE( DoubleLinkedList< UnsignedInteger64bits >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits >( 50UL, 350UL ) ) );
				DoubleLinkedList< UnsignedInteger64bits > testDoubleLinkedList_2( testDoubleLinkedList_1 ); 

				// Add 2 for each element in the array
				Do< UnsignedInteger64bits >( testDoubleLinkedList_1, FunctionPointer< Boolean, UnsignedInteger64bits&, UnsignedInteger64bits >( []( UnsignedInteger64bits& currentElement, UnsignedInteger64bits ) -> Boolean 
				{

					currentElement += 2UL;

					return ( false );

				} ) );

				// Create an array instance
				const DoubleLinkedList< UnsignedInteger64bits > testDoubleLinkedList_3 = MOVE( DoubleLinkedList< UnsignedInteger64bits >::GenerateRandomInstance( NumericRange< UnsignedInteger64bits >( 50UL, 350UL ) ) );

				// Create a test object instance
				TestConstantFunctorObjectType testFunctorObject_2( testDoubleLinkedList_3.Size() );

				// Set the contents of the arry into the test object instance
				Do< UnsignedInteger64bits >( testDoubleLinkedList_3, FunctorInvoker< TestConstantFunctorObjectType COMMA Boolean COMMA const UnsignedInteger64bits& COMMA UnsignedInteger64bits >( testFunctorObject_2 ) );
			}

		)  //  End of debug tool











    }  //  Namespace Memory


}  //  Namespace Universe


#endif  //  FOREACHELEMENT_CPP





