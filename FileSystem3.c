#include<stdio.h>

int main(int argc , char * argv[])
{
    printf("Name of Application is : %s \n" , argv[0]);
    if (argc == 1)
    {
        printf("Please Enter Your Name as Command Line Argumet");
        return -1;

    }
    else 
    {
        printf("Welcome to Marvellous :  %s \n" , argv[1]);
        return 0 ; 
    }
}