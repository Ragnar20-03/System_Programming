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
        printf("Child Sayas : PID of Parent Process is %d  \n" ,getppid());
        printf("Parent Sayas : PID of Child Process is %d  \n" , getpid());
    }
    else 
    {
        printf("Parent Process is Running \n");
        printf("Parent Sayas : PID of Child Process is %d  \n" , Ret);
        printf("Parent Sayas : PID of Parent Process is %d  \n" , getpid());
        printf("Parent Sayas : PID of Parent Process of Parent ie.teminal is %d  \n" , getppid());
    }



    return 0;
}