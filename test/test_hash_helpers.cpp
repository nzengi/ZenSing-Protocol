#include <iostream>
#include <vector>
#include "hash_helpers.h"

int main() {
    std::vector<uint8_t> data = {'t', 'e', 's', 't'};
    auto hash = sha256(data);

    std::cout << "SHA-256 Hash: ";
    for (uint8_t byte : hash) {
        std::cout << std::hex << (int)byte;
    }
    std::cout << std::endl;

    uint64_t fdh_result = full_domain_hash(data, 256);
    std::cout << "Full Domain Hash result: " << fdh_result << std::endl;

    return 0;
}
