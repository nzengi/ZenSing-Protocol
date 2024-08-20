#ifndef MATH_HELPERS_H
#define MATH_HELPERS_H

#include <cstdint>

uint64_t rand_int(int nbits);
uint64_t rand_less_than(uint64_t upper_bound, int nbits);
bool miller_rabin_test(uint64_t p, int nbits, int k = 5);
bool prime_test(uint64_t p, int nbits);
uint64_t rand_prime(int nbits);

#endif // MATH_HELPERS_H
