#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc , char * argv[])
{
    int fd =  0 ;
    int Ret =  0 ;
    char * Buffer =  NULL;

    if (argc != 3 )
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

    Buffer = (char * )malloc (sizeof (atoi(argv[2])));  // Dynamic Memory Allocation
    

    Ret = read(fd , Buffer, atoi( argv [2]));
    printf(" %d : ",Ret);
    if ( Ret == 0 )
    {
        printf("Unable to Read Data fromthe Fle \n");
    }
    else
    {
        printf("Data from file is : \n  :%s \n " , Buffer);
    }

    printf("Data From File is (Write): \n ");
    write ( 1 , Buffer , Ret);

    return 0;
}