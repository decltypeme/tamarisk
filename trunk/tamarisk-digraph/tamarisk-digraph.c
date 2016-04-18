/*
 * semsem is a Linux kernel module for listing processes
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE
 */

/*
 * File: tamarisk-digraph.c
 * Author: Islam Faisal
 */

//Some #defines
 #define COOL_AUTHOR "Islam Faisal <islamfm@aucegypt.edu>"
 #define COOL_DESC   "a Linux kernel module for listing all processes in a dot graph"

 //Some #includes
 #include <linux/module.h>
 #include <linux/printk.h>
 #include <linux/sched.h>
 #include <linux/init.h>
#include <linux/kernel.h>

 static int __init listdigraph_init(void)
 {
     printk("digraph processes {\n");
     struct task_struct *child_task;
          struct task_struct *task;
       struct list_head *list;
     for_each_process(task){
         list_for_each(list, &task->children) {
           child_task = list_entry(list, struct task_struct, sibling);
                  printk("%d -> %d;\n", task->pid, child_task->pid);
       }
     }
     printk("}\n");
     return 0;
 }

 static void __exit listdigraph_vanish(void)
 {

 }



 MODULE_AUTHOR(COOL_AUTHOR);
 MODULE_DESCRIPTION(COOL_DESC);
 module_init(listdigraph_init);
 module_exit(listdigraph_vanish);
 MODULE_LICENSE("GPL");
