/*
 * Author: vasudev
 * basic kernal module
 */ 

#include <linux/module.h>
#include <linux/sched.h>
#include <linux/delay.h>
#include <linux/init.h>

void aprint(void);
int mod_start(void);
void mod_end(void);

int var;

void aprint()
{
    printk("TEST: this is a print\n");
}

int mod_start()
{
    printk("inside mod_init\n");
    printk("\nTEST: pid=%d and current=%d\n",task_pid_nr(current),current->pid);
    msleep(10000);
    aprint();
    return 0;
}

void mod_end()
{
    pr_info("TEST: inside mod_exit\n");
}

module_init(mod_start);
module_exit(mod_end);

EXPORT_SYMBOL_GPL(var);

MODULE_AUTHOR("vasudev0510@gmail.com");
MODULE_DESCRIPTION("LKD_CW : First kernal module");
MODULE_LICENSE("GPL");


