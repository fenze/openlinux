#include <mqueue.h>
#include <stddef.h>
#include <syscall.h>
#include <time.h>

ssize_t mq_timedreceive(mqd_t mqdes, char *restrict msg_ptr, size_t msg_len, unsigned *restrict msg_prio,
			const struct timespec *restrict abstime)
{
	return syscall(mq_timedreceive, mqdes, msg_ptr, msg_len, msg_prio, abstime);
}
