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
    printf("Server Application running ...\n");

    shmid = shmget(key,shmsize , IPC_CREAT | 0666);

    printf("Shared memory allocated succesfully...\n");
    
    ptr = shmat(shmid , NULL , 0);
    if (ptr != NULL)
    {
        printf("Shared memory Attached succesfully...\n");
    }

    *ptr = 'H';
    ptr++;   
    
    *ptr = 'e';
    ptr++;   
    
    *ptr = 'l';
    ptr++;   
    
    *ptr = 'l';
    ptr++;   
    
    *ptr = 'o';
    ptr++;   
    
    *ptr = '\0';
    ptr++;

    printf("Data Written in Shared Memoty succesfully...\n");
    for (;;);

    shmdt(shmid);

    return 0;
}   