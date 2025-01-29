namespace Universe
{


namespace Graphics
{



// Open Graphics Library ( OpenGL ) is a cross language, cross platform application programming interface for rendering 2D and 3D vector 
// graphics. The API is typically used to interact with a graphics processing unit ( GPU ), to achieve hardware accelerated rendering.
//
// The OpenGL specification describes an abstrct API for drawing 2D and 3D graphics. Although it is possible for the API to be implemented
// entirely in software, it is designed to be implemented mostly or entirely in hardware.
//
// The API is defined as a set of functions which may be called by the client program, alongside as set of named integer constants. Although
// the function definitions are superficially similar to those of the programming language C, thery are language independent. In addition to
// being language independent, OpenGL is also cross platform. The specification says nothing on the subject of obtaining and managing an
// OpenGL context, leaving this as a detail of the underlying windowing system. For the same reason, OpenGL is purely connected with
// rendering, providing no APIs related to input, audio or windowing



// The OpenGL Extension Wrangler Library ( GLEW ) is a cross platform open source C/C++ extension loading library. GLEW provides efficient run
// time mechanisms for determining which OpenGL extensions are supported on the target platform. OpenGL core and extension functionality is 
// exposed on a single header file.
//
// Most compilers give an OpenGL header that provides support for OpenGL 1.1, but most of the functions provided in the version of OpenGL have
// been long since deprecated, and lacks important features such as shaders and vertex buffer objects. GLEW is basically a tool that provides newer
// OpenGL functionality.
//
// OpenGL is implemented by the graphics driver as a bunch of functions implemented according to the specification, not as a stand alone library,
// therefore cannot be simply linked to the code. To use those they must be queried for the address of each function before using it, and there
// is a lot of functions.
//
// GLEW exists because doing just that can be very difficult. It is much easier when an header can be included and then the functions are automatically
// uploaded



// Most GLFW functions must only be called from the main thread ( the thread that calls main ), but some may be called from any thread once the
// library has been initialized. Before initialization the whole library is thread unsafe. Initialization, termination, event processing and 
// the creation and destruction of windows, cursors and OpenGL contexts are all restricted to the main thread due to limitations of one or
// several platforms.
//
// Becasue event processing must be performed on the main thread, all callbacks except for the error callbacks will only be called on that
// thread. The error callback may be called on any thread, as any GLFW function may generate errors!



// 'glGetString' returns a pointer to a static string describing some aspect of the current GL connection. The options are :
//
//	1. GL_VENDOR
//	2. GL_RENDERER
//	3. GL_VERSION
//	4. GL_SHADING_LANGUAGE_VERSION
//
// The string for the vendor and renderer together uniquely specify a platform. They do not change from release to release and should be used
// by platform recognition algorithms. The version and shading language version strings begin with a version number



// 'glDrawArrays' :
//
// Render primitives from array data. It specifies multiple geometric primitives with very few subroutine calls. Instead of calling a
// GL procedure to pass each individual vertex, normal, texture coordinate, edge flag or color, it is possible to prespecifiy separate arrays
// of vertices, normals and colors and use them to construct a sequence of primitives with a single call. When it is called, it uses
// count sequential elements from each enabled array to construct a sequence of geometric primitives, beginning with element first. 
// The mode specifies what kind of primitives are constructed and how the array elements construct those primitives. Vertex attributes
// that are modifies by this call have an unspecified value after the call. Attributes that aren't modified remain well defined




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
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		Too many to count
//
class Renderer NotForInheritance
{
public:


// Create a type definition for this object
using SelfType = Renderer;


// The following methods are the basic methods for each object. How to create, destroy, copy and move the object. This methods if not declared
// the compiler generates a basic behavior for them if possible :


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
explicit inline Renderer( const Language::String& name, const UnsignedInteger64bits width, const UnsignedInteger64bits height );


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
inline ~Renderer();


// This part will contain all the get and set methods for the members of the object :


GetByValue_Creator( /* GetMethodName */ Name, /* MemberName */ member_name, /* MemberType */ Language::String )
GetByValue_Creator( /* GetMethodName */ Width, /* MemberName */ member_width, /* MemberType */ UnsignedInteger64bits )
GetByValue_Creator( /* GetMethodName */ Height, /* MemberName */ member_height, /* MemberType */ UnsignedInteger64bits )


// The following methods give access and manipulate the data inside this object :


// Method Information :
//
//  Description :
//
//		Use this method to start the rendering loop
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
void Run();



// The following functions are declared static. Static functions do not belong to any of the instances, but rather to the object.
// Satic functions only have access to static data members, which also don't belong to any instance, this means all other data members
// can not be used. The only purpose then of declaring a static function is when a private static data member needs to be manipulated,
// or some functionality needed that does not involve the non static data members


// Method Information :
//
//  Description :
//
//		Use this method to obtain information on the graphical processor unit vendor
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
//		A constant reference to a string with the graphical processor unit vendor
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		They will come
//
static inline const Language::String& Vendor();


// Method Information :
//
//  Description :
//
//		Use this method to obtain information on the renderer
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
//		A constant reference to a string with the renderer
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		They will come
//
static inline const Language::String& LowLevelRenderer();


// Method Information :
//
//  Description :
//
//		Use this method to obtain information on the OpenGL version
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
//		A constant reference to a string with the OpenGL version
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		They will come
//
static inline const Language::String& Version();


// Method Information :
//
//  Description :
//
//		Use this method to obtain information on the shading language version
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
//		A constant reference to a string with the shading language version
//
//  Expectations :
//
//		NONE
//
//  Possible errors :
//
//		They will come
//
static inline const Language::String& ShadingLanguageVersion();


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
	static void UnitTest() __attribute__ (( __unused__ ));

)  //  End of debug tool


private:


// Disable all copy and move related methods, this include the copy constructor, move constructor, assignment operator and move assignment operator
DisableCopyAndMove( Renderer );


// This string will store the window name
Language::String member_name;

// This pointer will store the memory address of the main window
GLFWwindow* member_windowPointer;

// This object will store the width of the main window
UnsignedInteger64bits member_width;

// This object will store the height of the main window
UnsignedInteger64bits member_height;


// Static data members do not belong to any instance, they belong to the object. Like every global variable it is created with the
// start of the program and only destroyed when the program ends. The access to the static member is bound to this object of course


// The following methods are private. This means that only public or protected methods can use them, in other words they not part of
// the interface, but rather help implement it :


// Friend class or friend function can access private and protected members of other object in which it is declared as friend. It is
// sometimes useful to allow a particular object to access private members of other object. The declration of such function is private,
// because these functions are part of the implemntation, which the user should not be aware of. The use of this functions is not limited
// to the object's scope. One of the problems that friend declaration solves is when the object needs to be as a right side operand in
// expressions. Every method in the object is implicitly added a pointer to the location of the object data with the name "this", and
// to enable this the method must be called from an existing instance. This means that the object can only be implemented as the left side
// operand of an expression with methods, and friend functions and objects does not have this limitation


};  //  Class Renderer