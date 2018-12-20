/*************************************************************************
	> File Name: mutex.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月07日 星期日 10时00分13秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define NLOOP           200
//共享资源
int counter = 0;
//线程互斥量
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void* thr_fn(void* args)
{
    int i, val;
    for (i = 0; i < NLOOP; i++)
    {
        //执行前先上锁
        pthread_mutex_lock(&counter_mutex);
        val  = counter;
        printf("thread id = %u, val = %d \n", (unsigned int)pthread_self(), val);
        counter = val + 1;
        //执行完毕后进行解锁操作
        pthread_mutex_unlock(&counter_mutex);
    }

    return NULL;
}

int main(int argc, char** argv)
{
    pthread_t tidA, tidB;
    pthread_create(&tidA, NULL, thr_fn, NULL);
    pthread_create(&tidB, NULL, thr_fn, NULL);

    //wait for both threads to terminate
    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);

    return 0;
}
