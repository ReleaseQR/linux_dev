/*************************************************************************
	> File Name: timer.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年08月18日 星期六 19时07分52秒
 ************************************************************************/
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/timer.h>

//定义一个定时器
struct timer_list bigdog_timer;

void bigdog_timer_handler(unsigned long data)
{
    static int bark_cout = 0;
    
    bark_cout++;

    printk("the data = %d \n", data);
    
    if (bark_cout < 10)
    {
        printk("wang wang wang ... \n");
        bigdog_timer.expires = jiffies + HZ*2;
        bigdog_timer.data = bark_cout;
        add_timer(&bigdog_timer);
    }
    //重新开启定时器

}

static int __init timertest_init(void)
{
    //初始化定时器
    init_timer(&bigdog_timer);

    bigdog_timer.expires = jiffies + HZ*2;
    bigdog_timer.function = bigdog_timer_handler;
    bigdog_timer.data = 10;

    //添加定时器到内核中
    add_timer(&bigdog_timer);

    return 0;
}


static void __exit timertest_exit(void)
{
    //从内核中删除定时器
    del_timer(&bigdog_timer);
    return;
}


module_init(timertest_init);
module_exit(timertest_exit);
MODULE_LICENSE("GPL");
