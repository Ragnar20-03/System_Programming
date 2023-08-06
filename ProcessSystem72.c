#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


void * ThreadProc1( void * ptr)
{
    printf("Inside Thread 1\n");
    pthread_exit(NULL);
}
void * ThreadProc2( void * ptr)
{
    printf("Inside Thread 2\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t TID1 , TID2;
    int ret1 = 0  , ret2 = 0 ;;

    ret1 = pthread_create(&TID1,  // Address of pthread_attr_t structure object
                         NULL , //Thread Attributes
                         ThreadProc1 , //Address of Callback function
                         NULL);     //Parameters to callback Functions

    if ( ret1 != 0)
    {
        printf("Unable to create Thread1 \n");
        return -1;
    }
    printf("Thread1 is created with Thead Id (TID) : %ld \n" ,TID1);



    ret2 = pthread_create(&TID2,  // Address of pthread_attr_t structure object
                         NULL , //Thread Attributes
                         ThreadProc2 , //Address of Callback function
                         NULL);     //Parameters to callback Functions

    if ( ret2 != 0)
    {
        printf("Unable to create Thread2 \n");
        return -1;
    }
    printf("Thread2 is created with Thead Id (TID) : %ld \n" ,TID2);


    pthread_join(TID1 , NULL);
    pthread_join(TID2 , NULL);
    
    printf("End of Main Thread\n");
    
    pthread_exit( NULL);
    pthread_exit( NULL);

    return 0;
}