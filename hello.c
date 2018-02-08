
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/slab.h>


SYSCALL_DEFINE1(test_syscall,const char __user *, tag) {
    
    size_t size_of_tag = strlen(tag);
    char *ntag = kmalloc(size_of_tag + 1,GFP_KERNEL);
    copy_from_user(ntag, tag, size_of_tag);
    ntag[size_of_tag] = '\0';
    return 0;
}

static int hello_init(void) {
    printk(KERN_ALERT "I bear a charmed life. \n");
    void *tp = kmalloc(16, GFP_KERNEL);
    kfree(tp);
    return 0;
}

static void hello_exit(void) {
    printk(KERN_ALERT "Out, out, brief chandle! \n");
}

module_init(hello_init);
module_exit(hello_exit);


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Paulus");
MODULE_DESCRIPTION("A hello, World Module");
