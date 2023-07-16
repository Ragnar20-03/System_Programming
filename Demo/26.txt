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
        // Creat vs Open 
    fd = creat ( argv[1] ,0777     );
    if ( fd != -1)
    {
        printf("File is succesfully Created with %d : \n",fd);
    }
    return 0;
}