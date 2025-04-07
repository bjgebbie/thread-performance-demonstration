#include "constants.h"
#include "integers.h"
#include "sum.h"
#include "threads.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate(uint64_t *integers, uint32_t size) {
	srand(time(NULL));
	uint8_t max_int = 10;

	for (uint32_t i = 0; i < size; i++) {
		uint8_t r = rand() % (max_int + 1);
		integers[i] = r;
	}
}

int main() {
	uint64_t size = 100;
	uint64_t *integers = (uint64_t *)malloc(size * sizeof(uint64_t));
	populate(integers, size);

	Integers ints = {integers, size};

	void *ret_vals[NUMBER_OF_THREADS];
	pthread_t thread_ids[NUMBER_OF_THREADS];
	create_threads(thread_ids, sum, (void *)&ints);
	join_threads(thread_ids, ret_vals);
	for (uint8_t i = 0; i < NUMBER_OF_THREADS; i++) {
		uint64_t *ret_val = (uint64_t *)ret_vals[i];
		printf("Sum is: %lu\n", *ret_val);
	}

	free(integers);

	printf("Main thread: New thread has finished execution.\n");

	return 0;
}
