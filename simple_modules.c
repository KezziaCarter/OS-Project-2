#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/pid.h>
#include <linux/proc_fs.h>
#include <linux/moduleparam.h>
#include <asm/current.h>
#include <linux/sched.h>
#include <asm/uaccess.h>
#include <asm/io.h>
#include <linux/seq_file.h>
#include <linux/fs.h>
#include <linux/mm.h>

#define DRIVER_AUTHOR "Alston, Cesa & Kezzia"
#define DRIVER_DESC "This module prints the pid, uid, gid, the parent process' pid and name, all children processes' pid and name and flag value set for a given process"

void pid_info(pid_t pid)
{
  struct task_struct *t_s_pointer;
  struct task_struct *child;
  struct task_struct *current;
  struct task_struct *ch_t;
  struct list_head list;
  t_s_pointer = pid_task(find_vpid(pid), PIDTYPE_PID);
  child = t_s_pointer;

  printk(KERN_INFO "PID of process: %i\n", t_s_pointer->pid);
  printk(KERN_INFO "UID: %i\n", (t_s_pointer->cred)->uid.val);
  printk(KERN_INFO "GID: %i\n", (t_s_pointer->cred)->gid.val);
  printk(KERN_INFO "Parent process: %i\n", t_s_pointer->parent->comm);
  printk(KERN_INFO "Parent PID: %i\n", (t_s_pointer->cred)->uid.val);

  current = t_s_pointer;
  list = current->children
  ch_t = list_entry(&list, struct task_struct, children);
  printk(KERN_INFO "CHILDREN:\n");
  printk(KERN_INFO "Child process: %i\n", ch_t->comm);
  printk(KERN_INFO "Child PID: %i\n", curr->pid);

  printk(KERN_INFO "FLAGS:%i\n", t_s_pointer->flags);
  pid_vminfo();
}


static int pid_info_begin(void)
{
  pid_t pid;
  pid = task_pid_nr(current);
  pid_info(pid);

  printk(KERN_INFO "Hello, world\n");
  return 0;
}


static void pid_info_exit(void)
{
  printk(KERN_INFO "Goodbye, world\n");
}


MODULE_LICENSE("GPL");

module_init(pid_info_begin);
module_exit(pid_info_exit);

MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DRIVER_DESC);
