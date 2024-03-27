#include "include/functions.h"
#include <iostream>
#include <cstdint>
#include <stdexcept>

/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously
remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7.
Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

int main() {
    /* int64_t test_prime = 3797;
    std::cout << "Is " << test_prime << " a truncateable prime?: " << std::boolalpha << func::is_truncateable_prime(test_prime) << '\n'; */
    try {
        std::cout << "The sum of the only eleven primes that are both truncatable from left to right and right to left is:" << '\n';
        std::cout << func::get_answer() << '\n';
    } catch (const std::invalid_argument& ex) {
        std::cerr << ex.what() << '\n';
    } catch (const std::exception& ex) {
        std::cerr << ex.what() << '\n';
    }

    return 0;
}