#include <linux/module.h>	/* Needed by all modules */
#include <linux/kernel.h>	/* Needed for KERN_INFO */
#include <linux/init.h>		/* Needed for the macros */

int pid = 0;

static int __init pid_info(void)
{
  *find_get_pid(pid_t nr) /* gets the struct pid of our pid */
  *pid_task(struct pid *pid, enum pid_type type) /* returns the struct task_struct of our pid */
  printk(KERN_INFO "PROCESS PID: ");
  printk(KERN_INFO "uid, gid of process\n");
  printk(KERN_INFO "all of the children processes pid and name\n");
  printk(KERN_INFO "any flags that are set, translated to readable names\n");
	return 0;
}

static void __exit pid_info_exit(void)
{
  printk(KERN_INFO "Goodbye, world\n");
}

/*
 * module_param(foo, int, 0000)
 * The first param is the parameters name
 * The second param is it's data type
 * The final argument is the permissions bits,
 * for exposing parameters in sysfs (if non-zero) at a later stage.
 */

module_param(pid, int, 0);
MODULE_PARM_DESC(pid, "The pid of the process whose information we're printing\n");

module_init(pid_info);
module_exit(pid_info_exit);
