#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>


void * ThreadProc1( void * ptr)
{
    char Buffer[512];
    int  iRet = 0 , i = 0 , fd = 0 ;
    int Count = 0 ;

    fd = open("Demo.txt" , O_RDONLY);

    while ( (iRet = read ( fd , Buffer , sizeof(Buffer))) != 0)
    {
        for (i = 0 ; i< iRet ; i++)
        {
            if ( Buffer[i] >= 'A' && Buffer[i] <= 'Z')
            {
                Count++;
            }
        }
    }
    printf("Count Capital is : %d\n" , Count); 
    close(fd);
    pthread_exit(NULL);
}
void * ThreadProc2( void * ptr)
{
    char Buffer[512];
    int  iRet = 0 , i = 0 , fd = 0 ;
    int Count = 0 ;

    fd = open("Demo.txt" , O_RDONLY);

    while ( (iRet = read ( fd , Buffer , sizeof(Buffer))) != 0)
    {
        for (i = 0 ; i< iRet ; i++)
        {
            if ( Buffer[i] >= 'a' && Buffer[i] <= 'z')
            {
                Count++;
            }
        }
    }
    printf("Count Small is : %d\n" , Count); 
    close(fd);
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