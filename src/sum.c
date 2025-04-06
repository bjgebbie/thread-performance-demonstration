#include <pthread.h>

void *sum() {
	const int retval = 1;

	pthread_exit((void *)&retval);
}
