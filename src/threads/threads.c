#include "../constants/constants.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

void *thread_function(void *arg) {
	const int retval = 1;

	pthread_exit((void *)&retval);
}

void create_threads(pthread_t *thread_ids) {
	for (int i = 0; i < NUMBER_OF_THREADS; i++) {
		pthread_t thread_id;

		if (0 != pthread_create(&thread_id, NULL, thread_function, NULL)) {
			perror("Failed to create thread");
		}

		thread_ids[i] = thread_id;
	}
}

void join_threads(pthread_t *thread_ids) {
	int thread_function_return_values[NUMBER_OF_THREADS];

	for (int i = 0; i < NUMBER_OF_THREADS; i++) {
		if (pthread_join(thread_ids[i], NULL) != 0) {
			perror("Failed to join thread");
		}
	}
}
