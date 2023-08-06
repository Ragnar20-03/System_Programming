#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


// void * _____(void * ____)
// {}
void * ThreadProc( void * ptr)
{
    int i = 0 ; 
    for ( i = 1 ; i<1000 ; i++ )
    {
        printf("Thread with Counter : %d \n" , i);
    }
}
int main()
{
    pthread_t TID;
    int ret = 0  ;

    ret = pthread_create(&TID,  // Address of pthread_attr_t structure object
                         NULL , //Thread Attributes
                         ThreadProc , //Address of Callback function
                         NULL);     //Parameters to callback Functions

    if ( ret != 0)
    {
        printf("Unable to create Threaf \n");
        return -1;
    }

    printf("Thread is created with Thead Id (TID) : %ld \n" ,TID);

    pthread_join(TID , NULL);

    printf("End of Main Thread\n");

    return 0;
}