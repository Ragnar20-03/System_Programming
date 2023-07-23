#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    int PID = 0 ;
    PID = getpid();
    printf("PID of Running Process is : %d\n",PID);

    for (;;)
    {
        
    }

    return 0;
}