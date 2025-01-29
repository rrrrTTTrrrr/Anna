















//							                        System - this file is used to describe the system environment for C/C++ 



















// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //
// **														   			            SYSTEM C                                                                               ** //
// ************************************************************************************************************************************************************************** //
// ************************************************************************************************************************************************************************** //




	// The two forms of conforming implementation are hosted and freestanding. A conforming hosted implementation shall accept any strictly conforming program. This constitutes
	// the typical application environment, with filesystems, allocated memory and threads... A conforming freestanding implementation shall accept any strictly conforming 
	// program in which the use of the features specified in the library clause is confined to the contents of the standard headers :
	// 
	// 		<float.h> <iso646.h> <limits.h> <stdalign.h> <stdarg.h> <stdbool.h> <stddef.h> <stdint.h> <stdnoreturn.h>.
	// 
	// This constitutes the typical kernel and/or embedded, bare minimum environment that doesn't have standard filesystems, allocated memory or threads ( among other things ).
	// A conforming implementation may have extensions ( including additional library functions ), provided they do not alter the behavior of any strictly conforming program.
	// 
	// It seems as though this gives a hosted implementation the freedom to call itself a hosted or freestanding implementation, and when it comes to filesystems, allocated 
	// memory or threads ( among other things ), these can fall under the extension category so that it can merely implement an interface that returns a value indicating 
	// errors every time. Just to name a few:
	// 
	//  	fopen, fgets and malloc can return NULL
	//  	fprintf, fscanf, fputc and fgetc can return EOF
	//  	thrd_create can return thrd_error (indicating that "the request could not be honored")
	//
	//
	// A hosted execution environment is also a freestanding, but not vice versa. A compiler need only provide a freestanding implementation. gcc, for example, is strictly 
	// speaking freestanding only, as the standard library is not included. However, it assumes it is available when compiling for a hosted environment ( the default ), 
	// assuming the library is available on the system ( like glibc )
	// 
	// Simply put, freestanding is just the language. It is not required to support any libraries and just a few headers ( mostly for common types and implementation specific
	// stuff like numerical limits, etc. ). This implies the standard library need not exist - nor do the corresponding headers. Reason is a freestanding environment most 
	// likely will not have such facilities like files, display, etc. It is used for kernels, bare-metal embedded, etc.
	// 
	// Note that gcc for instance will, if compiling for a hosted environment ( -fhosted ), assume functions used in the standard library have the corresponding meaning and 
	// might apply very aggressive optimizations ( it has many of those functions built-in ). For freestanding, it actually does not, so you can use a function strcmp for 
	// instance with completely different semantics. However, it assumes the memory functions to exist, as these are used for normal code, e.g. struct assignment.
	// 
	// So, if building for bare-metal, always pass -ffreestanding.
	// 
	// If a hosted implementation calls itself freestanding, it is obviously not a hosted implementation anymore. Once it calls itself hosted, however, it has to provide all 
	// facilities required by the standard and has to provide the semantics as defined in the standard
	// 
	// Just to state that clear - The cited section allows a freestanding environment to omit all functions of the library, except for the few listed headers. So you are 
	// free to supply any other library and use the same names, but do anything you like. As that would be not the standard library, there is no need for compliance.