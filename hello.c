#include <linux/init.h>   // module_init / module_exit
#include <linux/module.h> // MODULE_*
#include <linux/kernel.h> // printk
#include <linux/slab.h>   // 提供kmalloc接口，基于对象的内存管理器，通过着色法增加行缓存命中率

static int __init hello_init(void) {
    printk(KERN_ALERT "I bear a charmed life. \n");
    void *tp = kmalloc(16, GFP_KERNEL); // 最大只能开辟128k-16 16个字节是被页描述符结构占用了
    kfree(tp);
    return 0;
}

static void __exit hello_exit(void) {
    printk(KERN_ALERT "Out, out, brief chandle! \n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Paulus");
MODULE_DESCRIPTION("A hello, World Module");
