/*************************************************************************
	> File Name: src.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年11月13日 星期二 16时04分02秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>


int data[10] = {2, 9, 6, 4, 1, 8, 10, 7, 4, 5};

void Serot(int left, int right)
{
    int i, j;
    //找基准
    int temp = data[left];
    
    if (left > right)
    {
        return;
    }

    i = left;
    j = right;

    while(i != j)
    {
        while(data[j] >= temp && i < j)
            j--;
        while(data[i] <= temp && i < j)
            i++;

        if (i < j)
        {
            int t = data[i];
            data[i] = data[j];
            data[j] = t; 
        }
    }

    data[left] = data[i];
    data[i] = temp;

    Serot(left, i-1);
    Serot(i+1, right);
}

int main(int argc, char** argv)
{
    
    Serot(0, 9);
    for (int i = 0; i < 10; i++)
      printf("%d , ", data[i]);
    printf("\n");
    return 0;
}
