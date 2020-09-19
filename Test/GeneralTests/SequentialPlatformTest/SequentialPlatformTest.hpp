#ifndef SEQUENTIALPLATFORMTEST_HPP
#define SEQUENTIALPLATFORMTEST_HPP


#include "../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../FunctionalityBranch/Level_0/Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../../../../../../../Content/NumericRange/NumericRange.hpp"  //  Class NumericRange


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
		//		Use this object to perform a random test on a sequential platform object
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
		class SequentialPlatformTest
		{
		public:


			// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object. Satic functions
			// only have access to static data members, which also don't belong to any instance, this means all other data members can not be used. The only
			// purpose then of declaring a static function is when a private static data member needs to be manipulated, or some functionality needed that
			// does not involve the non static data members





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
			NoInstances_MACRO( SequentialPlatformTest )


		};  //  Class SequentialPlatformTest




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to test a sequential platform object, that implements the interface :
		//
		//			SequentialPlatform_Interface
		//
		//		It will test all the functionality declared in the interface. The methods that will be checked are :
		//
		//			1. AddData
		//			2. Operatror+=
		//			3. operator[]
		//			4. Size
		//			5.
		//			6. 
		//
		//		This method should be used to check only objects that contains the above methods!
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          1. numberOfIterations - number of iterations of checking to perform
		//			2. rangeForSize - the possible range for the sequential platform size
		//			3. rangeForValues - the possible range for the entries values
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
		template< typename SequentialPlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		void Full_SequentialPlatform_Interface( UnsignedInteger64bits numberOfIterations, const NumericRange< UnsignedInteger64bits >& rangeForSize, const NumericRange< SequentialPlatformDataType >& rangeForValues )
		{
			// This object will be used to store the current choosen
		}



		// Method Information :
		//
		//  Description :
		//
		//		Use this method to test a sequential platform object, that implements the interface :
		//
		//			SequentialPlatform_Interface
		//
		//		It will test all the functionality declared in the interface. The methods that will be checked are :
		//
		//			1. Size
		//			2. operator[]
		//
		//		This method should be used to check only objects that contains the above methods!
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          1. numberOfIterations - number of iterations of checking to perform
		//			2. rangeForSize - the possible range for the sequential platform size
		//			3. rangeForValues - the possible range for the entries values
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
		template< typename SequentialPlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		void Full_SequentialPlatform_Interface( UnsignedInteger64bits numberOfIterations, const NumericRange< UnsignedInteger64bits >& rangeForSize, const NumericRange< SequentialPlatformDataType >& rangeForValues )
		{
			// Create a default constructed test instance
			SequentialPlatformToTestType testInstance_1;

			// Create a default constructed test instance
			SequentialPlatformToTestType testInstance_2;

			// This object will store the random maximum capacity
			UnsignedInteger64bits testInstance_maximumCapacity = rangeForSize.Maximum() + 1;

			// This object will store the random size picked each iteration to initiate the instance
			UnsignedInteger64bits testInstance_size = 0UL;

			// This object will store the random data picked each iteration to initiate the instance
			DataType randomDataInstance;

			// Loop as long as the number iteration did not reach the requirement
			for ( UnsignedInteger64bits iteration = 0UL ; iteration < numberOfIterations ; ++iteration )
			{
				// Generate a random size
				testInstance_size = Random::Generator::Get< DataType >( rangeForSize );

				// Generate a random data instance
				randomDataInstance = Random::Generator::Get< DataType >();

				// Initiate the instance with random size and value
				testInstance_1.Initiate( testInstance_size, randomDataInstance );

				// Assert that the size is correct
				Assert_Test_MACRO( testInstance_1.Size() == testInstance_size )

				// Loop on all the entries
				for ( UnsignedInteger64bits index = 0UL ; index < testInstance_1.Size() ; ++index )
				{
					// Assert that the entry contains the value that was used in the initialization
					Assert_Test_MACRO( testInstance_1[ index ] == randomDataInstance )
				}

				// Initiate the other instance using the instance that was already intialized
				testInstance_2.Initiate( testInstance_1 );

				// Assert that the size is correct
				Assert_Test_MACRO( testInstance_2.Size() == testInstance_size )
				Assert_Test_MACRO( testInstance_2.Size() == testInstance_1.Size() )

				// Loop on all the entries
				for ( UnsignedInteger64bits index = 0UL ; index < testInstance_2.Size() ; ++index )
				{
					// Assert that the entry contains the value that was used in the initialization
					Assert_Test_MACRO( testInstance_1[ index ] == randomDataInstance )
					Assert_Test_MACRO( testInstance_2[ index ] == testInstance_1[ index ] )
				}

				// Loop on all the entries
				for ( UnsignedInteger64bits index = 0UL ; index < testInstance_2.Size() ; ++index )
				{
					// Generate random data
					randomDataInstance = Random::Generator::Get< DataType >();

					// Set random data in the current entry
					testInstance_2[ index ] = randomDataInstance;
					testInstance_1[ index ] = randomDataInstance;
				}

				// Loop on all the entries
				for ( UnsignedInteger64bits index = 0UL ; index < testInstance_size ; ++index )
				{
					// Assert that the current entry is the same in both instances
					Assert_Test_MACRO( testInstance_1[ index ] == testInstance_2[ index ] )
				}

			}

		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to test a sequential platform object, that implements the interface :
		//
		//			DynamicSequentialPlatform_Interface
		//
		//		It will test all the functionality declared in the interface. The methods that will be checked are :
		//
		//			1. Size
		//			2. operator[]
		//			3. AddData ( 2 overloads )
		//			4. RemoveData
		//			5. Reserve
		//			6. operator+=
		//
		//		This method should be used to check only objects that contains the above methods!
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//          1. numberOfIterations - number of iterations of checking to perform
		//			2. rangeForSize - the possible range for the sequential platform size
		//			3. rangeForValues - the possible range for the entries values
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
		template< typename SequentialPlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		void Full_DynamicSequentialPlatform_Interface( UnsignedInteger64bits numberOfIterations, const NumericRange< UnsignedInteger64bits >& rangeForSize, const NumericRange< SequentialPlatformDataType >& rangeForValues )
		{
			// Test the sequential platform interface which the dynamic interface inherits from
			Full_SequentialPlatform_Interface( numberOfIterations, rangeForSize, rangeForValues );

			// Create a test instance and intialize it with the random maximum capacity
			SequentialPlatformToTestType testInstance_1;

			// Create a test instance and intialize it with the random maximum capacity
			SequentialPlatformToTestType testInstance_2;

			// This object will store the random size picked each iteration
			UnsignedInteger64bits testInstance_size = 0UL;

			// This object will store the current size as it changes with each add or remove operation on the test instance
			UnsignedInteger64bits currentTestInstance_size = 0UL;

			// This object will store the random data picked each iteration
			DataType randomDataInstance;

			// Loop as long as the number iteration did not reach the requirement
			for ( UnsignedInteger64bits iteration = 0UL ; iteration < numberOfIterations ; ++iteration )
			{

				// Check if the instance is empty
				if ( testInstance_1.Size() == 0UL )
				{
					// The instance is empty

					// Add data to the instance
					AddData_OperatorConcatenate_OperatorSquareBrackets_Size__Private( testInstance_1, rangeForSize, rangeForValues );

					// Continue to the next iteration of the loop
					continue;
				}
				// Check if the instace reached the maximum size wanted
				if ( testInstance_1.Size() == rangeForSize.Maximum() )
				{
					// The maximum size wanted for the instance was reached

					// Remove data from the instance
					RemoveData_OperatorSquareBrackets_Size__Private( testInstance_1, NumericRange< UnsignedInteger64bits >( 1UL, testInstance_1.Size() ) )

					// Continue to the next iteration of the loop
					continue;
				}

				// Generate a random number, in case it is an even number add data to the instance, and if its odd remove data
				if ( ( Random::Generator::Get< UnsignedInteger8bits >() % 2U ) == 0U )
				{
					// The picked number is even

					// Add data to the instance
					AddData_OperatorConcatenate_OperatorSquareBrackets_Size__Private( testInstance_1, NumericRange< UnsignedInteger64bits >( 1UL, ( rangeForSize.Maximum() - testInstance_1.Size() ) ), rangeForValues );
				}
				else
				{
					// The picked number is odd

					// Remove data from the instance
					RemoveData_OperatorSquareBrackets_Size__Private( testInstance_1, NumericRange< UnsignedInteger64bits >( 1UL, testInstance_1.Size() ) );
				}

			}

					

		}

























//	**********************************************************   TEMPLATE OR INLINE PROTECTED METHODS IMPLEMENTATION   **********************************************************




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************
































		// Method Information :
		//
		//  Description :
		//
		//		Use this method to test the 'AddData' and 'operator+=' methods. It will randomly add data, while checking many characteristics to 
		//		ensure correctness. It will also use the methods 'Size', 'operator[]'
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. testInstance - a reference to an instance of the dynamic sequential platform tested
		//			2. rangeForSize - the possible range for the sequential platform size
		//			3. rangeForValues - the possible range for the entries values
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
		//		2. There is no more free memory space - Class std::bad_alloc is thrown
		//		3.
		//
		template< typename SequentialPlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		void AddData_OperatorConcatenate_OperatorSquareBrackets_Size__Private( SequentialPlatformToTestType& testInstance, const NumericRange< UnsignedInteger64bits >& rangeForSize, const NumericRange< SequentialPlatformDataType >& rangeForValues )
		{
			// Create a test instance
			SequentialPlatformToTestType testInstance_1;

			// Create a test instance
			SequentialPlatformToTestType testInstance_2;

			// This object will store the total random size for the instance
			UnsignedInteger64bits totalTestInstance_size = Random::Generator::Get< DataType >( rangeForSize );

			// This object will store the random size that the first part should add
			UnsignedInteger64bits firstPartSizeToAdd = Random::Generator::Get< DataType >( NumericRange< UnsignedInteger64bits >( 1UL, totalTestInstance_size ) );

			// Add data to the beginning of the instance
			AddDataToInstance__Private( testInstance, firstPartSizeToAdd, true, 0UL );

			// Add all the data into the second instance also
			testInstance_1.AddData( 0UL, testInstance );

			// Assert that the 2 instance are the same
			Assert_Test_MACRO( testInstance == testInstance_1 )

			// Concatenate the data to the end of the instance
			testInstance_2 += testInstance;

			// Assert that the 2 instance are the same
			Assert_Test_MACRO( testInstance == testInstance_2 )

			// Assert that the 2 instance are the same
			Assert_Test_MACRO( testInstance_1 == testInstance_2 )

			// Generate a random size to add for the second part
			UnsignedInteger64bits secondPartSizeToAdd = Random::Generator::Get< DataType >( NumericRange< UnsignedInteger64bits >( 1UL, ( totalTestInstance_size - firstPartSizeToAdd ) ) );

			// Add data to the beginning of the instance
			AddDataToInstance__Private( testInstance, firstPartSizeToAdd, true, testInstance.Size() );

			// Add all the data into the second instance also
			testInstance_1.AddData( firstPartSizeToAdd, testInstance );

			// Assert that the 2 instance are the same
			Assert_Test_MACRO( testInstance == testInstance_1 )

			// Concatenate the data to the end of the instance
			testInstance_2 += testInstance;

			// Assert that the 2 instance are the same
			Assert_Test_MACRO( testInstance == testInstance_2 )

			// Assert that the 2 instance are the same
			Assert_Test_MACRO( testInstance_1 == testInstance_2 )

			// Generate a random size to add for the second part
			UnsignedInteger64bits thirdPartSizeToAdd = totalTestInstance_size - ( firstPartSizeToAdd + secondPartSizeToAdd );

			// Add data at random indices to the instance
			AddDataToInstance__Private( testInstance, thirdPartSizeToAdd, false );

			// Add all the data into the second instance also
			testInstance_1.AddData( ( firstPartSizeToAdd + secondPartSizeToAdd ), testInstance );

			// Assert that the 2 instance are the same
			Assert_Test_MACRO( testInstance == testInstance_1 )
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to add the required amount of the data elements to the given instance, at the provided index or at a random choosen one
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. testInstance - a reference to an instance of the dynamic sequential platform tested
		//			2. numberOfDataElementsToAdd - the number of data elements to add to the instance
		//			3. generateRandomIndexToAddData - a boolean to allow selecting a defined index or a random one each iteration to add the data to
		//			4. indexToAddData - an index to add the data, this will be used only if the above boolean contains true
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
		//		2. The number of elements to add should be larger then 0
		//		3. 
		//
		//  Possible errors :
		//
		//		1. One of the asserts failed - Class Exception is thrown
		//		2. There is no more free memory space - Class std::bad_alloc is thrown
		//		3.
		//
		template< typename SequentialPlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		inline void AddDataToInstance__Private( SequentialPlatformToTestType& testInstance, UnsignedInteger64bits numberOfDataElementsToAdd, Boolean generateRandomIndexToAddData, UnsignedInteger64bits indexToAddData )
		{
			// This object will store the current size as it changes with each add operation on the test instance
			auto currentTestInstance_size = testInstance.Size();

			// This will store the index to add the data to
			UnsignedInteger64bits addDataAtThisIndex = 0UL;

			// Check if an index was provided or that a random one should be generated
			if ( ( generateRandomIndexToAddData == true ) && ( testInstance.Size() > 2UL ) )
			{
				// A random index needs to be generated

				// Generate a random index to add the data at
				addDataAtThisIndex = Random::Generator::Get< UnsignedInteger64bits >( NumericRange< UnsignedInteger64bits >( 0UL, testInstance.Size() ) );
			}
			else
			{
				// Use this index provided as argument
				addDataAtThisIndex = indexToAddData;
			}

			// This object will store the random data picked each iteration
			DataType randomDataInstance;

			// This object will store the data located in the current entry asscoiated with the index
			DataType oldDataInCurrentEntryAssociatedWithTheIndex;

			// This object will store the data located in the current entry asscoiated with the index plus 1
			DataType oldDataInCurrentEntryAssociatedWithTheIndexPlusOne;

			// This object will store the data located in the current entry asscoiated with the index minus 1
			DataType oldDataInCurrentEntryAssociatedWithTheIndexMinusOne;

			// Check that the instance size is larger then 0
			if ( testInstance.Size() > 0UL )
			{
				// The instance is not empty

				// Check if the index that the data needs to be added to, is the last entry
				if ( addDataAtThisIndex != testInstance.Size() )
				{
					// The index does not point to the end of the instance

					// Store the data in the entry associated with the index
					oldDataInCurrentEntryAssociatedWithTheIndex = testInstance[ addDataAtThisIndex ];
				}

				// Check if the index that the data needs to be added to, is the last entry or the end of the instance
				if ( addDataAtThisIndex < ( testInstance.Size() - 1UL ) )
				{
					// The index does not point to the last entry or the end of the instance

					// Store the data in the entry associated with the index plus one
					oldDataInCurrentEntryAssociatedWithTheIndexPlusOne = testInstance[ addDataAtThisIndex + 1UL ];
				}

				// Check if the index that the data needs to be added to, is the first entry
				if ( addDataAtThisIndex > 0UL )
				{
					// The index does not point to the first entry

					// Store the data in the entry associated with the index minus one
					oldDataInCurrentEntryAssociatedWithTheIndexPlusOne = testInstance[ addDataAtThisIndex - 1UL ];
				}

			}

			// Loop the number of times as the first part random size requires
			for ( UnsignedInteger64bits numberOfDataElementsAlreadyAdded = 0UL ; numberOfDataElementsAlreadyAdded < numberOfDataElementsToAdd ; ++numberOfDataElementsAlreadyAdded )
			{
				// Generate a random data instance
				randomDataInstance = Random::Generator::Get< DataType >();

				// Add the data to the test instance
				testInstance.AddData( addDataAtThisIndex, randomDataInstance );

				// Assert that the new first entry contains the correct data
				Assert_Test_MACRO( testInstance[ addDataAtThisIndex ] == randomDataInstance )

				// Increment the current size by 1
				currentTestInstance_size += 1UL;

				// Assert that the size is correct
				Assert_Test_MACRO( testInstance.Size() == currentTestInstance_size )

				// Check that the instance size is larger then 1
				if ( testInstance.Size() > 1UL )
				{
					// The instance is not empty

					// Check if the index that the data needs to be added to, is the last entry
					if ( addDataAtThisIndex != testInstance.Size() )
					{
						// The index does not point to the end of the instance

						// Assert that the data that was in the entry associated with the index, was moved to an entry with index larger by 1
						Assert_Test_MACRO( testInstance_1[ addDataAtThisIndex + 1UL ] == oldDataInCurrentEntryAssociatedWithTheIndex )
					}

					// Check if the index that the data needs to be added to, is the last entry or the end of the instance
					if ( addDataAtThisIndex < ( testInstance.Size() - 1UL ) )
					{
						// The index does not point to the last entry or the end of the instance

						// Assert that the data that was in the entry associated with the index, was moved to an entry with index larger by 2
						Assert_Test_MACRO( testInstance_1[ addDataAtThisIndex + 2UL ] == oldDataInCurrentEntryAssociatedWithTheIndexPlusOne )
					}

					// Check if the index that the data needs to be added to, is the first entry
					if ( addDataAtThisIndex > 0UL )
					{
						// The index does not point to the first entry

						// Assert that the data that was in the entry associated with the index, stayed in the same location
						Assert_Test_MACRO( testInstance_1[ addDataAtThisIndex - 1UL ] == oldDataInCurrentEntryAssociatedWithTheIndexMinusOne )
					}

				}

			}

			// Assert that the size is correct
			Assert_Test_MACRO( testInstance_1.Size() == currentTestInstance_size )
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to test the 'RemoveData' method. It will randomly remove data, while checking many characteristics to ensure correctness. 
		//		It will also use the methods 'Size', 'operator[]'
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. testInstance - a reference to an instance of the dynamic sequential platform tested
		//			2. rangeForSizeToRemove - the possible range for the number of entries to remove from the sequential platform instance
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
		template< typename SequentialPlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		void RemoveData_OperatorSquareBrackets_Size__Private( SequentialPlatformToTestType& testInstance, const NumericRange< UnsignedInteger64bits >& rangeForSizeToRemove )
		{
			// Create a test instance and intialize it with the random maximum capacity
			SequentialPlatformToTestType testInstance_1( testInstance );

			// This object will store the total random size for the instance
			UnsignedInteger64bits totalTestInstance_size = Random::Generator::Get< DataType >( rangeForSizeToRemove );

			// This object will store the random size that the first part should remove
			UnsignedInteger64bits firstPartSizeToRemove = Random::Generator::Get< DataType >( NumericRange< UnsignedInteger64bits >( 1UL, totalTestInstance_size ) );

			// Remove data from the beginning of the instance
			RemoveDataFromInstance__Private( testInstance, firstPartSizeToRemove, true, 0UL );

			// Add all the data into the second instance also
			testInstance_1.RemoveData( firstPartSizeToRemove, 0UL );

			// Assert that the 2 instance are the same
			Assert_Test_MACRO( testInstance == testInstance_1 )

			// Generate a random size to remove for the second part
			UnsignedInteger64bits secondPartSizeToRemove = Random::Generator::Get< DataType >( NumericRange< UnsignedInteger64bits >( 1UL, ( totalTestInstance_size - firstPartSizeToRemove ) ) );

			// Remove data from the end of the instance
			RemoveDataFromInstance__Private( testInstance, secondPartSizeToRemove, true, ( testInstance.Size() - secondPartSizeToRemove - 1UL ) );

			// Add all the data into the second instance also
			testInstance_1.RemoveData( secondPartSizeToRemove, ( testInstance.Size() - secondPartSizeToRemove - 1UL ) );

			// Assert that the 2 instance are the same
			Assert_Test_MACRO( testInstance == testInstance_1 )

			// Generate a random size to add for the second part
			UnsignedInteger64bits thirdPartSizeToRemove = totalTestInstance_size - ( firstPartSizeToRemove + secondPartSizeToRemove );

			// Add data at random indices to the instance
			RemoveDataFromInstance__Private( testInstance, thirdPartSizeToRemove, false );
		}


		// Method Information :
		//
		//  Description :
		//
		//		Use this method to remove the required amount of the data elements from the given instance, at the provided index or at a random choosen one
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. testInstance - a reference to an instance of the dynamic sequential platform tested
		//			2. numberOfDataElementsToRemove - the number of data elements to remove from the instance
		//			3. generateRandomIndexToRemoveData - a boolean to allow selecting a defined index or a random one each iteration to remove the data from
		//			4. indexToRemoveData - an index to remove the data, this will be used only if the above boolean contains true
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
		//		2. The number of elements to remove should be larger then 0
		//		3. The given index plus the size to remove is smaller then the instance size
		//		4. 
		//
		//  Possible errors :
		//
		//		1. One of the asserts failed - Class Exception is thrown
		//		2.
		//
		template< typename SequentialPlatformToTestType, typename SequentialPlatformDataType, typename DataType >
		inline void RemoveDataFromInstance__Private( SequentialPlatformToTestType& testInstance, UnsignedInteger64bits numberOfDataElementsToRemove, Boolean generateRandomIndexToRemoveData, UnsignedInteger64bits indexToRemoveData )
		{
			// This object will store the current size as it changes with each remove operation on the test instance
			auto currentTestInstance_size = testInstance.Size();

			// This will store the index to remove the data from
			UnsignedInteger64bits removeDataFromThisIndex = 0UL;

			// Check if an index was provided or that a random one should be generated
			if ( ( generateRandomIndexToRemoveData == true ) && ( testInstance.Size() > 2UL ) )
			{
				// A random index needs to be generated

				// Generate a random index to remove the data from
				removeDataFromThisIndex = Random::Generator::Get< UnsignedInteger64bits >( NumericRange< UnsignedInteger64bits >( 0UL, ( testInstance.Size() - 1UL ) ) );
			}
			else
			{
				// Use this index provided as argument
				removeDataFromThisIndex = indexToRemoveData;
			}

			// This object will store the data located in the current entry asscoiated with the index plus 1
			DataType oldDataInCurrentEntryAssociatedWithTheIndexPlusOne;

			// This object will store the data located in the current entry asscoiated with the index plus 2
			DataType oldDataInCurrentEntryAssociatedWithTheIndexPlusTwo;

			// This object will store the data located in the current entry asscoiated with the index minus 1
			DataType oldDataInCurrentEntryAssociatedWithTheIndexMinusOne;

			// Check that the instance size is larger then one
			if ( testInstance.Size() > 1UL )
			{
				// The instance has at least 2 entries with data

				// Check if the index that the data needs to be removed from, is the last
				if ( removeDataFromThisIndex != ( testInstance.Size() - 1UL ) )
				{
					// The index does not point to the last entry

					// Store the data in the entry associated with the index plus one
					oldDataInCurrentEntryAssociatedWithTheIndexPlusOne = testInstance[ removeDataFromThisIndex + 1UL ];
				}

				// Check if the index that the data needs to be removed from, has at least 2 entries after it in the instance
				if ( removeDataFromThisIndex < ( testInstance.Size() - 2UL ) )
				{
					// There is at leasy two entries after the entry associated with the index

					// Store the data in the entry associated with the index plus two
					oldDataInCurrentEntryAssociatedWithTheIndexPlusTwo = testInstance[ removeDataFromThisIndex + 2UL ];
				}

				// Check if the index that the data needs to be removed from, is the first entry
				if ( removeDataFromThisIndex > 0UL )
				{
					// The index does not point to the first entry

					// Store the data in the entry associated with the index minus one
					oldDataInCurrentEntryAssociatedWithTheIndexMinusOne = testInstance[ removeDataFromThisIndex - 1UL ];
				}

			}

			// Loop the number of times as the first part random size requires
			for ( UnsignedInteger64bits numberOfDataElementsAlreadyRemoved = 0UL ; numberOfDataElementsAlreadyRemoved < numberOfDataElementsToRemove ; ++numberOfDataElementsAlreadyRemoved )
			{
				// Remove the data from the test instance
				testInstance.RemoveData( 1UL, removeDataFromThisIndex );

				// Decrement the current size by 1
				currentTestInstance_size -= 1UL;

				// Assert that the size is correct
				Assert_Test_MACRO( testInstance.Size() == currentTestInstance_size )

				// Check that the instance size is larger then 0
				if ( testInstance.Size() > 0UL )
				{
					// The instance is not empty

					// Check if the index that the data needs to be removed from, is the last entry
					if ( removeDataFromThisIndex != ( testInstance.Size() - 1UL ) )
					{
						// The index does not point to the last entry

						// Assert that the data that was in the entry associated with the index plus 1, was moved to an entry associated with the index
						Assert_Test_MACRO( testInstance[ removeDataFromThisIndex ] == oldDataInCurrentEntryAssociatedWithTheIndexPlusOne )
					}

					// Check if the index that the data needs to be removed from, is the smaller then the index of the entry before the last entry
					if ( removeDataFromThisIndex < ( testInstance.Size() - 2UL ) )
					{
						// The index does not point to the entry smaller then the index of the entry before the last entry

						// Assert that the data that was in the entry associated with the index plus 2, was moved to an entry associated with the index plus 1
						Assert_Test_MACRO( testInstance[ removeDataFromThisIndex + 1UL ] == oldDataInCurrentEntryAssociatedWithTheIndexPlusTwo )
					}

					// Check if the index that the data needs to be removed from, is the first entry
					if ( removeDataFromThisIndex > 0UL )
					{
						// The index does not point to the first entry

						// Assert that the data that was in the entry associated with the index minus 1, stayed in the same location
						Assert_Test_MACRO( testInstance[ removeDataFromThisIndex - 1UL ] == oldDataInCurrentEntryAssociatedWithTheIndexMinusOne )
					}

				}

			}

			// Assert that the size is correct
			Assert_Test_MACRO( testInstance.Size() == currentTestInstance_size )
		}









    }  //  Namespace Testing

}  //  Namespace Universe


#endif  // SEQUENTIALPLATFORMTEST_HPP