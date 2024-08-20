#ifndef PROTOCOL_H
#define PROTOCOL_H

#include "dsa_helpers.h"

class Signer {
public:
    Signer(const Parameters& params);
    void start(const std::vector<uint8_t>& info);
    std::pair<uint64_t, uint64_t> one();
    std::tuple<uint64_t, uint64_t, uint64_t, uint64_t> three(uint64_t e);

private:
    Parameters parameters;
    Keypair keypair;
    uint64_t z;
    uint64_t u, s, d, a, b, c, r;
};

class User {
public:
    User(const Parameters& params, uint64_t pubkey);
    void start(const std::vector<uint8_t>& info, const std::vector<uint8_t>& msg);
    uint64_t two(uint64_t a, uint64_t b);
    std::tuple<uint64_t, uint64_t, uint64_t, uint64_t> four(uint64_t r, uint64_t c, uint64_t s, uint64_t d);

private:
    Parameters parameters;
    uint64_t y;
    uint64_t z;
    uint64_t t1, t2, t3, t4;
    std::vector<uint8_t> msg;
};

#endif // PROTOCOL_H
