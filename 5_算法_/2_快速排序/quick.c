/*************************************************************************
	> File Name: quick.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月13日 星期二 17时27分42秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int num[10] = {3, 7, 9, 6, 8, 2, 1, 0, 4, 5};
void Serot(int left, int right)
{
    int temp;
    int i, j;

    if (left > right)
        return;

    temp = num[left];
    i = left;
    j = right;

    while(i != j)
    {
        while(num[j] >= temp && i < j )
            j--;
        while(num[i] <= temp && i < j)
            i++;

        if (i < j)
        {
            int t = num[i];
            num[i] = num[j];
            num[j] = t;
        }
    }

    num[left] = num[i];
    num[i] = temp;

    Serot(left, i-1);
    Serot(i+1, right);
}


int main(int argc, char** argv)
{

    Serot(0, 9);
    for (int i = 0; i < 10; i++)
        printf("%d, ", num[i]);
    printf("\n");
    return 0;
}
