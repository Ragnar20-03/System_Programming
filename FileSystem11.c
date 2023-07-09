#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc , char * argv[])
{
    int fd =  0 ;
    char Buffer [1024] = {'\0'};
    int Ret =  0 ;

    if (argc != 2 )
    {
        printf("Insufficient Arguments \n");
        return -1;        
    }
    
    fd = open(argv[1] , O_RDONLY);
    if ( fd == -1)
    {
        printf("Unable to open File ..\n");
        return -1;
    }

    Ret = read(fd , Buffer,1024);
    if ( Ret == 0 )
    {
        printf("Unable to Read Data fromthe Fle \n");
    }
    else
    {
        printf("Data from file is %s \n " , Buffer);
    }

    return 0;
}