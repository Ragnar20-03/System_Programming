//Program to demostrate startup and exit using #pragma.
#include<stdio.h>
void fun();
void sun() ;

#pragma startup fun

#pragma exit sun

int main()
{
printf("\nIn main");
return 0;
}

void fun()
{
printf("\nIn fun");
}

void sun()
{
printf("\nIn sun");
}
