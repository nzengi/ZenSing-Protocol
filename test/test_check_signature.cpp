#include <iostream>
#include "check_signature.h"

int main() {
    int L = 1024, N = 160;
    Parameters params = choose_parameters(L, N);

    Signer signer(params);
    User user(params, signer.keypair.y);

    std::vector<uint8_t> info = {'i', 'n', 'f', 'o'};
    std::vector<uint8_t> msg = {'m', 'y', ' ', 'm', 's', 'g'};

    signer.start(info);
    user.start(info, msg);

    auto [a, b] = signer.one();
    uint64_t e = user.two(a, b);
    auto [r, c, s, d] = signer.three(e);
    auto [rho, omega, delta, sigma] = user.four(r, c, s, d);

    bool valid = check(rho, omega, delta, sigma, user.z, msg, user.y, params);
    if (valid) {
        std::cout << "Signature is valid!" << std::endl;
    } else {
        std::cout << "Signature is invalid!" << std::endl;
    }

    return 0;
}
