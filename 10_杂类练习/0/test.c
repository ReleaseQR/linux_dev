/*************************************************************************
	> File Name: test.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月23日 星期二 21时43分18秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char** argv)
{
    int tab[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++)
    {
        printf("*(tab + %d ) = %d \n", i, *(tab+i));
    }

    return 0;
}
