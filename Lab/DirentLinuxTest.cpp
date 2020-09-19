#include <iostream> 

#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

using namespace std;

// struct linux_dirent64 {
//    ino64_t        d_ino;    /* 64-bit inode number */
//    off64_t        d_off;    /* 64-bit offset to next structure */
//    unsigned short d_reclen; /* Size of this dirent */
//    unsigned char  d_type;   /* File type */
//    char           d_name[]; /* Filename (null-terminated) */
// };


class Test
{
public:



private:

};  //  class Test



int main()  
{

	try
    {

    	int fd = open( "/tmp/Love", O_CREAT | O_DIRECTORY, S_IRWXU );

    	if ( fd == -1 )
    	{
    		std::cout << strerror( errno ) << std::endl;
    	}

    	



    }
    catch ( const exception& stdException )
    {
    	cout << stdException.what() << endl;
    }

    return ( 0 );
}