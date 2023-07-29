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
        execl("./ChildProcess" , "NULL", NULL);  
   
     }
     else   //Parent 
     {
        while (1)
        {
        printf("Parent is running with PID : %d\n",getpid());
            
        }
     }

    return 0;
} 