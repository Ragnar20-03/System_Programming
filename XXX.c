#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<signal.h>

void sig_handler(int signo)
{
    printf("Signal Received\n");
}

int main()
{
    printf("Inside main \n");
    printf("%d:\n",getpid());
    signal(SIGINT , sig_handler);

    for (;;);

    return 0;
}