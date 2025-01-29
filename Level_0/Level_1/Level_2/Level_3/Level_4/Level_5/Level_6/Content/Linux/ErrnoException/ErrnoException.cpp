namespace Universe 
{


namespace Linux
{



// *********************************************************************************   TESTING   ********************************************************************************



DEBUG_TOOL(

	void ErrnoException::Test()
	{            
        // Set new value to errno
        errno = 18;

        // Throw the Errnoexception and catch it
        try
        {
            ThrowErrnoException;
        }
        catch ( const ErrnoException& Errnoexception )
        {}
	}

)  //  End of debug tool



}  //  Namespace Linux


}  //  Namespace Universe