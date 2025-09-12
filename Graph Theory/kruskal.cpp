#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p64;
typedef vector<ll> v64;
#define forn(i, s, e) for (ll i = (s); i < (e); i++)
#define ln "\n"
const ll INF = 0x3f3f3f3f3f3f3f3fll;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<Edge> kruskal(ll n, vector<Edge>& edges) {
    ll cost = 0;
    v64 tree_id(n);
    vector<Edge> result;
    forn (i, 0, n) tree_id[i] = i;

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (tree_id[e.u] != tree_id[e.v]) {
            cost += e.weight;
            result.push_back(e);

            ll old_id = tree_id[e.u], new_id = tree_id[e.v];
            forn (i, 0, n) {
                if (tree_id[i] == old_id) tree_id[i] = new_id;
            }
        }
    }

    return result;
}
