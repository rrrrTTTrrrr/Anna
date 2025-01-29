namespace Universe 
{


namespace Graphics
{



//	***************************************************************   PUBLIC METHODS IMPLEMENTATION - INTERFACE   ***************************************************************



static unsigned int CompileShader( unsigned int type, const std::string& source )
{
    unsigned int id = glCreateShader( type );
    const char* const src = source.data();
    glShaderSource( id, 1, &src, nullptr );
    glCompileShader( id );

    int result;
    glGetShaderiv( id, GL_COMPILE_STATUS, &result );

    if ( result == GL_FALSE )
    {
        int length;
        glGetShaderiv( id, GL_INFO_LOG_LENGTH, &length );
        char* message = (char*)alloca( static_cast< unsigned int >( length ) * sizeof( char ) );
        glGetShaderInfoLog( id, length, &length, message );

        std::cout << "Failed to compile " << ( type == GL_VERTEX_SHADER ? "vertex" : "fragment" ) << std::endl;
        std::cout << message << std::endl;
        glDeleteShader( id );
        return ( 0 );
    }

    return ( id );
}


static unsigned int CreateShader( const std::string& vertexShader, const std::string& fragmentShader )
{
    unsigned int program = glCreateProgram();

    unsigned int vs = CompileShader( GL_VERTEX_SHADER, vertexShader );
    unsigned int fs = CompileShader( GL_FRAGMENT_SHADER, fragmentShader );

    glAttachShader( program, vs );
    glAttachShader( program, fs );

    glLinkProgram( program );
    glValidateProgram( program );

    glDeleteShader( vs );
    glDeleteShader( fs );

    return ( program );
}


void Renderer::Run()
{
    // /* Initialize the library */
    // if (!glfwInit())
    //     return;

    // /* Create a windowed mode window and its OpenGL context */
    // member_windowPointer = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    // if (!member_windowPointer)
    // {
    //     glfwTerminate();
    //     return;
    // }

    // // Make the window's context current 
    // glfwMakeContextCurrent(member_windowPointer);

    // GLenum err = glewInit();
    
    // if (GLEW_OK != err)
    // {
    //   /* Problem: glewInit failed, something is seriously wrong. */
    //   fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
    //   return;
    // }

    // std::cout << glGetString( GL_VERSION ) << std::endl;

    float positions[6] {
        -0.5f, -0.5f,
        0.0f, 0.5f,
        0.5f, -0.5f
    };

    UnsignedInteger32bits indices[] = {
        0, 1, 2,
        2, 3, 0
    };

    VertexBuffer< UnsignedInteger32bits > vertexBuffer( positions, 4 * 2 * sizeof( float ) );


    glEnableVertexAttribArray( 0 );
    glVertexAttribPointer( 0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof( float ),  nullptr );

    IndexBuffer< UnsignedInteger32bits > indexBuffer( indices, 6 );

    std::string vertexShader = 
        "#version 330 core\n"
        "\n"
        "layout( location = 0 ) in vec4 position;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   gl_Position = position;\n"
        "}\n";


    std::string fragmentShader = 
        "#version 330 core\n"
        "\n"
        "layout( location = 0 ) out vec4 color;\n"
        "\n"
        "void main()\n"
        "{\n"
        "   color = vec4( 1.0, 0.0, 0.0, 1.0 );\n"
        "}\n";

    UnsignedInteger32bits shader = CreateShader( vertexShader, fragmentShader );

    // Loop until the user closes the window
    while ( glfwWindowShouldClose( member_windowPointer ) == false )
    {
        // Clear buffers to preset values. Sets the bitplane area of the window to values previously selected by 'glClear', 'glClearDepth' and
        // 'glClearStencil'. Multiple color buffers can be cleared simultaneously be selecting more than one buffer at a time using 'glDrawBuffer'
        glClear( GL_COLOR_BUFFER_BIT );

        glUseProgram( shader );
        //glUniform4f( location, r, 0.3f, 0.8f, 1.0f );

        // Specifies multiple geometric primitives with very few subroutine calls. Instead of calling a GL function to pass each individual vertex,
        // normal, texture coordinate, edge flag or color, it is possible to specifiy deparate arrays of vertices, normals and so on and use them to
        // construct a sequence of primitives with a single call to 'glDrawElements'. When it is called it uses count sequential elements from an
        // enabled array, starting at indices to construct a sequence of geometric primitives. The mode specifies what kind of primitives are
        // constructed and how the array elements construct these primitives. If more than one array is enabled all is used
        glDrawElements( GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr );

        // Swap the front and back buffers of the specifies window when rendering with OpenGL. If the swap interval is greater than zero
        // the grphical processing unit driver waits the specified number of screen updates before swapping the buffers. The specified
        // window must have an OpenGL context
        glfwSwapBuffers( member_windowPointer );

        // This function processes only those events that are already in the event queue and then returns immediately. Processing events will
        // cause the window and input callbacks associated with those events to be called
        glfwPollEvents();
    }

    glfwTerminate();
}



//  ************************************************************************   OPERATORS IMPLEMENTATION   ***********************************************************************



//  ********************************************************************   STATIC FUNCTIONS IMPLEMENTATION   ********************************************************************



//	********************************************************************   PRIVATE METHODS IMPLEMENTATION   *********************************************************************



// *****************************************************************   NESTED CLASS METHODS IMPLEMENTATION -    *****************************************************************



// **********************************************************************   FRIEND FUNCTIONS IMPLEMENTATION   *******************************************************************



// *********************************************************************************   TESTING   ********************************************************************************





DEBUG_TOOL(

void Renderer::UnitTest()
{
    Renderer renderer( "Lol", 1200, 700 );

    renderer.Run();
}

)  //  End of debug tool



}  //  Namespace Graphics


}  //  Namespace Universe
