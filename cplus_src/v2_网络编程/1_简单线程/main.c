/*************************************************************************
	> File Name: main.c
	> Author: DengXiang Zhang
	> Mail:1097684676@qq.com 
	> Created Time: 2018年05月15日 星期二 22时05分58秒
 ************************************************************************/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_t ntid;

void printids(const char *s)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();
    printf("%s pid %u tid %u (0x%x) \n", s, (unsigned int)pid, (unsigned int)tid, (unsigned int)tid);
}

void *thr_fn(void *arg)
{
    printids(arg);
    return NULL;
}

int main(int argc, char **argv)
{
    int err;

    err = pthread_create(&ntid, NULL, thr_fn, "new thread: ");
    if (err != 0)
    {
        fprintf(stderr,"can't create thread : %s\n", strerror(err));
        exit(1);
    }

    printids("main thread: ");
    sleep(1);
    return 0;
}
