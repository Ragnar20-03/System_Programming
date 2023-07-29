#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc , char*argv[])
{
    printf("PID is :  %d \n",getpid());

    printf("%s  %s  %s \n" , argv[0] , argv[1] , argv[2]);
 
    return 0;
}