#include <mqueue.h>
#include <syscall.h>

int mq_getattr(mqd_t mqdes, struct mq_attr *mqstat)
{
	return mq_setattr(mqdes, 0, mqstat);
}
