#include <linux/module.h>

MODULE_LICENSE("GPL");

static int __init hello_init(void)
{
    pr_info("hello_init!\n");

    return 0;
}

static void __exit hello_exit(void)
{
    pr_info("hello_exit!\n");
}

module_init(hello_init);
module_exit(hello_exit);
