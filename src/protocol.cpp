#include "protocol.h"
#include "hash_helpers.h"
#include "math_helpers.h"

Signer::Signer(const Parameters& params) : parameters(params), keypair(choose_keypair(params)) {}

void Signer::start(const std::vector<uint8_t>& info) {
    z = full_domain_hash(info, parameters.L);
}

std::pair<uint64_t, uint64_t> Signer::one() {
    u = rand_less_than(parameters.q, parameters.N);
    s = rand_less_than(parameters.q, parameters.N);
    d = rand_less_than(parameters.q, parameters.N);
    a = pow(parameters.g, u, parameters.p);
    b = (pow(parameters.g, s, parameters.p) * pow(z, d, parameters.p)) % parameters.p;
    return {a, b};
}

std::tuple<uint64_t, uint64_t, uint64_t, uint64_t> Signer::three(uint64_t e) {
    c = (e - d) % parameters.q;
    r = (u - c * keypair.x) % parameters.q;
    return {r, c, s, d};
}

User::User(const Parameters& params, uint64_t pubkey) : parameters(params), y(pubkey) {}

void User::start(const std::vector<uint8_t>& info, const std::vector<uint8_t>& msg) {
    z = full_domain_hash(info, parameters.L);
    this->msg = msg;
    t1 = rand_less_than(parameters.q, parameters.N);
    t2 = rand_less_than(parameters.q, parameters.N);
    t3 = rand_less_than(parameters.q, parameters.N);
    t4 = rand_less_than(parameters.q, parameters.N);
}

uint64_t User::two(uint64_t a, uint64_t b) {
    uint64_t alpha = (a * pow(parameters.g, t1, parameters.p) * pow(y, t2, parameters.p)) % parameters.p;
    uint64_t beta = (b * pow(parameters.g, t3, parameters.p) * pow(z, t4, parameters.p)) % parameters.p;
    // Implement the hash and calculation of epsilon here
    return 0;  // Placeholder
}

std::tuple<uint64_t, uint64_t, uint64_t, uint64_t> User::four(uint64_t r, uint64_t c, uint64_t s, uint64_t d) {
    uint64_t rho = (r + t1) % parameters.q;
    uint64_t omega = (c + t2) % parameters.q;
    uint64_t delta = (s + t3) % parameters.q;
    uint64_t sigma = (d + t4) % parameters.q;
    return {rho, omega, delta, sigma};
}
