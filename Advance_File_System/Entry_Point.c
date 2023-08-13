#include<stdio.h>
#include<stdlib.h>
// #include<unistd.h>
// #include<fcntl.h>
#pragma startup(New_Main)

int New_Main()
{
	// write(1 , "Hello" , 5);
	printf("Iniside New Main \n");
	exit(0);
}
int main()
{
	printf("Inside main\n");
	return 0;
}