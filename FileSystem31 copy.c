#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc ,  char * argv[])
{
    int fd = 0 ;
    if ( argc != 2)
    {
        printf("Invalid Arguments \n");
        return -1;
    }
                                // O_CREAT
    fd = open ( argv[1] ,O_RDWR     );
    if ( fd != -1)
    {
        printf("File is succesfully opend with %d : \n",fd);
    }
    return 0;
}