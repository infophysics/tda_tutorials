/**
 * @file BinomialCoefficientTable.cxx
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "BinomialCoefficientTable.hh"

namespace ripser
{
    BinomialCoefficientTable::BinomialCoefficientTable(int64_t n, int64_t k)
    : m_B(n+1)
    {
        for (int64_t i = 0; i <= n; i++)
        {
            m_B[i].resize(k + 1, 0);
            m_B[i][0] = 1;
            for (int64_t j = 1; j < std::min(i, k + 1); j++) {
                m_B[i][j] = m_B[i - 1][j - 1] + m_B[i - 1][j];
            }
            if (i <= k) {
                m_B[i][i] = 1;
            }
            check_overflow(m_B[i][std::min(i >> 1, k)]);
        }
    }
    
    BinomialCoefficientTable::~BinomialCoefficientTable()
    {}

    int64_t BinomialCoefficientTable::operator()(int64_t n, int64_t k) const
    {
        assert(n < m_B.size() and k < m_B[n].size() and n >= k - 1);
        return m_B[n][k];
    }
}