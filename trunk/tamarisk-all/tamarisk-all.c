/*
 * tamarisk is a Linux kernel module for listing processes
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE
 */

/*
 * File: tamarisk-all.c
 * Author: Islam Faisal
 */

//Some #defines
 #define COOL_AUTHOR "Islam Faisal <islamfm@aucegypt.edu>"
 #define COOL_DESC   "a Linux kernel module for listing all processes"


//Some #includes
#include <linux/module.h>
#include <linux/printk.h>
#include <linux/sched.h>

static int __init listall_init(void)
{
    //Print some message
    pr_info("tamarisk-all module is initializing..\n");

    struct task_struct *task;
    pr_info("pid \t\t pname \t\t state\n");
    for_each_process(task)
          #include "../includes/printer.h"

    return 0;
}

static void __exit listall_vanish(void)
{
    pr_info("tamarisk-all module is vanishing..\n");
}



 MODULE_AUTHOR(COOL_AUTHOR);
 MODULE_DESCRIPTION(COOL_DESC);
 module_init(listall_init);
 module_exit(listall_vanish);
 MODULE_LICENSE("GPL");
