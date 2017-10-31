#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */

int init_module(void)
{
	printk(KERN_INFO "Hello world 1.\n");
  printk(KERN_INFO "pid\n");
  printk(KERN_INFO "uid, gid of process\n");
  printk(KERN_INFO "all of the children processes pid and name\n");
  printk(KERN_INFO "any flags that are set translated to readable names\n");

	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "Goodbye world 1.\n");
}
