#include <mqueue.h>
#include <signal.h>
#include <syscall.h>

int mq_notify(mqd_t mqdes, const struct sigevent *notification)
{
	if (notification == NULL ||
	    notification->sigev_notify != SIGEV_THREAD) {
		return syscall(mq_notify, mqdes, notification);
	}

	// TODO: implement SIGEV_THREAD notification
	errno = ENOSYS;
	return -1;
}
