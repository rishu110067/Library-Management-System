#ifndef FENWICK_H
#define FENWICK_H

class Fenwick
{
    public:
    int size;
    vector<int> bit;
    Fenwick(int x)
    {
        size = x;
        bit.resize(size,0);
    }

    void update(int x, int val) 
    {
        for (; x < size; x += x & -x)
            bit[x] += val;
    }

    int query(int x) 
    {
        int res = 0;
        for (; x > 0; x -= x & -x)
            res += bit[x];
        return res;
    }

    int sum(int l, int r)
    {
        return query(r)-query(l-1);
    }   
};

#endif

