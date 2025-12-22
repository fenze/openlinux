#include <mqueue.h>
#include <syscall.h>

int mq_setattr(mqd_t mqdes, const struct mq_attr *restrict mqstat,
	       struct mq_attr *restrict omqstat)
{
	return syscall(mq_getsetattr, mqdes, mqstat, omqstat);
}
