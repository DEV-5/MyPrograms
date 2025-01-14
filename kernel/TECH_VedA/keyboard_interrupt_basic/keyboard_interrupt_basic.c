/*
 * Author: Vasudev
 * DATE: 24-02-20
 */
#include <linux/module.h>
//#include <linux/kernel.h>
//#include <linux/fs.h>
//#include <linux/cdev.h>
#include <linux/init.h>
#include <linux/interrupt.h>

#define SHARED_IRQ 1

static int irq = SHARED_IRQ, my_dev_id = 1, irq_counter = 0;
module_param(irq,int,S_IRUGO);

static irqreturn_t my_interrupt(int irq, void *dev_id)
{
    irq_counter++;
    printk("\nKIB: Inside the ISR Counter = %d\n", irq_counter);
    return IRQ_NONE; //we return IRQ_NONE because we are just observing
    //return IRQ_HANDLED;
}

static int __init keyboard_interrupt_init(void)
{
    int ret = 0;
    pr_info("\nKIB: Inside keyboard_interrupt_init module");
    ret = request_irq(irq,my_interrupt, IRQF_SHARED, "my_interrupt_dev",&my_dev_id);
    if(ret<0)
    {
        pr_err("\nKIB: Error Registering device drive \n");\
        return -1;
    }
    pr_info("\nKIB: Requested IRQ handler\n");
    return 0;
}

void __exit keyboard_interrupt_exit(void)
{
    pr_info("\nKIB: Inside keyboard_interrupt_exit: exiting module");
    synchronize_irq(irq);
    free_irq(irq,&my_dev_id);
    pr_info("\nKIB: Sucessfully unloaded \n");
}

module_init(keyboard_interrupt_init);
module_exit(keyboard_interrupt_exit);

MODULE_AUTHOR("VASUDEV M");
MODULE_DESCRIPTION("Keyboard Interrupt handler");
MODULE_LICENSE("GPL");
