#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc , char * argv[])
{
    char DirName[20];
    DIR * dp = NULL;
    struct dirent *entry  = NULL;

    printf("Enter Name of Directory \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if ( dp == NULL)
    {
        printf("Unable to open Directory\n");
        return -1;
    }

    while (( entry = readdir(dp)) != NULL) 
    {
        printf("%s\n",entry -> d_name);
    }

    return 0;
}