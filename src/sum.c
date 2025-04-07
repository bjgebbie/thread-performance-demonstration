#include "integers.h"
#include <pthread.h>
#include <stdint.h>
#include <stdlib.h>

void *sum(void *arg) {
	Integers *ints = (Integers *)arg;
	uint64_t *sum = malloc(sizeof(uint64_t));
	*sum = 0;
	for (int i = 0; i < ints->size; i++) {
		*sum += ints->values[i];
	}
	pthread_exit(sum);
}
