#include <stdio.h>

#include "counter.h"

/*
gcc example.c counter.c -o morriscounter
*/

int main(void) {
    config_t conf;
    counter_t cntr;

    init_config(&conf, 30);
    init_counter(&cntr, &conf);

    for (int i = 0; i < 10000; i++) {
        increment(&cntr);
        if (i < 10) {
            printf("Count %d: %hu\n", i + 1, approximate(&cntr));
        }
    }
    // print after 1000 incrementations
    printf("...\nCount 10000: %hu\n", approximate(&cntr));
    printf("Expected Error on 10000: %hu\n", expected_error_on_count(&cntr, 10000));

    return 0;
}
