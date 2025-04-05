#include "constants/constants.h"
#include "threads/threads.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	pthread_t thread_ids[NUMBER_OF_THREADS];
	pthread_t *something = create_threads(thread_ids);

	printf("Main thread: New thread has finished execution.\n");

	return 0;
}
