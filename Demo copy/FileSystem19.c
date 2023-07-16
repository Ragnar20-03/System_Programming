// Directoy Operations 
//  ls - i

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>


int main( int argc , char *argv[])
{
    DIR *dp = NULL;

    struct dirent * entry = NULL;

    if ( argc != 2)
    {
        printf("Insufficient Arguments \n");
    }

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("Unable to Open Directory \n");
        return -1;
    }

    printf("Entries From the Directory file are : \n");
    while((entry = readdir(dp) ) != NULL )
    {
        printf( " %s :  %d" , entry->d_name , entry->d_ino);
    }

    closedir(dp);

    return 0 ;
}