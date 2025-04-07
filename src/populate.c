#include <stdint.h>
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
