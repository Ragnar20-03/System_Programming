#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>

int main()
{
    int fd = 0 ; 
    char * path = "tmp/mypipe";
    fd = mkfifo(path , 0666);
    char Buffer[100];

    printf("Client  is running and Reading  data into named pipe\n");

    fd = open(path , O_WRONLY);

    read(fd , Buffer,13);

    printf("Data From  named pipe is  :: %s\n" , Buffer);
    
    close (fd);


    return 0;
}   