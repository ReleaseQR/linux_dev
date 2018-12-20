/*************************************************************************
	> File Name: list.c
	> Author: 张登翔
	> Mail:1097684676@qq.com 
	> Created Time: 2018年08月18日 星期六 15时23分16秒
 ************************************************************************/

#include<linux/init.h>
#include<linux/kernel.h>
#include<linux/module.h>

#include<linux/slab.h>
#include<linux/list.h>
#include<linux/err.h>


#define NUM     10

struct list_head employee_list;
struct employee *employeep = NULL;

struct employee{
    char name[20];
    int id;
    int age;
    struct list_head list; //使用内核提供的链表
};


static int __init listtest_init(void)
{
    int ret;
    int i = 0;
    struct list_head* pos = NULL;
    struct employee* employee_temp = NULL;

    //初始化链表的头节点
    INIT_LIST_HEAD(&employee_list);

    //申请employee的空间
    employeep = kmalloc(NUM * (sizeof(struct employee)), GFP_KERNEL);
    if (IS_ERR(employeep))
    {
        printk("kmalloc failed \n");
        return -ENOMEM;
    }

    memset(employeep, 0, sizeof(struct employee)*NUM);

    //初始化一个struct
    for (i = 0; i < NUM; i++)
    {
        sprintf(employeep[i].name, "e%d", i);
        employeep[i].id = 10000 + i;
        
        //添加节点到链表中去
        list_add(&(employeep[i].list), &employee_list);
    }

    //链表的遍列
    list_for_each(pos, &employee_list) //pos用于保存每次遍历后的节点
    {
        employee_temp = list_entry(pos, struct employee, list);
        printk("%s \n", employee_temp->name);
        printk("%d \n", employee_temp->id);
    }

    return 0;
}

static void __exit listtest_exit(void)
{
    kfree(employeep);
    return;
}


module_init(listtest_init);
module_exit(listtest_exit);


MODULE_LICENSE("GPL");
