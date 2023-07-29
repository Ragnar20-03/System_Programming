#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int Ret = 0; 
     Ret = fork();

     if ( Ret == 0) //Child 
     {
        execl("./ChildProcess" , "NNULL", NULL);  
   
     }
     else   //Parent 
     {
        printf("Parent is running with PID : %d\n",getpid());
        // sleep(1000);
     }

    return 0;
} 