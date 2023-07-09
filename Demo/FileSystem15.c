//  Coppy File Logic

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>


#define BLOCKSIZE 1024

int main( int argc , char * argv[])
{
    int fdSource = 0 ;
    int fdDest = 0 ;
    char Buffer[1024]={'\0'};
    int Ret = 0 ;

    if ( argc != 3)
    {
        printf("Insufficient Arguments \n");
        return -1;
    }

    fdSource = open(argv[1] , O_RDONLY);
    if ( fdSource == -1)
    {
        printf("Unable to open Source File \n");
        return -1;
    }

    fdDest = creat(argv[2] , 0777);
    if ( fdDest == -1)
    {
        printf("Unable to Create Destination File\n ");
        close(fdSource);  ////S
        return -1;
    }
    
    while ((Ret = read (fdSource , Buffer , sizeof(Buffer))) != 0 )
    {
        write(fdDest , Buffer , Ret);
        memset(Buffer , 0 , sizeof(Buffer)) ; //Clear the Buffer
    }
    close(fdSource);
    close(fdDest);

    return 0 ;
}