/*************************************************************************
	> File Name: hello.c
	> Author: DengXiang Zhang
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月08日 星期日 17时18分33秒
 ************************************************************************/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/miscdevice.h>

struct ldm_info{
    struct miscdevice dev;
    struct file_operations;
};

static int __init hello_init(void)
{
    return 0;
}

static void __exit hello_exit(void)
{
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Zhang Deng Xiang");
module_init(hello_init);    //insmod hello.ko
module_exit(hello_exit);
