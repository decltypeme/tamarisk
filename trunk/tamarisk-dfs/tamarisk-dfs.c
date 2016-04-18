/*
 * semsem is a Linux kernel module for listing processes
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

void dfs(struct task_struct *inTask)
{
  struct task_struct *task;
  struct list_head *list;

  pr_info("[%d]\t\t%s\t\t%ld\n", inTask->pid, inTask->comm, inTask->state);

  list_for_each(list, &inTask->children) {
    task = list_entry(list, struct task_struct, sibling);
    dfs(task);
}
}

static int __init listdfs_init(void)
{
    //Print some message
    pr_info("tamarisk-dfs module is initializing..\n");
    pr_info("pid \t\t pname \t\t state\n");
    dfs(&init_task);

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
