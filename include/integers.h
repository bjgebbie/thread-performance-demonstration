#ifndef INTEGERS_H
#define INTEGERS_H
#include <stdint.h>
#include <sys/types.h>

typedef struct {
	uint8_t *values;
	uint32_t size;
} Integers;
#endif
