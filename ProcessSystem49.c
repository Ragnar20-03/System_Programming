#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>

int No = 10;

void fun()
{
    No++;

    printf("Running Process PID is :  %d  AND Value of No is : %d \n",getpid() , No);

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