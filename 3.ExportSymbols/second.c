#include <linux/init.h>
#include <linux/module.h>

extern void print_number(int);

static int __init second_init(void)
{
    pr_info("second init!\n");
    print_number(200);
    print_number(300);

    return 0;
}

static void __exit second_exit(void)
{
    pr_info("second exit!\n");
}

module_init(second_init);
module_exit(second_exit);