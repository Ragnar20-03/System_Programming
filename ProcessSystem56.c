#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    printf("Inside Child Process  -> PID of Paerent Process is %d \n" , getppid());

    return 0;
} 