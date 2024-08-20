#ifndef CHECK_SIGNATURE_H
#define CHECK_SIGNATURE_H

#include <cstdint>
#include <vector>
#include "dsa_helpers.h"
#include "hash_helpers.h"

// The check function verifies if the signature is valid
// Parameters:
// - rho, omega, delta, sigma: Signature components
// - z: Hash of the information
// - msg: The original message
// - y: Public key of the signer
// - parameters: DSA parameters (p, q, g)
bool check(uint64_t rho, uint64_t omega, uint64_t delta, uint64_t sigma, uint64_t z, 
           const std::vector<uint8_t>& msg, uint64_t y, const Parameters& parameters) {
    // Convert the sum of omega and sigma modulo q to bytes
    std::vector<uint8_t> lhs = int_to_bytes((omega + sigma) % parameters.q);
    
    // Compute the right-hand side part of the equation
    uint64_t rhs_one = (pow(parameters.g, rho, parameters.p) * pow(y, omega, parameters.p)) % parameters.p;
    uint64_t rhs_two = (pow(parameters.g, delta, parameters.p) * pow(z, sigma, parameters.p)) % parameters.p;
    
    // Hash the right-hand side values along with the message and z
    std::vector<uint8_t> rhs_hash = full_domain_hash(int_to_bytes(rhs_one) + int_to_bytes(rhs_two) +
                                                     int_to_bytes(z) + msg, parameters.N);
    
    // Convert the hashed right-hand side value to bytes and compare it with lhs
    std::vector<uint8_t> rhs = int_to_bytes(int_from_bytes(rhs_hash) % parameters.q);
    return rhs == lhs;
}

#endif // CHECK_SIGNATURE_H
