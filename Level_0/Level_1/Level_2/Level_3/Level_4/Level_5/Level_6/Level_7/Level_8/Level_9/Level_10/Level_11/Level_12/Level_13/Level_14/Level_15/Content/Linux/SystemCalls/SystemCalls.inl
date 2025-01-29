//  ***********************************************************   TEMPLATE OR INLINE STATIC METHODS IMPLEMENTATION   ************************************************************



inline void SystemCalls::CreateDirectory( const AsciiCharacter* const directoryPathPointer, const UnsignedInteger64bits mode )
{
	// Invoke the system call using the required arguments to create the directory
	SystemCall< 2UL, const AsciiCharacter*, UnsignedInteger64bits >::Invoke( __NR_mkdir, directoryPathPointer, mode );
}


inline void SystemCalls::DeleteEmptyDirectory( const AsciiCharacter* const directoryPathPointer )
{
	// Invoke the system call using the required arguments, the system call will delete the directory only if its empty
	SystemCall< 1UL, const AsciiCharacter* >::Invoke( __NR_rmdir, directoryPathPointer );
}


inline SignedInteger32bits SystemCalls::OpenDirectory( const AsciiCharacter* const directoryPathPointer, const SignedInteger64bits flags )
{
	// Invoke the system call using the required arguments, and return the directory descriptor
	return ( SystemCall< 2UL, const AsciiCharacter*, SignedInteger64bits >::Invoke( __NR_open, directoryPathPointer, ( flags | O_DIRECTORY ) ) );
}


inline UnsignedInteger64bits SystemCalls::GetDirectoryEntry( const SignedInteger32bits fileDescriptor, UnsignedInteger8bits* const linuxDirectoryEntries64, const UnsignedInteger32bits size )
{
	// Invoke the system call using the required arguments, and return the number of bytes actually read
	return ( static_cast< UnsignedInteger64bits >( SystemCall< 3UL, SignedInteger64bits, UnsignedInteger8bits*, UnsignedInteger64bits >::Invoke( __NR_getdents64, static_cast< SignedInteger64bits >( fileDescriptor ), linuxDirectoryEntries64, size ) ) );
}


inline void SystemCalls::CreateFile( const AsciiCharacter* const filePathPointer, const UnsignedInteger64bits mode )
{
	// Invoke the system call using the required arguments, the system call will return a descriptor for the newly created file, but this
	// descriptor can have read and write permissions or not, it is known. Then the descriptor will be used to close the file, and let the
	// user later open the file with the required flags
	Close( SystemCall< 3UL, const AsciiCharacter*, SignedInteger64bits, UnsignedInteger64bits >::Invoke( __NR_open, filePathPointer, O_CREAT, mode ) );
}


inline void SystemCalls::DeleteFile( const AsciiCharacter* const filePathPointer )
{
	// Invoke the system call using the required arguments, the system call will unlink the file for further use. And when all references
	// to the file are closed it will be deleted
	SystemCall< 1UL, const AsciiCharacter* >::Invoke( __NR_unlink, filePathPointer );
}


inline SignedInteger32bits SystemCalls::OpenFile( const AsciiCharacter* const filePathPointer, const SignedInteger64bits flags )
{
	// Invoke the system call using the required arguments, and return the file descriptor
	return ( SystemCall< 2UL, const AsciiCharacter*, SignedInteger64bits >::Invoke( __NR_open, filePathPointer, flags ) );
}


inline void SystemCalls::DeleteFileContent( const AsciiCharacter* const filePathPointer )
{
	// Invoke the system call using the required arguments to delete the file content
	SystemCall< 2UL, const AsciiCharacter*, SignedInteger64bits >::Invoke( __NR_open, filePathPointer, O_TRUNC );
}


inline void SystemCalls::GetFileInformation( const SignedInteger32bits fileDescriptor, struct stat64* const fileInformationPointer )
{
	// Invoke the system call using the required arguments
	SystemCall< 2UL, SignedInteger64bits, struct stat64* >::Invoke( __NR_fstat, static_cast< SignedInteger64bits >( fileDescriptor ), fileInformationPointer );
}


inline UnsignedInteger64bits SystemCalls::GetFileSizeInBytes( const SignedInteger32bits fileDescriptor )
{
	// Create a buffer to store the file information
	struct stat64 fileInformation;

	// Invoke the system call to get the file information
	GetFileInformation( fileDescriptor, &fileInformation );

	// Return the size in bytes of the file
	return ( static_cast< UnsignedInteger64bits >( fileInformation.st_size ) );
}


inline void SystemCalls::Close( const SignedInteger32bits fileDescriptor )
{
	// Invoke the system call using the required arguments
	SystemCall< 1UL, SignedInteger64bits >::Invoke( __NR_close, static_cast< SignedInteger64bits >( fileDescriptor ) );
}


inline UnsignedInteger64bits SystemCalls::Read( const SignedInteger32bits fileDescriptor, void* const destinationPointer, const UnsignedInteger64bits numberOfBytesToRead )
{
	// Invoke the system call using the required arguments, and return the number of bytes actually read from the file
	return ( static_cast< UnsignedInteger64bits >( SystemCall< 3UL, SignedInteger64bits, const AsciiCharacter*, UnsignedInteger64bits >::Invoke( __NR_read, static_cast< SignedInteger64bits >( fileDescriptor ), reinterpret_cast< const AsciiCharacter* >( destinationPointer ), numberOfBytesToRead ) ) );
}


inline UnsignedInteger64bits SystemCalls::Write( const SignedInteger32bits fileDescriptor, const void* const sourcePointer, const UnsignedInteger64bits numberOfBytesToWrite )
{
	// Invoke the system call using the required arguments, and return the number of bytes actually written to the file
	return ( static_cast< UnsignedInteger64bits >( SystemCall< 3UL, SignedInteger64bits, const AsciiCharacter*, UnsignedInteger64bits >::Invoke( __NR_write, static_cast< SignedInteger64bits >( fileDescriptor ), reinterpret_cast< const AsciiCharacter* >( sourcePointer ), numberOfBytesToWrite ) ) );
}


inline void SystemCalls::SetReadAndWriteMarkerOffsetForFile( const SignedInteger32bits fileDescriptor, const SignedInteger64bits newOffset )
{
	// Invoke the system call using the required arguments
	SystemCall< 3UL, SignedInteger64bits, SignedInteger64bits, UnsignedInteger64bits >::Invoke( __NR_lseek, static_cast< SignedInteger64bits >( fileDescriptor ), newOffset, SEEK_SET );
}


inline void SystemCalls::EnableAccessToInputAndOutputPorts( const UnsignedInteger64bits startingPortIdentifier, const UnsignedInteger64bits numberOfPorts )
{
	// Invoke the system call using the given arguments, plus another argument with the value not zero, to notify that it should enbale access
	// to the required ports
	SystemCall< 3UL, UnsignedInteger64bits, UnsignedInteger64bits, UnsignedInteger64bits >::Invoke( __NR_ioperm, startingPortIdentifier, numberOfPorts, 0xFFFFFFFFFFFFFFFF );
}


inline void SystemCalls::DisableAccessToInputAndOutputPorts( const UnsignedInteger64bits startingPortIdentifier, const UnsignedInteger64bits numberOfPorts )
{
	// Invoke the system call using the given arguments, plus another argument with the value 0, to notify that it should disable access
	// to the required ports
	SystemCall< 3UL, UnsignedInteger64bits, UnsignedInteger64bits, UnsignedInteger64bits >::Invoke( __NR_ioperm, startingPortIdentifier, numberOfPorts, 0UL );
}



}  //  Namespace Linux


}  //  Namespace Universe