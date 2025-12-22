#include <mqueue.h>
#include <syscall.h>

int mq_close(mqd_t mqdes)
{
	return syscall(close, mqdes);
}
