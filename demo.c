#include<stdio.h>
#include <fcntl.h>


int main( int argc , char * argv[])
{
    int fd = 0 ;
    int Mode = 0 ;

    if ( argv [ 1] == "Read ")
    {

    }
    fd = open ( "FileSystem1" , O_RDWR);
    if ( fd == -1)
    {
        printf(" File Open Failed\n");
        
    }
    else 
    {
        printf(" File Open Success\n");

    }

    return 0;
}