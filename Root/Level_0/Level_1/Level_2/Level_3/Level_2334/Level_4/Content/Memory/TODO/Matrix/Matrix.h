#ifndef  __MATRICS__H_
#define  __MATRICS__H_

#include <iostream>  //  cout  
#include <sys/types.h>  //  size_t  
#include <vector>  //  std::vector  
#include <cassert>  //  assert  
#include <memory>  //  std::shared_ptr  

namespace Universe 
{ 


template< typename T >
class Matrix 
{ 
public: 

	// For divison use 1 / value in multiplication

	// The matrix's elements will be set to setInitialValue
	inline Matrix( size_t numOfRows, size_t numOfColumns, T setInitialValue );   // Non-explicit on purpose
	inline Matrix( size_t numOfRows, size_t numOfColumns );                      // Non-explicit on purpose
	inline Matrix( const Matrix& other );
	inline Matrix& operator=( const Matrix& other );

	void DispalyMatrix() const;

	void SetMatrixToSpecificValue( const T value );

	// The matrix must be square
	void SetMainDiagonalToValue( const T value );  // Top left to bottom right diagonal

	// The matrix must be square
	void SetSecondaryDiagonalToValue( const T value );    // Top right to bottom left diagonal

	void SetSpecificRowToValue( size_t row, const T value );
	void SetSpecificColumnToValue( size_t column, const T value );
	inline void SetSpecificElement( size_t row, size_t column, T value );

	// The matrix must be square
	// The type must be contigous and have [] operator to accesses the elements
	template< typename O >
	void SetMainDiagonal( const O& mainDiagonal );  // Top left to bottom right diagonal
	
	// The matrix must be square
	// The type must be contigous and have [] operator to accesses the elements
	template< typename O >
	void SetSecondaryDiagonal( const O& mainDiagonal );    // Top right to bottom left diagonal
	
	// The type must be contigous and have [] operator to accesses the elements
	template< typename O >
	void SetSpecificRow( size_t row, const O& other );

	// The type must be contigous and have [] operator to accesses the elements
	template< typename O >
	void SetSpecificColumn( size_t column, O& other );

	inline size_t GetNumOfRows() const;
	inline size_t GetNumOfColumns() const;

	// Change Matrix dimensions
	void ChangeRowNumber( size_t NumOfRowsToAdd );
	void ChangeColumnNumber( size_t NumOfColumnsToAdd );

	void GetSubMatrix( Matrix& subMatrix, size_t upperRow, size_t lowerRow, size_t rightColumn, size_t leftColumn ) const;
	Matrix<T>& GetMainDiagonal() const;  // Top left to bottom right diagonal
	Matrix<T>& GetSecondaryDiagonal() const;    // Top right to bottom left diagonal
	Matrix<T>& GetSpecificRow( size_t row ) const;
	Matrix<T>& GetSpecificColumn( size_t column ) const;
	T GetSpecificElement( size_t row, size_t column ) const;

	void MultiplyMatrixByValue( T value );
	void AddMatrixByValue( T value );
	void SubtractMatrixByValue( T value );

	void MultiplyRowByValue( size_t row, T value );
	void MultiplyColumnByValue( size_t column, T value );
	void AddRowByValue( size_t row, T value );
	void AddColumnByValue( size_t column, T value );
	void SubtractRowByValue( size_t row, T value );
	void SubtractColumnByValue( size_t column, T value );

	inline void MultiplyElementByValue( size_t row, size_t column, T value );
	inline void AddElementByValue( size_t row, size_t column, T value );
	inline void SubtractElementByValue( size_t row, size_t column, T value );

	// Operation options:
	// 1 Multiply
	// 2 Add
	// 3 Subtract
	void AddRows( size_t row1, int operation1, T value1, size_t row2, int operation2, T value2 );
	void AddClumns( size_t column1, int operation1, T value1, size_t column2, int operation2, T value2 );
	void SubtractRows( size_t row1, int operation1, T value1, size_t row2, int operation2, T value2 );
	void SubtractColumns( size_t column1, int operation1, T value1, size_t column2, int operation2, T value2 );

	void SwapRows( size_t row1, size_t row2 );
	void SwapColumns( size_t column1, size_t column2 );

	void TransposeMatrix();

	// The matrix must be square
	T DeterminantMatrix();

	// The matrix must be square
	std::vector<T> EigenValues() const;
	Matrix EigenVectors() const;

	// The matrix must be square
	// Use this if the desired outcome needed to be saved ( the former matrix will be changed )
	void Diagonalization();

