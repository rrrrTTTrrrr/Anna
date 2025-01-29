namespace Universe
{


namespace Graphics
{



// A rendering enging draws images of the application to the screen by using vertex and index buffers. The models used in games are created
// out of triangles, which the rendering engine uses to draw. A vertex buffer is a list of coordinates used for drawing triangles. The index
// buffer helps save memory be reducing the need to store shared vertices in the vertex buffer.
//
// To understand how 3D models are drawn, it helps to start with something easier than a 3D model, a square. The vertex buffer contains a
// list of vertices used to draw triangles to the screen. For example, for drawing a square in 2D it could list every vertex of the the
// two triangles :
//
//	float vertexBuffer[] = {
//     -1,  1 // Bottom left triangle
//     -1, -1,
//   	1, -1,
//     -1,  1, // Top right triangle
//   	1, -1,
//   	1,  1
//	}
//
// The first 3 coordinates form the bottom left corner of the square. The second 3 coordinates form the tope corner of the square. Together
// this could be used to tell the graphics card to render two triangles to the screen. The point is that there are duplicate vertices, vertices
// that contain the same data. In big detailed 3D modles that can add up to a lot of waste. Index buffers are used to save memory by listing
// indices into vertex buffer, rather than giving an explicit vertex buffer to the renderer. If a vertex buffer was used :
//
// 	float vertexBuffer[] = {
//     -1,  1, // Top left corner
//     -1, -1, // Bottom left corner
//    	1, -1, // Bottom right corner
//    	1,  1  // Top right corner
// 	}
//
// 	unsigned short indexBuffer[] = {
//   	0, 1, 2 // Bottom left triangle
//   	0, 2, 3 // Top right triangle
// 	}
//
// Instead of 12 floats ( 48 bytes ) to draw two triangles, 8 floats were used and 6 unsigned shorts ( 44 bytes ) for a total of 4 bytes saved.



// Class Information :
//
//  Purpose :
//
//		Artifical Inteligence
//
//  Description :
//
// 		1. Encapsulation means that the user is only allowed to access certain parts of the object. Encapsulation is acheived in C++ by
//		   providing 3 keywords :
//
//			1. Public - this part is for the user, it is the interface of the object. The user access and manipulate the data inside the
//						obejct using the tools presented here. This part will usually contain only methods and not data members. If a data
//						member is public all the encapsulation is lost, so it should be avoided in most cases
//
//			2. Protected - this part is for developing purposes, inheritance. A developer can inherit from this object and it will
//						   be able to access all the data and methods inside this part. This part will usually containt some methods and few
//						   data members
//
//			3. Private - this part is for the developer of the object. This part will probably contain most of the data members of the object
//						 and all the methods the developer needed to implement the interface presented in the public part. Every method in this
//						 part will end with the suffix __Private
//
//		2. Template arguments :
//
//			1.
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
template< typename AnyType >
class IndexBuffer NotForInheritance
{
public:


	// Create a type definition for this object
	using SelfType = IndexBuffer< AnyType >;


	// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
	// the compiler generates a basic behavior for them if possible :


	// Method Information :
	//
	//  Description :
	//
	//		Default Constructor,
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
	inline IndexBuffer();


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
	//			1. ata - a pointer with the memory address of the data
	//			2. sizeInBytes - the size of the data in bytes 
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
	//		1. The given pointer to the data is not NULL
	//		2. The size in bytes is larger than 0
	//
	//  Possible errors :
	//
	//		They will come
	//
	explicit inline IndexBuffer( const UnsignedInteger32bits* const data, const UnsignedInteger32bits sizeInBytes );


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
	inline ~IndexBuffer();


	// This part will contain all the get and set methods for the members of the object :


	GetByValue_Creator( /* GetMethodName */ Size, /* MemberName */ member_size, /* MemberType */ UnsignedInteger32bits )


	// The following methods give access and manipulate the data inside this object :


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to bind the IndexBuffer in this instance with the target 'GL_ARRAY_BUFFER', which means the IndexBuffer attributes
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
	inline void Bind() const;


	// Method Information :
	//
	//  Description :
	//
	//		Use this method to unbind the IndexBuffer in this instance from the target 'GL_ARRAY_BUFFER', which means the IndexBuffer attributes
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
	inline void Unbind() const;


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
	static inline void UnitTest() __attribute__ (( __unused__ ));

	)  //  End of debug tool


private:


	// Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
	DisableCopyAndMove( IndexBuffer );


	// This object will store the renderer ID
	UnsignedInteger32bits member_rendererId;

	// This object will store the number of indices in the buffer
	UnsignedInteger32bits member_size;


};  //  Class IndexBuffer