#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
const ll INF = 0x3f3f3f3f3f3f3f3fll;

ll n;
vector<v64> capacity;
vector<v64> adj;
vector<p64> min_cut;

ll bfs(ll s, ll t, v64& parent) {
    fill(parent.begin(), parent.end(), -1);
    parent[s] = -2;
    queue<p64> q;
    q.push({s, INF});

    while (!q.empty()) {
        ll cur = q.front().first;
        ll flow = q.front().second;
        q.pop();

        for (ll next : adj[cur]) {
            if (parent[next] == -1 && capacity[cur][next]) {
                parent[next] = cur;
                ll new_flow = min(flow, capacity[cur][next]);
                if (next == t) return new_flow;
                q.push({next, new_flow});
            }
        }
    }

    return 0;
}

ll maxflow(ll s, ll t) {
    ll flow = 0;
    v64 parent(n);
    ll new_flow;

    while (new_flow = bfs(s, t, parent)) {
        flow += new_flow;
        ll cur = t;
        while (cur != s) {
            ll prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }

    return flow;
}

void dfs(ll u, v64& id) {
    id[u] = 1;
    for (ll v : adj[u]) {
        if (id[v] == 1) continue;
        if (!capacity[u][v]) {
            min_cut.push_back({u, v});
            continue;
        }
        dfs(v, id);
    }
}

void get_cut(ll s, ll t) {
    v64 id(n, 0);
    dfs(s, id);
}