	// The matrix must be square
	// Use this to only calculate the diagonalization matrix but not change the current state
	Matrix& Diagonalization() const;

	// The matrix must be square 
	// Return 0 on success, and 1 if the matrix can not be inversed
	int InverseMatrix();

	// This matrix must have an equal number of rows to the number of columns in the other matrix
	Matrix& operator*=( const Matrix& other );

	// Matrices must be of equal size N*M
	Matrix& operator-=( const Matrix& other );
	Matrix& operator+=( const Matrix& other );

	// For matrix with one row 
	T& operator[]( size_t elementNumber );

private: 

	std::shared_ptr< std::vector< std::vector<T> > > m_matrix;

	// Copy the matrix in case a change needs to be made
	void ChangeSharedPtrIMP();

	void CopyMatrixIMP( const Matrix& other ) const;

};

// This matrix must have an equal number of rows to the number of columns in the other matrix
template < typename T >
Matrix<T>& MatricesMultiPlication( const Matrix<T>& m1, const Matrix<T>& m2 );

// Matrices must be of equal size N*M
template < typename T >
Matrix<T>& MatricesAddition( const Matrix<T>& m1, const Matrix<T>& m2 );

// Matrices must be of equal size N*M
template < typename T >
Matrix<T>& MatricesSubtraction( const Matrix<T>& m1, const Matrix<T>& m2 );

template< typename T >
std::shared_ptr< std::vector< std::vector<T> > > AllocateMatrixIMP( size_t numOfRows, size_t numOfColumns );



/***************************************************************************************************************************************
 **                                   Mmember Functions Implementation                                                                **
 ***************************************************************************************************************************************/


template< typename T >
inline Matrix<T>::Matrix( size_t numOfRows, size_t numOfColumns, T setInitialValue ) : 
m_matrix( AllocateMatrixIMP<T>( numOfRows, numOfColumns) ) 
{
	SetMatrixToSpecificValue( setInitialValue );
}

template< typename T >
inline Matrix<T>::Matrix( size_t numOfRows, size_t numOfColumns ) : 
m_matrix( AllocateMatrixIMP<T>( numOfRows, numOfColumns) )
{}

template< typename T >
inline Matrix<T>::Matrix( const Matrix& other ) : 
m_matrix( other.m_matrix ) 
{
	CopyMatrixIMP( other );
}

template< typename T >
inline Matrix<T>& Matrix<T>::operator=( const Matrix& other )
{
	m_matrix = other.m_matrix;

	return ( *this );
}

#error
template< typename T >
void Matrix<T>::ChangeRowNumber( size_t NumOfRowsToAdd )
{
	assert( NumOfRowsToAdd > 0 );


}

template< typename T >
void Matrix<T>::SetMainDiagonalToValue( const T value )
{
	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	assert( matrix.size() == matrix[0].size() );

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][indexRows] = value;

		++indexRows;
	}

}

template< typename T >
Matrix<T>& Matrix<T>::GetMainDiagonal() const
{
	size_t diagonalLength = (*m_matrix.get()).size();
	size_t indexMatrix = 0;

	Matrix* retMatrix = new Matrix( 1, diagonalLength );

	std::vector<T>& handleRetMatrix = (*retMatrix->m_matrix.get())[0];
	std::vector< std::vector<T> >& handleMatrix = *m_matrix.get();

	while ( indexMatrix < diagonalLength )
	{
		handleRetMatrix[indexMatrix] = handleMatrix[indexMatrix][indexMatrix];

		++indexMatrix;
	}

	return ( *retMatrix );
}

template< typename T >
Matrix<T>& Matrix<T>::GetSpecificRow( size_t row ) const
{
	assert( row > 0 ); assert( row <= (*m_matrix.get()).size() );

	size_t columnLength = (*m_matrix.get()).size();
	size_t indexMatrix = 0;

	Matrix* retMatrix = new Matrix( 1, columnLength );

	std::vector<T>& handleRetMatrix = (*retMatrix->m_matrix.get())[0];
	std::vector<T>& handleMatrix = (*m_matrix.get())[row - 1];

	while ( indexMatrix < columnLength )
	{
		handleRetMatrix[indexMatrix] = handleMatrix[indexMatrix];

		++indexMatrix;
	}

	return ( *retMatrix );
}

template< typename T >
T Matrix<T>::GetSpecificElement( size_t row, size_t column ) const
{
	return ( (*m_matrix.get())[row - 1][column - 1] );
}

