/**
 * @file UnionFind.cxx
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "UnionFind.hh"

namespace ripser
{
    UnionFind::UnionFind(const int64_t n)
    : parent(n), rank(n, 0)
    {
        for (int64_t i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    UnionFind::~UnionFind()
    {}

    int64_t UnionFind::find(int64_t x)
    {
        int64_t y = x, z;
        while ((z = parent[y]) != y) y = z;
        while ((z = parent[x]) != y) 
        {
            parent[x] = y;
            x = z;
        } 
        return z;
    }

    void UnionFind::link(int64_t x, int64_t y)
    {
        if ((x = find(x)) == (y = find(y))) {
            return;
        }
        if (rank[x] > rank[y]) {
            parent[y] = x;
        }
        else {
            parent[x] = y;
            if (rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
}