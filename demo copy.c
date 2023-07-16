#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>



int main(int argc , char * argv[])
{
    int fd = 0 ;
    fd = creat("XXX.xpp" , 0000);

    return 0;
}