template< typename T >
Matrix<T>& Matrix<T>::GetSpecificColumn( size_t column ) const
{
	assert( column > 0 ); assert( column <= (*m_matrix.get())[0].size() );

	size_t rowLength = (*m_matrix.get()).size();
	size_t indexMatrix = 0;

	Matrix* retMatrix = new Matrix( 1, rowLength );

	std::vector<T>& handleRetMatrix = (*retMatrix->m_matrix.get())[0];
	std::vector< std::vector<T> >& handleMatrix = *m_matrix.get();

	while ( indexMatrix < rowLength )
	{
		handleRetMatrix[indexMatrix] = handleMatrix[indexMatrix][column - 1];

		++indexMatrix;
	}

	return ( *retMatrix );
}

template< typename T >
Matrix<T>& Matrix<T>::GetSecondaryDiagonal() const
{
	size_t diagonalLength = (*m_matrix.get()).size();
	size_t indexMatrix = 0;

	Matrix* retMatrix = new Matrix( 1, diagonalLength );

	std::vector<T>& handleRetMatrix = (*retMatrix->m_matrix.get())[0];
	std::vector< std::vector<T> >& handleMatrix = *m_matrix.get();

	while ( indexMatrix < diagonalLength )
	{
		handleRetMatrix[indexMatrix] = handleMatrix[diagonalLength - indexMatrix - 1][indexMatrix];

		++indexMatrix;
	}

	return ( *retMatrix );
}

template< typename T >
template< typename O >
void Matrix<T>::SetMainDiagonal( const O& mainDiagonal )
{
	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	assert( matrix.size() == matrix[0].size() );

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][indexRows] = mainDiagonal[indexRows];

		++indexRows;
	}

}

template< typename T >
template< typename O >
void Matrix<T>::SetSecondaryDiagonal( const O& secondaryDiagonal )
{
	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	assert( matrix.size() == matrix[0].size() );

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][numOfRows - indexRows - 1] = secondaryDiagonal[indexRows];

		++indexRows;
	}

}

template< typename T >
template< typename O >
void Matrix<T>::SetSpecificRow( size_t row, const O& other )
{
	assert( row > 0 ); assert( row <= (*m_matrix.get()).size() );

	ChangeSharedPtrIMP();

	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][numOfRows - indexRows - 1] = other[indexRows];

		++indexRows;
	}

	
}

template< typename T >
void Matrix<T>::SetSecondaryDiagonalToValue( const T value )
{
	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	assert( matrix.size() == matrix[0].size() );

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][numOfRows - indexRows - 1] = value;

		++indexRows;
	}

}

template< typename T >
inline void Matrix<T>::SetSpecificElement( size_t row, size_t column, T value )
{
	(*m_matrix.get())[row - 1][column - 1] = value;
}

template< typename T >
void Matrix<T>::GetSubMatrix( Matrix& subMatrix, size_t upperRow, size_t lowerRow, size_t rightColumn, size_t leftColumn ) const
{
	assert( upperRow < lowerRow ); assert( rightColumn > leftColumn ); assert( upperRow >= 0 ); assert( rightColumn >= 0 );

	size_t indexRows = upperRow - 1;
	size_t indexColumns = 0;

	std::vector< std::vector<T> >& handleSubMatrix = *subMatrix.m_matrix.get();
	std::vector< std::vector<T> >& handleMatrix = *m_matrix.get();

	while ( indexRows < lowerRow )
	{

		for ( indexColumns = leftColumn - 1 ; indexColumns < rightColumn ; ++indexColumns )
		{
			handleSubMatrix[indexRows - upperRow + 1][indexColumns - leftColumn + 1] = handleMatrix[indexRows][indexColumns];
		}

		++indexRows;
	}

}

template< typename T >
inline size_t Matrix<T>::GetNumOfRows() const
{
	return ( (*m_matrix.get()).size() );
}

template< typename T >
inline size_t Matrix<T>::GetNumOfColumns() const
{
	return ( (*m_matrix.get())[0].size() );
}

template< typename T >
void Matrix<T>::SetSpecificRowToValue( size_t row, const T value )
{
	assert( row > 0 ); assert( row <= (*m_matrix.get()).size() );

	ChangeSharedPtrIMP();

	size_t indexColumns = 0;
	size_t numOfColumns = (*m_matrix.get())[0].size();

	std::vector< std::vector<T> >& mRow = (*m_matrix.get());

	while ( indexColumns < numOfColumns )
	{
		mRow[row - 1][indexColumns] = value;

		++indexColumns;
	}

}

