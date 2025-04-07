#include "constants.h"

#include "integers.h"
#include "populate.h"
#include "sum.h"
#include "threads.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	uint64_t size = 100;
	uint64_t *integers = (uint64_t *)malloc(size * sizeof(uint64_t));
	populate(integers, size);

	Integers ints = {integers, size};

	void *ret_vals[NUMBER_OF_THREADS];
	pthread_t thread_ids[NUMBER_OF_THREADS];
	create_threads(thread_ids, sum, (void *)&ints);
	join_threads(thread_ids, ret_vals);
	uint64_t *ret_val = (uint64_t *)ret_vals[NUMBER_OF_THREADS - 1];
	printf("Sum is: %lu\n", *ret_val);

	free(integers);

	printf("Main thread: New thread has finished execution.\n");

	return 0;
}
