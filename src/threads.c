#include "constants.h"
#include "sum.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>

void create_threads(pthread_t *thread_ids, void *thread_function,
					void *thread_function_arg) {
	for (int i = 0; i < NUMBER_OF_THREADS; i++) {
		pthread_t thread_id;

		if (0 != pthread_create(&thread_id, NULL, thread_function,
								thread_function_arg)) {
			perror("Failed to create thread");
		}

		thread_ids[i] = thread_id;
	}
}

void join_threads(pthread_t *thread_ids, void **ret_vals) {
	for (int i = 0; i < NUMBER_OF_THREADS; i++) {
		if (pthread_join(thread_ids[i], &ret_vals[i]) != 0) {
			perror("Failed to join thread");
		}
	}
}
