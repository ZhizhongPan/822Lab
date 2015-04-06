#include <linux/linkage.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/wait.h>
#include <linux/sched.h>

DECLARE_WAIT_QUEUE_HEAD(gone);

SYSCALL_DEFINE0(deepsleep){
	set_current_state(TASK_UNINTERRUPTIBLE);
	schedule();
	return 0;
}