#include <mqueue.h>
#include <syscall.h>

int mq_timedsend(mqd_t mqdes, const char *msg_ptr, size_t msg_len,
		 unsigned msg_prio, const struct timespec *abstime)
{
	return syscall(mq_timedsend, mqdes, msg_ptr, msg_len, msg_prio,
		       abstime);
}
