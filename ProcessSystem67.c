#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sched.h>
#include <sys/resource.h>


int main()
{
    int ret1 = 0 ; 
    int ret2 = 0 ;
    int Status1 = 0 , Status2 = 0 ; 
    ret1 = fork();
    if(ret1 == 0)
    {
        execl("./Process1" , "NULL" , NULL);
    }

    wait(&Status1);

    ret2 = fork();
    if(ret2 == 0)
    {
        execl("./Process2" , "NULL" , NULL);
    }

    wait(&Status2);

    return 0;
}