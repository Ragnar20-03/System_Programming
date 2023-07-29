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
        execl("./ChildProcess" , "Demo" , "Hello"  , "Marvellous", NULL);  
        // Parameter 1 : Name of exexcutable ;
        // Parameter 2 : Multiple values seperated by , Which are consider as CommandLine Arguments  ;
        // argv[0] : Demo
        // argv[1] : Hello
        // argv[2] : Marvellous

        // Paramter 3 : Enviorment Variable (NULL)

     }
     else   //Parent 
     {
        printf("Parent is running with PID : %d\n",getpid());
     }

    return 0;
}