#include <iostream> 
#include <vector>

using namespace std;



// void Per( int* arr, int size )
// {
// 	for ( int index = 0 ; index < size ; ++index )
// 	{
// 		cout << arr[ index ] << " ";
// 	}

// 	cout << endl;

// 	int* arr1 = new int[ size - 1 ];

// 	if ( size == 1 )
// 	{
// 		return;
// 	}

// 	Per( arr + 1, size - 1 );
// 	Per( arr, size - 1 );

// 	if ( size == 3 )
// 	{
// 		arr1[0] = arr[0];
// 		arr1[1] = arr[2];

// 		Per( arr1, size - 1 );
// 	}

// }

int find( vector< vector< int > >& vec )
{
	for ( unsigned long index = 0 ; index < vec.size() ; ++index )
	{
		if ( vec[index].size() == 0 )
		{
			return ( index );
		}
	}

	return ( ~0 );
}


void PerRec( int* arr, int size, vector< vector< int > >& thisPer )
{
	int find1 = find( thisPer );

	if ( find1 == ~0 )
	{
		return;
	}

	if ( size == 1 )
	{
		thisPer[find1].push_back( *arr );

		return;
	}

	PerRec( arr + 1, size - 1, thisPer );
	PerRec( arr, size - 1, thisPer );

}


vector< vector< int > > Per( int* arr, int size )
{
	vector< vector< int > > thisPer;

	thisPer.push_back( vector( arr[ size - 1 ];

	for ( int index = size - 2 ; index < ; ++index )
	{
		for ( int index2 = 0 ;  )
	}

	return ( thisPer );
}








int main()  
{
	int arr[3] = {1,2,3};

	vector< vector< int > > p = Per( arr, 3 );

	for ( unsigned long index = 0 ; index < p.size() ; ++index )
	{
		for ( unsigned long index2 = 0 ; index2 < p[index].size() ; ++index2 )
		{
			cout << p[index][index2] << " ";
		}

		cout << endl;
	}

	return ( 0 );
}