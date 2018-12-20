/*************************************************************************
	> File Name: stack.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月13日 星期五 22时22分06秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define MAXLEN      100

typedef struct Stack{
    int point;
    int buf[MAXLEN];
}stack; 


int pushStack(stack* nstack , int data)
{
    if (nstack->point >= MAXLEN)
        return -1;
    nstack->buf[nstack->point] = data;
    nstack->point++;
    return nstack->point;
}

int popStack(stack* nstack)
{
    if (nstack->point < 0)
        return -1;
    nstack->point--;
    return nstack->buf[nstack->point];
}

int main(int argc, char **argv)
{
    int data[200] = {1};
    stack* vstack = (stack*)malloc(sizeof(stack));
    int i = 0;
    int reVal;
    vstack->point = 0;

    for (i = 0; i < 105; i++)
    {
        reVal = pushStack(vstack, i);
        if (-1 != reVal)
        {
            printf(" %d, ", i);
        }else
        printf("stack is full \n ");
    }
    printf("\n");

    for (i = 0; i < 105; i++)
    {
        reVal = popStack(vstack);
        if (-1 != reVal)
        {
            printf(" %d, ", reVal);
        }else
        printf("stack is emty \n");
    }
    printf("\n");
 
    return 0;
}
