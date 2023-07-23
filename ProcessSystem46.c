#include <stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
    fork();

    printf("Hello World\n");

    return 0;
}