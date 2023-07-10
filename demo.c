#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/stat.h>


#define BLOCKSIZE 1024

int main( int argc , char * argv[])
{

    DIR * dp = NULL;
    int fd = 0;
    struct stat sobj;
    
    dp = opendir(argv[1]);
    if ( dp == NULL)
    {
        printf("Unable to Open Directory for some resaons .. \n");
        return -1;
    }

    struct dirent * entry = readdir(dp) ;

    printf( " Fle Name : \t \t INODE Number \n");
    printf( ".....................................................\n");

    while (( entry = readdir(dp)) != NULL)
    {
        printf( "%s \t\t  %d \n" , entry->d_name , entry -> d_ino);
        stat(entry -> d_name , &sobj);
        if (S_ISREG(sobj.st_mode))
        {
            printf("ReguralFile .......\n");
        }
    }

    closedir(dp);

    return 0;
}