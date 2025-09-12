#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> v64;

struct dsu {
    v64 id, sz;

    dsu(ll n) : id(n), sz(n, 1) { iota(id.begin(), id.end(), 0); }

    ll find(ll a) { return id[a] == a ? a : id[a] = find(id[a]); }

    void uni(ll a, ll b) {
        a = find(a), b = find(b);
        if (a == b) return;
        if (sz[a] < sz[b]) swap(a, b);
        sz[a] += sz[b], id[b] = a;
    }
};