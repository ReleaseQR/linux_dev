/*************************************************************************
	> File Name: test.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年08月25日 星期六 14时51分57秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char** argv)
{

    int fd;

    fd = open("/dev/led_oo", O_RDWR);

    close(fd);
    return 0;
}
