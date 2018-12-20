/*************************************************************************
	> File Name: rwlock.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年10月07日 星期日 10时24分19秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int counter;
pthread_rwlock_t rwlock;

void* th_write(void* args)
{
    int t;
    while(1)
    {
        pthread_rwlock_wrlock(&rwlock);
        t = counter;
        usleep(100);
        printf("write %x : counter = %d ++counter = %d \n", (int)pthread_self(), t, ++counter);
        pthread_rwlock_unlock(&rwlock);
        usleep(100);
    }
    return NULL;
}

void* th_read(void* args)
{
    while(1)
    {
        pthread_rwlock_rdlock(&rwlock);
        printf("read %x : %d \n", (int)pthread_self(), counter);
        pthread_rwlock_unlock(&rwlock);
        usleep(100);
    }
    return NULL;
}

int main(int argc, char** argv)
{
    //总共8个线程，其中3个写线程，5个读线程
    pthread_t tid[8];
    int i;
    //先初始化读写锁
    pthread_rwlock_init(&rwlock, NULL);
    for (i = 0; i < 3; i++)
        pthread_create(&tid[i], NULL, th_write, NULL);
    for (i = 0; i < 5; i++)
        pthread_create(&tid[i+3], NULL, th_read, NULL);
    for (i = 0; i < 8; i++)
        pthread_join(tid[i], NULL);

    //释放锁
    pthread_rwlock_destroy(&rwlock);
    return 0;
}
