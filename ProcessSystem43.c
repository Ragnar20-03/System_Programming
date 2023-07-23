#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int PID = 0 ;
    int PPID = 0 ;
    
    PID = getpid();
    printf("PID of Running Process is : %d\n",PID);

    PPID = getppid();
    printf("PID of Parent  Process is : %d\n",PPID);


    return     PID = getpid();
    printf("PID of Running Process is : %d\n",PID);
0;
}