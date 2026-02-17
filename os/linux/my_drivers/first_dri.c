#include<linux/module.h>
#include<linux/init.h>

 int my_first_dri_init(void)
{
 printk(KERNEL_ALERT "(first_driver)%s has been launched\n",__FUNCTION__);
 return 0;
}
 void my_first_dri_exit(void)
{
  printk(KERNEL_ALERT "(first_driver)%s has been removed\n"__FUNCTION__);
}
module_init(first_dri_init);
module_exit(first_dri_exit);
