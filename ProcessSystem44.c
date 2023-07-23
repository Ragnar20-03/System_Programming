#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int Ret = 0 ; 
    Ret = fork();

    if (Ret == 0 )
    {
        printf("Child Process is Running\n ");
    }
    else 
    {
        printf("Parent Process is Running \n");
    }



    return 0;
}