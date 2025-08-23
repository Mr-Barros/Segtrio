#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
const ll INF = 0x3f3f3f3f3f3f3f3fll;

vector<vector<p64>> adj;

void dijkstra(ll s, v64& d, v64& p) {
    ll n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    priority_queue<p64, vector<p64>, greater<p64>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v]) continue;

        for (auto edge : adj[v]) {
            ll to = edge.first;
            ll len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}
