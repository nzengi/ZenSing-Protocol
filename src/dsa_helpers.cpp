#include "dsa_helpers.h"
#include "math_helpers.h"

Parameters choose_parameters(int L, int N) {
    uint64_t q = rand_prime(N);
    uint64_t p;
    do {
        p = q * rand_int(L - N) + 1;
    } while (!prime_test(p, L));

    uint64_t g = 2;
    while (true) {
        g = pow(g, (p - 1) / q, p);
        if (pow(g, q, p) == 1) break;
    }

    return {L, N, p, q, g};
}

Keypair choose_keypair(const Parameters& parameters) {
    uint64_t x = rand_less_than(parameters.q, parameters.N);
    uint64_t y = pow(parameters.g, x, parameters.p);
    return {x, y, parameters};
}
