#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    char FileName1 [30] , FileName2 [ 30];
    int iRet = 0 ; 
    printf("Enter the Existing File Name \n");
    scanf("%s" , FileName1);

    printf("Enter the Name of Hard Link \n");
    scanf("%s" , FileName2);

    iRet = link(FileName1 , FileName2);
    if (iRet == -1)
    {
        printf("Unable to create Hard Link\n");
        return -1;
    }
    else
    {
        printf(" created Hard Link Succesfully!!!\n");
        
    }
    return 0;
}       