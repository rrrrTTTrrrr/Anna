//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



	inline Vertex_2D::Vertex_2D() :
		member_firstDimensionPosition( 0.0 ),
		member_secondDimensionPosition( 0.0 )
	{}


	inline Vertex_2D::Vertex_2D( const FloatingPoint64bits firstDimensionPosition, const FloatingPoint64bits secondDimensionPosition ) :
		member_firstDimensionPosition( firstDimensionPosition ),
		member_secondDimensionPosition( secondDimensionPosition )
	{}


	inline Vertex_2D::Vertex_2D( const SelfType& other ) :
		member_firstDimensionPosition( other.member_firstDimensionPosition ),
		member_secondDimensionPosition( other.member_secondDimensionPosition )
	{}



//  **************************************************************  TEMPLATE OR INLINE OPERATORS IMPLEMENTATION   ***************************************************************



	inline Boolean Vertex_2D::operator==( const SelfType& other ) const
	{
		// Compare the properties of the two vertices and return the result
		return ( ( member_firstDimensionPosition == other.member_firstDimensionPosition ) && ( member_secondDimensionPosition == other.member_secondDimensionPosition ) );
	}


	inline Boolean Vertex_2D::operator!=( const SelfType& other ) const
	{
		// Return the negotiated value from the equal operator
		return ( !( *this == other ) );
	}



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************



// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************



}  //  Namespace Graphics


}  //  Namespace Universe
