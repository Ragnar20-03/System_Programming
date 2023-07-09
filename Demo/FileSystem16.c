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

    printf("File Name : %s \n",argv[1]);
    printf("File Size is : %ld \n",sobj.st_size);
    printf("Number of Links : %ld \n",sobj.st_nlink);
    printf("INODE Number  : %ld \n",sobj.st_ino);
    printf("File System Number  : %ld \n",sobj.st_dev);
    printf("Number of Blocks : %ld \n" , sobj.st_blocks);

    return 0 ;
}