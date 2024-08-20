#ifndef HASH_HELPERS_H
#define HASH_HELPERS_H

#include <vector>
#include <cstdint>

std::vector<uint8_t> sha256(const std::vector<uint8_t>& data);
uint64_t full_domain_hash(const std::vector<uint8_t>& data, int target_length);

#endif // HASH_HELPERS_H
