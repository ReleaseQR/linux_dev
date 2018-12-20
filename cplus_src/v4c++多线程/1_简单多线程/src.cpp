/*************************************************************************
	> File Name: src.cpp
	> Author: DengXiang Zhang
	> Mail:1097684676@qq.com 
	> Created Time: 2018年05月11日 星期五 21时26分47秒
 ************************************************************************/

#include<iostream>
#include<unistd.h>
#include<pthread.h>
using namespace std;

void *thread(void *ptr)
{
    int num = 0;
    num = *((int *)(ptr));
    for (int i = 0; i < 3; i++){
        sleep(1);
        cout << "this is child process " << "num = "<< num <<  endl;
    }
    return 0;
}
/*
*pthread()函数：
第一个参数：指向线程标识符的指示符
第二个参数：设置线程属性
第三个参数：线程运行的起始地址，函数指针
第四个参数：运行函数的参数,回调函数参数
* *
*/
int main(int argc, char **argv)
{
    pthread_t id;
    int ret;
    int cn = 123;
    ret = pthread_create(&id, NULL, thread, &cn);
    if (ret){
        cout << "Created pthread error " << endl;
        return 1;
    }
    for (int i = 0; i < 3; i++){
        cout << "this is the main process " << endl;
        sleep(1);
    }

    pthread_join(id, NULL);
    return 0;
}
