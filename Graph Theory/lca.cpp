#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> v64;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

ll n, l, timer;
vector<v64> t, up;
v64 tin, tout;

void dfs(ll u, ll p) {
    tin[u] = ++timer;
    up[u][0] = p;
    forn (i, 1, l + 1) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (auto v : t[u]) {
        if (v == p) continue;
        dfs(v, u);
    }
    tout[u] = ++timer;
}

bool is_ancestor(ll u, ll v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

ll lca(ll u, ll v) {
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u)) return v;
    for (ll i = l; i >= 0; i--) {
        if (!is_ancestor(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}

void preprocess(ll root) {
    tin.resize(n);
    tout.resize(n);
    timer = 0;
    l = ceil(log2(n));
    up.assign(n, v64(l + 1));
    dfs(root, root);
}
