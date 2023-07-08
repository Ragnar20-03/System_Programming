#include<stdio.h>
#include<fcntl.h>

int main( int argc , char * argv[])
{
    int fd = 0 ;

    if ( argc != 2)
    {
        printf("InValid Number of Arguments \n");
        return -1;
    }

    fd = open(argv[1] , O_RDONLY);
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

// O_RDONLY     Read Mode
// O_RDWR       Read + Write Mode
// O_WRONLY     Write Mode
// O_CREATE     Create Mode