template< typename T >
void Matrix<T>::SetMatrixToSpecificValue( const T value )
{
	ChangeSharedPtrIMP();

	size_t indexRows = 1;
	size_t numOfRows = (*m_matrix.get()).size();

	while ( indexRows <= numOfRows )
	{
		SetSpecificRowToValue( indexRows, value );

		++indexRows;
	}

}

template< typename T >
void Matrix<T>::DispalyMatrix() const
{
	size_t indexRows = 0;
	size_t indexColumns = 0;

	size_t numOfRows = (*m_matrix.get()).size();
	size_t numOfColumns = (*m_matrix.get())[0].size();

	while ( indexRows < numOfRows )
	{
		std::vector<T>& currRow = (*m_matrix.get())[indexRows];

		for ( indexColumns = 0 ; indexColumns < numOfColumns ; ++indexColumns )
		{
			std::cout << currRow[indexColumns] << " ";
		}

		std::cout << std::endl;

		++indexRows;
	}

}

template< typename T >
void Matrix<T>::MultiplyMatrixByValue( T value )
{
	ChangeSharedPtrIMP();

	size_t indexRows = 0;
	size_t indexColumns = 0;

	size_t numOfRows = (*m_matrix.get()).size();
	size_t numOfColumns = (*m_matrix.get())[0].size();

	while ( indexRows < numOfRows )
	{
		std::vector<T>& currRow = (*m_matrix.get())[indexRows];

		for ( indexColumns = 0 ; indexColumns < numOfColumns ; ++indexColumns )
		{
			currRow[indexColumns]*= value;
		}

		++indexRows;
	}

}

template< typename T >
void Matrix<T>::AddMatrixByValue( T value )
{
	ChangeSharedPtrIMP();

	size_t indexRows = 0;
	size_t indexColumns = 0;

	size_t numOfRows = (*m_matrix.get()).size();
	size_t numOfColumns = (*m_matrix.get())[0].size();

	while ( indexRows < numOfRows )
	{
		std::vector<T>& currRow = (*m_matrix.get())[indexRows];

		for ( indexColumns = 0 ; indexColumns < numOfColumns ; ++indexColumns )
		{
			currRow[indexColumns]+= value;
		}

		++indexRows;
	}

}

template< typename T >
void Matrix<T>::SubtractMatrixByValue( T value )
{
	ChangeSharedPtrIMP();

	size_t indexRows = 0;
	size_t indexColumns = 0;

	size_t numOfRows = (*m_matrix.get()).size();
	size_t numOfColumns = (*m_matrix.get())[0].size();

	while ( indexRows < numOfRows )
	{
		std::vector<T>& currRow = (*m_matrix.get())[indexRows];

		for ( indexColumns = 0 ; indexColumns < numOfColumns ; ++indexColumns )
		{
			currRow[indexColumns]-= value;
		}

		++indexRows;
	}

}

template< typename T >
void Matrix<T>::MultiplyRowByValue( size_t row, T value )
{
	assert( row > 0 ); assert( row <= (*m_matrix.get()).szie() );

	ChangeSharedPtrIMP();

	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	size_t numOfColumns = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfColumns )
	{
		matrix[indexRows][numOfColumns - indexRows - 1] *= value;

		++indexRows;
	}

}

template< typename T >
void Matrix<T>::MultiplyColumnByValue( size_t column, T value )
{
	assert( column > 0 ); assert( column <= (*m_matrix.get())[0].size() );

	ChangeSharedPtrIMP();

	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][column] *= value;

		++indexRows;
	}

}

template< typename T >
void Matrix<T>::AddRowByValue( size_t row, T value )
{
	assert( row > 0 ); assert( row <= (*m_matrix.get()).szie() );

	ChangeSharedPtrIMP();

	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][numOfRows - indexRows - 1] += value;

		++indexRows;
	}
	
}
template< typename T >
void Matrix<T>::AddColumnByValue( size_t column, T value )
{
	assert( column > 0 ); assert( column <= (*m_matrix.get())[0].size() );

	ChangeSharedPtrIMP();

	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][column] += value;

		++indexRows;
	}
	
}

template< typename T >
void Matrix<T>::SubtractRowByValue( size_t row, T value )
{
	assert( row > 0 ); assert( row <= (*m_matrix.get()).szie() );

	ChangeSharedPtrIMP();

	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][numOfRows - indexRows - 1] -= value;

		++indexRows;
	}
	
}

template< typename T >
void Matrix<T>::SubtractColumnByValue( size_t column, T value )
{
	assert( column > 0 ); assert( column <= (*m_matrix.get())[0].size() );

	ChangeSharedPtrIMP();

	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][column] -= value;

		++indexRows;
	}
	
}

