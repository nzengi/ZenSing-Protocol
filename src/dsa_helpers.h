#ifndef DSA_HELPERS_H
#define DSA_HELPERS_H

#include <cstdint>

struct Parameters {
    int L;
    int N;
    uint64_t p;
    uint64_t q;
    uint64_t g;
};

struct Keypair {
    uint64_t x;
    uint64_t y;
    Parameters parameters;
};

Parameters choose_parameters(int L, int N);
Keypair choose_keypair(const Parameters& parameters);

#endif // DSA_HELPERS_H
