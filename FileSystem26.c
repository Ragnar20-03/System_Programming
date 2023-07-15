#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

// Largest File 
int main(int argc , char * argv[])
{
    char DirName[20];
    DIR * dp = NULL;
    struct dirent *entry  = NULL;
    char name[30];
    struct stat sobj;
    char NameCopy[30] = {'/0'};
    int iMax = 0 ;

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
        sprintf(name , "%s/%s" , DirName,entry -> d_name);
        stat ( name , &sobj);
        if (S_ISREG(sobj.st_mode))
        {
            if ( iMax < sobj.st_size)
            iMax = sobj.st_size;
            strcpy(NameCopy , name);
        }
    }

    printf("Name of  Largest File is : %s  with size %d Bytes \n",NameCopy , iMax);

    closedir(dp);

    return 0;
}