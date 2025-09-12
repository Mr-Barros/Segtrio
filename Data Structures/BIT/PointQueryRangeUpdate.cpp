
struct BIT { // indexada a 1, range update point sum. O(N) espaco e construcao
    v64 bit;
    ll n;

    BIT(ll sz){
        n = sz + 1;
        bit.assign(n, 0);
    }

    BIT(const v64& v) : BIT(v.size()) {
        v64 delta(n-1);
        delta[0] = v[0];
        forn(i, 1, n-1)
            delta[i] = v[i] - v[i - 1];

        forn(i, 1, n) {
            bit[i] += delta[i-1];
            ll j = i + (i & -i);
            if (j < n)
                bit[j] += bit[i];
        }
    }

    ll point_query(ll i){
        ll sum = 0;
        for(++i; i > 0; i -= i & -i) 
            sum += bit[i];
        return sum;
    }

    void add(ll i, ll delta){
        for(++i; i < n; i += i & -i){
            bit[i] += delta;
        }
    }

    void range_add(ll l, ll r, ll val) {
        add(l, val);
        add(r + 1, -val);
    }
};
