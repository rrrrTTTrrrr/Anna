#ifndef SEARCH_HPP
#define SEARCH_HPP


#include "../../../../../../../../../../Content/CodingLanguages/C++/LanguageFeatures/C++_LanguageFeatures.hpp"  //  Macro DEBUG_ONLY, Macro COMMA
#include "../../../../../../../../../../ObjectBranch/Content/ObjectInfrastructure/ObjectInfrastructure.hpp"  //  Macro ObjectInfrastructure_MACRO
#include "../../../../../../../Content/Memory/Operations/Operations.hpp"  //  Class Operations
#include "../../../../../../../../Content/Error/Assert/Assert.hpp"  //  Class Assert
#include "../SequentialPlatformsInterfaces/SequentialPlatform_Interface/SequentialPlatform_Interface.hpp"  // Class SequentialPlatform_Interface
#include "../../../../../../Content/BindObjects/Pair/Pair.hpp"  //  Class Pair
#include "../../../../../../../Content/RawPointers/HeapPointer/HeapPointer.hpp"  //  Class HeapPointer


// This additional headers are only needed in test mode
#ifdef TEST_MODE
#endif


namespace Universe
{

    namespace Memory
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



    	// Deduction refers to the process of determining the type of a template parameter from a given argument. It applies to function templates, auto
    	// and few other cases ( e.g partial specialization ). For example, consider :
    	//
    	//		template< typename Type >
    	//		void Flow( std::list< Type > );
    	//
    	// Now if the function is used as 'Flow( X )', where X was declared as :
    	//
    	//		std::list< int > X;
    	//
    	// Then the template type is deduced as 'int', and the resulting specialization 'Flow< int >'.
    	//
    	// In order for deduction to work, the template parameter type that is to be deduced has to appear in a deducible context. In this example, the
    	// function parameter of 'Flow' is such a deducible context. That is, an argument in the function call expression allows us to determine what 
    	// the template parameter should be in order for the call expression to be valid.
    	//
    	// However there are non deduced contexts, where no deduction is possible. The canonical example is "a template parameter that appears to the
    	// left of a ::" :
    	//
    	//		template< typename Type >
    	//		class Anna;
    	//
    	// 		template< typename Type >
    	//		void FuckAnna( typename Anna< Type >::type );
    	//
    	// In this function template, the template argument is a non deduced context. Thus it cannot be be used as 'FuckAnna( X )' and deduce the template
    	// argument. The reason for this is that there is no "backwards correspondence" between arbitrary types and members. For example, the following
    	// specializations can be created :
    	//
    	//		template<>
    	//		class FuckAnna< int >
    	//		{
    	//			using type = double;
    	//		}
    	//
    	//		template<>
    	//		class FuckAnna< double >
    	//		{
    	//			using type = double;
    	//		}
    	//
    	//		template<>
    	//		class FuckAnna< char >
    	//		{
    	//			using type = short;
    	//		}
    	//
    	// As can be seen calling the function as 'FuckAnna( int() )' has two possible answers for the template argument!



