/*************************************************************************
	> File Name: readwrite.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年08月04日 星期六 17时08分32秒
 ************************************************************************/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include <linux/fs.h>
#include <linux/device.h>
#include <asm/uaccess.h>
char kbuf[1024] = {"i am kernel data"};
char revbuf[1024];
int major;


struct class* ldm_cls;
struct device* ldm_devs;

static int ldm_open(struct inode *inode, struct file* filp)
{

    return 0;
}

static int ldm_close(struct inode* inode, struct file* filp)
{
    return 0;
}

static ssize_t ldm_read(struct file* filp, char __user* buf, size_t size, loff_t* off)
{
    size_t read_len = strlen(kbuf) + 1;
//    strncpy(buf, kbuf, read_len); //返回的是指针，并不是返回复制到的字节数
    copy_to_user(buf, kbuf, read_len);
    return read_len;
}

static ssize_t ldm_write(struct file* filp, const char __user* buf, size_t size, loff_t* off) //注意的是write比read多一个const修辞
{
    size_t len;
    len = copy_from_user(revbuf, buf, size);
    printk("%s", revbuf);
    printk("\n");
    return len;
}


struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = ldm_open,
    .read = ldm_read,
    .write = ldm_write,
    .release = ldm_close,
};

static int __init ldm_init(void)
{
    major = register_chrdev(0, "ldm_demo", &fops);
    
    ldm_cls = class_create(THIS_MODULE, "demo");
    ldm_devs = device_create(ldm_cls, NULL, MKDEV(major, 0), NULL, "ldm_demo");
    return 0;
}

static void __exit ldm_exit(void)
{
    device_destroy(ldm_cls, MKDEV(major, 0));
    class_destroy(ldm_cls);
    unregister_chrdev(major, "ldm_demo");
}

module_init(ldm_init);
module_exit(ldm_exit);
MODULE_LICENSE("GPL");
