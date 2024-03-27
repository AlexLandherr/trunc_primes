#include <cstdint>
#include <string>
#include <vector>

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

namespace func {
    bool is_prime(int64_t n);
    bool is_truncateable_prime(int64_t prime);
    bool contains_only(std::string &allowed, std::string str);
    int64_t get_answer();
}

#endif