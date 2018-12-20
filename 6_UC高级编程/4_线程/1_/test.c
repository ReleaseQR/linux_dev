/*************************************************************************
	> File Name: test.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月06日 星期六 19时50分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

void* pth_fn_1(void* arg)
{
    printf("thread 1 returning \n");
    return (void*)1; //线程的返回不能采用return
}

void* pth_fn_2(void* arg)
{
    printf("thread 2 exiting \n");
    pthread_exit((void*)2);
}

void* pth_fn_3(void* arg)
{
    while(1)
    {
        printf("thread 3 writing \n");
        sleep(1);
    }
}

int main(int argc, char** argv)
{
    pthread_t tid;
    void* tret;

    pthread_create(&tid, NULL, pth_fn_1, NULL);
    pthread_join(tid, &tid);
    printf("thread 1 exit code %d\n", (int)tret);

    pthread_create(&tid, NULL, pth_fn_2, NULL);
    pthread_join(tid, &tret);
    printf("thread 3 exit code %d\n", (int)tret);

    pthread_create(&tid, NULL, pth_fn_3, NULL);
    sleep(3);
    pthread_cancel(tid);
    pthread_join(tid, &tret);
    printf("thread 3 exit code %d \n", (int)tret);
    return 0;
}
