//Program to demostrate startup and exit using #pragma.
#include<stdio.h>
void fun()
{
printf("\nIn fun");
}

void sun()
{
printf("\nIn sun");
}
void fun();
void sun() ;

#pragma startup fun

#pragma exit sun

int main()
{
printf("\nIn main");
return 0;
}


