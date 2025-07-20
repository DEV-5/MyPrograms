/*
 * Author: Vasudev
 * 
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/init.h>

#define MAJORNO 190
#define MINORNO  0
#define CHAR_DEV_NAME "vdev1"

static dev_t mydev;
static int count = 1;
static struct cdev * veda_cdev;

static int char_dev_open(struct inode* inode,struct file* file)
{
    printk("\nSCD: Inside char_dev_Open\n");
}

static int char_dev_release(struct inode *inode, struct file *file)
{
    printk("\nSCD: Inside char_dev_release\n");
}

static ssize_t char_dev_write(struct file *file,
        const char __user *buf,size_t buf2,loff_t *offset)
{
    printk("\nSCD: Inside char_dev_write\n");
}

static ssize_t char_dev_read(struct file *file,
        char *buf, size_t buf2, loff_t *offset)
{
    printk("\nSCD: Inside char_dev_read\n");
}

static struct file_operations char_dev_fops = {
    .owner = THIS_MODULE,
    .write = char_dev_write,
    .read  = char_dev_read,
    //.open  = char_dev_open,
    .release = char_dev_release
    };

static int __init simple_char_init(void)
{
    int ret = 0;
    printk("\nSCD: Inside simple_char_init module");
    mydev = MKDEV(MAJORNO,MINORNO);
    ret = register_chrdev_region(mydev,count,CHAR_DEV_NAME);
    if(ret<0)
    {
        pr_err("\nSCD: Error Setting majorno(%d) and minorno(%d)\n",MAJORNO,MINORNO);
    }
    /*allocate cdev instance*/
    veda_cdev = cdev_alloc();
    if(veda_cdev == NULL)
    {
        pr_err("\nSCD: Error while allocating cdev structure \n");
    }
    /*initialize cdev with address of driver fops objects*/
    cdev_init(veda_cdev,&char_dev_fops);
    /*register cdev with vfs(devtmpfs)*/
    ret = cdev_add(veda_cdev,mydev,count);
    if(ret<0)
    {
        pr_err("\nSCD: Error Registering device drive \n");
    }
}

void __exit simple_char_exit(void)
{
    printk("\nSCD: Inside simple_char_exit: exiting module");
    /*remove cdev*/
    cdev_del(veda_cdev);
    /*free major/minor no that are not used*/
    unregister_chrdev_region(mydev,count);
}

module_init(simple_char_init);
module_exit(simple_char_exit);
