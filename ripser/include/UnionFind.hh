/**
 * @file UnionFind.hh
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

#include <vector>
#include <cmath>
#include <stdint.h>

namespace ripser
{
    /**
     * @brief 
     * 
     */
    class UnionFind
    {
    public:
        UnionFind(const int64_t n);
        ~UnionFind();

        int64_t find(int64_t x);

        void link(int64_t x, int64_t y);

    private:
        std::vector<int64_t> parent;
        std::vector<uint8_t> rank;
    };
}