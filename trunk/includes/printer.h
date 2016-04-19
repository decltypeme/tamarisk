/*
 * tamarisk is a Linux kernel module for listing processes
 * Written by: Islam Faisal (decltypeme)
 * The American University in Cairo
 * For License, please see LICENSE
 */

/*
 * File: printer.h
 * Author: Islam Faisal
 */

 /*
THIS IS NOT AN EVERY DAY HEADER. THIS IS A CODE SNIPPET. ONLY INCLUDE WHEN USING IT.
 */

//THE TASK MUST, again  MUST, be named TASK.
//THIS IS NOT A NEAT WAY I KNOW TO WRITE CODE, BUT I JUST WANTED TO DO IT QUICKLY. SORRY FOR HOLDING ON TO THE CAPS LOCK> IT IS ACTUALLY  ENJOYABLE.


#define STATE_STRING


#ifndef STATE_STRING
pr_info("[%d]\t\t%s\t\t%ld\n", task->pid, task->comm, task->state);
#endif

#ifdef STATE_STRING
{
long int state_no = task->state;
if(state_no == TASK_RUNNING)
    pr_info("[%d]\t\t%s\t\tTASK RUNNING\n", task->pid, task->comm);
else if(state_no == TASK_INTERRUPTIBLE)
        pr_info("[%d]\t\t%s\t\tTASK INTERRUPTIBLE\n", task->pid, task->comm);
else if(state_no == TASK_UNINTERRUPTIBLE)
        pr_info("[%d]\t\t%s\t\tTASK UNINTERRUPTIBLE\n", task->pid, task->comm);
else if(state_no == 8)
        pr_info("[%d]\t\t%s\t\tTASK ZOMBIE\n", task->pid, task->comm);
else if(state_no == TASK_STOPPED)
        pr_info("[%d]\t\t%s\t\tTASK STOPPED\n", task->pid, task->comm);
else
    pr_info("[%d]\t\t%s\t\tWEIRDP\n", task->pid, task->comm);
}
#endif
