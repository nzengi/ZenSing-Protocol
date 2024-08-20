#include <iostream>
#include "dsa_helpers.h"

int main() {
    int L = 1024, N = 160;
    Parameters params = choose_parameters(L, N);

    std::cout << "p: " << params.p << std::endl;
    std::cout << "q: " << params.q << std::endl;
    std::cout << "g: " << params.g << std::endl;

    Keypair keypair = choose_keypair(params);
    std::cout << "Private key: " << keypair.x << std::endl;
    std::cout << "Public key: " << keypair.y << std::endl;

    return 0;
}
