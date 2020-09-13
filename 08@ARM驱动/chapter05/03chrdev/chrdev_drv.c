#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>

MODULE_LICENSE("GPL");

#define DEVICE_NAME "chrdev_drv"
int major = 0;
dev_t dev_nr = 0;

static int chrdev_open(struct inode* pinode, struct file* pfile) {
    printk("%s\n", __FUNCTION__);
    return 0;
}

static int chrdev_release(struct inode* pinode, struct file* pfile) {
    printk("%s\n", __FUNCTION__);
    return 0;
}

static ssize_t chrdev_read(struct file* pfile, char __user *buf, size_t count, loff_t* offset) {
    printk("%s\n", __FUNCTION__);
    return count;
}

static ssize_t chrdev_write(struct file* pfile, const char __user *buf, size_t count, loff_t* offset) {
    printk("%s\n", __FUNCTION__);
    return count;
}

static loff_t chrdev_llseek(struct file* pfile, loff_t offset, int origin) {
    printk("%s\n", __FUNCTION__);
    return 0;
}

static int chrdev_ioctl(struct file* pfile, unsigned int cmd, unsigned long arg) {
    printk("%s\n", __FUNCTION__);
    return 0;
}

struct file_operations dev_ops = {
    .open = chrdev_open,
    .release = chrdev_release,
    .read = chrdev_read,
    .write = chrdev_write,
    .llseek = chrdev_llseek,
    .unlocked_ioctl = chrdev_ioctl,
};

struct cdev my_cdev;

static int __init chrdev_init(void) {
    int ret;
    ret = register_chrdev_region(MKDEV(major, 0), 1, DEVICE_NAME);

    if()
}
module_int(chrdev_init);
module_exit(chrdev_exit);
