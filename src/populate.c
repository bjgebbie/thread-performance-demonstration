#include "integers.h"
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

void populate(Integers *ints) {
	srand(time(NULL));
	uint8_t max_int = 10;

	for (uint32_t i = 0; i < ints->size; i++) {
		uint8_t r = rand() % (max_int + 1);
		ints->values[i] = r;
	}
}
