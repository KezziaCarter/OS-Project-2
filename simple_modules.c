#include <linux/module.h>	  // Needed by all modules
#include <linux/kernel.h>	  // Needed for KERN_INFO
#include <linux/init.h>     // Needed for the macros
#include <asm/current.h>    // Process information
#include <linux/sched.h>    // For "struct task_struct"

#define DRIVER_AUTHOR "Alston, Cesa & Kezzia"
#define DRIVER_DESC "This module prints the pid, uid, gid, the parent process' pid and name, all children processes' pid and name and flag value set for a given process"

void pid_info(pid_t pid)
{
  struct task_struct *t_s_pointer;
  struct task_struct *child;
  struct task_struct *current;
  struct task_struct *ch_t;

  t_s_pointer = pid_task(find_vpid(pid), PIDTYPE_PID);
  child = t_s_pointer;

  printk(KERN_INFO "PID of process: %i\n", t_s_pointer->pid);
  printk(KERN_INFO "UID: %i\n", (t_s_pointer->cred)->uid.val);
  printk(KERN_INFO "GID: %i\n", (t_s_pointer->cred)->gid.val);
  printk(KERN_INFO "Parent process: %i\n", t_s_pointer->parent->comm);
  printk(KERN_INFO "Parent PID: %i\n", (t_s_pointer->cred)->uid.val);
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
