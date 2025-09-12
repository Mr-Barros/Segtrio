
// range min point update; 
// limitations: 
//   can only answer queries of type  [0, r]
//   the new value updated has to be smaller than the current value
// solution for this: Efficient Range Minimum Queries using Binary Indexed Trees
struct BIT { 
    v64 bit;
    ll n;

    BIT(ll n) {
        this->n = n;
        bit.assign(n, INF);
    }

    BIT(v64 a) : BIT(a.size()) {
        forn(i,0,n)
            update(i, a[i]);
    }

    ll getmin(ll r) {
        ll ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }

    void update(ll idx, ll val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
};