		// Class Information :
		//
		//  Purpose :
		//
		//		Use this object to search for specific single elements or patterns in a data. The search is performed only in sequential platforms,
		//		platforms that has meaning to the order, and can be accessed through indexing
		//
   	    //  Description :
   	    //
		//		1. This object is used only to wrap some static methods, which can be used without any instance of the object. Then this object is
		//		   an interface which conatins only static methods, and does not need to never be instantied
		//
		//		2. This object has all the methods to create, destory, copy and move disabled to ensure that no instances of it will be created
    	//
		//      3. The algorithm :
        //
        //          Notion : n = data size, k = pattern size
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
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		Too many to count
		//
		class Search
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
			//      Use this method to get the location of a specific apperance of a single element in the data
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. data - a constant reference to a sequential platform
			//			2. singleElementData - the single element to find in the data
			//			3. requiredNumberOfPatternAppearnceInTheData - use this to get the location of a specific apperance in the data
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	A pair with the first entry containing a boolean to describe if the required apperance of the single element was found in the data or not. 
			//		If it was found the the boolean will contain true, and the second entry will contain the index on the data it was found in
			//
			//  Expectations :
			//
			//		1. The sequential platform with the data should be ready 
			//		2. The sequential platform with the data should have a size larger then 0
			//		3. The required apperance number should be larger then 0
			//		4. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename DataType >
			static inline Pair< Boolean, UnsignedInteger64bits > SingleElementInTheData( const SequentialPlatform_Interface< DataType >& data, const DataType& singleElementData, UnsignedInteger64bits requiredNumberOfPatternAppearnceInTheData );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the location of a specific apperance of the pattern in the data
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. data - a constant reference to a sequential platform
			//			2. pattern - a constant reference to a sequential platform instance that contains information that needs to be found in the data
			//			3. requiredNumberOfPatternAppearnceInTheData - use this to get the location of a specific apperance in the data
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	A pair with the first entry containing a boolean to describe if the required apperance of the pattern was found in the data or not. If it was
			//		found the the boolean will contain true, and the second entry will contain the index on the data that the pattern was found
			//
			//  Expectations :
			//
			//		1. The sequential platform with the data should be ready 
			//		2. The sequential platform with the data should have a size larger then 0
			//		3. The sequential platform with the pattern should be ready 
			//		4. The sequential platform with the pattern should have a size larger then 0
			//		5. The required apperance number should be larger then 0
			//		6. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename DataType >
			static inline Pair< Boolean, UnsignedInteger64bits > PatternInTheData( const SequentialPlatform_Interface< DataType >& data, const SequentialPlatform_Interface< DataType >& pattern, UnsignedInteger64bits requiredNumberOfPatternAppearnceInTheData );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the location of a specific apperance of the pattern in the data
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. data - a constant reference to a sequential platform
			//			2. pattern - a constant reference to a sequential platform instance that contains information that needs to be found in the data
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	A pair with the first entry containing a boolean to describe if at least one apperance of the pattern was found in the data. If it was
			//		found the the boolean will contain true, and the second entry will contain a list with all the indices on the data that the pattern 
			//		was found
			//
			//  Expectations :
			//
			//		1. The sequential platform with the data should be ready 
			//		2. The sequential platform with the data should have a size larger then 0
			//		3. The sequential platform with the pattern should be ready 
			//		4. The sequential platform with the pattern should have a size larger then 0
			//		5. 
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename DataType >
			static inline Pair< Boolean, HeapPointer< UnsignedInteger64bits > > PatternInTheData( const SequentialPlatform_Interface< DataType >& data, const SequentialPlatform_Interface< DataType >& pattern );


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
			NoInstances_MACRO( Search )


			// Method Information :
			//
			//  Description :
			//
			//		Use this method each time a new pattern is set into the instance, to process the pattern and make the instance ready to search for
			//		for it in the data
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			pattern - a constant reference to a sequential platform instance that contains information that needs to be found in the data
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
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename DataType >
			static Pair< UnsignedInteger64bits, HeapPointer< UnsignedInteger64bits > > ProcessPatternToFindTheStartingPointForTheNextSearchIfMismatchWasFoundBetweenThePatternAndTheData__Private( const SequentialPlatform_Interface< DataType >& pattern );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to compare a subpattern with the subpattern that starts from the beginning of the pattern
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. pattern - a constant reference to a sequential platform instance that contains information that needs to be found in the data
			//			2. subpatternFirstEntryIndex - the index of the first entry of the subpattern
			//			3. subpatternSize - the size of the subpattern to compare
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	True if the subpattern match the subpattern with the same size that starts from the beginning, and false otherwise
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename DataType >
			static inline Boolean CompareSubpatternWithTheSubpatternThatStartAtTheBeginning__Private( const SequentialPlatform_Interface< DataType >& pattern, UnsignedInteger64bits subpatternFirstEntryIndex, UnsignedInteger64bits subpatternSize );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to get the location of the next apperance of the pattern in the data. The search will start from the given index on the data
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. pattern - a constant reference to a sequential platform instance that contains information that needs to be found in the data
			//			2. startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch - the result of processing the data
			//			3. startSearchFromThisIndexOnTheData - the index on the data from which the search for the data will start
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//   	The index of the next apperance of the pattern in the data. If no apperance was found then the size of the data will be returned
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		They will come
			//
			template< typename DataType >
			static inline UnsignedInteger64bits FindNextApperance__Private( const SequentialPlatform_Interface< DataType >& data, UnsignedInteger64bits startSearchFromThisIndexOnTheData, const SequentialPlatform_Interface< DataType >& pattern, Pair< UnsignedInteger64bits, HeapPointer< UnsignedInteger64bits > >& startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch );


