/*************************************************************************
	> File Name: test_app.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年08月03日 星期五 22时51分49秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char** argv)
{
    int fd;
    fd = open("/dev/ldm_led", O_RDWR);//open除了目录外，其他都可以打开
    if (fd < 0)
    {
        perror("canot open ");
    }
    close(fd);
    return 0;
}
