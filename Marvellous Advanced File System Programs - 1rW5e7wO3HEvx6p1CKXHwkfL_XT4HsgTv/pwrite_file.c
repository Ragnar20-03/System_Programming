//Program to demostrate pwrite().
#include <fcntl.h>
#include<stdio.h>
#include <unistd.h>

int main(void)
{
int fd;
int ret;
int offset;

char buff[25] = "Hello World";

// If file is opened in read mode
fd = open("file.txt",O_RDWR);
if(fd == -1)
{
	printf("Unable to open file \n");
	return -1;
}


// When we use write and lseek system call it not provides atomic behaviour.
// When multiple processess can access the same file then there can be a problem.
// which can be avoided using pwrite system call which gives effect of lseek and read atomically.

// Parameters of pwrite system call is same but only diffrence is in last parameter
// Last parameter is offset at which we have to write

ret = pwrite(fd,buff,sizeof(buff),20);

// pwrite system call returns no of bytes successfully written.

if(ret != sizeof(buff))
{
	printf("Unable to write contents\n");
}

printf("Written contents are \n %s",buff);

return 0;

}
