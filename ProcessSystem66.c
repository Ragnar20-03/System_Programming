#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sched.h>
#include <sys/resource.h>
#include <sys/wait.h>


int main()
{
    int ret1 = 0 ; 
    int ret2 = 0 ;

    ret1 = fork();
    if(ret1 == 0)
    {
        execl("./Process1" , "NULL" , NULL);
    }

    ret2 = fork();
    if(ret2 == 0)
    {
        execl("./Process2" , "NULL" , NULL);
    }


    return 0;
}