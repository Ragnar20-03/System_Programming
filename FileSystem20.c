#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

#pragma pack(1)
struct Student 
{
    int RollNo;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc , char * argv[])
{
    struct Student sobj;
    char Fname[20];
    int fd = 0 ;

    sobj.RollNo = 11;
    sobj.Marks = 89.99f;
    sobj.Age = 52;
    strcpy(sobj.Sname , " Roshan ");

    printf("Enter the File Name \n");
    scanf("%s" , Fname);

    fd = creat(Fname , 0777);

    write(fd , &sobj , sizeof(sobj));

    return 0;
}