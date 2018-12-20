/************************************************************************
	> File Name: src.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月13日 星期二 12时29分22秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int main(int argc, char** argv)
{
    int data[10] = {1, 9, 7, 8, 4, 3, 8, 9, 10, 2};
    int temp;
    int len = sizeof(data) / sizeof(int);

    for (int i = 0; i < 10; i++)
        printf("%d , ", data[i]);
    printf("\n");

    
/*
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - 1 - i; j++)
            if (data[j] > data[j + 1])
            {
                temp = data[j] ;
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
    }
    for (int i = 0; i < 10; i++)
        printf("%d , ", data[i]);
*/

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j <= len - 1; j++)
        {
            if (data[i] > data[j])
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            } 
        }
    }

    for (int i = 0; i < 10; i++)
        printf("%d , ", data[i]);

    printf("\n");
    return 0;
}
