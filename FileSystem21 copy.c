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

    printf("Enter the File Name \n");
    scanf("%s" , Fname);

    fd = open(Fname ,O_RDONLY);

    read (fd , &sobj , sizeof(sobj));
    printf("Roll Number : %d \n",sobj.RollNo);
    printf("Name : %s \n",sobj.Sname);
    printf("Marks  : %f \n",sobj.Marks);
    printf("Age  : %d \n",sobj.Age);

    close(fd);

    return 0;
}