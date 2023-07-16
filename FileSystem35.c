#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
#include<sys/dir.h>

int main(int argc ,  char * argv[])
{
    DIR * dp = NULL;
    struct dirent * entry = NULL;

    dp = opendir(argv[1]);
    if ( dp == NULL)
    {
        printf("Unavle to to open the directory ]\n");
        return -1;
    }

    while ((entry = readdir(dp) ) != NULL)
    {
        if (strcmp(argv[2] , entry -> d_name) == 0 )
        {
            printf("File is Available in thr Directory \n");
            break;
        }
    }

    if(entry == NULL)
    {
        printf("There is no such file \n");
        return -1;
    }

    closedir(dp);

    return 0;
}