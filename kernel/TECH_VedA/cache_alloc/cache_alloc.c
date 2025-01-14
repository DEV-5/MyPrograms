/*
 * Author: Vasudev.M
 * purpose: driver module to allocate cache 
 */
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/mm.h>
#include <linux/init.h>
//#include <linux/fs.h>
//#include <linux/cdev.h>

typedef struct {
    int a;
    int b;
    char c;
}mystruct;

struct kmem_cache *cache_ptr;
mystruct* obj;

static mystruct * mystruct_cache_alloc(void)
{
    mystruct* mycache; 
    mycache = kmem_cache_alloc(cache_ptr,GFP_KERNEL);
    return mycache;
}

void cache_init(void* data)
{
    mystruct *myobj = (mystruct*)data;
    myobj->a = 0;
    myobj->b = 0;
    myobj->c = '0';  
}

static int __init cache_alloc_init(void)
{
    pr_info("\nCache_Alloc: Inside INIT \n");
    cache_ptr = kmem_cache_create("test_cache",sizeof(mystruct),0,
            SLAB_HWCACHE_ALIGN,cache_init);
    if(cache_ptr==NULL)
    {
        pr_err("\nCache_Alloc: Error Registering device drive \n");
    }
    obj = mystruct_cache_alloc();
    if(obj==NULL)
    {
        pr_err("\nCache_Alloc: Error Registering device drive \n");
    }
    return 0;
}

void __exit cache_alloc_exit(void)
{
    pr_info("\nCache_Alloc: inside exit\n");
    kmem_cache_free(cache_ptr,obj);
    kmem_cache_destroy(cache_ptr);
}

module_init(cache_alloc_init);
module_exit(cache_alloc_exit);
