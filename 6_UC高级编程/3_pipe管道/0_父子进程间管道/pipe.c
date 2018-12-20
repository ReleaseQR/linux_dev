/*************************************************************************
	> File Name: pipe.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年08月21日 星期二 21时18分21秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char** argv)
{
    int fd[2];
    int ret;
    pid_t pid;

    ret = pipe(fd);
    if (ret < 0 )
    {
        perror("create pip fialed");
        return ret;
    }

    //管道创建成功后，创建进程
    pid = fork();
    if (pid == -1)
    {
        perror("fork error");
        exit(1);
    }

    //patent process
    if (pid > 0)
    {
        //写管道操作,关闭读端
        close(fd[0]);
        //重定向
        dup2(fd[1], STDOUT_FILENO);
        execlp("ps", "ps", "aux", NULL);
        perror("execp");
        exit(1);
    }
    else if (pid == 0)
    {
        close(fd[1]);
        //重定向
        dup2(fd[0], STDIN_FILENO);
        execlp("grep", "grep","net", "--color=auto", NULL);
        exit(1);
    }
    return 0;
}
