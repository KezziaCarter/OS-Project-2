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
  struct task_struct *t_s_pointer; /* The target process' task struct */
  struct task_struct *child; /* A child */
  struct list_head list; /* A nice list to hold current node's children */
  t_s_pointer = pid_task(find_vpid(pid), PIDTYPE_PID); /* finds the right task by process pid */

  /* Printing values from the task struct */
  printk(KERN_INFO "PID of process: %i\n", t_s_pointer->pid);
  printk(KERN_INFO "UID: %i\n", (t_s_pointer->cred)->uid.val);
  printk(KERN_INFO "GID: %i\n", (t_s_pointer->cred)->gid.val);
  printk(KERN_INFO "Parent process: %i\n", t_s_pointer->parent->comm);
  printk(KERN_INFO "Parent PID: %i\n", (t_s_pointer->parent)->pid);

  /* Get list of children of our task */
  list = t_s_pointer->children
  child = list_entry(&list, struct task_struct, children);
  printk(KERN_INFO "CHILDREN:\n");
  printk(KERN_INFO "Child process: %i\n", child->comm);
  printk(KERN_INFO "Child PID: %i\n", child->pid);

  printk(KERN_INFO "FLAGS:%i\n", t_s_pointer->flags);
  pid_vminfo()
}


void pid_vminfo(void)
{
  printk(KERN_INFO "pid_vminfo()\n");
  int var = 0;
  struct vm_area_struct *virtual;
  struct proc_dir_entry *proc;

  proc = proc_create("simple_modules_proc", 0644, NULL, &proc_file_fops);
  printk(KERN_INFO "Number of Virtual Memory Addresses is  %i/n", current->mm->map_count );
  printk(KERN_INFO "Task struct maps: \n");
  for(virtual = current->mm->mmap; virtual; virtual = virtual->vm_next)
  {
    var = var + 1;
    printk("\n Virtual Mem address %d:", var );
    printk(KERN_INFO "Starts at address 0x%lx\n", virtual->vm_start);
    printk(KERN_INFO "Ends at at address 0x%lx\n", virtual->vm_end);
    printk(KERN_INFO "Has an offset of: %lu\n", virtual->vm_pgoff );
    printk(KERN_INFO "Has the following flags: %lu\n", virtual->vm_flags );
  }

}


static int pid_info_begin(void)
{
  pid_t pid;
  pid = task_pid_nr(current); /* Get PID of current task */
  pid_info(pid); /* Pass that PID into pid_info */

  printk(KERN_INFO "Hello, world\n");
  return 0; /* Return 0 so we know it worked. */
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
