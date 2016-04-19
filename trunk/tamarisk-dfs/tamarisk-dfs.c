/*
 * tamarisk is a Linux kernel module for listing processes
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE
 */

/*
 * File: tamarisk-dfs.c
 * Author: Islam Faisal
 */

//Some #defines
 #define COOL_AUTHOR "Islam Faisal <islamfm@aucegypt.edu>"
 #define COOL_DESC   "a Linux kernel module for listing all processes in DFS manner"


//Some #includes
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/sched.h>
#include <linux/init.h>

void dfs_tasks(struct task_struct *task)
{
  struct task_struct *tast_ptr;
  struct list_head *list;

  #include "../includes/printer.h"

  list_for_each(list, &task->children) {
    tast_ptr = list_entry(list, struct task_struct, sibling);
    dfs_tasks(tast_ptr);
}
}

static int __init listdfs_init(void)
{
    //Print some message
    pr_info("tamarisk-dfs module is initializing..\n");
    pr_info("pid \t\t pname \t\t state\n");
    dfs_tasks(&init_task);

    return 0;
}

static void __exit listdfs_vanish(void)
{
    pr_info("tamarisk-dfs module is vanishing..\n");
}



 MODULE_AUTHOR(COOL_AUTHOR);
 MODULE_DESCRIPTION(COOL_DESC);
 module_init(listdfs_init);
 module_exit(listdfs_vanish);
 MODULE_LICENSE("GPL");
