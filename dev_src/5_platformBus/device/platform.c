/*************************************************************************
	> File Name: platform.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年08月19日 星期日 16时13分31秒
 ************************************************************************/
#include<linux/kernel.h>
#include<linux/module.h>
#include<linux/init.h>
#include<linux/platform_device.h>

//初始化硬件资源
static struct resource led_resource_table[] = {
    [0] = {
        .start = 0x110002e0 , //LED0的起始地址
        .end   = 0x110002e0 + 4, //LED0的结束地址
        .flags = IORESOURCE_MEM,
    },
};

//设置realease函数
static void led_release(struct device* dev)
{
    printk("release sucess \n");
    return;
}

//初始化一个平台总线设备
static struct platform_device led_dev = {
    .name = "qr_led",
    .dev  = {
        .release = led_release,
    },
    .resource = led_resource_table,
};

static int __init platformdev_init(void)
{
    platform_device_register(&led_dev);
    return 0;
}


static void __exit platformdev_exit(void)
{
    platform_device_unregister(&led_dev);
    return;
}


module_init(platformdev_init);
module_exit(platformdev_exit);
MODULE_LICENSE("GPL");
