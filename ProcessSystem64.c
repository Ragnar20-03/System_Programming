#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<sched.h>
#include <sys/resource.h>


int main()
{
    char Buffer[512];

    int iCnt = 0  , iRet = 0 , i = 0 , fd = 0 ;
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
    return 0;
}