//	*******************************************************   END PART OF DECLRATIONS, PUBLIC METHODS IMPLMENTATION TIME   *******************************************************



inline Renderer::Renderer( const Language::String& name, const UnsignedInteger64bits width, const UnsignedInteger64bits height ) :
	member_name( AssignOnlyIfValueToAssertIsLargerThenZero( name, name.Size() ) ),
	member_windowPointer( nullptr ),
	member_width( AssignOnlyIfValueIsLargerThenZero( width ) ),
	member_height( AssignOnlyIfValueIsLargerThenZero( height ) )
{
	// Initialize the GLFW graphics library
	Assert( ( glfwInit() != GLFW_NO_ERROR ), "Failed to initialize the GLFW library" );

	// Create a window using the GLFW library
	member_windowPointer = glfwCreateWindow( static_cast< SignedInteger32bits >( member_width ), static_cast< SignedInteger32bits >( member_height ), "Main Window", nullptr, nullptr );

	// Ensure that the creation of the main window was successful
	if ( member_windowPointer == nullptr )
	{
		// Failed to create the main window

		// Close the GLFW graphics library
		glfwTerminate();

		// Notify the user of the error
		ThrowException( "Failed to create the main window" );
	}

    // This function makes the OpenGL context of the specified window current on the calling thread. A context must only be made current on a single
    // thread at a time and each thread can have only a single current context at a time
    glfwMakeContextCurrent( member_windowPointer );

    // Initialize the GLEW graphics library
    const GLenum returnValue = glewInit();
    
    if ( returnValue != GLEW_OK )
    {
		// Failed to create the main window

		// Close the GLFW graphics library
		glfwTerminate();

		// Notify the user of the error
		ThrowException( "Failed to initialize the GLEW graphics library" );
    }
}


inline Renderer::~Renderer()
{
	// Destroy the window
	glfwDestroyWindow( member_windowPointer );

	// Close the GLFW graphics library
	glfwTerminate();
}



//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



inline const Language::String& Renderer::Vendor()
{
	// Create a string with the vendor information. The string memory will be allocated in the data segment, this way the string will be
	// created only once in the first time this method is called
	static const Language::String vendor( reinterpret_cast< const AsciiCharacter* >( glGetString( GL_VENDOR ) ) );

	// Return a reference to the vendor string
	return ( vendor );
}


inline const Language::String& Renderer::LowLevelRenderer()
{
	// Create a string with the renderer information. The string memory will be allocated in the data segment, this way the string will be
	// created only once in the first time this method is called
	static const Language::String renderer( reinterpret_cast< const AsciiCharacter* >( glGetString( GL_RENDERER ) ) );

	// Return a reference to the renderer string
	return ( renderer );
}


inline const Language::String& Renderer::Version()
{
	// Create a string with the renderer information. The string memory will be allocated in the data segment, this way the string will be
	// created only once in the first time this method is called
	static const Language::String version( reinterpret_cast< const AsciiCharacter* >( glGetString( GL_VERSION ) ) );

	// Return a reference to the version string
	return ( version );
}


inline const Language::String& Renderer::ShadingLanguageVersion()
{
	// Create a string with the renderer information. The string memory will be allocated in the data segment, this way the string will be
	// created only once in the first time this method is called
	static const Language::String shadingLanguageVersion( reinterpret_cast< const AsciiCharacter* >( glGetString( GL_SHADING_LANGUAGE_VERSION ) ) );

	// Return a reference to the shading language version string
	return ( shadingLanguageVersion );
}



//  ********************************************************   TEMPLATE OR INLINE PURE VIRTUAL METHODS IMPLEMENTATION   *********************************************************



//	***********************************************************   TEMPLATE OR INLINE PRIVATE METHODS IMPLEMENTATION   ***********************************************************



// ***************************************************************   NESTED CLASS PUBLIC METHODS IMPLEMENTATION -    ************************************************************



// **********************************************************   INLINE AND TEMPLATE FRIEND FUNCTIONS IMPLEMENTATION   ***********************************************************



}  //  Namespace Graphics


}  //  Namespace Universe
