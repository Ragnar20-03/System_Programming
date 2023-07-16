#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>

int main(int argc ,  char * argv[])
{
    int fd = 0 , ret = 0 ; 
    char Arr[20];

    fd = open(argv[1] ,O_RDONLY);
    if ( fd == -1)
    {
        printf("Unable to Opne file\n");
        return -1;
    }

    lseek(fd , atoi(argv[2]) , 0);
    ret = read(fd,Arr,20);
    write(1 ,Arr , ret);

    return 0;
}