/*************************************************************************
	> File Name: hello.c
	> Author: DengXiang Zhang
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月08日 星期日 17时18分33秒
 ************************************************************************/
#include <linux/init.h>
#include <linux/module.h>
#include "show.h"
//extern int show_addr(void);

static int irq;
static char *pstr;

module_param(irq, int, 0664);
module_param(pstr, charp, 0);

static int __init hello_init(void)
{
    printk("hello init \n");
    printk("irq = %d, pstr = %s \n", irq, pstr);
    show_addr();
    return 0;
}

static void __exit hello_exit(void)
{
    printk("hello_exit \n");
    printk("irq = %d, pstr = %s \n", irq, pstr);
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zhang Deng Xiang");
module_init(hello_init);    //insmod hello.ko
module_exit(hello_exit);
