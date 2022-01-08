/**
 * @file BinomialCoefficientTable.hh
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
#include <vector>
#include <cassert>

#include "Utilities.hh"

namespace ripser
{
    /**
     * @brief 
     * 
     */
    class BinomialCoefficientTable
    {
    public:
        BinomialCoefficientTable(int64_t n, int64_t k);
        ~BinomialCoefficientTable();

        int64_t operator()(int64_t n, int64_t k) const;

    private:
        std::vector<std::vector<int64_t>> m_B;
    };
}