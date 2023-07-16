#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<dirent.h>
#include<sys/stat.h>

// Coppy file name and Size inside Structure..

#pragma pack (1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc , char * argv[])
{
    char DirName[20], name[30] ,  NameCopy[30] = {'/0'};
    DIR * dp = NULL;
    struct dirent *entry  = NULL;
    struct stat sobj;
    struct FileInfo fobj;
    int iMax = 0  , fd = 0 ;

    printf("Enter Name of Directory \n");
    scanf("%s",DirName);

    dp = opendir(DirName);
    if ( dp == NULL)
    {
        printf("Unable to open Directory\n");
        return -1;
    }

    fd = creat ("FileCombine.txt" , 0777);

    while (( entry = readdir(dp)) != NULL) 
    {
        sprintf(name , "%s/%s" , DirName,entry -> d_name);
        stat ( name , &sobj);
        if (S_ISREG(sobj.st_mode))
        {
            fobj.FileSize = sobj.st_size;
            strcpy(fobj.FileName , entry->d_name);
            write(fd,&fobj,sizeof(fobj));
            printf("%s\n",entry->d_name);
        }
    }

    char Buffer[1024];
    int iRet =  0;
    fd = open("FileCombine.txt",O_RDONLY);
    while ((iRet = read(fd , Buffer , 1024)) !=  0)
    {
        write(1 , Buffer , 844);
    }



    closedir(dp);

    return 0;
}