#include "counter.h"

#include <math.h>
#include <stdlib.h>

double gen_rand() {
    return (double)rand() / (double)RAND_MAX;
}

bool init_config(config_t * c, uint8_t a) {
    if (c == NULL) return false;
    c->a = a;
    c->precompute = (double *) malloc(sizeof(double) * (UINT8_MAX + 1));
    if (c->precompute == NULL) return false;
    // precompute (a/(a+1))^j j=[0, 255]
    for (int i = 0; i < UINT8_MAX + 1; i++) {
        c->precompute[i] = pow(1.0 * a / (a + 1), i);
    }
    return true;
}

bool init_counter(counter_t * c, config_t * conf) {
    if (c == NULL || conf == NULL) return false;
    c->internal = 0;
    c->conf = conf;
    return true;
}

void increment(counter_t * c) {
    double r = gen_rand();
    double d = c->conf->precompute[c->internal];
    if (d > r) {
        c->internal += 1;
    }
}

uint16_t approximate(counter_t * c) {
    return (uint16_t) c->conf->a * (1 / c->conf->precompute[c->internal] - 1);
}

uint16_t expected_error_on_count(counter_t * c, uint16_t i) {
    return (uint16_t) pow((i * (i - 1)) / (2 * c->conf->a), 0.5);
}
