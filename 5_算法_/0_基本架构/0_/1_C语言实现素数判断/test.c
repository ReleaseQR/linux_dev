/*************************************************************************
	> File Name: test.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月22日 星期一 10时19分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

char isPareNum(int num)
{
    if (num < 2)
        return 0;
    for (int i = 2; i*i <= num; i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char** argv)
{
    int num;
    while(1)
    {
        scanf("%d", &num);
        if (isPareNum(num) == 1)
        {
            printf("%d is pareNum \n", num);
        }
        else
        {
            printf("%d is not pareNum \n", num);
        }
    }
    return 0;
}
