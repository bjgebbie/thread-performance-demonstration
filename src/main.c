#include "constants.h"
#include "integers.h"
#include "populate.h"
#include "sum.h"
#include "threads.h"
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

int main() {
	const uint32_t size = 100000000;
	// This needs to be dynamic because other wize we hit stack overflow.
	uint8_t *values = (uint8_t *)malloc(sizeof(uint8_t) * size);
	Integers ints;
	ints.values = values;
	ints.size = size;

	populate(&ints);

	pthread_t thread_ids[NUMBER_OF_THREADS];
	create_threads(thread_ids, sum, (void *)&ints);

	void *ret_vals[NUMBER_OF_THREADS];
	join_threads(thread_ids, ret_vals);
	uint64_t *ret_val = (uint64_t *)ret_vals[NUMBER_OF_THREADS - 1];
	printf("Sum is: %lu\n", *ret_val);

	free(values);
	return 0;
}
