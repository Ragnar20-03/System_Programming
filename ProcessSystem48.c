#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>


void fun()
{
    printf("Running Process PID is :  %d \n",getpid());
}

int main()
{

    int Ret = 0 ;

    Ret = fork();

    if ( Ret == 0)
    {
        fun();
    }
    else 
    {
        fun();
    }

    return 0;
}