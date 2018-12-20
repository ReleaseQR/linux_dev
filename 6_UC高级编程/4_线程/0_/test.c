/*************************************************************************
	> File Name: test.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月06日 星期六 18时56分01秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

//线程ID
pthread_t ntid;


void printids(const char *str)
{
    pid_t pid;
    pthread_t tid;

    pid = getpid();
    tid = pthread_self();

    printf("%s pid = %u, tid = %u \n", str, (unsigned int)pid, (unsigned int)tid);

}

void* thr_fn(void* arg)
{
    printids(arg);

    return NULL;
}

int main(int argc, char** argv)
{
    
    int err;

    //创建线
    err = pthread_create(&ntid, NULL, thr_fn, "new thread: ");
    if (err != 0)
    {
        fprintf(stderr, "can't create thread: %s \n",strerror(err));
        exit(1);
    }
    printf("the create pthread = %u \n", (unsigned int)ntid);
    printids("main thread:");
    sleep(1);


    return 0;
}
