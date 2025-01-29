//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



template< typename AnyType >
inline VertexBuffer< AnyType >::VertexBuffer() :
	member_rendererId( NumericLimits< UnsignedInteger32bits >::Maximum )
{}


template< typename AnyType >
inline VertexBuffer< AnyType >::VertexBuffer( const void* const data, const UnsignedInteger32bits sizeInBytes ) :
    member_rendererId( NumericLimits< UnsignedInteger32bits >::Maximum )
{
    // Each method that interacts with the user directly needs to ensure that the given data is valid, and that the current
    // instance is ready to be used
	AssertPointerIsNotNull( data );
	AssertValueIsLargerThenZero( sizeInBytes );

    // Generate buffer object names. It will generate one buffer, and store the ID. No buffer pbjects are associated
    // with the returned buffer object names until they are first bound. In this case the only possible error is if
    // the required number of sizes is negative. The values used is 1, therefore there is no way it would fail and
    // no need to handle errors
    glGenBuffers( 1, &member_rendererId );

    // Bind a named buffer object. The target 'GL_ARRAY_BUFFER' is to describe the vertex attributes. Binds a buffer 
    // object to the specified bufer binding point
    glBindBuffer( GL_ARRAY_BUFFER, member_rendererId );

    // Create and initialize a buffer object's data store. The buffer object currently bound to the target 'GL_ARRAY_BUFFER'
    // is used. While creating the new storage, any pre existing data store is deleted. The new data store is created
    // with the specified size in bytes and the required usage. In its initial state, the new data store is not mapped,
    // it has NULL mapped pointer, and its mapped access is 'GL_READ_WRITE'.
    //
    // Usage is a hint to the GL implementation as to how a buffer object's data store will be accessed. This enables
    // the GL implementation to make more intelligent decisions that may significantly impact buffer object performance.
    // It does not, however, constrain the actual usage of the data store. Usage can be brokwn down into two parts.
    // The first is the frequency of access, and second the nature of the access. The frequency of access may be one
    // of these :
    //
    //  1. STREAM - the data store contents will be modified once and used at most a few times
    //  2. STATIC - the data store contents will be modified once and used many times
    //  3. DYNAMIC - the data store contents will be modified repeatedly and used many times
    //
    // The nature of the access may be one of these:
    //
    //  1. DRAW - the data store contents are modified by the application, and used as the source for GL drawing and 
    //            image specification commands
    //  2. READ - the data store contents are modified by reading data from the GL, and used to return that data when
    //            queried by the application
    //  3. COPY - the data store contents are modified by reading data from the GL, and used as the source for GL
    //            drawing and image specification commands
    //
    glBufferData( GL_ARRAY_BUFFER, sizeInBytes, data, GL_STATIC_DRAW );
}


template< typename AnyType >
inline VertexBuffer< AnyType >::~VertexBuffer()
{
	// Check if the instance was constructed using the default constructor or the 'Reset' method was used, which usually signify that there
    // are no resources used by the instance, and nothing needs to be done further in the destructor
    ReturnIfExpressionIsTrue( member_rendererId == NumericLimits< UnsignedInteger32bits >::Maximum );

    // Delete named buffer objects. After a buffer is deleted, it has no contents and its name is free for reuse. If a buffer
    // object that is currently bound is deleted, the binding reverts to 0 (the absence of any buffer object). It will
    // silently ignore 0's and names that do not correspond to existing buffer objects
    glDeleteBuffers( 1, &member_rendererId );
}


template< typename AnyType >
inline void VertexBuffer< AnyType >::Bind() const
{
    // Bind a named buffer object. The target is to describe the vertex attributes. Binds a buffer object to the specified 
    // bufer binding point
    glBindBuffer( GL_ARRAY_BUFFER, member_rendererId );
}


template< typename AnyType >
inline void VertexBuffer< AnyType >::Unbind() const
{
    // Unbind the buffer object. Buffer object names are unsigned integers. The value zero is resereved, but there is no 
    // default buffer object for each buffer object target. Instead, buffer set to zero effectively unbinds any buffer 
    // object previously bound, and restores client memory usage for that buffer object target. Buffer object names and 
    // the corresponding buffer object contents are local to the shared object space of the current GL rendering context
    glBindBuffer( GL_ARRAY_BUFFER, 0 );   
}



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	template< typename AnyType >
	void VertexBuffer< AnyType >::UnitTest()
	{}

)  //  End of debug tool



}  //  Namespace Graphics


}  //  Namespace Universe
