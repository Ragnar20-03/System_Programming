#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main( int argc , char *argv[])
{
    struct stat sobj;

    if ( argc != 2)
    {
        printf("Insfficient Arguments .. \n");
        return -1;
    }

    stat(argv[1] , &sobj );

    if ( S_ISREG(sobj.st_mode))
    {
        printf(" It is a Regural File \n");
    }
    else if ( S_ISIDR(sobj.st_mode))
    {
        printf("Its a Directory \n");
    }
    else if ( S_ISLINK(sobj.st_mode))
    {
        printf("It is a Symbolic Link \n");
    }

    return 0 ;
}