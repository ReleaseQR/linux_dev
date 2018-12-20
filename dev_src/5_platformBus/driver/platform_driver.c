/*************************************************************************
	> File Name: platform_driver.c
	> Author: zhang dengxiang
	> Mail: 995361462@qq.com
	> Created Time: 2018年08月25日 星期六 10时06分24秒
 ************************************************************************/
#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

#include<linux/fs.h>
#include<linux/cdev.h>
#include<linux/platform_device.h>
#include<linux/device.h>


dev_t devno;
int led_major;


static struct cdev led_cdev = {
    .owner = THIS_MODULE,
};


struct class *led_cls = NULL;
struct device *led_device = NULL;


static int leddrv_open (struct inode *nod, struct file *filp)
{
    printk("led dir is open \n");
    return 0;
}

static struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = leddrv_open,
};

static int leddrv_probe(struct platform_device* pdev)
{
    int ret;
    printk("match sucess qr_led \n");

    
    //1->初始化一个字符设备
    cdev_init(&led_cdev, &fops);

    //2->申请设备号
    ret = alloc_chrdev_region(&devno, 0, 1, "qr_no");
    if (ret < 0)
    {
        printk("alloc_chrdev failed \n");
        return ret;
    }

    //3->添加字符设备到申请的设备号
    ret =  cdev_add(&led_cdev, devno, 1);
    if (ret < 0) 
    {
        printk("cdev_add failed \n");
        goto err_add_cdev;
    }
    

//    led_major =  register_chrdev(0, "LED", &fops);


    //4->自动创建设备节点
    led_cls = class_create(THIS_MODULE, "love_qr");
    //led_device = device_create(led_cls, NULL, MKDEV(led_major, 0), NULL, "led_oo");
    led_device = device_create(led_cls, NULL, devno, NULL, "led_oo");

    return 0;

err_add_cdev:
    unregister_chrdev_region(devno, 1);

    return ret;
}

static int leddrv_rmove(struct platform_device* pdev)
{
    //device_destroy(led_cls, MKDEV(led_major, 0));
    device_destroy(led_cls, devno);
    class_destroy(led_cls);
    cdev_del(&led_cdev);
    unregister_chrdev_region(devno, 1);
//    unregister_chrdev(MKDEV(led_major, 0), "LED");
    return 0;
}

static struct platform_driver plt_leddrv = {
    .driver = {
        .name = "qr_led",
        .owner = THIS_MODULE,
    },
    .probe = leddrv_probe,
    .remove = leddrv_rmove,
};



static int __init platform_leddrv_init(void)
{
    platform_driver_register(&plt_leddrv);
    return 0;
}


static void __exit platform_leddrv_exit(void)
{
    platform_driver_unregister(&plt_leddrv);
    return;
}



module_init(platform_leddrv_init);
module_exit(platform_leddrv_exit);

MODULE_LICENSE("GPL");
