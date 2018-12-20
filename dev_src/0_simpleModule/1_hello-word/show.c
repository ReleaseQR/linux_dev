/*************************************************************************
	> File Name: show.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月08日 星期日 20时45分20秒
 ************************************************************************/
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int a = 0;

int show_addr(void)
{
    printk("kernel addr : %p  %p \n", &a, show_addr);
    return 0;
}
