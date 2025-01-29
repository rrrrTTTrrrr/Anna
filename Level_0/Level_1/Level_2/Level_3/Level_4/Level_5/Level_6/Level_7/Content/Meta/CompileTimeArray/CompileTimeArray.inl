//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
constexpr CompileTimeArray< NumericType, Values... >::CompileTimeArray()
{}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
constexpr LargestUnsignedInteger CompileTimeArray< NumericType, Values... >::Size() const
{
	// Return the number of values in the template pack
	return ( sizeof...( Values ) );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< LargestUnsignedInteger Index > requires ( Index < sizeof...( Values ) )
constexpr NumericType CompileTimeArray< NumericType, Values... >::Entry() const
{
	// Pill the types one by one using compile time recursive calls, until the index reaches 0 and than return the exposed type
	return ( Entry__Private< Index, Values... >() );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< NumericType Value >
constexpr Boolean CompileTimeArray< NumericType, Values... >::DoesValueExist() const
{
	// Use fold expressions to calculate the sum, and return the result
	return ( DoesValueExist__Private< Value, Values... >() );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
constexpr NumericType CompileTimeArray< NumericType, Values... >::Maximum() const
{
	// Find the maximum value and return the result
	return ( Maximum__Private< Values... >() );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
constexpr NumericType CompileTimeArray< NumericType, Values... >::Minimum() const
{
	// Find the minimum value and return the result
	return ( Minimum__Private< Values... >() );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
constexpr NumericType CompileTimeArray< NumericType, Values... >::Sum() const
{
	// Use fold expressions to calculate the sum, and return the result
	return ( Values + ... );
}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
constexpr Boolean CompileTimeArray< NumericType, Values... >::operator==( const SelfType& other ) const
{
	// As we only accept intances of the same object, it contains the same values. Return true 
	return ( true );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< typename OtherCompileTimeArrayType > requires ( CompareRegardlessOfTemplateArguments< OtherCompileTimeArrayType, CompileTimeArray< NumericType, Values... > >::Result )
constexpr Boolean CompileTimeArray< NumericType, Values... >::operator==( const OtherCompileTimeArrayType& other ) const
{
	// As we only accept intances of different objects, they don't contain the same values. Return false
	return ( false );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
constexpr Boolean CompileTimeArray< NumericType, Values... >::operator!=( const SelfType& other ) const
{
	// As we only accept intances of the same object, it contains the same values. Return false
	return ( false );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< typename OtherCompileTimeArrayType > requires ( CompareRegardlessOfTemplateArguments< OtherCompileTimeArrayType, CompileTimeArray< NumericType, Values... > >::Result )
constexpr Boolean CompileTimeArray< NumericType, Values... >::operator!=( const OtherCompileTimeArrayType& other ) const
{
	// As we only accept intances of different objects, they don't contain the same values. Return true
	return ( true );
}



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< LargestUnsignedInteger Index, NumericType ExposedValue, NumericType... RestOfValues > requires ( ( Index < sizeof...( Values ) ) && ( Index > 0 ) )
constexpr NumericType CompileTimeArray< NumericType, Values... >::Entry__Private() const
{
	// Pill the types one by one be compile time recursive calls, until the index reaches 0 and than return the exposed type
	return ( Entry__Private< Index - 1, RestOfValues... >() );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< LargestUnsignedInteger Index, NumericType ExposedValue, NumericType... RestOfValues > requires ( Index == 0 )
constexpr NumericType CompileTimeArray< NumericType, Values... >::Entry__Private() const
{
	// Return the exposed type
	return ( ExposedValue );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< NumericType Value, NumericType ExposedValue, NumericType NextExposedValue, NumericType... RestOfValues >
constexpr Boolean CompileTimeArray< NumericType, Values... >::DoesValueExist__Private() const
{
	// Compare the exposed type and return the result
	return ( Value == ExposedValue || DoesValueExist__Private< Value, NextExposedValue, RestOfValues... >() );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< NumericType Value, NumericType ExposedValue >
constexpr Boolean CompileTimeArray< NumericType, Values... >::DoesValueExist__Private() const
{
	// Compare the exposed type and return the result
	return ( Value == ExposedValue );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< NumericType FirstExposedValue, NumericType SecondExposedValue, NumericType NextExposedValue, NumericType... RestOfValues >
constexpr NumericType CompileTimeArray< NumericType, Values... >::Maximum__Private() const
{
	// Compare the first and seconds exposed values and use the larger one for the compile time recursive call to be compared with the next value in the
	// template pack until the last two, which will call the base case to stop the recurssion and will return the maximum value
	return ( FirstExposedValue >= SecondExposedValue ? Maximum__Private< FirstExposedValue, NextExposedValue, RestOfValues... >() : Maximum__Private< SecondExposedValue, NextExposedValue, RestOfValues... >() );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< NumericType FirstExposedValue, NumericType SecondExposedValue >
constexpr NumericType CompileTimeArray< NumericType, Values... >::Maximum__Private() const
{
	// Compare the first and seconds exposed values and return the larger one
	return ( FirstExposedValue >= SecondExposedValue ? FirstExposedValue : SecondExposedValue );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< NumericType FirstExposedValue, NumericType SecondExposedValue, NumericType NextExposedValue, NumericType... RestOfValues >
constexpr NumericType CompileTimeArray< NumericType, Values... >::Minimum__Private() const
{
	// Compare the first and seconds exposed values and use the smaller one for the compile time recursive call to be compared with the next value in the
	// template pack until the last two, which will call the base case to stop the recurssion and will return the minimum value
	return ( FirstExposedValue <= SecondExposedValue ? Minimum__Private< FirstExposedValue, NextExposedValue, RestOfValues... >() : Minimum__Private< SecondExposedValue, NextExposedValue, RestOfValues... >() );
}


template< Concepts::Numeric NumericType, NumericType... Values > requires ( sizeof...( Values ) > 0 )
template< NumericType FirstExposedValue, NumericType SecondExposedValue >
constexpr NumericType CompileTimeArray< NumericType, Values... >::Minimum__Private() const
{
	// Compare the first and seconds exposed values and return the smaller one
	return ( FirstExposedValue <= SecondExposedValue ? FirstExposedValue : SecondExposedValue );
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< Concepts::Numeric NumericType COMMA NumericType... Values > requires ( sizeof...( Values ) > 0 )
	void CompileTimeArray< NumericType COMMA Values... >::UnitTest()
	{
		CompileTimeArray< LargestUnsignedInteger COMMA 8UL COMMA 9UL COMMA 10UL COMMA 11UL COMMA 1214UL > testCompileTimeArray_0;

		std::cout << testCompileTimeArray_0.Maximum() << std::endl;
		std::cout << testCompileTimeArray_0.Minimum() << std::endl;
		std::cout << testCompileTimeArray_0.Sum() << std::endl;
		std::cout << testCompileTimeArray_0.DoesValueExist< 10UL >() << std::endl;
		std::cout << testCompileTimeArray_0.DoesValueExist< 11111UL >() << std::endl;
		std::cout << testCompileTimeArray_0.Entry< 0UL >() << std::endl;
		std::cout << testCompileTimeArray_0.Entry< 1UL >() << std::endl;
	}

)  //  End of debug tool



}  //  Namespace Universe