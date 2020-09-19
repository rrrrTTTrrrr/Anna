#ifndef PLATFORMTEST_HPP
#define PLATFORMTEST_HPP


#include "../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../FunctionalityBranch/Level_0/Level_1/Level_2/Level_3/Level_4/Content/Memory/Platforms_SequentialPlatformAsKeys/CommonFunctionality/Interfaces/ManipulateDataUsingSequentialPlatformAsKey_Interface/ManipulateDataUsingSequentialPlatformAsKey_Interface.hpp"  //  Class ManipulateDataUsingSequentialPlatformAsKey_Interface
#include "../../FunctionalityBranch/Level_0/Level_1/Level_2/Level_3/Content/Memory/SequentialPlatforms/CommonFunctionality/Interfaces/GetAndSetDataUsingIndices_Interface/GetAndSetDataUsingIndices_Interface.hpp"  //  Class GetAndSetDataUsingIndices_Interface
#include "../../FunctionalityBranch/Level_0/Level_1/Level_2/Level_3/Content/Memory/SequentialPlatforms/DoubleLinkedList/DoubleLinkedList.hpp"  //  Class DoubleLinkedList
#include "../../FunctionalityBranch/Level_0/Level_1/Level_2/Level_3/Content/Memory/SequentialPlatforms/HeapArray/HeapArray.hpp"  //  Class HeapArray


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


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


		// Class Information :
		//
		//  Purpose :
		//
		//		Use this object to perform a random test on a platform object
		//
   	    //  Description :
   	    //
		//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
		//		   an interface which conatins only static methods, and does not need to never be instantied
		//
		//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class PlatformTest
		{
		public:


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
			// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
			// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
			// does not involve the non static data members


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to test a platform object, that implements the interface :
			//
			//			ManipulateDataUsingSequentialPlatformAsKey_Interface
			//
			//		It will test all the functionality declared in the interface. The methods that will be checked are :
			//
			//			1. MaximumCapacity
			//			2. Capacity
			//			3. Size
			//			4. KeyExist
			//			5. DataExist
			//			6. AddData
			//			7. RemoveData
			//			8. ForEachElementDo
			//			9. Operator square brackes
			//			10. Concatenate operator
			//
			//		This method should be used to check only objects that contains the above methods!
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//          1. numberOfIterations - number of iterations of checking to perform
			//			2. rangeForKeySize - the possible range for the key size
			//			3. rangeForKeyValues - the possible range for the key entries values
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//      NONE
			//
			//  Expectations :
			//
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
			template< typename PlatformToTestType, typename SequentialPlatformDataType, typename DataType >
			static void Full( UnsignedInteger64bits numberOfIterations, const NumericRange< UnsignedInteger64bits >& rangeForKeySize, const NumericRange< SequentialPlatformDataType >& rangeForKeyValues );


			DEBUG_TOOL(

				// This part of the object is dedicated for testing :


				// Method Information :
				//
				//  Description :
				//
				//		This method is used to test the object. It is not part of the implementation, it is only used to find problems with the code
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
				//			NONE
				//
				//  Expectations :
				//
				//		Please let the test pass lord!!
				//
				//  Possible errors :
				//
				//		It says there are no problems, which is even scarier, did I just wrote a working code??
				//
				static void Test() __attribute__ (( __unused__ ));

			)  //  End of debug tool


		private:


			// Disable all default generated methods - constructor, destructor, copy constructor, assignment operator, move constructor and move assignment operator
			NoInstances_MACRO( PlatformTest )


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to test the 'AddData' method. It will also use the methods 'KeyExist', 'DataExist' and 'Size' and will test them 
			//		also. It will randomly generate a key and associated data in each iteration and add them to the instance
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. testInstance_1 - a reference to an instance of the platform tested
			//          1. numberOfIterations - number of iterations of checking to perform
			//			2. rangeForKeySize - the possible range for the key size
			//			3. rangeForKeyValues - the possible range for the key entries values
			//			5. testInstance_1_keys - a reference to a double linked list to contain all the keys added
			//			6. testInstance_1_data - a reference to a double linked list to contain all the added data
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//      NONE
			//
			//  Expectations :
			//
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
			template< typename PlatformToTestType, typename SequentialPlatformDataType, typename DataType >
			static void AddData_KeyExist_DataExist_Size__Private( Memory::ManipulateDataUsingSequentialPlatformAsKey_Interface< SequentialPlatformDataType, DataType >& testInstance_1, UnsignedInteger64bits numberOfIterations, const NumericRange< UnsignedInteger64bits >& rangeForKeySize, const NumericRange< SequentialPlatformDataType >& rangeForKeyValues, Memory::DoubleLinkedList< Memory::HeapArray< SequentialPlatformDataType > >& testInstance_1_keys, Memory::DoubleLinkedList< DataType >& testInstance_1_data );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to test the 'RemoveData' method. It will also use the methods 'KeyExist' and 'Size' and will test it also. It will
			//		remove all the data currently in the instance
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. testInstance_1 - a reference to an instance of the platform tested
			//			2. testInstance_1_keys - a reference to a double linked list to contain all the keys added
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//      NONE
			//
			//  Expectations :
			//
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
			template< typename PlatformToTestType, typename SequentialPlatformDataType, typename DataType >
			static void RemoveData_KeyExist_Size__Private( Memory::ManipulateDataUsingSequentialPlatformAsKey_Interface< SequentialPlatformDataType, DataType >& testInstance_1, Memory::DoubleLinkedList< Memory::HeapArray< SequentialPlatformDataType > >& testInstance_1_keys );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to test the 'operator[]' method. It will also use the methods 'KeyExist', 'DataExist' and 'Size' and will test them 
			//		also
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. testInstance_1 - a reference to an instance of the platform tested
			//			2. testInstance_1_keys - a reference to a double linked list to contain all the keys added
			//			3. testInstance_1_data - a reference to a double linked list to contain all the added data
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//      NONE
			//
			//  Expectations :
			//
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
			template< typename PlatformToTestType, typename SequentialPlatformDataType, typename DataType >
			static void OperatorSquareBrackets_KeyExist_DataExist_Size__Private( Memory::ManipulateDataUsingSequentialPlatformAsKey_Interface< SequentialPlatformDataType, DataType >& testInstance_1, const Memory::ManipulateDataUsingSequentialPlatformAsKey_Interface< SequentialPlatformDataType, DataType >& testConstantTree_1, Memory::DoubleLinkedList< Memory::HeapArray< SequentialPlatformDataType > >& testInstance_1_keys, const Memory::DoubleLinkedList< DataType >& testInstance_1_data );


			// Method Information :
			//
			//  Description :
			//
			//		Use this method to test the 'operator+=' method. It will also use the methods 'KeyExist', 'DataExist', 'Size', copy constructor,
			//		move constructor, equal operator and non equal operator and will test them also
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			NONE
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//      NONE
			//
			//  Expectations :
			//
			//		1. All the methods listed in the description exist in the template type object to test
			//		2. 
			//
			//  Possible errors :
			//
			//		1. One of the asserts failed - Class Exception is thrown
			//		2. 
			//
			template< typename PlatformToTestType, typename SequentialPlatformDataType, typename DataType >
			static void ConcatenateOperator_KeyExist_DataExist_Size__Private();


		};  //  Class PlatformTest




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to test a platform object, that implements the interface :
		//
		//			Memory::ManipulateDataUsingSequentialPlatformAsKey_Interface
		//
		//		It will test all the functionality declared in the interface. The methods that will be checked are :
		//
		//			1. MaximumCapacity
		//			2. Capacity
		//			3. Size
		//			4. KeyExist
		//			5. DataExist
		//			6. AddData
		//			7. RemoveData
		//			8. ForEachElementDo
		//			9. Operator square brackes
		//			10. Concatenate operator
		//
		//		This method should be used to check only objects that contains the above methods!
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          1. numberOfIterations - number of iterations of checking to perform
		//			2. rangeForKeySize - the possible range for the key size
		//			3. rangeForKeyValues - the possible range for the key entries values
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		1. All the methods listed in the description exist in the template type object to test
		//		2. 
		//
		//  Possible errors :
		//
		//		1. One of the asserts failed - Class Exception is thrown
		//		2. 
		//
		template< typename PlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		void PlatformTest::Full( UnsignedInteger64bits numberOfIterations, const NumericRange< UnsignedInteger64bits >& rangeForKeySize, const NumericRange< SequentialPlatformDataType >& rangeForKeyValues )
		{
			// Create a default constructed instance
			PlatformToTestType testInstance_1;

			// This object will store all the added keys
			Memory::DoubleLinkedList< Memory::HeapArray< SequentialPlatformDataType > > testInstance_1_keys;

			// This object will store all the added data
			Memory::DoubleLinkedList< DataType > testInstance_1_data;

			// Add data to the instance
			AddData_KeyExist_DataExist_Size__Private< PlatformToTestType, SequentialPlatformDataType, DataType >( testInstance_1, numberOfIterations, rangeForKeySize, rangeForKeyValues, testInstance_1_keys, testInstance_1_data );

			// Verify the data added correctly
			OperatorSquareBrackets_KeyExist_DataExist_Size__Private< PlatformToTestType, SequentialPlatformDataType, DataType >( testInstance_1, testInstance_1, testInstance_1_keys, testInstance_1_data );

			// Remove the data
			RemoveData_KeyExist_Size__Private< PlatformToTestType, SequentialPlatformDataType, DataType >( testInstance_1, testInstance_1_keys );

			// Verify the concatenate operator
			ConcatenateOperator_KeyExist_DataExist_Size__Private< PlatformToTestType, SequentialPlatformDataType, DataType >();
		}

































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************


































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to test the 'AddData' method. It will also use the methods 'KeyExist', 'DataExist' and 'Size' and will test them 
		//		also. It will randomly generate a key and associated data in each iteration and add them to the instance
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. testInstance_1 - a reference to an instance of the platform tested
		//          1. numberOfIterations - number of iterations of checking to perform
		//			2. rangeForKeySize - the possible range for the key size
		//			3. rangeForKeyValues - the possible range for the key entries values
		//			5. testInstance_1_keys - a reference to a double linked list to contain all the keys added
		//			6. testInstance_1_data - a reference to a double linked list to contain all the added data
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		1. All the methods listed in the description exist in the template type object to test
		//		2. 
		//
		//  Possible errors :
		//
		//		1. One of the asserts failed - Class Exception is thrown
		//		2. 
		//
		template< typename PlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		void PlatformTest::AddData_KeyExist_DataExist_Size__Private( Memory::ManipulateDataUsingSequentialPlatformAsKey_Interface< SequentialPlatformDataType, DataType >& testInstance_1, UnsignedInteger64bits numberOfIterations, const NumericRange< UnsignedInteger64bits >& rangeForKeySize, const NumericRange< SequentialPlatformDataType >& rangeForKeyValues, Memory::DoubleLinkedList< Memory::HeapArray< SequentialPlatformDataType > >& testInstance_1_keys, Memory::DoubleLinkedList< DataType >& testInstance_1_data )
		{
			// This will store the last size of the instance to check that it increases by 1 each time
			UnsignedInteger64bits testInstance_1_size = 0UL;

			// Loop and add an entry each time to the instance
			for ( UnsignedInteger64bits iteration = 0UL ; iteration < numberOfIterations ; ++iteration )
			{
				// Generate random key
				Memory::HeapArray< SequentialPlatformDataType > randomKey = MOVE( Memory::HeapArray< SequentialPlatformDataType >::GenerateRandomInstance( rangeForKeySize, rangeForKeyValues ) );

				// Check if the key already exist
				if ( testInstance_1.KeyExist( randomKey ) == true )
				{
					// The current key exist already
					continue;
				}

				// Add the random genereated key
				testInstance_1_keys.AddData( 0UL, randomKey );

				// Generate random data
				DataType randomData = MOVE( Random::Generator::Get< DataType >() );

				// Generate random data and add it to the instance with the random key
				testInstance_1.AddData( randomKey, randomData );

				// Add the random genereated data
				testInstance_1_data.AddData( 0UL, randomData );

				// Increment the test tree instance size by 1
				testInstance_1_size += 1UL;

				// Assert that the random data exist in the tree instance
				Assert_Test_MACRO( testInstance_1.DataExist( randomData ) == true )

				// Assert that the instance size in the saved size are the same
				Assert_Test_MACRO( testInstance_1_size == testInstance_1.Size() )
			}

			// Assert that the instance size is the same as the number of keys
			Assert_Test_MACRO( testInstance_1.Size() == testInstance_1_keys.Size() )

			// Assert that the instance size is the same as the number of data added
			Assert_Test_MACRO( testInstance_1.Size() == testInstance_1_data.Size() )
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to test the 'RemoveData' method. It will also use the methods 'KeyExist' and 'Size' and will test it also. It will
		//		remove all the data currently in the instance
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. testInstance_1 - a reference to an instance of the platform tested
		//			2. testInstance_1_keys - a reference to a double linked list to contain all the keys added
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		1. All the methods listed in the description exist in the template type object to test
		//		2. 
		//
		//  Possible errors :
		//
		//		1. One of the asserts failed - Class Exception is thrown
		//		2. 
		//
		template< typename PlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		void PlatformTest::RemoveData_KeyExist_Size__Private( Memory::ManipulateDataUsingSequentialPlatformAsKey_Interface< SequentialPlatformDataType, DataType >& testInstance_1, Memory::DoubleLinkedList< Memory::HeapArray< SequentialPlatformDataType > >& testInstance_1_keys )
		{
			// This will store the last size of the instance to check that it decrements by 1 each time
			UnsignedInteger64bits testInstance_1_size = testInstance_1.Size();

			// Store the current size
			UnsignedInteger64bits currentSize = testInstance_1.Size();

			// Loop and remove all the entries of the test tree instance
			for ( UnsignedInteger64bits iteration = 0UL ; iteration < currentSize ; ++iteration )
			{
				// Assert that the key already exist
				Assert_Test_MACRO( testInstance_1.KeyExist( testInstance_1_keys[ iteration ] ) == true )

				// Remove the data assoicated with the current key
				testInstance_1.RemoveData( testInstance_1_keys[ iteration ] );

				// Decrement the test tree instance size by 1
				testInstance_1_size -= 1UL;

				// Assert that the key does not exist anymore in the test tree instance
				Assert_Test_MACRO( testInstance_1.KeyExist( testInstance_1_keys[ iteration ] ) == false )

				// Assert that the instance size in the saved size are the same
				Assert_Test_MACRO( testInstance_1_size == testInstance_1.Size() );
			}

			// Assert that the size of the instance is 0
			Assert_Test_MACRO( testInstance_1.Size() == 0UL );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to test the 'operator[]' method. It will also use the methods 'KeyExist', 'DataExist' and 'Size' and will test them 
		//		also
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. testInstance_1 - a reference to an instance of the platform tested
		//			2. testInstance_1_keys - a reference to a double linked list to contain all the keys added
		//			3. testInstance_1_data - a reference to a double linked list to contain all the added data
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		1. All the methods listed in the description exist in the template type object to test
		//		2. 
		//
		//  Possible errors :
		//
		//		1. One of the asserts failed - Class Exception is thrown
		//		2. 
		//
		template< typename PlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		void PlatformTest::OperatorSquareBrackets_KeyExist_DataExist_Size__Private( Memory::ManipulateDataUsingSequentialPlatformAsKey_Interface< SequentialPlatformDataType, DataType >& testInstance_1, const Memory::ManipulateDataUsingSequentialPlatformAsKey_Interface< SequentialPlatformDataType, DataType >& testConstantTree_1, Memory::DoubleLinkedList< Memory::HeapArray< SequentialPlatformDataType > >& testInstance_1_keys, const Memory::DoubleLinkedList< DataType >& testInstance_1_data )
		{
			// Assert that the instance size is the same as the number of keys
			Assert_Test_MACRO( testInstance_1.Size() == testInstance_1_keys.Size() )

			// Assert that the instance size is the same as the number of data added
			Assert_Test_MACRO( testInstance_1.Size() == testInstance_1_data.Size() )

			// Assert that the instance size is the same as the number of keys
			Assert_Test_MACRO( testConstantTree_1.Size() == testInstance_1_keys.Size() )

			// Assert that the instance size is the same as the number of data added
			Assert_Test_MACRO( testConstantTree_1.Size() == testInstance_1_data.Size() )

			// Store the current size
			UnsignedInteger64bits currentSize = testInstance_1.Size();

			// Loop and remove all the entries of the test tree instance
			for ( UnsignedInteger64bits iteration = 0UL ; iteration < currentSize ; ++iteration )
			{
				// Assert that the key already exist
				Assert_Test_MACRO( testInstance_1.KeyExist( testInstance_1_keys[ iteration ] ) == true )

				// Assert that the random data exist in the tree instance
				Assert_Test_MACRO( testInstance_1.DataExist( testInstance_1_data[ iteration ] ) == true )

				// Use the square brackets operator and assert that it retrievs the correct data for the key
				Assert_Test_MACRO( testInstance_1[ testInstance_1_keys[ iteration ] ] == testInstance_1_data[ iteration ] )

				// Assert that the key already exist
				Assert_Test_MACRO( testConstantTree_1.KeyExist( testInstance_1_keys[ iteration ] ) == true )

				// Assert that the random data exist in the tree instance
				Assert_Test_MACRO( testConstantTree_1.DataExist( testInstance_1_data[ iteration ] ) == true )

				// Use the square brackets operator and assert that it retrievs the correct data for the key
				Assert_Test_MACRO( testConstantTree_1[ testInstance_1_keys[ iteration ] ] == testInstance_1_data[ iteration ] )
			}

		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to test the 'operator+=' method. It will also use the methods 'KeyExist', 'DataExist', 'Size', copy constructor,
		//		move constructor, equal operator and non equal operator and will test them also
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			NONE
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		1. All the methods listed in the description exist in the template type object to test
		//		2. 
		//
		//  Possible errors :
		//
		//		1. One of the asserts failed - Class Exception is thrown
		//		2. 
		//
		template< typename PlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		void PlatformTest::ConcatenateOperator_KeyExist_DataExist_Size__Private()
		{
			// Create an instance using the generated arguments
			PlatformToTestType testInstance_1 = MOVE( PlatformToTestType::GenerateRandomInstance() );

			// Copy construct another instance
			PlatformToTestType testInstance_2( testInstance_1 );

			// Ensure that both instance match
			Assert_Test_MACRO( testInstance_1 == testInstance_2 )
			Assert_Test_MACRO( ( testInstance_1 != testInstance_2 ) == false )

			// Create an instance using the generated arguments
			PlatformToTestType testInstance_3 = MOVE( PlatformToTestType::GenerateRandomInstance() );

			// Copy construct another instance
			PlatformToTestType testInstance_4( testInstance_3 );

			// Ensure that both instance match
			Assert_Test_MACRO( testInstance_3 == testInstance_4 )
			Assert_Test_MACRO( ( testInstance_3 != testInstance_4 ) == false )

			// Remove all the keys that exist in both the first and the third instance from the third instance. This lambda expression will be used 
			// for that purpose
			CreateLambdaExpressionInstanceWithArguments( ConsiderAsOneArgument ( [ &testInstance_3 ]( const DataType&, const Memory::GetAndSetDataUsingIndices_Interface< SequentialPlatformDataType >& currentKey ) -> Boolean
			{

				// Check if the key exist in both instances
				if ( testInstance_3.KeyExist( currentKey ) == true )
				{
					// The current key exist in both instances

					// Remove it
					testInstance_3.RemoveData( currentKey );
				}

				// Return false, to continue adding the data
				return ( false );

			} ), lambdaExpressionToRemoveAllSimilarKeysFromThirdInstance, Boolean, const DataType&, const Memory::GetAndSetDataUsingIndices_Interface< SequentialPlatformDataType >& )

			// Use the lambda expression to verify the concatenate operator
			testInstance_1.ForEachElementDo( lambdaExpressionToRemoveAllSimilarKeysFromThirdInstance );		

			// Concatenate two instances
			testInstance_1 += testInstance_3;

			// Check that the total size match the sum of the two instances alone
			Assert_Test_MACRO( testInstance_1.Size() == ( testInstance_2.Size() + testInstance_3.Size() ) )

			// Loop on all the entries of the second instance and check that they exist. This lambda expression will be used for that purpose
			CreateLambdaExpressionInstanceWithArguments( ConsiderAsOneArgument ( [ &testInstance_1 ]( const DataType& currentData, const Memory::GetAndSetDataUsingIndices_Interface< SequentialPlatformDataType >& currentKey ) -> Boolean
			{

				// Ensure that the data associated with the current key exist also in the second instance
				Assert_Test_MACRO( testInstance_1.KeyExist( currentKey ) == true )

				// Ensure that the data exist
				Assert_Test_MACRO( testInstance_1.DataExist( currentData ) == true )

				// Ensure that in both instances the key is associated with the correct data
				Assert_Test_MACRO( currentData == testInstance_1[ currentKey ] )

				// Return false, to continue adding the data
				return ( false );

			} ), lambdaExpressionToVerifyTheConcatenateOperator, Boolean, const DataType&, const Memory::GetAndSetDataUsingIndices_Interface< SequentialPlatformDataType >& )

			// Use the lambda expression to verify the concatenate operator
			testInstance_2.ForEachElementDo( lambdaExpressionToVerifyTheConcatenateOperator );

			// Use the lambda expression to verify the concatenate operator
			testInstance_3.ForEachElementDo( lambdaExpressionToVerifyTheConcatenateOperator );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to test the 'RemoveData' method. It will also use the methods 'KeyExist' and 'Size' and will test it also. It will
		//		remove all the data currently in the instance
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. testInstance_1 - a reference to an instance of the platform tested
		//			2. testInstance_1_keys - a reference to a double linked list to contain all the keys added
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//      NONE
		//
		//  Expectations :
		//
		//		1. All the methods listed in the description exist in the template type object to test
		//		2. 
		//
		//  Possible errors :
		//
		//		1. One of the asserts failed - Class Exception is thrown
		//		2. 
		//
		template< typename PlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		void PlatformTest::RemoveData_KeyExist_Size__Private( Memory::ManipulateDataUsingSequentialPlatformAsKey_Interface< SequentialPlatformDataType, DataType >& testInstance_1, Memory::DoubleLinkedList< Memory::HeapArray< SequentialPlatformDataType > >& testInstance_1_keys )
		{
			
		}




    }  //  Namespace Testing

}  //  Namespace Universe


#endif  // PLATFORMTEST_HPP