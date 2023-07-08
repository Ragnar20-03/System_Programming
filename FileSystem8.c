#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main( int argc , char * argv[])
{
    int fd = 0 ;
    int MODE = 0  ;
    if ( argc != 3)
    {
        printf("InValid Number of Arguments \n");
        return -1;
    }

    if ( strcmp ( argv[2] , "Read") == 0)
    {
        MODE = O_RDONLY;
    }

    else if ( strcmp (argv[2] , "Write") == 0)
    {
        MODE = O_WRONLY;
    }
    else 
    {
        MODE = O_RDONLY;
    }

    fd = open(argv[1] , MODE);
    if(fd == -1)
    {
        printf ("Unable to Open FIle ..\n");
    }
    else 
    {
        printf("File Susscessfully Opend ..  with fd : %d :\n", fd);
    }

    return 0;
}

// O_RDONLY     Read MODE
// O_RDWR       Read + Write MODE
// O_WRONLY     Write MODE
// O_CREATE     Create MODE