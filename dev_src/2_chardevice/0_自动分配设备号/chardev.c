/*************************************************************************
	> File Name: ioctl.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年08月03日 星期五 21时11分28秒
 ************************************************************************/
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

#include <asm/io.h>
#include <mach/regs-gpio.h>
#include <linux/fs.h>
#include <linux/cdev.h>

#include <linux/device.h>

#define DEV_MAJOR   500
#define DEV_MINOR   0

#define GPM4CON     (*(volatile u32*)((u32)S5P_VA_GPIO2 + 0X02E0))
#define GPM4DAT     (*(volatile u8*)((u32)S5P_VA_GPIO2 + 0X02E4))

dev_t devno;
struct class* ldm_cls;
struct device* ldm_device;
static int led_init(void)
{
    //初始化con寄存器
    GPM4CON = (GPM4CON & ~0XFFFF) | 0X1111;
    printk("led configration sucess \n");
    return 0;
}

static void led_on(u8 stat)
{
    GPM4DAT = (GPM4DAT & ~0XF) | (stat & 0xf);
}

static struct cdev ldm_dev;

static int ldm_open(struct inode *inod, struct file * filp)
{
    printk("open sucess \n");
    led_init();
    led_on(0x00);
    return 0;
}


static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open  = ldm_open,
};


static int __init ldm_init(void)
{
    int ret;
//    devno = MKDEV(DEV_MAJOR, DEV_MINOR);
//    ret = register_chrdev_region(devno, 1, "demo");
    ret = alloc_chrdev_region(&devno, 0, 1, "ldm_led");     //自动分配设备号 这个名字无所谓
    if (ret < 0)
    {
        printk("alloc_chrdev_region failed \n");
        goto err_register_chrdev;
    }

    cdev_init(&ldm_dev, &fops);

    cdev_add(&ldm_dev, devno, 1);
    
    ldm_cls = class_create(THIS_MODULE, "ldm_cls");
    ldm_device = device_create(ldm_cls, NULL, devno, NULL, "ldm_led");  //名字默认载/dev目录下

printk("ldm_init sucess \n");
    return 0;
err_register_chrdev:
    return ret;
}

static void __exit ldm_exit(void)
{
    device_destroy(ldm_cls, devno);
    class_destroy(ldm_cls);
    cdev_del(&ldm_dev);
    unregister_chrdev_region(devno, 1);
    printk("ldm_exit sucess \n");    
}


module_init(ldm_init);
module_exit(ldm_exit);
MODULE_LICENSE("GPL");
