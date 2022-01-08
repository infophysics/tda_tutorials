/**
 * @file Utilities.hh
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include <cmath>
#include <iostream>
#include <string>

namespace ripser
{
    /// number of bits to use for a single coefficient
    static const size_t NUM_COEFFICIENT_BITS = 8;
    /// the maximum simplex index used
    static const int64_t MAX_SIMPLEX_INDEX = 
        (1l << (8 * sizeof(int64_t) - 1 - NUM_COEFFICIENT_BITS)) - 1;

    /// function to check if an index is greater than max simplex index
    /// or is less than zero.
    void check_overflow(int64_t i)
    {
        if
#ifdef USE_COEFFICIENTS
            (i > MAX_SIMPLEX_INDEX)
#else
            (i < 0)
#endif
            throw std::overflow_error("simplex index " + std::to_string((uint64_t)i) +
                " in filtration is larger than maximum index " +
                std::to_string(MAX_SIMPLEX_INDEX));
    }

    /// check if a number is prime
    bool is_prime(const uint64_t n)
    {
        // check if number is == 2
        if (!(n & 1) || n < 2) {
            return n == 2;
        }
        for (uint16_t p = 3; p <= n / p; p += 2) {
            if (!(n % p)) {
                return false;
            }
        }
        return true;
    }

    /// generate a vector which contains the multiplicative inverse
    /// of an unsigned integer
    std::vector<uint16_t> multiplicative_inverse_vector(const uint16_t m)
    {
        std::vector<uint16_t> inverse(m);
        inverse[1] = 1;
        for (uint16_t a = 2; a < m; a++) {
            inverse[a] = m - (inverse[m % a] * (m / a)) % m;
        }
        return inverse;
    }

    struct diameter_index_t
    {
        float diameter;
        int64_t index;
    };

    struct diameter_entry_t
    {
        diamater_entry_t(float diameter, int64_t index, uint16_t coefficient)
        : diameter_entry_t(diameter, index, coefficient)
        {}
        
        diameter_entry_t(const diameter_index_t diameter_index, 
            uint16_t coefficient)
        : diameter_entry_t(diameter_index.diameter,
            diameter_index.index,coefficient)
        {}

        diameter_entry_t(const diameter_index_t diameter_index)
        : diameter_entry_t(diameter_index.diameter,
            diameter_index.index, 0)
        {}

        diameter_entry_t(const int64_t& index)
        : diameter_entry_t(0, index, 0)
        {}
    };
}