			// Method Information :
			//
			//  Description :
			//
			//      Use this method to copy the apperances indices found so far to a larger memory space, and add the new apperance index found
			//
			//  Required arguments :
			//
			//      User information needed :
			//
			//			1. apperancesIndices - a copy of a heap pointer with all the apperances indices
			//			2. currentApperanceOfThePatternInTheDataIndex - the index in which the current apperance was found
			//
			//      Information returned to the user :
			//
			//          NONE
			//
			//  Return value :
			//
			//		A heap pointer instance copy with the all the apperances indcies
			//
			//  Expectations :
			//
			//		NONE
			//
			//  Possible errors :
			//
			//		1. There is no more free memory space - Class std::bad_alloc is thrown
			//		2. 
			//
			static inline HeapPointer< UnsignedInteger64bits > AllocateBiggerMemorySpaceCopyTheCurrentIndicesAndFinallyAddAlsoTheNewIndex__Private( const HeapPointer< UnsignedInteger64bits > apperancesIndices, UnsignedInteger64bits currentApperanceOfThePatternInTheDataIndex );


		};  //  Class Search




































//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************


































		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the location of a specific apperance of a single element in the data
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. data - a constant reference to a sequential platform
		//			2. singleElementData - the single element to find in the data
		//			3. requiredNumberOfPatternAppearnceInTheData - use this to get the location of a specific apperance in the data
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	A pair with the first entry containing a boolean to describe if the required apperance of the single element was found in the data or not. 
		//		If it was found the the boolean will contain true, and the second entry will contain the index on the data it was found in
		//
		//  Expectations :
		//
		//		1. The sequential platform with the data should be ready 
		//		2. The sequential platform with the data should have a size larger then 0
		//		3. The required apperance number should be larger then 0
		//		4. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DataType >
		inline Pair< Boolean, UnsignedInteger64bits > Search::SingleElementInTheData( const SequentialPlatform_Interface< DataType >& data, const DataType& singleElementData, UnsignedInteger64bits requiredNumberOfPatternAppearnceInTheData )
		{
            // Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertInstanceIsReady_MACRO( data )
			AssertInstanceSizeIsLargerThenZero_MACRO( data )
			Assert_MACRO( ( requiredNumberOfPatternAppearnceInTheData > 0 ), "The given apperance number should be larger then 0" )

			// This pair will store the result of the method. If the required apperance was found it will contain a boolean with the value true and 
			// otherwise false. The second entry will store the index of the required apperance if found
			Pair< Boolean, UnsignedInteger64bits > singleElementDataApperancePair_foundOrNotAndIndex;

			// This object will store the number of apperances of the pattern already found in the data
			UnsignedInteger64bits numberOfApperancesOfThePatternAlreadyFound = 0UL;

			// Loop until the required apperance was found or the data ended
			for ( UnsignedInteger64bits dataIndex = 0UL ; dataIndex < data.Size() ; ++dataIndex )
			{

				// Check if the current entry contains the required data element
				if ( data[ dataIndex ] == singleElementData )
				{
					// The required single data element was found

					// Increase the number of apperances found by 1
					numberOfApperancesOfThePatternAlreadyFound += 1UL;

					// Check if the current apperance is the required one
					if ( numberOfApperancesOfThePatternAlreadyFound == requiredNumberOfPatternAppearnceInTheData )
					{
						// The required apperance of the single element data in the data was reached

						// Set the boolean to true in the pair, to notify the caller that the requied apperance of the pattern was found
						singleElementDataApperancePair_foundOrNotAndIndex.First() = true;

						// Set the index of the apperance in the data
						singleElementDataApperancePair_foundOrNotAndIndex.Second() = dataIndex;

						// Nothing else needs to be done, break the loop
						break;
					}

				}

			}

			// Return the pair with the result
			return ( MOVE( singleElementDataApperancePair_foundOrNotAndIndex ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the location of a specific apperance of the pattern in the data
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. data - a constant reference to a sequential platform
		//			2. pattern - a constant reference to a sequential platform instance that contains information that needs to be found in the data
		//			3. requiredNumberOfPatternAppearnceInTheData - use this to get the location of a specific apperance in the data
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	A pair with the first entry containing a boolean to describe if the required apperance of the pattern was found in the data or not. If it was
		//		found the the boolean will contain true, and the second entry will contain the index on the data that the pattern was found
		//
		//  Expectations :
		//
		//		1. The sequential platform with the data should be ready 
		//		2. The sequential platform with the data should have a size larger then 0
		//		3. The sequential platform with the pattern should be ready 
		//		4. The sequential platform with the pattern should have a size larger then 0
		//		5. The required apperance number should be larger then 0
		//		6. 
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DataType >
		inline Pair< Boolean, UnsignedInteger64bits > Search::PatternInTheData( const SequentialPlatform_Interface< DataType >& data, const SequentialPlatform_Interface< DataType >& pattern, UnsignedInteger64bits requiredNumberOfPatternAppearnceInTheData )
		{
            // Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertInstanceIsReady_MACRO( data )
			AssertInstanceSizeIsLargerThenZero_MACRO( data )
			AssertInstanceIsReady_MACRO( pattern )
			AssertInstanceSizeIsLargerThenZero_MACRO( pattern )
			Assert_MACRO( ( requiredNumberOfPatternAppearnceInTheData > 0 ), "The given apperance number should be larger then 0" )

			// This pair will store the result of the method. If the required apperance was found it will contain a boolean with the value true and 
			// otherwise false. The second entry will store the index of the required apperance if found
			Pair< Boolean, UnsignedInteger64bits > patternApperancePair_foundOrNotAndIndex;

			// This object will store the result of processing the pattern. It will contain the information on the amount to advance the index on the data
			// in case a mismatch between the data and the pattern was found at a specific index on the pattern
			Pair< UnsignedInteger64bits, HeapPointer< UnsignedInteger64bits > > startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch( MOVE( ProcessPatternToFindTheStartingPointForTheNextSearchIfMismatchWasFoundBetweenThePatternAndTheData__Private< DataType >( pattern ) ) );

			// This object will store the index on the data
			UnsignedInteger64bits dataIndex = 0UL;

			// This object will store the data size minus the pattern size, to prevent calculating it each time
			UnsignedInteger64bits lastIndexOnDataThatThePatternCanStillFitIn = ( data.Size() - pattern.Size() + 1 );

			// This object will store the number of apperances of the pattern already found in the data
			UnsignedInteger64bits numberOfApperancesOfThePatternAlreadyFound = 0UL;

			// Loop until the required apperance was found or the data ended
			while ( dataIndex < lastIndexOnDataThatThePatternCanStillFitIn )
			{
				// Try to find the next apperance of the pattern in the data
				patternApperancePair_foundOrNotAndIndex.Second() = FindNextApperance__Private< DataType >( data, dataIndex, pattern, startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch );

				// Check if the next apperance of the pattern was not found
				if ( patternApperancePair_foundOrNotAndIndex.Second() == data.Size() )
				{
					// The next apperance of the pattern was not found

					// Notify the caller that the required apperance does not exist in the data
					return ( MOVE( patternApperancePair_foundOrNotAndIndex ) );
				}

				// The next apperance of the pattern was found

				// Increment the number of apperance of the pattern found by 1
				numberOfApperancesOfThePatternAlreadyFound += 1UL;

				// Check if the required apperance number was found
				if ( numberOfApperancesOfThePatternAlreadyFound == requiredNumberOfPatternAppearnceInTheData )
				{
					// The required apperance of the pattern in the data was found

					// Set the boolean to true in the pair, to notify the caller that the requied apperance of the pattern was found
					patternApperancePair_foundOrNotAndIndex.First() = true;

					// Break the loop
					break;
				}

				// Set the index on the data to the next index behind the index on which the last apperance of the pattern was found in the data
				dataIndex = patternApperancePair_foundOrNotAndIndex.Second() + 1UL;
			}

			// Return the pair with the result
			return ( MOVE( patternApperancePair_foundOrNotAndIndex ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the location of a specific apperance of the pattern in the data
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. data - a constant reference to a sequential platform
		//			2. pattern - a constant reference to a sequential platform instance that contains information that needs to be found in the data
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	A pair with the first entry containing a boolean to describe if at least one apperance of the pattern was found in the data. If it was
		//		found the the boolean will contain true, and the second entry will contain a list with all the indices on the data that the pattern 
		//		was found
		//
		//  Expectations :
		//
		//		1. The sequential platform with the data should be ready 
		//		2. The sequential platform with the data should have a size larger then 0
		//		3. The sequential platform with the pattern should be ready 
		//		4. The sequential platform with the pattern should have a size larger then 0
		//		5. 
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		template< typename DataType >
		inline Pair< Boolean, HeapPointer< UnsignedInteger64bits > > Search::PatternInTheData( const SequentialPlatform_Interface< DataType >& data, const SequentialPlatform_Interface< DataType >& pattern )
		{
            // Each method that interacts with the user directly needs to ensure that the given data is valid
			AssertInstanceIsReady_MACRO( data )
			AssertInstanceSizeIsLargerThenZero_MACRO( data )
			AssertInstanceIsReady_MACRO( pattern )
			AssertInstanceSizeIsLargerThenZero_MACRO( pattern )

			// This pair will store the result of the method. If the required apperance was found it will contain a boolean with the value true and 
			// otherwise false. The second entry will store the index of the required apperance if found
			Pair< Boolean, HeapPointer< UnsignedInteger64bits > > patternApperancePair_foundOrNotAndIndex;

			// This object will store the result of processing the pattern. It will contain the information on the amount to advance the index on the data
			// in case a mismatch between the data and the pattern was found at a specific index on the pattern
			Pair< UnsignedInteger64bits, UnsignedInteger64bits* > startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch( MOVE( ProcessPatternToFindTheStartingPointForTheNextSearchIfMismatchWasFoundBetweenThePatternAndTheData__Private< DataType >( pattern ) ) );

			// This object will store the index on the data
			UnsignedInteger64bits dataIndex = 0UL;

			// This object will store the data size minus the pattern size, to prevent calculating it each time
			UnsignedInteger64bits lastIndexOnDataThatThePatternCanStillFitIn = ( data.Size() - pattern.Size() + 1 );

			// This object will store current index that an apperance of the pattern was found in the data
			UnsignedInteger64bits currentApperanceOfThePatternInTheDataIndex = 0UL;

			// Loop until the required apperance was found or the data ended
			while ( dataIndex < lastIndexOnDataThatThePatternCanStillFitIn )
			{
				// Try to find the next apperance of the pattern in the data
				currentApperanceOfThePatternInTheDataIndex = FindNextApperance__Private< SequentialPlatform_Interface< DataType > >( data, dataIndex, pattern, startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch );

				// Check if the next apperance of the pattern was not found
				if ( ( currentApperanceOfThePatternInTheDataIndex == data.Size() ) && ( dataIndex == 0UL ) )
				{
					// The next apperance of the pattern was not found

					// Notify the caller that the required apperance does not exist in the data
					return ( MOVE( patternApperancePair_foundOrNotAndIndex ) );
				}

				// The next apperance of the pattern was found

				// Add the index of the current found apperance
				patternApperancePair_foundOrNotAndIndex.Second() = MOVE( AllocateBiggerMemorySpaceCopyTheCurrentIndicesAndFinallyAddAlsoTheNewIndex__Private( MOVE( patternApperancePair_foundOrNotAndIndex.Second() ), currentApperanceOfThePatternInTheDataIndex ) );

				// Set the index on the data to the next index behind the index on which the last apperance of the pattern was found in the data
				dataIndex = currentApperanceOfThePatternInTheDataIndex + 1UL;
			}

			// If control reached here this means that at least one apperance of the pattern in the data was found, set the boolean to true
			patternApperancePair_foundOrNotAndIndex.First() = true;

			// Delete the memory space allocated
			delete[] startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch.Second();

			// Return the pair with the result
			return ( MOVE( patternApperancePair_foundOrNotAndIndex ) );
		}




































//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************




































		// Method Information :
		//
		//  Description :
		//
		//		Use this method each time a new pattern is set into the instance, to process the pattern and make the instance ready to search for
		//		for it in the data
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			pattern - a constant reference to a sequential platform instance that contains information that needs to be found in the data
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
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DataType >
		Pair< UnsignedInteger64bits, HeapPointer< UnsignedInteger64bits > > Search::ProcessPatternToFindTheStartingPointForTheNextSearchIfMismatchWasFoundBetweenThePatternAndTheData__Private( const SequentialPlatform_Interface< DataType >& pattern )
		{

			// The rational :
			//
			// When searching for a pattern in the data, the complexity is large because for each index in the data, the search needs to be made which 
			// can be in the worst case, for 'n' number of entries and 'm' number of entries in the pattern :
			//
			//			O( n * ( m - 1 ) )
			//
			// Which is unwanted.
			//
			// Now, the data is not known in advance, but only the pattern that needs to be found, therefore to optimize the search the pattern will
			// be processed. The general point is to set the amount to increase the index on the data in the next search for every entry in the pattern,
			// if the mismatch between the data and the pattern happend in that entry.
			//
			// The first 2 entries of each pattern always act the same on the increasing of the index on the data for mismatch. For the first entry if
			// it does not match the data then the index on the data must increase by 1 to check the next entry. In the case of the second entry, the
			// amount to advance depends if the first and second entry has the same content. If they do have the same content, then the index on the data
			// can advance by 2, and if they mismatch then only by 1.
			//
			//
			//			Data 		->		hklsdlfslklsda
			//
			//			Pattern    	->    	abcdefg
			//
			//
			//				Try to match 1 :      index of data == 1  index of pattern == 1
			//
			//															hkasdlfslklsda
			//					   mismatch at first entry of pattern	|
			//															abcdefg
			//
			//				Result - index on data needs to be increased by 1
			//
			//
			//				Try to match 2 :      index of data == 2  index of pattern == 1
			//
			//															hkasdlfslklsda
			//					   mismatch at first entry of pattern	 |
			//												 			 abcdefg
			//
			//				Result - index on data needs to be increased by 1
			//
			//
			//				Try to match 3 :      index of data == 3  index of pattern == 1
			//
			//															hkasdlfslklsda
			//					   match at first entry of pattern	      |
			//												 			  abcdefg
			//
			//				Result - index on the pattern needs to be increased by 1
			//
			//
			//				Try to match 3 :      index of data == 3  index of pattern == 2
			//
			//															hkasdlfslklsda
			//					   mismatch at second entry of pattern	   |
			//												 			  abcdefg
			//
			//				Result - index on the pattern needs to be increased by 1
			//
			//
			// The easiest pattern is where all the parts of the pattern are different. In the easiest pattern, each entry beside the first 2, the index
			// on the data at the next search will be increased by the entry index in the pattern. This because what is known that the data match exactly
			// all the previous part of the pattern until the point of the mismatch, each part of the pattern is different so shifting it by any number 
			// smaller then the location of the mismatch will also create mismatch.
			// 
			//
			//			Data 		->		abcdefhhslklsda
			//
			//			Pattern    	->    	abcdefg
			//
			//
			//				Try to match 1 :      index of data == 1  index of pattern == 6
			//
			//															abcdefhhslklsda
			//					   mismatch at first entry of pattern	      |
			//															abcdefg
			//
			//				Result - index on data needs to be increased by 6, as can be seen any other shift will return mismatch :
			//
			//															abcdefhhslklsda
			//					   mismatch at first entry of pattern	 |
			//															 abcdefg
			//
			//															abcdefhhslklsda
			//					   mismatch at first entry of pattern	  |
			//															  abcdefg
			//
			// And so on.
			//
			// In most cases then the next index on the data will be increased by the index of the pattern where the mismatch happend. The cases
			// where this does not apply, is for patterns that contains repeating parts inside them. For example :
			//
			//
			//			Pattern    	->    	abcabcf
			//
			//
			// At this case mismatch at 'f', will allow adding to the index on the data only 3, because all that is known that the data does not contain
			// 'f', but it can contain 'a'. For example :
			//
			//
			//			Data 		->		abcabcabcf
			//
			//			Pattern    	->    	abcabcf
			//
			//				Try to match 1 :      index of data == 1  index of pattern == 6
			//
			//															abcabcabcf
			//					   mismatch at first entry of pattern	      |
			//															abcabcf
			//
			//				Result - index on data needs to be increased by 3 and not by 6, otherwise the apperance of the pattern in the data will be skipped
			//
			//
			// Therefore the processing of the pattern means for each entry of the pattern checking if it contains matching subparts, and setting the amount
			// to increase the index of the data appropriately!
			//
			// Then processing the pattern means for each entry trying to find a subpattern that match the starting of the pattern. For example :
			//
			//
			//			Pattern    	->    	abcabwf
			//
			//			For index 2 :
			//
			//					ab c abwf
			//
			//				The subpatterns are : 
			//
			//					a - b
			//
			//
			// And as can be seen 'a' and 'b' do not match.
			//
			//
			//			For index 3 :
			//
			//					abc a bwf
			//
			//				The subpatterns are : 
			//
			//					ab - bc AND a - c
			//
			//
			// Again the subpatterns do not match.
			//
			//
			//			For index 4 :
			//
			//					abca b wf
			//
			//				The subpatterns are : 
			//
			//					abc - bca AND ab - ca AND a - a
			//
			//
			// Only the last subpattern which consist of 'a' match, but because the mismatch happend with 'b', and also in the beginning of the pattern
			// the next letter after 'a' is 'b', then it won't match anyway and in this case the index on the data can also increase by the index on the
			// pattern.
			//
			//
			//			For index 5 :
			//
			//					abcab w f
			//
			//				The subpatterns are : 
			//
			//					abca - bcab AND abc - cab AND ab - ab AND a - b
			//
			//
			// The subpattern 'ab' match. The mismatch happend at 'w', therefore the index on the data can only increase by 3, becasue in the mismatch
			// it is known that is not 'w', but it can be 'c!


			// This object will store the final result of processing the pattern. Processing the pattern means finding for each entry at the pattern, what to do
			// if a mismatch with the actual data of the container was found. Without this optimization each time a mismatch will be found the search will have to
			// start from the beginning of the pattern, instead this object will tell from which index of entry at the pattern the search should start again. If the
			// pattern size less then 3, this object is redundant
			Pair< UnsignedInteger64bits, HeapPointer< UnsignedInteger64bits > > startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch;

			// Initialize the pair
			startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch.First() = pattern.Size();
			startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch.Second() = MOVE( HeapPointer< UnsignedInteger64bits >( pattern.Size() ) );

			// If the mismatch between the pattern and the data happend in the first entry of the pattern, the index on the data should always be increased
			// by 1
			startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch.Second()[0] = 1UL;

			// Check if the size of the pattern is 1
			if ( pattern.Size() == 1UL )
			{
				// The size of the pattern is 1

				// Nothing else needs to be done
				return ( MOVE( startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch ) );
			}

			// If the mismatch between the pattern and the data happend in the second entry of the pattern, the content of the first and second entry
			// in the pattern needs to be compared. If the content is the same, then the index on the data needs to be advanced by 1, otherwise it
			// can be advanced by 2
			if ( pattern[0] != pattern[1] )
			{
				// The content of the first and second entry of the pattern are not the same

				// Set to advance the index on the data by 1
				startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch.Second()[1] = 1UL;
			}
			else
			{
				// The content of the first and second entry of the pattern are the same

				// Set to advance the index on the data by 2
				startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch.Second()[1] = 2UL;
			}

			// Check if the size of the pattern is 2
			if ( pattern.Size() == 2UL )
			{
				// The size of the pattern is 1

				// Nothing else needs to be done
				return ( MOVE( startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch ) );
			}

			// This object will store the amount the index on the data needs to be incremented by, if a mismatch happend at the current index
			UnsignedInteger64bits incrementIndexOnDataByThisAmount = 0UL;

			// This obejct will store the pattern size plus one, to prevent calculating it each time
			UnsignedInteger64bits patternSize = pattern.Size();

			// Loop on all the entries of the pattern, starting from the third entry
			for ( UnsignedInteger64bits patternIndex = 2UL ; patternIndex < patternSize ; ++patternIndex )
			{
				// Find all the entries before the currrent entry in the pattern where the content match the content of the first entry in the patern

				// Set the amount to increase the index on the data to the current pattern index. This is the general case, if a subpattern will be found
				// it will set this object to the required amount instead
				incrementIndexOnDataByThisAmount = patternIndex;

				// Loop on all the entries of the subpattern up until to the current entry. The first subpattern always start from the second entry of
				// the general pattern
				for ( UnsignedInteger64bits subpatternFirstEntryIndex = 1UL ; subpatternFirstEntryIndex < patternIndex ; ++subpatternFirstEntryIndex )
				{

					// Check if the current subpattern, match the subpattern at the beginning of the pattern. This check if done by asserting if the
					// while loop reached all the way until the stop condition
					if ( CompareSubpatternWithTheSubpatternThatStartAtTheBeginning__Private( pattern, subpatternFirstEntryIndex, ( patternIndex - subpatternFirstEntryIndex ) ) == true ) 
					{
						// A subpattern that match the beginning of the pattern was found 

						// The index on the data then should not be incremented by the pattern index, but rather only the amount to the first entry
						// of the matching subpattern
						incrementIndexOnDataByThisAmount = subpatternFirstEntryIndex;

						// The longest subpattern was found, break the loop
						break;
					}

				}

				// Set the amount that the index on the data needs to be incremented by, if a mismatch happend at the current pattern index
				startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch.Second()[ patternIndex ] = incrementIndexOnDataByThisAmount;
			}

			// Return a copy of the result of processing the pattern
			return ( MOVE( startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch ) );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to compare a subpattern with the subpattern that starts from the beginning of the pattern
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. pattern - a constant reference to a sequential platform instance that contains information that needs to be found in the data
		//			2. subpatternFirstEntryIndex - the index of the first entry of the subpattern
		//			3. subpatternSize - the size of the subpattern to compare
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	True if the subpattern match the subpattern with the same size that starts from the beginning, and false otherwise
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DataType >
		inline Boolean Search::CompareSubpatternWithTheSubpatternThatStartAtTheBeginning__Private( const SequentialPlatform_Interface< DataType >& pattern, UnsignedInteger64bits subpatternFirstEntryIndex, UnsignedInteger64bits subpatternSize ) 
		{

			// Loop on all the entries of the subpattern
			for ( UnsignedInteger64bits subpatternIndex = 0UL ; subpatternIndex < subpatternSize ; ++subpatternIndex )
			{

				// Check if the content of the current entry in the subpattern match the content of the equivalent entry of the subpattern
				// that starts from the beginning of the pattern
				if ( pattern[ subpatternIndex ] != pattern[ subpatternFirstEntryIndex + subpatternIndex ] )
				{
					// The content does not match

					// Return that the subpatterns are not the same
					return ( false );
				}

			}

			// If control of the method reached here then the subpatterns match
			return ( true );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to get the location of the next apperance of the pattern in the data. The search will start from the given index on the data
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. pattern - a constant reference to a sequential platform instance that contains information that needs to be found in the data
		//			2. startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch - the result of processing the data
		//			3. startSearchFromThisIndexOnTheData - the index on the data from which the search for the data will start
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//   	The index of the next apperance of the pattern in the data. If no apperance was found then the size of the data will be returned
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		They will come
		//
		template< typename DataType >
		inline UnsignedInteger64bits Search::FindNextApperance__Private( const SequentialPlatform_Interface< DataType >& data, UnsignedInteger64bits startSearchFromThisIndexOnTheData, const SequentialPlatform_Interface< DataType >& pattern, Pair< UnsignedInteger64bits, HeapPointer< UnsignedInteger64bits > >& startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch )
		{
			// This object will store the index on the data
			UnsignedInteger64bits dataIndex = startSearchFromThisIndexOnTheData;

			// This object will store the index on the pattern
			UnsignedInteger64bits patternIndex = 0UL;

			// This object will store the data size minus the pattern size, to prevent calculating it each time
			UnsignedInteger64bits dataSizeMinusPatternSize = ( data.Size() - pattern.Size() );

			// Loop on the data starting at the given index
			while ( dataIndex < dataSizeMinusPatternSize )
			{
				// Set the index on the pattern to 0
				patternIndex = 0UL;

				// Loop on the pattern
				while ( patternIndex < pattern.Size() )
				{
					
					// Check if the current entry in the pattern match the data
					if ( data[ dataIndex ] != pattern[ patternIndex ] )
					{
						// The data and the pattern does not match

						// Break the loop
						break;
					}

					// Increment the index on the pattern by 1
					patternIndex += 1UL;
				}

				// Check if the pattern was currently found in the data, by checking if the loop passed on all the pattern
				if ( patternIndex == pattern.Size() )
				{
					// An apperance of the pattern in the data was found

					// Return the index on the data
					return ( dataIndex );
				}

				// The current location in the data does not contain the pattern, advance to the next location to search for it
				dataIndex += startSearchAgainAtThisIndexOfThePatternIfReachedToThisIndexOnThePatternInLastSearch.Second()[ patternIndex ];
			}

			// If control reached here this means the pattern was not found in the data, return the size of the data
			return ( data.Size() );
		}


		// Method Information :
		//
		//  Description :
		//
		//      Use this method to copy the apperances indices found so far to a larger memory space, and add the new apperance index found
		//
		//  Required arguments :
		//
		//      User information needed :
		//
		//			1. apperancesIndices - a copy of a heap pointer with all the apperances indices
		//			2. currentApperanceOfThePatternInTheDataIndex - the index in which the current apperance was found
		//
		//      Information returned to the user :
		//
		//          NONE
		//
		//  Return value :
		//
		//		A heap pointer instance copy with the all the apperances indcies
		//
		//  Expectations :
		//
		//		NONE
		//
		//  Possible errors :
		//
		//		1. There is no more free memory space - Class std::bad_alloc is thrown
		//		2. 
		//
		inline HeapPointer< UnsignedInteger64bits > Search::AllocateBiggerMemorySpaceCopyTheCurrentIndicesAndFinallyAddAlsoTheNewIndex__Private( const HeapPointer< UnsignedInteger64bits > apperancesIndices, UnsignedInteger64bits currentApperanceOfThePatternInTheDataIndex )
		{
			// Allocate a memory space bigger by 1 entry
			HeapPointer< UnsignedInteger64bits > apperancesIndicesWithNewIndex( apperancesIndices.Size() + 1UL );

			// Copy all the indices apperances to the new memory space
			Memory::Operations::Copy< UnsignedInteger64bits >( apperancesIndices, apperancesIndicesWithNewIndex, apperancesIndices.Size() );

			// Add the new apperance index			
			apperancesIndicesWithNewIndex[ apperancesIndices.Size() ] = currentApperanceOfThePatternInTheDataIndex;

			// Return the apperances indices plus the new apperance index
			return ( MOVE( apperancesIndicesWithNewIndex ) );
		}











    }  //  Namespace Memory

}  //  Namespace Universe


#endif  // SEARCH_HPP