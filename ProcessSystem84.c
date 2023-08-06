// Client for Shared Memory

#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<sys/shm.h>


int main()
{
    int shmid  = 0 ; 
    int shmsize = 100 ; 
    int key = 1234;
    char * ptr = NULL;
    printf("Client Application running ...\n");

    shmid = shmget(key,shmsize ,  0666);
    
    ptr = shmat(shmid , NULL , 0);
    if (ptr != NULL)
    {
        printf("Shared memory Attached succesfully...\n");
    }

    return 0;
}   