template< typename T >
inline void Matrix<T>::MultiplyElementByValue( size_t row, size_t column, T value )
{
	(*m_matrix.get())[row - 1][column - 1] *= value;
}

template< typename T >
inline void Matrix<T>::AddElementByValue( size_t row, size_t column, T value )
{
	(*m_matrix.get())[row - 1][column - 1] += value;
}
template< typename T >
inline void Matrix<T>::SubtractElementByValue( size_t row, size_t column, T value )
{
	(*m_matrix.get())[row - 1][column - 1] -= value;
}

template< typename T >
void Matrix<T>::SwapRows( size_t row1, size_t row2 )
{
	int vecSize = (*m_matrix.get()).size();

	assert( row1 > 0 ); assert( row2 > 0 ); assert( row1 != row2 );
	assert( row1 <= vecSize ); assert( row2 <= vecSize );

	ChangeSharedPtrIMP();

	std::vector<T> tempVec( (*m_matrix.get())[row1 - 1] );

	(*m_matrix.get())[row1 - 1] = (*m_matrix.get())[row2 - 1];

	(*m_matrix.get())[row2 - 1] = tempVec;
}

template< typename T >
void Matrix<T>::SwapColumns( size_t column1, size_t column2 )
{
	int vecSize = (*m_matrix.get())[0].size();

	assert( column1 > 0 ); assert( column2 > 0 ); assert( column1 != column2 );
	assert( column1 <= vecSize ); assert( column2 <= vecSize );

	ChangeSharedPtrIMP();

	Matrix<T> tempMat( GetSpecificColumn( column1 ) );

	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	size_t indexRows = 0;

	while ( indexRows < vecSize )
	{
		matrix[indexRows][column1 - 1] = matrix[indexRows][column2 - 1];

		++indexRows;
	}

	SetSpecificColumn< Matrix<T> >( column2, tempMat ); 
}

template< typename T >
template< typename O >
void Matrix<T>::SetSpecificColumn( size_t column, O& other )
{
	assert( column > 0 ); assert( column <= (*m_matrix.get())[0].size() );

	ChangeSharedPtrIMP();

	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][column] = other[indexRows];

		++indexRows;
	}

}

template< typename T >
void Matrix<T>::SetSpecificColumnToValue( size_t column, const T value )
{
	assert( column > 0 ); assert( column <= (*m_matrix.get())[0].size() );

	ChangeSharedPtrIMP();

	std::vector< std::vector<T> >& matrix = *m_matrix.get();

	size_t numOfRows = matrix.size();
	size_t indexRows = 0;

	while ( indexRows < numOfRows )
	{
		matrix[indexRows][column] = value;

		++indexRows;
	}

}

#error 
template< typename T >
void Matrix<T>::TransposeMatrix()
{
	Matrix<T> tempMatrix( *this );


}

template< typename T >
T& Matrix<T>::operator[]( size_t elementNumber ) 
{
	return ( (*m_matrix.get())[0][elementNumber] );
}



/***************************************************************************************************************************************
 **                               Support Functions Implementation                                                                    **
 ***************************************************************************************************************************************/



template< typename T >
std::shared_ptr< std::vector< std::vector<T> > > AllocateMatrixIMP( size_t numOfRows, size_t numOfColumns )
{
	assert( numOfRows != 0 ); assert( numOfColumns != 0 );

	std::shared_ptr< std::vector< std::vector<T> > > matrix( new std::vector< std::vector<T> >( numOfRows ) );

	size_t indexMatrix = 0;

	while ( indexMatrix < numOfRows )
	{
		(*matrix.get())[indexMatrix].resize( numOfColumns );

		++indexMatrix;
	}

	return (  matrix );
}

template< typename T >
void Matrix<T>::CopyMatrixIMP( const Matrix& other ) const
{
	size_t numOfRows = other.GetNumOfRows();
	size_t indexRows = 0; 

	while ( indexRows < numOfRows )
	{
		(*m_matrix.get())[indexRows] = (*other.m_matrix.get())[indexRows];

		++indexRows;
	}
}

template< typename T >
void Matrix<T>::ChangeSharedPtrIMP()
{

	if ( m_matrix.use_count() > 1 )
	{
		Matrix swapMatrix( (*m_matrix.get()).size(), (*m_matrix.get())[0].size(), 0 );

		swapMatrix.CopyMatrixIMP( *this );

		m_matrix = swapMatrix.m_matrix;
	}

}


 
}

 #endif  // __MATRICS__H_
