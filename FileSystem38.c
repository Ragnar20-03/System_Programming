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
    char oldname [ 50];
    char newname [ 50];
    int iCnt = 1;

    dp = opendir(argv[1]);
    if (dp == NULL)
    {
        printf("Unable to Open Directoey \n");
        return -1;
    }

    while ((entry = readdir(dp)) != NULL)
    {
        sprintf(oldname , "%s/%s" , argv[1],entry->d_name);
        sprintf(newname , "%s/%d.txt" , argv[1],iCnt);

        rename(oldname , newname);
        iCnt++;
    }

    closedir(dp);
    return 0;
}