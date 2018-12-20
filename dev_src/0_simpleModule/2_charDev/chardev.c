/*************************************************************************
	> File Name: dev.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年07月08日 星期日 20时39分29秒
 ************************************************************************/
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>


static int __init hello_init(void)
{
    return 0;
}

static void __exit hello_exit(void)
{
    
}

module_init(hello_init);
module_exit(hello_exit);
MODULE_AUTHOR("Zhang Deng Xiang");
MODULE_LICENSE("GPL");
