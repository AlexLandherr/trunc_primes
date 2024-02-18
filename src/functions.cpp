#include "include/functions.h"
#include <cmath>
#include <numeric>
#include <algorithm>
#include <stdexcept>
#include <cstdint>
#include <string>

/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously
remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7.
Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

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

        for (unsigned int j = 1; j < prime_str.length(); j++) {
            if (!func::is_prime(std::stoll(prime_str.substr(j)))) {
                left_to_right = false;
            }
        }

        for (unsigned int i = 1; i < prime_str.length(); i++) {
            if (!func::is_prime(std::stoll(prime_str.substr(0, (prime_str.length() - i))))) {
                right_to_left = false;
            }
        }

        return (left_to_right && right_to_left);
    }
}