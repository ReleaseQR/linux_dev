/*************************************************************************
	> File Name: test.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月07日 星期日 09时44分15秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

#define NUM 200
//共享资源
int counter = 0;

void* thr_fn(void* args)
{
    int val;
    int i = 0;
    for (i = 0; i < NUM; i++)
    {
        val = counter;
        printf("thread id = %u, counter = %d \n", (unsigned int)pthread_self(), counter);
        counter = val + 1;
    }

    return NULL;
}

int main(int argc, char** argv)
{
    pthread_t tidA, tidB;

    //创建两个线程
    pthread_create(&tidA, NULL, &thr_fn, NULL);
    pthread_create(&tidB, NULL, &thr_fn, NULL);

    //等待回收线程
    pthread_join(tidA, NULL);
    pthread_join(tidB, NULL);

    return 0;
}
