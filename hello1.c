#include <linux/init.h>
#include <linux/module.h>
#include <linux/printk.h>
#include <hello1.h>
#include <linux/types.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_DESCRIPTION("Lab5");
MODULE_AUTHOR("Peter Polovinkin <>");

EXPORT_SYMBOL(print_hello);

static int print_hello(uint count)
{
    int i;
    
    if (count == 0){
        pr_warn("WARNING\ncount = 0\n");
    }else if (count >= 5 && count <= 10){
        pr_warn("WARNING\ncount is between 5 and 10\n");
    }else if (count > 10){
        pr_err("ERROR\n count > 10");
        return -EINVAL;
    }
    
    for (i = 0; i < count; i++){
    	pr_info("Hello, world\n");
    }
    return 0;
}

static int __init hello1_init(void)
{
    pr_info("hello1 init");
    return 0;
}

static void __exit hello1_exit(void)
{
    pr_info("hello1 exit");
}

module_init(hello1_init);
module_exit(hello1_exit);
