/*************************************************************************
	> File Name: test_1.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月21日 星期日 22时24分39秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


/*可以增加不同级的数目以解决问题*/
void swap_point(int** p1, int** p2)//保持类型匹配
{
    int* temp; //临时存放的地址值
    temp = *p1; //p1本身是个二级指针，*p1还是地址
    *p1 = *p2;
    *p2 = temp;
    return;
}

int main(int argc, char** argv)
{
    int a = 10;
    int b = 20;

    int* pa = &a;
    int* pb = &b;

    printf("pa = %d \n", *pa);
    printf("pb = %d \n", *pb);
    printf("pa = %lx, pb = %lx \n", (long)pa, (long)pb);

    printf("----------------------------------\n");
    swap_point(&pa,&pb);
    printf("pa = %lx, pb = %lx \n", (long)pa, (long)pb);
    printf("pa = %d \n", *pa);
    printf("pb = %d \n", *pb);
 
    printf("a = %d, b = %d \n", a, b);

    return 0;
}
