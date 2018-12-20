/*************************************************************************
	> File Name: src.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月13日 星期二 18时05分59秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    int data[100] = {0, 6, 3, 1, 7, 5, 8, 9, 2, 4};
    int head, tail;

    head = 1;
    tail = 10;

    while(head != tail)
    {
        //先弹出第一个元素
        printf("%d, ", data[head]);
        head++;

        data[tail] = data[head];
        tail++;
        head++;
    }
    return 0;
}
