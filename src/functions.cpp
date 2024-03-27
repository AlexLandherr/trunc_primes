#include "include/functions.h"
#include <cmath>
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <cstdint>
#include <string>
#include <vector>

namespace func {
    bool is_prime(int64_t n) {
        //Checks if a single signed 64-bit integer is a prime number.
        if (n > std::numeric_limits<int64_t>::max() || n < std::numeric_limits<int64_t>::min()) {
            throw std::invalid_argument("Argument 'n' is out of range for 'int64_t' type.");
        }
        if (n <= 1) {
            return false;
        } else if (n == 2) {
            return true;
        } else if (n > 2 && n % 2 == 0) {
            return false;
        }

        int64_t max_divisor = std::ceil(std::sqrt((long double) n));
        for (int64_t d = 3; d < max_divisor + 1; d+=2) {
            if (n % d == 0) {
                return false;
            }
        }

        return true;
    }

    bool is_truncateable_prime(int64_t prime) {
        std::string prime_str = std::to_string(prime);
        bool left_to_right = true;
        bool right_to_left = true;

        //Left to right loop.
        for (unsigned long i = 1; i < prime_str.length(); i++) {
            if (!func::is_prime(std::stoll(prime_str.substr(i)))) {
                left_to_right = false;
            }
        }

        //Right to left loop.
        for (unsigned long j = 1; j < prime_str.length(); j++) {
            if (!is_prime(std::stoll(prime_str.substr(0, (prime_str.length() - j))))) {
                right_to_left = false;
            }
        }

        return (left_to_right && right_to_left);
    }

    bool contains_only(std::string &allowed, std::string str) {
        return str.find_first_not_of(allowed) != std::string::npos;
    }

    int64_t get_answer() {
        std::string allowed_chars = "024568";
        std::vector<int64_t> truncateable_primes;
        int64_t counter = 0;
        int64_t i = 11;
        while (counter < 11) {
            if (contains_only(allowed_chars, std::to_string(i))) {
                if (is_prime(i)) {
                    if (is_truncateable_prime(i)) {
                        truncateable_primes.push_back(i);
                        counter++;
                    }
                }
            }
            i += 2;
        }

        return std::reduce(truncateable_primes.begin(), truncateable_primes.end());
    }
}