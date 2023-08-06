#include<stdio.h>
#include "sharedfile.h"

int main()
{
    int a = 10, b = 11, ret = 0;

    ret = Addition(a,b);

    printf("Addition is : %d\n",ret);

    return 0;
}

// gcc client.c -o Myexe

// gcc -static client.c -o Myexe sharedfile.a

// ./Myexe