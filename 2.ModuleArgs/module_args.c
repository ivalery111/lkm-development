#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");

static int param_value = 0;
static char *param_msg = NULL;

/* Get the parameter */
module_param(param_value, int, 0);
module_param(param_msg, charp, 0);

static int __init hello_init(void)
{
    pr_info("param_value: %d\n", param_value);
    pr_info("param_msg  : %s\n", param_msg);

    return 0;
}

static void __exit hello_exit(void)
{
    pr_info("hello_exit!\n");
}

module_init(hello_init);
module_exit(hello_exit);
