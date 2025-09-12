#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> v64;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)

ll n;
vector<v64> g;
v64 vis, top;
bool cycle = false;

void dfs(ll u) {
    vis[u] = 1;
    for (auto v : g[u]) {
        if (vis[v] == 1) {
            cycle = true;
            continue;
        }
        if (vis[v] == 2) continue;
        dfs(v);
    }
    vis[u] = 2;
    top.push_back(u);
}

void topsort() {
    vis.assign(n, false);
    top.clear();
    forn (u, 0, n) {
        if (!vis[u]) dfs(u);
    }
    reverse(top.begin(), top.end());
}

bool kahn() {
    top.resize(n);
    v64 indeg(n);
    forn (u, 0, n) {
        for (auto v : g[u]) indeg[v]++;
    }
    queue<ll> q;
    forn (u, 0, n) {
        if (indeg[u] == 0) q.push(u);
    }

    ll idx = 0;
    while (!q.empty()) {
        ll at = q.front(); q.pop();
        top[idx++] = at;
        for (auto to : g[at]) {
            indeg[to]--;
            if (indeg[to] == 0) q.push(to);
        }
    }
    if (idx != n) return false;
    return true;
}