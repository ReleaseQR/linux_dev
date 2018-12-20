/*************************************************************************
	> File Name: test.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月21日 星期日 22时12分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct student{
    int age;
    char name[256];
}Student;

int main(int argc, char** argv)
{
    Student Stu1, Stu2;

    Stu1.age =  10;
    Stu2 = Stu1;

    strcpy(Stu1.name, "张登翔");
    printf("Stu1.name = %s \n", Stu1.name);

    printf("Stu2.age = %d \n", Stu2.age);
    printf("Stu2.name = %s \n", Stu2.name);
    return 0;
}
