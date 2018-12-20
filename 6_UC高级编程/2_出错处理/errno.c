/*************************************************************************
	> File Name: errno.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月14日 星期六 21时45分38秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
int main(int argc, char **argv)
{
    FILE* file = fopen("/etc/passwd2", "r");
    if (NULL == file)
    {
        printf("%s \n", strerror(errno));
        perror("fopen"); //函数出错 基本使用perror
        printf("%m \n");
    }
    else            //如果不加else的话将会导致段错误
    fclose(file);

    return 0;
}
