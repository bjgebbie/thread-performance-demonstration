#include "constants.h"
#include "sum.h"
#include "threads.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void populate(int *integers, int size) {
	srand(time(NULL));
	int max_int = 10;

	for (int i = 0; i < size; i++) {
		int r = rand() % (max_int + 1);
		integers[i] = r;

		printf("%d\n", r);
	}
}

int main() {
	int size = 10;

	int integers[size];
	populate(integers, size);

	pthread_t thread_ids[NUMBER_OF_THREADS];

	create_threads(thread_ids, sum);
	join_threads(thread_ids);

	printf("Main thread: New thread has finished execution.\n");

	return 0;
}
