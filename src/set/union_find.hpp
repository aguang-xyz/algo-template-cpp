#include "../vec/vec.hpp"

struct union_find
{
    vec<int> parent;

    union_find(int n)
    {
        parent = vec<int>::range(0, n);
    }

    int query(int x)
    {
        return parent[x] = parent[x] == x ? x : query(parent[x]);
    }
        
    void merge(int x, int y)
    {
        x = query(x);
        y = query(y);
        
        if (x != y)
        {
            parent[x] = y;
        }
    }
};
