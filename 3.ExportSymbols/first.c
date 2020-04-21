#include <linux/module.h>

MODULE_LICENSE("GPL");

const int NUMBER = 10;

void print_number(int number)
{
    pr_info("number = %d\n", number);
}

EXPORT_SYMBOL(print_number);

static int __init first_init(void)
{
    pr_info("first init!\n");
    print_number(NUMBER);

    return 0;
}

static void __exit first_exit(void)
{
    pr_info("first exit!\n");
}

module_init(first_init);
module_exit(first_exit);
