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
#include<string.h>

int main(int argc, char** argv)
{
    int fd;
    int len;
    char buf[1024];
    char* sendbuf = "i am from user";
    fd = open("/dev/ldm_demo", O_RDWR);//open除了目录外，其他都可以打开
    if (fd < 0)
    {
        perror("canot open ");
    }
    
    len = read(fd, buf, 1024);
    /*
    for (i = 0; i < len; i++)
        printf("%c", buf[i]);
    */

    printf("%s", buf);
    printf("\n");

    len = write(fd, sendbuf, strlen(sendbuf));

    close(fd);
    return 0;
}
