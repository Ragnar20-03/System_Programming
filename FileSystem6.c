#include<stdio.h>
#include<fcntl.h>

int main( int argc , char * argv[])
{
    char Fname[20];
    int fd = 0;

    printf ( "Enter the File Name to Open : \n");
    scanf("%s" , Fname);

    fd = open(Fname , O_RDONLY);
    if ( fd == -1)
    {
        printf("Unable to open the File \n");
        return -1;
    }
    else
    {
        printf("File is Succesfully Opened with FD %d \n" , fd);
    }

    return 0;
}

// O_RDONLY     Read Mode
// O_RDWR       Read + Write Mode
// O_WRONLY     Write Mode
// O_CREATE     Create Mode