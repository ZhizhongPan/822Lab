#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/sched.h>
#include <linux/signal.h>
#include <linux/pid_namespace.h>

SYSCALL_DEFINE2(smunch, int, pid, unsigned long, bit_pattern){
	struct task_struct *task;
	unsigned long flags;

	task = pid_task(find_vpid(pid), PIDTYPE_PID);
	if (task == NULL) {
        printk(KERN_ALERT "Cannot Find PID !\r\n");
        return -1;
    }
	
	if (thread_group_empty(task) == 0){
		printk(KERN_ALERT "Multi-thread Process!\r\n");
		return -1;
	}

	if(!lock_task_sighand(task, &flags)){
		printk(KERN_ALERT "Lock Task Failed!\r\n");
		return -1;
	}

	if (task->exit_state == EXIT_ZOMBIE || task->exit_state == EXIT_DEAD){
		if  (bit_pattern & sigmask(SIGKILL)){
			printk(KERN_ALERT "SIGKILL is set , Process is ZOMBIE or DEAD!\r\n");
			unlock_task_sighand(task, &flags);
			release_task(task);
			return 0;
		}

		printk(KERN_ALERT "SIGKILL is NOT set , Process is ZOMBIE or DEAD!\r\n");
		unlock_task_sighand(task, &flags);
		return 0;
	}
	
	sigaddsetmask(&(task->signal->shared_pending.signal), bit_pattern);
	wake_up_process(task);
	unlock_task_sighand(task, &flags);
	return 0;

}
