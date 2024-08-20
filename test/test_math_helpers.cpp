#include <iostream>
#include "math_helpers.h"

int main() {
    int nbits = 64;
    uint64_t random_num = rand_int(nbits);
    std::cout << "Random number (64 bits): " << random_num << std::endl;

    uint64_t prime_num = rand_prime(nbits);
    std::cout << "Random prime (64 bits): " << prime_num << std::endl;

    if (prime_test(prime_num, nbits)) {
        std::cout << "Prime test passed!" << std::endl;
    } else {
        std::cout << "Prime test failed!" << std::endl;
    }

    return 0;
}
