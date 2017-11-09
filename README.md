# OS-Project-2
CSCI 401 Operating Systems Instructor: Gedare Bloom Project 2 (100 points)
Team Members:
- Alston 
- Cesa
- Kezzia

For project 2, we were required to create two informative kernel modules.

Module 1: The pid_info module.
  "You will write a simple kernel module called pid_info. The module should cleanly load and unload an unlimited number of times. The module should take a parameter of the pid of a specific process. When loaded, the module will lookup the process task_struct of the specified process and print out, using the printk() function, the following information nicely formatted.
 - pid
 - uid, gid of process
 - parent process id and name
 - all of the children processes pid and name
 - any flags that are set. Make sure to translate them to readable names.
You can find the struct task_struct defined in the file linux/sched.h The LKD chapters on processes, modules and appendix A on linked lists can be helpful. There is also an example of a module and Makefile already available on the virtual machine, located at ${HOME}/osc9e-src/ch2/.
The c source file with your module should have two global variables (pid parameter and module name) and only two functions (the module init and cleanup). Use the MODULE_ macros (linux/module.h) to document the license (GPL), author, and description of your module. Your makefile should have a default target to build your modules and a clean target to remove all compiled files. Your modules should have the exact name given in the assignment."

Module 2: The pid_vminfo module.
  Now you will write a module called pid_vminfo that creates a /proc entry file that when read, prints out the virtual memory     state of a process. The virtual memory state of the process can be found by looking at the mm field of the task struct you used in the first module. You should print out at least enough information to identify the process (pid, name, ...) and all of the vm_area structs that are listed in the mmap list. Additional information that is displayed in a useful format will be a bonus.
  The module should print out the state of whatever process is running when its proc file is read. So it does not need to lookup a pid like the first module. Creating and destroying /proc entries is easy; you can do it with a single function call. Documentation on how can be found on page 11-14 of Chapter 4 Debugging of the Linux Device Drivers 3rd Edition available online.
  
 Project Challenges:
    Some of the main challenges faced during the duration of this project were:
      - Time Management
      - Downloading the VM (Working with Howard University was a challenge) and complete the system administration changes.
      
 Running the Project:
  Once the code as been downloaded successfully, navigate to the directory the project is in. Once there, execute run insmod simple_modules.ko and then unload rmmod simple_modules


