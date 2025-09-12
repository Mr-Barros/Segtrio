#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> v64;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

vector<bool> vis;

void dfs(ll u, vector<v64> const& adj, v64& out) {
    vis[u] = true;
    for (auto v : adj[u]) {
        if (vis[v]) continue;
        dfs(v, adj, out);
    }
    out.push_back(u);
}

void kosaraju(vector<v64>& adj, vector<v64>& scc, vector<v64>& adj_cond) {
    ll n = adj.size();
    scc.clear(), adj_cond.clear();
    v64 order;
    vis.assign(n, false);

    forn (u, 0, n) {
        if (!vis[u]) dfs(u, adj, order);
    }

    vector<v64> adj_rev(n);
    forn (u, 0, n) {
        for (auto v : adj[u]) {
            adj_rev[v].push_back(u);
        }
    }

    vis.assign(n, false);

    reverse(order.begin(), order.end());

    v64 roots(n, 0);

    for (auto u : order) {
        if (!vis[u]) {
            v64 component;
            dfs(u, adj_rev, component);
            scc.push_back(component);
            ll root = *min_element(component.begin(), component.end());
            for (auto v : component) roots[v] = root;
        }
    }

    adj_cond.assign(n, {});
    forn (u, 0, n) {
        for (auto v : adj[u]) {
            if (roots[u] != roots[v]) adj_cond[roots[u]].push_back(roots[v]);
        }
    }
}