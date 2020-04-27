#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <asm/uaccess.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/types.h>

static dev_t first_device;
static unsigned int count = 1;
static int major_num = 250, minor_num = 0;
static struct cdev *char_device;

#define DEVICE_NAME "char_dev"
#define KERNEL_BUF_SIZE ((10) * PAGE_SIZE)

static int open_counter = 0;

int char_device_open(struct inode *inode, struct file *file)
{
    open_counter++;
    printk(KERN_INFO "Custom device: opened %d time\n", open_counter);
    return 0;
}

int char_device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Custom device: release\n");
    return 0;
}

ssize_t char_device_read(struct file *file, char __user *buffer, size_t buff_len, loff_t *pos)
{
    printk(KERN_INFO "Custom device: read\n");
    return 0;
}

ssize_t char_device_write(struct file *file, const char __user *buffer, size_t buff_len, loff_t *pos)
{
    printk(KERN_INFO "Custom device: write\n");
    return buff_len; /* if returns 0 will enter to infinity loop because in userspace the result of sys.call will be 0 */
}

static const struct file_operations char_device_ops = {

    .owner = THIS_MODULE,
    .read = char_device_read,
    .write = char_device_write,
    .open = char_device_open,
    .release = char_device_release};

static int __init hello_init(void)
{
    pr_info("hello_init!\n");

    first_device = MKDEV(major_num, minor_num);

    register_chrdev_region(first_device, count, DEVICE_NAME);

    char_device = cdev_alloc();
    cdev_init(char_device, &char_device_ops);
    cdev_add(char_device, first_device, count);

    return 0;
}

static void __exit hello_exit(void)
{
    open_counter = 0;

    if (char_device)
        cdev_del(char_device);

    /* release major number of this device */
    unregister_chrdev_region(first_device, count);
    pr_info("hello_exit!\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");