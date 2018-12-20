/*************************************************************************
	> File Name: erro.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月14日 星期六 20时19分34秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<unistd.h>

int maxNum(int num1, int num2, int* max)
{
    if(num1 == num2)
    {
        *max = num1;
        return -1;
    }
    else
    *max = (num1 > num2) ? num1 : num2;
    return 0;
}

int randomdata(void)
{
    srand(time(0)); //防止伪随机
    int rad = rand() % 11; //注意，这里是要的0-10，所以要对11进行取余。10是我需要的
    if (0 == rad)
    {
        return -1;
    }
    else
    {
        return rad;
    }
}

char* iserror(char* str)
{
    if (!strcmp(str, "error"))
        return NULL;
}



int main(int argc, char **argv)
{
    int n1 = 21;
    int n2 = 21;
    int reVal = 0;
    if (!maxNum(n1, n2, &reVal))
    {
        printf("the max num = %d \n", reVal);
    }
    else
    {
        printf("the num1 =  num2 \n");
        printf("the max num = %d \n", reVal);
    }

    for( ; n1 >= 0; n1--)
    {
        if (-1 == randomdata())
        {
            printf("the num = 0 \n");
        }else
        {
            printf("the random data = %d \n", randomdata());
        }
        sleep(1);

    }
    return 0;
}
