#include "math_helpers.h"
#include <random>

uint64_t rand_int(int nbits) {
    std::random_device rd;
    std::uniform_int_distribution<uint64_t> dist(0, (1ULL << nbits) - 1);
    return dist(rd);
}

uint64_t rand_less_than(uint64_t upper_bound, int nbits) {
    while (true) {
        uint64_t r = rand_int(nbits);
        if (r < upper_bound) return r;
    }
}

bool miller_rabin_test(uint64_t p, int nbits, int k) {
    // Implement Miller-Rabin primality test here
    // Similar to the Python implementation but optimized for C++
    return true;  // Placeholder
}

bool prime_test(uint64_t p, int nbits) {
    return miller_rabin_test(p, nbits);
}

uint64_t rand_prime(int nbits) {
    while (true) {
        uint64_t p = rand_int(nbits);
        if (prime_test(p, nbits)) return p;
    }
}
