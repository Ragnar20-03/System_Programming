#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


// void * _____(void * ____)
// {}
void * ThreadProc( void * ptr)
{
    printf("value Recieved From thread is : %d \n" , (int *) ptr);
}
int main()
{
    pthread_t TID;
    int ret = 0  ;
    int no = 11;

    ret = pthread_create(&TID,  // Address of pthread_attr_t structure object
                         NULL , //Thread Attributes
                         ThreadProc , //Address of Callback function
                         (int * ) no );     //Parameters to callback Functions

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