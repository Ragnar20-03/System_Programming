// Server for Shared Memory

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
    printf("Server Application running ...\n");

    shmid = shmget(key,shmsize , IPC_CREAT | 0666);

    printf("Shared memory allocated succesfully...\n");

    return 0;
}   