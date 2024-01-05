#ifndef MORRIS_COUNTER
#define MORRIS_COUNTER

#include <stdint.h>
#include <stdbool.h>

// from the paper:
// https://www.inf.ed.ac.uk/teaching/courses/exc/reading/morris.pdf 

typedef struct {
    uint8_t a;
    double * precompute;
} config_t;

typedef struct {
    uint8_t internal;
    config_t * conf;
} counter_t;

bool init_config(config_t * c, uint8_t a);

bool init_counter(counter_t * c, config_t * conf);

void increment(counter_t * c);

uint16_t approximate(counter_t * c);

uint16_t expected_error_on_count(counter_t * c, uint16_t i);

#endif
